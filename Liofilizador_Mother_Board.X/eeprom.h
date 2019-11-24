/*-----------------------------------------------------------------------------/
 * File:   eeprom.h
 * Author: Neraildes
 * Revisão 1.0.0
 * Created on 13 de Outubro de 2017, 06:25
 * Descrição:
 *		Leitura e gravação de EEEPROM interna do microcontrolador PIC.
 -----------------------------------------------------------------------------*/


#ifndef EEPROM_H
#define EEPROM_H

void          EEPROM_Write_Byte(unsigned int addr, unsigned char dado);
unsigned char EEPROM_Read_Byte(unsigned int addr);
void          EEPROM_Write_Integer(unsigned int addr, unsigned int dado);
int           EEPROM_Read_Integer(unsigned int addr);
void          EEPROM_Write_Float(unsigned int addr,float dado);
float         EEPROM_Read_Float(unsigned int addr);
void          EEPROM_Write_Double(unsigned int addr,double dado);
float         EEPROM_Read_Double(unsigned int addr);


void EEPROM_Write_ULong24(unsigned int addr,long dado);
long EEPROM_Read_ULong24(unsigned int addr);
void          EEPROM_Write_Long32(unsigned int addr,long dado);
long          EEPROM_Read_Long32(unsigned int addr);

void          EEPROM_Write_String(unsigned int addr,char *dado);
void          EEPROM_Read_String(unsigned int addr,char *dado);

void          EEPROM_Write_Buffer(unsigned int addr,char *dado,char size);
void          EEPROM_Read_Buffer(unsigned int addr,char *dado,char size);

#endif
