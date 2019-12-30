/*------------------------------------------------------------------------------
 * Descricao..................................Rotinas de persistencia de dados |
 * Autor......................................Neraildes da Silva               |
 * Data.......................................13/10/2017                       |
------------------------------------------------------------------------------*/



#include <xc.h>
#include "global.h"
#include "eeprom.h"


extern volatile unsigned int tmr_led_memory;
extern volatile unsigned int Delay_Led_Memory;

/*------------------------------------------------------------------------------
                                  B Y T E                                      |
------------------------------------------------------------------------------*/
void EEPROM_Write_Byte(unsigned int addr, unsigned char dado)
{
    unsigned char last_GIE;
    Delay_Led_Memory=DEFAULT_LEDS; 
    
    while(EECON1bits.WR==1) continue;
    
  
       if(INTCONbits.GIE)
          last_GIE=1;
       else
          last_GIE=0; 
    
       EEADRH=Hi(addr);
       EEADR=Lo(addr);
       EEDATA=dado;
       EECON1bits.EEPGD=0;
       EECON1bits.CFGS=0;
       EECON1bits.WREN=1;
       INTCONbits.GIE=0;
       EECON2=0x55;
       EECON2=0xAA;
       EECON1bits.WR=1;
       
       if(last_GIE) 
          INTCONbits.GIE=1;
       else
          INTCONbits.GIE=0;
       
       EECON1bits.WREN=0;
       __delay_ms(25);
    
}


//------------------------------------------------------------------------------
unsigned char EEPROM_Read_Byte(unsigned int addr)
{    
   Delay_Led_Memory=DEFAULT_LEDS; 
    
   while(EECON1bits.WR==1)continue;   
   EEADRH=Hi(addr);
   EEADR =Lo(addr);   
   EECON1bits.EEPGD=0;
   EECON1bits.CFGS=0;
   EECON1bits.RD=1;
   __delay_ms(25);
   return EEDATA;
   
}

/*------------------------------------------------------------------------------
                          I  N  T  E  G  E  R                                  |
------------------------------------------------------------------------------*/
void EEPROM_Write_Integer(unsigned int addr, unsigned int dado)
{
     EEPROM_Write_Byte(addr,Hi(dado));
     EEPROM_Write_Byte(++addr,Lo(dado));
}

//------------------------------------------------------------------------------
int EEPROM_Read_Integer(unsigned int addr)
{
      int resultado;
      resultado =(int)EEPROM_Read_Byte(addr)<<8 | (int)EEPROM_Read_Byte(addr+1);
      return resultado; 
}






/*------------------------------------------------------------------------------
                 F  L  O  A  T      2 4        B I T S                         |
------------------------------------------------------------------------------*/

void EEPROM_Write_Float(unsigned int addr,float dado)
{
      unsigned char *ptr;
      unsigned char i;
      unsigned char addr_memo;
      addr_memo=addr;
      ptr=(unsigned char *)&dado;
      for (i=0;i<3;i++)
          EEPROM_Write_Byte(addr++,*(ptr++));
}

//------------------------------------------------------------------------------
float EEPROM_Read_Float(unsigned int addr)
{
      float result;
      unsigned char *ptr;
      unsigned char i;
      ptr=(unsigned char *)&result;
      for (i=0;i<3;i++)
          *(ptr++)=EEPROM_Read_Byte(addr++);
      return result;
}




/*------------------------------------------------------------------------------
                                D O U B L E                                    |
------------------------------------------------------------------------------*/
void EEPROM_Write_Double(unsigned int addr,double dado)
{
      unsigned char *ptr;
      unsigned char i;
      unsigned char addr_memo;
      addr_memo=addr;
      ptr=(unsigned char *)&dado;
      for (i=0;i<4;i++)
          EEPROM_Write_Byte(addr++,*(ptr++));
}


//------------------------------------------------------------------------------
float EEPROM_Read_Double(unsigned int addr)
{
      float result;
      unsigned char *ptr;
      unsigned char i;
      ptr=(unsigned char *)&result;
      for (i=0;i<4;i++)
          *(ptr++)=EEPROM_Read_Byte(addr++);
      return result;
}




/*------------------------------------------------------------------------------
                                L  O  N  G                                     |
------------------------------------------------------------------------------*/

void EEPROM_Write_ULong24(unsigned int addr,long dado)
{
      unsigned char *ptr;
      unsigned char i;
      unsigned char addr_memo;
      addr_memo=addr;
      ptr=(unsigned char *)&dado;
      for (i=0;i<3;i++){
          EEPROM_Write_Byte(addr,*ptr);
          addr++;
          ptr++;
          }
}

//------------------------------------------------------------------------------
long EEPROM_Read_ULong24(unsigned int addr)
{
      unsigned long result;
      unsigned char *ptr;
      unsigned char i;
      ptr=(unsigned char *)&result;
      for (i=0;i<3;i++)
          *(ptr++)=EEPROM_Read_Byte(addr++);
      return result;
}





void EEPROM_Write_Long32(unsigned int addr,long dado)
{
      unsigned char *ptr;
      unsigned char i;
      unsigned char addr_memo;
      addr_memo=addr;
      ptr=(unsigned char *)&dado;
      for (i=0;i<4;i++)
           EEPROM_Write_Byte(addr++,*(ptr++));
}



//------------------------------------------------------------------------------
long EEPROM_Read_Long32(unsigned int addr)
{
      unsigned long result;
      unsigned char *ptr;
      unsigned char i;
      ptr=(unsigned char *)&result;
      for (i=0;i<4;i++)
          {
          *(ptr++)=EEPROM_Read_Byte(addr++);
          }
      return result;
}


/*------------------------------------------------------------------------------
                                    STRING                                     |
------------------------------------------------------------------------------*/
void EEPROM_Write_String(unsigned int addr,char *dado)
{
    while(*dado)
    {
     EEPROM_Write_Byte(addr,*dado);
     addr++;
     dado++;
    }
    EEPROM_Write_Byte(addr,0);
}

//------------------------------------------------------------------------------
void EEPROM_Read_String(unsigned int addr,char *dado)
{
    unsigned char c;    
    do{
        c=EEPROM_Read_Byte(addr++);        
        *(dado++)=c;
        //__delay_ms(5);
      }while(c); 
      *(dado)=0;
}



/*------------------------------------------------------------------------------
                                    BUFFER                                     |
------------------------------------------------------------------------------*/
void EEPROM_Write_Buffer(unsigned int addr,char *dado,char size)
{
    for(char i=0;i<size;i++)
    {
     EEPROM_Write_Byte(addr,*dado);
     addr++;
     dado++;
    }
}

//------------------------------------------------------------------------------
void EEPROM_Read_Buffer(unsigned int addr,char *dado,char size)
{
    for(char i=0;i<size;i++)  
        {
        (*dado)=EEPROM_Read_Byte(addr);        
        addr++;
        dado++;
        };
}