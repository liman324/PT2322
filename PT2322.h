// PT2322 | rcl-radio.ru | liman324@yandex.ru
#ifndef  PT2322_H
#define  PT2322_H

#define  PT2322_address 0x44 // адрес

#include <Arduino.h>
class  PT2322
{
  public:
     PT2322();
     ///////////////// аттенюаторы ////////////////////////
        void setFront_lk_att(int f_lk_att);// att front L
        void setFront_rk_att(int f_rk_att);// att front R
        void setCenter_att(int c_att);     // att center
        void setRear_lk_att(int r_lk_att); // att rear L
        void setRear_rk_att(int r_rk_att); // att rear R
        void setSub_att(int sub_att);      // att SUB
            // -15...0 dB (int 15...0)
     //////////////////////////////////////////////////////   
        
        void setFunc(int mute, int ddd, int tembr);// FUNC:  
                                                  // mute - 0 выкл, 1 вкл 
                                                  // ddd - 0 вкл, 1 выкл
                                                  // тембр - 0 вкл, 1 выкл
                                                  // (int 0,0,0) - по умолчанию
        
        void setBass(int bass);            // BASS    -14...0...14 dB (int -7...0...7)
        void setMiddle(int mid);           // MIDDLE  -14...0...14 dB (int -7...0...7)
        void setTreble(int treb);          // TREBLE  -14...0...14 dB (int -7...0...7)
        
        void setVol(int vol);              // VOLUME  -79...0 dB (int 0...79)
  private:
	void writeWire(char a);
};
	
#endif // PT2322_H
