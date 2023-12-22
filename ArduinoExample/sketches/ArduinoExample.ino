#include "LedCube4_hardware.h" // Include header file with pin definitions for de led cube

/*  Data types:
int = integer (whole number)          - 2 bytes (16 bits) - range: -32768			to 32767 (possible values)
unsigned int = integer (whole number) - 2 bytes (16 bits) - range:      0			to 65535 

byte = integer (whole number)         - 1 byte  ( 8 bits) - range:      0			to   255 

float = floating point number         - 4 bytes (32 bits) - range: -3.4028235E+38	to 3.4028235E+38
double = floating point number        - 8 bytes (64 bits) - range: -1.7976931348623157E+308 to 1.7976931348623157E+308

bool = true or false                  - 1 byte  ( 8 bits) - range:      0			to     1
char = character                      - 1 byte  ( 8 bits) - range:      0			to   255 (ASCII table) 'A' = 65, 'B' = 66, 'C' = 67, etc.

String = text                         - n bytes (n bits) Example: String myString = "Hello World!"; // 12 bytes (12*8 = 96 bits)
*/

/* Arrays:

int = data type
 |
 |  myArray = name of the array
 |     |
 |     |   [10] = number of elements in the array
 |     |     |
 v     v     v
int myArray[10]; // Array with 10 elements

Access elements in the array:
Array elements are numbered from 0 to 9. Inexes always start at 0.
int firstElement = myArray[0]; // First element in the array
int secondElement = myArray[1]; // Second element in the array
*/


/* Functions:
 
 void = return type (void means no return value)
   |
   |  myFunction = name of the function
   |     | 
   |     |        () = parameters of the function
   |     |         |
   v     v         v
   void myFunction(); // Function declaration
   
   void myFunction() // Function definition
   {
	   // Function code here
   }
 
   A function must be declared before the first call to the function.
   The function definition can be placed anywhere in the code.
 
 
  int = return type (void means no return value)
   |
   |    add = name of the function
   |     | 
   |     |  (int a, int b) = parameters of the function
   |     |       |
   v     v       v
   int add(int a, int b); // Function declaration
   
   int add(int a, int b) // Function definition
   {
	   return a + b; // "return" means that the function will give the value of a + b back to the place where the function was called
   }
*/



/* if statement
 
 Checks if the condition is true
 If the condition is true, the code inside the if statement will be executed
 If the condition is false, the code inside the else statement will be executed
 
 if (condition)
 {
	 // Code here will be executed if the condition is true
 }
 else
 {
	 // Code here will be executed if the condition is false
 }
 
 bool myBool = true;
 bool myBool2 = false;
 
 // Possible comparison operators:
 // == (equal to)
 // != (not equal to)
 // > (greater than)
 // < (smaller than)
 // >= (greater than or equal to)
 // <= (smaller than or equal to)
 if(myBool == true)
 {
	 // This will be executed
 }
 else
 {
	 // This will not be executed
 }
 
 // Multiple conditions can be defined using different operators:
 // && (and)
 // || (or)
 // ! (not)
 if(myBool == true && myBool2 == false)
 {
	 // This will be executed
 }
 else if(myBool == true && myBool2 == true)
 {
	 // This will not be executed
 }
 else
 {
	 // This will not be executed
 }


 
 */


/* Switch case
 

switch (variable)
{
	case 1:
	case 2:
		// Code here will be executed if variable is 1 or 2
		break;
	case 3:
		// Code here will be executed if variable is 3
		break;
	default:
		// Code here will be executed if variable is not 1, 2 or 3
		break;
}

*/




/* for loop

Creates a counter variable "i" and sets it to 0
Checks if "i" is smaller than 10
If "i" is smaller than 10, the code inside the for loop will be executed
After the code inside the for loop is executed, the counter variable "i" will be incremented by 1
The code inside the for loop will be executed again
This will repeat until "i" is no longer smaller than 10

for (int i = 0; i < 10; i++)
{
	// Code here will be executed 10 times
	// i will be 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
}


*/


void lampeEinAus(int e, int i);
void lampeEin(int e, int i);
void lampeAus(int e, int i);
void lampeReiheEin(int e, int z, int s);
void lampeReiheAus(int e, int z, int s);
void lampeEbeneEin(int e);
void lampeEbeneAus(int e);


// This function is called once at startup of the sketch
void setup()
{
	// Setup all pins as output here
	// Use the pin definitions from the header file
	// Use the pinMode() function
	// Example: pinMode(PIN_NR, OUTPUT);
	
	// See in the file LedCube4_hardware.h which pins are used for the layers and columns
	for (int i = 0; i < LedCube4_hardware::Layer::count; i++)
	{
		pinMode(LedCube4_hardware::Layer::pins[i], OUTPUT);
	}

	for (int i = 0; i < LedCube4_hardware::Column::count; i++)
	{
		pinMode(LedCube4_hardware::Column::pins[i], OUTPUT);
	}
}

// This function is called repeatedly after setup() finishes.
void loop()
{
	// Turn on the first layer
	// Use the digitalWrite() function
	// Example: digitalWrite(PIN_NR, HIGH);
	/*for (int e = 0; e < 4; e++)
	{
		for (int i = 3; i < 16;i+=4)
		{
			lampeEin(e, i);
			lampeEin(e, i-3);
			lampeAus(e, i);
			lampeAus(e, i-3);
		}
		
	} */
	lampeEbeneEin(4);
	delay(1000);
	lampeEbeneEin(3);
	delay(1000);
	lampeEbeneEin(2);
	lampeEbeneAus(4);
	delay(1000);
	lampeEbeneEin(1);
	
	delay(1000);
	lampeEbeneAus(3);
	delay(1000);
	lampeEbeneAus(2);
	delay(1000);
	lampeEbeneAus(1);
}

void lampeEinAus(int e, int i)
{
	delay(100);
	digitalWrite(LedCube4_hardware::Layer::pins[e], HIGH);
	digitalWrite(LedCube4_hardware::Column::pins[i], HIGH);	
	delay(100);
	digitalWrite(LedCube4_hardware::Layer::pins[e], LOW);
	digitalWrite(LedCube4_hardware::Column::pins[i], LOW);
}

void lampeEin(int e, int i)
{
	digitalWrite(LedCube4_hardware::Layer::pins[e], HIGH);
	digitalWrite(LedCube4_hardware::Column::pins[i], HIGH);
}
void lampeAus(int e, int i)
{
	digitalWrite(LedCube4_hardware::Layer::pins[e], LOW);
	digitalWrite(LedCube4_hardware::Column::pins[i], LOW);
}

void lampeReiheEin(int e, int z, int s) //Reihe in einer Ebene 0 1 4
{
	e = e - 1;
	if (e < 0)
	{
		return;
	}
	if (s != 0)
	{		
		for (int i = s-1; i < 16; i += 4) 
		{
			digitalWrite(LedCube4_hardware::Layer::pins[e], HIGH);
			digitalWrite(LedCube4_hardware::Column::pins[i], HIGH);
		}
	}
	
	if (z != 0)
	{		
		for (int i = (z-1)*4; i < z*4; i += 1) 
		{
			digitalWrite(LedCube4_hardware::Layer::pins[e], HIGH);
			digitalWrite(LedCube4_hardware::Column::pins[i], HIGH);
		}
	}
}

void lampeReiheAus(int e, int z, int s) //Reihe in einer Ebene
{
	e=e-1;
	if (e < 0)
	{
		return;
	}
	if (s != 0)
	{		
		for (int i = s-1; i < 16; i += 4) 
		{
			digitalWrite(LedCube4_hardware::Layer::pins[e], LOW);
			digitalWrite(LedCube4_hardware::Column::pins[i], LOW);
		}
	}
	
	if (z != 0)
	{		
		for (int i = (z-1)*4; i < z*4; i += 1) 
		{
			digitalWrite(LedCube4_hardware::Layer::pins[e], LOW);
			digitalWrite(LedCube4_hardware::Column::pins[i],LOW);
		}
	}
}
void lampeEbeneEin(int e)
{
	lampeReiheEin(e, 1, 0);
	lampeReiheEin(e, 2, 0);
	lampeReiheEin(e, 3, 0);
	lampeReiheEin(e, 4, 0);
}
void lampeEbeneAus(int e)
{
	lampeReiheAus(e, 1, 0);
	lampeReiheAus(e, 2, 0);
	lampeReiheAus(e, 3, 0);
	lampeReiheAus(e, 4, 0);
}