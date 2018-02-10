//======================================================================================================================
// A minimal startup file for STM32F0 MCU - intializes memory and calls main
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
#include <stdint.h>
#include <sys/types.h>

//======================================================================================================================
// Forward declarations of external data and functions
//======================================================================================================================
extern int main (void);

// Section addresses. All of them come from the linker script file.
// Start address for the initialisation values of the .data section
extern unsigned int _sidata;
// Start address for the .data section
extern unsigned int _sdata;
// End address for the .data section
extern unsigned int _edata;

// Start address for the .bss section
extern unsigned int __bss_start__;
// End address for the .bss section
extern unsigned int __bss_end__;


//======================================================================================================================
// Local functions
//======================================================================================================================
// The implementation for the exit routine; for embedded
// applications, a system reset will be performed.
void __attribute__((weak)) _exit(int code __attribute__((unused)))
{
#if !defined(DEBUG)
    __reset_hardware();
#endif

    while (1)
    {
    }
}

// Initializes a RAM data region. Requires all pointers to be WORD aligned
inline void __attribute__((always_inline)) 
    __initialize_data(unsigned int * from, unsigned int * region_start, unsigned int * region_end)
{
    unsigned int *p = region_start;
    while (p < region_end)
    {
        *p++ = *from++;
    }
}

// Initialize(clear) a region. Requires all pointers to be WORD aligned
inline void __attribute__((always_inline))
    __initialize_bss (unsigned int * region_start, unsigned int * region_end)
{
    unsigned int *p = region_start;
    while (p < region_end)
    {
        *p++ = 0;
    }
}

// This is the place where Cortex-M core will go immediately after reset,
// via a call or jump from the Reset_Handler.
//
// For the call to work, and for the call to __initialize_hardware_early()
// to work, the reset stack must point to a valid internal RAM area.

void __attribute__ ((section(".after_vectors"),noreturn,weak))
_start (void)
{
    // Copy the DATA segment from Flash to RAM
    __initialize_data(&_sidata, &_sdata, &_edata);


    // Initialize BSS with zero
    __initialize_bss(&__bss_start__, &__bss_end__);

    // Call the main entry point, and save the exit code.
    int code = main();

    _exit(code);

    // Unreachable under normal conditions
    while (1)
    {
    }
}
