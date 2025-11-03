/**
******************************************************************************
@brief Pingpong, functions for Pingpong-program
@file pingpong_functions.c
@author Simon Stål, Lucas Pirvall, Hugo Förnell, Hannes Pålsson
@version 1.0
@date 03-November-2025
@brief Functions and structures for program Pingpong
******************************************************************************
*/

#include "pingpong_functions.h"

/**
@brief led_on, turn one of the pingpong leds on
@param uint8_t Lednr , number to the Led that is turned on
Lednr can be 1-8, all other values turns all leds off
@return void
*/
void led_on(uint8_t Lednr)
{
	uint8_t i;
	for (i=1; i<= 8; i++)
	{

		switch(i){
		case 1 : // Led 1
			if (Lednr==i) HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_RESET);
			break;
		case 2 : // Led 2
			if (Lednr==i) HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_RESET);
			break;
		case 3 : // Led 3
			if (Lednr==i) HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_RESET);
			break;
		case 4 : // Led 4
			if (Lednr==i) HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_RESET);
			break;
		case 5 : // Led 5
			if (Lednr==i) HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_RESET);
			break;
		case 6 : // Led 6
			if (Lednr==i) HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_RESET);
			break;
		case 7 : // Led 7
			if (Lednr==i) HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_RESET);
			break;
		case 8 : // Led 8
			if (Lednr==i) HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
			else HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_RESET);
			break;
		default :
			;
		} // end switch
	} // end for-loop
	return;
} // end function Led_on


/**
@brief show_points, display points after missed ball
@param1 uint8_t l_points points for left player
@param2 uint8_t r_points points for right player
@return void, no return value
*/
void show_points(uint8_t l_points, uint8_t r_points){

	if((l_points || r_points > 4 ) || (l_points || r_points < 0) ){
		return;
	}
	int k = 8;

	for(int i = 1; i <= 4; i++){

		if(l_points >= i){

			one_led_on(i);
		}


		if((r_points >= i) ){

			one_led_on(k);
			k--;
		}
		HAL_Delay(500);

	}

}




void one_led_on(uint8_t Lednr){

	switch(Lednr){
	case 1 : // Led 1
		 HAL_GPIO_WritePin(L1_GPIO_Port, L1_Pin, GPIO_PIN_SET);
		break;
	case 2 : // Led 2
		HAL_GPIO_WritePin(L2_GPIO_Port, L2_Pin, GPIO_PIN_SET);
		break;
	case 3 : // Led 3
		 HAL_GPIO_WritePin(L3_GPIO_Port, L3_Pin, GPIO_PIN_SET);
		break;
	case 4 : // Led 4
		 HAL_GPIO_WritePin(L4_GPIO_Port, L4_Pin, GPIO_PIN_SET);
		break;
	case 5 : // Led 5
		 HAL_GPIO_WritePin(L5_GPIO_Port, L5_Pin, GPIO_PIN_SET);
		break;
	case 6 : // Led 6
		HAL_GPIO_WritePin(L6_GPIO_Port, L6_Pin, GPIO_PIN_SET);
		break;
	case 7 : // Led 7
		 HAL_GPIO_WritePin(L7_GPIO_Port, L7_Pin, GPIO_PIN_SET);
		break;
	case 8 : // Led 8
		HAL_GPIO_WritePin(L8_GPIO_Port, L8_Pin, GPIO_PIN_SET);
		break;
	default :
		;
	} // end switch

return;

}
