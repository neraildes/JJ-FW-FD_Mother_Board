#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"
#include "I2C.h"
#include "EEPROM_24C512.h"
#include "util.h"
#include "timedate.h"


void EEPROM_24C512_Write_Byte(unsigned char chip_add, unsigned int mem_add, unsigned char data){
     I2C_Master_Start();                   // start no barramento i2c
     I2C_Master_Write(0xA0|(chip_add<<1));
     I2C_Master_Write(Hi(mem_add));   // endereço da eerprom onde será salvo o dado High
     I2C_Master_Write(Lo(mem_add));   // endereço da eerprom onde será salvo o dado Low     
     I2C_Master_Write(data);    // grava a variável A no endereço 00 da memória serial
     I2C_Master_Stop();         // condição de stop na comunicação i2c      
     Delay_EEPROM_24C512();
}


unsigned char EEPROM_24C512_Read_Byte(unsigned char chip_add, unsigned int mem_add){
    volatile unsigned char retorno;
    I2C_Master_Start();                   // start no barramento i2c 
    I2C_Master_Write(0xA0|(chip_add<<1));
    I2C_Master_Write(Hi(mem_add));        // endereço da eeprom onde será lido o byte h
    I2C_Master_Write(Lo(mem_add));        // endereço da eeprom onde será lido o byte l 
    I2C_Master_RepeatedStart();           // re-start no barramento  
    I2C_Master_Write((0xA1|(chip_add<<1 ))|0x01);
    retorno = I2C_Master_Read(0);         // leitura do endereço 00h na variável_A     
    I2C_Master_Stop();                    // finaliza a comunicação i2c
    Delay_EEPROM_24C512();
    return retorno;  
}


void EEPROM_24C512_Write_Int(unsigned char chip_add, unsigned int mem_add, unsigned int data){
     I2C_Master_Start();              // start no barramento i2c
     I2C_Master_Write(0xA0|(chip_add<<1));
     I2C_Master_Write(Hi(mem_add));   // endereço da eerprom onde será salvo o dado High
     I2C_Master_Write(Lo(mem_add));   // endereço da eerprom onde será salvo o dado Low     
     I2C_Master_Write(Hi(data));      // grava a variável A no endereço 00 da memória serial
     I2C_Master_Write(Lo(data));      // grava a variável A no endereço 00 da memória serial
     I2C_Master_Stop();         // condição de stop na comunicação i2c      
     Delay_EEPROM_24C512();
}

unsigned int EEPROM_24C512_Read_Int(unsigned char chip_add, unsigned int mem_add){
     unsigned int retorno=0;     
     I2C_Master_Start();                   // start no barramento i2c 
     I2C_Master_Write(0xA0|(chip_add<<1));
     I2C_Master_Write(Hi(mem_add));        // endereço da eeprom onde será lido o byte h
     I2C_Master_Write(Lo(mem_add));        // endereço da eeprom onde será lido o byte l 
     I2C_Master_RepeatedStart();           // re-start no barramento  
     I2C_Master_Write(0xA1|(chip_add<<1));
     retorno =(I2C_Master_Read(1)<<8);   // leitura do endereço 00h na variável_A 
     retorno+= I2C_Master_Read(0);       // leitura do endereço 00h na variável_A 
     I2C_Master_Stop();                  // finaliza a comunicação i2c                 
     Delay_EEPROM_24C512();
     return retorno;
}



void EEPROM_24C512_Write_Str(unsigned char chip_add, unsigned int mem_add,char *text){
     I2C_Master_Start();              // start no barramento i2c
     I2C_Master_Write(0xA0|(chip_add<<1));
     I2C_Master_Write(Hi(mem_add));   // endereço da eerprom onde será salvo o dado High
     I2C_Master_Write(Lo(mem_add));   // endereço da eerprom onde será salvo o dado Low     
     while((*text)!=0){
          I2C_Master_Write(*text); //Grava String na EEPROM
          text++;
          }
     I2C_Master_Write(0);
     I2C_Master_Stop();                 // condição de stop na comunicação i2c           
     Delay_EEPROM_24C512();
}


void EEPROM_24C512_Read_Str(unsigned char chip_add, unsigned int mem_add,char *text){
 I2C_Master_Start();                   // start no barramento i2c 
 I2C_Master_Write(0xA0|(chip_add<<1));
 I2C_Master_Write(Hi(mem_add));        // endereço da eeprom onde será lido o byte h
 I2C_Master_Write(Lo(mem_add));        // endereço da eeprom onde será lido o byte l 
 I2C_Master_RepeatedStart();           // re-start no barramento  
 I2C_Master_Write(0xA1|(chip_add<<1));
 while((*text)!=0)
      {
      (*text)=I2C_Master_Read(1);
      text++;
      }
 (*text)=I2C_Master_Read(0);
 I2C_Master_Stop();                // finaliza a comunicação i2c
 Delay_EEPROM_24C512();
}


void EEPROM_24C512_Write_Buffer(unsigned char chip_add, unsigned int mem_add, char size, char *buffer){
     unsigned int i;
     I2C_Master_Start();              // start no barramento i2c
     I2C_Master_Write(0xA0|(chip_add<<1));
     I2C_Master_Write(Hi(mem_add));   // endereço da eerprom onde será salvo o dado High
     I2C_Master_Write(Lo(mem_add));   // endereço da eerprom onde será salvo o dado Low     
     for(i=0;i<size;i++)
        {
        I2C_Master_Write(*buffer); //Grava String na EEPROM
        buffer++;         
        }
     I2C_Master_Stop();                 // condição de stop na comunicação i2c           
     Delay_EEPROM_24C512();
}


void EEPROM_24C512_Read_Buffer(unsigned char chip_add, unsigned int mem_add, char size, char *buffer){
 unsigned int i;   
 I2C_Master_Start();                   // start no barramento i2c 
 I2C_Master_Write(0xA0|(chip_add<<1));
 I2C_Master_Write(Hi(mem_add));        // endereço da eeprom onde será lido o byte h
 I2C_Master_Write(Lo(mem_add));        // endereço da eeprom onde será lido o byte l 
 I2C_Master_RepeatedStart();           // re-start no barramento  
 I2C_Master_Write(0xA1|(chip_add<<1));
 //if(size>63)size=63;
 for(i=0;i<(size-1);i++)
    {
    (*buffer)=I2C_Master_Read(1);    
    buffer++;
    }
 (*buffer)=I2C_Master_Read(0); 
 I2C_Master_Stop();                // finaliza a comunicação i2c
 Delay_EEPROM_24C512();
}















void Delay_EEPROM_24C512(void){
     __delay_us(SERIAL_EEPROM_DELAY);
}