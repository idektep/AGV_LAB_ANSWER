void forward(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255

  digitalWrite(MR_IN1, HIGH);  //backright motor
  digitalWrite(MR_IN2, LOW);   //backright motor
  digitalWrite(MR_IN3, HIGH);  //frontright motor
  digitalWrite(MR_IN4, LOW);   //frontright motor
  digitalWrite(ML_IN1, HIGH);  //frontleft motor
  digitalWrite(ML_IN2, LOW);   //frontleft motor
  digitalWrite(ML_IN3, HIGH);  //backleft motor
  digitalWrite(ML_IN4, LOW);   //backleft motor
  delay(d);
}

void backward(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
  delay(d);
}

void slide_left(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, HIGH);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, HIGH);
  digitalWrite(ML_IN4, LOW);
  delay(d);
}

void slide_right(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, HIGH);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, HIGH);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
  delay(d);
}

void slide_left_front(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, HIGH);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, HIGH);
  digitalWrite(ML_IN4, LOW);
  delay(d);
}

void slide_right_front(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, HIGH);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, HIGH);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, LOW);
  delay(d);
}

void slide_left_back(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, LOW);
  delay(d);
}

void slide_right_back(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
  delay(d);
}

void turn_left(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, HIGH);
  digitalWrite(MR_IN2, LOW);
  digitalWrite(MR_IN3, HIGH);
  digitalWrite(MR_IN4, LOW);
  digitalWrite(ML_IN1, LOW);
  digitalWrite(ML_IN2, HIGH);
  digitalWrite(ML_IN3, LOW);
  digitalWrite(ML_IN4, HIGH);
  delay(d);
}

void turn_right(int d) {
  analogWrite(BR_ENA, 200); //Pin speed //backright motor Adjust range value 120-255
  analogWrite(FR_ENB, 200); //Pin speed //frontright motor Adjust range value 120-255
  analogWrite(BL_ENB, 200); //Pin speed //backleft motor Adjust range value 120-255
  analogWrite(FL_ENA, 200); //Pin speed //frontleft motor Adjust range value 120-255
  
  digitalWrite(MR_IN1, LOW);
  digitalWrite(MR_IN2, HIGH);
  digitalWrite(MR_IN3, LOW);
  digitalWrite(MR_IN4, HIGH);
  digitalWrite(ML_IN1, HIGH);
  digitalWrite(ML_IN2, LOW);
  digitalWrite(ML_IN3, HIGH);
  digitalWrite(ML_IN4, LOW);
  delay(d);
}

void stop(int d) {
  digitalWrite(MR_IN1, LOW);  //backright motor
  digitalWrite(MR_IN2, LOW);  //backright motor
  digitalWrite(MR_IN3, LOW);  //frontright motor
  digitalWrite(MR_IN4, LOW);  //frontright motor
  digitalWrite(ML_IN1, LOW);  //frontleft motor
  digitalWrite(ML_IN2, LOW);  //frontleft motor
  digitalWrite(ML_IN3, LOW);  //backleft motor
  digitalWrite(ML_IN4, LOW);  //backleft motor
  delay(d);
}
