#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "timedate.h"


//------------------------------------------------------------------------------
void my_delay_ms(long time){
     long i;
     for(i=0;i<time;i++) 
        {            
        __delay_ms(1);            
        }
}



void my_delay_ms_TMR1(long time){
     long i;
     for(i=0;i<time;i++) 
        { 
        __delay_ms(1); 
        if((flag_global_datalog==1)&&(flag_capture_datalog==1))break;
        }
   }  
   


void my_delay_ms_CLRWDT(long time){
     long i;
     for(i=0;i<time;i++) 
        { 
        __delay_ms(1); 
        asm("CLRWDT");
        }    
}  