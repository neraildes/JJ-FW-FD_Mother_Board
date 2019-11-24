/* 
 * File:   timedate.h
 * Author: Nera
 *
 * Created on 26 de Janeiro de 2019, 11:03
 */
#ifndef TIMEDATE_H
#define	TIMEDATE_H

#include <xc.h>
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "global.h"

//unsigned long Time_DateToEpoch(char *date, char *time);

void my_delay_ms(long time);
void my_delay_ms_TMR1(long time); //Delay com saida obrigatoria quando tmr1 estourar (500ms)
void my_delay_ms_CLRWDT(long time);


#endif	/* TIMEDATE_H */

