const byte POTENZIOMETRO = A0;
const byte LED_GIALLO = 3;
const byte LED_BIANCO = 4;
const byte LED_ROSSO = 5;
const byte LED_VERDE = 8;
const byte LED_BLU = 9;
const int CheckLedDelay = 5;
void setup()
{
 //potenziometro
 pinMode(POTENZIOMETRO, INPUT);
 //led Rosso
 pinMode(LED_ROSSO, OUTPUT);
 //led verde
 pinMode(LED_VERDE, OUTPUT);
 //led blu
 pinMode(LED_BLU, OUTPUT);
 //led Bianco caldo
 pinMode(LED_GIALLO, OUTPUT);
 //led Bianco
 pinMode(LED_BIANCO, OUTPUT);
 //init seriale
 Serial.begin(9600);
 //controllo se tutti i led funzionano
 CheckLed();
}
int lastVal = 0;
void loop()
{
  int val = getPotenza();
  if(lastVal == 0 || val != lastVal){
      writeColor(0,0,0,0,0);
      lastVal = val;
  }
  if(val >= 0 && val < 140)
  {
    Gioco_1();
      writeColor(0,0,0,0,0);
  }
  else if(val >= 140 && val < 280)
  {
   CheckLed();
     writeColor(0,0,0,0,0);
  }
  else if(val >= 280 && val < 420)
  {
   writeColor(255,0,0,0,0);
  }
  else if(val >= 420 && val < 560)
  {
   writeColor(0,255,0,0,0);
  }
  else if(val >= 560 && val < 700)
  {
   writeColor(0,0,255,0,0);
  }
  else if(val >= 700 && val < 820)
  {
   writeColor(0,0,0,255,0);
  }
  else if(val >= 820)
  {
  writeColor(0,0,0,0,255);
  }
}
void Gioco_2()
{
   
}
void Gioco_1()
{
  Light(LED_ROSSO, true, 10);
  delay(1000);
  Light(LED_ROSSO, false, 10);
  
  Light(LED_BLU, true, 10);
  delay(1000);
  Light(LED_BLU, false, 10);
  
  Light(LED_VERDE, true, 10);
  delay(1000);
  Light(LED_VERDE, false, 10);
  
  Light(LED_ROSSO, true, 10);
  Light(LED_BLU, true, 10);
  delay(1000);
  Light(LED_ROSSO, false, 10);
  Light(LED_BLU, false, 10);

  
  Light(LED_ROSSO, true, 10);
  Light(LED_VERDE, true, 10);
  delay(1000);
  Light(LED_ROSSO, false, 10);
  Light(LED_VERDE, false, 10);
  
  Light(LED_BLU, true, 10);
  Light(LED_VERDE, true, 10);
  delay(1000);
  Light(LED_BLU, false, 10);
  Light(LED_VERDE, false, 10);

  
  Light(LED_ROSSO, true, 10);
  Light(LED_BLU, true, 10);
  Light(LED_VERDE, true, 10);
  delay(1000);
  Light(LED_BLU, false, 10);
  Light(LED_VERDE, false, 10);
  Light(LED_ROSSO, true, 10);
}

void CheckLed()
{
  
 Light(LED_GIALLO, true, CheckLedDelay);

 Light(LED_GIALLO, false, CheckLedDelay);
 
 Light(LED_BIANCO, true, CheckLedDelay);

 Light(LED_BIANCO, false, CheckLedDelay);
 
 Light(LED_ROSSO, true, CheckLedDelay);

 Light(LED_ROSSO, false, CheckLedDelay);

 
 Light(LED_BLU, true, CheckLedDelay);

 Light(LED_BLU, false, CheckLedDelay);
 
 Light(LED_VERDE, true, CheckLedDelay);

 Light(LED_VERDE, false, CheckLedDelay);
}
void writeColor(int red, int green, int blue, int w, int ww)
{
  
      analogWrite(LED_ROSSO, red);

   
      analogWrite(LED_BLU, blue);

      analogWrite(LED_VERDE, green);
      
      analogWrite(LED_BIANCO, w);
      
      analogWrite(LED_GIALLO, ww);

    
}
void Light(byte LED, bool lightUp, int delaySet)
{
 
  if(lightUp)
  {
    for(int val = 0; val <= 255; val++)
    {
      analogWrite(LED, val);
      delay(delaySet);
    }
  }
  else
  {
       for(int val = 255; val >= 0; val--)
       {
          analogWrite(LED, val);
          delay(delaySet);
       }
  }
}
/*
 * maxValue = 1023
 * minValue = 0
*/
int getPotenza()
{
  int value = analogRead(POTENZIOMETRO);
  Serial.println(value);
  return value;
}
