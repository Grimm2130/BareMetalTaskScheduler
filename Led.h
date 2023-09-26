/*
 * Led.h
 *
 *  Created on: Sep 24, 2023
 *      Author: chimaochiagha
 */

#ifndef LED_H_
#define LED_H_

#include <stdint.h>

typedef struct Gpio_Reg_Map{

	uint32_t volatile MODER;
	uint32_t volatile OTYPER;
	uint32_t volatile OSPEEDR;
	uint32_t volatile PUPDR;
	uint32_t volatile IDR;
	uint32_t volatile ODR;
	uint32_t volatile BSRR;
	uint32_t volatile LCKR;
	uint32_t volatile AFRL;
	uint32_t volatile AFRH;

}Gpio_Reg_Map_t;


#define RCC_REG_ADDR			0x40023800U
#define RCC_AHB1_EN_REG_OFFSET	0x30U
#define RCC_AHB1_EN_REG_REF		(* ( (uint32_t volatile * const) (RCC_REG_ADDR + RCC_AHB1_EN_REG_OFFSET) ) )

// ON board LED Addresses
#define	GPIO_D_REG_ADDRESS		0x40020C00U
#define	GPIO_REG_REF			(*(Gpio_Reg_Map_t volatile * const ) GPIO_D_REG_ADDRESS )

// operation Macros
#define AHB1_BUS_EN_GPIOD()		do{ RCC_AHB1_EN_REG_REF |= 0x1 << 3;  }while(0)
#define	LED_ON( x )				do{ GPIO_REG_REF.ODR |= 0x1 << (uint32_t)x;  }while(0)
#define	LED_OFF( x )			do{ GPIO_REG_REF.ODR &= ~(0x1 << (uint32_t)x);  }while(0)


// Function Declarations
void LED_Setup();
void ToggleLed1();
void ToggleLed2();
void ToggleLed3();
void ToggleLed4();


#endif /* LED_H_ */
