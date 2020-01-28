# define rightpin1 10  //right is 左輪
# define rightpin2 11
# define leftpin1 13   //left is 右輪
# define leftpin2 12
# define enA 14
# define enB 15
const int front_Trig_Pins = 6;//trig 腳位
const int front_Echo_Pins = 7;// echo 腳位
const int right_Trig_Pins = 2;//trig 腳位
const int right_Echo_Pins = 3;// echo 腳位
const int left_Trig_Pins = 4;//trig 腳位
const int left_Echo_Pins = 5;// echo 腳位
int c1=0;
int c2=0;
int c3=0;
int c5=0;

float get_distance(int trig, int echo){//計算距離
    float duration;
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);//給予trig 10us TTL pulse,讓模組發射聲波
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH, 5000000);//紀錄echo電位從high到low的時間，就是超音波來回的時間，若5秒內沒收到超音波則回傳0
    return duration / 29 / 2;// 聲速340m/s ，換算後約每29微秒走一公分，超音波來回所以再除2
}

void setup() {
   Serial.begin(9600);
   pinMode(rightpin1,OUTPUT);
   pinMode(rightpin2,OUTPUT);
   pinMode(leftpin1,OUTPUT);
   pinMode(leftpin2,OUTPUT);
   pinMode(enA,OUTPUT);
   pinMode(enB,OUTPUT);
   analogWrite(enA,235);  
   analogWrite(enB,235);  
   go(70); 
}

void loop() {
   float front_result= get_distance( front_Trig_Pins, front_Echo_Pins);
   float right_result= get_distance( right_Trig_Pins, right_Echo_Pins);
   float left_result= get_distance( left_Trig_Pins, left_Echo_Pins);
   
   if(c2>3){
       backward(400); 
       go_right(56); 
       c2=0;
       go(1000); 
       Serial.println("sol_not_move");
   }
   if(c3>10){
       backward(400); 
       go_right(56); 
       c3=0;
       go(1000); 
       Serial.println("sol_not_move_2");
   }
   if(c5>10){
       backward(200);
       go_right(400); 
       c5=0;
       go(600); 
       Serial.println("sol_not_move_3");
   }
   
   ////adjust
   if(right_result<4.2){  
       go_left(16); 
       Serial.println("left_big_adjust");
   }
   else if(left_result<4){  
       go_right(16); 
       Serial.println("right_big_adjust");
   }
   else if(right_result<7){ 
       go_left(12); 
       Serial.println("left_little_adjust");
   }
   else if(left_result<6){  
       go_right(12);  
       Serial.println("right_little_adjust");
   }
   ////

   //左前右
   if(left_result>29 && left_result<300){ 
       go(184);  
       stop_go(500); 
       go_left(396); 
       stop_go(500); 
       go(400); 
       c2++; 
       Serial.println("turn_left");
       c3=0;
   }
   else if(front_result>15 && front_result<300){
       go(150); 
       Serial.println("go_forward");
       c2=0;
       c3++;
   }
   else if(right_result>30 && right_result<300){ 
       go(184); 
       stop_go(500);  
       go_right(396); 
       stop_go(500);  
       go(400); 
       Serial.println("turn_right");
       c2=0; 
       c3=0; 
   }
   else if(front_result<15 && right_result<20 && left_result<20){  
       go_right(464); 
       stop_go(500); 
       backward(200); 
       stop_go(500);  
       go_right(456); 
       go(100);    
       Serial.println("U_turn");
       c2=0;  
       c3=0; 
   }
   else if(front_result<4){  
       stop_go(500);  
       backward(50); 
       Serial.println("front_result<5");
   }
   else if(front_result>3000){  
       stop_go(500); 
       backward(50); 
       Serial.println("front_result>3000");
       c5++;
   }
   else if(right_result>2000){
       go_left(16); 
       Serial.println("right_result>2000");
   }
   else if(left_result>2000){
       go_right(16); 
       Serial.println("left_result>2000");
   }
   else{
       go(200);  
       Serial.println("else_go");
       c5++;
   }
}

void stop_go(int t){
      digitalWrite(rightpin1,LOW);
      digitalWrite(rightpin2,LOW);
      digitalWrite(leftpin1,LOW);
      digitalWrite(leftpin2,LOW);
      delay(t);
}

void go(int t){
      digitalWrite(rightpin1,HIGH);
      digitalWrite(rightpin2,LOW);
      digitalWrite(leftpin1,HIGH);
      digitalWrite(leftpin2,LOW);
      delay(t);
}

void backward(int t){
      digitalWrite(rightpin1,LOW);
      digitalWrite(rightpin2,HIGH);
      digitalWrite(leftpin1,LOW);
      digitalWrite(leftpin2,HIGH);
      delay(t);
}

void go_right(int t){
      digitalWrite(rightpin1,HIGH);
      digitalWrite(rightpin2,LOW);
      digitalWrite(leftpin1,LOW);
      digitalWrite(leftpin2,HIGH);
      delay(t);
}

void go_left(int t){
      digitalWrite(rightpin1,LOW);
      digitalWrite(rightpin2,HIGH);
      digitalWrite(leftpin1,HIGH);
      digitalWrite(leftpin2,LOW);
      delay(t);
}
