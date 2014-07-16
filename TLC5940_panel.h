
#ifndef _TLC5940_PANEL_H_
#define _TLC5940_PANEL_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Adafruit_GFX.h>

class TLC5940_panel : public Adafruit_GFX{
public:
	TLC5940_panel(uint8_t width, uint8_t height);

	void update_next_col();
	void drawPixel(int16_t x, int16_t y, uint16_t color);

private:
	uint8_t curr_col;
	void display_col(uint8_t col);
	uint16_t *matrixbuff;

};
#endif
