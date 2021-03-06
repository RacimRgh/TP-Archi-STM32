
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);


/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{


  /* STM32F4xx HAL library initialization*/
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


  /*A COMPLETER */
  // Déclaration d'une structure GPIO_InitTypeDef pour la configurer et l'envoyer comme paramètre à Init
  GPIO_InitTypeDef GPIO_InitStruct;
  //Activate clock for GPIOA
  __HAL_RCC_GPIOA_CLK_ENABLE();
  
  // Initialisation GPIOA: Pin 5
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  // Initialisation du type de sortie: Push Pull
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  // Initialisation pull down
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  // Initialisation de la vitesse de commutatation de sortie (freq_very_high = range 50 MHz to 200 MHz)
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

  // La fonction GPIO_Init prend en paramètre le port GPIOx et la structure GPIO_InitTypeDef
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//Set default value: RESET
	
	//Infinite loop
	while(1){
		// Mettre le pin 5 à 1
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        // Délai de 1000ms = 1s
		HAL_Delay(1000);
		// Reset le pin 5 (à 0)
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	}
}


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
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
