
#include "button.h"
#include "main.h"

static GPIO_PinState buttonBuffer[NUM_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NUM_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NUM_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NUM_OF_BUTTONS];

static uint8_t flagForLongPress3s[NUM_OF_BUTTONS];
static uint16_t counterLongPress3s[NUM_OF_BUTTONS];

int button_flag[NUM_OF_BUTTONS];

//void readKeyInput() {
//	for (int i=0; i < NUM_OF_BUTTONS; i++){
//		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
//		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
//
//		if(i == BTN_SELECT_INDEX) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN_SELECT_GPIO_Port, BTN_SELECT_Pin);
//		else if(i == BTN_MODIFY_INDEX) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN_MODIFY_GPIO_Port, BTN_MODIFY_Pin);
//		else if(i == BTN_SET_INDEX) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN_SET_GPIO_Port, BTN_SET_Pin);
//
//
//		if ((debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) && (debounceButtonBuffer1[i] == debounceButtonBuffer3[i])) {
//			if (buttonBuffer[i] == BTN_RELEASED && debounceButtonBuffer1[i] == BTN_PRESSED) {
//				button_flag[i] = 1;
//			}
//			buttonBuffer[i] = debounceButtonBuffer1[i];
//		}
//
//		// LONGPRESSED 3S
//		if (buttonBuffer[i] == BTN_PRESSED) {
//			if (counterLongPress3s[i] < PRESSED_DURATION_3S/TIMER_CYCLE) {
//				counterLongPress3s[i]++;
//			} else {
//				flagForLongPress3s[i] = 1;
//			}
//		} else {
//			button_flag[i] = 0;
//			counterLongPress3s[i] = 0;
//			flagForLongPress3s[i] = 0;
//		}
//	}
//}

/*
void readKeyInput() {
	for (int i=0; i < NUM_OF_BUTTONS; i++){
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];

//		if(i == BTN_SELECT_INDEX) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN_SELECT_GPIO_Port, BTN_SELECT_Pin);
//		else if(i == BTN_MODIFY_INDEX) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN_MODIFY_GPIO_Port, BTN_MODIFY_Pin);
//		else if(i == BTN_SET_INDEX) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN_SET_GPIO_Port, BTN_SET_Pin);

		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin);

		if ((debounceButtonBuffer1[i] == debounceButtonBuffer2[i]) && (debounceButtonBuffer1[i] == debounceButtonBuffer3[i])) {
			if (buttonBuffer[i] == BTN_RELEASED && debounceButtonBuffer1[i] == BTN_PRESSED) {
				button_flag[i] = 1;
			}
			buttonBuffer[i] = debounceButtonBuffer1[i];
		}

		// LONGPRESSED 3S
		if (buttonBuffer[i] == BTN_PRESSED) {
			if (counterLongPress3s[i] < PRESSED_DURATION_3S/TIMER_CYCLE) {
				counterLongPress3s[i]++;
			} else {
				flagForLongPress3s[i] = 1;
			}
		} else {
			button_flag[i] = 0;
			counterLongPress3s[i] = 0;
			flagForLongPress3s[i] = 0;
		}
	}
}

*/

int isPressedAndReleased(int buttonIndex) {
	if (button_flag[buttonIndex] == 1) {
		button_flag[buttonIndex] = 0;
		return 1;
	}
	return 0;
}

unsigned char is_button_pressed (uint8_t index) {
	if(index >= NUM_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BTN_PRESSED);
}
unsigned char is_button_pressed_3s(unsigned char index) {
	if(index >= NUM_OF_BUTTONS) return 0xff ;
	return (flagForLongPress3s[index] == 1) ;
}


