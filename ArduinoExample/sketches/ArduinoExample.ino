#include "LedCube4_hardware.h" // Include header file with pin definitions for de led cube

/*  Data types:
int = integer (whole number)          - 2 bytes (16 bits) - range: -32768			to 32767 (possible values)
unsigned int = integer (whole number) - 2 bytes (16 bits) - range:      0			to 65535 

byte = integer (whole number)         - 1 byte  ( 8 bits) - range:      0			to   255 
unsigned byte = integer (whole number)- 1 byte  ( 8 bits) - range:      0			to   255 

float = floating point number         - 4 bytes (32 bits) - range: -3.4028235E+38	to 3.4028235E+38
double = floating point number        - 8 bytes (64 bits) - range: -1.7976931348623157E+308 to 1.7976931348623157E+308

boolean = true or false               - 1 byte  ( 8 bits) - range:      0			to     1
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
 if(myBool == true && myBool2 == false)
 {
	 // This will be executed
 }
 else
 {
	 // This will not be executed
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





// This function is called once at startup of the sketch
void setup()
{
	// Setup all pins as output here
	// Use the pin definitions from the header file
	// Use the pinMode() function
	// Example: pinMode(PIN_NR, OUTPUT);
	
	// See in the file LedCube4_hardware.h which pins are used for the layers and columns
	pinMode(LedCube4_hardware::Layer::pins[0], OUTPUT); // Sets the pin mode of the first layer to output
	
	pinMode(LedCube4_hardware::Column::pins[0], OUTPUT); // Sets the pin mode of the first column to output
}

// This function is called repeatedly after setup() finishes.
void loop()
{
	// Turn on the first layer
	// Use the digitalWrite() function
	// Example: digitalWrite(PIN_NR, HIGH);
	
	// See in the file LedCube4_hardware.h which pins are used for the layers and columns
	digitalWrite(LedCube4_hardware::Layer::pins[0], HIGH); // Turns on the first layer
	
	// Turn on the first column
	// See in the file LedCube4_hardware.h which pins are used for the layers and columns
	digitalWrite(LedCube4_hardware::Column::pins[0], HIGH); // Turns on the first column
}
