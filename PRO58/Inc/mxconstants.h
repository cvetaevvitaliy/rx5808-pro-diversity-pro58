/**
  ******************************************************************************
  * File Name          : mxconstants.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MXCONSTANT_H
#define __MXCONSTANT_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define RECEIVER_SW_Pin GPIO_PIN_15
#define RECEIVER_SW_GPIO_Port GPIOC
#define RSSI_A_ADC_Pin GPIO_PIN_0
#define RSSI_A_ADC_GPIO_Port GPIOA
#define RSSI_B_ADC_Pin GPIO_PIN_1
#define RSSI_B_ADC_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_2
#define LED_B_GPIO_Port GPIOA
#define SPI_SLAVE_SELECT_B_Pin GPIO_PIN_3
#define SPI_SLAVE_SELECT_B_GPIO_Port GPIOA
#define SPI_SLAVE_SELECT_A_Pin GPIO_PIN_4
#define SPI_SLAVE_SELECT_A_GPIO_Port GPIOA
#define SPI_DATA_Pin GPIO_PIN_5
#define SPI_DATA_GPIO_Port GPIOA
#define SPI_CLOCK_Pin GPIO_PIN_7
#define SPI_CLOCK_GPIO_Port GPIOA
#define I2C_EEPROM_SCL_Pin GPIO_PIN_10
#define I2C_EEPROM_SCL_GPIO_Port GPIOB
#define I2C_EEPROM_SDA_Pin GPIO_PIN_11
#define I2C_EEPROM_SDA_GPIO_Port GPIOB
#define BUTTON_DOWN_Pin GPIO_PIN_12
#define BUTTON_DOWN_GPIO_Port GPIOB
#define BUTTON_EB0_Pin GPIO_PIN_13
#define BUTTON_EB0_GPIO_Port GPIOB
#define BUTTON_MODE_Pin GPIO_PIN_14
#define BUTTON_MODE_GPIO_Port GPIOB
#define BUTTON_EB2_Pin GPIO_PIN_15
#define BUTTON_EB2_GPIO_Port GPIOB
#define BUTTON_UP_Pin GPIO_PIN_8
#define BUTTON_UP_GPIO_Port GPIOA
#define BUTTON_EB1_Pin GPIO_PIN_11
#define BUTTON_EB1_GPIO_Port GPIOA
#define I2C_DISPLAY_SCL_Pin GPIO_PIN_6
#define I2C_DISPLAY_SCL_GPIO_Port GPIOB
#define I2C_DISPLAY_SDA_Pin GPIO_PIN_7
#define I2C_DISPLAY_SDA_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_8
#define BUZZER_GPIO_Port GPIOB
#define LED_A_Pin GPIO_PIN_9
#define LED_A_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MXCONSTANT_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
