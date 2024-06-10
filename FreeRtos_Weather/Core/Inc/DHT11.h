/*
 * DHT11.h
 *
 *  Created on: Mar 24, 2024
 *      Author: EmrecanBL
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_


#include "main.h"
#define DHT11_PORT  GPIOA
#define DHT11_PIN  	GPIO_PIN_1
extern TIM_HandleTypeDef htim1;
typedef struct {
	uint16_t Temp;
	uint16_t Hum;
}Mesuerement_t;


void delay (uint16_t time);
void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void DHT11_Start (void);
uint8_t Check_Response (void);
uint8_t DHT11_Read (void);


#endif /* INC_DHT11_H_ */
