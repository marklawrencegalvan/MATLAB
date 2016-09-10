// Name: Mark Lawrence Galvan (818661916)
// Lab 2: Morse Code BRUTE FORCE

/* Description: This program will produces the morse code equivalent of my name and REDid through 
				calling the child functions such as dot, dash, and delay from the main class. First,
				the my name and my REDid is stored in a char array. Then,defined the how long the dot, 
				dash and delay blink respectively. Then, at the main class,I used the for loop which if 
				and else-if statements to check whether the element of an array is an alphabet or a digit.
				Then, it proceeds by determining what letter or number specifically the character is from the switch 
				statement.*/


/*
 * BlinkLed328PXplained.c
 * Blinks the LED on the Xplained mini board fast!
 * Created: 8/15/2015 4:26:25 PM
 *  Author: Ken "BMPPH" Arnold
 */ 

#define F_CPU 16000000UL // 16MHz clock from the debug processor
#include <avr/io.h>
#include <util/delay.h>
#include <ctype.h>

// Child function called dot that turns on for 200mS and turns off for another 200mS
void dot()
{
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(200); // delay 200mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(200); // delay 200mS
}

// Child function called dash that turns on for 800mS and turns of for 200mS
void dash()
{
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(800); // delay 800mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(200); // delay 200mS
}

// Child function called delay that turns off for 200mS
void delay()
{
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(3000); // delay 200mS
}

// Child function called space that blinks rapidly to tell the user that space has been scanned by the board
void space()
{
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(100); // delay 800mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(100); // delay 200mS
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(100); // delay 800mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(100); // delay 200mS
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(100); // delay 800mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(100); // delay 200mS
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(100); // delay 800mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(100); // delay 200mS
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(100); // delay 800mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(100); // delay 200mS
	PORTB |= (1<<PORTB5); // Set port bit B5 to 1 to turn on the LED
	_delay_ms(100); // delay 800mS
	PORTB &= (0<<PORTB5); // Clear port bit B5 to 0 to turn off the LED
	_delay_ms(100); // delay 200mS
}

int main(void)
{
	char myString[] = "Lawrence Galvan 818661916";
	int i; // for counter
    
	//LED 0 on the board is connected to AVR port pin B5 (pin #17 on the 328P)
	DDRB |= (1<<DDB5); // Set port bit B5 in data direction register to 1: an OUTput
	
	// For looop that will convert the alphabetic characters into an uppercase letter
	for(i=0;i<26;i++) 
	{
		myString[i] = toupper(myString[i]);
	}

	while(1) // will loop infinitely
    {
		// For loop that will scan the char array name myString
		for(i=0;i<26;i++) 
		{
			// checks if an element of the string array is an alphabet character
			if(isalpha(myString[i]))
			{
				switch(myString[i])
				{
					case ('A'): dot();  dash();  delay(); break;
					case ('B'): dash(); dot(); dot(); dot(); delay(); break;
					case ('C'): dash(); dot(); dash(); dot(); delay(); break;
					case ('D'): dash(); dot(); dot(); delay(); break;
					case ('E'): dot(); delay(); break;
					case ('F'): dot(); dot(); dash(); dot(); delay(); break;
					case ('G'): dash(); dash(); dot(); delay(); break;
					case ('H'): dot(); dot(); dot(); dot(); break;
					case ('I'): dot(); dot(); break;
					case ('J'): dot(); dash(); dash(); dash(); break;
					case ('K'): dash(); dot(); dash(); break;
					case ('L'): dot(); dash(); dot(); dot(); delay(); break;
					case ('M'): dash(); dash(); delay(); break;
					case ('N'): dash(); dot(); delay(); break;
					case ('O'): dash(); dash(); dash(); delay(); break;
					case ('P'): dot(); dash(); dash(); dot(); delay(); break;
					case ('Q'): dash(); dash(); dot(); dash(); delay(); break;
					case ('R'): dot(); dash(); dot();delay(); break;
					case ('S'): dot(); dot(); dot(); delay(); break;
					case ('T'): dash(); delay(); break;
					case ('U'): dot(); dot(); dash(); delay(); break;
					case ('V'): dot(); dot(); dot(); dash(); delay(); break;
					case ('W'): dot(); dash(); dash(); delay(); break;
					case ('X'): dash(); delay(); dot(); delay(); dot(); delay(); dash(); delay(); break;
					case ('Y'): dash(); dot(); dash(); dash(); delay(); break;
					case ('Z'): dash(); dash(); dot(); dot(); delay(); break;
					default: break;
				} // end of switch
			}// end of if isalpha

			// checks if an element of the string array is a digit character
			else if(isdigit(myString[i])) 
			{
				switch(myString[i])
				{
					case ('1'): dot();  dash(); dash(); dash(); dash();  delay(); break;
					case ('2'): dot(); dot(); dash(); dash(); dash(); delay(); break;
					case ('3'): dot(); dot(); dot(); dash(); dash(); delay(); break;
					case ('4'): dot(); dot(); dot(); dot(); dash(); delay(); break;
					case ('5'): dot(); dot(); dot(); dot(); dot(); delay(); break;
					case ('6'): dash(); dot(); dot(); dot(); dot(); delay(); break;
					case ('7'): dash(); dash(); dot(); dot(); dot(); delay(); break;
					case ('8'): dash(); dash(); dash(); dot(); dot(); delay(); break;
					case ('9'): dash(); dash(); dash(); dash(); dot(); delay(); break;
					case ('0'): dash(); dash(); dash(); dash(); dash(); delay(); break;
					default: break;
				} // end of switch
			}// end of if isdigit

			// checks if the element of the character is a space
			// I coded it to blink repetitively in order to recognize that a space has been scanned by the for loop
			else if(myString[i] == ' ')
			{
				space(); space(); delay();
			}
		} // end of for loop	
	}// end of while
} // end of main

