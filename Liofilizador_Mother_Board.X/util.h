
#ifndef UTIL_H
#define UTIL_H
void print(char *texto);
void bcd2str(char valor, char *dado);
char str2bcd(char *value);
void clear_screen(void);
int my_pow(int rad, int exp);
#if ((defined __18F4620) || (defined __18F4525))
char* itoa(int num, char* str, int base);
char * reverse( char * s );
char *ultoa(unsigned long num, char *str, int radix);
#endif
#endif