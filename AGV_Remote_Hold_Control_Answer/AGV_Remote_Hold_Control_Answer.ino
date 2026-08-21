//-------------------------------------------------Declare variable-------------------------------------------------------//
#define MR_IN1 12 //backright motor
#define MR_IN2 13 //backright motor
#define MR_IN3 32 //frontright motor
#define MR_IN4 33 //frontright motor

#define ML_IN1 27 //frontleft motor
#define ML_IN2 14 //frontleft motor
#define ML_IN3 25 //backleft motor
#define ML_IN4 26 //backleft motor

#define BR_ENA 15  //Pin speed backright motor
#define FR_ENB 2   //Pin speed frontright motor
#define BL_ENB 4   //Pin speed backleft motor
#define FL_ENA 19  //Pin speed frontleft motor

#define L_LED 16  // Left LED
#define R_LED 17  // Right LED

#define TRIG 5   // Trig pin pin5
#define ECHO 35  // Echo pin pin35

long microsecondsToCentimeters(long microseconds)  // function การแปลงหน่วยให้เป็น เซนติเมตร
{
  return microseconds / 29 / 2;  // การแปลงหน่วยที่อ่านได้ ให้เป็นเซนติเมตร
}

void setup() {

  Serial.begin(112500);
  initWebServer();
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(MR_IN1, OUTPUT);
  pinMode(MR_IN2, OUTPUT);
  pinMode(MR_IN3, OUTPUT);
  pinMode(MR_IN4, OUTPUT);
  pinMode(ML_IN1, OUTPUT);
  pinMode(ML_IN2, OUTPUT);
  pinMode(ML_IN3, OUTPUT);
  pinMode(ML_IN4, OUTPUT);
  
  pinMode(FL_ENA, OUTPUT);
  pinMode(BL_ENB, OUTPUT);
  pinMode(BR_ENA, OUTPUT);
  pinMode(FR_ENB, OUTPUT);

  pinMode(L_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);
  delay(1000);
}

void loop() {

  updateWebServer();
}

void checkDistance(int collision_distance) {
  while (1) {
    long duration, distance;
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(5);
    digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO, HIGH);
    distance = microsecondsToCentimeters(duration);

    Serial.print("distance =  ");  // กำหนดชื่อ
    Serial.println(distance);      // ให้แสดงค่าที่ อ่านได้
    delay(10);
    forward(100);
    
    if (distance <= collision_distance && distance != 0) {
      stop(500);
      break;
    }
  }
}

