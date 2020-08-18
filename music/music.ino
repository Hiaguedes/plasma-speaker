#include <SoftwareSerial.h>

#include <SD.h>                      // need to include the SD library

//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>
#define button 3
SoftwareSerial BTserial(2, 3);

TMRpcm tmrpcm;   // create an object for use in this sketch
  int estado=0;
  int estado_old;
 int id=0;
 int id_old;
 char q;
 
boolean debounce1=true;
boolean debounce2=true;
void setup(){

  tmrpcm.speakerPin = 10; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  tmrpcm.setVolume(3); 
  Serial.begin(9600);
  BTserial.begin(9600);
  tmrpcm.quality(1);
  //tmrpcm.play("ff.wav"); //the sound file "music" will play each time the arduino powers up, or is reset
 tmrpcm.play("thunder.wav");

}


void loop(){  
/*Serial.println(debounce1);
Serial.print(id);
estado=digitalRead(button);

if(digitalRead(button)==HIGH && debounce1==true){ 
id++; 
if(id>1) id=0;
debounce1=false;
if (digitalRead(button)==LOW) debounce1=true; //Avoid debounce
if(id==0){tmrpcm.play("ff.wav");}
if(id==1){tmrpcm.play("ff9ed.wav");}*/


  /*  switch(id){

case 0: tmrpcm.play("ff.wav");
        break;

case 1: tmrpcm.play("ff9ed.wav");
        break;

default: tmrpcm.disable();
}*/

if(BTserial.available()){
  //     
  BTserial.println("Funcionou...");
   q=BTserial.read();

if(q == 'q'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("ff1.wav");
}
if(q == 'w'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("ff9ed.wav");
}

if(q == 'e'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("Paranoid.wav");
}
if(q == 'r'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("danga2.wav");
}
if(q == 't'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("Funebre.wav");
}
if(q == 'y'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("thunder.wav");
}
if(q == 'j'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("jojo.wav");
}
if(q == 'd'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("danga1.wav");
}

if(q == 'n'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("Stand.wav");
}


    }


    if(Serial.available()){
  //     
  BTserial.println("Funcionou...");
   q=Serial.read();

if(q == 'q'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("ff1.wav");
}
if(q == 'w'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("ff9ed.wav");
}

if(q == 'e'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("Paranoid.wav");
}
if(q == 'r'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("danga2.wav");
}
if(q == 't'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("Funebre.wav");
}
if(q == 'y'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("thunder.wav");
}
if(q == 'j'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("jojo.wav");
}
if(q == 'd'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("danga1.wav");
}

if(q == 'n'){ //File will play only after pressing “q” key in “Serial Monitor”
tmrpcm.play("Stand.wav");
}


    }
 
    
    }
