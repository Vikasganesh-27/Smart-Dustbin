#define trigPin 4
#define echoPin 5

const int ledRed = 9;
const int ledGreen = 8;
const int buzzer = A0;

void setup() 
{
 Serial.begin(9600); //start serial monitor and setting baud rate to 9600
 pinMode(trigPin, OUTPUT); //setting trigger pin to output
 pinMode(echoPin, INPUT); //setting echo pin to input
 pinMode(ledRed, OUTPUT); //setting led red to output
 pinMode(ledGreen, OUTPUT); //setting led green to output
 pinMode(buzzer, OUTPUT); //setting buzzer to output
}

void loop()
{
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  
  digitalWrite(trigPin, HIGH);

  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); //measuring the duration of the pulse received by echoPin
  distance = (duration*0.034)/2; //calculated the distance in cm with speed of sound 
  Serial.print("Distance is: ");
  Serial.println(distance);

  //check if distance is less than 70cm
  if(distance < 70)
  {
    
    digitalWrite(ledGreen, HIGH); //Green LED is turned ON
    digitalWrite(ledRed, LOW); //Red LED is turned OFF
    int buzzVal = 180;
    tone(buzzer, buzzVal, 50); //buzzer is turned ON
    Serial.println("DUSTBIN IS OPEN"); //DustBin is open
  }

  else
  {
    digitalWrite(ledGreen, LOW); //Green LED is turned OFF
    digitalWrite(ledRed, HIGH); //Red LED is turned ON
    analogWrite(buzzer, 0); //Buzzer is turned OFF
    Serial.println("DUSTBIN IS CLOSED"); //DustBin is closed
  }
  delay(200);
}
