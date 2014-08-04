#include <TLC5940_panel.h>
#include <Tlc5940_custom.h>
#include <Adafruit_GFX.h>

int8_t width = 15;
int8_t height = 8; //When changing this, also change "#define DATABUFFERS" in tlc_config
TLC5940_panel panel(width, height);

void setup()
{
  Tlc.init();
  
  panel.fillTriangle(10, 0, 14, 4, 8, 7, 4095);//4095 is maximum value
  panel.drawCircle(3, 3, 2, 4095);
}

void loop()
{
  //
  //Add your code here
  //
  panel.update_next_row();	
  delay(5);
}
