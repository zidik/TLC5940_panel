
#include "TLC5940_panel.h"
#include <Tlc5940.h>


TLC5940_panel::TLC5940_panel(uint8_t width, uint8_t height) : Adafruit_GFX(width, height) {
	int buffsize = 2 * width * height; // 2 bytes per pixel
	if (NULL == (matrixbuff = (uint16_t *)malloc(buffsize))) return;
	memset(matrixbuff, 0, buffsize);

	Tlc.init();
	DDRC = 0xFF; //Port C outputs
}

void TLC5940_panel::update_next_col(){
	curr_col = curr_col++ % WIDTH;
	display_col(curr_col);
}
void TLC5940_panel::drawPixel(int16_t x, int16_t y, uint16_t color){
	if (x >= WIDTH) return;
	if (y >= HEIGHT) return;
	matrixbuff[y * WIDTH + x] = color;
}

void TLC5940_panel::display_col(uint8_t col){
	//Turn off all LED's
	Tlc.clear();
	Tlc.update();
	//choose column mosfet
	PORTC = (1 << col);
	//Set up new data
	//This could be optimised - 
	// Tlc5940 library could be modified so there would be array of tlc_GSData buffers
	// then drawpixel would use Tlc.set and here we only would select right buffer to display.
	for (uint8_t row = 0; row < HEIGHT; row++){
		Tlc.set(row, matrixbuff[row * WIDTH + col]);
	}
	//Push data out
	Tlc.update();
}


