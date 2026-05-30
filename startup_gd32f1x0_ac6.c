#include <stdint.h>
#include <rt_misc.h>
#include "config/board/board_profile_u17_gd32f130.h"

#ifndef __NO_RETURN
#define __NO_RETURN __attribute__((noreturn))
#endif

extern void SystemInit(void);
extern __attribute__((noreturn)) void __main(void);

typedef void (*vector_entry_t)(void);

#define STARTUP_U17_STACK_TOP ((uintptr_t)(0x20000000UL + (BSP_MCU_SRAM_KB * 1024UL)))
#define STARTUP_U17_HEAP_BASE  ((uintptr_t)0x20001DE0UL)
#define STARTUP_U17_HEAP_LIMIT ((uintptr_t)0x20001E00UL)
#define STARTUP_U17_STACK_BASE ((uintptr_t)0x20002000UL)
#define STARTUP_U17_STACK_LIMIT ((uintptr_t)0x20001E00UL)

__value_in_regs struct __initial_stackheap __user_initial_stackheap(__uintptr r0,
                                                                    __uintptr sp,
                                                                    __uintptr r2,
                                                                    __uintptr sl)
{
    struct __initial_stackheap bounds;
    (void)r0;
    (void)sp;
    (void)r2;
    (void)sl;
    bounds.heap_base = STARTUP_U17_HEAP_BASE;
    bounds.stack_base = STARTUP_U17_STACK_BASE;
    bounds.heap_limit = STARTUP_U17_HEAP_LIMIT;
    bounds.stack_limit = STARTUP_U17_STACK_LIMIT;
    return bounds;
}

void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

void WWDGT_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LVD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCU_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_15_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TSI_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA_Channel0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA_Channel1_2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA_Channel3_4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC_CMP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER0_BRK_UP_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER0_Channel_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER5_DAC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER13_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER14_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER15_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER16_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C0_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CEC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C0_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USBD_LP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USBD_HP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USBDWakeUp_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA_Channel5_6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

__NO_RETURN void Reset_Handler(void)
{
    SystemInit();
    __main();
}

void Default_Handler(void)
{
    while (1) {
    }
}

const vector_entry_t g_vector_table[] __attribute__((used, section("RESET"))) = {
    (vector_entry_t)STARTUP_U17_STACK_TOP,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    WWDGT_IRQHandler,                       /* 0  */
    LVD_IRQHandler,                         /* 1  */
    RTC_IRQHandler,                         /* 2  */
    FMC_IRQHandler,                         /* 3  */
    RCU_IRQHandler,                         /* 4  */
    EXTI0_1_IRQHandler,                     /* 5  */
    EXTI2_3_IRQHandler,                     /* 6  */
    EXTI4_15_IRQHandler,                    /* 7  */
    TSI_IRQHandler,                         /* 8  */
    DMA_Channel0_IRQHandler,                /* 9  */
    DMA_Channel1_2_IRQHandler,              /* 10 */
    DMA_Channel3_4_IRQHandler,              /* 11 */
    ADC_CMP_IRQHandler,                     /* 12 */
    TIMER0_BRK_UP_TRG_COM_IRQHandler,       /* 13 */
    TIMER0_Channel_IRQHandler,              /* 14 */
    TIMER1_IRQHandler,                      /* 15 */
    TIMER2_IRQHandler,                      /* 16 */
    TIMER5_DAC_IRQHandler,                  /* 17 */
    0,                                      /* 18 */
    TIMER13_IRQHandler,                     /* 19 */
    TIMER14_IRQHandler,                     /* 20 */
    TIMER15_IRQHandler,                     /* 21 */
    TIMER16_IRQHandler,                     /* 22 */
    I2C0_EV_IRQHandler,                     /* 23 */
    I2C1_EV_IRQHandler,                     /* 24 */
    SPI0_IRQHandler,                        /* 25 */
    SPI1_IRQHandler,                        /* 26 */
    USART0_IRQHandler,                      /* 27 */
    USART1_IRQHandler,                      /* 28 */
    0,                                      /* 29 */
    CEC_IRQHandler,                         /* 30 */
    0,                                      /* 31 */
    I2C0_ER_IRQHandler,                     /* 32 */
    0,                                      /* 33 */
    I2C1_ER_IRQHandler,                     /* 34 */
    I2C2_EV_IRQHandler,                     /* 35 */
    I2C2_ER_IRQHandler,                     /* 36 */
    USBD_LP_IRQHandler,                     /* 37 */
    USBD_HP_IRQHandler,                     /* 38 */
    0,                                      /* 39 */
    0,                                      /* 40 */
    0,                                      /* 41 */
    USBDWakeUp_IRQHandler,                  /* 42 */
    0,                                      /* 43 */
    0,                                      /* 44 */
    0,                                      /* 45 */
    0,                                      /* 46 */
    0,                                      /* 47 */
    DMA_Channel5_6_IRQHandler,              /* 48 */
    0,                                      /* 49 */
    0,                                      /* 50 */
    SPI2_IRQHandler                         /* 51 */
};

