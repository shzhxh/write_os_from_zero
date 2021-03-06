#ifndef __DRIVER_SYSCTL_H__
#define __DRIVER_SYSCTL_H__

#include <stdint.h>

typedef struct _sysctl_git_id
{
    uint32_t git_id : 32;
} __attribute__((packed, aligned(4))) sysctl_git_id_t;

typedef struct _sysctl_clk_freq
{
    uint32_t clk_freq : 32;
} __attribute__((packed, aligned(4))) sysctl_clk_freq_t;

typedef struct _sysctl_pll0
{
    uint32_t clkr0 : 4;
    uint32_t clkf0 : 6;
    uint32_t clkod0 : 4;
    uint32_t bwadj0 : 6;
    uint32_t pll_reset0 : 1;
    uint32_t pll_pwrd0 : 1;
    uint32_t pll_intfb0 : 1;
    uint32_t pll_bypass0 : 1;
    uint32_t pll_test0 : 1;
    uint32_t pll_out_en0 : 1;
    uint32_t pll_test_en : 1;
    uint32_t reserved : 5;
} __attribute__((packed, aligned(4))) sysctl_pll0_t;

typedef struct _sysctl_pll1
{
    uint32_t clkr1 : 4;
    uint32_t clkf1 : 6;
    uint32_t clkod1 : 4;
    uint32_t bwadj1 : 6;
    uint32_t pll_reset1 : 1;
    uint32_t pll_pwrd1 : 1;
    uint32_t pll_intfb1 : 1;
    uint32_t pll_bypass1 : 1;
    uint32_t pll_test1 : 1;
    uint32_t pll_out_en1 : 1;
    uint32_t reserved : 6;
} __attribute__((packed, aligned(4))) sysctl_pll1_t;

typedef struct _sysctl_pll2
{
    uint32_t clkr2 : 4;
    uint32_t clkf2 : 6;
    uint32_t clkod2 : 4;
    uint32_t bwadj2 : 6;
    uint32_t pll_reset2 : 1;
    uint32_t pll_pwrd2 : 1;
    uint32_t pll_intfb2 : 1;
    uint32_t pll_bypass2 : 1;
    uint32_t pll_test2 : 1;
    uint32_t pll_out_en2 : 1;
    uint32_t pll_ckin_sel2 : 2;
    uint32_t reserved : 4;
} __attribute__((packed, aligned(4))) sysctl_pll2_t;

typedef struct _sysctl_pll_lock
{
    uint32_t pll_lock0 : 2;
    uint32_t pll_slip_clear0 : 1;
    uint32_t test_clk_out0 : 1;
    uint32_t reserved0 : 4;
    uint32_t pll_lock1 : 2;
    uint32_t pll_slip_clear1 : 1;
    uint32_t test_clk_out1 : 1;
    uint32_t reserved1 : 4;
    uint32_t pll_lock2 : 2;
    uint32_t pll_slip_clear2 : 1;
    uint32_t test_clk_out2 : 1;
    uint32_t reserved2 : 12;
} __attribute__((packed, aligned(4))) sysctl_pll_lock_t;

typedef struct _sysctl_rom_error
{
    uint32_t rom_mul_error : 1;
    uint32_t rom_one_error : 1;
    uint32_t reserved : 30;
} __attribute__((packed, aligned(4))) sysctl_rom_error_t;

typedef struct _sysctl_clk_sel0
{
    uint32_t aclk_sel : 1;
    uint32_t aclk_divider_sel : 2;
    uint32_t apb0_clk_sel : 3;
    uint32_t apb1_clk_sel : 3;
    uint32_t apb2_clk_sel : 3;
    uint32_t spi3_clk_sel : 1;
    uint32_t timer0_clk_sel : 1;
    uint32_t timer1_clk_sel : 1;
    uint32_t timer2_clk_sel : 1;
    uint32_t reserved : 16;
} __attribute__((packed, aligned(4))) sysctl_clk_sel0_t;

typedef struct _sysctl_clk_sel1
{
    uint32_t spi3_sample_clk_sel : 1;
    uint32_t reserved0 : 30;
    uint32_t reserved1 : 1;
} __attribute__((packed, aligned(4))) sysctl_clk_sel1_t;

typedef struct _sysctl_clk_en_cent
{
    uint32_t cpu_clk_en : 1;
    uint32_t sram0_clk_en : 1;
    uint32_t sram1_clk_en : 1;
    uint32_t apb0_clk_en : 1;
    uint32_t apb1_clk_en : 1;
    uint32_t apb2_clk_en : 1;
    uint32_t reserved : 26;
} __attribute__((packed, aligned(4))) sysctl_clk_en_cent_t;

typedef struct _sysctl_clk_en_peri
{
    uint32_t rom_clk_en : 1;
    uint32_t dma_clk_en : 1;
    uint32_t ai_clk_en : 1;
    uint32_t dvp_clk_en : 1;
    uint32_t fft_clk_en : 1;
    uint32_t gpio_clk_en : 1;
    uint32_t spi0_clk_en : 1;
    uint32_t spi1_clk_en : 1;
    uint32_t spi2_clk_en : 1;
    uint32_t spi3_clk_en : 1;
    uint32_t i2s0_clk_en : 1;
    uint32_t i2s1_clk_en : 1;
    uint32_t i2s2_clk_en : 1;
    uint32_t i2c0_clk_en : 1;
    uint32_t i2c1_clk_en : 1;
    uint32_t i2c2_clk_en : 1;
    uint32_t uart1_clk_en : 1;
    uint32_t uart2_clk_en : 1;
    uint32_t uart3_clk_en : 1;
    uint32_t aes_clk_en : 1;
    uint32_t fpioa_clk_en : 1;
    uint32_t timer0_clk_en : 1;
    uint32_t timer1_clk_en : 1;
    uint32_t timer2_clk_en : 1;
    uint32_t wdt0_clk_en : 1;
    uint32_t wdt1_clk_en : 1;
    uint32_t sha_clk_en : 1;
    uint32_t otp_clk_en : 1;
    uint32_t reserved : 1;
    uint32_t rtc_clk_en : 1;
    uint32_t reserved0 : 2;
} __attribute__((packed, aligned(4))) sysctl_clk_en_peri_t;

typedef struct _sysctl_soft_reset
{
    uint32_t soft_reset : 1;
    uint32_t reserved : 31;
} __attribute__((packed, aligned(4))) sysctl_soft_reset_t;

typedef struct _sysctl_peri_reset
{
    uint32_t rom_reset : 1;
    uint32_t dma_reset : 1;
    uint32_t ai_reset : 1;
    uint32_t dvp_reset : 1;
    uint32_t fft_reset : 1;
    uint32_t gpio_reset : 1;
    uint32_t spi0_reset : 1;
    uint32_t spi1_reset : 1;
    uint32_t spi2_reset : 1;
    uint32_t spi3_reset : 1;
    uint32_t i2s0_reset : 1;
    uint32_t i2s1_reset : 1;
    uint32_t i2s2_reset : 1;
    uint32_t i2c0_reset : 1;
    uint32_t i2c1_reset : 1;
    uint32_t i2c2_reset : 1;
    uint32_t uart1_reset : 1;
    uint32_t uart2_reset : 1;
    uint32_t uart3_reset : 1;
    uint32_t aes_reset : 1;
    uint32_t fpioa_reset : 1;
    uint32_t timer0_reset : 1;
    uint32_t timer1_reset : 1;
    uint32_t timer2_reset : 1;
    uint32_t wdt0_reset : 1;
    uint32_t wdt1_reset : 1;
    uint32_t sha_reset : 1;
    uint32_t reserved : 2;
    uint32_t rtc_reset : 1;
    uint32_t reserved0 : 2;
} __attribute__((packed, aligned(4))) sysctl_peri_reset_t;

typedef struct _sysctl_clk_th0
{
    uint32_t sram0_gclk_threshold : 4;
    uint32_t sram1_gclk_threshold : 4;
    uint32_t ai_gclk_threshold : 4;
    uint32_t dvp_gclk_threshold : 4;
    uint32_t rom_gclk_threshold : 4;
    uint32_t reserved : 12;
} __attribute__((packed, aligned(4))) sysctl_clk_th0_t;

typedef struct _sysctl_clk_th1
{
    uint32_t spi0_clk_threshold : 8;
    uint32_t spi1_clk_threshold : 8;
    uint32_t spi2_clk_threshold : 8;
    uint32_t spi3_clk_threshold : 8;
} __attribute__((packed, aligned(4))) sysctl_clk_th1_t;

typedef struct _sysctl_clk_th2
{
    uint32_t timer0_clk_threshold : 8;
    uint32_t timer1_clk_threshold : 8;
    uint32_t timer2_clk_threshold : 8;
    uint32_t reserved : 8;
} __attribute__((packed, aligned(4))) sysctl_clk_th2_t;

typedef struct _sysctl_clk_th3
{
    uint32_t i2s0_clk_threshold : 16;
    uint32_t i2s1_clk_threshold : 16;
} __attribute__((packed, aligned(4))) sysctl_clk_th3_t;

typedef struct _sysctl_clk_th4
{
    uint32_t i2s2_clk_threshold : 16;
    uint32_t i2s0_mclk_threshold : 8;
    uint32_t i2s1_mclk_threshold : 8;
} __attribute__((packed, aligned(4))) sysctl_clk_th4_t;

typedef struct _sysctl_clk_th5
{
    uint32_t i2s2_mclk_threshold : 8;
    uint32_t i2c0_clk_threshold : 8;
    uint32_t i2c1_clk_threshold : 8;
    uint32_t i2c2_clk_threshold : 8;
} __attribute__((packed, aligned(4))) sysctl_clk_th5_t;

typedef struct _sysctl_clk_th6
{
    uint32_t wdt0_clk_threshold : 8;
    uint32_t wdt1_clk_threshold : 8;
    uint32_t reserved0 : 8;
    uint32_t reserved1 : 8;
} __attribute__((packed, aligned(4))) sysctl_clk_th6_t;

typedef struct _sysctl_misc
{
    uint32_t debug_sel : 6;
    uint32_t reserved0 : 4;
    uint32_t spi_dvp_data_enable: 1;
    uint32_t reserved1 : 21;
} __attribute__((packed, aligned(4))) sysctl_misc_t;

typedef struct _sysctl_peri
{
    uint32_t timer0_pause : 1;
    uint32_t timer1_pause : 1;
    uint32_t timer2_pause : 1;
    uint32_t timer3_pause : 1;
    uint32_t timer4_pause : 1;
    uint32_t timer5_pause : 1;
    uint32_t timer6_pause : 1;
    uint32_t timer7_pause : 1;
    uint32_t timer8_pause : 1;
    uint32_t timer9_pause : 1;
    uint32_t timer10_pause : 1;
    uint32_t timer11_pause : 1;
    uint32_t spi0_xip_en : 1;
    uint32_t spi1_xip_en : 1;
    uint32_t spi2_xip_en : 1;
    uint32_t spi3_xip_en : 1;
    uint32_t spi0_clk_bypass : 1;
    uint32_t spi1_clk_bypass : 1;
    uint32_t spi2_clk_bypass : 1;
    uint32_t i2s0_clk_bypass : 1;
    uint32_t i2s1_clk_bypass : 1;
    uint32_t i2s2_clk_bypass : 1;
    uint32_t jtag_clk_bypass : 1;
    uint32_t dvp_clk_bypass : 1;
    uint32_t debug_clk_bypass : 1;
    uint32_t reserved0 : 1;
    uint32_t reserved1 : 6;
} __attribute__((packed, aligned(4))) sysctl_peri_t;

typedef struct _sysctl_spi_sleep
{
    uint32_t ssi0_sleep : 1;
    uint32_t ssi1_sleep : 1;
    uint32_t ssi2_sleep : 1;
    uint32_t ssi3_sleep : 1;
    uint32_t reserved : 28;
} __attribute__((packed, aligned(4))) sysctl_spi_sleep_t;

typedef struct _sysctl_reset_status
{
    uint32_t reset_sts_clr : 1;
    uint32_t pin_reset_sts : 1;
    uint32_t wdt0_reset_sts : 1;
    uint32_t wdt1_reset_sts : 1;
    uint32_t soft_reset_sts : 1;
    uint32_t reserved : 27;
} __attribute__((packed, aligned(4))) sysctl_reset_status_t;

typedef struct _sysctl_dma_sel0
{
    uint32_t dma_sel0 : 6;
    uint32_t dma_sel1 : 6;
    uint32_t dma_sel2 : 6;
    uint32_t dma_sel3 : 6;
    uint32_t dma_sel4 : 6;
    uint32_t reserved : 2;
} __attribute__((packed, aligned(4))) sysctl_dma_sel0_t;

typedef struct _sysctl_dma_sel1
{
    uint32_t dma_sel5 : 6;
    uint32_t reserved : 26;
} __attribute__((packed, aligned(4))) sysctl_dma_sel1_t;

typedef struct _sysctl_power_sel
{
    uint32_t power_mode_sel0 : 1;
    uint32_t power_mode_sel1 : 1;
    uint32_t power_mode_sel2 : 1;
    uint32_t power_mode_sel3 : 1;
    uint32_t power_mode_sel4 : 1;
    uint32_t power_mode_sel5 : 1;
    uint32_t power_mode_sel6 : 1;
    uint32_t power_mode_sel7 : 1;
    uint32_t reserved : 24;
} __attribute__((packed, aligned(4))) sysctl_power_sel_t;

/**
 * @brief       System controller object
 *
 *              The System controller is a peripheral device mapped in the
 *              internal memory map, discoverable in the Configuration String.
 *              It is responsible for low-level configuration of all system
 *              related peripheral device. It contain PLL controller, clock
 *              controller, reset controller, DMA handshake controller, SPI
 *              controller, timer controller, WDT controller and sleep
 *              controller.
 */
typedef struct _sysctl{
    sysctl_git_id_t     git_id;     // 0 (0x00):Git short commit id
    sysctl_clk_freq_t   clk_freq;   // 1 (0x04):System clock base frequency
    sysctl_pll0_t       pll0;       // 2 (0x08):PLL0 controller
    sysctl_pll1_t       pll1;       // 3 (0x0c):PLL1 controller
    sysctl_pll2_t       pll2;       // 4 (0x10):PLL2 controller
    uint32_t            resv5;      // 5 (0x14):Reserved
    sysctl_pll_lock_t   pll_lock;   // 6 (0x18):PLL lock tester
    sysctl_rom_error_t  rom_error;  // 7 (0x1c):AXI ROM detector
    sysctl_clk_sel0_t   clk_sel0;   // 8 (0x20): Clock select controller0 
    sysctl_clk_sel1_t   clk_sel1;   // 9 (0x24): Clock select controller1 
    sysctl_clk_en_cent_t clk_en_cent; // 10 (0x28): Central clock enable
    sysctl_clk_en_peri_t clk_en_peri; // 11 (0x2c): Peripheral clock enable
    sysctl_soft_reset_t soft_reset;   // 12 (0x30): Soft reset ctrl
    sysctl_peri_reset_t peri_reset;   // 13 (0x34): Peripheral reset controller
    sysctl_clk_th0_t    clk_th0;    // 14 (0x38): Clock threshold controller 0
    sysctl_clk_th1_t    clk_th1;    // 15 (0x3c): Clock threshold controller 1
    sysctl_clk_th2_t    clk_th2;    // 16 (0x40): Clock threshold controller 2
    sysctl_clk_th3_t    clk_th3;    // 17 (0x44): Clock threshold controller 3
    sysctl_clk_th4_t    clk_th4;    // 18 (0x48): Clock threshold controller 4
    sysctl_clk_th5_t    clk_th5;    // 19 (0x4c): Clock threshold controller 5
    sysctl_clk_th6_t    clk_th6;    // 20 (0x50): Clock threshold controller 6
    sysctl_misc_t       misc;       // 21 (0x54): Miscellaneous controller
    sysctl_peri_t       peri;       // 22 (0x58): Peripheral controller
    sysctl_spi_sleep_t  spi_sleep;  // 23 (0x5c): SPI sleep controller
    sysctl_reset_status_t reset_status;// 24 (0x60): Reset source status
    sysctl_dma_sel0_t   dma_sel0;   // 25 (0x64): DMA handshake selector
    sysctl_dma_sel1_t   dma_sel1;   // 26 (0x68): DMA handshake selector
    sysctl_power_sel_t  power_sel;  // 27 (0x6c): IO Power Mode Select controller
    uint32_t            resv28;     // 28 (0x70): Reserved
    uint32_t            resv29;     // 29 (0x74): Reserved
    uint32_t            resv30;     // 30 (0x78): Reserved
    uint32_t            resv31;     // 31 (0x7c): Reserved
}__attribute__((packed, aligned(4))) sysctl_t;

extern volatile sysctl_t *const sysctl;

typedef enum _sysctl_pll_t{
    SYSCTL_PLL0,
    SYSCTL_PLL1,
    SYSCTL_PLL2,
    SYSCTL_PLL_MAX,
} sysctl_pll_t;

/**
 * @brief      System controller clock id
 */
typedef enum _sysctl_clock_t
{
    SYSCTL_CLOCK_PLL0,
    SYSCTL_CLOCK_PLL1,
    SYSCTL_CLOCK_PLL2,
    SYSCTL_CLOCK_CPU,
    SYSCTL_CLOCK_SRAM0,
    SYSCTL_CLOCK_SRAM1,
    SYSCTL_CLOCK_APB0,
    SYSCTL_CLOCK_APB1,
    SYSCTL_CLOCK_APB2,
    SYSCTL_CLOCK_ROM,
    SYSCTL_CLOCK_DMA,
    SYSCTL_CLOCK_AI,
    SYSCTL_CLOCK_DVP,
    SYSCTL_CLOCK_FFT,
    SYSCTL_CLOCK_GPIO,
    SYSCTL_CLOCK_SPI0,
    SYSCTL_CLOCK_SPI1,
    SYSCTL_CLOCK_SPI2,
    SYSCTL_CLOCK_SPI3,
    SYSCTL_CLOCK_I2S0,
    SYSCTL_CLOCK_I2S1,
    SYSCTL_CLOCK_I2S2,
    SYSCTL_CLOCK_I2C0,
    SYSCTL_CLOCK_I2C1,
    SYSCTL_CLOCK_I2C2,
    SYSCTL_CLOCK_UART1,
    SYSCTL_CLOCK_UART2,
    SYSCTL_CLOCK_UART3,
    SYSCTL_CLOCK_AES,
    SYSCTL_CLOCK_FPIOA,
    SYSCTL_CLOCK_TIMER0,
    SYSCTL_CLOCK_TIMER1,
    SYSCTL_CLOCK_TIMER2,
    SYSCTL_CLOCK_WDT0,
    SYSCTL_CLOCK_WDT1,
    SYSCTL_CLOCK_SHA,
    SYSCTL_CLOCK_OTP,
    SYSCTL_CLOCK_RTC,
    SYSCTL_CLOCK_ACLK = 40,
    SYSCTL_CLOCK_HCLK,
    SYSCTL_CLOCK_IN0,
    SYSCTL_CLOCK_MAX
} sysctl_clock_t;

/*
 * sysctl_pll_get_freq : get PLL frequency
 */
uint32_t sysctl_pll_get_freq(sysctl_pll_t pll);

/*
 * sysctl_clock_get_greq : get base clock frequency by clock id
 */
uint32_t sysctl_clock_get_freq(sysctl_clock_t clock);

#endif /* __DRIVER_SYSCTL_H__ */
