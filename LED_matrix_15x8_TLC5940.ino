#include "TLC5940_panel.h"
#include "Adafruit_GFX.h"
#include "Tlc5940_custom.h"

int8_t width = 15;
int8_t height = 8;
TLC5940_panel panel(width, height);

uint8_t counter = 0;
void setup()
{
	panel.fillTriangle(10, 0, 14, 4, 8, 7, 4095);
	panel.drawCircle(3, 3, 2, 4095); //4095 is maximum value
	Tlc.init();
}

void loop()
{
	delay(5);
	panel.update_next_row();
}
