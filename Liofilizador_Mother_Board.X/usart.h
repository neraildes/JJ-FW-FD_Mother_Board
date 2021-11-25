/*-----------------------------------------------------------------------------/
 * File: usart.h                                                               /
 * Author: Neraildes                                                           /
 *                                                                             /
 * Revisão 1.0.0                                                               /
 * Created on 25 de Dezembro de 2017, 11:44                                    /
 * Descrição:                                                                  /
 *                Funções de configuração e comunicação serial                           /
 *                                                                             /
 * Revisão 1.0.1                                                               /
 * Modificado em  18/04/2018, 15:38                                            /
 * Alterações                                                                  /
 *     - Incluido código para trabalhar com 20Mhz                              /
 -----------------------------------------------------------------------------*/

#ifndef USART_H
#define USART_H

#include <xc.h>
#include "protocolo.h"

#define USART_BUFFER_SIZE 10+256  //32 bytes uteis
//#define USART_LINE_BUFFER_SIZE 2 //Linhas de buffer
#define RX_MAX_WAIT_TIME  400    //Loops de recepcao serial
#define TIME_ACQUIRE_MS   2      //Tempo em ms para aguardar resposta 



#define USART_put_enter() USART_putc(13)





void USART_to_Protocol(t_usart_protocol *usart_protocol);
void USART_init(unsigned long baudrate);
void USART_restart(unsigned long baudrate);
void USART_putc(unsigned char value);
void USART_put_int(unsigned int value);
void USART_put_sint(int value);
void USART_put_float24(float value);
void USART_put_long(unsigned long value);
void USART_put_string(char *vetor);
void USART_put_buffer(char *vetor, char size);
unsigned char USART_input_buffer(void);



#endif