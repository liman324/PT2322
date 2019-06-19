#include <Arduino.h>
#include <Wire.h>
#include "PT2322.h"

PT2322::PT2322(){
	Wire.begin();
}

void PT2322::setFront_lk_att(int f_lk_att){
             writeWire(f_lk_att + 0b00010000);
}

void PT2322::setFront_rk_att(int f_rk_att){
             writeWire(f_rk_att + 0b00100000);
}

void PT2322::setCenter_att(int c_att){
             writeWire(c_att + 0b00110000);
}

void PT2322::setRear_lk_att(int r_lk_att){
             writeWire(r_lk_att + 0b01000000);
}

void PT2322::setRear_rk_att(int r_rk_att){
             writeWire(r_rk_att + 0b01010000);
}

void PT2322::setSub_att(int sub_att){
             writeWire(sub_att + 0b01100000);
}

void PT2322::setFunc(int mute, int ddd, int tembr){
                   switch(mute){
                      case 0: mute = 0b00000000; break;
                      case 1: mute = 0b00001000; break;
                      }
                   switch(ddd){
                      case 0: ddd = 0b00000000; break;
                      case 1: ddd = 0b00000100; break;
                      }
                   switch(tembr){
                      case 0: tembr = 0b00000000; break;
                      case 1: tembr = 0b00000010; break;
                      }
             writeWire(0b01110000 + mute + ddd + tembr);
}

void PT2322::setBass(int bass){
                   switch(bass){
                      case -7: bass = 0b00000000; break;
                      case -6: bass = 0b00000001; break;
                      case -5: bass = 0b00000010; break;
                      case -4: bass = 0b00000011; break;
                      case -3: bass = 0b00000100; break;
                      case -2: bass = 0b00000101; break;
                      case -1: bass = 0b00000110; break;
                      case  0: bass = 0b00000111; break;
                      
                      case  7: bass = 0b00001000; break;
                      case  6: bass = 0b00001001; break;
                      case  5: bass = 0b00001010; break;
                      case  4: bass = 0b00001011; break;
                      case  3: bass = 0b00001100; break;
                      case  2: bass = 0b00001101; break;
                      case  1: bass = 0b00001110; break;
                      }
               writeWire(0b10010000 + bass);
}

void PT2322::setMiddle(int mid){
                   switch(mid){
                      case -7: mid = 0b00000000; break;
                      case -6: mid = 0b00000001; break;
                      case -5: mid = 0b00000010; break;
                      case -4: mid = 0b00000011; break;
                      case -3: mid = 0b00000100; break;
                      case -2: mid = 0b00000101; break;
                      case -1: mid = 0b00000110; break;
                      case  0: mid = 0b00000111; break;
                      
                      case  7: mid = 0b00001000; break;
                      case  6: mid = 0b00001001; break;
                      case  5: mid = 0b00001010; break;
                      case  4: mid = 0b00001011; break;
                      case  3: mid = 0b00001100; break;
                      case  2: mid = 0b00001101; break;
                      case  1: mid = 0b00001110; break;
                      }
               writeWire(0b10100000 + mid);
}

void PT2322::setTreble(int treb){
                   switch(treb){
                      case -7: treb = 0b00000000; break;
                      case -6: treb = 0b00000001; break;
                      case -5: treb = 0b00000010; break;
                      case -4: treb = 0b00000011; break;
                      case -3: treb = 0b00000100; break;
                      case -2: treb = 0b00000101; break;
                      case -1: treb = 0b00000110; break;
                      case  0: treb = 0b00000111; break;
                      
                      case  7: treb = 0b00001000; break;
                      case  6: treb = 0b00001001; break;
                      case  5: treb = 0b00001010; break;
                      case  4: treb = 0b00001011; break;
                      case  3: treb = 0b00001100; break;
                      case  2: treb = 0b00001101; break;
                      case  1: treb = 0b00001110; break;
                      }
               writeWire(0b10110000 + treb);
}
 
void PT2322::setVol(int vol){
            vol = vol - 78;
            vol = abs(vol);
            int vol_10 = vol / 10;
            int vol_1 = vol - vol_10 * 10;
  writeWire(vol_10 + 0b11100000);
  writeWire(vol_1 + 0b11010000);
}


void PT2322::writeWire(char a){
  Wire.beginTransmission(PT2322_address);
//  Wire.write (0b11111111); // очистка регистра
  Wire.write (0b11000111); // активация входов
  Wire.write (0b00000000);
  Wire.write (a);
  Wire.endTransmission();
}
