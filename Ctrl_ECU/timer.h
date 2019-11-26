/*
 * Note : I implemented here Timer0 Compare mode only because
 * This Application needs only one timer with that mode
 * So, It is not a complete timer driver
 * */

#ifndef TIMER_0
#define TIMER_0


/*******************************************************************************
 *                          INCLUDE                                    *
 *******************************************************************************/



#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define TICKS_TO_COUNT_SEC 32
#define COMPARE_MODE_VALUE 250

/*******************************************************************************
 *                      Variables deceleration                                    *
 *******************************************************************************/

extern uint8 g_tick;
extern uint8 g_flag ;
extern uint8 g_sec ;

/*******************************************************************************
 *                      FUNCTIONS PROTOTYPE                                    *
 *******************************************************************************/

void timer0_init_CTC_mode(void);
void Count_sec(uint8 no_of_sec);

#endif
