
#include "TLC5940_panel.h"
#include "Tlc5940_custom.h"


TLC5940_panel::TLC5940_panel(uint8_t width, uint8_t height) : Adafruit_GFX(width, height) {
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
	Tlc.setActiveBuffer(x);
	Tlc.set(y, color);
}

void TLC5940_panel::display_col(uint8_t col){
	//Turn off all LED's
	//Display "empty buffer"
	Tlc.setActiveBuffer(15); // "special buffer"
	Tlc.update();
	//choose column mosfet
	PORTC = (1 << col);
	//Display the right buffer
	Tlc.setActiveBuffer(col);
	Tlc.update();
}


