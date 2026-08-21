// =======================
// LED Functions
// =======================

// เปิด LED ซ้าย
void leftLEDOn(int d) {
  digitalWrite(L_LED, HIGH);
  delay(d);
}

// ปิด LED ซ้าย
void leftLEDOff(int d) {
  digitalWrite(L_LED, LOW);
  delay(d);
}

// เปิด LED ขวา
void rightLEDOn(int d) {
  digitalWrite(R_LED, HIGH);
  delay(d);
}

// ปิด LED ขวา
void rightLEDOff(int d) {
  digitalWrite(R_LED, LOW);
  delay(d);
}

// เปิด LED ทั้งสองข้าง
void bothLEDOn(int d) {
  digitalWrite(L_LED, HIGH);
  digitalWrite(R_LED, HIGH);
  delay(d);
}

// ปิด LED ทั้งสองข้าง
void bothLEDOff(int d) {
  digitalWrite(L_LED, LOW);
  digitalWrite(R_LED, LOW);
  delay(d);
}

// กระพริบ LED ซ้าย
void blinkLeftLED(int d) {
  digitalWrite(L_LED, HIGH);
  delay(d);
  digitalWrite(L_LED, LOW);
  delay(d);
}

// กระพริบ LED ขวา
void blinkRightLED(int d) {
  digitalWrite(R_LED, HIGH);
  delay(d);
  digitalWrite(R_LED, LOW);
  delay(d);
}

// กระพริบ LED ทั้งสองข้าง
void blinkBothLED(int d) {
  digitalWrite(L_LED, HIGH);
  digitalWrite(R_LED, HIGH);
  delay(d);

  digitalWrite(L_LED, LOW);
  digitalWrite(R_LED, LOW);
  delay(d);
}