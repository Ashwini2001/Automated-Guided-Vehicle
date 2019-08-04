#include <SoftwareSerial.h>

#define LM1 8 // left motor M1a
#define LM2 9 // left motor M2a
#define RM1 10 // right motor M2a
#define RM2 11 // right motor M2b

SoftwareSerial mySerial(3, 4); // RX, TX

int sensor = 2;

int left_intr = 0;
int distance;
int angle_left;
//unsigned long start_time = 0;
//unsigned long end_time = 0;

/*Hardware details*/
float radius_of_wheel = 5.6;  //Measure the radius of your wheel and enter it here in cm


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(sensor, INPUT_PULLUP);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);


//  Serial.println("SoftwareSerial  Started!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(2), Left_ISR, CHANGE); //Left_ISR is called when left wheel sensor is triggered

}

void loop() {
  // run over and over
  char response;

  while (mySerial.available()) {
    response = mySerial.read();
    Serial.println(response);


    if (response == 'A')
    {

      Forword();
    }
    else if (response == 'B')
    {
;
      Backword();
    }
    else  if (response == 'C')
    {

      Left();
    }
    else if (response == 'D')
    {

      Right();
    }
    else if (response == 'E')
    {
 
      Stop();
    }

    else if (response == 'F')
    {

      First_Job();
      Stop();

    }
    else if (response == 'G')
    {
      First_Job();
      Stop();
    }
    else if (response == 'H')
    {
      First_Job();
      Stop();
    }
    else if (response == 'I')
    {
      Second_Job();
      Stop();
    }
    else if (response == 'J')
    {
      Second_Job();
      Stop();
    }
    else if (response == 'K')
    {
      Second_Job();
      Stop();
    }
    else if (response == 'L')
    {
      New2();
      Stop();
    }
    else if (response == 'M')
    {
      New2();
      Stop();
    }
    else if (response == 'N')
    {
      New2();
      Stop();
    }
  }
  distance = (2 * 3.141 * radius_of_wheel) * (left_intr / 50);
  angle_left = (left_intr % 360) * (90 / 100) ;
}

void Forword()
{
  analogWrite(LM1, 255);
  analogWrite(RM1, 255);
  analogWrite(LM2, 0);
  analogWrite(RM2, 0);
}

void Backword()
{
  analogWrite(LM1, 0);
  analogWrite(RM1, 0);
  analogWrite(LM2, 255);
  analogWrite(RM2, 255);
}

void Left()
{
  analogWrite(LM1, 255);
  analogWrite(RM2, 255);
  analogWrite(RM1, 0);
  analogWrite(LM2, 0);
}

void Right()
{
  analogWrite(LM1, 0);
  analogWrite(RM2, 0);
  analogWrite(RM1, 255);
  analogWrite(LM2, 255);
}

void Stop()
{
  analogWrite(LM1, 0);
  analogWrite(RM2, 0);
  analogWrite(RM1, 0);
  analogWrite(LM2, 0);
}

void First_Job()
{
  left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Right();
      }
           
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }


	left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }

        
      left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }

      Stop();
      delay(6000);



       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }


       left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      delay(6000);
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      delay(6000);

      left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      delay(6000);

      left_intr=0;
    while (left_intr >= 0 && left_intr <= 10) {
        Forword();
      }

      left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
      
}

void Second_Job()
{
  left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Right();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }

	left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
      left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      delay(6000);
      
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 7) {
        Left();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }

left_intr=0;
    while (left_intr >= 0 && left_intr <= 7) {
        Left();
      }
      
      Stop();
      delay(6000);
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      
}

void New2()
{
  left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Right();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }

 left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
      left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      delay(6000);
      

       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      delay(6000);
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
       left_intr=0;
    while (left_intr >= 0 && left_intr <= 30) {
        Forword();
      }
      Stop();
      delay(6000);

      left_intr=0;
    while (left_intr >= 0 && left_intr <= 35 ) {
        Forword();
      }


      left_intr=0;
    while (left_intr >= 0 && left_intr <= 15) {
        Left();
      }
      
}

void Left_ISR()
{
  left_intr++;
  Serial.print(left_intr);
  mySerial.println(left_intr);
  delay(50);
}
