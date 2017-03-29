

//latest modified code

// motor controls
int motorRight1=10;
int motorRight2=12;
int motorLeft1=8;
int motorLeft2=9;

//IR  sense pins
int leftSensePin=4;
int rightSensePin=0;
int middleSensePin1=3;
int middleSensePin2=2;
int middleSensePin3=1;


//leds
int led=13;

// sensed values
int middleValue1;
int middleValue2;
int middleValue3;
int rightValue;
int leftValue;

// Functions
void moveLeft();
void moveRight();
void moveForward();
void moveBack();
void Stop();

int counter=12;
unsigned long long int timer = 0;
unsigned long long int threshold = 20000;

/*
void extremeRight()
{
  delay(500);
 digitalWrite(motorRight1,LOW);
  digitalWrite(motorRight2,HIGH);
  digitalWrite(motorLeft1,HIGH);
  digitalWrite(motorLeft2,LOW); 
  }
*/

void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);
    pinMode(motorLeft1,OUTPUT);
    pinMode(motorLeft2,OUTPUT);
    pinMode(motorRight1,OUTPUT);
    pinMode(motorRight2,OUTPUT);

    pinMode(leftSensePin,INPUT);
    pinMode(rightSensePin,INPUT);
    pinMode(middleSensePin1,INPUT);
    pinMode(middleSensePin2,INPUT);
    pinMode(middleSensePin3,INPUT);

    pinMode(led,OUTPUT);
   // pinMode(GreenLed,OUTPUT);

   delay(5000);

digitalWrite(led,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  //  middleValue = (analogRead(MiddleSensePin1)+analogRead(MiddleSensePin2)+analogRead(MiddleSensePin3))/2;

  middleValue1 = (analogRead(middleSensePin1));
  middleValue2 = (analogRead(middleSensePin2));
  middleValue3 = (analogRead(middleSensePin3));

    leftValue = analogRead(leftSensePin);
    rightValue = analogRead(rightSensePin);



/* // Check for all sesor values 
  Serial.print(leftValue); Serial.print("   ");
  Serial.print(middleValue1); Serial.print("   ");
  Serial.print(middleValue2); Serial.print("   ");
  Serial.print(middleValue3); Serial.print("   ");
  Serial.print(rightValue); Serial.println("   ");

*/





if (leftValue>200 && rightValue>200  )// extremes are white
  {
    digitalWrite(led,LOW);
        if(((middleValue2<200)&& (middleValue1>200 && middleValue3>200))|| (middleValue1<200) && (middleValue2<200) && (middleValue3<200))  // partial left
        {
            moveForward();
        }
    
        else if((middleValue2<200)&& (middleValue1<200))  //partial right
        {
            moveLeft();
        }
   
       else if((middleValue2<200)&&(middleValue3<200))   //  middle sensor is black
        {
            moveRight();
        }
      
    
       

    }
   
      else  if(rightValue<200)                                      // when a junction is reached
       {  if((counter==3) || (counter==4) ||( counter==9))
           {
              Stop();
              digitalWrite(led,HIGH);
              delay(1000);
              digitalWrite(led,LOW);
              moveForward();
            
        
            }
       

      //  leftValue = (leftValue>200?1:0);    // converting to 0 or 1 format for readLeftSensor function
      //  rightValue = (rightValue>200?1:0);   // converting to 0 or 1 format for readRightSensor function
       
         if(rightValue<200 && leftValue<200 && middleValue1<200 && middleValue2<200 && middleValue3<200 && ((counter==1) || (counter==5)|| (counter==7)|| (counter==10)||(counter==12)))
         z
          
          if(counter==12)
          {
          
          Stop();
          delay(1000);
          moveRight();
          delay(800);
 
          }
          else if(counter == 14)
          {
            moveForward();
            delay(2000);
            while(1)
            Stop(); 
             
          }
         
     
         
         else
         {
          
        Stop();
          digitalWrite(led,HIGH);
          delay(1000);
          digitalWrite(led,LOW);
          moveRight();
          delay(800);  
         }
         }
           while(rightValue <200)
           {
         rightValue = analogRead(rightSensePin);
           }
           counter++;
          
        }
        else if(leftValue<200 && rightValue >200)
        moveLeft();
   

  
      
Serial.println(counter);
   

}





void moveRight()
{
  digitalWrite(motorRight1,LOW);
  digitalWrite(motorRight2,LOW);
  digitalWrite(motorLeft1,HIGH);
  digitalWrite(motorLeft2,LOW);

}

void moveLeft()
{
  digitalWrite(motorRight1,HIGH);
  digitalWrite(motorRight2,LOW);
  digitalWrite(motorLeft1,LOW);
  digitalWrite(motorLeft2,LOW);

}


void moveForward()
{
  digitalWrite(motorRight1,HIGH);
  digitalWrite(motorRight2,LOW);
  digitalWrite(motorLeft1,HIGH);
  digitalWrite(motorLeft2,LOW);

}

void moveBack()
{
  digitalWrite(motorRight1,LOW);
  digitalWrite(motorRight2,HIGH);
  digitalWrite(motorLeft1,LOW);
  digitalWrite(motorLeft2,HIGH);

}

void Stop()
{
  digitalWrite(motorRight1,LOW);
  digitalWrite(motorRight2,LOW);
  digitalWrite(motorLeft1,LOW);
  digitalWrite(motorLeft2,LOW);
}



// foolproof sensing of left sensor

int  readLeftSensor(int previousState)
{
  int newState = digitalRead(leftSensePin);
  
  if(newState !=previousState)  // state changed
  {
    delay(50);
    newState = digitalRead(leftSensePin);
     if(newState !=previousState) 
     {
      return newState;
     }
     else
     {
      return previousState;
      }
    
    }

}



// foolproof sensing of right sensor


int  readRightSensor(int previousState)
{
  int newState = digitalRead(rightSensePin);
  
  if(newState !=previousState)  // state changed
  {
    delay(50);
    newState = digitalRead(rightSensePin);
     if(newState !=previousState) 
     {
      return newState;
     }
     else
     {
      return previousState;
      }
    
    }

}




