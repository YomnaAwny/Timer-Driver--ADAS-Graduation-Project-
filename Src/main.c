

#include"App_IC.h"

int main(void) {

	Timer2_init();
	TIM2TO5_Init_InputCaptureMode();
	UltraSonic_Pin_Init();
	Led_Init();

	while(1){

		UltraSonic_Init();

		dms(50);

	}
}


