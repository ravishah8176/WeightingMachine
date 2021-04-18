#include "HX711.h"
#define DOUT  2
#define CLK  3
HX711 scale;
int a =10;
float weight;
float calibration_factor = -386720.00;
void setup() {
  Serial.begin(9600);
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor);
  scale.tare(); //Reset the scale to 0
  long zero_factor = scale.read_average(); //Get a baseline reading
}
void loop() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  Serial.println( scale.get_units(),2);    
}
