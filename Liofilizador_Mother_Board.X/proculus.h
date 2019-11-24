/*-----------------------------------------------------------------------------/
 * File:   proculus.h 
 * Author: Neraildes
 * Revisão 1.0.0
 * Created on 17 de Outubro de 2017, 09:17
 * Descrição:
 *                Funções de comunicação com o display victor vision.
 *                Partnumber/Modelo: P48272V43C_T07
 *      Tamanho: 4.3 polegadas
 *      Resolução: 480x272
 -----------------------------------------------------------------------------*/

#ifndef PROCULUS_H
#define PROCULUS_H


#define Control_Register_Write 0x80
#define Control_Register_Read  0x81
#define VP_WRITE               0x82
#define VP_READ                0x83
#define TREND_CURVE_WRITE      0x84

//---------------CONTROL REGISTER-----------------
#define VERSION_INFO           0x00
#define DEFAULT_BACKLIGHT      0x01
#define ACTIVE_BUZZER          0x02
#define PIC_ID                 0x03
#define DATA_TIME_READ         0x20


#define NAME_TASK_SIZE         30


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

#define PROCULUS_HEADER            0x5AA5
#define CONSTANT_FIX_01            0x0683
#define CONSTANT_FIX_02            0x0582
#define PROCULUS_Reg_Read          0x0381
#define PROCULUS_Reg_Write         0x0380

#define PROCULUS_DATA_SIZE         15

#define TIME_AFTER_SEND_PROCULUS_COMMAND 1

#define WINDOW_TELA_01 1
#define WINDOW_TELA_02 2
#define WINDOW_TELA_03 3
#define WINDOW_TELA_04 4
#define WINDOW_TELA_05 5


#define DELAY_PROCULUS __delay_ms(32)


const int TrendColor[13]={
                          0x0000, //Preto
                          0x39E7, //Cinza escuro
                          0x6B6D, //Cinza claro
                          0x7800, //Marron Escuro
                          0x9A23, //Marron Claro
                          0xF800, //Vermelho vivo
                          0xFBE0, //Laranja
                          0xFBF7, //Rosa
                          0xD540, //Amarelo Escuro
                          0x03E0, //Verde Escuro
                          0x07E0, //Verde Claro
                          0x07FF, //Azul Piscina
                          0xF81F  //Roxo
                          };

typedef struct {
    unsigned int  header;
    unsigned char size;
    unsigned char function;    
    unsigned int  vp;
    unsigned char length;   
    unsigned int  dado[PROCULUS_DATA_SIZE];
    unsigned char page;
    unsigned char button;
    unsigned char status;    
    }t_proculus;
  
    
typedef struct{
              unsigned char plataforma;
              unsigned int  temperaturaatual;
              unsigned int  setpoint;
              unsigned char tempoON;
              unsigned char tempoOFF;
              } t_visaogeral;    
              
    
void PROCULUS_REG_Write(unsigned char *vetor, unsigned char size);
void PROCULUS_REG_Read(unsigned char reg, unsigned char size, unsigned char *retorno);
void PROCULUS_Read_RTC(char *date, char *time);
void PROCULUS_Write_RTC(char *date, char *time);
void PROCULUS_Control_Activation(char value);

void PROCULUS_VP_Write(unsigned int vp,char *vetor,char size);


void PROCULUS_VP_Read(unsigned int vp,char *vetor,char size);



//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


//--------------------------------- byte ---------------------------------------
void PROCULUS_VP_Write_Byte(unsigned int vp,char value);
unsigned char PROCULUS_VP_Read_Byte(unsigned int vp);


//----------------------- Unsigned int16 ---------------------------------------
void PROCULUS_VP_Write_UInt16(unsigned int vp, unsigned int value);
unsigned int PROCULUS_VP_Read_UInt16(unsigned int vp);


//-------------------------- signed int16 --------------------------------------
void PROCULUS_VP_Write_Int16(unsigned int vp, int value);
unsigned int PROCULUS_VP_Read_Int16(int vp);


//-------------------------------- long ----------------------------------------
long PROCULUS_VP_Read_Long32(unsigned int vp);
void PROCULUS_VP_Write_Long32(unsigned int vp, unsigned long value);


//-------------------------------- float ---------------------------------------
void PROCULUS_VP_Write_Float24(unsigned int vp, float value);
float PROCULUS_VP_Read_Float24(unsigned int vp);

void PROCULUS_VP_Write_Float32(unsigned int vp, float value);
float PROCULUS_VP_Read_Float32(unsigned int vp);



//-------------------------------- double --------------------------------------
void PROCULUS_VP_Write_Double24(unsigned int vp, double value);
double PROCULUS_VP_Read_Double24(unsigned int vp);

void PROCULUS_VP_Write_Double32(unsigned int vp, double value);
double PROCULUS_VP_Read_Double32(unsigned int vp);

//-----------------------------string-------------------------------------------
void PROCULUS_VP_Write_String(unsigned int vp, char *text);
void PROCULUS_VP_Read_String(unsigned int vp, char *text);   

//----------------------------plotagem de grafico-------------------------------
//void PROCULUS_graphic_plot(unsigned char board, unsigned char lcd_channel, unsigned char board_channel);




unsigned char PROCULUS_Read_Version(void);
void PROCULUS_Buzzer(unsigned int time_ms_x_10);
void PROCULUS_Show_Screen(unsigned int screen);
void PROCULUS_Reset(void);
char PROCULUS_TPFLAG_Read(void);
void PROCULUS_TPFLAG_Write(char value);

void PROCULUS_Buffer_to_Proculus(t_proculus *proculus);

void PROCULUS_OK(void);
void PROCULUS_NOK(void);

void PROCULUS_Delay(unsigned int tempo_ms);   

unsigned int PROCULUS_Get_Page(void);

void PROCULUS_Popup(char value);

void PROCULUS_graphic_plot(unsigned char lcd_channel, unsigned int value); //Plotar gráfico

void PROCULUS_Clear_Line_Graphic(char channel);

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx



#endif        /* PROCULUS_H */