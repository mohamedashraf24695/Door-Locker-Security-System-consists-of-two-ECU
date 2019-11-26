#include "Tasks_2.h"

Password_ConfigType PassWord_Configuration_CTRL;
Password_EEPROM_ConfigType PassWord_Configuration_EEPROM;


uint8 error_counter;
int main(void) {
	Init_Fun();
	RecievePassword(&PassWord_Configuration_CTRL);

	/*ShowPassword(&PassWord_Configuration_CTRL);*/

	SavePassword_EEPROM(&PassWord_Configuration_CTRL);
	ReadPassword_EEPROM( Begining_Address, &PassWord_Configuration_EEPROM);

	while (1) {

		uint8 rec_data = Recieve_Option_Select();

		if (rec_data == CHANGE_PW) {


			/*Get the Password entered by the user*/
			Entered_PW_ECU2(&PassWord_Configuration_EEPROM);


			/*Check on the Password , is that same to the one in EEPROM ?*/
			uint8 check_status = CheckPassword(&PassWord_Configuration_EEPROM);

			/*Send to the HMI Is that password is Right or Wrong */
			UART_sendByte(check_status);

			if (check_status == TRUE) {

				/*If the Password is right */
				RecievePassword(&PassWord_Configuration_CTRL);
				SavePassword_EEPROM(&PassWord_Configuration_CTRL);
				ReadPassword_EEPROM( Begining_Address,
						&PassWord_Configuration_EEPROM);


			}


		}

		else if (rec_data == OPEN_DOOR) {
			/*Get the Password entered by the user*/
			Entered_PW_ECU2(&PassWord_Configuration_EEPROM);

			/*Check on the Password , is that same to the one in EEPROM ?*/
			uint8 check_status = CheckPassword(&PassWord_Configuration_EEPROM);

			/*Send to the HMI Is that password is Right or Wrong */
			UART_sendByte(check_status);

			if (check_status == TRUE) {
				Control_door(OPEN_CLOSE_TIME, WAIT_TIME);

				/*Send to the HMI ECU That the Motor
				 * finished its work*/
				UART_sendByte(TRUE);

			}

		}

		else {
			/*No Code*/
		}



	}

}
