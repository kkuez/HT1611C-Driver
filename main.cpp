#include <Arduino.h>

const int halfClockTime = 1;
const int dataPin = 6;
const int clockPin = 7;


bool bitArray[4] = {false, false, false, false};
int ticker = 0;
bool active = true;
char *lastMessage = " ";

void writeStringToLCD(char *number);
void pause();
void getByteForChar(char inputChar, bool *incomingByte);
void writeCharToLCD(char incomingChar);
void keepDisplayAlive();


void setup() {
  //bytes to write are store in here
  pinMode(5, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(5, HIGH);
//10 digits
char stringToWrite[10] = "- P22"
writeStringToLCD(stringToWrite)

    
    //writeStringToLCD("0-42FP111");

digitalWrite(5, LOW);
delay(200);
  ticker += 200;
  keepDisplayAlive();
}

void keepDisplayAlive(){
if(ticker % 4000 > 3700){
  Serial.println(lastMessage);
  writeStringToLCD(lastMessage);
  }
  if(ticker > 60000){
   ticker = 0;
 }
}

void pause(){
  digitalWrite(clockPin, HIGH);
  delay(halfClockTime);
  delay(halfClockTime);
}

void writeStringToLCD(char *incoming){
  for(int i =0;i<10;i++){
    if(incoming[i] != NULL){
      writeCharToLCD(incoming[i]);
    }else{
      writeCharToLCD(' ');
    }
    if(i != 9){
      pause();
    }
  }

}

void writeCharToLCD(char incomingChar){
getByteForChar(incomingChar, &bitArray[0]);
for(int j = 0; j<4;j++){
    digitalWrite(clockPin, HIGH);
    //Serial.println(byteForChar[j]);
    digitalWrite(dataPin, bitArray[j] ? HIGH : LOW);
    delay(halfClockTime);
    digitalWrite(clockPin, LOW);
    delay(halfClockTime);
}
}


void getByteForChar(char inputChar, bool *incomingByte){
//Dec ascii http://www.asciitable.com/
  int charValue = inputChar;
  Serial.println(charValue);
  if(charValue == 49){
        incomingByte[0] = false;
       incomingByte[1] = false;
       incomingByte[2] = false;
       incomingByte[3] = true;
  }else{
    if(charValue == 50){
      incomingByte[0] = false;
       incomingByte[1] = false;
       incomingByte[2] = true;
       incomingByte[3] = false;
    }else{
    if(charValue == 51){
      incomingByte[0] = false;
       incomingByte[1] = false;
       incomingByte[2] = true;
       incomingByte[3] = true;
    }else{
    if(charValue == 52){
      incomingByte[0] = false;
       incomingByte[1] = true;
       incomingByte[2] = false;
       incomingByte[3] = false;
    }else{
    if(charValue == 53){
      incomingByte[0] = false;
       incomingByte[1] = true;
       incomingByte[2] = false;
       incomingByte[3] = true;
    }else{
    if(charValue == 54){
       incomingByte[0] = false;
       incomingByte[1] = true;
       incomingByte[2] = true;
       incomingByte[3] = false;
    }else{
    if(charValue == 55){
      incomingByte[0] = false;
       incomingByte[1] = true;
       incomingByte[2] = true;
       incomingByte[3] = true;
    }else{
    if(charValue == 56){
      incomingByte[0] = true;
       incomingByte[1] = false;
       incomingByte[2] = false;
       incomingByte[3] = false;
    }else{
    if(charValue == 57){
      incomingByte[0] = true;
       incomingByte[1] = false;
       incomingByte[2] = false;
       incomingByte[3] = true;
    }else{
    if(charValue == 48){
      incomingByte[0] = true;
       incomingByte[1] = false;
       incomingByte[2] = true;
       incomingByte[3] = false;
    }else{
    if(charValue == 42){
      // *
      incomingByte[0] = true;
       incomingByte[1] = true;
       incomingByte[2] = false;
       incomingByte[3] = true;
    }else{
    if(charValue == 35){
      // #
      incomingByte[0] = true;
       incomingByte[1] = true;
       incomingByte[2] = false;
       incomingByte[3] = false;
    }else{
    if(charValue == 80){
      // P
      incomingByte[0] = true;
       incomingByte[1] = true;
       incomingByte[2] = true;
       incomingByte[3] = false;
    }else{
    if(charValue == 70){
      // F
      incomingByte[0] = true;
       incomingByte[1] = false;
       incomingByte[2] = true;
       incomingByte[3] = true;
    }else{
    if(charValue == 45){
      // -
      incomingByte[0] = true;
       incomingByte[1] = true;
       incomingByte[2] = true;
       incomingByte[3] = true;
    }else{
    if(charValue == 32){
      // " "
      incomingByte[0] = false;
       incomingByte[1] = false;
       incomingByte[2] = false;
       incomingByte[3] = false;
    }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
}
