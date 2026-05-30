#ifndef PROJECT_BOOL_H
#define PROJECT_BOOL_H

#if defined(APP_ROLE_U17_SLAVE)
/* U17 / GD32F130: 使用厂商库自己的 bool / TRUE / FALSE */
#include "gd32f1x0.h"

#ifndef true
#define true  TRUE
#endif

#ifndef false
#define false FALSE
#endif

#else
/* U12 / GD32C103: 自己提供轻量 bool */
#include <stdint.h>

#ifndef __cplusplus
typedef uint8_t bool;
#endif

#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#endif

#endif /* PROJECT_BOOL_H */