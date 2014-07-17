#include "TLC5940_panel.h"
#include "Adafruit_GFX.h"
#include <Tlc5940.h>

int8_t width = 15;
int8_t height = 8;
TLC5940_panel panel(width, height);

void setup()
{
	panel.fillTriangle(10, 0, 14, 4, 8, 7, 1000);
	panel.drawCircle(3, 3, 2, 4095); //4095 is maximum value
}

void loop()
{


	delay(1);
	panel.update_next_col();
}
