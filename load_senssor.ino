#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
HX711 scale;
long a;

void setup() {
  Serial.begin(57600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  if (scale.is_ready()) {
//    long reading = scale.read();
    a = 0.0049 * (scale.read());
//    Serial.print("HX711 reading: ");
//    Serial.println(reading);
Serial.print("Weight : ");
Serial.print(a-21 );
Serial.println("gms");
} else {
    Serial.println("HX711 not found.");
  }
 // return (a-21);

  delay(1000);
 //a = calculate_weight();
  if (a < 1000)
  Serial.println("Signal 0 ");
  else
  Serial.println("Signal 1 ");
}

long calculate_weight(){
 
}
