/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.7-dev */

#ifndef PB_PB_SMARTKNOB_PB_H_INCLUDED
#define PB_PB_SMARTKNOB_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _PB_RequestState {
    char dummy_field;
} PB_RequestState;

typedef struct _PB_Ack {
    uint32_t nonce;
} PB_Ack;

typedef struct _PB_Log {
    char msg[256];
} PB_Log;

typedef struct _PB_SmartKnobConfig {
    int32_t num_positions;
    int32_t position;
    float position_width_radians;
    float detent_strength_unit;
    float endstop_strength_unit;
    float snap_point;
    char text[51];
    pb_size_t detent_positions_count;
    int32_t detent_positions[5];
    float snap_point_bias;
    int32_t snap_point_bias_center_position;
} PB_SmartKnobConfig;

typedef struct _PB_SmartKnobState {
    int32_t current_position;
    float sub_position_unit;
    bool has_config;
    PB_SmartKnobConfig config;
} PB_SmartKnobState;

/* Message TO the Smartknob from the USB host */
typedef struct _PB_ToSmartknob {
    uint32_t nonce;
    pb_size_t which_payload;
    union {
        PB_RequestState request_state;
        PB_SmartKnobConfig smartknob_config;
    } payload;
} PB_ToSmartknob;

/* Message FROM the SmartKnob to USB host */
typedef struct _PB_FromSmartKnob {
    pb_size_t which_payload;
    union {
        PB_Ack ack;
        PB_Log log;
        PB_SmartKnobState smartknob_state;
    } payload;
} PB_FromSmartKnob;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define PB_FromSmartKnob_init_default            {0, {PB_Ack_init_default}}
#define PB_Ack_init_default                      {0}
#define PB_Log_init_default                      {""}
#define PB_SmartKnobState_init_default           {0, 0, false, PB_SmartKnobConfig_init_default}
#define PB_ToSmartknob_init_default              {0, 0, {PB_RequestState_init_default}}
#define PB_SmartKnobConfig_init_default          {0, 0, 0, 0, 0, 0, "", 0, {0, 0, 0, 0, 0}, 0, 0}
#define PB_RequestState_init_default             {0}
#define PB_FromSmartKnob_init_zero               {0, {PB_Ack_init_zero}}
#define PB_Ack_init_zero                         {0}
#define PB_Log_init_zero                         {""}
#define PB_SmartKnobState_init_zero              {0, 0, false, PB_SmartKnobConfig_init_zero}
#define PB_ToSmartknob_init_zero                 {0, 0, {PB_RequestState_init_zero}}
#define PB_SmartKnobConfig_init_zero             {0, 0, 0, 0, 0, 0, "", 0, {0, 0, 0, 0, 0}, 0, 0}
#define PB_RequestState_init_zero                {0}

/* Field tags (for use in manual encoding/decoding) */
#define PB_Ack_nonce_tag                         1
#define PB_Log_msg_tag                           1
#define PB_SmartKnobConfig_num_positions_tag     1
#define PB_SmartKnobConfig_position_tag          2
#define PB_SmartKnobConfig_position_width_radians_tag 3
#define PB_SmartKnobConfig_detent_strength_unit_tag 4
#define PB_SmartKnobConfig_endstop_strength_unit_tag 5
#define PB_SmartKnobConfig_snap_point_tag        6
#define PB_SmartKnobConfig_text_tag              7
#define PB_SmartKnobConfig_detent_positions_tag  8
#define PB_SmartKnobConfig_snap_point_bias_tag   9
#define PB_SmartKnobConfig_snap_point_bias_center_position_tag 10
#define PB_SmartKnobState_current_position_tag   1
#define PB_SmartKnobState_sub_position_unit_tag  2
#define PB_SmartKnobState_config_tag             3
#define PB_ToSmartknob_nonce_tag                 1
#define PB_ToSmartknob_request_state_tag         2
#define PB_ToSmartknob_smartknob_config_tag      3
#define PB_FromSmartKnob_ack_tag                 1
#define PB_FromSmartKnob_log_tag                 2
#define PB_FromSmartKnob_smartknob_state_tag     3

/* Struct field encoding specification for nanopb */
#define PB_FromSmartKnob_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,ack,payload.ack),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,log,payload.log),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,smartknob_state,payload.smartknob_state),   3)
#define PB_FromSmartKnob_CALLBACK NULL
#define PB_FromSmartKnob_DEFAULT NULL
#define PB_FromSmartKnob_payload_ack_MSGTYPE PB_Ack
#define PB_FromSmartKnob_payload_log_MSGTYPE PB_Log
#define PB_FromSmartKnob_payload_smartknob_state_MSGTYPE PB_SmartKnobState

#define PB_Ack_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   nonce,             1)
#define PB_Ack_CALLBACK NULL
#define PB_Ack_DEFAULT NULL

#define PB_Log_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   msg,               1)
#define PB_Log_CALLBACK NULL
#define PB_Log_DEFAULT NULL

#define PB_SmartKnobState_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    current_position,   1) \
X(a, STATIC,   SINGULAR, FLOAT,    sub_position_unit,   2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  config,            3)
#define PB_SmartKnobState_CALLBACK NULL
#define PB_SmartKnobState_DEFAULT NULL
#define PB_SmartKnobState_config_MSGTYPE PB_SmartKnobConfig

#define PB_ToSmartknob_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   nonce,             1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,request_state,payload.request_state),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,smartknob_config,payload.smartknob_config),   3)
#define PB_ToSmartknob_CALLBACK NULL
#define PB_ToSmartknob_DEFAULT NULL
#define PB_ToSmartknob_payload_request_state_MSGTYPE PB_RequestState
#define PB_ToSmartknob_payload_smartknob_config_MSGTYPE PB_SmartKnobConfig

#define PB_SmartKnobConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    num_positions,     1) \
X(a, STATIC,   SINGULAR, INT32,    position,          2) \
X(a, STATIC,   SINGULAR, FLOAT,    position_width_radians,   3) \
X(a, STATIC,   SINGULAR, FLOAT,    detent_strength_unit,   4) \
X(a, STATIC,   SINGULAR, FLOAT,    endstop_strength_unit,   5) \
X(a, STATIC,   SINGULAR, FLOAT,    snap_point,        6) \
X(a, STATIC,   SINGULAR, STRING,   text,              7) \
X(a, STATIC,   REPEATED, INT32,    detent_positions,   8) \
X(a, STATIC,   SINGULAR, FLOAT,    snap_point_bias,   9) \
X(a, STATIC,   SINGULAR, INT32,    snap_point_bias_center_position,  10)
#define PB_SmartKnobConfig_CALLBACK NULL
#define PB_SmartKnobConfig_DEFAULT NULL

#define PB_RequestState_FIELDLIST(X, a) \

#define PB_RequestState_CALLBACK NULL
#define PB_RequestState_DEFAULT NULL

extern const pb_msgdesc_t PB_FromSmartKnob_msg;
extern const pb_msgdesc_t PB_Ack_msg;
extern const pb_msgdesc_t PB_Log_msg;
extern const pb_msgdesc_t PB_SmartKnobState_msg;
extern const pb_msgdesc_t PB_ToSmartknob_msg;
extern const pb_msgdesc_t PB_SmartKnobConfig_msg;
extern const pb_msgdesc_t PB_RequestState_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define PB_FromSmartKnob_fields &PB_FromSmartKnob_msg
#define PB_Ack_fields &PB_Ack_msg
#define PB_Log_fields &PB_Log_msg
#define PB_SmartKnobState_fields &PB_SmartKnobState_msg
#define PB_ToSmartknob_fields &PB_ToSmartknob_msg
#define PB_SmartKnobConfig_fields &PB_SmartKnobConfig_msg
#define PB_RequestState_fields &PB_RequestState_msg

/* Maximum encoded size of messages (where known) */
#define PB_Ack_size                              6
#define PB_FromSmartKnob_size                    261
#define PB_Log_size                              258
#define PB_RequestState_size                     0
#define PB_SmartKnobConfig_size                  165
#define PB_SmartKnobState_size                   184
#define PB_ToSmartknob_size                      174

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
