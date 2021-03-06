/* Headers for the CIF to C translation of controller.cif
 * Generated file, DO NOT EDIT
 */

#ifndef CIF_C_CONTROLLER_ENGINE_H
#define CIF_C_CONTROLLER_ENGINE_H

#include "controller_library.h"

/* Types of the specification.
 * Note that integer ranges are ignored in C.
 */
enum Enumcontroller_ {
    _controller_awaiting_command,
    _controller_data_pLV2V0NPQH35K,
    _controller_data_pO6JO6QW5TBOU,
    _controller_executing,
    _controller_in_service,
    _controller_no_object,
    _controller_none,
    _controller_object_found,
    _controller_safe_front,
    _controller_safe_left,
    _controller_safe_right,
    _controller_stop_sign,
    _controller_stopped,
    _controller_unsafe_front,
    _controller_unsafe_left,
    _controller_unsafe_right,
};
typedef enum Enumcontroller_ controllerEnum;

extern const char *enum_names[];
extern int EnumTypePrint(controllerEnum value, char *dest, int start, int end);


/* Event declarations. */
enum controllerEventEnum_ {
    EVT_INITIAL_,                              /**< Initial step. */
    EVT_DELAY_,                                /**< Delay step. */
    EVT_TAU_,                                  /**< Tau step. */
    message_scan_front_u_response_,            /**< Event message_scan_front.u_response. */
    data_scan_front_c_none_,                   /**< Event data_scan_front.c_none. */
    message_scan_left_u_response_,             /**< Event message_scan_left.u_response. */
    data_scan_left_c_none_,                    /**< Event data_scan_left.c_none. */
    message_scan_right_u_response_,            /**< Event message_scan_right.u_response. */
    data_scan_right_c_none_,                   /**< Event data_scan_right.c_none. */
    message_rotate_left_c_trigger_,            /**< Event message_rotate_left.c_trigger. */
    data_rotate_left_c_none_,                  /**< Event data_rotate_left.c_none. */
    message_rotate_right_c_trigger_,           /**< Event message_rotate_right.c_trigger. */
    data_rotate_right_c_none_,                 /**< Event data_rotate_right.c_none. */
    message_rotate_done_u_response_,           /**< Event message_rotate_done.u_response. */
    data_rotate_done_c_none_,                  /**< Event data_rotate_done.c_none. */
    component_ObjectDetector_c_pU6SJARKG2TD7_, /**< Event component_ObjectDetector.c_pU6SJARKG2TD7. */
    component_ObjectDetector_c_pEQ73M2PZ6GC9_, /**< Event component_ObjectDetector.c_pEQ73M2PZ6GC9. */
    message_object_count_u_response_,          /**< Event message_object_count.u_response. */
    data_object_count_c_none_,                 /**< Event data_object_count.c_none. */
    message_object_scan_u_response_,           /**< Event message_object_scan.u_response. */
    data_object_scan_c_none_,                  /**< Event data_object_scan.c_none. */
    message_move_c_trigger_,                   /**< Event message_move.c_trigger. */
    data_move_c_none_,                         /**< Event data_move.c_none. */
    data_move_c_p9ON15CK7WIV2_,                /**< Event data_move.c_p9ON15CK7WIV2. */
    message_halt_c_trigger_,                   /**< Event message_halt.c_trigger. */
    data_halt_c_none_,                         /**< Event data_halt.c_none. */
    data_halt_c_pZQW1X9M3P0X5_,                /**< Event data_halt.c_pZQW1X9M3P0X5. */
    message_stop_u_response_,                  /**< Event message_stop.u_response. */
    data_stop_c_none_,                         /**< Event data_stop.c_none. */
    message_continue_u_response_,              /**< Event message_continue.u_response. */
    data_continue_c_none_,                     /**< Event data_continue.c_none. */
};
typedef enum controllerEventEnum_ controller_Event_;

/** Names of all the events. */
extern const char *controller_event_names[];

/* Constants. */


/* Input variables. */
extern controllerEnum message_scan_front_i_response_;  /**< Input variable "E message_scan_front.i_response". */
extern controllerEnum message_scan_left_i_response_;   /**< Input variable "E message_scan_left.i_response". */
extern controllerEnum message_scan_right_i_response_;  /**< Input variable "E message_scan_right.i_response". */
extern IntType message_object_count_i_response_count_; /**< Input variable "int[0..1] message_object_count.i_response_count". */
extern controllerEnum message_object_scan_i_response_; /**< Input variable "E message_object_scan.i_response". */

extern void controller_AssignInputVariables();

/* Declaration of internal functions. */


/* State variables (use for output only). */
extern RealType model_time; /**< Current model time. */
extern controllerEnum component_EmergencyStop_;                   /**< Discrete variable "E component_EmergencyStop". */
extern controllerEnum component_LidarScanner_v_front_;            /**< Discrete variable "E component_LidarScanner.v_front". */
extern controllerEnum component_LidarScanner_v_left_;             /**< Discrete variable "E component_LidarScanner.v_left". */
extern controllerEnum component_LidarScanner_v_right_;            /**< Discrete variable "E component_LidarScanner.v_right". */
extern BoolType component_LidarScanner_v_has_front_;              /**< Discrete variable "bool component_LidarScanner.v_has_front". */
extern IntType component_ObjectDetector_v_scanned_object_count_;  /**< Discrete variable "int[0..1] component_ObjectDetector.v_scanned_object_count". */
extern controllerEnum component_ObjectDetector_v_scanned_object_; /**< Discrete variable "E component_ObjectDetector.v_scanned_object". */
extern controllerEnum component_ObjectDetector_;                  /**< Discrete variable "E component_ObjectDetector". */
extern controllerEnum component_Rotator_;                         /**< Discrete variable "E component_Rotator". */
extern controllerEnum data_halt_;                                 /**< Discrete variable "E data_halt". */
extern controllerEnum data_move_;                                 /**< Discrete variable "E data_move". */

/* Algebraic and derivative functions (use for output only). */






/* Code entry points. */
void controller_EngineFirstStep(void);
void controller_EngineTimeStep(double delta);
BoolType controller_EnginePerformEvent(controller_Event_ event);

#if EVENT_OUTPUT
/**
 * External callback function reporting about the execution of an event.
 * @param event Event being executed.
 * @param pre If \c TRUE, event is about to be executed. If \c FALSE, event has been executed.
 * @note Function must be implemented externally.
 */
extern void controller_InfoEvent(controller_Event_ event, BoolType pre);
#endif

#if PRINT_OUTPUT
/**
 * External callback function to output the given text-line to the given filename.
 * @param text Text to print (does not have a EOL character).
 * @param fname Name of the file to print to.
 */
extern void controller_PrintOutput(const char *text, const char *fname);
#endif

#endif

