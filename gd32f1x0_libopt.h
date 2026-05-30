#ifndef GD32F1X0_LIBOPT_H
#define GD32F1X0_LIBOPT_H

/*
 * 本地回退的 libopt 头文件。
 * 说明：Keil DFP 包的某些变体依赖自动生成的 RTE_Components.h。
 * 本工程直接使用捆绑的 GD32 SPL，因此显式包含外设头，
 * 以使工程在 Keil AC5/AC6 下保持自包含（无需生成 RTE 文件）。
 */
#include "gd32f1x0_adc.h"
#include "gd32f1x0_cec.h"
#include "gd32f1x0_crc.h"
#include "gd32f1x0_cmp.h"
#include "gd32f1x0_dac.h"
#include "gd32f1x0_dbg.h"
#include "gd32f1x0_dma.h"
#include "gd32f1x0_exti.h"
#include "gd32f1x0_fmc.h"
#include "gd32f1x0_gpio.h"
#include "gd32f1x0_syscfg.h"
#include "gd32f1x0_i2c.h"
#include "gd32f1x0_fwdgt.h"
#include "gd32f1x0_pmu.h"
#include "gd32f1x0_rcu.h"
#include "gd32f1x0_rtc.h"
#include "gd32f1x0_spi.h"
#include "gd32f1x0_timer.h"
#include "gd32f1x0_usart.h"
#include "gd32f1x0_wwdgt.h"
#include "gd32f1x0_misc.h"
#include "gd32f1x0_tsi.h"

#endif
