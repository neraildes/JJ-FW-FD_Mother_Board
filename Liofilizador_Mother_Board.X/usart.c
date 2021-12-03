/*------------------------------------------------------------------------------
 * Rotinas para comunicação serial                                           |
 -----------------------------------------------------------------------------*/
#include <xc.h>
#include "global.h"
#include "usart.h"
#include "proculus.h"


extern volatile unsigned char usart_buffer[USART_BUFFER_SIZE]; 
//extern volatile unsigned char usart_buffer_fila[USART_LINE_BUFFER_SIZE][USART_BUFFER_SIZE];
extern volatile unsigned int tmr_led_usart;
extern volatile unsigned int Delay_Led_Usart;

extern int ResetSerial;


/*----------------------------------------------------------------------------*/
void USART_init(unsigned long baudrate)
     {
     unsigned char erro;
     unsigned char i;
     
     //................................USART...............................
     RCSTAbits.SPEN = 1;
     RCSTAbits.CREN = 1;

     TXSTAbits.BRGH    = 1; //Trasmitter hight speeed  
     BAUDCONbits.BRG16 = 0;
     TXSTAbits.SYNC    = 0; //Async mode                                          |
     TXSTAbits.TX9     = 0; //without 9o bit                                      |
     SPBRG             = ((_XTAL_FREQ)/(16*baudrate))-1  ; //spbrg=16                                           |
     INTCONbits.PEIE   = 1; //Periferical Interrupt Enable                        |
     //PIE1bits.RCIE     = 1; //USART receiver RX                                   |
     RCIE=1;   //Habilista interrup��o 
     TXEN=1;
         
     
     TRISCbits.TRISC6= 1;
     TRISCbits.TRISC7= 1;
    
     for(i=0;i<15;i++) erro=RCREG;
}

void flashIndcateReset(int flashes){
     int count;
     //TRISCbits.TRISC6= 0; //TX
     TRISCbits.TRISC7= 0;   //RX
     for(count=0; count<flashes; count++)
        { 
        flag_led_usart  = 1;              
        flag_led_memory = 0;
        PORTCbits.RC7=0;
        __delay_ms(10);
        PORTCbits.RC7=1;                
        __delay_ms(10);
        asm("CLRWDT");
        flag_led_usart  = 0;              
        flag_led_memory = 1;
        PORTCbits.RC7=0;
        __delay_ms(10);
        PORTCbits.RC7=1;                        
        __delay_ms(10);
        asm("CLRWDT");                 
        }
     PORTCbits.RC7=1;                        
     __delay_ms(100);     
     TRISCbits.TRISC7= 1;   //RX
}

void USART_restart(unsigned long baudrate)
{
     ResetSerial++;
     RCSTAbits.SPEN = 0;
     RCSTAbits.CREN = 0;   
     flashIndcateReset(30);
     USART_init(baudrate);
     __delay_ms(1000);
     
}

void USART_to_Protocol(t_usart_protocol *usart_protocol){
     int i;
     usart_protocol->header=(usart_buffer[0]<<8)+usart_buffer[1];
     usart_protocol->origem=usart_buffer[2];
     usart_protocol->destino=usart_buffer[3];
     usart_protocol->command=usart_buffer[4];
     usart_protocol->size=usart_buffer[5];
     for(i=0;i<=usart_protocol->size;i++)
        usart_protocol->value[i]=(unsigned char) usart_buffer[i+6];    
}


void USART_putc(unsigned char value)
{   
    
    unsigned int counter=0;    
    Delay_Led_Usart=DEFAULT_LEDS;
    while(!PIR1bits.TXIF) 
         {
         counter++;
         if(counter>2500)
           {  
           USART_restart(115200);
           counter=0;  
           break;
           }
         continue;//Registrador vazio
         __delay_ms(1);
         }
    TXREG=value;           
}


void USART_putsc(char value)
{   
    putc(value);
}


void USART_put_buffer(char *vetor, char size){       
    char loop=0;
    char *ptr;
    ptr = vetor;
    
    while(loop<size)
    {
        USART_putc(*ptr);        
        ptr++;
        loop++;
    }
}



unsigned char USART_input_buffer(void){
    unsigned int  time=0;
    unsigned char result=FALSE;
    
    while(time<RX_MAX_WAIT_TIME){ 
        if(flag_usart_rx==1){
           flag_usart_rx=FALSE;
           result = TRUE;
           break;
           }
        time++;
        __delay_ms(1);
    }
    return result;
}



void USART_put_int(unsigned int value){
     USART_putc(value>>8);
     USART_putc(value);
}



void USART_put_sint(int value){
     USART_putsc(value>>8);
     USART_putsc(value);
}


void USART_put_long(unsigned long value){
     USART_putc(value>>24);
     USART_putc(value>>16);
     USART_putc(value>>8);
     USART_putc(value);
}


void USART_put_float24(float value){
     unsigned char *pt;
     pt=(unsigned char *) &value;
     USART_putc(*(pt++));
     USART_putc(*(pt++));
     USART_putc(*(pt++));     
}


void USART_put_string(char *vetor)
{       
    char *ptr;
    ptr=vetor;
    while(*(ptr)){ 
        USART_putc(*(ptr));
        ptr++;
    }
    USART_putc(*(ptr));
}

