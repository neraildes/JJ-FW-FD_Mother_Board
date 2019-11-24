//#include <pic18f4620.h>
#include <xc.h>
#include "global.h"
#include "adc.h"

void My_ADC_init(void){
     #if ((defined __18F4620) || (defined __18F4525)) 
     ADCON2bits.ADCS0=1;  //Clock derivado de um oscilador interno.
     ADCON2bits.ADCS1=1;  //Clock derivado de um oscilador interno.
     ADCON1=0b10000000;
     ADCON2bits.ADFM=1; //10 BITS
     ADCON0bits.ADON=1; //Ligar conversor 
     #endif  
}

double My_ADC_Read(unsigned char canal){
       unsigned char i;
       double media=0;
       ADCON0bits.CHS=canal;
       /*
       ADCON0bits.CHS0=0;
       ADCON0bits.CHS1=0;
       ADCON0bits.CHS2=0;
       switch(canal){
          case 2: ADCON0bits.CHS2=1;
          case 1: ADCON0bits.CHS1=1;
          case 0: ADCON0bits.CHS0=1;
       }
       */
       for(i=0; i<SAMPLE_NUMBER; i++){
          ADCON0bits.GO=1;
          while(ADCON0bits.GO)continue;
          media+=(ADRESL+(ADRESH<<8));
          __delay_ms(5);
          }
       media/=SAMPLE_NUMBER;
       return media;

}