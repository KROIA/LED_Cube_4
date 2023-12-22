#include "LedCube4_hardware.h"
#include "Timer.h"

bool cubeData1[LedCube4_hardware::Dimensions::x]
			 [LedCube4_hardware::Dimensions::y]
			 [LedCube4_hardware::Dimensions::z];

bool cubeData2[LedCube4_hardware::Dimensions::x]
			 [LedCube4_hardware::Dimensions::y]
			 [LedCube4_hardware::Dimensions::z];

// pointer to the cube data
bool (*cubeDisplayData)[LedCube4_hardware::Dimensions::x]
				   [LedCube4_hardware::Dimensions::y]
				   [LedCube4_hardware::Dimensions::z] = &cubeData1;

bool(*cubeEditingData)[LedCube4_hardware::Dimensions::x]
				   [LedCube4_hardware::Dimensions::y]
				   [LedCube4_hardware::Dimensions::z] = &cubeData2;

Timer updateTimer;
int updateInterval = 1; // ms
int currentLayer = 0;
void updateCube();
void displayCube();
void setPixel(int x, int y, int z, bool value);
void clearPixels();


Timer animationTimer;



void setup()
{
	for (int i = 0; i < LedCube4_hardware::Layer::count; i++)
	{
		pinMode(LedCube4_hardware::Layer::pins[i], OUTPUT);
		digitalWrite(LedCube4_hardware::Layer::pins[i], LOW);
	}
	for (int i = 0; i < LedCube4_hardware::Column::count; i++)
	{
		pinMode(LedCube4_hardware::Column::pins[i], OUTPUT);
		digitalWrite(LedCube4_hardware::Column::pins[i], LOW);
	}
	
	
	for (int x = 0; x < LedCube4_hardware::Dimensions::x; x++)
	{
		for (int y = 0; y < LedCube4_hardware::Dimensions::y; y++)
		{
			for (int z = 0; z < LedCube4_hardware::Dimensions::z; z++)
			{
				cubeData1[x][y][z] = false;
				cubeData2[x][y][z] = false;
			}
		}
	}
}


void loop()
{
	updateCube();
	
	if (animationTimer.start(500))
	{
		static int y = 0;
		static bool countUp = true;
		
		clearPixels();
		setPixel(y, y, y, true);
		
		if(countUp)
		{
			y++;
		}
		else
		{
			y--;
		}
		if(y >= 3 || y <= 0)
		{
			countUp = !countUp;
		}
		displayCube();
	}
}





void switchToNextLayer()
{
	// Schalte aktuellen Layer aus
	digitalWrite(LedCube4_hardware::Layer::pins[currentLayer], LOW);
	
	// Schalte Leds für den nächsten Layer ein
	currentLayer = (currentLayer + 1) % LedCube4_hardware::Dimensions::z;
	for (int x = 0; x < LedCube4_hardware::Dimensions::x; x++)
	{
		for (int y = 0; y < LedCube4_hardware::Dimensions::y; y++)
		{
			int ledIndex = y * LedCube4_hardware::Dimensions::x + x;
			digitalWrite(LedCube4_hardware::Column::pins[ledIndex], (*cubeDisplayData)[x][y][currentLayer]);
		}
	}
	
	// Schalte nächsten Layer ein
	digitalWrite(LedCube4_hardware::Layer::pins[currentLayer], HIGH);
}
void updateCube()
{
	if (updateTimer.start(updateInterval))
	{
		switchToNextLayer();
	}
}
void displayCube()
{
	//Vertausche die Pointer
	bool(*tmp)[LedCube4_hardware::Dimensions::x]
				   [LedCube4_hardware::Dimensions::y]
				   [LedCube4_hardware::Dimensions::z] = cubeDisplayData;
	cubeDisplayData = cubeEditingData;
	cubeEditingData = tmp;
}
void setPixel(int x, int y, int z, bool value)
{
	(*cubeEditingData)[x][y][z] = value;
}
void clearPixels()
{
	for (int x = 0; x < LedCube4_hardware::Dimensions::x; x++)
	{
		for (int y = 0; y < LedCube4_hardware::Dimensions::y; y++)
		{
			for (int z = 0; z < LedCube4_hardware::Dimensions::z; z++)
			{
				(*cubeEditingData)[x][y][z] = false;
			}
		}
	}
}