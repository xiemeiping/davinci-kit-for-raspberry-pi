/**********************************************************************
* Filename    : 2.1.5_Keypad.cpp
* Description : obtain the key code of 4x4 Matrix Keypad
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Cavon    2016/07/01
**********************************************************************/
#include "Keypad.hpp"
#include <stdio.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {  //key code
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {1, 4, 5, 6 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12,3, 2, 0 }; //connect to the column pinouts of the keypad
//create Keypad object
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int main(){
	printf("\n");
	printf("\n");
	printf("========================================\n");
	printf("|                 Keypad               |\n");
	printf("|    ------------------------------    |\n");
	printf("|   Pin connect to #18 #23 #24 #25     |\n");
	printf("|                  MOSI #22 #27 #17    |\n");
	printf("|                                      |\n");
	printf("|             Use Keypad input         |\n");
	printf("|                                      |\n");
	printf("|                            SunFounder|\n");
	printf("========================================\n");
	printf("\n");
	printf("\n");
    if(wiringPiSetup() == -1){ //when initialize wiring failed,print message to screen
        printf("setup wiringPi failed !");
        return 1; 
    }
	char key = 0;
	keypad.setDebounceTime(50);
    while(1){
        key = keypad.getKey();  //get the state of keys
        if (key){       //if a key is pressed, print out its key code
            printf("You Pressed key :  %c \n",key);
        }
    }
    return 1;
}

