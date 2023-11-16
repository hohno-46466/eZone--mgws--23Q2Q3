// moka4.ino

// Last update: Sun Feb 19 10:26:51 AST 2023

// pins for the LEDs
int LEDs[3] = {0, 0, 0};
const int LEDpins[3] = {11, 10, 9};

void setup() {
  // initialize serial:
  Serial.begin(57600);
  // make the LEDpins output:
  pinMode(LEDpins[0], OUTPUT);
  pinMode(LEDpins[1], OUTPUT);
  pinMode(LEDpins[2], OUTPUT);
}

void loop() {
  while (Serial.available() > 0) {
    LEDs[0] = Serial.parseInt();
    LEDs[1] = Serial.parseInt();
    LEDs[2] = Serial.parseInt();
    if (Serial.read() == '\n') {
      Serial.print("LED\t");
      Serial.print(millis()); Serial.print("\t");
      // fade the three LEDs and print the three numbers in one string with TABs:
      for (int i = 0; i <= 2; i++) {
        // constrain the values to 0 - 255
        LEDs[i] = constrain(LEDs[i], 0, 255);
        analogWrite(LEDpins[i], 255 - LEDs[i]);
        Serial.print(LEDs[i]); Serial.print("\t");
      }
      Serial.println();
    }
  }
}
