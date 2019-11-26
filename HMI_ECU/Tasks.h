
/* MODULE      : TASK_2
 * file type   : H file
 * AUTHOR      : Mohamed Ashraf Ibrahim
 * Description : Header file for Complex drive
 */


/*******************************************************************************
 *                          INCLUDE                                    *
 *******************************************************************************/

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
#include "keypad.h"
#include "lcd.h"
#include "uart.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define PASSWORD_SIZE 5

#define CHANGE_PW  0x07
#define OPEN_DOOR  0x10
#define OK_STATUS  0x08
#define ALERT_ENTRY   0x20
#define NO_OREDR       0x30

#define OPEN_CLOSE_TIME 5
#define WAIT_TIME 5

/*******************************************************************************
 *                      Variables deceleration                                    *
 *******************************************************************************/


typedef struct {

	uint8 PW[PASSWORD_SIZE];
	uint8 checkPW[PASSWORD_SIZE];

} Password_ConfigType;

uint8 Menu_Option;


/*******************************************************************************
 *                      FUNCTIONS PROTOTYPE                                    *
 *******************************************************************************/

void Get_Password(Password_ConfigType * Password_Config);

void Init_Fun(void);
uint8 CheckPassword(Password_ConfigType * Password_Config);
void SendPassword(Password_ConfigType * Password_Config);
void Menu(void);
void Change_PW_ECU1(void);
uint8 Option_Select(uint8 data);
void Oped_door_ECU1(void);
void MSG (uint8 *Str);
void Require_Password(void) ;
