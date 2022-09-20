#include <Adafruit_BMP085.h>

// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here

Adafruit_BMP085 bmp;
float temp,refa,refb;   //referencia alta y baja

void setup() {
  Serial.begin(9600);
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
  pinMode(D0,OUTPUT);
  digitalWrite(D0,HIGH);
  refa=32;
  refb=27;
}
  
void loop() {
  temp=bmp.readTemperature();
  //Serial.println(bmp.readTemperature());
  if(temp>refa){
    digitalWrite(D0,LOW);
  }

  if(temp<refb){
    digitalWrite(D0,HIGH);
  }
    
  delay(500);
}
