//
// our1stSketch.ino
//

void setup() {
  Serial.begin(57600);
}

void loop() {
  Serial.print("Hello, World! I'm GBKA.\t");
  Serial.println(millis());
  delay(1000);
}
