#include <ESP32Servo.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu(Wire);

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  Serial.begin(115200);
  Wire.begin();  
  mpu.begin();
  mpu.calcGyroOffsets(true);

  servo1.attach(13);   
  servo2.attach(12); 
  servo3.attach(14);   
  servo4.attach(27);   
  servo5.attach(26);  

  servo1.write(90);
  servo2.write(90);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);

  delay(1000);
}

void loop() {
  mpu.update();

  float roll = mpu.getAngleX();   
  float pitch = mpu.getAngleY();  
  float yaw = mpu.getAngleZ();    

  if(roll > 3) {
    servo1.write(0);
    servo2.write(0);
  }else if(roll < 3){
    servo1.write(180);
    servo2.write(180);
  } else {
    servo1.write(90);
    servo2.write(90);
  }

  if(pitch > 0) {
    servo3.write(180);
    servo4.write(180);
  }else if(pitch < 0){
    servo3.write(0);
    servo4.write(0);
  }else {
    servo3.write(90);
    servo4.write(90);
  }

  if(yaw > 0) {
    servo5.write(180);
    delay(1000);
    servo5.write(90);
  } else if(yaw < 0){
    servo5.write(0);
    delay(1000);
    servo5.write(90);
  }else{
    servo5.write(90);
  }

  delay(300);
}
