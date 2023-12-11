#include "LedCube4_hardware.h"


void setLayer(byte layerIndex, bool state);
void setLed(byte ledIndex, bool state);

void individualLayerTest();


void setup()
{
	// Set the layerpins to output
	for (byte i = 0; i < LedCube4_hardware::Layer::count; i++)
	{
		pinMode(LedCube4_hardware::Layer::pins[i], OUTPUT);
	}
	
	// Set the columnpins to output
	for (byte i = 0; i < LedCube4_hardware::Column::count; i++)
	{
		pinMode(LedCube4_hardware::Column::pins[i], OUTPUT);
	}
}

void loop()
{
	individualLayerTest();
}


void setLayer(byte layerIndex, bool state)
{
	for (byte i = 0; i < LedCube4_hardware::Layer::count; i++)
	{
		digitalWrite(LedCube4_hardware::Layer::pins[i], 0);	
	}
	digitalWrite(LedCube4_hardware::Layer::pins[layerIndex], state);	
}
void setLed(byte ledIndex, bool state)
{
	digitalWrite(LedCube4_hardware::Column::pins[ledIndex], state);
}

void individualLayerTest()
{
	for (byte i = 0; i < LedCube4_hardware::Layer::count; ++i)
	{
		for (byte j = 0; j < LedCube4_hardware::Column::count; ++j)
		{
			setLed(j, false);
		}
		setLayer(i, HIGH);
		delay(100);
		for (byte j = 0; j < LedCube4_hardware::Column::count; ++j)
		{
			setLed(j, true);
			delay(100);
		}
	}
}




