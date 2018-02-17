//======================================================================================================================
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
#include <stdlib.h>
#include <stdio.h>

#include <cocoos.h>
#include "stm32f030.h"

//======================================================================================================================
// Local defines
//======================================================================================================================
#define LED_TICK_PERIOD         (uint32_t)500       // in ms
#define BUTTON_SAMPLE_PERIOD    (uint32_t)10        // in ms

//======================================================================================================================
// Local function declarations
//======================================================================================================================
static void tick_init(void);
static void hardware_init(void);
static void led_blink_task(void);
static void button_input_task(void);

//======================================================================================================================
// Local functions
//======================================================================================================================

//! @brief Initializes SysTick peripheral to generate interrupts at a rate of OS_TICK_RATE. When the interrupt is 
//! generated, SysTick_Handler() will be called.
//! @param none
//! @return none
static void tick_init(void)
{
    // Configure SysTick Reload value
    NVIC_SYSTICKRVR_Bits.RELOAD = ( OS_CPU_CLOCK / OS_TICK_RATE ) - 1UL;
    
    NVIC_SYSTICKCSR_Bits.CLKSOURCE = 1;         // Use processor clock
    NVIC_SYSTICKCSR_Bits.TICKINT = 1;           // Enable SysTick interrupt
    NVIC_SYSTICKCSR_Bits.ENABLE = 1;            // Enable SysTick counter
}

//! @brief Initializes the hardware on the STM32F0308-DISCO board - the two LEDs and the push-button input
//! @param none
//! @return none
static void hardware_init(void)
{
    // blue & green leds are on GPIOC
    RCC_AHBENR_Bits.IOPCEN = 1;                 // Turn on GPIOC clock 
    // push-button USER is on PORTA
    RCC_AHBENR_Bits.IOPAEN = 1;
    
    // Configure GPIOC Pin8 - blue led on STM32f0-discovery board
    GPIOC.Mode.Pin8 = GPIO_MODER_OUTPUT;        // Set pin as output
    GPIOC.Otype.Pin8 = GPIO_OTYPER_PP;          // Output is Push-Pull
    GPIOC.Ospeed.Pin8 = GPIO_OSPEEDR_MEDIUM;    // Output speed medium
    GPIOC.Pupd.Pin8 = GPIO_PUPDR_NONE;          // No pull-up or down
    GPIOC.Output.Pin8 = 1;                      // Set output high - led on
    
    // Configure GPIOC Pin9 - green led on STM32f0-discovery board
    GPIOC.Mode.Pin9 = GPIO_MODER_OUTPUT;
    GPIOC.Otype.Pin9 = GPIO_OTYPER_PP;
    GPIOC.Ospeed.Pin9 = GPIO_OSPEEDR_MEDIUM;
    GPIOC.Pupd.Pin9  = GPIO_PUPDR_NONE;
    GPIOC.Output.Pin9 = 0;                      // Set output low - led off
    
    // Configure GPIOA Pin0 - USER push-button
    GPIOA.Mode.Pin0 = GPIO_MODER_INPUT;
    GPIOA.Pupd.Pin0 = GPIO_PUPDR_NONE;
}

//! @brief A task that toggles the blue LED with a period of 2*LED_TICK_PERIOD
//! @param none
//! @return none
static void led_blink_task(void)
{
    // cocoOS tasks actually resume through a direct call to their function, so all the data must be either global or 
    // static in order to be preserved after a task_wait() call.
    static int ledState = 0;
    task_open();
    
    while(1)
    {
        GPIOC.Output.Pin8 = ledState;
        ledState = !ledState;
        task_wait(OS_MS_TO_TICKS(LED_TICK_PERIOD));
    }
    
    task_close();
}

//! @brief A task that reads the state of USER push-button and sets the green LED state based on that.
//! @param none
//! @return none
static void button_input_task(void)
{
    task_open();
    
    while(1)
    {
        GPIOC.Output.Pin9 = GPIOA.Input.Pin0;
        task_wait(OS_MS_TO_TICKS(BUTTON_SAMPLE_PERIOD));
    }
    
    task_close();
}

//======================================================================================================================
// Main function
//======================================================================================================================
//! @brief Main program entry point
//! @param none
//! @return none
int main()
{
    // Initialize cocoOS
    os_disable_interrupts();
    os_init();
    
    // initialize SysTick interrupt
    tick_init();
    
    // initialize the hardware - leds and push-button
    hardware_init();
    
    task_create(led_blink_task,     1, NULL, 0, 0);
    task_create(button_input_task,  2, NULL, 0, 0);

    // Start cocoOS scheduler
    os_start();
    
    // we should never reach this
    return 0;
}
