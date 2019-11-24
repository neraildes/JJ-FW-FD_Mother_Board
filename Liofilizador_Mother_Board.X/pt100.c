#include "global.h"
#include "pt100.h"
#include "adc.h"

double PT100_Read_Temperature(unsigned char canal){
       //
       // ADC_Read(canal);
       //((5.0/1023)*(1023.0-ADC_Read(canal))*(PT100_CONSTANT))+(PT100_TRANSLADA);
       return My_ADC_Read(canal);
}