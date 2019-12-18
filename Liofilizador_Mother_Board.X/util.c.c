#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "global.h"
#include "util.h"
#include "proculus.h"
#include "usart.h"


//extern volatile unsigned int  tempocaptura; //variavel de captura de dados para memoria datalog
//extern volatile unsigned int  tempocapturaconstante; //variavel de memoria
   
extern unsigned int vpPrint;  
extern int Tamanho_Display;

   
   
   void print(char *texto){ 
        unsigned int vp_roll;
        char textolocal[73];   
        int MAXVP;
        flag_proculus_hs=TRUE;
        
        if(Tamanho_Display==50) MAXVP =  2270;
        if(Tamanho_Display==80) MAXVP =  2420;
   
        
        if(vpPrint<=MAXVP)
          { 
          
          PROCULUS_VP_Write_String(vpPrint,texto);
          
          vpPrint+=30;
          }
        else
          {
          for(vp_roll=2000;vp_roll<=MAXVP;vp_roll+=30)
             {
             strcpy(textolocal,""); 
             PROCULUS_VP_Read_String(vp_roll+30, textolocal);
             PROCULUS_VP_Write_String(vp_roll, textolocal);             
             }
          
          PROCULUS_VP_Write_String(MAXVP, texto);
          
          }  
        flag_proculus_hs=FALSE;
   }
   
void clear_screen(void){
    for(unsigned int i=2000;i<=2420;i+=30)
        PROCULUS_VP_Write_String(i," ");
    vpPrint=2000;
}   
   
void bcd2str(char valor, char *dado){     
     dado[0]=((valor>>4)+0x30);
     dado[1]=((0x0F&valor)+0x30);
     dado[2]=0;          
     }

char str2bcd(char *value){
     return ((value[0]<<4)|(0x0F & (value[1])));
}


#if ((defined __18F4620) || (defined __18F4525))  
// Implementation of itoa() 
char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    char isNegative = FALSE; 
  
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (num < 0 && base == 10) 
    { 
        isNegative = TRUE; 
        num = -num; 
    } 
  
    // Process individual digits 
    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        str[i++] = '-'; 
  
    str[i] = '\0'; // Append string terminator 
  
    // Reverse the string 
    reverse(str); 
  
    return str; 
} 



char * reverse( char * s )
{
    int length = strlen(s) ;
    int c, i, j;

    for (i=0, j=length-1; i<j; i++, j--)
        {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
        }
    return s;
}

#endif


/*******************************************************
* Code contributed by Chris Takahashi,                 *
* ctakahashi (at) users (dot) sourceforge (dot) net.   *
* See stdlib.h for licence.                            *
* $Date: 2005/08/31 11:39:47 $                         *
*******************************************************/
char *ultoa(unsigned long num, char *str, int radix) {
    char temp[33];  //an int can only be 16 bits long
                    //at radix 2 (binary) the string
                    //is at most 16 + 1 null long.
    int temp_loc = 0;
    int digit;
    int str_loc = 0;

    //construct a backward string of the number.
    do {
        digit = (unsigned long)num % radix;
        if (digit < 10) 
            temp[temp_loc++] = digit + '0';
        else
            temp[temp_loc++] = digit - 10 + 'A';
                        num  = (unsigned long)num /radix;
    } while ((unsigned long)num > 0);

    temp_loc--;


    //now reverse the string.
    while ( temp_loc >=0 ) {// while there are still chars
        str[str_loc++] = temp[temp_loc--];    
    }
    str[str_loc] = 0; // add null termination.

    return str;
}


//------------------------------------------------------------------------------
int my_pow(int rad, int exp){
    int resposta;
    if(exp==0)
       resposta=1;
    else if(exp==1)
           {
           resposta=rad; 
           }
    else
       {
       resposta=rad;
       for(char i=0;i<exp-1;i++)
          { 
          resposta*=rad; 
          } 
       }
    return resposta;    
}