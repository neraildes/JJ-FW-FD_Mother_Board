// ISR DO SLAVELIOFILIZADOR
#include <xc.h>
#include "global.h"
#include "isr.h"
#include "usart.h"
#include "Liofilizador Placa Mae.h"



/*----------------------------------------------------------------------------*/
extern volatile unsigned char usart_buffer[USART_BUFFER_SIZE];
extern volatile unsigned char usart_buffer_fila[USART_LINE_BUFFER_SIZE][USART_BUFFER_SIZE];

////-----------------timer1-----------------------
//extern volatile unsigned int  milisegundo ;
//extern volatile unsigned char segundo     ;
//extern volatile unsigned char minuto      ;
//extern volatile unsigned char hora        ;


extern volatile unsigned int  tempodecorrido        ;
extern volatile unsigned int  tempocaptura          ; //variavel de captura de dados para memoria datalog
extern volatile unsigned int  tempocapturaconstante ; //variavel de memoria

extern volatile unsigned int  processo_totalminuto;
extern volatile unsigned char processo_segundo ;
extern volatile unsigned char processo_minuto ;
extern volatile unsigned char processo_hora   ;

//==============================================================================


extern volatile unsigned int Delay_Led_Usart;
extern volatile unsigned int  tmr_led_usart;

extern volatile unsigned int Delay_Led_Memory;
extern volatile unsigned int tmr_led_memory;


extern volatile unsigned int Delay_Led_Tmr0;
extern volatile unsigned int tmr_led_tmr0;

//------------------------------------------------------------------------------

extern volatile unsigned char flag_senha_global_liberada ;
extern volatile unsigned char flag_senha_liberada ;
extern volatile unsigned char totalboard ;
extern volatile signed int senhacount ;

//------------------------------------------------------------------------------

extern volatile unsigned int delaycheckscreen;
extern volatile unsigned int delay_update_display;

//------------------------------------------------------------------------------
volatile unsigned int  tempo;


volatile int count;
volatile unsigned char *pointer;

extern volatile char MonitorBuffer;

volatile unsigned char cntAbandona;

extern volatile unsigned char flag_array_slave_WDT[15];

volatile unsigned char ClrReset;

extern volatile unsigned char delay_condensador;

void __interrupt(low_priority) isr(void)
{
    
    //============================= U S A R T ==================================
    if(PIR1bits.RCIF)
        {   
        TRISDbits.RD6=0;
        PORTDbits.RD6=1; 
        tempo=RX_MAX_WAIT_TIME;       
        count=0;
        cntAbandona=255;
        flag_usart_rx=TRUE;
        pointer=usart_buffer;  
        TRISDbits.RD4=0;
        PORTDbits.RD4=1;
        while(tempo)
        {    
            if (PIR1bits.RCIF) 
            {     
                PORTDbits.RD4=0;
                PORTDbits.RD4=1;
                (*pointer)=RCREG;
                if(count<USART_BUFFER_SIZE-1) 
                   {  
                   count++; 
                   pointer++;                
                   }
                tempo=RX_MAX_WAIT_TIME; 
            }
            else    
            {
                tempo--;    
            }  

        }           
        //(*pointer)=0;
        PORTDbits.RD4=0;
        
        if(RCSTAbits.OERR)
           {
           RCSTAbits.CREN=0;
           RCSTAbits.CREN=1;
           tempo=RCREG;
           tempo=RCREG;
           tempo=RCREG;
           usart_buffer[0]=0;
           flag_usart_error=TRUE;
           }
      
    }    
    
    
    
    
 
    //======================== T I M E R   1  ==================================
    if(PIR1bits.TMR1IF==1){
       PIR1bits.TMR1IF=0;  
       TMR1H = 0x3C;          // 0x3CB4 = 50ms
       TMR1L = 0xB4;          // 0xFE0B = 500us

       //-----------------------------------------------------------------------
       //TRISDbits.RD6=0;
       //PORTDbits.RD6=1; 
       ClrReset=TRUE;
       if(flag_main_loop_WDT==FALSE) ClrReset=FALSE;
       
       for(count=1;count<=totalboard;count++) 
           {
           if(flag_array_slave_WDT[count]==FALSE) ClrReset=FALSE;             
           }
       if(ClrReset==TRUE)
          { 
          asm("CLRWDT");      
          flag_main_loop_WDT=FALSE;
          for(count=1;count<15;count++) 
              {
              flag_array_slave_WDT[count]=FALSE;
              }
          }
      //------------------------------------------------------------------------ 
        
        if(rtc.milisegundo>500)
           flag_led_tmr0=0;
        else
           flag_led_tmr0=1;
       
       if(tempocaptura>0)
          {  
          tempocaptura-=50;
          }
       else
          {
          tempocaptura=tempocapturaconstante;  
          flag_capture_datalog=1;  
          }  
       
          

          delaycheckscreen+=50;                
          tempodecorrido+=50;    
          if(!flag_senha_global_liberada)
             if(senhacount>=0)
                senhacount-=50;

          delay_update_display+=50; //Aguarda resposta das placas Slaves       
       //-----------------------------------------------------------------------
          rtc.milisegundo+=50;          
          if(rtc.milisegundo>=1000){
              
             if(flag_time_process)
               { 
               processo_segundo++;
               if(processo_segundo>=60)
                  {
                  processo_segundo=0;
                  processo_minuto++;                  
                  if(processo_minuto>=60)
                    {
                    processo_minuto=0;
                    processo_hora++;
                    if(processo_hora>=100)
                      processo_hora=0;  
                    }  
                  } 
               }         
             
             rtc.milisegundo=0;
             rtc.segundo++;
             if(delay_condensador)delay_condensador--;
             if(rtc.segundo>=60){
                rtc.segundo=0;
                rtc.minuto++; 
                processo_totalminuto++;
                if(rtc.minuto>=60){
                   rtc.minuto=0;                   
                   rtc.hora++; 
                   if(rtc.hora>=24)rtc.hora=0;
                }
             }
          } 
          //PORTDbits.RD6=0;
    }
        
     //========================  I  N  T  F  ===================================
     #if ((defined __18F4620) || (defined __18F4525))  
     if(INTCONbits.INT0IF==1)
       {  
       INTCONbits.INT0IF=0;
       }
     #endif       
       
    
    //============================= T I M E R   0 ==============================
    if(INTCONbits.T0IF==1)
                {
                __delay_us(5);
                TMR0=0xE1;             //Uma interrupção a cada 1.0005ms
                INTCONbits.T0IF=0;     //Precisão

               //-----------------------------------------------------------------------
                  if(Delay_Led_Usart>0){
                     Delay_Led_Usart--;
                     flag_led_usart=1;
                     }
                  else{
                     flag_led_usart=0;
                     }

                  if(Delay_Led_Memory>0){
                     Delay_Led_Memory--;
                     flag_led_memory=1;
                     }
                  else{
                     flag_led_memory=0;
                     }


            }   
    
   
}