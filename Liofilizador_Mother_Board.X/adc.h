/*-----------------------------------------------------------------------------/
 * File:   adc.h                                                               /
 * Author: Neraildes                                                           /
 * Revisão 1.0.0                                                               /
 * Created on 19 de Abril de 2018, 06:24                                       /
 * Descrição:                                                                  /
 *                Funções de Analogic to Digital converter                               /
 -----------------------------------------------------------------------------*/


#ifndef ADC_H
#define ADC_H
#define SAMPLE_NUMBER   10

void My_ADC_init(void);
double My_ADC_Read(unsigned char canal);



void My_ADC_init(void) ;
float ADC_Read(unsigned char canal) ;
float ADC_Read_NTC(unsigned char canal) ;
unsigned int LerADcomFiltro(unsigned char canal) ;
unsigned int NovoADCon(unsigned char canal) ;
unsigned int captura();
void ADCON_set(unsigned char canal);


#endif