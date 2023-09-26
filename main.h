/*
 * main.h
 *
 *  Created on: Sep 11, 2023
 *      Author: chimaochiagha
 */

#ifndef MAIN_H_
#define MAIN_H_


#define	CLK_FREQ				16000000U												// Clock frequency

#define SRAM_START				0x20000000U												// SRAM Start Address
#define SRAM_SIZE				( 128 * 1024U )											// SRAM Address Size
#define SRAM_END				(SRAM_START + SRAM_SIZE )								// SRAM End Address

#define TASK_OFFSET				1024U					// Size of task start

#define TASK_1_START 			SRAM_END
#define TASK_2_START 			( SRAM_END - ( 1 * TASK_OFFSET ) )
#define TASK_3_START 			( SRAM_END - ( 2 * TASK_OFFSET ) )
#define TASK_4_START 			( SRAM_END - ( 3 * TASK_OFFSET ) )
#define IDLE_TASK_START			( SRAM_END - ( 4 * TASK_OFFSET ) )
#define SCHEDULER_STACK_START 	( SRAM_END - ( 5 * TASK_OFFSET ) )

#define MAX_NUM_TASKS			0x5U


// default PSR and LR values for the task
#define DEFAULT_PSR				0x01000000U
#define DEFAULT_LR				0xFFFFFFFDU

// Addresses
#define 	SHCRS				(* (uint32_t volatile * const) 0xE000ED24)
#define 	USG_FAULT			18
#define 	BUS_FAULT			17
#define 	MEM_FAULT			16

// MACROS
#define 	EN_FAULTS()			do{ 	\
										SHCRS |= (0x1 << MEM_FAULT);		\
										SHCRS |= (0x1 << BUS_FAULT);		\
										SHCRS |= (0x1 << USG_FAULT);		\
								} while(0)


// ---------- Enumerations ----------
/**
 *  Task State Enumeration
 */
typedef enum States{
	TASK_WAITING = 0x0,
	TASK_READY = 0x1
} TaskStateEnum;


// ---------- Structures ----------

// Task Structure
typedef struct Task{
	uint8_t Id;							// ID of the task
	void (*Operation) (void);			// operation of task
	TaskStateEnum volatile TaskState;	// Task current state
	uint32_t volatile StackPtr;			// Pointer to the task's Stack
	uint32_t volatile currDelay;		// Delay between task running
} Task_t;


// Systick timer control block
typedef struct {
	uint32_t volatile CSR;
	uint32_t volatile RVR;
	uint32_t volatile CVR;
	uint32_t volatile CALIB;
}SystickBlock;


// Systick Address reference
#define	SYSTICK_BLOCK				( (SystickBlock volatile * const ) 0xE000E010U )

#define SYS_CTRL_BLK_ICSR			( *( (uint32_t volatile * const ) 0xE000ED04 ) )
#define		SET_PEND_BIT()			do{ SYS_CTRL_BLK_ICSR |= 0x1 << 28; } while(0)
#define		CLEAR_PEND_BIT()		do{ SYS_CTRL_BLK_ICSR |= 0x1 << 27; } while(0)
#define PEND_BIT					28U

#define SYSTICK_TIMEOUT_MS			1U

#define MS_TO_HZ(x)					( (uint32_t) ( (1000)/ (x) )  )
#define US_TO_HZ(x)                 ( (uint32_t) ( (1000000)/ (x) )  )
#define	CLK_FREQ					16000000U										// Clock frequency

void DELAY_MS( uint32_t delay  );

#define GET_SYS_TICK_RELOAD			( CLK_FREQ / MS_TO_HZ( SYSTICK_TIMEOUT_MS ) )
#endif /* MAIN_H_ */
