#pragma once
#include <Arduino.h>

namespace LedCube4_hardware
{
	namespace Layer
	{
		// Define on which pins the layer transistors are connected
		constexpr const byte pins[] = { A0, A1, A2, A3 };
		
		// The same pins are also in the register PORTF for faster access
		volatile uint8_t &port = PORTF;
		
		// Register to set the pinMode for the layer pins
		volatile uint8_t &portDirRegister = DDRF;
		
		// PinMode for the layer pins (0 = input, 1 = output)
		constexpr byte portDirMask = 0b00001111;
		
		// Define the mask for the layer pins. Bits 0-3 are used for the layer pins
		const byte portMask = 0b00001111;
		
		// Define the number of layers
		constexpr byte count = sizeof(pins) / sizeof(pins[0]);
	}
	
	namespace Column
	{
		// Define on which pins the column transistors are connected
		constexpr byte pins[] = 
		{ 
				22, 23, 24, 25, 
			    26, 27, 28, 29,
				37, 36, 35, 34,
				33, 32, 31, 30
		};
		
		// The same pins are also in the register PORTA and PORTC for faster access
		volatile uint8_t &port1 = PORTA;
		volatile uint8_t &port2 = PORTC;
		
		// Register to set the pinMode for the column pins
		volatile uint8_t &portDirRegister1 = DDRA;
		volatile uint8_t &portDirRegister2 = DDRC;
		
		// PinMode for the layer pins (0 = input, 1 = output)
		constexpr byte portDirMask = 0b11111111;
		
		// Define the number of columns
		constexpr byte count = sizeof(pins) / sizeof(pins[0]);
	}
	
	namespace Dimensions
	{
		constexpr byte x = 4;
		constexpr byte y = 4;
		constexpr byte z = 4;
	}
};