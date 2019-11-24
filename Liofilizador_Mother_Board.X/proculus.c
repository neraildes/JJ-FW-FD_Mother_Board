//#include <xc.h>
#include "global.h"
#include "proculus.h"
//#include "database.h"
#include "usart.h"
#include <string.h>
#include "util.h"
#include <math.h>
#include "timedate.h"

extern volatile unsigned char usart_buffer[USART_BUFFER_SIZE];
volatile unsigned int  tempodecorrido;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void PROCULUS_REG_Write(unsigned char *vetor, unsigned char size){
     unsigned char i;
     DELAY_PROCULUS;
     USART_put_int(PROCULUS_HEADER);
     USART_putc((unsigned char)(1+size));
     USART_putc(Control_Register_Write);
     for(i=0;i<size;i++)
         USART_putc(vetor[i]);
     my_delay_ms(TIME_AFTER_SEND_PROCULUS_COMMAND);
}




void PROCULUS_REG_Read(unsigned char reg, unsigned char size, unsigned char *retorno){
     unsigned char i;
     unsigned int tempo;
     if(!flag_proculus_hs) DELAY_PROCULUS; 
     USART_put_int(PROCULUS_HEADER);
     USART_putc((unsigned char)(2+size)); //era 1+size
     USART_putc(Control_Register_Read);
     USART_putc(reg);
     USART_putc(size);
     
     
     TRISDbits.RD4=0;
     PORTDbits.RD4=1;

     tempo=0;
     while(tempo<RX_MAX_WAIT_TIME)
           {
           __delay_us(500);
           if(flag_usart_rx) 
              {
              flag_usart_rx=0;              
              for(i=0;i<size;i++) 
                 { 
                 *(&retorno[i])=(unsigned char)usart_buffer[(6+i)];                 
                 }
              break;
              } 
           tempo++;                   
           } 
     
     PORTDbits.RD4=0;
     
     my_delay_ms(TIME_AFTER_SEND_PROCULUS_COMMAND);
          
}



//------------------------------------------------------------------------------
void PROCULUS_VP_Write(unsigned int vp,char *vetor,char size){
     unsigned char i;
     if(!flag_proculus_hs) DELAY_PROCULUS;     
     USART_put_int(PROCULUS_HEADER);
     USART_putc((unsigned char)(3+size));
     USART_putc(VP_WRITE);
     USART_put_int(vp);
     for(i=0;i<size;i++)
        USART_putc(vetor[i]);
     USART_putc(0);
     my_delay_ms(TIME_AFTER_SEND_PROCULUS_COMMAND);

}

//------------------------------------------------------------------------------
void PROCULUS_VP_Read(unsigned int vp,char *vetor,char size){ 
     unsigned char i;
     unsigned int  tempo;
     t_proculus proculus;
     
     

     DELAY_PROCULUS;
     USART_put_int(PROCULUS_HEADER);   //5AA5
     USART_putc(4);
     USART_putc(VP_READ);
     USART_put_int(vp);
     USART_putc((unsigned char)(size>>1));  // size = size / 2  
     __delay_us(50);




     tempo=0;
     while(tempo<RX_MAX_WAIT_TIME) 
           {
           __delay_us(500);
           if(flag_usart_rx) 
              {
              flag_usart_rx=0;  
              for(i=0;i<size;i++) 
                 { 
                 *(&vetor[i])=usart_buffer[(7+i)];                                 
                 }              
              break;
              } 
           tempo++;
           }      
    my_delay_ms(TIME_AFTER_SEND_PROCULUS_COMMAND);
}    


void PROCULUS_Control_Activation(char value){
     my_delay_ms(500);
     USART_put_int(PROCULUS_HEADER);
     USART_putc(0x03);
     USART_putc(Control_Register_Write);
     USART_putc(0x4F);
     USART_putc(value);
     my_delay_ms(500);
}

void PROCULUS_Popup(char value){
     PROCULUS_Control_Activation(value);
}



void PROCULUS_Read_RTC(char *date,char *time){
     char i;
     char retorno[10];
     char year[3],month[3],day[3],hour[3],minute[3],second[3];
     
     
     USART_put_int(PROCULUS_HEADER);
     USART_putc(0x03); //size
     USART_putc(Control_Register_Read); //reg. de leitura
     USART_putc(0x20); //registro
     USART_putc(0x07); //quantidade de bytes a ler
     
     
     if(USART_input_buffer())     
        {
        for(i=0;i<10;i++)
            retorno[i] = usart_buffer[(unsigned char)(6+i)];  
        }
        
        bcd2str(retorno[0],year);
        bcd2str(retorno[1],month);
        bcd2str(retorno[2],day);
        
        strcpy(date,"");
        strcat(date,day);
        strcat(date,"/");
        strcat(date,month);        
        strcat(date,"/");
        strcat(date,year);         
        
        bcd2str(retorno[4],hour);
        bcd2str(retorno[5],minute);
        bcd2str(retorno[6],second);
        
        strcpy(time,"");
        strcat(time,hour);
        strcat(time,":");
        strcat(time,minute);        
        strcat(time,":");
        strcat(time,second);        
        
        my_delay_ms(TIME_AFTER_SEND_PROCULUS_COMMAND);
}

void PROCULUS_Write_RTC(char *date, char *time){
     char year[3],month[3],day[3],hour[3],minute[3],second[3];    

     year[0]=date[6]; 
     year[1]=date[7]; 
     year[2]=0;     
     
     month[0]=date[3]; 
     month[1]=date[4]; 
     month[2]=0;
     
     day[0]=date[0];
     day[1]=date[1];
     day[2]=0;
     
     hour[0]=time[0];
     hour[1]=time[1];
     hour[2]=0;
             
     minute[0]=time[3];
     minute[1]=time[4];
     minute[2]=0;
             
     second[0]=time[6];
     second[1]=time[7];
     second[2]=0;     
     
     USART_put_int(PROCULUS_HEADER);
     USART_putc(0x0A); //size
     USART_putc(Control_Register_Write); //reg. de escrita
     USART_putc(0x1F); //registro
     USART_putc(0x5A); //não sei o que é isso??????
     USART_putc(str2bcd(year));
     USART_putc(str2bcd(month));
     USART_putc(str2bcd(day));
     USART_putc(0x01); //dia da semana
     USART_putc(str2bcd(hour));
     USART_putc(str2bcd(minute));
     USART_putc(str2bcd(second));  
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                 
                     
                     
                  





//------------------------------- VP WRITE -------------------------------------


void PROCULUS_VP_Write_Byte(unsigned int vp,char value){
     char vetor[1];
     vetor[0]=value;
     PROCULUS_VP_Write(vp,vetor,1);
     my_delay_ms(TIME_AFTER_SEND_PROCULUS_COMMAND);
}
unsigned char PROCULUS_VP_Read_Byte(unsigned int vp){
     char vetor[1];
     PROCULUS_VP_Read(vp,vetor,1);
     return vetor[0];
}



//---------------------------  I  N  T  1  6  ----------------------------------
void PROCULUS_VP_Write_UInt16(unsigned int vp, unsigned int value){
     char vetor[2];
     unsigned char *pt;
     pt=(unsigned char *)(&value);
     vetor[1]=(char)(value);
     vetor[0]=(char)(value>>8);      
     PROCULUS_VP_Write(vp,vetor,2);
}

unsigned int PROCULUS_VP_Read_UInt16(unsigned int vp){
     char vetor[2];
     PROCULUS_VP_Read(vp,vetor,2);
     return (((unsigned int)vetor[0]<<8)+vetor[1]);
}



//---------------------------  I  N  T  1  6  ----------------------------------
void PROCULUS_VP_Write_Int16(unsigned int vp, int value){
     char vetor[2];
     char *pt;
     pt=(char *)(&value);
     vetor[1]=(char)(value>>8);
     vetor[0]=(char)(value);      
     PROCULUS_VP_Write(vp,vetor,2);
}
unsigned int PROCULUS_VP_Read_Int16(int vp){
     char vetor[2];
     PROCULUS_VP_Read(vp,vetor,2);
     return (int)((vetor[0]<<8)+vetor[1]);
}








//--------------------------------  L  O  N  G  --------------------------------
void PROCULUS_VP_Write_Long32(unsigned int vp, unsigned long value){
     char vetor[4];
     unsigned char *pt;
     pt=(unsigned char *)(&value);
     vetor[3]=(char)(*(pt++)); 
     vetor[2]=(char)(*(pt++));    
     vetor[1]=(char)(*(pt++));
     vetor[0]=(char)(*(pt++));    
     PROCULUS_VP_Write(vp,vetor,4);
}


long PROCULUS_VP_Read_Long32(unsigned int vp){
     char vetor[4];
     long retorno=1234; //fix
     PROCULUS_VP_Read(vp,vetor,4);
     /*
     retorno (long)(
             (long)(*(vetor+0)<<24)|
             (long)(*(vetor+1)<<16)|
             (long)(*(vetor+2)<< 8)|
             (long) *(vetor+3)
             );
     */ 
     return retorno;
}
 


/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 *                       P O N T O      F L U T U A N T E                       
 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/


//--------------------------------- F L O A T ----------------------------------
void PROCULUS_VP_Write_Float24(unsigned int vp, float value){
     char vetor[4];
     char *pt;
     pt=(char *)(&value);
     vetor[2]=(char)(*(pt++));    
     vetor[1]=(char)(*(pt++));
     vetor[0]=(char)(*(pt++));      
     PROCULUS_VP_Write(vp,vetor,3);
}
 float PROCULUS_VP_Read_Float24(unsigned int vp){
     char vetor[4];
     PROCULUS_VP_Read(vp,vetor,4);
     //return (vetor[0]<<24)+(vetor[1]<<16)+(vetor[2]<<8)+(vetor[3]); fix
     return 1234;
}


void PROCULUS_VP_Write_Float32(unsigned int vp, float value){
     char vetor[4];
     char *pt;
     pt=(char *)(&value);
     vetor[3]=(char)(*(pt++)); 
     vetor[2]=(char)(*(pt++));    
     vetor[1]=(char)(*(pt++));
     vetor[0]=(char)(*(pt++));      
     PROCULUS_VP_Write(vp,vetor,4);
}
 float PROCULUS_VP_Read_Float32(unsigned int vp){
     char vetor[4];
     PROCULUS_VP_Read(vp,vetor,4);
     //return (vetor[0]<<24)+(vetor[1]<<16)+(vetor[2]<<8)+(vetor[3]); fix
     return 1234;
}




//------------------------------ D O U B L E -----------------------------------

void PROCULUS_VP_Write_Double24(unsigned int vp, double value){ //Não testada
     char  vetor[3];
     char  *pnt;
     
     pnt=(char *)(&value);
     vetor[0]=*(pnt++);
     vetor[1]=*(pnt++);
     vetor[2]=*(pnt++);
     PROCULUS_VP_Write(vp,vetor,3);          
}
double PROCULUS_VP_Read_Double24(unsigned int vp){
     char vetor[3];
     PROCULUS_VP_Read(vp,vetor,3);
     //return (vetor[0]<<16)+(vetor[1]<<8)+(vetor[2]); fix
     return 1234;
}

 
 
void PROCULUS_VP_Write_Double32(unsigned int vp, double value){
     double vetor[4];
     /*
     vetor[0]=(double)(value<<32);
     vetor[1]=(double)(value<<16);    
     vetor[2]=(double)(value<<8);        
     vetor[3]=(double)(value);
     */  //fix
     PROCULUS_VP_Write(vp,(char*)vetor,4);
}     
double PROCULUS_VP_Read_Double32(unsigned int vp){
     char vetor[4];
     PROCULUS_VP_Read(vp,vetor,4);
     //return (vetor[0]<<24)+(vetor[1]<<16)+(vetor[2]<<8)+(vetor[3]); fix
     return 1234;
}     


//--------------------------- S T R I N G --------------------------------------

void PROCULUS_VP_Write_String(unsigned int vp,char *text){     
     PROCULUS_VP_Write(vp, text, strlen(text)+1);
}

void PROCULUS_VP_Read_String(unsigned int vp,char *text){
     PROCULUS_VP_Read(vp, text, NAME_TASK_SIZE);
}



//------------------------------------------------------------------------------


unsigned char PROCULUS_Read_Version(void){
    unsigned char retorno[2];
    PROCULUS_REG_Read(VERSION_INFO,2,retorno);
    return retorno[0];
}

void PROCULUS_Buzzer(unsigned int time_ms_x_10){
     unsigned char vetor[2];
     time_ms_x_10 /= 10;
     vetor[0]=ACTIVE_BUZZER;
     vetor[1]=(unsigned char) time_ms_x_10;
     PROCULUS_REG_Write(vetor,2); 
}










void PROCULUS_Reset(void){
     unsigned char vetor[3];
     vetor[0]=0xEE;
     vetor[1]=0x5A;
     vetor[2]=0xA5;
     PROCULUS_REG_Write(vetor,3); 
}




//---------------------------------------------------------------------
void PROCULUS_Show_Screen(unsigned int screen){
     unsigned char vetor[3];
     vetor[0] = PIC_ID;
     vetor[1] = (char)(screen>>8);  
     vetor[2] = (char) screen;              
     PROCULUS_REG_Write(vetor,3);     
}



/*
void PROCULUS_Buffer_to_Proculus(t_proculus *proculus){
     proculus->header      =(*(usart_buffer+0)<<8)+*(usart_buffer+1);
     proculus->size        = *(usart_buffer+2);
     proculus->function    = *(usart_buffer+3);
     proculus->VP          =(*(usart_buffer+4)<<8)+*(usart_buffer+5);
     proculus->length      = *(usart_buffer+6);
     for(unsigned char i=0;i<PROCULUS_DATA_SIZE;i++) 
         proculus->data[i] = usart_buffer[7+i];
}
*/

void PROCULUS_Buffer_to_Proculus(t_proculus *proculus){
     unsigned char i;
     proculus->header  = (usart_buffer[0]<<8)+usart_buffer[1];
     proculus->size    = usart_buffer[2];
     proculus->function= usart_buffer[3];
     proculus->vp      = (usart_buffer[4]<<8)+usart_buffer[5];
     proculus->length  = usart_buffer[6];
     for (i=0;i<=proculus->size;i++)
     proculus->dado[i] = usart_buffer[7+i];
     proculus->page    = usart_buffer[7];
     proculus->button  = ((usart_buffer[8]>>4)&0x0F);
     proculus->status  = (usart_buffer[8]&0x0F);     
}






void PROCULUS_OK(void){
     PROCULUS_Buzzer(100);
     my_delay_ms(100);
     PROCULUS_Buzzer(100);
     my_delay_ms(100);
     PROCULUS_Buzzer(100);     
}


void PROCULUS_NOK(void){
     PROCULUS_Buzzer(300);
     my_delay_ms(100);
}



/*
void PROCULUS_Delay(unsigned int tempo_ms){  
     unsigned int i;
     for(i=0;i<tempo_ms;i++){
        Delay_ms(1);
    }
}
*/


unsigned int PROCULUS_Get_Page(void)
     {
     int i;
     volatile unsigned int retorno=0;
     USART_put_int(PROCULUS_HEADER);
     USART_putc(0x03);
     USART_putc(0x81);
     USART_putc(0x03);
     USART_putc(0x02);     
     for(i=0;i<1000;i++)
         {    
           if(flag_usart_rx)
           {
           flag_usart_rx=0;
           retorno=(usart_buffer[6]<<8)+usart_buffer[7];
           break;
           }
           __delay_ms(1);
         }     
     my_delay_ms(TIME_AFTER_SEND_PROCULUS_COMMAND);
     return retorno;
     }


//void PROCULUS_graphic_plot(unsigned char board, unsigned char lcd_channel, unsigned char board_channel){
//     float fvalue;
//     USART_put_int(PROCULUS_HEADER);
//     USART_putc(0x12);
//     USART_putc(0x84);
//     USART_putc(0x01);
//     for(unsigned char teste=0;teste<200;teste++)
//         {
//         fvalue=sin(teste);
//         fvalue*=100.0;
//         USART_put_int(fvalue);
//         }
// }    
     
    





void PROCULUS_TPFLAG_Write(char value){
    unsigned char vetor[3];
    vetor[0]=5;
    vetor[1]=value;
    PROCULUS_REG_Write(vetor, 2);
    //Envia  5A A5 03 81 05 01

}


char PROCULUS_TPFLAG_Read(void){
     unsigned char retorno[10];
     PROCULUS_REG_Read(0x05, 0x01, retorno);     
     return retorno[0]; 
     //envio     5A A5 03 81 05 01
     //resposta  5A A5 04 81 05 01 5A
}


void PROCULUS_graphic_plot(unsigned char lcd_channel, unsigned int value){
     char channel;
     if((lcd_channel>=1)&&(lcd_channel<=8))
       {          
       channel=(char)my_pow(2,(lcd_channel-1));
       USART_put_int(PROCULUS_HEADER);
       USART_putc(0x04);
       USART_putc(0x84);
       USART_putc(channel);
       USART_put_int(1150+value);
       }
}

void PROCULUS_Clear_Line_Graphic(char channel){
     unsigned char buffer[2];
     buffer[0]=0xEB;
     buffer[1]=0x55+channel;
     PROCULUS_REG_Write(buffer,0x03);
}



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

/*

//------------------------- Read Version of Display ---------------------
unsigned int PROCULUS_Version(void){
    unsigned char result;
    
    USART_put_int(PROCULUS_Header);
    USART_put_int(PROCULUS_Reg_Read);
    USART_put_int(0x0001);
    
    if(USART_input_buffer())
       result = *(&usart_buffer[6]);
    else
       result = 0;
    
    PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);     
    
    return result;

}


//----------------------------- RESET the LCD -------------------------
void PROCULUS_Reset(void){
     USART_put_int(PROCULUS_Header);
     USART_put_int(0x0480);
     USART_put_int(0xEE5A);
     USART_putc(0xA5);
     
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);      
}


//------------------------------ BUZZER -------------------------------
void PROCULUS_Buzzer(unsigned int tempo){
     unsigned int value;    
     tempo /= 10.0;
     value=(0x0200|tempo);
     USART_put_int(PROCULUS_Header);
     USART_put_int(PROCULUS_Reg_Write);         
     USART_put_int(value);   
     
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);      
}


//---------------------------------------------------------------------
void PROCULUS_Show_Screen(unsigned int screen){
     USART_put_int(PROCULUS_Header);
     USART_put_int(0x0480);
     USART_put_int(0x0300);
     USART_putc(screen);
     
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);      
}



//------------------------------------------------------------------------------
void PROCULUS_Send_Char(unsigned char caracter, unsigned char size, unsigned int vp){
     unsigned char byte_count; 
    
     byte_count=3+size; 
    
     USART_put_int(PROCULUS_Header);
     USART_putc(byte_count);
     USART_put_int(PROCULUS_VP_Write);
     USART_putc((char)(vp>>8)); 
     USART_putc((char)vp); 
     for(unsigned char i=0;i<size;i++)
         USART_putc(caracter);   
    
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND); 
} 





//--------------------------------------------------------------------
void PROCULUS_Write_VP_String(unsigned char *texto, unsigned int vp){
     unsigned char byte_count; 
    
     byte_count=3+(strlen(texto)+1); 
    
     USART_put_int(PROCULUS_Header);
     USART_putc(byte_count);
     USART_put_int(PROCULUS_VP_Write);
     USART_putc((char)(vp>>8)); 
     USART_putc((char)vp); 
     for(unsigned char i=0;i<strlen(texto);i++)
         USART_putc(*(texto+i));  
     USART_putc(0);
     
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);
} 


//------------------------------------------------------------------------------
unsigned char PROCULUS_Read_VP_String(unsigned int vp, unsigned char size, unsigned char *output){
    unsigned char result=FALSE;
    
    USART_put_int(PROCULUS_Header);
    USART_put_int(0x0483);
    USART_put_int(vp);
    USART_putc(size); 
    
    if(USART_input_buffer()){ //dados vem no usart_buffer
       result=TRUE;
       for(unsigned char i=0; i<size; i++)
           output[i]=usart_buffer[7+i];          
       }    
    return result;   
}


//--------------------------------------------------------------------
unsigned char PROCULUS_Read_VP_Long24(unsigned int vp, unsigned char size, unsigned long *output){
    unsigned char result=FALSE;
   
    USART_put_int(PROCULUS_Header);
    USART_put_int(0x0483);
    USART_put_int(vp);
    USART_putc(size); 
   
    if(USART_input_buffer()){ //dados vem no usart_buffer
       result=TRUE;
       
       *(output)=(usart_buffer[7]<<24)+
                 (usart_buffer[8]<<16)+
                 (usart_buffer[9]<<8)+
                 (usart_buffer[10]); 
       } 
         
    return result;   
}



//----------------------------------------------------------------------
void PROCULUS_Write_VP_Long24(unsigned long value, unsigned int vp){
     unsigned char byte_count;
    
     byte_count=3+4;
    
     USART_put_int(PROCULUS_Header);
     USART_putc(byte_count);
     USART_put_int(PROCULUS_VP_Write);
     USART_putc(vp>>8);
     USART_putc(vp);
     USART_put_long(value);
     
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);

} 


//------------------------------------------------------------------------------
unsigned int PROCULUS_Read_Int(unsigned int vp){
    unsigned char output;
    t_proculus proculus;
    unsigned char *pt;
    unsigned char result=FALSE;
    
    proculus.header=PROCULUS_Header;
    proculus.function=0x1883;
    proculus.VP=vp;
    proculus.length=2; 
    
    if(USART_input_buffer()){ //dados vem no usart_buffer
       proculus.header=usart_buffer[0]<<8+usart_buffer[1]<<0;
       proculus.function=usart_buffer[2]<<8+usart_buffer[3]<<0;
       proculus.VP=usart_buffer[4]<<8+usart_buffer[5]<<5;
       proculus.length=usart_buffer[6];
       strcpy(proculus.data,&usart_buffer[7]);
       output=proculus.data;
       result=TRUE;          
       }    
    return usart_buffer[7]<<8+usart_buffer[6];
}

//------------------------------------------------------------------------------
unsigned long PROCULUS_Read_Long(unsigned int vp){
    unsigned char output;
    t_proculus proculus;
    unsigned char *pt;
    unsigned char result=FALSE;
    
    proculus.header=PROCULUS_Header;
    proculus.function=0x1883;
    proculus.VP=vp;
    proculus.length=2; 
    
    if(USART_input_buffer()){ //dados vem no usart_buffer
       proculus.header=usart_buffer[0]<<8+usart_buffer[1]<<0;
       proculus.function=usart_buffer[2]<<8+usart_buffer[3]<<0;
       proculus.VP=usart_buffer[4]<<8+usart_buffer[5]<<5;
       proculus.length=usart_buffer[6];
       strcpy(proculus.data,&usart_buffer[7]);
       output=proculus.data;
       result=TRUE;          
       }    
    return usart_buffer[8]<<8+usart_buffer[7]<<8+usart_buffer[6];
}


void PROCULUS_Buffer_to_Proculus(t_proculus *proculus){
     proculus->header      =(*(usart_buffer+0)<<8)+*(usart_buffer+1);
     proculus->function    =(*(usart_buffer+2)<<8)+*(usart_buffer+3);
     proculus->VP          =(*(usart_buffer+4)<<8)+*(usart_buffer+5);
     proculus->length      = *(usart_buffer+6);
     for(unsigned char i=0;i<PROCULUS_DATA_SIZE;i++) 
         proculus->data[i] = usart_buffer[7+i];
}






unsigned char USART_put_Proculus(t_proculus *proculus){
    unsigned char result=FALSE;
    USART_put_int(proculus->header);
    USART_put_int(proculus->function);
    USART_put_int(proculus->VP);
    USART_putc(proculus->length);
}





//----------------------------------------------------------------------
void PROCULUS_Send_Int(unsigned int value, unsigned int vp){
     unsigned char byte_count;
     byte_count=3+4;    
     USART_put_int(PROCULUS_Header);
     USART_put_int(0x0483);
     USART_put_int(vp);
     USART_putc(2); //size  
     
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);
} 




//-----------------------------------------------------------------------
void PROCULUS_Send_Float24(unsigned long value, unsigned int vp){
     unsigned char byte_count;
    
     byte_count=3+3;
    
     USART_put_int(PROCULUS_Header);
     USART_putc(byte_count);
     USART_put_int(PROCULUS_VP_Write);
     USART_putc(vp>>8);
     USART_putc(vp);
     USART_put_float24(value);
     
     PROCULUS_Delay_Tx(TIME_AFTER_SEND_PROCULUS_COMMAND);
     
} 





*/


/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
 * 
 * 
 * 
 xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/