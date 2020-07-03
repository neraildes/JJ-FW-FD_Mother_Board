/*-----------------------------------------------------------------------------/
 * File:   global.h                                                            /
 * Author: Neraildes                                                           /
 * Revisão 1.0.0                                                               /
 * Created on 16 de Fevereiro de 2018                                          /
 * Descrição:                                                                  /
 *                Configurações globais de todas as funções do Dipcoating      /
 -----------------------------------------------------------------------------*/
 
#ifndef GLOBAL_H
#define GLOBAL_H


#if (defined __18F4620)
        // PIC18F4620 Configuration Bit Settings

        // 'C' source line config statements

        // CONFIG1H
        #pragma config OSC = INTIO67    // Oscillator Selection bits (HSpll oscillator)
        #pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
        #pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

        // CONFIG2L
        #pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
        #pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
        #pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

        // CONFIG2H
        #pragma config WDT = ON         // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
        #pragma config WDTPS = 16384    // Watchdog Timer Postscale Select bits (1:32768) 16384= 1:07 minutos

        // CONFIG3H
        #pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
        #pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
        #pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
        #pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

        // CONFIG4L
        #pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
        #pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
        #pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

        // CONFIG5L
        #pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-003FFFh) not code-protected)
        #pragma config CP1 = OFF        // Code Protection bit (Block 1 (004000-007FFFh) not code-protected)
        #pragma config CP2 = OFF        // Code Protection bit (Block 2 (008000-00BFFFh) not code-protected)
        #pragma config CP3 = OFF        // Code Protection bit (Block 3 (00C000-00FFFFh) not code-protected)

        // CONFIG5H
        #pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
        #pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

        // CONFIG6L
        #pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-003FFFh) not write-protected)
        #pragma config WRT1 = OFF       // Write Protection bit (Block 1 (004000-007FFFh) not write-protected)
        #pragma config WRT2 = OFF       // Write Protection bit (Block 2 (008000-00BFFFh) not write-protected)
        #pragma config WRT3 = OFF       // Write Protection bit (Block 3 (00C000-00FFFFh) not write-protected)

        // CONFIG6H
        #pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
        #pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
        #pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

        // CONFIG7L
        #pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
        #pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
        #pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
        #pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)

        // CONFIG7H
        #pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

        // #pragma config statements should precede project file includes.
        // Use project enums instead of #define for ON and OFF.

        #define _XTAL_FREQ 32000000 
        #define  XTAL_32MHZ

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#endif


#if (defined __18F4525)
        // PIC18F4620 Configuration Bit Settings

        // 'C' source line config statements

        // CONFIG1H
        #pragma config OSC = INTIO67    // Oscillator Selection bits (HSpll oscillator)
        #pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
        #pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

        // CONFIG2L
        #pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
        #pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
        #pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

        // CONFIG2H
        #pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
        #pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

        // CONFIG3H
        #pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
        #pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
        #pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
        #pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

        // CONFIG4L
        #pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
        #pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
        #pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

        // CONFIG5L
        #pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-003FFFh) not code-protected)
        #pragma config CP1 = OFF        // Code Protection bit (Block 1 (004000-007FFFh) not code-protected)
        #pragma config CP2 = OFF        // Code Protection bit (Block 2 (008000-00BFFFh) not code-protected)
        //#pragma config CP3 = OFF        // Code Protection bit (Block 3 (00C000-00FFFFh) not code-protected)

        // CONFIG5H
        #pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
        #pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

        // CONFIG6L
        #pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-003FFFh) not write-protected)
        #pragma config WRT1 = OFF       // Write Protection bit (Block 1 (004000-007FFFh) not write-protected)
        #pragma config WRT2 = OFF       // Write Protection bit (Block 2 (008000-00BFFFh) not write-protected)
        //#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (00C000-00FFFFh) not write-protected)

        // CONFIG6H
        #pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
        #pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
        #pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

        // CONFIG7L
        #pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-003FFFh) not protected from table reads executed in other blocks)
        #pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
        #pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
        //#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)

        // CONFIG7H
        #pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

        // #pragma config statements should precede project file includes.
        // Use project enums instead of #define for ON and OFF.

        #define _XTAL_FREQ 32000000 
        #define  XTAL_32MHZ

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#endif


#define HW_NAME          "Mother Board"
#define HW_VERSION       "1.0"
#define HW_DATE          "01/2009"
#define TIPO             EEPROM_Read_Byte(0)




//------------------------------------------------------------------------------
#define UPDATE_ENABLE()  PORTDbits.RD4=1
#define UPDATE_DISABLE() PORTDbits.RD4=0
#define POWER_ON()       PORTDbits.RD2=0
#define POWER_OFF()      PORTDbits.RD2=1

#define HEADER_LIOFILIZADOR 0xAABB
#define BOARD_ADD           0x00  //Não possui jumper de endereço
#define TODOS               0xFF  

#define DEFAULT_LEDS 5      //Tempo de leds indicadores acesos em ms.

#define Lo(param) ((char *)&param)[0]
#define Hi(param) ((char *)&param)[1]
#define Lower(param)((char *)&param)[2]
#define High(param) ((char *)&param)[3]

#define HARDWARE_PIC_VERSION      100
#define HARDWARE_PROCULUS_VERSION PROCULUS_Read_Version()
#define FIRMWARE_PIC_VERSION      100
#define DATABASE_VERSION          100

#define TIME_PASSWORD             30000

#define TRUE  1
#define FALSE 0
//#define ALL   0x0F

#define SOUND_SINGLE 0  //Utilizado em Showmessage do programa principal;
#define SOUND_OK     1

//#define ERRO_CAPTURA 0 //1200

//---------------DEFINE DO DEBUG--------------
#define DOWN   0
#define UP     1
#define TOGGLE 2


//==============================================================================
#define SALVO_COM_SUCESSO        0x50
#define ACESSO_NEGADO            0x52
#define ACESSO_NEGADO_HIDE       0x53
#define SENHA_INVALIDA           0X20 
#define SENHAS_DIFERENTES        0X21
#define SENHA_CADASTRADA_SUCESSO 0x22
#define SENHA_ZERO_INVALIDA      0x23
#define OP_REALIZADA_COM_SUCESSO 0x60 
#define DESEJA_ENCERRAR_PROCESSO 0x42  






//------------------------------------------------------------------------------
#define OFFSET_EEPROM_RECEITA       256
#define RECEITA_EEPROM_SIZE          16
#define OFFSET_VP_RECEITA           420
#define VP_RECEITA_SIZE              10






struct {
    unsigned flag_usart_rx        : 1 ;
    unsigned flag_usart_error     : 1 ;
    unsigned flag_power_off       : 1 ;
    unsigned flag_led_tmr0        : 1 ;
    unsigned flag_led_usart       : 1 ;
    unsigned flag_led_memory      : 1 ;
    unsigned flag_capture_datalog : 1 ;
    unsigned flag_edit_temperatura: 1 ;
} statusgen ;
 
#define flag_usart_rx         statusgen.flag_usart_rx
#define flag_usart_error      statusgen.flag_usart_error
#define flag_power_off        statusgen.flag_power_off
#define flag_led_tmr0         PORTBbits.RB7
#define flag_led_usart        PORTBbits.RB6
#define flag_led_memory       PORTBbits.RB5
#define flag_capture_datalog  statusgen.flag_capture_datalog 
#define flag_edit_temperatura statusgen.flag_edit_temperatura 


//------------------------------------------------------------------------------
// Serão salvos e recuperados caso desligue o sistema (blackout)
union {
      unsigned char bits;
      struct {
             unsigned flag_global_datalog     : 1 ;
             unsigned flag_global_aquecimento : 1 ;
             unsigned flag_global_condensador : 1 ;
             unsigned flag_global_vacuo       : 1 ;
             unsigned flag_time_process       : 1 ;
             unsigned flag_call_work          : 1 ;
             unsigned flag_global_porta       : 1 ;
             
             };      
      } statuspower;    
      

#define flag_global_datalog      statuspower.flag_global_datalog
#define flag_global_aquecimento  statuspower.flag_global_aquecimento     
#define flag_global_condensador  statuspower.flag_global_condensador
#define flag_global_vacuo        statuspower.flag_global_vacuo
#define flag_time_process        statuspower.flag_time_process        
#define flag_call_work           statuspower.flag_call_work
#define flag_global_porta        statuspower.flag_global_porta      

//------------------------------------------------------------------------------
struct{
        unsigned flag_save_time           :1;
        unsigned flag_wakeup              :1;
        unsigned flagSendDataFix          :1;
        unsigned flag_proculus_hs         :1;  
        unsigned flag_Vacuo_estava_ligado :1;
        unsigned flag_generico            :1;
        unsigned flag_recomunication      :1;
        unsigned flag_pc_conected         :1;
}statusgen1;

#define flag_save_time           statusgen1.flag_save_time
#define flag_wakeup              statusgen1.flag_wakeup
#define flagSendDataFix          statusgen1.flagSendDataFix
#define flag_proculus_hs         statusgen1.flag_proculus_hs
#define flag_Vacuo_estava_ligado statusgen1.flag_Vacuo_estava_ligado
#define flag_generico            statusgen1.flag_generico
#define flag_recomunication      statusgen1.flag_recomunication
#define flag_pc_conected         statusgen1.flag_pc_conected
//------------------------------------------------------------------------------
struct{
        unsigned flag_main_loop_WDT :1;    
}statusWDT;
#define flag_main_loop_WDT          statusWDT.flag_main_loop_WDT

typedef struct{
    unsigned int  milisegundo;
    unsigned char segundo;
    unsigned char minuto;
    unsigned char hora;
}t_rtc;

volatile t_rtc rtc;

//==============================================================================

#endif