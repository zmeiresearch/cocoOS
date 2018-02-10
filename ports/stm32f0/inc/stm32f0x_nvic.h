//======================================================================================================================
// STM32F0x0 NVIC regsiter definitions - only the SysTick-relevant ones are present
//
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

#ifndef INC_STM32F0X_NVIC_H
#define INC_STM32F0X_NVIC_H

//======================================================================================================================
// Register bitfield definitions
//======================================================================================================================

// SysTick Control and Status Register - http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0552a/Bhccjgga.html
typedef struct 
{
  unsigned long ENABLE      : 1;
  unsigned long TICKINT     : 1;
  unsigned long CLKSOURCE   : 1;
  unsigned long             : 13;
  unsigned long COUNTFLAG   : 1;
  unsigned long             : 15;
} NVIC_SYSTICKCSR_BITS;

typedef struct 
{
  unsigned long RELOAD      : 24;
  unsigned long             : 8;
} NVIC_SYSTICKRVR_BITS;


//======================================================================================================================
// Register addresses
//======================================================================================================================
#define NVIC_SYSTICKCSR_ADDR     0xE000E010
#define NVIC_SYSTICKRVR_ADDR     0xE000E014


//======================================================================================================================
// Compiler-specific implementation
//======================================================================================================================
#ifdef __IAR_SYSTEMS_ICC__
volatile __no_init union {  unsigned long NVIC_SYSTICKCSR; NVIC_SYSTICKCSR_BITS NVIC_SYSTICKCSR_Bits; } @ NVIC_SYSTICKCSR_ADDR;
volatile __no_init union {  unsigned long NVIC_SYSTICKRVR; NVIC_SYSTICKRVR_BITS NVIC_SYSTICKRVR_Bits; } @ NVIC_SYSTICKRVR_ADDR;
#elif __GNUC__
#define NVIC_SYSTICKCSR         ( * ( ( volatile uint32_t *         )       NVIC_SYSTICKCSR_ADDR ) )
#define NVIC_SYSTICKCSR_Bits    ( * ( ( volatile NVIC_SYSTICKCSR_BITS *  )  NVIC_SYSTICKCSR_ADDR ) )
#define NVIC_SYSTICKRVR         ( * ( ( volatile uint32_t *         )       NVIC_SYSTICKRVR_ADDR ) )
#define NVIC_SYSTICKRVR_Bits    ( * ( ( volatile NVIC_SYSTICKRVR_BITS *  )  NVIC_SYSTICKRVR_ADDR ) )
#else
#error "Usupported compiler!"
#endif

#endif	// INC_STM32F0X_NVIC_H
