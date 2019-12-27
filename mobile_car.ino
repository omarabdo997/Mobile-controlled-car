

//int input_signal_n=0;
#include "NewPing.h"
int motor_r_enable =5;
int motor_r_f=2;
int motor_r_b=4;
int motor_l_enable =6;
int motor_l_f=7;
int motor_l_b=8;
int line_sensor_r=9;
int line_sensor_m=10;
int line_sensor_l=11;
//int line_sensor_l=3;
char input_signal ;
const int trigPin=12;
const int echoPin=13;
int line_time=20000;
float duration;
int lastrot=2;
int lastrot1=2;
int lastrot2=2;
int left_chance , right_chance;
int left,right,middle;
float distance;
int time_now;
int last;
int indicator =0;
#define MAX_DISTANCE 400
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

int move_forward()

  {
    analogWrite(motor_r_enable, 120);
    digitalWrite(motor_r_f, HIGH);
    digitalWrite(motor_r_b, LOW);
    analogWrite(motor_l_enable, 120);
    digitalWrite(motor_l_f, HIGH);
    digitalWrite(motor_l_b, LOW);
  }
int move_backward()
  {
    analogWrite(motor_r_enable, 120);
    digitalWrite(motor_r_f, LOW);
    digitalWrite(motor_r_b, HIGH);
    analogWrite(motor_l_enable, 120);
    digitalWrite(motor_l_f, LOW);
    digitalWrite(motor_l_b, HIGH);
  }  
int move_right()
  {
    analogWrite(motor_r_enable, 120);
    digitalWrite(motor_r_f, LOW);
    digitalWrite(motor_r_b, HIGH);
    analogWrite(motor_l_enable, 120);
    digitalWrite(motor_l_f, HIGH);
    digitalWrite(motor_l_b, LOW);
    delay(340);
    stop_m();
  }    
int move_right_wall()
  {
    analogWrite(motor_r_enable, 117);
    digitalWrite(motor_r_f, LOW);
    digitalWrite(motor_r_b, HIGH);
    analogWrite(motor_l_enable, 117);
    digitalWrite(motor_l_f, HIGH);
    digitalWrite(motor_l_b, LOW);
    delay(350);
    move_forward_s();
    delay(200);
  }      
int move_left()
  {
    analogWrite(motor_r_enable, 120);
    digitalWrite(motor_r_f, HIGH);
    digitalWrite(motor_r_b, LOW);
    analogWrite(motor_l_enable, 120);
    digitalWrite(motor_l_f, LOW);
    digitalWrite(motor_l_b, HIGH);
    delay(340);
    stop_m();
  }
int move_left_wall()
  {
    analogWrite(motor_r_enable, 117);
    digitalWrite(motor_r_f, HIGH);
    digitalWrite(motor_r_b, LOW);
    analogWrite(motor_l_enable, 117);
    digitalWrite(motor_l_f, LOW);
    digitalWrite(motor_l_b, HIGH);
    delay(330);
    move_forward_s();
    delay(200);
  }          
int stop_m()
  {
   
    analogWrite(motor_r_enable, 120);
    digitalWrite(motor_r_f, LOW);
    digitalWrite(motor_r_b, LOW);
    analogWrite(motor_l_enable, 120);
    digitalWrite(motor_l_f, LOW);
    digitalWrite(motor_l_b, LOW);
    
  }
int move_forward_s()

  {
  
    analogWrite(motor_r_enable,75);
    digitalWrite(motor_r_f, HIGH);
    digitalWrite(motor_r_b, LOW);
    analogWrite(motor_l_enable, 75);
    digitalWrite(motor_l_f, HIGH);
    digitalWrite(motor_l_b, LOW);
  }
int move_right_s()
  {
    analogWrite(motor_r_enable, 75);
    digitalWrite(motor_r_f, LOW);
    digitalWrite(motor_r_b, HIGH);
    analogWrite(motor_l_enable, 75);
    digitalWrite(motor_l_f, HIGH);
    digitalWrite(motor_l_b, LOW);

  }
int move_right_f()
  {
    analogWrite(motor_r_enable, 75);
    digitalWrite(motor_r_f, LOW);
    digitalWrite(motor_r_b, HIGH);
    analogWrite(motor_l_enable, 75);
    digitalWrite(motor_l_f, HIGH);
    digitalWrite(motor_l_b, LOW);
    

  }  
int move_left_s()
  {
    analogWrite(motor_r_enable, 75);
    digitalWrite(motor_r_f, HIGH);
    digitalWrite(motor_r_b, LOW);
    analogWrite(motor_l_enable, 75);
    digitalWrite(motor_l_f, LOW);
    digitalWrite(motor_l_b, HIGH);

  }
int move_left_f()
  {
    analogWrite(motor_r_enable, 70);
    digitalWrite(motor_r_f, HIGH);
    digitalWrite(motor_r_b, LOW);
    analogWrite(motor_l_enable, 70);
    digitalWrite(motor_l_f, LOW);
    digitalWrite(motor_l_b, HIGH);

  }                                              
    
  
void setup() 
{
  // put your setup code here, to run once:
  pinMode(motor_r_enable, OUTPUT);
  pinMode(motor_r_f, OUTPUT);
  pinMode(motor_r_b, OUTPUT);
  pinMode(motor_l_enable, OUTPUT);
  pinMode(motor_l_f, OUTPUT);
  pinMode(motor_l_b, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  distance = sonar.ping_cm();
  Serial.println(distance);
  if (distance<30  & distance!=0)
    {
      stop_m();  
      delay(200);
      move_backward();
      delay(200);
      stop_m();
      move_right();
      move_forward();        
    }
  if (Serial.available())
  {
    
    input_signal = Serial.read();
    
    if (input_signal == 'f')
    {
    move_forward();

    }
    else if (input_signal=='b')
    {
    move_backward();

    }
    else if (input_signal=='r')
    {
     move_right();

    }
    else if (input_signal=='l')
    {
      move_left();

    }
    else if (input_signal=='g')
    { 
      while(1)
      {
        if(analogRead(A0)>analogRead(A1)& analogRead(A0)>analogRead(A2))
        {
          move_right_s();
        }
        if(analogRead(A1)>analogRead(A0)& analogRead(A1)>analogRead(A2))
        {
          move_forward_s();
        }
        if(analogRead(A2)>analogRead(A1)& analogRead(A2)>analogRead(A0))
        {
          move_left_s();
        }
        }
 
    }
    else if (input_signal=='i')
    {
     

      time_now=millis();
      while(1)
      {
        left_chance=0;
        right_chance=0;
        distance = sonar.ping_cm();
       // Serial.println(distance);
        if (distance<15 & distance!=0)
      {
        if(lastrot == 1)
        {
          left_chance=left_chance+1;
        }
        if(lastrot == 0)
        {
          right_chance=right_chance+1; 
        }
        if(lastrot1 == 1)
        {
          left_chance=left_chance+1;
        }
        if(lastrot1 == 0)
        {
          right_chance=right_chance+1; 
        }
        if(lastrot2 == 1)
        {
          left_chance=left_chance+1;
        }
        if(lastrot2 == 0)
        {
          right_chance=right_chance+1; 
        }
        if (left_chance > right_chance)
        {
          move_left_wall();
          indicator=1;
        }
        else if (right_chance > left_chance)
        {
          move_right_wall();
          indicator=2;
        }
            
            
      }

        left=digitalRead(line_sensor_l);
        middle=digitalRead(line_sensor_m);
//        middleL=digitalRead(line_sensor_ml);
        right=digitalRead(line_sensor_r);
        
        if(indicator ==1 & !left)
        {
          move_left_s();
          indicator=0;
        }
        else if(indicator ==2 &!right)
        {
          move_right_s();
          indicator=0;
        }
        else if(left & !middle & right)
        {
          
          move_forward_s();
          last=1;
        }
        else if (!left & middle & right)
        {
          move_left_s();
          last=2;
          lastrot2=lastrot1;
          lastrot1=lastrot;
          lastrot=1;
        }
        
        else if (left & middle & !right)
        {
          move_right_s();
          lastrot2=lastrot1;
          lastrot1=lastrot;
          lastrot=0;
          last=3;
          
        }
        else if(!left & !middle & right)
        {
          move_forward_s();

        }
        else if (left & !middle & !right)
        {
          move_forward_s();

          last=3;
          
        }
        else if(!left & !middle & !right)
        {
          move_forward_s();
        }
        

        
      }
      stop_m();

    }
  
  

    else 
    {
      stop_m();
    
    }  
    
  }


  
  

}
