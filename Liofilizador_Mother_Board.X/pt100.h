/* 
 * File:   pt100.h
 * Author: Nera
 *
 * Created on 2 de Maio de 2018, 10:36
 */

#ifndef PT100_H
#define PT100_H

#define PT100_CONSTANT   -10.73
#define PT100_TRANSLADA   -1.30


double PT100_Read_Temperature(unsigned char canal);

#endif        /* PT100_H */