/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : TP3_ex1.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Init_Led1(void);
void Led1_On(void);
void Led1_Off(void);

// Numéro du pin du LED2
#define LED_PIN 5


/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


  /* A COMPLETER */
  	//infinite loop
  	Init_Led1();
  	while(1){
  		Led1_On();
  		HAL_Delay(1000);
  		Led1_Off();
  	}

}


void Init_Led1(void){
	/* A COMPLETER */
	//activate clock for GPIOA
	RCC->AHB1ENR |= 1;
	//Set GPIOA pin 5 output mode selection
	/*
	Etant donnée la structure des registres MODER, OTYPER, OSPEEDR, PUPDR;
	il faut faire un décalage de NUM_PIN*2 pour arriver aux bits qui lui correspondent.
	Dans notre cas: MODER5[1,0]
	*/
	// Décalage de LED_PIN*2 de la valeur 01
	GPIOA->MODER  |=  (0x1 << (LED_PIN*2));
	//Set GPIOA pin 5 type
	GPIOA->OTYPER &= (1 << LED_PIN);
	//Set GPIOA pin 5 speed
	GPIOA->OSPEEDR |= (0x3 << (LED_PIN*2));
	//Set GPIOA pin 5 pull-up/pull-down
	GPIOA->PUPDR |= (0x3 << (LED_PIN*2));
}

void Led1_On(void){
	/* A COMPLETER */
	// Activate LED by setting GPIO_BSRR_BS_5 flag n°5 of BSSR register (GPIOA5-> LD1)
	// Le bit LED_PIN==5 corresponds au bit set du PIN 5 (1 = set, 0 = rien)
    GPIOA->BSRR = (1 << LED_PIN);
}


void Led1_Off(void){
	/* A COMPLETER */
	// Deactivate LED by resetting (GPIO_BSRR_BR_5) flag n°5 of BSSR register (GPIOA5-> LD1)
	// Le bit LED_PIN==21 corresponds au bit reset du PIN 5 (1 = reset, 0 = rien)
	GPIOA->BSRR = (1 << 21);
}



/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}



/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
