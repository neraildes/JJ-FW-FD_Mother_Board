# 1 "pt100.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "pt100.c" 2
# 1 "./global.h" 1
# 24 "./global.h"
#pragma config OSC = INTIO67
#pragma config FCMEN = OFF
#pragma config IESO = OFF


#pragma config PWRT = ON
#pragma config BOREN = SBORDIS
#pragma config BORV = 3


#pragma config WDT = ON
#pragma config WDTPS = 16384


#pragma config CCP2MX = PORTC
#pragma config PBADEN = ON
#pragma config LPT1OSC = OFF
#pragma config MCLRE = ON


#pragma config STVREN = ON
#pragma config LVP = OFF
#pragma config XINST = OFF


#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF


#pragma config CPB = OFF
#pragma config CPD = OFF


#pragma config WRT0 = OFF
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT3 = OFF


#pragma config WRTC = OFF
#pragma config WRTB = OFF
#pragma config WRTD = OFF


#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF


#pragma config EBTRB = OFF
# 229 "./global.h"
struct {
    unsigned flag_usart_rx : 1 ;
    unsigned flag_usart_error : 1 ;
    unsigned flag_power_off : 1 ;
    unsigned flag_led_tmr0 : 1 ;
    unsigned flag_led_usart : 1 ;
    unsigned flag_led_memory : 1 ;
    unsigned flag_capture_datalog : 1 ;
    unsigned flag_edit_temperatura: 1 ;
} statusgen ;
# 252 "./global.h"
union {
      unsigned char bits;
      struct {
             unsigned flag_global_datalog : 1 ;
             unsigned flag_global_aquecimento : 1 ;
             unsigned flag_global_condensador : 1 ;
             unsigned flag_global_vacuo : 1 ;
             unsigned flag_time_process : 1 ;
             unsigned flag_call_work : 1 ;

             };
      } statuspower;
# 274 "./global.h"
struct{
        unsigned flag_save_time :1;
        unsigned flag_wakeup :1;
        unsigned flagSendDataFix :1;
        unsigned flag_Vacuo_estava_ligado :1;
        unsigned flag_generico :1;
}statusgen1;







struct{
        unsigned flag_main_loop_WDT :1;
}statusWDT;


typedef struct{
    unsigned int milisegundo;
    unsigned char segundo;
    unsigned char minuto;
    unsigned char hora;
}t_rtc;

volatile t_rtc rtc;
# 1 "pt100.c" 2

# 1 "./pt100.h" 1
# 15 "./pt100.h"
double PT100_Read_Temperature(unsigned char canal);
# 2 "pt100.c" 2

# 1 "./adc.h" 1
# 15 "./adc.h"
void My_ADC_init(void);
double My_ADC_Read(unsigned char canal);



void My_ADC_init(void) ;
float ADC_Read(unsigned char canal) ;
float ADC_Read_NTC(unsigned char canal) ;
unsigned int LerADcomFiltro(unsigned char canal) ;
unsigned int NovoADCon(unsigned char canal) ;
unsigned int captura();
void ADCON_set(unsigned char canal);
# 3 "pt100.c" 2


double PT100_Read_Temperature(unsigned char canal){



       return My_ADC_Read(canal);
}
