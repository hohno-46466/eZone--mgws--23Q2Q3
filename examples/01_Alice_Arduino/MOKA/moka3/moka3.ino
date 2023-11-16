// moka3.ino

// Last update: Tue Feb 21 02:54:19 AST 2023

long dummyNum = 100;
const int SWpins[3] = {A3, A4, A5};
const int POTpins[3] = {A0, A1, A2};

void setup() {
  Serial.begin(57600);
  pinMode(SWpins[0], INPUT_PULLUP);
  pinMode(SWpins[1], INPUT_PULLUP);
  pinMode(SWpins[2], INPUT_PULLUP);
  randomSeed(micros());
}

void loop() {
  Serial.print("Hello, World! This is moka3"); Serial.print("\t");
  Serial.print(millis()); Serial.print("\t");

  Serial.print(digitalRead(SWpins[0])); Serial.print("\t");
  Serial.print(analogRead(POTpins[0])); Serial.print("\t");
  Serial.print(dummyNum); Serial.print("\t"); dummyNum += random(-50,50);

  Serial.print(digitalRead(SWpins[1])); Serial.print("\t");
  Serial.print(analogRead(POTpins[1])); Serial.print("\t");
  Serial.print(dummyNum); Serial.print("\t"); dummyNum += random(-50,50);

  Serial.print(digitalRead(SWpins[2])); Serial.print("\t");
  Serial.print(analogRead(POTpins[2])); Serial.print("\t");
  Serial.print(dummyNum); Serial.println();   dummyNum += random(-50,50);
  delay(200);
}
