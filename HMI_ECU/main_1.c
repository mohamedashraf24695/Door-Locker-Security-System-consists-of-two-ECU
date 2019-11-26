#include "Tasks.h"


/*Structure to hold the PW values of the HMI ECU*/
Password_ConfigType PassWord_Configuration_HMI;



int main(void) {

	/*Init_Func to Initiate the system of the ECU*/
	Init_Fun();


	/*Get Password from the user and Checking it */
	Get_Password(&PassWord_Configuration_HMI);


	/*After Getting a checked PW , Send it to the Ctrl ECU*/
	SendPassword(&PassWord_Configuration_HMI);

	while (1) {

		/*Show to the user the options of the system
				 * on a LCD to choose an action to be transfered to
				 * the Ctrl ECU and be performed
				 * */
		Menu();

		/*Take the action from keypad and stored it in
				 * a variable*/
		Menu_Option = KeyPad_getPressedKey();
		_delay_ms(200);


		/*Condition Checking variables */
		uint8 loop_Checking_1;
		uint8 loop_Checking_2;



		if (Option_Select(Menu_Option) == FALSE) {
			/*Do Nothing and Return to Menu*/
		}

		else if (Option_Select(Menu_Option) == CHANGE_PW) {
			uint8 Attemps;
			do {
				/*Send to the ECU_2 Password change Request*/
				/*Request from the user the password and send it
				 * to Ctrl ECU */
				Change_PW_ECU1();

				uint8 check_status = UART_recieveByte();

				if (check_status == TRUE) {

					Get_Password(&PassWord_Configuration_HMI);
					/*Send The Password to ECU_2 */
					SendPassword(&PassWord_Configuration_HMI);
					_delay_ms(200);
					MSG("PW is Changed");
					loop_Checking_1 = TRUE;

				} else {
					loop_Checking_1 = FALSE;
					Attemps++;
				}

				/*Make the user to re-enter the password
				 * only Three times , after that ,
				 * Return to main menu*/
			} while (loop_Checking_1 == FALSE && Attemps < 3);

			Attemps = 0;
		}

		else if (Option_Select(Menu_Option) == OPEN_DOOR) {

			uint8 Attemps;

			do {
				/*Send to the ECU_2 Password change Request*/
				/*Request from the user the password and send it
				 * to Ctrl ECU */

				/*Take password and send password & open_door
				 * command to the Ctrl ECU */
				Oped_door_ECU1();

				uint8 check_status = UART_recieveByte();

				if (check_status == TRUE) {

					MSG("Door is UnLocking");

					uint8 Motor_finish = UART_recieveByte();


					/*This looping to make sure the motor finish
					 * its work first in the other ECU and then
					 * Go ahead to complete the code */
					while (Motor_finish != TRUE) {

					}

					loop_Checking_2 = TRUE;

				} else {
					loop_Checking_2 = FALSE;
					Attemps++;
				}
				/*Make the user to re-enter the password
								 * only Three times , after that ,
								 * Return to main menu*/
			} while (loop_Checking_2 == FALSE && Attemps < 3);

			Attemps = 0;

		}

		else {
			/*No Code*/
		}


	}

}

