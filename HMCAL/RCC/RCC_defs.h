/*
 * File Name --> RCC_defs.h
 * Author	 --> Ahmed Mohamed Abd-Elfattah
 * Version	 --> 1.0.0
 * Layer	 --> HMCAL
 */

#ifndef HMCAL_RCC_RCC_DEFS_H_
#define HMCAL_RCC_RCC_DEFS_H_
/*
==================================================
  Start Section --> Bit definitions
==================================================
*/

/*  Bit definition for RCC_CR register  */
#define RCC_CR_HSION                   0
#define RCC_CR_HSIRDY                  1
#define RCC_CR_HSITRIM                 3
#define RCC_CR_HSITRIM_0               3
#define RCC_CR_HSITRIM_1               4
#define RCC_CR_HSITRIM_2               5
#define RCC_CR_HSITRIM_3               6
#define RCC_CR_HSITRIM_4               7
#define RCC_CR_HSICAL                  8
#define RCC_CR_HSICAL_0                8
#define RCC_CR_HSICAL_1                9
#define RCC_CR_HSICAL_2                10
#define RCC_CR_HSICAL_3                11
#define RCC_CR_HSICAL_4                12
#define RCC_CR_HSICAL_5                13
#define RCC_CR_HSICAL_6                14
#define RCC_CR_HSICAL_7                15
#define RCC_CR_HSEON                   16
#define RCC_CR_HSERDY                  17
#define RCC_CR_HSEBYP                  18
#define RCC_CR_CSSON                   19
#define RCC_CR_PLLON                   24
#define RCC_CR_PLLRDY                  25
#define RCC_CR_PLLI2SON                26
#define RCC_CR_PLLI2SRDY               27
/*  Bit definition for RCC_PLLCFGR register  */
#define RCC_PLLCFGR_PLLM               0
#define RCC_PLLCFGR_PLLM_0             0
#define RCC_PLLCFGR_PLLM_1             1
#define RCC_PLLCFGR_PLLM_2             2
#define RCC_PLLCFGR_PLLM_3             3
#define RCC_PLLCFGR_PLLM_4             4
#define RCC_PLLCFGR_PLLM_5             5
#define RCC_PLLCFGR_PLLN               6
#define RCC_PLLCFGR_PLLN_0             6
#define RCC_PLLCFGR_PLLN_1             7
#define RCC_PLLCFGR_PLLN_2             8
#define RCC_PLLCFGR_PLLN_3             9
#define RCC_PLLCFGR_PLLN_4             10
#define RCC_PLLCFGR_PLLN_5             11
#define RCC_PLLCFGR_PLLN_6             12
#define RCC_PLLCFGR_PLLN_7             13
#define RCC_PLLCFGR_PLLN_8             14
#define RCC_PLLCFGR_PLLP               16
#define RCC_PLLCFGR_PLLP_0             16
#define RCC_PLLCFGR_PLLP_1             17
#define RCC_PLLCFGR_PLLSRC             22
#define RCC_PLLCFGR_PLLSRC_HSE         22
#define RCC_PLLCFGR_PLLQ               24
#define RCC_PLLCFGR_PLLQ_0             24
#define RCC_PLLCFGR_PLLQ_1             25
#define RCC_PLLCFGR_PLLQ_2             26
#define RCC_PLLCFGR_PLLQ_3             30
/*  Bit definition for RCC_CFGR register  */
#define RCC_CFGR_SW                    0
#define RCC_CFGR_SW_0                  0
#define RCC_CFGR_SW_1                  1
#define RCC_CFGR_SWS                   2
#define RCC_CFGR_SWS_0                 2
#define RCC_CFGR_SWS_1                 3
#define RCC_CFGR_HPRE                  4
#define RCC_CFGR_HPRE_0                4
#define RCC_CFGR_HPRE_1                5
#define RCC_CFGR_HPRE_2                6
#define RCC_CFGR_HPRE_3                7
#define RCC_CFGR_PPRE1                 10
#define RCC_CFGR_PPRE1_0               10
#define RCC_CFGR_PPRE1_1               11
#define RCC_CFGR_PPRE1_2               12
#define RCC_CFGR_PPRE2                 13
#define RCC_CFGR_PPRE2_0               13
#define RCC_CFGR_PPRE2_1               14
#define RCC_CFGR_PPRE2_2               15
#define RCC_CFGR_RTCPRE                16
#define RCC_CFGR_RTCPRE_0          	   16
#define RCC_CFGR_RTCPRE_1          	   17
#define RCC_CFGR_RTCPRE_2              18
#define RCC_CFGR_RTCPRE_3              19
#define RCC_CFGR_RTCPRE_4              20
#define RCC_CFGR_MCO1                  21
#define RCC_CFGR_MCO1_0                21
#define RCC_CFGR_MCO1_1                22
#define RCC_CFGR_I2SSRC                23
#define RCC_CFGR_MCO1PRE               24
#define RCC_CFGR_MCO1PRE_0             24
#define RCC_CFGR_MCO1PRE_1             25
#define RCC_CFGR_MCO1PRE_2             26
#define RCC_CFGR_MCO2PRE               27
#define RCC_CFGR_MCO2PRE_0             27
#define RCC_CFGR_MCO2PRE_1             27
#define RCC_CFGR_MCO2PRE_2             27
#define RCC_CFGR_MCO2                  30
#define RCC_CFGR_MCO2_0                30
#define RCC_CFGR_MCO2_1                31
/*  Bit definition for RCC_CIR register  */
#define RCC_CIR_LSIRDYF                0
#define RCC_CIR_LSERDYF                1
#define RCC_CIR_HSIRDYF                2
#define RCC_CIR_HSERDYF                3
#define RCC_CIR_PLLRDYF                4
#define RCC_CIR_PLLI2SRDYF             5
#define RCC_CIR_CSSF                   7
#define RCC_CIR_LSIRDYIE               8
#define RCC_CIR_LSERDYIE               9
#define RCC_CIR_HSIRDYIE               10
#define RCC_CIR_HSERDYIE               11
#define RCC_CIR_PLLRDYIE               12
#define RCC_CIR_PLLI2SRDYIE            13
#define RCC_CIR_LSIRDYC                16
#define RCC_CIR_LSERDYC                17
#define RCC_CIR_HSIRDYC                18
#define RCC_CIR_HSERDYC                19
#define RCC_CIR_PLLRDYC                20
#define RCC_CIR_PLLI2SRDYC             21
#define RCC_CIR_CSSC                   23
/*  Bit definition for RCC_AHB1RSTR register  */
#define RCC_AHB1RSTR_GPIOARST          0
#define RCC_AHB1RSTR_GPIOBRST          1
#define RCC_AHB1RSTR_GPIOCRST          2
#define RCC_AHB1RSTR_GPIODRST          3
#define RCC_AHB1RSTR_GPIOERST          4
#define RCC_AHB1RSTR_GPIOFRST          5
#define RCC_AHB1RSTR_GPIOGRST          6
#define RCC_AHB1RSTR_GPIOHRST          7
#define RCC_AHB1RSTR_GPIOIRST          8
#define RCC_AHB1RSTR_CRCRST            12
#define RCC_AHB1RSTR_DMA1RST           21
#define RCC_AHB1RSTR_DMA2RST           22
#define RCC_AHB1RSTR_ETHMACRST         25
#define RCC_AHB1RSTR_OTGHRST           29
/*  Bit definition for RCC_AHB2RSTR register  */
#define RCC_AHB2RSTR_DCMIRST           0
#define RCC_AHB2RSTR_RNGRST            6
#define RCC_AHB2RSTR_OTGFSRST          7
/*  Bit definition for RCC_AHB3RSTR register  */
#define RCC_AHB3RSTR_FSMCRST           0
/*  Bit definition for RCC_APB1RSTR register  */
#define RCC_APB1RSTR_TIM2RST           0
#define RCC_APB1RSTR_TIM3RST           1
#define RCC_APB1RSTR_TIM4RST           2
#define RCC_APB1RSTR_TIM5RST           3
#define RCC_APB1RSTR_TIM6RST           4
#define RCC_APB1RSTR_TIM7RST           5
#define RCC_APB1RSTR_TIM12RST          6
#define RCC_APB1RSTR_TIM13RST          7
#define RCC_APB1RSTR_TIM14RST          8
#define RCC_APB1RSTR_WWDGRST           11
#define RCC_APB1RSTR_SPI2RST           14
#define RCC_APB1RSTR_SPI3RST           15
#define RCC_APB1RSTR_USART2RST         17
#define RCC_APB1RSTR_USART3RST         18
#define RCC_APB1RSTR_UART4RST          19
#define RCC_APB1RSTR_UART5RST          20
#define RCC_APB1RSTR_I2C1RST           21
#define RCC_APB1RSTR_I2C2RST           22
#define RCC_APB1RSTR_I2C3RST           23
#define RCC_APB1RSTR_CAN1RST           25
#define RCC_APB1RSTR_CAN2RST           26
#define RCC_APB1RSTR_PWRRST            28
#define RCC_APB1RSTR_DACRST            29
/*  Bit definition for RCC_APB2RSTR register  */
#define RCC_APB2RSTR_TIM1RST           0
#define RCC_APB2RSTR_TIM8RST           1
#define RCC_APB2RSTR_USART1RST         4
#define RCC_APB2RSTR_USART6RST         5
#define RCC_APB2RSTR_ADCRST            8
#define RCC_APB2RSTR_SDIORST           11
#define RCC_APB2RSTR_SPI1RST           12
#define RCC_APB2RSTR_SYSCFGRST         14
#define RCC_APB2RSTR_TIM9RST           16
#define RCC_APB2RSTR_TIM10RST          17
#define RCC_APB2RSTR_TIM11RST          18
/*  Bit definition for RCC_AHB1ENR register  */
#define RCC_AHB1ENR_GPIOAEN            0
#define RCC_AHB1ENR_GPIOBEN            1
#define RCC_AHB1ENR_GPIOCEN            2
#define RCC_AHB1ENR_GPIODEN            3
#define RCC_AHB1ENR_GPIOEEN            4
#define RCC_AHB1ENR_GPIOFEN            5
#define RCC_AHB1ENR_GPIOGEN            6
#define RCC_AHB1ENR_GPIOHEN            7
#define RCC_AHB1ENR_GPIOIEN            8
#define RCC_AHB1ENR_CRCEN              12
#define RCC_AHB1ENR_BKPSRAMEN          18
#define RCC_AHB1ENR_CCMDATARAMEN       20
#define RCC_AHB1ENR_DMA1EN             21
#define RCC_AHB1ENR_DMA2EN             22
#define RCC_AHB1ENR_ETHMACEN           25
#define RCC_AHB1ENR_ETHMACTXEN         26
#define RCC_AHB1ENR_ETHMACRXEN         27
#define RCC_AHB1ENR_ETHMACPTPEN        28
#define RCC_AHB1ENR_OTGHSEN            29
#define RCC_AHB1ENR_OTGHSULPIEN        30
/*  Bit definition for RCC_AHB2ENR register  */
#define RCC_AHB2ENR_DCMIEN             0
#define RCC_AHB2ENR_RNGEN              6
#define RCC_AHB2ENR_OTGFSEN            7
/*  Bit definition for RCC_AHB3ENR register  */
#define RCC_AHB3ENR_FSMCEN             0
/*  Bit definition for RCC_APB1ENR register  */
#define RCC_APB1ENR_TIM2EN             0
#define RCC_APB1ENR_TIM3EN             1
#define RCC_APB1ENR_TIM4EN             2
#define RCC_APB1ENR_TIM5EN             3
#define RCC_APB1ENR_TIM6EN             4
#define RCC_APB1ENR_TIM7EN             5
#define RCC_APB1ENR_TIM12EN            6
#define RCC_APB1ENR_TIM13EN            7
#define RCC_APB1ENR_TIM14EN            8
#define RCC_APB1ENR_WWDGEN             11
#define RCC_APB1ENR_SPI2EN             14
#define RCC_APB1ENR_SPI3EN             15
#define RCC_APB1ENR_USART2EN           17
#define RCC_APB1ENR_USART3EN           18
#define RCC_APB1ENR_UART4EN            19
#define RCC_APB1ENR_UART5EN            20
#define RCC_APB1ENR_I2C1EN             21
#define RCC_APB1ENR_I2C2EN             22
#define RCC_APB1ENR_I2C3EN             23
#define RCC_APB1ENR_CAN1EN             25
#define RCC_APB1ENR_CAN2EN             26
#define RCC_APB1ENR_PWREN              28
#define RCC_APB1ENR_DACEN              29
/*  Bit definition for RCC_APB2ENR register  */
#define RCC_APB2ENR_TIM1EN             0
#define RCC_APB2ENR_TIM8EN             1
#define RCC_APB2ENR_USART1EN           4
#define RCC_APB2ENR_USART6EN           5
#define RCC_APB2ENR_ADC1EN             8
#define RCC_APB2ENR_ADC2EN             9
#define RCC_APB2ENR_ADC3EN             10
#define RCC_APB2ENR_SDIOEN             11
#define RCC_APB2ENR_SPI1EN             12
#define RCC_APB2ENR_SYSCFGEN           14
#define RCC_APB2ENR_TIM9EN             16
#define RCC_APB2ENR_TIM10EN            17
#define RCC_APB2ENR_TIM11EN            18
/*  Bit definition for RCC_AHB1LPENR register  */
#define RCC_AHB1LPENR_GPIOALPEN        0
#define RCC_AHB1LPENR_GPIOBLPEN        1
#define RCC_AHB1LPENR_GPIOCLPEN        2
#define RCC_AHB1LPENR_GPIODLPEN        3
#define RCC_AHB1LPENR_GPIOELPEN        4
#define RCC_AHB1LPENR_GPIOFLPEN        5
#define RCC_AHB1LPENR_GPIOGLPEN        6
#define RCC_AHB1LPENR_GPIOHLPEN        7
#define RCC_AHB1LPENR_GPIOILPEN        8
#define RCC_AHB1LPENR_CRCLPEN          12
#define RCC_AHB1LPENR_FLITFLPEN        15
#define RCC_AHB1LPENR_SRAM1LPEN        16
#define RCC_AHB1LPENR_SRAM2LPEN        17
#define RCC_AHB1LPENR_BKPSRAMLPEN      18
#define RCC_AHB1LPENR_DMA1LPEN         21
#define RCC_AHB1LPENR_DMA2LPEN         22
#define RCC_AHB1LPENR_ETHMACLPEN       25
#define RCC_AHB1LPENR_ETHMACTXLPEN     26
#define RCC_AHB1LPENR_ETHMACRXLPEN     27
#define RCC_AHB1LPENR_ETHMACPTPLPEN    28
#define RCC_AHB1LPENR_OTGHSLPEN        29
#define RCC_AHB1LPENR_OTGHSULPILPEN    30
/*  Bit definition for RCC_AHB2LPENR register  */
#define RCC_AHB2LPENR_DCMILPEN         0
#define RCC_AHB2LPENR_RNGLPEN          6
#define RCC_AHB2LPENR_OTGFSLPEN        7
/*  Bit definition for RCC_AHB3LPENR register  */
#define RCC_AHB3LPENR_FSMCLPEN         0
/*  Bit definition for RCC_APB1LPENR register  */
#define RCC_APB1LPENR_TIM2LPEN         0
#define RCC_APB1LPENR_TIM3LPEN         1
#define RCC_APB1LPENR_TIM4LPEN         2
#define RCC_APB1LPENR_TIM5LPEN         3
#define RCC_APB1LPENR_TIM6LPEN         4
#define RCC_APB1LPENR_TIM7LPEN         5
#define RCC_APB1LPENR_TIM12LPEN        6
#define RCC_APB1LPENR_TIM13LPEN        7
#define RCC_APB1LPENR_TIM14LPEN        8
#define RCC_APB1LPENR_WWDGLPEN         11
#define RCC_APB1LPENR_SPI2LPEN         14
#define RCC_APB1LPENR_SPI3LPEN         15
#define RCC_APB1LPENR_USART2LPEN       17
#define RCC_APB1LPENR_USART3LPEN       18
#define RCC_APB1LPENR_UART4LPEN        19
#define RCC_APB1LPENR_UART5LPEN        20
#define RCC_APB1LPENR_I2C1LPEN         21
#define RCC_APB1LPENR_I2C2LPEN         22
#define RCC_APB1LPENR_I2C3LPEN         23
#define RCC_APB1LPENR_CAN1LPEN         25
#define RCC_APB1LPENR_CAN2LPEN         26
#define RCC_APB1LPENR_PWRLPEN          28
#define RCC_APB1LPENR_DACLPEN          29
/*  Bit definition for RCC_APB2LPENR register  */
#define RCC_APB2LPENR_TIM1LPEN         0
#define RCC_APB2LPENR_TIM8LPEN         1
#define RCC_APB2LPENR_USART1LPEN       4
#define RCC_APB2LPENR_USART6LPEN       5
#define RCC_APB2LPENR_ADC1LPEN         8
#define RCC_APB2LPENR_ADC2LPEN         9
#define RCC_APB2LPENR_ADC3LPEN         10
#define RCC_APB2LPENR_SDIOLPEN         11
#define RCC_APB2LPENR_SPI1LPEN         12
#define RCC_APB2LPENR_SYSCFGLPEN       14
#define RCC_APB2LPENR_TIM9LPEN         16
#define RCC_APB2LPENR_TIM10LPEN        17
#define RCC_APB2LPENR_TIM11LPEN        18
/*  Bit definition for RCC_BDCR register  */
#define RCC_BDCR_LSEON                 0
#define RCC_BDCR_LSERDY                1
#define RCC_BDCR_LSEBYP                2
#define RCC_BDCR_RTCSEL                8
#define RCC_BDCR_RTCSEL_0              8
#define RCC_BDCR_RTCSEL_1              9
#define RCC_BDCR_RTCEN                 15
#define RCC_BDCR_BDRST                 16
/*  Bit definition for RCC_CSR register  */
#define RCC_CSR_LSION                  0
#define RCC_CSR_LSIRDY                 1
#define RCC_CSR_RMVF                   24
#define RCC_CSR_BORRSTF                25
#define RCC_CSR_PINRSTF                26
#define RCC_CSR_PORRSTF                27
#define RCC_CSR_SFTRSTF                28
#define RCC_CSR_IWDGRSTF               29
#define RCC_CSR_WWDGRSTF               30
#define RCC_CSR_LPWRRSTF               31
/*  Bit definition for RCC_SSCGR register  */
#define RCC_SSCGR_MODPER               0
#define RCC_SSCGR_INCSTEP              13
#define RCC_SSCGR_SPREADSEL            30
#define RCC_SSCGR_SSCGEN               31
/*  Bit definition for RCC_PLLI2SCFGR register  */
#define RCC_PLLI2SCFGR_PLLI2SN         6
#define RCC_PLLI2SCFGR_PLLI2SN_0       6
#define RCC_PLLI2SCFGR_PLLI2SN_1       7
#define RCC_PLLI2SCFGR_PLLI2SN_2       8
#define RCC_PLLI2SCFGR_PLLI2SN_3       9
#define RCC_PLLI2SCFGR_PLLI2SN_4       10
#define RCC_PLLI2SCFGR_PLLI2SN_5       11
#define RCC_PLLI2SCFGR_PLLI2SN_6       12
#define RCC_PLLI2SCFGR_PLLI2SN_7       13
#define RCC_PLLI2SCFGR_PLLI2SN_8       14
#define RCC_PLLI2SCFGR_PLLI2SR         28
#define RCC_PLLI2SCFGR_PLLI2SR_0       28
#define RCC_PLLI2SCFGR_PLLI2SR_1       28
#define RCC_PLLI2SCFGR_PLLI2SR_2       29

/*
==================================================
  End   Section --> Bit definitions
==================================================
*/


#endif /* HMCAL_RCC_RCC_DEFS_H_ */
