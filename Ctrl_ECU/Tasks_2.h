

/* MODULE      : TASK_2
 * file type   : H file
 * AUTHOR      : Mohamed Ashraf Ibrahim
 * Description : Header file for Complex drive
 */
#ifndef _TASK_2_H
#define _TASK_2_H


/*******************************************************************************
 *                          INCLUDE                                    *
 *******************************************************************************/

#include "lcd.h"
#include "uart.h"
#include "external_eeprom.h"
#include "timer.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define PASSWORD_SIZE 5
#define Begining_Address  0x0311

#define CHANGE_PW  0x07
#define OPEN_DOOR  0x10
#define ALERT_ENTRY   0x20
#define OK_STATUS  0x08

#define MOTOR_PORTX PORTD
#define MOTOR_DDRX  DDRD
#define MOTOR_PIN_1 PD6
#define MOTOR_PIN_2 PD7

#define OPEN_CLOSE_TIME 5
#define WAIT_TIME 5
#define ALERT_BUZZ_TIME 10

/*******************************************************************************
 *                      Variables deceleration                                    *
 *******************************************************************************/

typedef struct {

	uint8 PW[PASSWORD_SIZE];
	uint8 checkPW[PASSWORD_SIZE];

} Password_ConfigType;

typedef struct {

	uint8 PW_EEPROM[PASSWORD_SIZE];
	uint8 Entered_PW[PASSWORD_SIZE];

} Password_EEPROM_ConfigType;

uint8 Password_InEEPROM[PASSWORD_SIZE];

/*******************************************************************************
 *                      FUNCTIONS PROTOTYPE                                    *
 *******************************************************************************/

void Init_Fun(void);
void RecievePassword(Password_ConfigType * Password_Config);
void ShowPassword(Password_ConfigType * Password_Config);
void SavePassword_EEPROM(Password_ConfigType * Password_Config);
void ReadPassword_EEPROM(uint16 Address,
		Password_EEPROM_ConfigType * Password_Config);
uint8 CheckPassword(Password_EEPROM_ConfigType * Password_Config);
void Entered_PW_ECU2_PW_ECU2(Password_EEPROM_ConfigType * Password_Config);
uint8 Recieve_Option_Select(void);
void Control_door(uint8 open_time, uint8 wait_time);


#endif
