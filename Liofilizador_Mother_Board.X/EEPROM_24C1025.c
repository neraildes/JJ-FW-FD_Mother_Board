#include <xc.h>
#include <stdlib.h>
#include "global.h"
#include "I2C.h"
#include "EEPROM_24C1025.h"
#include "usart.h"


extern volatile unsigned int Delay_Led_Memory; //Verde

extern char buffer[64];
//------------------------------------------------------------------------------

void EEPROM_24C1025_Write_Buffer(unsigned char chip_add, 
                                 unsigned long mem_add,
                                 unsigned char sizedata,
                                 char *data)
     {
     unsigned char range=0;
     unsigned char ctrl;
     unsigned char count;
     
     Delay_Led_Memory=DEFAULT_LEDS;
     
     if(mem_add>0x1FFFF) return;
     
     if(mem_add>0xFFFF) range=0x08; else range=0x00;
     ctrl=chip_add;
     ctrl<<=1;
     ctrl |= 0xA0;
     ctrl |= range;     
    
     I2C_Master_Start();              // start no barramento i2c
     I2C_Master_Write(ctrl);
     I2C_Master_Write(Hi(mem_add));   // endere�o da eerprom onde ser� salvo o dado High
     I2C_Master_Write(Lo(mem_add));   // endere�o da eerprom onde ser� salvo o dado Low     
     for(count=0;count<(sizedata-1);count++) 
          {
          if(mem_add>0x1FFFF) return;
          if((mem_add+1)%128==0)
            {
            I2C_Master_Write(*data);
            I2C_Master_Stop();

            __delay_ms(5);
            mem_add++;
            data++;
            if(mem_add>0xFFFF) range=0x08; else range=0x00;
            ctrl=chip_add;
            ctrl<<=1;
            ctrl |= 0xA0;
            ctrl |= range;    

            I2C_Master_Start();       
            I2C_Master_Write(ctrl);
            I2C_Master_Write(Hi(mem_add));   
            I2C_Master_Write(Lo(mem_add));   
            }
          else
            {  
            I2C_Master_Write(*data); 
            data++;
            mem_add++;
            }
     } 
     I2C_Master_Write(*data);
     I2C_Master_Stop();                // condi��o de stop na comunica��o i2c           
     __delay_ms(5);                   //__delay_us(650);
}




//------------------------------------------------------------------------------
void EEPROM_24C1025_Read_Buffer(unsigned char chip_add, 
                                unsigned long mem_add,
                                unsigned char sizedata,
                                char *data)
     {
     unsigned char cnt=0;
     unsigned char range=0;
     unsigned char ctrl;
     
     Delay_Led_Memory=DEFAULT_LEDS;
     
     if(mem_add>0x1FFFF) return;
     
     if(mem_add>0xFFFF) range=0x08; else range=0x00;
     ctrl=chip_add;
     ctrl<<=1;
     ctrl |= 0xA0;
     ctrl |= 0b00000001;//Fazer Leitura
     ctrl |= range;     
     
     I2C_Master_Start();                   // start no barramento i2c 
     I2C_Master_Write(ctrl & 0xFE);
     I2C_Master_Write(Hi(mem_add));        // endere�o da eeprom onde ser� lido o byte h
     I2C_Master_Write(Lo(mem_add));        // endere�o da eeprom onde ser� lido o byte l 
     I2C_Master_RepeatedStart();           // re-start no barramento  
     I2C_Master_Write(ctrl);
     
     for(char cnt=0;cnt<(sizedata);cnt++)
        {
           if(mem_add>0x1FFFF) break;
           if((mem_add+1)%128==0)
             {
             (*data)=I2C_Master_Read(0);
             I2C_Master_Stop(); 
             
             __delay_ms(5);
             mem_add++;
             data++;             
             if(mem_add>0xFFFF) range=0x08; else range=0x00;
             ctrl=chip_add;
             ctrl<<=1;
             ctrl |= 0xA0;
             ctrl |= 0b00000001;//Fazer Leitura
             ctrl |= range;              
                         
             I2C_Master_Start();                   // start no barramento i2c 
             I2C_Master_Write(ctrl & 0xFE);
             I2C_Master_Write(Hi(mem_add));        // endere�o da eeprom onde ser� lido o byte h
             I2C_Master_Write(Lo(mem_add));        // endere�o da eeprom onde ser� lido o byte l 
             I2C_Master_RepeatedStart();           // re-start no barramento  
             I2C_Master_Write(ctrl);       
             }  
           else
             {
             (*data)=I2C_Master_Read(1); 
             data++;
             mem_add++;
             }           
        }       
        I2C_Master_Read(0);
        I2C_Master_Stop();                // finaliza a comunica��o i2c
        __delay_us(650); 
}





//------------------------------------------------------------------------------
void EEPROM_24C1025_Read_Buffer_to_USART(unsigned char chip_add, 
                                         unsigned long mem_add,
                                         unsigned char sizedata,
                                         char *data)
     {
     unsigned char cnt=0;
     unsigned char range=0;
     unsigned char ctrl;
     
     Delay_Led_Memory=DEFAULT_LEDS;
     
     if(mem_add>0x1FFFF) return;
     
     if(mem_add>0xFFFF) range=0x08; else range=0x00;
     ctrl=chip_add;
     ctrl<<=1;
     ctrl |= 0xA0;
     ctrl |= 0b00000001;//Fazer Leitura
     ctrl |= range;     
     
     I2C_Master_Start();                   // start no barramento i2c 
     I2C_Master_Write(ctrl & 0xFE);
     I2C_Master_Write(Hi(mem_add));        // endere�o da eeprom onde ser� lido o byte h
     I2C_Master_Write(Lo(mem_add));        // endere�o da eeprom onde ser� lido o byte l 
     I2C_Master_RepeatedStart();           // re-start no barramento  
     I2C_Master_Write(ctrl);
     
     for(char cnt=0;cnt<(sizedata);cnt++)
        {
           if(mem_add>0x1FFFF) break;
           if((mem_add+1)%128==0)
             {
             (*data)=I2C_Master_Read(0);
             I2C_Master_Stop(); 
             USART_putc(*data);
             
             __delay_ms(5);
             mem_add++;
             //data++;             
             if(mem_add>0xFFFF) range=0x08; else range=0x00;
             ctrl=chip_add;
             ctrl<<=1;
             ctrl |= 0xA0;
             ctrl |= 0b00000001;//Fazer Leitura
             ctrl |= range;              
                         
             I2C_Master_Start();                   // start no barramento i2c 
             I2C_Master_Write(ctrl & 0xFE);
             I2C_Master_Write(Hi(mem_add));        // endere�o da eeprom onde ser� lido o byte h
             I2C_Master_Write(Lo(mem_add));        // endere�o da eeprom onde ser� lido o byte l 
             I2C_Master_RepeatedStart();           // re-start no barramento  
             I2C_Master_Write(ctrl);       
             }  
           else
             {
             (*data)=I2C_Master_Read(1); 
             USART_putc(*data);
             //data++;
             mem_add++;
             }           
        }       
        I2C_Master_Read(0);
        I2C_Master_Stop();                // finaliza a comunica��o i2c
        __delay_us(650); 
}






void EEPROM_24C1025_Write_Str(unsigned char chip_add, unsigned long mem_add,char *data){
     unsigned char range=0;
     unsigned char ctrl;
     
     if(mem_add>0x1FFFF) return;
     
     if(mem_add>0xFFFF) range=0x08; else range=0x00;
     ctrl=chip_add;
     ctrl<<=1;
     ctrl |= 0xA0;
     ctrl |= range;    

     I2C_Master_Start();              // start no barramento i2c
     I2C_Master_Write(ctrl);
     I2C_Master_Write(Hi(mem_add));   // endere�o da eerprom onde ser� salvo o dado High
     I2C_Master_Write(Lo(mem_add));   // endere�o da eerprom onde ser� salvo o dado Low     
     while(*data)
          {
          if(mem_add>0x1FFFF) return;
          if((mem_add+1)%128==0)
            {
            I2C_Master_Write(*data);
            I2C_Master_Stop();

            __delay_ms(5);
            mem_add++;
            data++;
            if(mem_add>0xFFFF) range=0x08; else range=0x00;
            ctrl=chip_add;
            ctrl<<=1;
            ctrl |= 0xA0;
            ctrl |= range;    

            I2C_Master_Start();       
            I2C_Master_Write(ctrl);
            I2C_Master_Write(Hi(mem_add));   
            I2C_Master_Write(Lo(mem_add));   
            }
          else
            {  
            I2C_Master_Write(*data); 
            data++;
            mem_add++;
            }
     } 
     I2C_Master_Write(0);
     I2C_Master_Stop();                // condi��o de stop na comunica��o i2c           
     __delay_ms(5);     
     
}




void EEPROM_24C1025_Read_Str(unsigned char chip_add, unsigned long mem_add,char *texto){
     unsigned char cnt=0;
     unsigned char range=0;
     unsigned char ctrl;

     if(mem_add>0x1FFFF) return;
     
     if(mem_add>0xFFFF) range=0x08; else range=0x00;
     ctrl=chip_add;
     ctrl<<=1;
     ctrl |= 0xA0;
     ctrl |= 0b00000001;//Fazer Leitura
     ctrl |= range;     
     
     I2C_Master_Start();                   // start no barramento i2c 
     I2C_Master_Write(ctrl & 0xFE);
     I2C_Master_Write(Hi(mem_add));        // endere�o da eeprom onde ser� lido o byte h
     I2C_Master_Write(Lo(mem_add));        // endere�o da eeprom onde ser� lido o byte l 
     I2C_Master_RepeatedStart();           // re-start no barramento  
     I2C_Master_Write(ctrl);
     
     cnt=0;
     do{
           if(mem_add>0x1FFFF) break;
           if((mem_add+1)%128==0)
             {
             (*texto)=I2C_Master_Read(0);
             I2C_Master_Stop(); 
             
             __delay_ms(5);
             mem_add++;
             texto++;             
             if(mem_add>0xFFFF) range=0x08; else range=0x00;
             ctrl=chip_add;
             ctrl<<=1;
             ctrl |= 0xA0;
             ctrl |= 0b00000001;//Fazer Leitura
             ctrl |= range;              
                         
             I2C_Master_Start();                   // start no barramento i2c 
             I2C_Master_Write(ctrl & 0xFE);
             I2C_Master_Write(Hi(mem_add));        // endere�o da eeprom onde ser� lido o byte h
             I2C_Master_Write(Lo(mem_add));        // endere�o da eeprom onde ser� lido o byte l 
             I2C_Master_RepeatedStart();           // re-start no barramento  
             I2C_Master_Write(ctrl);       
             }  
           else
             {
             (*texto)=I2C_Master_Read(1);
             if((*texto)==0)break;
             texto++;
             mem_add++;
             }           
       }while((cnt++)<64);
       
     I2C_Master_Read(0);
     I2C_Master_Stop();                // finaliza a comunica��o i2c
     __delay_us(650); 
}






//-------------------------------------BYTE-------------------------------------
void EEPROM_24C1025_Write_Byte(unsigned char chip_add, unsigned long mem_add, char data){
     EEPROM_24C1025_Write_Buffer(chip_add, mem_add, 1, &data);
}


unsigned char EEPROM_24C1025_Read_Byte(unsigned char chip_add, unsigned long mem_add){
    char data;
    EEPROM_24C1025_Read_Buffer(chip_add, mem_add, 1, &data);
    return data;
}

//--------------------------------------INT-------------------------------------
void EEPROM_24C1025_Write_Int(unsigned char chip_add, unsigned long mem_add, int data){
     char local[2];
     local[0]=Hi(data);
     local[1]=Lo(data);
     EEPROM_24C1025_Write_Buffer(chip_add, mem_add, 2, local);
}


unsigned int EEPROM_24C1025_Read_Int(unsigned char chip_add, unsigned long mem_add){
    char data[2];
    EEPROM_24C1025_Read_Buffer(chip_add, mem_add, 2, data);
    return (data[0]<<8)+data[1];
}


//---------------------------------LONG-----------------------------------------
void EEPROM_24C1025_Write_Long(unsigned char chip_add, unsigned long mem_add, long data){
     char local[4];
     local[0]=High(data);
     local[1]=Lower(data);
     local[2]=Hi(data);
     local[3]=Lo(data);     
     EEPROM_24C1025_Write_Buffer(chip_add, mem_add, 4, local);
}

unsigned long EEPROM_24C1025_Read_Long(unsigned char chip_add, unsigned long mem_add){
    char data[4];
    long resultado;
    EEPROM_24C1025_Read_Buffer(chip_add, mem_add, 4, data);
    resultado=((long)data[0]<<24)|
              ((long)data[1]<<16)|
              ((long)data[2]<<8) |
              ((long)data[3]<<0) ;
    return resultado;        
}







//----------------------------FILL----------------------------------------------
void EEPROM_24C1025_Fill_All(unsigned char chip_add, unsigned int value){
     unsigned long mem_add;
     for(mem_add=0;mem_add<=0x3FF;mem_add+=2)
        { 
        EEPROM_24C1025_Write_Int(chip_add, mem_add, value); 
        asm("CLRWDT");        
        }
}














