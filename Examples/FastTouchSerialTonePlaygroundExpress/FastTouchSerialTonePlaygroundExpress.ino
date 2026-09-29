#include <FastTouch.h>

// monotone touch sequencer
// Adrian Freed 2018

void setup()
{
  Serial.begin(9600);
}


 void loop()
 {
    int r;
    const int tonepin=A0;
    const int notelength=140, notetonote=190;
    Serial.print(r = fastTouchRead(A2)); Serial.print(" ");
    if(r>1)
     { tone(tonepin, 587/2, notelength/(r-1)); delay(notetonote); }
     Serial.print(r = fastTouchRead(A3)); Serial.print(" ");
    if(r>1)
      { tone(tonepin, 440, notelength/(r-1)); delay(notetonote); }
     Serial.print(r = fastTouchRead(A4)); Serial.print(" ");
    if(r>1)
      { tone(tonepin, 220, notelength/(r-1)); delay(notetonote);}
     Serial.print(r = fastTouchRead(A5)); Serial.print(" ");
     if(r>1)
      { tone(tonepin, 153, notelength/(r-1)); delay(notetonote); }
    Serial.print(r = fastTouchRead(A1)); Serial.print(" ");
     if(r>1)
      { tone(tonepin, 185, notelength/(r-1)); delay(notetonote);}
    Serial.print(r = fastTouchRead(A6)); Serial.print(" ");
    if(r>1)
      { tone(tonepin, 196, notelength/(r-1)); delay(notetonote);}
    Serial.print(r = fastTouchRead(A7)); Serial.print(" ");
     if(r>1)
      { tone(tonepin, 349, notelength/(r-1)); delay(notetonote);}
  
   Serial.println();
}

