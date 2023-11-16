// moka5.ino

// Last update: Tue Feb 21 02:48:48 AST 2023

// pins for the LEDs
const int LEDpins[3] = {11, 10, 9};
int LEDs[3] = {0, 0, 0};

// pins for the Buttons
const int SWpins[3] = {A3, A4, A5};

// pins for the Potentiometers
const int POTpins[3] = {A0, A1, A2};

void setup() {
  // initialize serial:
  Serial.begin(57600);
  // make the LEDLEDpins outputs:
  for (int i = 0; i <= 2; i++) {
    pinMode(LEDpins[i], OUTPUT);
    pinMode(SWpins[i], INPUT_PULLUP);
  }
}

void loop() {
  // print keyword and millis
  Serial.print("Sw/Pot\t");
  Serial.print(millis()); Serial.print("\t");

  // print six numbers (three sets of Buttons and Pots) in one string with TABs:
  for (int i = 0; i <= 2; i++) {
    Serial.print(digitalRead(SWpins[i])); Serial.print("\t");
    Serial.print(analogRead(POTpins[i])); Serial.print("\t");
  }
  Serial.println();

  if (Serial.available() > 0) {
    uint32_t d = millis();
    while (Serial.available() > 0) {
      for (int i = 0; i <= 2; i++) {
        LEDs[i] = Serial.parseInt();
      }
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
  } else {
    delay(200);
  }
}
