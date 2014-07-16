
#include "TLC5940_panel.h"
#include <Tlc5940.h>


TLC5940_panel::TLC5940_panel(uint8_t width, uint8_t height) : Adafruit_GFX(width, height) {
	int buffsize = 2 * 15 * 8;
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
	matrixbuff[x + y * WIDTH] = color;
}

void TLC5940_panel::display_col(uint8_t col){
	Tlc.clear();
	Tlc.update();
	PORTC = (1 << col);
	for (uint8_t row = 0; row < HEIGHT; row++){
		Tlc.set(row, matrixbuff[row * WIDTH + col]);
	}
	Tlc.update();
}


