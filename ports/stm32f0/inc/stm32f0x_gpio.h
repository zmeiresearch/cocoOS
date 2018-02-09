//======================================================================================================================
// STM32F0x0 GPIO regsiter definitions 
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

#ifndef INC_STM32F0X_GPIO_H
#define INC_STM32F0X_GPIO_H

//======================================================================================================================
// Register bitfield definitions
//======================================================================================================================

// Structure for accessing fields where each pin is represented by two bits, including:
// RM0091, 8.4.1 GPIO port mode register (GPIOx_MODER) (x =A..F)
// RM0091, 8.4.3 GPIO port output speed register (GPIOx_OSPEEDR) (x = A..F)
// RM0091, 8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR) (x = A..F)
typedef struct 
{
    unsigned long   Pin0            : 2;
    unsigned long   Pin1            : 2;
    unsigned long   Pin2            : 2;
    unsigned long   Pin3            : 2;
    unsigned long   Pin4            : 2;
    unsigned long   Pin5            : 2;
    unsigned long   Pin6            : 2;
    unsigned long   Pin7            : 2;
    unsigned long   Pin8            : 2;
    unsigned long   Pin9            : 2;
    unsigned long   Pin10           : 2;
    unsigned long   Pin11           : 2;
    unsigned long   Pin12           : 2;
    unsigned long   Pin13           : 2;
    unsigned long   Pin14           : 2;
    unsigned long   Pin15           : 2;
} GPIO_PINS_2BITS;

// Structure for accessing fields where each pin is represented by one bit, including:
// RM0091, 8.4.2 GPIO port output type register (GPIOx_OTYPER) (x = A..F)
// RM0091, 8.4.5 GPIO port input data register (GPIOx_IDR) (x = A..F)
// RM0091, 8.4.6 GPIO port output data register (GPIOx_ODR) (x = A..F)
// RM0091, 8.4.11 GPIO port bit reset register (GPIOx_BRR) (x =A..F)
typedef struct 
{
    unsigned long  Pin0             : 1;
    unsigned long  Pin1             : 1;
    unsigned long  Pin2             : 1;
    unsigned long  Pin3             : 1;
    unsigned long  Pin4             : 1;
    unsigned long  Pin5             : 1;
    unsigned long  Pin6             : 1;
    unsigned long  Pin7             : 1;
    unsigned long  Pin8             : 1;
    unsigned long  Pin9             : 1;
    unsigned long  Pin10            : 1;
    unsigned long  Pin11            : 1;
    unsigned long  Pin12            : 1;
    unsigned long  Pin13            : 1;
    unsigned long  Pin14            : 1;
    unsigned long  Pin15            : 1;
    unsigned long                   : 16;
} GPIO_PINS_1BIT;

// RM0091, 8.4.1 GPIO port mode register (GPIOx_MODER) (x =A..F)
#define GPIO_MODER_INPUT            0x0
#define GPIO_MODER_OUTPUT           0x1
#define GPIO_MODER_AF               0x2
#define GPIO_MODER_ANALOG           0x3


// RM0091, 8.4.2 GPIO port output type register (GPIOx_OTYPER) (x = A..F)
#define GPIO_OTYPER_PP              0x0
#define GPIO_OTYPER_OD              0x1

// RM0091, 8.4.3 GPIO port output speed register (GPIOx_OSPEEDR) (x = A..F)
#define GPIO_OSPEEDR_LOW            0x0
#define GPIO_OSPEEDR_MEDIUM         0x1
#define GPIO_OSPEEDR_HIGH           0x3

// RM0091, 8.4.4 GPIO port pull-up/pull-down register (GPIOx_PUPDR) (x = A..F)
#define GPIO_PUPDR_NONE             0x0
#define GPIO_PUPDR_PULLUP           0x1
#define GPIO_PUPDR_PULLDOWN         0x2

// Special cases
// RM0091, 8.4.7 GPIO port bit set/reset register (GPIOx_BSRR) (x = A..F)
typedef struct 
{
    unsigned long  Bset0            : 1;
    unsigned long  Bset1            : 1;
    unsigned long  Bset2            : 1;
    unsigned long  Bset3            : 1;
    unsigned long  Bset4            : 1;
    unsigned long  Bset5            : 1;
    unsigned long  Bset6            : 1;
    unsigned long  Bset7            : 1;
    unsigned long  Bset8            : 1;
    unsigned long  Bset9            : 1;
    unsigned long  Bset10           : 1;
    unsigned long  Bset11           : 1;
    unsigned long  Bset12           : 1;
    unsigned long  Bset13           : 1;
    unsigned long  Bset14           : 1;
    unsigned long  Bset15           : 1;
    unsigned long  Breset0          : 1;
    unsigned long  Breset1          : 1;
    unsigned long  Breset2          : 1;
    unsigned long  Breset3          : 1;
    unsigned long  Breset4          : 1;
    unsigned long  Breset5          : 1;
    unsigned long  Breset6          : 1;
    unsigned long  Breset7          : 1;
    unsigned long  Breset8          : 1;
    unsigned long  Breset9          : 1;
    unsigned long  Breset10         : 1;
    unsigned long  Breset11         : 1;
    unsigned long  Breset12         : 1;
    unsigned long  Breset13         : 1;
    unsigned long  Breset14         : 1;
    unsigned long  Breset15         : 1;
} GPIO_BSRR_BITS;

// RM0091, 8.4.8 GPIO port configuration lock register (GPIOx_LCKR) (x = A..B)
typedef struct 
{
    unsigned long  Lck0         : 1;
    unsigned long  Lck1         : 1;
    unsigned long  Lck2         : 1;
    unsigned long  Lck3         : 1;
    unsigned long  Lck4         : 1;
    unsigned long  Lck5         : 1;
    unsigned long  Lck6         : 1;
    unsigned long  Lck7         : 1;
    unsigned long  Lck8         : 1;
    unsigned long  Lck9         : 1;
    unsigned long  Lck10        : 1;
    unsigned long  Lck11        : 1;
    unsigned long  Lck12        : 1;
    unsigned long  Lck13        : 1;
    unsigned long  Lck14        : 1;
    unsigned long  Lck15        : 1;
    unsigned long  Lckk         : 1;
    unsigned long               : 15;
} GPIO_LCKR_BITS;

// RM0091, 8.4.9 GPIO alternate function low register (GPIOx_AFRL) (x = A..F)
// RM0091, 8.4.10 GPIO alternate function high register (GPIOx_AFRH) (x = A..F)
typedef struct 
{
    unsigned long  Afsel0       : 4;
    unsigned long  Afsel1       : 4;
    unsigned long  Afsel2       : 4;
    unsigned long  Afsel3       : 4;
    unsigned long  Afsel4       : 4;
    unsigned long  Afsel5       : 4;
    unsigned long  Afsel6       : 4;
    unsigned long  Afsel7       : 4;
    unsigned long  Afsel8       : 4;
    unsigned long  Afsel9       : 4;
    unsigned long  Afsel10      : 4;
    unsigned long  Afsel11      : 4;
    unsigned long  Afsel12      : 4;
    unsigned long  Afsel13      : 4;
    unsigned long  Afsel14      : 4;
    unsigned long  Afsel15      : 4;
} GPIO_AFR_BITS;

// RM0091, 8.4.9 GPIO alternate function low register (GPIOx_AFRL) (x = A..F)
// RM0091, 8.4.10 GPIO alternate function high register (GPIOx_AFRH) (x = A..F)
#define GPIO_AFR_AF0            0x0
#define GPIO_AFR_AF1            0x1
#define GPIO_AFR_AF2            0x2
#define GPIO_AFR_AF3            0x3
#define GPIO_AFR_AF4            0x4
#define GPIO_AFR_AF5            0x5
#define GPIO_AFR_AF6            0x6
#define GPIO_AFR_AF7            0x7


typedef struct
{
    volatile GPIO_PINS_2BITS    Mode;               // GPIO port mode register,                 Offset: 0x00
    volatile GPIO_PINS_1BIT     Otype;              // GPIO port output type register,          Offset: 0x04
    volatile GPIO_PINS_2BITS    Ospeed;             // GPIO port output speed register,         Offset: 0x08
    volatile GPIO_PINS_2BITS    Pupd;               // GPIO port pull-up/pull-down register,    Offset: 0x0C
    volatile GPIO_PINS_1BIT     Input;              // GPIO port input data register,           Offset: 0x10
    volatile GPIO_PINS_1BIT     Output;             // GPIO port output data register,          Offset: 0x14
    volatile GPIO_BSRR_BITS     Bsr;                // GPIO port bit set/reset registerBSRR,    Offset: 0x18
    volatile GPIO_LCKR_BITS     Lock;               // GPIO port configuration lock register,   Offset: 0x1C
    volatile GPIO_AFR_BITS      Afsel;              // GPIO alternate function low register,    Offset: 0x20-0x24
    volatile GPIO_PINS_1BIT     Brr;                // GPIO bit reset register,                 Offset: 0x28
} GPIO;

//======================================================================================================================
// Register addresses
//======================================================================================================================
#define GPIOA_BASE_ADDR     0x48000000
#define GPIOB_BASE_ADDR     0x48000400
#define GPIOC_BASE_ADDR     0x48000800
#define GPIOD_BASE_ADDR     0x48000C00
#define GPIOF_BASE_ADDR     0x48001400

//======================================================================================================================
// Compiler-specific implementation
//======================================================================================================================
#ifdef __IAR_SYSTEMS_ICC__
volatile __no_init GPIO GPIOA @ GPIOA_BASE_ADDR;
volatile __no_init GPIO GPIOB @ GPIOB_BASE_ADDR;
volatile __no_init GPIO GPIOC @ GPIOC_BASE_ADDR;
volatile __no_init GPIO GPIOD @ GPIOD_BASE_ADDR;
volatile __no_init GPIO GPIOF @ GPIOF_BASE_ADDR;
#elif __GNUC__
#define GPIOA              ( * ( ( volatile GPIO * ) GPIOA_BASE_ADDR ) )
#define GPIOB              ( * ( ( volatile GPIO * ) GPIOB_BASE_ADDR ) )
#define GPIOC              ( * ( ( volatile GPIO * ) GPIOC_BASE_ADDR ) )
#define GPIOD              ( * ( ( volatile GPIO * ) GPIOD_BASE_ADDR ) )
#define GPIOF              ( * ( ( volatile GPIO * ) GPIOE_BASF_ADDR ) )
#else
#error "Usupported compiler!"
#endif

#endif // INC_STM32F0X_GPIO_H