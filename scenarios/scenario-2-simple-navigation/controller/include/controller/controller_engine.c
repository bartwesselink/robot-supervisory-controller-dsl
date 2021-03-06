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
    "initial-step",                    /**< Initial step. */
    "delay-step",                      /**< Delay step. */
    "tau",                             /**< Tau step. */
    "message_point.u_response",        /**< Event message_point.u_response. */
    "data_point.c_none",               /**< Event data_point.c_none. */
    "message_initial_pose.u_response", /**< Event message_initial_pose.u_response. */
    "data_initial_pose.c_none",        /**< Event data_initial_pose.c_none. */
    "action_navigate.c_trigger",       /**< Event action_navigate.c_trigger. */
    "action_navigate.c_reset",         /**< Event action_navigate.c_reset. */
    "action_navigate.c_cancel",        /**< Event action_navigate.c_cancel. */
    "action_navigate.u_feedback",      /**< Event action_navigate.u_feedback. */
    "action_navigate.u_response",      /**< Event action_navigate.u_response. */
    "action_navigate.u_error",         /**< Event action_navigate.u_error. */
    "data_navigate.c_none",            /**< Event data_navigate.c_none. */
    "data_navigate.c_p1RWVCO75R33V",   /**< Event data_navigate.c_p1RWVCO75R33V. */
    "message_stop.u_response",         /**< Event message_stop.u_response. */
    "data_stop.c_none",                /**< Event data_stop.c_none. */
    "message_continue.u_response",     /**< Event message_continue.u_response. */
    "data_continue.c_none",            /**< Event data_continue.c_none. */
};

/** Enumeration names. */
const char *enum_names[] = {
    "awaiting_point",
    "data_pFXFXDZEMOW8W",
    "error",
    "executing",
    "has_point",
    "idle",
    "in_service",
    "no_initial_pose",
    "none",
    "ready",
    "stopped",
};

/* Constants. */


/* Functions. */


/* Input variables. */


/* State variables. */
controllerEnum action_navigate_;         /**< Discrete variable "E action_navigate". */
controllerEnum component_EmergencyStop_; /**< Discrete variable "E component_EmergencyStop". */
controllerEnum component_Nav2_;          /**< Discrete variable "E component_Nav2". */
controllerEnum data_navigate_;           /**< Discrete variable "E data_navigate". */

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
 * Execute code for event "action_navigate.c_cancel".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent0(void) {
    BoolType guard = (((action_navigate_) == (_controller_executing)) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point)))))) && (((component_EmergencyStop_ != _controller_in_service)) || ((component_Nav2_ != _controller_has_point)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_c_cancel_, TRUE);
    #endif

    action_navigate_ = _controller_idle;
    if ((component_Nav2_) == (_controller_no_initial_pose)) {
        component_Nav2_ = _controller_no_initial_pose;
    } else if ((component_Nav2_) == (_controller_awaiting_point)) {
        component_Nav2_ = _controller_awaiting_point;
    } else if ((component_Nav2_) == (_controller_has_point)) {
        component_Nav2_ = _controller_awaiting_point;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_c_cancel_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "action_navigate.c_reset".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent1(void) {
    BoolType guard = ((action_navigate_) == (_controller_ready)) || ((action_navigate_) == (_controller_error));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_c_reset_, TRUE);
    #endif

    if ((action_navigate_) == (_controller_ready)) {
        action_navigate_ = _controller_idle;
    } else if ((action_navigate_) == (_controller_error)) {
        action_navigate_ = _controller_idle;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_c_reset_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "action_navigate.c_trigger".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent2(void) {
    BoolType guard = ((action_navigate_) == (_controller_idle)) && (((component_EmergencyStop_) == (_controller_in_service)) && ((component_Nav2_) == (_controller_has_point)));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_c_trigger_, TRUE);
    #endif

    action_navigate_ = _controller_executing;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_c_trigger_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "action_navigate.u_error".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent3(void) {
    BoolType guard = ((action_navigate_) == (_controller_executing)) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_u_error_, TRUE);
    #endif

    action_navigate_ = _controller_error;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_u_error_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "action_navigate.u_feedback".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent4(void) {
    BoolType guard = ((action_navigate_) == (_controller_executing)) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_u_feedback_, TRUE);
    #endif

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_u_feedback_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "action_navigate.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent5(void) {
    BoolType guard = ((action_navigate_) == (_controller_executing)) && ((((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point)))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_u_response_, TRUE);
    #endif

    action_navigate_ = _controller_ready;
    if ((component_Nav2_) == (_controller_no_initial_pose)) {
        component_Nav2_ = _controller_no_initial_pose;
    } else if ((component_Nav2_) == (_controller_awaiting_point)) {
        component_Nav2_ = _controller_awaiting_point;
    } else if ((component_Nav2_) == (_controller_has_point)) {
        component_Nav2_ = _controller_awaiting_point;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(action_navigate_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_continue.c_none".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent6(void) {
    #if EVENT_OUTPUT
        controller_InfoEvent(data_continue_c_none_, TRUE);
    #endif

    #if EVENT_OUTPUT
        controller_InfoEvent(data_continue_c_none_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_initial_pose.c_none".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent7(void) {
    #if EVENT_OUTPUT
        controller_InfoEvent(data_initial_pose_c_none_, TRUE);
    #endif

    #if EVENT_OUTPUT
        controller_InfoEvent(data_initial_pose_c_none_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_navigate.c_none".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent8(void) {
    BoolType guard = FALSE;
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(data_navigate_c_none_, TRUE);
    #endif

    if (FALSE) {
        data_navigate_ = _controller_none;
    } else if (FALSE) {
        data_navigate_ = _controller_none;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(data_navigate_c_none_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_navigate.c_p1RWVCO75R33V".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent9(void) {
    BoolType guard = ((data_navigate_) == (_controller_none)) || ((data_navigate_) == (_controller_data_pFXFXDZEMOW8W));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(data_navigate_c_p1RWVCO75R33V_, TRUE);
    #endif

    if ((data_navigate_) == (_controller_none)) {
        data_navigate_ = _controller_data_pFXFXDZEMOW8W;
    } else if ((data_navigate_) == (_controller_data_pFXFXDZEMOW8W)) {
        data_navigate_ = _controller_data_pFXFXDZEMOW8W;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(data_navigate_c_p1RWVCO75R33V_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_point.c_none".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent10(void) {
    #if EVENT_OUTPUT
        controller_InfoEvent(data_point_c_none_, TRUE);
    #endif

    #if EVENT_OUTPUT
        controller_InfoEvent(data_point_c_none_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "data_stop.c_none".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent11(void) {
    #if EVENT_OUTPUT
        controller_InfoEvent(data_stop_c_none_, TRUE);
    #endif

    #if EVENT_OUTPUT
        controller_InfoEvent(data_stop_c_none_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_continue.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent12(void) {
    BoolType guard = (((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point))));
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
 * Execute code for event "message_initial_pose.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent13(void) {
    BoolType guard = (((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_initial_pose_u_response_, TRUE);
    #endif

    if ((component_Nav2_) == (_controller_no_initial_pose)) {
        component_Nav2_ = _controller_awaiting_point;
    } else if ((component_Nav2_) == (_controller_awaiting_point)) {
        component_Nav2_ = _controller_awaiting_point;
    } else if ((component_Nav2_) == (_controller_has_point)) {
        component_Nav2_ = _controller_has_point;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_initial_pose_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_point.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent14(void) {
    BoolType guard = (((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point))));
    if (!guard) return FALSE;

    #if EVENT_OUTPUT
        controller_InfoEvent(message_point_u_response_, TRUE);
    #endif

    if ((component_Nav2_) == (_controller_no_initial_pose)) {
        component_Nav2_ = _controller_no_initial_pose;
    } else if ((component_Nav2_) == (_controller_awaiting_point)) {
        component_Nav2_ = _controller_has_point;
    } else if ((component_Nav2_) == (_controller_has_point)) {
        component_Nav2_ = _controller_has_point;
    }

    #if EVENT_OUTPUT
        controller_InfoEvent(message_point_u_response_, FALSE);
    #endif
    return TRUE;
}

/**
 * Execute code for event "message_stop.u_response".
 *
 * @return Whether the event was performed.
 */
static BoolType execEvent15(void) {
    BoolType guard = (((component_EmergencyStop_) == (_controller_in_service)) || ((component_EmergencyStop_) == (_controller_stopped))) && (((component_Nav2_) == (_controller_no_initial_pose)) || (((component_Nav2_) == (_controller_awaiting_point)) || ((component_Nav2_) == (_controller_has_point))));
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

        if (execEvent0()) continue;  /* (Try to) perform event "action_navigate.c_cancel". */
        if (execEvent1()) continue;  /* (Try to) perform event "action_navigate.c_reset". */
        if (execEvent2()) continue;  /* (Try to) perform event "action_navigate.c_trigger". */
        if (execEvent6()) continue;  /* (Try to) perform event "data_continue.c_none". */
        if (execEvent7()) continue;  /* (Try to) perform event "data_initial_pose.c_none". */
        if (execEvent8()) continue;  /* (Try to) perform event "data_navigate.c_none". */
        if (execEvent9()) continue;  /* (Try to) perform event "data_navigate.c_p1RWVCO75R33V". */
        if (execEvent10()) continue;  /* (Try to) perform event "data_point.c_none". */
        if (execEvent11()) continue;  /* (Try to) perform event "data_stop.c_none". */
        break; /* No event fired, done with discrete steps. */
    }
}

/** First model call, initializing, and performing discrete events before the first time step. */
void controller_EngineFirstStep(void) {
    InitConstants();

    model_time = 0.0;

    action_navigate_ = _controller_idle;
    component_EmergencyStop_ = _controller_in_service;
    component_Nav2_ = _controller_no_initial_pose;
    data_navigate_ = _controller_none;

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
        case action_navigate_c_cancel_:
            return execEvent0();
        case action_navigate_c_reset_:
            return execEvent1();
        case action_navigate_c_trigger_:
            return execEvent2();
        case action_navigate_u_error_:
            return execEvent3();
        case action_navigate_u_feedback_:
            return execEvent4();
        case action_navigate_u_response_:
            return execEvent5();
        case data_continue_c_none_:
            return execEvent6();
        case data_initial_pose_c_none_:
            return execEvent7();
        case data_navigate_c_none_:
            return execEvent8();
        case data_navigate_c_p1RWVCO75R33V_:
            return execEvent9();
        case data_point_c_none_:
            return execEvent10();
        case data_stop_c_none_:
            return execEvent11();
        case message_continue_u_response_:
            return execEvent12();
        case message_initial_pose_u_response_:
            return execEvent13();
        case message_point_u_response_:
            return execEvent14();
        case message_stop_u_response_:
            return execEvent15();
        default:
            return FALSE;
    }
}
