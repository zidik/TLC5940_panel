
#include "TLC5940_panel.h"
#include "Tlc5940_custom.h"


TLC5940_panel::TLC5940_panel(uint8_t width, uint8_t height) : Adafruit_GFX(width, height) {
	DDRC = 0xFF; //Port C outputs
}

void TLC5940_panel::update_next_row(){
	curr_row = (curr_row+1) % HEIGHT;
	display_row(curr_row);
}
void TLC5940_panel::drawPixel(int16_t x, int16_t y, uint16_t brightness){
	if (x >= WIDTH) return;
	if (y >= HEIGHT) return;
	Tlc.setActiveBuffer(y);
	Tlc.set(x, brightness);
}

void TLC5940_panel::display_row(uint8_t row){
	//Turn off mosfets
	PORTC = 0xFF;
	//Display the right buffer
	Tlc.setActiveBuffer(row);
	Tlc.update();
	//choose column mosfet
	PORTC = ~(1 << row);
}


