//======================================================================================================================
// A minimal vector table for STM32F0 MCU
// This file is part of the cocoOS stm32f0 port available from hhttps://github.com/zmeiresearch/cocoOS.git
//
// Copyright (c) 2018 Ivan Vasilev, Zmei Research Ltd.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted (subject to the
// limitations in the disclaimer below) provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//    disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
//    following disclaimer in the documentation and/or other materials provided with the distribution.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.  THIS SOFTWARE IS PROVIDED
// BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
// OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//======================================================================================================================

//======================================================================================================================
// Includes
//======================================================================================================================

#include <string.h>
#include <stdlib.h>

//======================================================================================================================
// Types
//======================================================================================================================
typedef void (* const pHandler)(void);

//======================================================================================================================
// Declarations
//======================================================================================================================
extern void __attribute__((noreturn,weak)) _start (void);
void __attribute__((weak)) Default_Handler(void);

extern unsigned int _estack;

//======================================================================================================================
// Reset handler. MCU jumps here after power-on and any kind of reset
//======================================================================================================================
void __attribute__ ((section(".after_vectors"),noreturn))
Reset_Handler (void)
{
    _start ();
}

//======================================================================================================================
// Default handlers for generic Cortex-M0 interrupts. All are defined as weak so that they can be overriden by the user.
//======================================================================================================================
void __attribute__ ((section(".after_vectors"),weak))
NMI_Handler (void)
{
    while (1)
    {
    }
}


void __attribute__ ((section(".after_vectors"),weak))
HardFault_Handler ()
{
    while (1)
    {
    }
}

void __attribute__ ((section(".after_vectors"),weak))
SVC_Handler ()
{
    while (1)
    {
    }
}

void __attribute__ ((section(".after_vectors"),weak))
PendSV_Handler ()
{
  while (1)
    {
    }
}

void __attribute__ ((section(".after_vectors"),weak))
SysTick_Handler ()
{
}

// Default handler - catches interrupts that do not have a user-provided handler. Typically, this means application
// misconfiguration.
void __attribute__ ((section(".after_vectors")))
Default_Handler(void)
{
  while (1)
    {
    }
}

//======================================================================================================================
// STM32F0x-specific interrupts. Aliased to the Default_Handler and all are defined as weak so that they can be
// overriden by the user by prviding an alternative implementation.
//======================================================================================================================
void __attribute__ ((weak, alias ("Default_Handler"))) WWDG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) RTC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) FLASH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) RCC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) EXTI0_1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) EXTI2_3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) EXTI4_15_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) DMA1_Channel1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) DMA1_Channel2_3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) DMA1_Channel4_5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) ADC1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM1_BRK_UP_TRG_COM_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM1_CC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM14_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM15_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM16_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) TIM17_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) I2C1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) I2C2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) SPI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) SPI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) USART1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) USART2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) USART3_6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler"))) USB_IRQHandler(void);

//======================================================================================================================
// The vector table itself. Linker must be instructed to place it at the correct memory location. For more info, see
// e.g. RM0360, 11.1.3 Interrupt and exception vectors or
// http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0497a/BABIFJFG.html
//======================================================================================================================
__attribute__ ((section(".isr_vector"),used))
pHandler vectors[] =
    {
      // Cortex-M0 generic vectors
      (pHandler) &_estack,          // Initial stack pointer                                    - offset 0x00
      Reset_Handler,                // Reset handler                                            - offset 0x04
      NMI_Handler,                  // NMI handler                                              - offset 0x08
      HardFault_Handler,            // Hard fault handler                                       - offset 0x0c
      0,                            // Reserved
      0,                            // Reserved
      0,                            // Reserved
      0,                            // Reserved
      0,                            // Reserved
      0,                            // Reserved
      0,                            // Reserved
      SVC_Handler,                  // SVCall handler                                           - offset 0x2c
      0,                            // Reserved
      0,                            // Reserved
      PendSV_Handler,               // The PendSV handler                                       - offset 0x38
      SysTick_Handler,              // The SysTick handler                                      - offset 0x3c

      // Device-specific vectors
#if defined(STM32F030)
      WWDG_IRQHandler,              // Window Watchdog interrupt                                - offset 0x40
      0,                            // Reserved
      RTC_IRQHandler,               // RTC & EXTI interrupt                                     - offset 0x48
      FLASH_IRQHandler,             // Flash global interrupt                                   - offset 0x4c
      RCC_IRQHandler,               // RCC global interrupt                                     - offset 0x50
      EXTI0_1_IRQHandler,           // EXTI Line[1:0] interrupt                                 - offset 0x54
      EXTI2_3_IRQHandler,           // EXTI Line[3:2] interrupt                                 - offset 0x58
      EXTI4_15_IRQHandler,          // EXTI Line[15:4] interrupt                                - offset 0x5c
      0,                            // Reserved
      DMA1_Channel1_IRQHandler,     // DMA channel 1 interrupt                                  - offset 0x64
      DMA1_Channel2_3_IRQHandler,   // DMA channel 2 and 3 interrupts                           - offset 0x68
      DMA1_Channel4_5_IRQHandler,   // DMA channel 4 and 5 interrupts                           - offset 0x6c
      ADC1_IRQHandler,              // ADC interrupts                                           - offset 0x70
      TIM1_BRK_UP_TRG_COM_IRQHandler, // TIM1 break, update, trigger and commutation interrupt  - offset 0x74
      TIM1_CC_IRQHandler,           // TIM1 capture compare interrupt                           - offset 0x78
      0,                            // Reserved
      TIM3_IRQHandler,              // TIM3 global interrupt                                    - offset 0x80
      TIM6_IRQHandler,              // TIM6 global interrupt                                    - offset 0x84
      0,                            // Reserved
      TIM14_IRQHandler,             // TIM14 global interrupt                                   - offset 0x8C
      TIM15_IRQHandler,             // TIM15 global interrupt                                   - offset 0x90
      TIM16_IRQHandler,             // TIM16 global interrupt                                   - offset 0x94
      TIM17_IRQHandler,             // TIM17 global interrupt                                   - offset 0x98
      I2C1_IRQHandler,              // I2C1 global interrupt                                    - offset 0x9C
      I2C2_IRQHandler,              // I2C2 global interrupt                                    - offset 0xA0
      SPI1_IRQHandler,              // SPI1 global interrupt                                    - offset 0xA4
      SPI2_IRQHandler,              // SPI2 global interrupt                                    - offset 0xA8
      USART1_IRQHandler,            // USART1 global interrupt                                  - offset 0xAC
      USART2_IRQHandler,            // USART2 global interrupt                                  - offset 0xB0
      USART3_6_IRQHandler,          // USART3, USART4, USART5, USART6 global interrupts         - offset 0xB4
      0,                            // Reserved
      USB_IRQHandler,               // USB global interrupt (combined with EXTI line 18)        - offset 0xBC
#else
#error "Unknown device"
#endif
  };

// ----------------------------------------------------------------------------



// ----------------------------------------------------------------------------
