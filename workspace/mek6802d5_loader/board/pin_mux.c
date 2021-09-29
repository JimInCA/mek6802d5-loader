/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v10.0
processor: MK64FN1M0xxx12
package_id: MK64FN1M0VLL12
mcu_data: ksdk2_0
processor_version: 10.0.0
board: FRDM-K64F
pin_labels:
- {pin_num: '35', pin_signal: PTA1/UART0_RX/FTM0_CH6/JTAG_TDI/EZP_DI, label: 'J1[8]', identifier: SCOPE_TRIGGER}
- {pin_num: '36', pin_signal: PTA2/UART0_TX/FTM0_CH7/JTAG_TDO/TRACE_SWO/EZP_DO, label: 'J1[12]/J9[6]/TRACE_SWO', identifier: UART_TX}
- {pin_num: '64', pin_signal: PTB18/CAN0_TX/FTM2_CH0/I2S0_TX_BCLK/FB_AD15/FTM2_QD_PHA, label: 'J1[1]', identifier: CMP0_UART_TX}
- {pin_num: '77', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/I2S0_RXD0/FB_AD10/CMP0_OUT/FTM0_CH2, label: 'J1[15]', identifier: CMP0_OUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '62', peripheral: UART0, signal: RX, pin_signal: PTB16/SPI1_SOUT/UART0_RX/FTM_CLKIN0/FB_AD17/EWM_IN}
  - {pin_num: '63', peripheral: UART0, signal: TX, pin_signal: PTB17/SPI1_SIN/UART0_TX/FTM_CLKIN1/FB_AD16/EWM_OUT_b}
  - {pin_num: '35', peripheral: GPIOA, signal: 'GPIO, 1', pin_signal: PTA1/UART0_RX/FTM0_CH6/JTAG_TDI/EZP_DI, direction: OUTPUT, pull_select: down, pull_enable: disable}
  - {pin_num: '64', peripheral: GPIOB, signal: 'GPIO, 18', pin_signal: PTB18/CAN0_TX/FTM2_CH0/I2S0_TX_BCLK/FB_AD15/FTM2_QD_PHA, direction: OUTPUT, drive_strength: high}
  - {pin_num: '77', peripheral: CMP0, signal: OUT, pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/I2S0_RXD0/FB_AD10/CMP0_OUT/FTM0_CH2}
  - {pin_num: '79', peripheral: CMP0, signal: 'IN, 1', pin_signal: CMP0_IN1/PTC7/SPI0_SIN/USB_SOF_OUT/I2S0_RX_FS/FB_AD8}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);

    gpio_pin_config_t SCOPE_TRIGGER_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA1 (pin 35)  */
    GPIO_PinInit(BOARD_SCOPE_TRIGGER_GPIO, BOARD_SCOPE_TRIGGER_PIN, &SCOPE_TRIGGER_config);

    gpio_pin_config_t CMP0_UART_TX_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB18 (pin 64)  */
    GPIO_PinInit(BOARD_CMP0_UART_TX_GPIO, BOARD_CMP0_UART_TX_PIN, &CMP0_UART_TX_config);

    /* PORTA1 (pin 35) is configured as PTA1 */
    PORT_SetPinMux(BOARD_SCOPE_TRIGGER_PORT, BOARD_SCOPE_TRIGGER_PIN, kPORT_MuxAsGpio);

    PORTA->PCR[1] = ((PORTA->PCR[1] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PS_MASK | PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Select: Internal pulldown resistor is enabled on the corresponding pin, if the
                      * corresponding PE field is set. */
                     | PORT_PCR_PS(kPORT_PullDown)

                     /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
                     | PORT_PCR_PE(kPORT_PullDisable));

    /* PORTB16 (pin 62) is configured as UART0_RX */
    PORT_SetPinMux(BOARD_DEBUG_UART_RX_PORT, BOARD_DEBUG_UART_RX_PIN, kPORT_MuxAlt3);

    /* PORTB17 (pin 63) is configured as UART0_TX */
    PORT_SetPinMux(BOARD_DEBUG_UART_TX_PORT, BOARD_DEBUG_UART_TX_PIN, kPORT_MuxAlt3);

    /* PORTB18 (pin 64) is configured as PTB18 */
    PORT_SetPinMux(BOARD_CMP0_UART_TX_PORT, BOARD_CMP0_UART_TX_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[18] = ((PORTB->PCR[18] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_DSE_MASK | PORT_PCR_ISF_MASK)))

                      /* Drive Strength Enable: High drive strength is configured on the corresponding pin, if
                       * pin is configured as a digital output. */
                      | PORT_PCR_DSE(kPORT_HighDriveStrength));

    /* PORTC5 (pin 77) is configured as CMP0_OUT */
    PORT_SetPinMux(BOARD_CMP0_OUT_PORT, BOARD_CMP0_OUT_PIN, kPORT_MuxAlt6);

    /* PORTC7 (pin 79) is configured as CMP0_IN1 */
    PORT_SetPinMux(BOARD_CMP0_IN1_PORT, BOARD_CMP0_IN1_PIN, kPORT_PinDisabledOrAnalog);

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART0TXSRC_MASK)))

                  /* UART 0 transmit data source select: UART0_TX pin. */
                  | SIM_SOPT5_UART0TXSRC(SOPT5_UART0TXSRC_UART_TX));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
