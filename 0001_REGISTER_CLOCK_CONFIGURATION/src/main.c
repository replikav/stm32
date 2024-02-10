
#include <stm32f4xx.h>
#include <stm32f4_discovery.h>


void RCC_Config(void)
{
	RCC->CR &= ~(1 <<0);
	RCC ->CR  |= 1 <<  16;
	while(!(RCC ->CR &(1<<17))); //WAÝT HSE ACTIVE
	RCC->CR |= 1<<19;
	RCC ->PLLCFGR =0X00000000;  // B A &B M =2
	RCC ->PLLCFGR |= (1 << 22);
	RCC ->PLLCFGR |= (4 << 0); // PLL M 4
	RCC ->PLLCFGR |= (168 << 6); 	// PLL N 168


	RCC ->CR |= (1 << 24); // PLL ON
	while(!(RCC ->CR &(1<<25))); //WAÝT PLL ACTIVE
	RCC ->CFGR &= ~(1<<0);//1. BÝTÝNÝ 0 YAPTIM
	RCC ->CFGR &= ~(1<<1);		// 1. BÝTÝNÝ 1 YAPTIM SYSTEM VLOCK ÝS PLL ON
	while(!(RCC->CFGR &(1<<1)));

// 8 000 000 -> 168 000 000
}
int main(void)
{

	RCC_Config();
	SystemCoreClockUpdate();


  while (1)
  {

  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
