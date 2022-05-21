/* CIF to C translation of controller.cif
 * Generated file, DO NOT EDIT
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller_engine.h"

#ifndef MAX_NUM_EVENTS
#define MAX_NUM_EVENTS 1000
#endif

/* What to do if a range error is found in an assignment? */
#ifdef KEEP_RUNNING
static inline void RangeErrorDetected(void) { /* Do nothing, error is already reported. */ }
#else
static inline void RangeErrorDetected(void) { exit(1); }
#endif

/* Type support code. */
int EnumTypePrint(controllerEnum value, char *dest, int start, int end) {
    int last = end - 1;
    const char *lit_name = enum_names[value];
    while (start < last && *lit_name) {
        dest[start++] = *lit_name;
        lit_name++;
    }
    dest[start] = '\0';
    return start;
}


/** Event names. */
const char *controller_event_names[] = {
    "initial-step",                        /**< Initial step. */
    "delay-step",                          /**< Delay step. */
    "tau",                                 /**< Tau step. */
    "message_scan.u_response",             /**< Event message_scan.u_response. */
    "message_ball_correction.u_response",  /**< Event message_ball_correction.u_response. */
    "message_no_ball.u_response",          /**< Event message_no_ball.u_response. */
    "message_needs_ajustment.u_response",  /**< Event message_needs_ajustment.u_response. */
    "message_no_adjustment.u_response",    /**< Event message_no_adjustment.u_response. */
    "message_ball_front_check.u_response", /**< Event message_ball_front_check.u_response. */
    "message_goal_correction.u_response",  /**< Event message_goal_correction.u_response. */
    "message_no_goal.u_response",          /**< Event message_no_goal.u_response. */
    "message_stop.u_response",             /**< Event message_stop.u_response. */
    "message_continue.u_response",         /**< Event message_continue.u_response. */
    "message_move_forward.c_trigger",      /**< Event message_move_forward.c_trigger. */
    "data_move_forward.c_pYYTYBX6IYT0C",   /**< Event data_move_forward.c_pYYTYBX6IYT0C. */
    "data_move_forward.c_pQZAS5U6DXUKN",   /**< Event data_move_forward.c_pQZAS5U6DXUKN. */
    "data_move_forward.c_p7V114S5U6K7O",   /**< Event data_move_forward.c_p7V114S5U6K7O. */
    "data_move_forward.c_pQH3YZ1QP30AZ",   /**< Event data_move_forward.c_pQH3YZ1QP30AZ. */
    "message_halt.c_trigger",              /**< Event message_halt.c_trigger. */
    "data_halt.c_pUCEHVH1PWJ4N",           /**< Event data_halt.c_pUCEHVH1PWJ4N. */
};

/** Enumeration names. */
const char *enum_names[] = {
    "adjusting",
    "awaiting",
    "ball_found",
    "ball_in_front",
    "data_pB2V6S43RB4A4",
    "data_pEPFB7F9VF53E",
    "data_pJ3SFWI5LTZLP",
    "data_pKU7A65GAZ6FU",
    "data_pPCZF4J99PHAJ",
    "free",
    "goal_found",
    "in_service",
    "no_ball",
    "no_goal",
    "none",
    "obstructed",
    "stopped",
};

/* Constants. */


/* Functions. */


/* Input variables. */
controllerEnum message_scan_i_response_; /**< Input variable "E message_scan.i_response". */

/* State variables. */
controllerEnum component_BallDetector_;       /**< Discrete variable "E component_BallDetector". */
controllerEnum component_EmergencyStop_;      /**< Discrete variable "E component_EmergencyStop". */
controllerEnum component_GoalDetector_;       /**< Discrete variable "E component_GoalDetector". */
controllerEnum component_Scanner_v_distance_; /**< Discrete variable "E component_Scanner.v_distance". */
controllerEnum data_halt_;                    /**< Discrete variable "E data_halt". */
controllerEnum data_move_forward_;            /**< Discrete variable "E data_move_forward". */

RealType model_time; /**< Current model time. */

/** Initialize constants. */
static void InitConstants(void) {

}

/** Print function. */
#if PRINT_OUTPUT
static void PrintOutput(controller_Event_ event, BoolType pre) {
}
#endif

/* Event execution code. */

/**
 * Execute code for event "data_halt.c_pUCEHVH1PWJ4N".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent0(void) {
    BoolType guard = ((data_halt_) == (_controller_none)) || ((data_halt_) == (_controller_data_pKU7A65GAZ6FU));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(data_halt_c_pUCEHVH1PWJ4N_, TRUE);
    #endif

    if ((data_halt_) == (_controller_none)) {
        data_halt_ = _controller_data_pKU7A65GAZ6FU;
    } else if ((data_halt_) == (_controller_data_pKU7A65GAZ6FU)) {
        data_halt_ = _controller_data_pKU7A65GAZ6FU;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(data_halt_c_pUCEHVH1PWJ4N_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_move_forward.c_p7V114S5U6K7O".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent1(void) {
    BoolType guard = ((((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_ball_in_front))) || (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_ball_in_front)))) || ((((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_ball_in_front))) || ((((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_ball_in_front))) || (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_ball_in_front)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_p7V114S5U6K7O_, TRUE);
    #endif

    if (((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_ball_in_front))) {
        data_move_forward_ = _controller_data_pB2V6S43RB4A4;
    } else if (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_ball_in_front))) {
        data_move_forward_ = _controller_data_pB2V6S43RB4A4;
    } else if (((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_ball_in_front))) {
        data_move_forward_ = _controller_data_pB2V6S43RB4A4;
    } else if (((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_ball_in_front))) {
        data_move_forward_ = _controller_data_pB2V6S43RB4A4;
    } else if (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_ball_in_front))) {
        data_move_forward_ = _controller_data_pB2V6S43RB4A4;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_p7V114S5U6K7O_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_move_forward.c_pQH3YZ1QP30AZ".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent2(void) {
    BoolType guard = ((((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_no_ball))) || (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_no_ball)))) || ((((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_no_ball))) || ((((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_no_ball))) || (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_no_ball)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_pQH3YZ1QP30AZ_, TRUE);
    #endif

    if (((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_no_ball))) {
        data_move_forward_ = _controller_data_pEPFB7F9VF53E;
    } else if (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_no_ball))) {
        data_move_forward_ = _controller_data_pEPFB7F9VF53E;
    } else if (((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_no_ball))) {
        data_move_forward_ = _controller_data_pEPFB7F9VF53E;
    } else if (((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_no_ball))) {
        data_move_forward_ = _controller_data_pEPFB7F9VF53E;
    } else if (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_no_ball))) {
        data_move_forward_ = _controller_data_pEPFB7F9VF53E;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_pQH3YZ1QP30AZ_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_move_forward.c_pQZAS5U6DXUKN".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent3(void) {
    BoolType guard = ((((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_adjusting))) || (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_adjusting)))) || ((((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_adjusting))) || ((((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_adjusting))) || (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_adjusting)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_pQZAS5U6DXUKN_, TRUE);
    #endif

    if (((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_adjusting))) {
        data_move_forward_ = _controller_data_pJ3SFWI5LTZLP;
    } else if (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_adjusting))) {
        data_move_forward_ = _controller_data_pJ3SFWI5LTZLP;
    } else if (((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_adjusting))) {
        data_move_forward_ = _controller_data_pJ3SFWI5LTZLP;
    } else if (((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_adjusting))) {
        data_move_forward_ = _controller_data_pJ3SFWI5LTZLP;
    } else if (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_adjusting))) {
        data_move_forward_ = _controller_data_pJ3SFWI5LTZLP;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_pQZAS5U6DXUKN_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_move_forward.c_pYYTYBX6IYT0C".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent4(void) {
    BoolType guard = ((((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_ball_found))) || (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_ball_found)))) || ((((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_ball_found))) || ((((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_ball_found))) || (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_ball_found)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_pYYTYBX6IYT0C_, TRUE);
    #endif

    if (((data_move_forward_) == (_controller_none)) && ((component_BallDetector_) == (_controller_ball_found))) {
        data_move_forward_ = _controller_data_pPCZF4J99PHAJ;
    } else if (((data_move_forward_) == (_controller_data_pPCZF4J99PHAJ)) && ((component_BallDetector_) == (_controller_ball_found))) {
        data_move_forward_ = _controller_data_pPCZF4J99PHAJ;
    } else if (((data_move_forward_) == (_controller_data_pJ3SFWI5LTZLP)) && ((component_BallDetector_) == (_controller_ball_found))) {
        data_move_forward_ = _controller_data_pPCZF4J99PHAJ;
    } else if (((data_move_forward_) == (_controller_data_pB2V6S43RB4A4)) && ((component_BallDetector_) == (_controller_ball_found))) {
        data_move_forward_ = _controller_data_pPCZF4J99PHAJ;
    } else if (((data_move_forward_) == (_controller_data_pEPFB7F9VF53E)) && ((component_BallDetector_) == (_controller_ball_found))) {
        data_move_forward_ = _controller_data_pPCZF4J99PHAJ;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(data_move_forward_c_pYYTYBX6IYT0C_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_ball_correction.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent5(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_ball_correction_u_response_, TRUE);
    #endif

    if ((component_BallDetector_) == (_controller_awaiting)) {
        component_BallDetector_ = _controller_ball_found;
    } else if ((component_BallDetector_) == (_controller_ball_found)) {
        component_BallDetector_ = _controller_ball_found;
    } else if ((component_BallDetector_) == (_controller_ball_in_front)) {
        component_BallDetector_ = _controller_ball_in_front;
    } else if ((component_BallDetector_) == (_controller_adjusting)) {
        component_BallDetector_ = _controller_adjusting;
    } else if ((component_BallDetector_) == (_controller_no_ball)) {
        component_BallDetector_ = _controller_ball_found;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_ball_correction_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_ball_front_check.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent6(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_ball_front_check_u_response_, TRUE);
    #endif

    if ((component_BallDetector_) == (_controller_awaiting)) {
        component_BallDetector_ = _controller_awaiting;
    } else if ((component_BallDetector_) == (_controller_ball_found)) {
        component_BallDetector_ = _controller_ball_in_front;
    } else if ((component_BallDetector_) == (_controller_ball_in_front)) {
        component_BallDetector_ = _controller_ball_in_front;
    } else if ((component_BallDetector_) == (_controller_adjusting)) {
        component_BallDetector_ = _controller_adjusting;
    } else if ((component_BallDetector_) == (_controller_no_ball)) {
        component_BallDetector_ = _controller_no_ball;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_ball_front_check_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_continue.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent7(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_continue_u_response_, TRUE);
    #endif

    if ((component_EmergencyStop_) == (_controller_in_service)) {
        component_EmergencyStop_ = _controller_in_service;
    } else if ((component_EmergencyStop_) == (_controller_stopped)) {
        component_EmergencyStop_ = _controller_in_service;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_continue_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_goal_correction.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent8(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_goal_correction_u_response_, TRUE);
    #endif

    if ((component_GoalDetector_) == (_controller_awaiting)) {
        component_GoalDetector_ = _controller_goal_found;
    } else if ((component_GoalDetector_) == (_controller_goal_found)) {
        component_GoalDetector_ = _controller_goal_found;
    } else if ((component_GoalDetector_) == (_controller_no_goal)) {
        component_GoalDetector_ = _controller_goal_found;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_goal_correction_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_halt.c_trigger".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent9(void) {
    BoolType guard = ((component_EmergencyStop_) == (_controller_stopped)) || ((component_Scanner_v_distance_) == (_controller_obstructed));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_halt_c_trigger_, TRUE);
    #endif

    #if EVENT_OUTPUT
        controller_InfoEvent(message_halt_c_trigger_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_move_forward.c_trigger".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent10(void) {
    BoolType guard = ((component_EmergencyStop_) == (_controller_in_service)) && ((component_Scanner_v_distance_) == (_controller_free));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_move_forward_c_trigger_, TRUE);
    #endif

    #if EVENT_OUTPUT
        controller_InfoEvent(message_move_forward_c_trigger_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_needs_ajustment.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent11(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_needs_ajustment_u_response_, TRUE);
    #endif

    if ((component_BallDetector_) == (_controller_awaiting)) {
        component_BallDetector_ = _controller_awaiting;
    } else if ((component_BallDetector_) == (_controller_ball_found)) {
        component_BallDetector_ = _controller_ball_found;
    } else if ((component_BallDetector_) == (_controller_ball_in_front)) {
        component_BallDetector_ = _controller_adjusting;
    } else if ((component_BallDetector_) == (_controller_adjusting)) {
        component_BallDetector_ = _controller_adjusting;
    } else if ((component_BallDetector_) == (_controller_no_ball)) {
        component_BallDetector_ = _controller_no_ball;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_needs_ajustment_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_no_adjustment.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent12(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_no_adjustment_u_response_, TRUE);
    #endif

    if ((component_BallDetector_) == (_controller_awaiting)) {
        component_BallDetector_ = _controller_awaiting;
    } else if ((component_BallDetector_) == (_controller_ball_found)) {
        component_BallDetector_ = _controller_ball_found;
    } else if ((component_BallDetector_) == (_controller_ball_in_front)) {
        component_BallDetector_ = _controller_ball_in_front;
    } else if ((component_BallDetector_) == (_controller_adjusting)) {
        component_BallDetector_ = _controller_ball_in_front;
    } else if ((component_BallDetector_) == (_controller_no_ball)) {
        component_BallDetector_ = _controller_no_ball;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_no_adjustment_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_no_ball.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent13(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_no_ball_u_response_, TRUE);
    #endif

    if ((component_BallDetector_) == (_controller_awaiting)) {
        component_BallDetector_ = _controller_no_ball;
    } else if ((component_BallDetector_) == (_controller_ball_found)) {
        component_BallDetector_ = _controller_no_ball;
    } else if ((component_BallDetector_) == (_controller_ball_in_front)) {
        component_BallDetector_ = _controller_ball_in_front;
    } else if ((component_BallDetector_) == (_controller_adjusting)) {
        component_BallDetector_ = _controller_adjusting;
    } else if ((component_BallDetector_) == (_controller_no_ball)) {
        component_BallDetector_ = _controller_no_ball;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_no_ball_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_no_goal.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent14(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_no_goal_u_response_, TRUE);
    #endif

    if ((component_GoalDetector_) == (_controller_awaiting)) {
        component_GoalDetector_ = _controller_no_goal;
    } else if ((component_GoalDetector_) == (_controller_goal_found)) {
        component_GoalDetector_ = _controller_no_goal;
    } else if ((component_GoalDetector_) == (_controller_no_goal)) {
        component_GoalDetector_ = _controller_no_goal;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_no_goal_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_scan.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent15(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_scan_u_response_, TRUE);
    #endif

    component_Scanner_v_distance_ = message_scan_i_response_;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_scan_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_stop.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent16(void) {
    BoolType guard = ((((component_BallDetector_) == (_controller_awaiting)) || ((component_BallDetector_) == (_controller_ball_found))) || (((component_BallDetector_) == (_controller_ball_in_front)) || (((component_BallDetector_) == (_controller_adjusting)) || ((component_BallDetector_) == (_controller_no_ball))))) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_GoalDetector_) == (_controller_awaiting)) || (((component_GoalDetector_) == (_controller_goal_found)) || ((component_GoalDetector_) == (_controller_no_goal)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_stop_u_response_, TRUE);
    #endif

    if ((component_EmergencyStop_) == (_controller_in_service)) {
        component_EmergencyStop_ = _controller_stopped;
    } else if ((component_EmergencyStop_) == (_controller_stopped)) {
        component_EmergencyStop_ = _controller_stopped;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_stop_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Normalize and check the new value of a continuous variable after an update.
 * @param new_value Unnormalized new value of the continuous variable.
 * @param var_name Name of the continuous variable in the CIF model.
 * @return The normalized new value of the continuous variable.
 */
static inline RealType UpdateContValue(RealType new_value, const char *var_name) {
    if (isfinite(new_value)) {
        return (new_value == -0.0) ? 0.0 : new_value;
    }

    const char *err_type;
    if (isnan(new_value)) {
        err_type = "NaN";
    } else if (new_value > 0) {
        err_type = "+inf";
    } else {
        err_type = "-inf";
    }
    fprintf(stderr, "Continuous variable \"%s\" has become %s.\n", var_name, err_type);

#ifdef KEEP_RUNNING
    return 0.0;
#else
    exit(1);
#endif
}

/** Repeatedly perform discrete event steps, until no progress can be made any more. */
static void PerformEvents(void) {
    int count = 0;
    for (;;) {
        count++;
        if (count > MAX_NUM_EVENTS) { /* 'Infinite' loop detection. */
            fprintf(stderr, "Warning: Quitting after performing %d events, infinite loop?\n", count);
            break;
        }

        if (execEvent0()) continue;  /* (Try to) perform event "data_halt.c_pUCEHVH1PWJ4N". */
        if (execEvent1()) continue;  /* (Try to) perform event "data_move_forward.c_p7V114S5U6K7O". */
        if (execEvent2()) continue;  /* (Try to) perform event "data_move_forward.c_pQH3YZ1QP30AZ". */
        if (execEvent3()) continue;  /* (Try to) perform event "data_move_forward.c_pQZAS5U6DXUKN". */
        if (execEvent4()) continue;  /* (Try to) perform event "data_move_forward.c_pYYTYBX6IYT0C". */
        if (execEvent9()) continue;  /* (Try to) perform event "message_halt.c_trigger". */
        if (execEvent10()) continue;  /* (Try to) perform event "message_move_forward.c_trigger". */
        break; /* No event fired, done with discrete steps. */
    }
}

/** First model call, initializing, and performing discrete events before the first time step. */
void controller_EngineFirstStep(void) {
    InitConstants();

    model_time = 0.0;
    controller_AssignInputVariables();
    component_BallDetector_ = _controller_awaiting;
    component_EmergencyStop_ = _controller_in_service;
    component_GoalDetector_ = _controller_awaiting;
    component_Scanner_v_distance_ = _controller_free;
    data_halt_ = _controller_none;
    data_move_forward_ = _controller_none;

    #if PRINT_OUTPUT
        /* pre-initial and post-initial prints. */
        PrintOutput(EVT_INITIAL_, TRUE);
        PrintOutput(EVT_INITIAL_, FALSE);
    #endif

    PerformEvents();

    #if PRINT_OUTPUT
        /* pre-timestep print. */
        PrintOutput(EVT_DELAY_, TRUE);
    #endif
}

/**
 * Engine takes a time step of length \a delta.
 * @param delta Length of the time step.
 */
void controller_EngineTimeStep(double delta) {
    controller_AssignInputVariables();

    /* Update continuous variables. */
    if (delta > 0.0) {

        model_time += delta;
    }

    #if PRINT_OUTPUT
        /* post-timestep print. */
        PrintOutput(EVT_DELAY_, FALSE);
    #endif

    PerformEvents();

    #if PRINT_OUTPUT
        /* pre-timestep print. */
        PrintOutput(EVT_DELAY_, TRUE);
    #endif
}

/**
  * Engine (attempts) to perform a single event.
  * @param event The event to perform.
  * @return Whether the specified event could be executed.
  */
BoolType controller_EnginePerformEvent(controller_Event_ event) {
    switch (event) {
        case data_halt_c_pUCEHVH1PWJ4N_:
            return execEvent0();
        case data_move_forward_c_p7V114S5U6K7O_:
            return execEvent1();
        case data_move_forward_c_pQH3YZ1QP30AZ_:
            return execEvent2();
        case data_move_forward_c_pQZAS5U6DXUKN_:
            return execEvent3();
        case data_move_forward_c_pYYTYBX6IYT0C_:
            return execEvent4();
        case message_ball_correction_u_response_:
            return execEvent5();
        case message_ball_front_check_u_response_:
            return execEvent6();
        case message_continue_u_response_:
            return execEvent7();
        case message_goal_correction_u_response_:
            return execEvent8();
        case message_halt_c_trigger_:
            return execEvent9();
        case message_move_forward_c_trigger_:
            return execEvent10();
        case message_needs_ajustment_u_response_:
            return execEvent11();
        case message_no_adjustment_u_response_:
            return execEvent12();
        case message_no_ball_u_response_:
            return execEvent13();
        case message_no_goal_u_response_:
            return execEvent14();
        case message_scan_u_response_:
            return execEvent15();
        case message_stop_u_response_:
            return execEvent16();
        default:
            return FALSE;
    }
}