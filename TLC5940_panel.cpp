
#include "TLC5940_panel.h"
#include "Tlc5940_custom.h"


TLC5940_panel::TLC5940_panel(uint8_t width, uint8_t height) : Adafruit_GFX(width, height) {
	DDRC |= B00111111;   // Port C (Analog 0 - Analog 5)
	DDRD |= (1 << PD7);  // Digital 7
	DDRB |= (1 << PB0);  // Digital 8
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
	//Turn off mosfets by setting all outputs high
	PORTC |= B00111111;   // Port C (Analog 0 - Analog 5)
	PORTD |= (1 << PD7);  // Digital 7
	PORTB |= (1 << PB0);  // Digital 8
	//Display the right buffer
	Tlc.setActiveBuffer(row);
	Tlc.update();
	//choose column mosfet - set it low
	if (row >= 0 && row < 6)
		PORTC &= ~(1 << row);
	else if (row == 6)
		PORTD &= ~(1 << PD7);
	else if (row == 7)
		PORTB &= ~(1 << PB0);
	else{}
}


