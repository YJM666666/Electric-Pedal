#ifndef PEDAL_TYPES_H
#define PEDAL_TYPES_H

#include <stdint.h>

typedef enum
{
    STEP_SIDE_LEFT = 0,
    STEP_SIDE_RIGHT,
    STEP_SIDE_MAX
} step_side_t;

typedef enum
{
    STEP_ACT_STOP = 0,
    STEP_ACT_EXTEND,
    STEP_ACT_RETRACT,
    STEP_ACT_RETRACT_SLOW
} step_action_t;

#endif
