	#include <chrono>
	#include <memory>
	#include <thread>
	#include <unistd.h>
	#include <functional>
	#include <future>
	#include <memory>
	#include <sstream>
	
	#include "rclcpp/rclcpp.hpp"
	#include "rclcpp_action/rclcpp_action.hpp"
	#include "std_msgs/msg/string.hpp"
	#include "std_msgs/msg/bool.hpp"
	#include "std_msgs/msg/empty.hpp"
	#include "std_msgs/msg/int16.hpp"
	#include "std_msgs/msg/float32.hpp"
	#include "geometry_msgs/msg/twist.hpp"
	#include "geometry_msgs/msg/twist.hpp"
	#include <cinttypes>
	
	extern "C" {
	    #include "../include/controller/controller_engine.h"
	}
	
	using namespace std::chrono_literals;

	// Utility functions
	void shuffle_events(controller_Event_ *x, size_t n)
	{
	    if (n > 1) {
	        srand(time(NULL));
	
	        for (unsigned i = 0; i < n-1; ++i)
	        {
	            unsigned j = rand() % (n-i) + i;
	            controller_Event_ temp = x[i];
	            x[i] = x[j];
	            x[j] = temp;
	        }
	    }
	}
	std::string serialize_json_vector(const std::vector<std::string>& list) {
	    std::stringstream output;
	    output << "[";
	    
	    bool first = true;
	
	    for (const auto& value : list) {
	        if (!first) {
	            output << ", ";
	        }
	        
	        first = false;
	
	        output << "\"" << value << "\"";
	    }
	    
	    output << "]";   
	    
	    return output.str();
	}
	
	double code_LineDetector_current_correction = 0.0;
	
	class Controller : public rclcpp::Node {
	public:	
		// Enum conversions

		rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscriber_client_correction;
		rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr subscriber_client_no_line;
		rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr subscriber_client_stop;
		rclcpp::Subscription<std_msgs::msg::Empty>::SharedPtr subscriber_client_continue;
		rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_client_move_forward;
		rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_client_halt;
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr state_information;
		std::vector<std::string> taken_transitions;

		Controller() : Node("controller") {
			subscriber_client_correction = this->create_subscription<std_msgs::msg::Float32>("/correction", 10, std::bind(&Controller::callback_message_correction, this, std::placeholders::_1));
			subscriber_client_no_line = this->create_subscription<std_msgs::msg::Empty>("/no_line", 10, std::bind(&Controller::callback_message_no_line, this, std::placeholders::_1));
			subscriber_client_stop = this->create_subscription<std_msgs::msg::Empty>("/stop", 10, std::bind(&Controller::callback_message_stop, this, std::placeholders::_1));
			subscriber_client_continue = this->create_subscription<std_msgs::msg::Empty>("/continue", 10, std::bind(&Controller::callback_message_continue, this, std::placeholders::_1));
			publisher_client_move_forward = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
			publisher_client_halt = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

			state_information = this->create_publisher<std_msgs::msg::String>("/controller/state", 10);
			timer = this->create_wall_timer(100ms, std::bind(&Controller::tick, this));
			controller_EngineFirstStep();
		}

		void callback_message_correction(const std_msgs::msg::Float32::SharedPtr msg) {
			
			code_LineDetector_current_correction = msg->data;
			
			
			// Call engine function
			controller_EnginePerformEvent(message_correction_u_response_);
		}
		
		
		void callback_message_no_line(const std_msgs::msg::Empty::SharedPtr msg) {
			
			
			
			// Call engine function
			controller_EnginePerformEvent(message_no_line_u_response_);
		}
		
		
		void callback_message_stop(const std_msgs::msg::Empty::SharedPtr msg) {
			
			
			
			// Call engine function
			controller_EnginePerformEvent(message_stop_u_response_);
		}
		
		
		void callback_message_continue(const std_msgs::msg::Empty::SharedPtr msg) {
			
			
			
			// Call engine function
			controller_EnginePerformEvent(message_continue_u_response_);
		}
		
		
		
		
		void call_message_move_forward() {
			auto value = geometry_msgs::msg::Twist();
			
			if (data_move_forward_ == _controller_data_pSCSYW0FL3FE3) {
				value.linear.x = 0.6;
			}
			if (data_move_forward_ == _controller_data_pSCSYW0FL3FE3) {
			}
			if (data_move_forward_ == _controller_data_pSCSYW0FL3FE3) {
			}
			if (data_move_forward_ == _controller_data_pSCSYW0FL3FE3) {
			}
			if (data_move_forward_ == _controller_data_pSCSYW0FL3FE3) {
			}
			if (data_move_forward_ == _controller_data_pSCSYW0FL3FE3) {
				value.angular.z = (0.0 - code_LineDetector_current_correction) / 100;
			}
			
			this->publisher_client_move_forward->publish(value);
		}
		
		
		void call_message_halt() {
			auto value = geometry_msgs::msg::Twist();
			
			if (data_halt_ == _controller_data_p4A24AENRE0ZA) {
				value.linear.x = 0.0;
			}
			if (data_halt_ == _controller_data_p4A24AENRE0ZA) {
			}
			if (data_halt_ == _controller_data_p4A24AENRE0ZA) {
			}
			if (data_halt_ == _controller_data_p4A24AENRE0ZA) {
			}
			if (data_halt_ == _controller_data_p4A24AENRE0ZA) {
			}
			if (data_halt_ == _controller_data_p4A24AENRE0ZA) {
				value.angular.z = 0.0;
			}
			
			this->publisher_client_halt->publish(value);
		}
		
		void emit_current_state() {
			std::stringstream output;
			
			output << "{";
			
			output << "\"current\": {" << "";
			output << "\"LineDetector\": {";
			output << "\"state\": \"" << enum_names[component_LineDetector_] << "\",";
			output << "\"variables\": {";
			
			output << "\"current_correction\": \"" << code_LineDetector_current_correction << "\"";				
			
			output << "}";
			output << "},";
			output << "\"EmergencyStop\": {";
			output << "\"state\": \"" << enum_names[component_EmergencyStop_] << "\",";
			output << "\"variables\": {";
			
			
			output << "}";
			output << "}";
			output << "},";
			output << "\"transitions\": " << serialize_json_vector(taken_transitions) << ",";
			output << "\"definition\": " << "{\"name\":\"LineFollowerController\",\"components\":[{\"name\":\"LineDetector\",\"messages\":[\"correction\",\"no_line\"],\"services\":[],\"actions\":[],\"behaviour\":{\"variables\":[\"current_correction\"],\"states\":[{\"name\":\"awaiting\",\"initial\":true,\"transitions\":[{\"next\":\"no_line\",\"id\":\"message_no_line_u_response_\",\"type\":\"response\",\"communication\":\"no_line\"},{\"next\":\"line_found\",\"id\":\"message_correction_u_response_\",\"type\":\"response\",\"communication\":\"correction\"}]},{\"name\":\"line_found\",\"initial\":false,\"transitions\":[{\"next\":\"no_line\",\"id\":\"message_no_line_u_response_\",\"type\":\"response\",\"communication\":\"no_line\"},{\"next\":null,\"id\":\"message_correction_u_response_\",\"type\":\"response\",\"communication\":\"correction\",\"assignment\":\"current_correction := value\"}]},{\"name\":\"no_line\",\"initial\":false,\"transitions\":[{\"next\":\"line_found\",\"id\":\"message_correction_u_response_\",\"type\":\"response\",\"communication\":\"correction\"}]}]}},{\"name\":\"EmergencyStop\",\"messages\":[\"stop\",\"continue\"],\"services\":[],\"actions\":[],\"behaviour\":{\"variables\":[],\"states\":[{\"name\":\"in_service\",\"initial\":true,\"transitions\":[{\"next\":\"stopped\",\"id\":\"message_stop_u_response_\",\"type\":\"response\",\"communication\":\"stop\"}]},{\"name\":\"stopped\",\"initial\":false,\"transitions\":[{\"next\":\"in_service\",\"id\":\"message_continue_u_response_\",\"type\":\"response\",\"communication\":\"continue\"}]}]}},{\"name\":\"TurtlebotPlatform\",\"messages\":[\"move_forward\",\"halt\"],\"services\":[],\"actions\":[]}]}";
			output << "}";
			
			auto msg = std_msgs::msg::String();
			msg.data = output.str();
			
			this->state_information->publish(msg);
		
			taken_transitions.clear();
		}
	private:
		// Heart of the controller
		void tick() {
			int nOfDataEvents = 2;
			      controller_Event_ data_events[2] = { data_move_forward_c_pVH45ZVZOCRIW_,data_halt_c_pWUJV2CSPI0X2_ };
			
			// Always execute data transitions that are possible
			shuffle_events(data_events, nOfDataEvents);
			
			for (int i = 0; i < nOfDataEvents; i++) {
				controller_EnginePerformEvent(data_events[i]);
			}
			
			int nOfControllableEvents = 2;
			      controller_Event_ controllable_events[2] = { message_move_forward_c_trigger_,message_halt_c_trigger_ };
			
			shuffle_events(controllable_events, nOfControllableEvents);
			
			for (int i = 0; i < nOfControllableEvents; i++) {
				if (controller_EnginePerformEvent(controllable_events[i])) {
					break;
				}
			}
			
			this->emit_current_state();
		}
		
		rclcpp::TimerBase::SharedPtr timer;
	};
	
	std::shared_ptr<Controller> node_controller = nullptr;
	
	// Control synthesis engine
	bool assigned = false;
	
	void controller_AssignInputVariables() {
		if (assigned) return;
		
		
		assigned = true;
	}
	void controller_InfoEvent(controller_Event_ event, BoolType pre) {
	    if (pre) {
	    	node_controller->taken_transitions.push_back(controller_event_names[event]);
	    	return;
	    }
	    
	    switch (event) {
	case message_move_forward_c_trigger_:
		node_controller->call_message_move_forward();
	break;
	case message_halt_c_trigger_:
		node_controller->call_message_halt();
	break;
	
	    default:
			return;	
	   	}
	}
	
	int main(int argc, char *argv[]) {
	    rclcpp::init(argc, argv);
	
	    node_controller = std::make_shared<Controller>();
	
	    rclcpp::spin(node_controller);
	    rclcpp::shutdown();
	
	    return 0;
	}
