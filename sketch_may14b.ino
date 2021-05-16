#define REC 5 // pin 2 is used for recording

#define PLAY_E 6 // pin 3 is used for playback-edge trigger

#define playtime 15000 // playback time 5 seconds

#define recordtime 15000 // recording time 5 seconds 

int potpin = 12;    // select the input pin for the potentiometer
int ledpin = 13;   // select the pin for the LED green
int ledpin2 =10;   // select the pin for the LED red
int val = 0;       // value to store the data  from the sensor

char intp;     // enter char alphabet 

void setup() {
  pinMode(REC,OUTPUT);// set the REC pin as output
  pinMode(ledpin, OUTPUT);  // initialize digital pin ledpin as an output.
  pinMode(ledpin2, OUTPUT); // initialize digital pin ledpin2 as an output.
  pinMode(PLAY_E,OUTPUT);// set the PLAY_e pin as output
 
 Serial.begin(9600);// set up Serial monitor  

}

void loop() {
  Serial.println("enter r to record sound and enter p to play sound");
  if(!Serial) {
    intp = (char)Serial.read();
    
    if(intp =='r'){
      digitalWrite(REC, HIGH);   // record sound
      Serial.println("recording begain");
      
      delay(recordtime);
      digitalWrite(REC, LOW);
      Serial.println("recording stop");
    }
    else if(intp =='p'){
      val=analogRead(potpin); // store new data from senor 
      
      digitalWrite(PLAY_E, HIGH); // play sound
      delay(100);
      digitalWrite(PLAY_E, LOW);  
      Serial.println("Playbing begain"); 
      digitalWrite(ledpin, HIGH); // green led blink
      digitalWrite(ledpin, HIGH);   
      delay(val);                       
      digitalWrite(ledpin, LOW);  
      delay(playtime);
      Serial.println("playbing stop"); 
      digitalWrite(ledpin2,HIGH);  // red led show stop
      delay(100);
      digitalWrite(ledpin2,LOW);
      }else
      {
      break;
      }
                                         
   }
 delay(500);

}
