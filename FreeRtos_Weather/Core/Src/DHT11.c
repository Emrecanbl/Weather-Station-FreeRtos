/*
 * DHT11.c
 *
 *  Created on: Mar 24, 2024
 *      Author: EmrecanBl
 */
#include"DHT11.h"


void delay (uint16_t time)
{
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while ((__HAL_TIM_GET_COUNTER(&htim1))<time);
}


void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}
void DHT11_Start (void)
{
	Set_Pin_Output (DHT11_PORT, DHT11_PIN);  		// set the pin as output
	HAL_GPIO_WritePin (DHT11_PORT, DHT11_PIN, 0);   // pull the pin low as Start Signal.
	delay (18000);
	HAL_GPIO_WritePin (DHT11_PORT, DHT11_PIN, 1);
	delay (40);
}
uint8_t Check_Response (void)
{

	Set_Pin_Input(DHT11_PORT, DHT11_PIN); // Set up GPIO as input for signal reading.

	uint8_t Response = 0;
	delay (50);
	if (!(HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)))
	{
		delay (70);
		if ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN))) Response = 1;
		else Response = -1;
	}
	while ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)));   // wait for the pin to go low

	return Response;
}
uint8_t DHT11_Read (void)
{
	Set_Pin_Input(DHT11_PORT, DHT11_PIN); // Set up GPIO as input for signal reading.

	uint8_t Data_Raw,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)));   // Get Ready signal
		delay (50);   // wait for 50 us
		if (!(HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)))   // if the pin is low
		{
			Data_Raw&= ~(1<<(7-j));   // write 0
		}
		else Data_Raw|= (1<<(7-j));  //  write 1
		while ((HAL_GPIO_ReadPin (DHT11_PORT, DHT11_PIN)));  // wait for the pin to go low
	}
	return Data_Raw;
}

