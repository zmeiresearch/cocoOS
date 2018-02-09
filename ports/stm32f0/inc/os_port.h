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
 
#ifndef OS_PORT_H_
#define OS_PORT_H_

//! MCU peripherals clock rate
//! @remark This is hardware-specific and is used for time management puposes only
#define OS_CPU_CLOCK        ((uint32_t)8000000)

//! OS Tick rate
//! @remark This is configurable and affects granularity of task scheduling, among other things
#define OS_TICK_RATE        ((uint32_t)1000)

//! Max number of used tasks
//! @remark Must be defined. @n Allowed range: 0-254. Value must not be exceeded
#define N_TASKS             (5)


//! Max number of used message queues
//! @remark Must be defined. @n Allowed range: 0-254. Value must not be exceeded
#define N_QUEUES            (10)


//! Max number of used semaphores
//! @remark Must be defined. @n Allowed range: 0-254. Value must not be exceeded
#define N_SEMAPHORES        (10)


//! Max number of used events
//! @remark Must be defined. @n Allowed range: 0-254. Value must not be exceeded 
#define N_EVENTS            (10)


//! Round Robin scheduling
//! @remark If defined, tasks will be scheduled ignoring the priorities
// #define ROUND_ROBIN


//! Memory size
//! @remark Should be set to the size of address pointer.
// #define OS_PTR_16BIT
#define OS_PTR_32BIT        1


//! Interrupts
//! @remark Interrupt enable/disable macros.
#define os_enable_interrupts()          __asm volatile( "cpsie i" );
#define os_disable_interrupts()         __asm volatile( "cpsid i" );

#define OS_MS_TO_TICKS(x)               ( (((uint32_t)(x) * 1000 ) + OS_TICK_RATE/2) / (uint32_t)OS_TICK_RATE)

#endif
