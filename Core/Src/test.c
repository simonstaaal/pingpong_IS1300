/*
 * test.c
 *
 *  Created on: Nov 3, 2025
 *      Author: simonstal
 */

#include "test.h"




/**
@brief l_hit, display points after missed ball
@param1 uint8_t l_points points for left player
@param2 uint8_t r_points points for right player
@return void, no return value
*/


bool L_hit(void){
	if (HAL_GPIO_ReadPin(L_Button_GPIO_Port, L_Button_Pin) == 0){
		return true;
	}
	else {
		return false;
	}

}

bool R_hit(void)
{ if (HAL_GPIO_ReadPin(R_button_GPIO_Port, R_button_Pin) == 0) return true;
else return false;
}


void Test_buttons(void)
{
	int8_t j;
	/* Checking buttons */
	j=4;
	Led_on(j); // Light on
	while (j<9 && j>0)
	{
		if ( L_hit() == true ) // Wait for left button hit
		{
			j++; // next led to the right

			Led_on(j); // Light on
			HAL_Delay(100); // 100 ms
			while ( L_hit() == true ); // Wait for button release
				HAL_Delay(100); // 100 ms
		}
		if ( R_hit() == true ) // Wait for right button hit
		{
			j--; // next led to the left
			Led_on(j); // Light on
			HAL_Delay(100); // 100 ms
			while ( R_hit() == true ); // Wait for button release
				HAL_Delay(100); // 100 ms
		if (j<1)
			j=0; // Start again from left
		}
	}
	return;
}






void test_program(void)
{
	//test_Led();

	show_points(10,10);
}

void test_Led(void)
{
	uint8_t Lednr;
/* Loop checking that all leds can be turned on*/
for (Lednr=1; Lednr<= 8; Lednr++) {
	led_on(Lednr);
	HAL_Delay(500);
}
	led_on(9); // Turn off led 8
	HAL_Delay(1000); // 1000 ms
	return;
}
