// moka1.ino

// Last update: Sun Feb 19 05:59:00 AST 2023

void setup() {
  Serial.begin(57600);
}

void loop() {
  Serial.print("Hello, World! This is moka1.\t");
  Serial.println(millis());
  delay(1000);
}
