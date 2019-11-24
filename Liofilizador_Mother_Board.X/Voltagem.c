#include <xc.h>
#include "global.h"
#include "voltagem.h"
#include "adc.h"


int VOLTAGEM_read(char canal){
    int retorno;
    ADCON1bits.VCFG0=1; //Referencia POSITIVA AN2
    ADCON1bits.VCFG1=1; //Referencia NEGATIVA AN3
    __delay_ms(50);
    retorno=My_ADC_Read(canal);
    ADCON1bits.VCFG0=0; //Referencia POSITIVA VDD
    ADCON1bits.VCFG1=0; //Referencia NEGATIVA VSS
    return retorno;    
}