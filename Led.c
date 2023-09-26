/*
 * led.c
 *
 *  Created on: Sep 24, 2023
 *      Author: chimaochiagha
 */

#include "Led.h"
#include "main.h"
#include <stdio.h>

#define 	LED_1		12U
#define 	LED_2		13U
#define 	LED_3		14U
#define 	LED_4		15U


void LED_Setup(){
	AHB1_BUS_EN_GPIOD();
	// Set Mode of the LEDs to output
	GPIO_REG_REF.MODER &= ~((0x1 << (LED_1*2)) | (0x1 << (LED_2*2)) | (0x1 << (LED_3*2)) | (0x1 << (LED_4*2))) ;
	GPIO_REG_REF.MODER |= (0x1 << (LED_1*2));
	GPIO_REG_REF.MODER |= (0x1 << (LED_2*2));
	GPIO_REG_REF.MODER |= (0x1 << (LED_3*2));
	GPIO_REG_REF.MODER |= (0x1 << (LED_4*2) );
}


void ToggleLed1(){
	while( 1 ){
		printf("Toggling Led 1\n");
		LED_ON( LED_1 );
		DELAY_MS(250);
		LED_OFF( LED_1 );
		DELAY_MS(250);
	}
}

void ToggleLed2(){
	while( 1 ){
		printf("Toggling Led 2\n");
		LED_ON( LED_2 );
		DELAY_MS(1000);
		LED_OFF( LED_2 );
		DELAY_MS(1000);
	}
}

void ToggleLed3(){
	while( 1 ){
		printf("Toggling Led 3\n");
		LED_ON( LED_3 );
		DELAY_MS(500);
		LED_OFF( LED_3 );
		DELAY_MS(500);
	}
}

void ToggleLed4(){
	while( 1 ){
		printf("Toggling Led 4\n");
		LED_ON( LED_4 );
		DELAY_MS(750);
		LED_OFF( LED_4 );
		DELAY_MS(750);
	}
}
