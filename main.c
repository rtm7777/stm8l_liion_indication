/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_it.h"    /* SDCC patch: required by SDCC for interrupts */
#include "main.h"
#include "SSD1306.h"

uint16_t welding = 0;
uint16_t welding_timer = 0;
uint16_t delay = 0;
uint16_t delay_timer = 0;
uint16_t toggle = 0;
uint16_t toggle_timer = 0;

void main(void)
{
  CLK_DeInit();

  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);

  GPIO_Config();

  TIM2_Config();

  LCD_Init();
  // LCD_Time_Init();
  LCD_Update();

  /* Initialize the Interrupt sensitivity */
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_RISE_FALL);

  enableInterrupts();

  uint16_t encoder_time = 0;
  while (1)
  {
    Delay(0xAFFF);
    // LCD_Set_Time(encoder_time);
    LCD_Update();
  }
}

static void GPIO_Config(void)
{
  GPIO_Init(GPIOC, ((GPIO_Pin_TypeDef)(GPIO_PIN_6 | GPIO_PIN_7)), GPIO_MODE_IN_PU_NO_IT);
  GPIO_Init(GPIOD, (GPIO_Pin_TypeDef)(GPIO_PIN_1), GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIOD, (GPIO_Pin_TypeDef)(GPIO_PIN_2), GPIO_MODE_IN_PU_IT);
  GPIO_Init(GPIOD, (GPIO_Pin_TypeDef)(GPIO_PIN_6), GPIO_MODE_OUT_PP_LOW_FAST);
}

static void TIM2_Config(void)
{
  TIM2_TimeBaseInit(TIM2_PRESCALER_128, ARR_Val);
  TIM2_PrescalerConfig(TIM2_PRESCALER_128, TIM2_PSCRELOADMODE_IMMEDIATE);

  TIM2_ARRPreloadConfig(ENABLE);
  
  TIM2_ITConfig(TIM2_IT_UPDATE, ENABLE);

  TIM2_Cmd(ENABLE);
}

void Start_Welding(void)
{
  GPIO_WriteHigh(GPIOD, GPIO_PIN_6); //Start welding
}

void Stop_Welding(void)
{
  GPIO_WriteLow(GPIOD, GPIO_PIN_6); //Stop welding
}

void Delay(uint16_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}
