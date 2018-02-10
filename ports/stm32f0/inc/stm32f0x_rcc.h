//======================================================================================================================
// STM32F0x0 RCC regsiter definitions 
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

#ifndef INC_STM32F0X_RCC_H
#define INC_STM32F0X_RCC_H

//======================================================================================================================
// Register bitfield definitions
//======================================================================================================================

// RM0091 6.4.1 Clock control register (RCC_CR)
typedef struct 
{
    unsigned long HSION             : 1;
    unsigned long HSIRDY            : 1;
    unsigned long                   : 1;
    unsigned long HSITRIM           : 5;
    unsigned long HSICAL            : 8;
    unsigned long HSEON             : 1;
    unsigned long HSERDY            : 1;
    unsigned long HSEBYP            : 1;
    unsigned long CSSON             : 1;
    unsigned long                   : 4;
    unsigned long PLLON             : 1;
    unsigned long PLLRDY            : 1;
    unsigned long                   : 6;
} RCC_CR_BITS;

// RM0091, 6.4.2 Clock configuration register (RCC_CFGR)
typedef struct 
{
    unsigned long SW                : 2;
    unsigned long SWS               : 2;
    unsigned long HPRE              : 4;
    unsigned long PPRE              : 3;
    unsigned long                   : 3;
    unsigned long ADCPRE            : 1;
    unsigned long PLLSRC            : 2;
    unsigned long PLLXTPRE          : 1;
    unsigned long PLLMUL            : 4;
    unsigned long                   : 2;
    unsigned long MCO               : 4;
    unsigned long MCOPREDIV         : 3;
    unsigned long PLLNODIV          : 1;
} RCC_CFGR_BITS;

// Bits 30:28 MCOPRE[2:0]: Microcontroller Clock Output Prescaler (not available on STM32F05x devices) 
#define RCC_CFGR_MCOPREDIV_1        0x0
#define RCC_CFGR_MCOPREDIV_2        0x1
#define RCC_CFGR_MCOPREDIV_4        0x2
#define RCC_CFGR_MCOPREDIV_8        0x3
#define RCC_CFGR_MCOPREDIV_16       0x4
#define RCC_CFGR_MCOPREDIV_32       0x5
#define RCC_CFGR_MCOPREDIV_64       0x6
#define RCC_CFGR_MCOPREDIV_128      0x7

// Bits 27:24 MCO[3:0]: Microcontroller clock output
#define RCC_MCOSOURCE_NOCLK         0x0
#define RCC_MCOSOURCE_HSI14         0x1
#define RCC_MCOSOURCE_LSI           0x2
#define RCC_MCOSOURCE_LSE           0x3
#define RCC_MCOSOURCE_SYSCLK        0x4
#define RCC_MCOSOURCE_HSI           0x5
#define RCC_MCOSOURCE_HSE           0x6
#define RCC_MCOSOURCE_PLLCLK_Div2   0x7
#define RCC_MCOSOURCE_HSI48         0x8
//#define RCC_MCOSOURCE_PLLCLK      0x87 //  RCC in StdPeriph Library has this but RM0091 does not

// Bits 21:18 PLLMUL[3:0]: PLL multiplication factor
#define RCC_PLLMUL_2                0x0
#define RCC_PLLMUL_3                0x1
#define RCC_PLLMUL_4                0x2
#define RCC_PLLMUL_5                0x3
#define RCC_PLLMUL_6                0x4
#define RCC_PLLMUL_7                0x5
#define RCC_PLLMUL_8                0x6
#define RCC_PLLMUL_9                0x7
#define RCC_PLLMUL_10               0x8
#define RCC_PLLMUL_11               0x9
#define RCC_PLLMUL_12               0xa
#define RCC_PLLMUL_13               0xb
#define RCC_PLLMUL_14               0xc
#define RCC_PLLMUL_15               0xd
#define RCC_PLLMUL_16               0xe

// Bits 16:15 PLLSRC[1:0]: PLL input clock source 
#define RCC_PLLSRC_HSI_Div2         0x0
#define RCC_PLLSRC_HSI_PREDIV       0x1
#define RCC_PLLSRC_HSE_PREDIV       0x2
#define RCC_PLLSRC_HSI48_PREDIV     0x3

// Bits 10:8 PPRE[2:0]: PCLK prescaler 
#define RCC_PPRE_HCLK               0x0
#define RCC_PPRE_HCLK_Div2          0x4
#define RCC_PPRE_HCLK_Div4          0x5
#define RCC_PPRE_HCLK_Div8          0x6
#define RCC_PPRE_HCLK_Div16         0x7

// Bits 7:4 HPRE[3:0]: HCLK prescaler
#define RCC_HPRE_SYSCLK             0x0
#define RCC_HPRE_SYSCLK_Div2        0x8
#define RCC_HPRE_SYSCLK_Div4        0x9
#define RCC_HPRE_SYSCLK_Div8        0xa
#define RCC_HPRE_SYSCLK_Div16       0xb
#define RCC_HPRE_SYSCLK_Div64       0xc
#define RCC_HPRE_SYSCLK_Div128      0xd
#define RCC_HPRE_SYSCLK_Div256      0xe
#define RCC_HPRE_SYSCLK_Div512      0xf

// Bits 3:2 SWS[1:0]: System clock switch status 
// Bits 1:0 SW[1:0]: System clock switch
#define RCC_SW_HSI                  0x0
#define RCC_SW_HSE                  0x1
#define RCC_SW_PLL                  0x2
#define RCC_SW_HSI48                0x3


// RM0091, 6.4.3 Clock interrupt register (RCC_CIR)
typedef struct 
{
    unsigned long  LSIRDYF          : 1;
    unsigned long  LSERDYF          : 1;
    unsigned long  HSIRDYF          : 1;
    unsigned long  HSERDYF          : 1;
    unsigned long  PLLRDYF          : 1;
    unsigned long  HSI14RDYF        : 1;
    unsigned long  HSI48RDYF        : 1;
    unsigned long  CSSF             : 1;
    unsigned long  LSIRDYIE         : 1;
    unsigned long  LSERDYIE         : 1;
    unsigned long  HSIRDYIE         : 1;
    unsigned long  HSERDYIE         : 1;
    unsigned long  PLLRDYIE         : 1;
    unsigned long  HSI14RDYIE       : 1;
    unsigned long  HSI48RDYIE       : 1;
    unsigned long                   : 1;
    unsigned long  LSIRDYC          : 1;
    unsigned long  LSERDYC          : 1;
    unsigned long  HSIRDYC          : 1;
    unsigned long  HSERDYC          : 1;
    unsigned long  PLLRDYC          : 1;
    unsigned long  HSI14RDYC        : 1;
    unsigned long  HSI48RDYC        : 1;
    unsigned long  CSSC             : 1;
    unsigned long                   : 8;
} RCC_CIR_BITS;

// RM0091, 6.4.4 APB peripheral reset register 2 (RCC_APB2RSTR)
typedef struct 
{
    unsigned long  SYSCFGRST        : 1;
    unsigned long                   : 4;
    unsigned long  USART6RST        : 1;
    unsigned long  USART7RST        : 1;
    unsigned long  USART8RST        : 1;
    unsigned long                   : 1;
    unsigned long  ADCRST           : 1;
    unsigned long                   : 1;
    unsigned long  TIM1RST          : 1;
    unsigned long  SPI1RST          : 1;
    unsigned long                   : 1;
    unsigned long  USART1RST        : 1;
    unsigned long                   : 1;
    unsigned long  TIM15RST         : 1;
    unsigned long  TIM16RST         : 1;
    unsigned long  TIM17RST         : 1;
    unsigned long                   : 3;
    unsigned long  DBGMCURST        : 1;
    unsigned long                   : 9;
} RCC_APB2RSTR_BITS;

// RM0091, 6.4.5 APB peripheral reset register 1 (RCC_APB1RSTR) 
typedef struct 
{
    unsigned long  TIM2RST          : 1;
    unsigned long  TIM3RST          : 1;
    unsigned long                   : 2;
    unsigned long  TIM6RST          : 1;
    unsigned long  TIM7RST          : 1;
    unsigned long                   : 2;
    unsigned long  TIM14RST         : 1;
    unsigned long                   : 2;
    unsigned long  WWDGRST          : 1;
    unsigned long                   : 2;
    unsigned long  SPI2RST          : 1;
    unsigned long                   : 2;
    unsigned long  USART2RST        : 1;
    unsigned long  USART3RST        : 1;
    unsigned long  USART4RST        : 1;
    unsigned long  USART5RST        : 1;
    unsigned long  I2C1RST          : 1;
    unsigned long  I2C2RST          : 1;
    unsigned long  USBRST           : 1;
    unsigned long                   : 1;
    unsigned long  CANRST           : 1;
    unsigned long                   : 1;
    unsigned long  CRSRST           : 1;
    unsigned long  PWRRST           : 1;
    unsigned long  DACRST           : 1;
    unsigned long  CECCRST          : 1;
    unsigned long                   : 1;
} RCC_APB1RSTR_BITS;

// RM0091, 6.4.6 AHB peripheral clock enable register (RCC_AHBENR)
typedef struct 
{
    unsigned long  DMAEN            : 1;
    unsigned long  DMA2EN           : 1;
    unsigned long  SRAMEN           : 1;
    unsigned long                   : 1;
    unsigned long  FLITFEN          : 1;
    unsigned long                   : 1;
    unsigned long  CRCEN            : 1;
    unsigned long                   :10;
    unsigned long  IOPAEN           : 1;
    unsigned long  IOPBEN           : 1;
    unsigned long  IOPCEN           : 1;
    unsigned long  IOPDEN           : 1;
    unsigned long  IOPEEN           : 1;
    unsigned long  IOPFEN           : 1;
    unsigned long                   : 1;
    unsigned long  TSCEN            : 1;
    unsigned long                   : 7;
} RCC_AHBENR_BITS;

// RM0091, 6.4.7 APB peripheral clock enable register 2 (RCC_APB2ENR) 
typedef struct 
{
    unsigned long  SYSCFGEN         : 1;
    unsigned long                   : 4;
    unsigned long  USART6EN         : 1;
    unsigned long  USART7EN         : 1;
    unsigned long  USART8EN         : 1;
    unsigned long                   : 1;
    unsigned long  ADC1EN           : 1;
    unsigned long                   : 1;
    unsigned long  TIM1EN           : 1;
    unsigned long  SPI1EN           : 1;
    unsigned long                   : 1;
    unsigned long  USART1EN         : 1;
    unsigned long                   : 1;
    unsigned long  TIM15EN          : 1;
    unsigned long  TIM16EN          : 1;
    unsigned long  TIM17EN          : 1;
    unsigned long                   : 3;
    unsigned long  DBGMCUEN         : 1;
    unsigned long                   : 9;
} RCC_APB2ENR_BITS;

// RM0091, 6.4.8 APB peripheral clock enable register 1 (RCC_APB1ENR)
typedef struct 
{
    unsigned long  TIM2EN           : 1;
    unsigned long  TIM3EN           : 1;
    unsigned long                   : 2;
    unsigned long  TIM6EN           : 1;
    unsigned long  TIM7EN           : 1;
    unsigned long                   : 2;
    unsigned long  TIM14EN          : 1;
    unsigned long                   : 2;
    unsigned long  WWDGEN           : 1;
    unsigned long                   : 2;
    unsigned long  SPI2EN           : 1;
    unsigned long                   : 2;
    unsigned long  USART2EN         : 1;
    unsigned long  USART3EN         : 1;
    unsigned long  USART4EN         : 1;
    unsigned long  USART5EN         : 1;
    unsigned long  I2C1EN           : 1;
    unsigned long  I2C2EN           : 1;
    unsigned long  USBEN            : 1;
    unsigned long                   : 1;
    unsigned long  CANEN            : 1;
    unsigned long                   : 1;
    unsigned long  CRSEN            : 1;
    unsigned long  PWREN            : 1;
    unsigned long  DACEN            : 1;
    unsigned long  CECEN            : 1;
    unsigned long                   : 1;
} RCC_APB1ENR_BITS;

// RM0091, 6.4.9 RTC domain control register (RCC_BDCR) 
typedef struct 
{
    unsigned long  LSEON            : 1;
    unsigned long  LSERDY           : 1;
    unsigned long  LSEBYP           : 1;
    unsigned long  LSEDRV           : 2;
    unsigned long                   : 3;
    unsigned long  RTCSEL           : 2;
    unsigned long                   : 5;
    unsigned long  RTCEN            : 1;
    unsigned long  BDRST            : 1;
    unsigned long                   :15;
} RCC_BDCR_BITS;

// Bits 9:8 RTCSEL[1:0]: RTC clock source selectio
#define RCC_BDCR_RTCSEL_NOCLK       0x0
#define RCC_BDCR_RTCSEL_LSE         0x1
#define RCC_BDCR_RTCSEL_LSI         0x2
#define RCC_BDCR_RTCSEL_HSE_Div32   0x3

// Bits 4:3 LSEDRV LSE oscillator drive capability
#define RCC_BDCR_LSEDRV_LOW         0x0
#define RCC_BDCR_LSEDRV_MEDHIGH     0x1
#define RCC_BDCR_LSEDRV_MEDLOW      0x2
#define RCC_BDCR_LSEDRV_HIGH        0x3


// RM0091, 6.4.10 Control/status register (RCC_CSR)
typedef struct 
{
    unsigned long  LSION            : 1;
    unsigned long  LSIRDY           : 1;
    unsigned long                   :21;
    unsigned long  V18PWRRSTF       : 1;
    unsigned long  RMVF             : 1;
    unsigned long  OBLRSTF          : 1;
    unsigned long  PINRSTF          : 1;
    unsigned long  PORRSTF          : 1;
    unsigned long  SFTRSTF          : 1;
    unsigned long  IWDGRSTF         : 1;
    unsigned long  WWDGRSTF         : 1;
    unsigned long  LPWRRSTF         : 1;
} RCC_CSR_BITS;

// RM0091, 6.4.11 AHB peripheral reset register (RCC_AHBRSTR)
typedef struct 
{
    unsigned long                   :17;
    unsigned long  IOPARST          : 1;
    unsigned long  IOPBRST          : 1;
    unsigned long  IOPCRST          : 1;
    unsigned long  IOPDRST          : 1;
    unsigned long  IOPERST          : 1;
    unsigned long  IOPFRST          : 1;
    unsigned long                   : 1;
    unsigned long  TSCRST           : 1;
    unsigned long                   : 7;
} RCC_AHBRSTR_BITS;

// RM0091, 6.4.12 Clock configuration register 2 (RCC_CFGR2)
typedef struct 
{
    unsigned long  PREDIV           : 4;
    unsigned long                   :28;
} RCC_CFGR2_BITS;

#define RCC_CFGR2_PREDIV_Nodiv      0x0
#define RCC_CFGR2_PREDIV_Div2       0x1
#define RCC_CFGR2_PREDIV_Div3       0x2
#define RCC_CFGR2_PREDIV_Div4       0x3
#define RCC_CFGR2_PREDIV_Div5       0x4
#define RCC_CFGR2_PREDIV_Div6       0x5
#define RCC_CFGR2_PREDIV_Div7       0x6
#define RCC_CFGR2_PREDIV_Div8       0x7
#define RCC_CFGR2_PREDIV_Div9       0x8
#define RCC_CFGR2_PREDIV_Div10      0x9
#define RCC_CFGR2_PREDIV_Div11      0xa
#define RCC_CFGR2_PREDIV_Div12      0xb
#define RCC_CFGR2_PREDIV_Div13      0xc
#define RCC_CFGR2_PREDIV_Div14      0xd
#define RCC_CFGR2_PREDIV_Div15      0xe
#define RCC_CFGR2_PREDIV_Div16      0xf


// RM0091, 6.4.13 Clock configuration register 3 (RCC_CFGR3)
typedef struct 
{
    unsigned long  USART1SW         : 2;
    unsigned long                   : 2;
    unsigned long  I2C1SW           : 1;
    unsigned long                   : 1;
    unsigned long  CECSW            : 1;
    unsigned long  USBSW            : 1;
    unsigned long  ADCSW            : 1;
    unsigned long                   : 7;
    unsigned long  USART2SW         : 2;
    unsigned long  USART3SW         : 2;
    unsigned long                   :12;
} RCC_CFGR3_BITS;

// Bits 19:18 USART3SW[1:0]: USART3 clock source selection (available only on STM32F09x devices)
// Bits 17:16 USART2SW[1:0]: USART2 clock source selection (available only on STM32F07x and STM32F09x devices)
// Bits 1:0 USART1SW[1:0]: USART1 clock source selection
#define RCC_CFGR3_USARTSW_PCLK      0x0
#define RCC_CFGR3_USARTSW_SYSCLK    0x1
#define RCC_CFGR3_USARTSW_LSE       0x2
#define RCC_CFGR3_USARTSW_HSI       0x3

// Bit 7 USBSW: USB clock source selection
#define RCC_CFGR3_USBSW_HSI48       0x0
#define RCC_CFGR3_USBSW_PLLCLK      0x1

// Bit 6 CECSW: HDMI CEC clock source selection
#define RCC_CFGR3_CECSW_HSI_Div244  0x0
#define RCC_CFGR3_LSE               0x1

// Bit 4 I2C1SW: I2C1 clock source selection
#define RCC_CFGR3_I2CSW_HSI         0x0
#define RCC_CFGR3_I2CSW_SYSCLK      0x1

// RM0091, 6.4.14 Clock control register 2 (RCC_CR2)
typedef struct 
{
    unsigned long  HSI14ON          : 1;
    unsigned long  HSI14RDY         : 1;
    unsigned long  HSI14DIS         : 1;
    unsigned long  HSI14TRIM        : 5;
    unsigned long  HSI14CAL         : 8;
    unsigned long                   :16;
} RCC_CR2_BITS;


//======================================================================================================================
// Register addresses
//======================================================================================================================
#define RCC_BASE                    ((uint32_t)0x40021000)
#define RCC_CR_ADDR                 ((uint32_t)RCC_BASE + 0x0)
#define RCC_CFGR_ADDR               ((uint32_t)RCC_BASE + 0x4)
#define RCC_CIR_ADDR                ((uint32_t)RCC_BASE + 0x8)
#define RCC_APB2RSTR_ADDR           ((uint32_t)RCC_BASE + 0xc)
#define RCC_APB1RSTR_ADDR           ((uint32_t)RCC_BASE + 0x10)
#define RCC_AHBENR_ADDR             ((uint32_t)RCC_BASE + 0x14)
#define RCC_APB2ENR_ADDR            ((uint32_t)RCC_BASE + 0x18)
#define RCC_APB1ENR_ADDR            ((uint32_t)RCC_BASE + 0x1c)
#define RCC_BDCR_ADDR               ((uint32_t)RCC_BASE + 0x20)
#define RCC_CSR_ADDR                ((uint32_t)RCC_BASE + 0x24)
#define RCC_AHBRSTR_ADDR            ((uint32_t)RCC_BASE + 0x28)
#define RCC_CFGR2_ADDR              ((uint32_t)RCC_BASE + 0x2c)
#define RCC_CFGR3_ADDR              ((uint32_t)RCC_BASE + 0x30)
#define RCC_CR2_ADDR                ((uint32_t)RCC_BASE + 0x34)


//======================================================================================================================
// Compiler-specific implementation
//======================================================================================================================
#ifdef __IAR_SYSTEMS_ICC__
volatile __no_init union {  unsigned long RCC_CR;       RCC_CR_BITS         RCC_CR_Bits      ; } @ RCC_CR_ADDR      ;
volatile __no_init union {  unsigned long RCC_CFGR;     RCC_CFGR_BITS       RCC_CFGR_Bits    ; } @ RCC_CFGR_ADDR    ;
volatile __no_init union {  unsigned long RCC_CIR;      RCC_CIR_BITS        RCC_CIR_Bits     ; } @ RCC_CIR_ADDR	    ;
volatile __no_init union {  unsigned long RCC_APB2RSTR; RCC_APB2RSTR_BITS   RCC_APB2RSTR_Bits; } @ RCC_APB2RSTR_ADDR;
volatile __no_init union {  unsigned long RCC_APB1RSTR; RCC_APB1RSTR_BITS   RCC_APB1RSTR_Bits; } @ RCC_APB1RSTR_ADDR;
volatile __no_init union {  unsigned long RCC_AHBENR;   RCC_AHBENR_BITS     RCC_AHBENR_Bits  ; } @ RCC_AHBENR_ADDR  ;
volatile __no_init union {  unsigned long RCC_APB2ENR;  RCC_APB2ENR_BITS    RCC_APB2ENR_Bits ; } @ RCC_APB2ENR_ADDR ;
volatile __no_init union {  unsigned long RCC_APB1ENR;  RCC_APB1ENR_BITS    RCC_APB1ENR_Bits ; } @ RCC_APB1ENR_ADDR ;
volatile __no_init union {  unsigned long RCC_BDCR;     RCC_BDCR_BITS       RCC_BDCR_Bits    ; } @ RCC_BDCR_ADDR    ;
volatile __no_init union {  unsigned long RCC_CSR;      RCC_CSR_BITS        RCC_CSR_Bits     ; } @ RCC_CSR_ADDR     ;
volatile __no_init union {  unsigned long RCC_AHBRSTR;  RCC_AHBRSTR_BITS    RCC_AHBRSTR_Bits ; } @ RCC_AHBRSTR_ADDR ;
volatile __no_init union {  unsigned long RCC_CFGR2;    RCC_CFGR2_BITS      RCC_CFGR2_Bits   ; } @ RCC_CFGR2_ADDR   ;
volatile __no_init union {  unsigned long RCC_CFGR3;    RCC_CFGR3_BITS      RCC_CFGR3_Bits   ; } @ RCC_CFGR3_ADDR   ;
volatile __no_init union {  unsigned long RCC_CR2;      RCC_CR2_BITS        RCC_CR2_Bits     ; } @ RCC_CR2_ADDR     ;
#elif __GNUC__
#define RCC_AHBENR              ( * ( ( volatile uint32_t *         )   RCC_AHBENR_ADDR     ) )
#define RCC_AHBENR_Bits         ( * ( ( volatile RCC_AHBENR_BITS *  )   RCC_AHBENR_ADDR     ) )
#define RCC_CR                  ( * ( ( volatile uint32_t *         )   RCC_CR_ADDR         ) )
#define RCC_CR_Bits             ( * ( ( volatile RCC_CR *           )   RCC_CR_ADDR         ) )
#define RCC_CFGR                ( * ( ( volatile uint32_t *         )   RCC_CFGR_ADDR       ) )
#define RCC_CFGR_Bits           ( * ( ( volatile RCC_CFGR *         )   RCC_CFGR_ADDR       ) )
#define RCC_CIR                 ( * ( ( volatile uint32_t *         )   RCC_CIR_ADDR        ) )
#define RCC_CIR_Bits            ( * ( ( volatile RCC_CIR *          )   RCC_CIR_ADDR        ) )
#define RCC_APB2RSTR            ( * ( ( volatile uint32_t *         )   RCC_APB2RSTR_ADDR   ) )
#define RCC_APB2RSTR_Bits       ( * ( ( volatile RCC_APB2RSTR *     )   RCC_APB2RSTR_ADDR   ) )
#define RCC_APB1RSTR            ( * ( ( volatile uint32_t *         )   RCC_APB1RSTR_ADDR   ) )
#define RCC_APB1RSTR_Bits       ( * ( ( volatile RCC_APB1RSTR_BITS *)   RCC_APB1RSTR_ADDR   ) )
#define RCC_AHBENR              ( * ( ( volatile uint32_t *         )   RCC_AHBENR_ADDR     ) )
#define RCC_AHBENR_Bits         ( * ( ( volatile RCC_AHBENR_BITS *  )   RCC_AHBENR_ADDR     ) )
#define RCC_APB2ENR             ( * ( ( volatile uint32_t *         )   RCC_APB2ENR_ADDR    ) )
#define RCC_APB2ENR_Bits        ( * ( ( volatile RCC_APB2ENR_BITS * )   RCC_APB2ENR_ADDR    ) )
#define RCC_APB1ENR             ( * ( ( volatile uint32_t *         )   RCC_APB1ENR_ADDR    ) )
#define RCC_APB1ENR_Bits        ( * ( ( volatile RCC_APB1ENR_BITS * )   RCC_APB1ENR_ADDR    ) )
#define RCC_BDCR                ( * ( ( volatile uint32_t *         )   RCC_BDCR_ADDR       ) )
#define RCC_BDCR_Bits           ( * ( ( volatile RCC_BDCR_BITS *    )   RCC_BDCR_ADDR       ) )
#define RCC_CSR                 ( * ( ( volatile uint32_t *         )   RCC_CSR_ADDR        ) )
#define RCC_CSR_Bits            ( * ( ( volatile RCC_CSR_BITS *     )   RCC_CSR_ADDR        ) )
#define RCC_AHBRSTR             ( * ( ( volatile uint32_t *         )   RCC_AHBRSTR_ADDR    ) )
#define RCC_AHBRSTR_Bits        ( * ( ( volatile RCC_AHBRSTR_BITS * )   RCC_AHBRSTR_ADDR    ) )
#define RCC_CFGR2               ( * ( ( volatile uint32_t *         )   RCC_CFGR2_ADDR      ) )
#define RCC_CFGR2_Bits          ( * ( ( volatile RCC_CFGR2_BITS *   )   RCC_CFGR2_ADDR      ) )
#define RCC_CFGR3               ( * ( ( volatile uint32_t *         )   RCC_CFGR3_ADDR      ) )
#define RCC_CFGR3_Bits          ( * ( ( volatile RCC_CFGR3_BITS *   )   RCC_CFGR3_ADDR      ) )
#define RCC_CR2                 ( * ( ( volatile uint32_t *         )   RCC_CR2_ADDR        ) )
#define RCC_CR2_Bits            ( * ( ( volatile RCC_CR2_BITS *     )   RCC_CR2_ADDR        ) )

#else
#error "Usupported compiler!"
#endif

#endif // INC_STM32F0X_RCC_H
