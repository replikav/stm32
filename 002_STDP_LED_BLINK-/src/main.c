#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
GPIO_InitTypeDef GPIO_InitiStruct;

void GPIO_Config(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD , ENABLE);
	GPIO_InitiStruct.GPIO_Pin =GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitiStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitiStruct.GPIO_OType = GPIO_OType_PP ;
	GPIO_InitiStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitiStruct.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD , &GPIO_InitStruct);



}



int main(void)
{
GPIO_Config();

  while (1)
  {
	  GPIO_SetBits(GPIOD,GPIO_Pin_12 );
	  GPIO_SetBits(GPIOD,GPIO_Pin_13 );
	  GPIO_SetBits(GPIOD,GPIO_Pin_14 );
	  GPIO_SetBits(GPIOD,GPIO_Pin_15 );
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){

  return -1;
}
