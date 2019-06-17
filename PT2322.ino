#include <Wire.h> 
#include <PT2322.h>

PT2322 pt1;
 
void setup(){}

void loop(){
audio();
delay(1000);
}
  
 void audio(){
pt1.setFront_lk_att(0);// att front L
pt1.setFront_rk_att(0);// att front R
pt1.setCenter_att(0);  // att center
pt1.setRear_lk_att(0); // att rear L
pt1.setRear_rk_att(0); // att rear R
pt1.setSub_att(0);     // att sub
// int -7...7 = -14...+14 dB 

pt1.setFunc(0,0,0);// FUNC:  
                   // mute - 0 выкл, 1 вкл 
                   // 3d - 0 вкл, 1 выкл
                   // тембр - 0 вкл, 1 выкл
                   // (int 0,0,0) - по умолчанию
        
pt1.setBass(0);            // BASS    -14...0...14 dB (int -7...0...7)
pt1.setMiddle(0);          // MIDDLE  -14...0...14 dB (int -7...0...7)
pt1.setTreble(0);          // TREBLE  -14...0...14 dB (int -7...0...7)
        
pt1.setVol(65); // 0...79
}
