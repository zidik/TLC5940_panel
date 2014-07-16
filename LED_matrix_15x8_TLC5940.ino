#include "TLC5940_panel.h"
#include "Adafruit_GFX.h"
#include <Tlc5940.h>

int8_t width = 15;
int8_t height = 8;
TLC5940_panel panel(width, height);

// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF800
#define GREEN    0x07E0
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0 
#define WHITE    0xFFFF

void setup()
{

	panel.fillScreen(BLUE);
	panel.drawCircle(3, 3, 2, GREEN);
	
}

void loop()
{


	delay(1);
	panel.update_next_col();
}
