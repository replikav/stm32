
#include <stm32f4xx.h>
#include <stm32f4_discovery.h>


void RCC_Config(void)
{
	RCC->CR &= ~(1 <<0);
	RCC ->CR  |= 1 <<  16;
	while(!(RCC ->CR & (1<<17))); //WA�T HSE ACTIVE
	RCC->CR |= 1<<19;
	RCC ->PLLCFGR =0X00000000;  // B A &B M =2
	RCC ->PLLCFGR |= (1 << 22);
	RCC ->PLLCFGR |= (4 << 0); // PLL M 4
	RCC ->PLLCFGR |= (168 << 6); 	// PLL N 168


	RCC ->CR |= (1 << 24); // PLL ON
	while(!(RCC ->CR &(1<<25))); //WA�T PLL ACTIVE
	RCC ->CFGR &= ~(1<<0);//1. B�T�N� 0 YAPTIM
	RCC ->CFGR &= ~(1<<1);		// 1. B�T�N� 1 YAPTIM SYSTEM VLOCK �S PLL ON
	while(!(RCC->CFGR &(1<<1)));

// 8 000 000 -> 168 000 000
	void GPIO_Config(void){
		RCC->AHB1ENR |= 1 <<3;  //GPIOD Clock Enable
		GPIOD->MODER |= 1 << 24; // 24. Bellegi 1 yapt�k 12 pin output oldu
		GPIOD->MODER &= ~(1 <<25);
		GPIOD->MODER |= 1 << 26; //  Bellegi 1 yapt�k 13 pin output oldu
		GPIOD->MODER &= ~(1 <<27);
		GPIOD->MODER |= 1 << 28; //  Bellegi 1 yapt�k 14 pin output oldu
		GPIOD->MODER &= ~(1 <<29);
		GPIOD->MODER |= 1 << 30; //  Bellegi 1 yapt�k 15 pin output oldu
		GPIOD->MODER &= ~(1 <<31);
		GPIOD->OSPEEDR |= 0xFF000000;
	}
}
int main(void)
{

	RCC_Config();
	SystemCoreClockUpdate();
	GPIO_Config();

  while (1)
  {
	  GPIOD->ODR |= 1 <<12;
	  GPIOD->ODR |= 1 <<13;
	  GPIOD->ODR |= 1 <<14;
	  GPIOD->ODR |= 1 <<15;
	  for(int i = 0; i< 1680000; i++);
	  GPIOD->ODR &= ~(1 <<12); // 12.P�N RESET
	  GPIOD->ODR &= ~(1 <<13);
	  GPIOD->ODR &= ~(1 <<14);
	  GPIOD->ODR &= ~(1 <<15);
	  for(int i = 0 ; i < 1680000 ; i ++ );
  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}


uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
