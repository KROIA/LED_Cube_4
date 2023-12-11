#include "LedCube4_hardware.h"
#include "Timer.h"

using namespace LedCube4_hardware;

// Timer stuff
Timer layerSwitchTimer;
unsigned int layerSwitchTime = 1; // ms


// Led Cube stuff
byte currentLayer = 0;

// 3D cube image data
constexpr size_t cubeBufferSize = Column::count / 8 * Layer::count;	
byte *cubeBuffer = new byte[cubeBufferSize];


// 3D cube animation data
Timer animationTimer;
int animationStep = 0;
constexpr byte animationFrameCount = 8;
byte animationData[animationFrameCount][cubeBufferSize]
{
	{
		0b10011111, 0b11111001,
		0b00001001, 0b10010000,
		0b00001001, 0b10010000,
		0b10011111, 0b11111001
	},
	{
		0b00000000, 0b00000000,
		0b10011111, 0b11111001,
		0b00001001, 0b10010000,
		0b00001001, 0b10010000
	},
	{
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b10011111, 0b11111001,
		0b00001001, 0b10010000
	},
	{
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b10011111, 0b11111001
	},
	{
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000
	},
	{
		0b10011111, 0b11111001,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
	},
	{
		0b00001001, 0b10010000,
		0b10011111, 0b11111001,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000
	},
	{
		0b00001001, 0b10010000,
		0b00001001, 0b10010000,
		0b10011111, 0b11111001,
		0b00000000, 0b00000000
	}
};



void updateCube();
void setPixel(byte x, byte y, byte z, bool state);
bool getPixel(byte x, byte y, byte z);

void setPixels(const byte *data);

void setup()
{
	
	
	// Set Layer pins as output
	Layer::portDirRegister = Layer::portDirRegister | Layer::portDirMask;
	
	// Set Column pins as output
	Column::portDirRegister1 = Column::portDirRegister1 | Column::portDirMask;
	Column::portDirRegister2 = Column::portDirRegister2 | Column::portDirMask;
	
	// Set all pins to low
	Layer::port = Layer::port & ~Layer::portDirMask;
	Column::port1 = 0;
	Column::port2 = 0;
	
	// Set all pixels to off
	memset(cubeBuffer, 0, cubeBufferSize);
}

void loop()
{
	updateCube();
	
	if (animationTimer.start(500))
	{
		animationStep = (animationStep + 1) % animationFrameCount;

		setPixels(animationData[animationStep]);
	}
}


void updateCube()
{
	unsigned int time = millis();
	if (layerSwitchTimer.start(layerSwitchTime))
	{
		// Counts up to until it reaches 4 and then resets to 0
		currentLayer = (currentLayer + 1) % Layer::count;
		byte newLayerData = (Layer::port & ~Layer::portDirMask) | (1 << currentLayer);
		
		// disabble all columns
		Column::port1 = 0;
		Column::port2 = 0;
		Layer::port = newLayerData;
	}
	
	// Set column data
	Column::port1 = cubeBuffer[currentLayer*2];
	Column::port2 = cubeBuffer[currentLayer*2 + 1];
}
void setPixel(byte x, byte y, byte z, bool state)
{
	if (x >= Dimensions::x || y >= Dimensions::y || z >= Dimensions::z)
	{
		return;
	}
	
	/*byte *data = &cubeBuffer[z*2];
	if (y <= 1)
		data++;
	
	byte mask = 1 << (x + );
	
	byte column = x;
	byte layer = z;
	byte bit = y;
	
	byte mask = 1 << bit;
	
	if (state)
	{
		cubeBuffer[layer][column] = cubeBuffer[layer][column] | mask;
	}
	else
	{
		cubeBuffer[layer][column] = cubeBuffer[layer][column] & ~mask;
	}*/
}
bool getPixel(byte x, byte y, byte z)
{
	if (x >= Dimensions::x || y >= Dimensions::y || z >= Dimensions::z)
	{
		return false;
	}
	return false;
	/*byte column = x;
	byte layer = z;
	byte bit = y;
	
	byte mask = 1 << bit;
	
	return (cubeBuffer[layer][column] & mask) != 0;*/
}

void setPixels(const byte *data)
{
	memcpy(cubeBuffer, data, cubeBufferSize);
}