
#include "neo.h"

neo_biped neo;
int degree[20];
int index = 0;
String content = "";
char character;
int eyeLED = 46;


void setup() {
  Serial.begin(115200);
  Serial.println("GPIO test!");
  pinMode(eyeLED, OUTPUT);

  neo.init_neo();
  eye_led();
  neo.initial_position();
  delay(5000);
  neo.say_hi(2, 1000);
  neo.hands_up(1, 3000);
  neo.forward(20, 500);
  neo.turn_right(5, 500);
  neo.turn_left(5, 500);
  neo.move_right(5, 800);
  neo.move_left(5, 800);
  neo.ball_kick_right(1, 1000);
  neo.ball_kick_left(1, 1000);
  neo.max_sit(1, 2000);
  neo.bow(1, 2000);
  neo.right_bow(1, 2000);
  neo.left_bow(1, 2000);
  neo.ape_move(3, 2000);
  neo.clap(3, 2000);
  neo.right_leg_up(3, 2000);
  neo.left_leg_up(3, 2000);
  neo.hip_pose(1, 2000);
  neo.right_leg_balance(1, 3000);
  neo.left_leg_balance(1, 3000);
  neo.flying_action(3, 2000);
  neo.hand_sit_zigzak(3, 2000);
  neo.side_shake(3, 1200);
  neo.hip_shake(3, 1200);
  neo.bend_up(1, 2000);
  neo.push_up(3, 3000);

}



void loop() {

}

void eye_led() {
  digitalWrite(eyeLED, HIGH);
}

void blink_eye() {
  digitalWrite(eyeLED, LOW);
  delay(250);
  digitalWrite(eyeLED, HIGH);
  delay(5000);
}

void serialEvent() {
  //Sample serial input: "90,150,150,30,90,90,90,30,30,150,90,90,30,30,30,150,150,150,90,90,"
  String degree;
  degree = Serial.readString();
  //Serial.println(degree);
  executeAngle(degree);
}

void executeAngle(String degree) {
  int angle_array[20], r = 0, t = 0;
  //Serial.println(degree);
  for (int i = 0; i < degree.length(); i++)
  {
    if (degree.charAt(i) == ',')
    {
      angle_array[t] = degree.substring(r, i).toInt();
      r = (i + 1);
      t++;
    }
  }
  for (int i = 0; i < 20; i++) {
    Serial.print(angle_array[i]);
    Serial.print("|");
  }
  Serial.println("");
  neo.move_servo(2000, angle_array);
}
