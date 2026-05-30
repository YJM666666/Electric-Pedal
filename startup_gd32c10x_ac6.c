#include "gd32c10x.h"
#include <stdint.h>
#define __STACK_SIZE 0x00000200
#define __HEAP_SIZE  0x00000020
#ifndef __NO_RETURN
#define __NO_RETURN __attribute__((noreturn))
#endif
#ifndef __VECTOR_TABLE_ATTRIBUTE
#define __VECTOR_TABLE_ATTRIBUTE __attribute__((used, section(".isr_vector")))
#endif
#ifndef __VECTOR_TABLE
#define __VECTOR_TABLE __attribute__((used))
#endif

extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Limit;
extern void SystemInit(void);
extern __attribute__((noreturn)) void __main(void);

volatile uint32_t g_default_handler_active = 0U;
volatile uint32_t g_default_handler_ipsr = 0U;
volatile uint32_t g_default_handler_lr = 0U;
volatile uint32_t g_default_handler_cfsr = 0U;
volatile uint32_t g_default_handler_hfsr = 0U;
volatile uint32_t g_default_handler_bfar = 0U;
volatile uint32_t g_default_handler_mmfar = 0U;

typedef void (*vector_entry_t)(void);
extern const vector_entry_t g_vector_table[];

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
void TAMPER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCU_CTC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_Channel0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_Channel5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA0_Channel6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC0_1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN0_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN0_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN0_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN0_EWMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI5_9_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER0_BRK_TIMER8_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER0_UP_TIMER9_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER0_TRG_CMT_TIMER10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER0_Channel_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C0_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C0_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI10_15_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USBFS_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER7_BRK_TIMER11_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER7_UP_TIMER12_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER7_TRG_CMT_TIMER13_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER7_Channel_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIMER6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_EWMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USBFS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

__NO_RETURN void Reset_Handler(void)
{
    SCB->VTOR = (uint32_t)g_vector_table;
    __DSB();
    __ISB();
    SystemInit();
    __main();
}

void default_handler_capture(uint32_t lr)
{
    uint32_t ipsr;

    __asm volatile("MRS %0, ipsr" : "=r"(ipsr) :: "memory");
    g_default_handler_active = 1U;
    g_default_handler_ipsr = ipsr;
    g_default_handler_lr = lr;
    g_default_handler_cfsr = SCB->CFSR;
    g_default_handler_hfsr = SCB->HFSR;
    g_default_handler_bfar = SCB->BFAR;
    g_default_handler_mmfar = SCB->MMFAR;

    while (1) {
    }
}

__attribute__((naked)) void Default_Handler(void)
{
    __asm volatile(
        "mov r0, lr\n"
        "b default_handler_capture\n"
    );
}

const vector_entry_t g_vector_table[] __attribute__((used, section("RESET"))) = {
    (vector_entry_t)&Image$$ARM_LIB_STACK$$ZI$$Limit,
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
    WWDGT_IRQHandler,
    LVD_IRQHandler,
    TAMPER_IRQHandler,
    RTC_IRQHandler,
    FMC_IRQHandler,
    RCU_CTC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA0_Channel0_IRQHandler,
    DMA0_Channel1_IRQHandler,
    DMA0_Channel2_IRQHandler,
    DMA0_Channel3_IRQHandler,
    DMA0_Channel4_IRQHandler,
    DMA0_Channel5_IRQHandler,
    DMA0_Channel6_IRQHandler,
    ADC0_1_IRQHandler,
    CAN0_TX_IRQHandler,
    CAN0_RX0_IRQHandler,
    CAN0_RX1_IRQHandler,
    CAN0_EWMC_IRQHandler,
    EXTI5_9_IRQHandler,
    TIMER0_BRK_TIMER8_IRQHandler,
    TIMER0_UP_TIMER9_IRQHandler,
    TIMER0_TRG_CMT_TIMER10_IRQHandler,
    TIMER0_Channel_IRQHandler,
    TIMER1_IRQHandler,
    TIMER2_IRQHandler,
    TIMER3_IRQHandler,
    I2C0_EV_IRQHandler,
    I2C0_ER_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    SPI0_IRQHandler,
    SPI1_IRQHandler,
    USART0_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,
    EXTI10_15_IRQHandler,
    RTC_Alarm_IRQHandler,
    USBFS_WKUP_IRQHandler,
    TIMER7_BRK_TIMER11_IRQHandler,
    TIMER7_UP_TIMER12_IRQHandler,
    TIMER7_TRG_CMT_TIMER13_IRQHandler,
    TIMER7_Channel_IRQHandler,
    0,
    EXMC_IRQHandler,
    0,
    TIMER4_IRQHandler,
    SPI2_IRQHandler,
    UART3_IRQHandler,
    UART4_IRQHandler,
    TIMER5_IRQHandler,
    TIMER6_IRQHandler,
    DMA1_Channel0_IRQHandler,
    DMA1_Channel1_IRQHandler,
    DMA1_Channel2_IRQHandler,
    DMA1_Channel3_IRQHandler,
    DMA1_Channel4_IRQHandler,
    0,
    0,
    CAN1_TX_IRQHandler,
    CAN1_RX0_IRQHandler,
    CAN1_RX1_IRQHandler,
    CAN1_EWMC_IRQHandler,
    USBFS_IRQHandler,
};