# 1 "Liofilizador Placa Mae.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Liofilizador Placa Mae.c" 2








# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\xc.h" 1 3
# 18 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\xc.h" 3
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\xc8debug.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 2 3






# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 2 3
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 18 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 122 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 168 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdlib.h" 2 3


int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);



long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);

          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);

void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);

typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);





size_t __ctype_get_mb_cur_max(void);
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\xc8debug.h" 2 3








#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 23 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\xc.h" 2 3
# 32 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\xc.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 1 3




# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\htc.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\xc.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\htc.h" 2 3
# 5 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 2 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18_chip_select.h" 1 3
# 734 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18_chip_select.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 1 3
# 44 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\__at.h" 1 3
# 44 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 2 3








extern volatile unsigned char PORTA __attribute__((address(0xF80)));

__asm("PORTA equ 0F80h");


typedef union {
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
    struct {
        unsigned :4;
        unsigned T0CKI :1;
        unsigned AN4 :1;
    };
    struct {
        unsigned :5;
        unsigned SS :1;
    };
    struct {
        unsigned :5;
        unsigned NOT_SS :1;
    };
    struct {
        unsigned :5;
        unsigned nSS :1;
    };
    struct {
        unsigned :5;
        unsigned LVDIN :1;
    };
    struct {
        unsigned :5;
        unsigned HLVDIN :1;
    };
    struct {
        unsigned ULPWUIN :1;
        unsigned :6;
        unsigned RJPU :1;
    };
} PORTAbits_t;
extern volatile PORTAbits_t PORTAbits __attribute__((address(0xF80)));
# 189 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PORTB __attribute__((address(0xF81)));

__asm("PORTB equ 0F81h");


typedef union {
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
        unsigned RB3 :1;
        unsigned RB4 :1;
        unsigned RB5 :1;
        unsigned RB6 :1;
        unsigned RB7 :1;
    };
    struct {
        unsigned INT0 :1;
        unsigned INT1 :1;
        unsigned INT2 :1;
        unsigned CCP2 :1;
        unsigned KBI0 :1;
        unsigned KBI1 :1;
        unsigned KBI2 :1;
        unsigned KBI3 :1;
    };
    struct {
        unsigned AN12 :1;
        unsigned AN10 :1;
        unsigned AN8 :1;
        unsigned AN9 :1;
        unsigned AN11 :1;
        unsigned PGM :1;
        unsigned PGC :1;
        unsigned PGD :1;
    };
    struct {
        unsigned :3;
        unsigned CCP2_PA2 :1;
    };
} PORTBbits_t;
extern volatile PORTBbits_t PORTBbits __attribute__((address(0xF81)));
# 360 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PORTC __attribute__((address(0xF82)));

__asm("PORTC equ 0F82h");


typedef union {
    struct {
        unsigned RC0 :1;
        unsigned RC1 :1;
        unsigned RC2 :1;
        unsigned RC3 :1;
        unsigned RC4 :1;
        unsigned RC5 :1;
        unsigned RC6 :1;
        unsigned RC7 :1;
    };
    struct {
        unsigned T1OSO :1;
        unsigned T1OSI :1;
        unsigned CCP1 :1;
        unsigned SCK :1;
        unsigned SDI :1;
        unsigned SDO :1;
        unsigned TX :1;
        unsigned RX :1;
    };
    struct {
        unsigned T13CKI :1;
        unsigned CCP2 :1;
        unsigned :1;
        unsigned SCL :1;
        unsigned SDA :1;
        unsigned :1;
        unsigned CK :1;
        unsigned DT :1;
    };
    struct {
        unsigned T1CKI :1;
    };
    struct {
        unsigned :1;
        unsigned PA2 :1;
        unsigned PA1 :1;
    };
} PORTCbits_t;
extern volatile PORTCbits_t PORTCbits __attribute__((address(0xF82)));
# 535 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PORTD __attribute__((address(0xF83)));

__asm("PORTD equ 0F83h");


typedef union {
    struct {
        unsigned RD0 :1;
        unsigned RD1 :1;
        unsigned RD2 :1;
        unsigned RD3 :1;
        unsigned RD4 :1;
        unsigned RD5 :1;
        unsigned RD6 :1;
        unsigned RD7 :1;
    };
    struct {
        unsigned PSP0 :1;
        unsigned PSP1 :1;
        unsigned PSP2 :1;
        unsigned PSP3 :1;
        unsigned PSP4 :1;
        unsigned PSP5 :1;
        unsigned PSP6 :1;
        unsigned PSP7 :1;
    };
    struct {
        unsigned :5;
        unsigned P1B :1;
        unsigned P1C :1;
        unsigned P1D :1;
    };
    struct {
        unsigned :7;
        unsigned SS2 :1;
    };
} PORTDbits_t;
extern volatile PORTDbits_t PORTDbits __attribute__((address(0xF83)));
# 677 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PORTE __attribute__((address(0xF84)));

__asm("PORTE equ 0F84h");


typedef union {
    struct {
        unsigned RE0 :1;
        unsigned RE1 :1;
        unsigned RE2 :1;
        unsigned RE3 :1;
    };
    struct {
        unsigned RD :1;
        unsigned WR :1;
        unsigned CS :1;
        unsigned MCLR :1;
    };
    struct {
        unsigned NOT_RD :1;
    };
    struct {
        unsigned :1;
        unsigned NOT_WR :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_CS :1;
    };
    struct {
        unsigned :3;
        unsigned NOT_MCLR :1;
    };
    struct {
        unsigned nRD :1;
        unsigned nWR :1;
        unsigned nCS :1;
        unsigned nMCLR :1;
    };
    struct {
        unsigned AN5 :1;
        unsigned AN6 :1;
        unsigned AN7 :1;
        unsigned VPP :1;
    };
    struct {
        unsigned PD2 :1;
        unsigned PC2 :1;
        unsigned CCP10 :1;
        unsigned CCP9E :1;
    };
    struct {
        unsigned RDE :1;
        unsigned WRE :1;
        unsigned PB2 :1;
        unsigned PC3E :1;
    };
} PORTEbits_t;
extern volatile PORTEbits_t PORTEbits __attribute__((address(0xF84)));
# 880 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char LATA __attribute__((address(0xF89)));

__asm("LATA equ 0F89h");


typedef union {
    struct {
        unsigned LATA0 :1;
        unsigned LATA1 :1;
        unsigned LATA2 :1;
        unsigned LATA3 :1;
        unsigned LATA4 :1;
        unsigned LATA5 :1;
        unsigned LATA6 :1;
        unsigned LATA7 :1;
    };
    struct {
        unsigned LA0 :1;
        unsigned LA1 :1;
        unsigned LA2 :1;
        unsigned LA3 :1;
        unsigned LA4 :1;
        unsigned LA5 :1;
        unsigned LA6 :1;
        unsigned LA7 :1;
    };
} LATAbits_t;
extern volatile LATAbits_t LATAbits __attribute__((address(0xF89)));
# 992 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char LATB __attribute__((address(0xF8A)));

__asm("LATB equ 0F8Ah");


typedef union {
    struct {
        unsigned LATB0 :1;
        unsigned LATB1 :1;
        unsigned LATB2 :1;
        unsigned LATB3 :1;
        unsigned LATB4 :1;
        unsigned LATB5 :1;
        unsigned LATB6 :1;
        unsigned LATB7 :1;
    };
    struct {
        unsigned LB0 :1;
        unsigned LB1 :1;
        unsigned LB2 :1;
        unsigned LB3 :1;
        unsigned LB4 :1;
        unsigned LB5 :1;
        unsigned LB6 :1;
        unsigned LB7 :1;
    };
} LATBbits_t;
extern volatile LATBbits_t LATBbits __attribute__((address(0xF8A)));
# 1104 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char LATC __attribute__((address(0xF8B)));

__asm("LATC equ 0F8Bh");


typedef union {
    struct {
        unsigned LATC0 :1;
        unsigned LATC1 :1;
        unsigned LATC2 :1;
        unsigned LATC3 :1;
        unsigned LATC4 :1;
        unsigned LATC5 :1;
        unsigned LATC6 :1;
        unsigned LATC7 :1;
    };
    struct {
        unsigned LC0 :1;
        unsigned LC1 :1;
        unsigned LC2 :1;
        unsigned LC3 :1;
        unsigned LC4 :1;
        unsigned LC5 :1;
        unsigned LC6 :1;
        unsigned LC7 :1;
    };
} LATCbits_t;
extern volatile LATCbits_t LATCbits __attribute__((address(0xF8B)));
# 1216 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char LATD __attribute__((address(0xF8C)));

__asm("LATD equ 0F8Ch");


typedef union {
    struct {
        unsigned LATD0 :1;
        unsigned LATD1 :1;
        unsigned LATD2 :1;
        unsigned LATD3 :1;
        unsigned LATD4 :1;
        unsigned LATD5 :1;
        unsigned LATD6 :1;
        unsigned LATD7 :1;
    };
    struct {
        unsigned LD0 :1;
        unsigned LD1 :1;
        unsigned LD2 :1;
        unsigned LD3 :1;
        unsigned LD4 :1;
        unsigned LD5 :1;
        unsigned LD6 :1;
        unsigned LD7 :1;
    };
} LATDbits_t;
extern volatile LATDbits_t LATDbits __attribute__((address(0xF8C)));
# 1328 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char LATE __attribute__((address(0xF8D)));

__asm("LATE equ 0F8Dh");


typedef union {
    struct {
        unsigned LATE0 :1;
        unsigned LATE1 :1;
        unsigned LATE2 :1;
    };
    struct {
        unsigned LE0 :1;
        unsigned LE1 :1;
        unsigned LE2 :1;
    };
} LATEbits_t;
extern volatile LATEbits_t LATEbits __attribute__((address(0xF8D)));
# 1380 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TRISA __attribute__((address(0xF92)));

__asm("TRISA equ 0F92h");


extern volatile unsigned char DDRA __attribute__((address(0xF92)));

__asm("DDRA equ 0F92h");


typedef union {
    struct {
        unsigned TRISA0 :1;
        unsigned TRISA1 :1;
        unsigned TRISA2 :1;
        unsigned TRISA3 :1;
        unsigned TRISA4 :1;
        unsigned TRISA5 :1;
        unsigned TRISA6 :1;
        unsigned TRISA7 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
} TRISAbits_t;
extern volatile TRISAbits_t TRISAbits __attribute__((address(0xF92)));
# 1495 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned TRISA0 :1;
        unsigned TRISA1 :1;
        unsigned TRISA2 :1;
        unsigned TRISA3 :1;
        unsigned TRISA4 :1;
        unsigned TRISA5 :1;
        unsigned TRISA6 :1;
        unsigned TRISA7 :1;
    };
    struct {
        unsigned RA0 :1;
        unsigned RA1 :1;
        unsigned RA2 :1;
        unsigned RA3 :1;
        unsigned RA4 :1;
        unsigned RA5 :1;
        unsigned RA6 :1;
        unsigned RA7 :1;
    };
} DDRAbits_t;
extern volatile DDRAbits_t DDRAbits __attribute__((address(0xF92)));
# 1602 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TRISB __attribute__((address(0xF93)));

__asm("TRISB equ 0F93h");


extern volatile unsigned char DDRB __attribute__((address(0xF93)));

__asm("DDRB equ 0F93h");


typedef union {
    struct {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
        unsigned TRISB3 :1;
        unsigned TRISB4 :1;
        unsigned TRISB5 :1;
        unsigned TRISB6 :1;
        unsigned TRISB7 :1;
    };
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
        unsigned RB3 :1;
        unsigned RB4 :1;
        unsigned RB5 :1;
        unsigned RB6 :1;
        unsigned RB7 :1;
    };
} TRISBbits_t;
extern volatile TRISBbits_t TRISBbits __attribute__((address(0xF93)));
# 1717 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned TRISB0 :1;
        unsigned TRISB1 :1;
        unsigned TRISB2 :1;
        unsigned TRISB3 :1;
        unsigned TRISB4 :1;
        unsigned TRISB5 :1;
        unsigned TRISB6 :1;
        unsigned TRISB7 :1;
    };
    struct {
        unsigned RB0 :1;
        unsigned RB1 :1;
        unsigned RB2 :1;
        unsigned RB3 :1;
        unsigned RB4 :1;
        unsigned RB5 :1;
        unsigned RB6 :1;
        unsigned RB7 :1;
    };
} DDRBbits_t;
extern volatile DDRBbits_t DDRBbits __attribute__((address(0xF93)));
# 1824 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TRISC __attribute__((address(0xF94)));

__asm("TRISC equ 0F94h");


extern volatile unsigned char DDRC __attribute__((address(0xF94)));

__asm("DDRC equ 0F94h");


typedef union {
    struct {
        unsigned TRISC0 :1;
        unsigned TRISC1 :1;
        unsigned TRISC2 :1;
        unsigned TRISC3 :1;
        unsigned TRISC4 :1;
        unsigned TRISC5 :1;
        unsigned TRISC6 :1;
        unsigned TRISC7 :1;
    };
    struct {
        unsigned RC0 :1;
        unsigned RC1 :1;
        unsigned RC2 :1;
        unsigned RC3 :1;
        unsigned RC4 :1;
        unsigned RC5 :1;
        unsigned RC6 :1;
        unsigned RC7 :1;
    };
} TRISCbits_t;
extern volatile TRISCbits_t TRISCbits __attribute__((address(0xF94)));
# 1939 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned TRISC0 :1;
        unsigned TRISC1 :1;
        unsigned TRISC2 :1;
        unsigned TRISC3 :1;
        unsigned TRISC4 :1;
        unsigned TRISC5 :1;
        unsigned TRISC6 :1;
        unsigned TRISC7 :1;
    };
    struct {
        unsigned RC0 :1;
        unsigned RC1 :1;
        unsigned RC2 :1;
        unsigned RC3 :1;
        unsigned RC4 :1;
        unsigned RC5 :1;
        unsigned RC6 :1;
        unsigned RC7 :1;
    };
} DDRCbits_t;
extern volatile DDRCbits_t DDRCbits __attribute__((address(0xF94)));
# 2046 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TRISD __attribute__((address(0xF95)));

__asm("TRISD equ 0F95h");


extern volatile unsigned char DDRD __attribute__((address(0xF95)));

__asm("DDRD equ 0F95h");


typedef union {
    struct {
        unsigned TRISD0 :1;
        unsigned TRISD1 :1;
        unsigned TRISD2 :1;
        unsigned TRISD3 :1;
        unsigned TRISD4 :1;
        unsigned TRISD5 :1;
        unsigned TRISD6 :1;
        unsigned TRISD7 :1;
    };
    struct {
        unsigned RD0 :1;
        unsigned RD1 :1;
        unsigned RD2 :1;
        unsigned RD3 :1;
        unsigned RD4 :1;
        unsigned RD5 :1;
        unsigned RD6 :1;
        unsigned RD7 :1;
    };
} TRISDbits_t;
extern volatile TRISDbits_t TRISDbits __attribute__((address(0xF95)));
# 2161 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned TRISD0 :1;
        unsigned TRISD1 :1;
        unsigned TRISD2 :1;
        unsigned TRISD3 :1;
        unsigned TRISD4 :1;
        unsigned TRISD5 :1;
        unsigned TRISD6 :1;
        unsigned TRISD7 :1;
    };
    struct {
        unsigned RD0 :1;
        unsigned RD1 :1;
        unsigned RD2 :1;
        unsigned RD3 :1;
        unsigned RD4 :1;
        unsigned RD5 :1;
        unsigned RD6 :1;
        unsigned RD7 :1;
    };
} DDRDbits_t;
extern volatile DDRDbits_t DDRDbits __attribute__((address(0xF95)));
# 2268 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TRISE __attribute__((address(0xF96)));

__asm("TRISE equ 0F96h");


extern volatile unsigned char DDRE __attribute__((address(0xF96)));

__asm("DDRE equ 0F96h");


typedef union {
    struct {
        unsigned TRISE0 :1;
        unsigned TRISE1 :1;
        unsigned TRISE2 :1;
        unsigned :1;
        unsigned PSPMODE :1;
        unsigned IBOV :1;
        unsigned OBF :1;
        unsigned IBF :1;
    };
    struct {
        unsigned RE0 :1;
        unsigned RE1 :1;
        unsigned RE2 :1;
        unsigned RE3 :1;
    };
} TRISEbits_t;
extern volatile TRISEbits_t TRISEbits __attribute__((address(0xF96)));
# 2354 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned TRISE0 :1;
        unsigned TRISE1 :1;
        unsigned TRISE2 :1;
        unsigned :1;
        unsigned PSPMODE :1;
        unsigned IBOV :1;
        unsigned OBF :1;
        unsigned IBF :1;
    };
    struct {
        unsigned RE0 :1;
        unsigned RE1 :1;
        unsigned RE2 :1;
        unsigned RE3 :1;
    };
} DDREbits_t;
extern volatile DDREbits_t DDREbits __attribute__((address(0xF96)));
# 2432 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char OSCTUNE __attribute__((address(0xF9B)));

__asm("OSCTUNE equ 0F9Bh");


typedef union {
    struct {
        unsigned TUN :5;
        unsigned :1;
        unsigned PLLEN :1;
        unsigned INTSRC :1;
    };
    struct {
        unsigned TUN0 :1;
        unsigned TUN1 :1;
        unsigned TUN2 :1;
        unsigned TUN3 :1;
        unsigned TUN4 :1;
    };
} OSCTUNEbits_t;
extern volatile OSCTUNEbits_t OSCTUNEbits __attribute__((address(0xF9B)));
# 2497 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PIE1 __attribute__((address(0xF9D)));

__asm("PIE1 equ 0F9Dh");


typedef union {
    struct {
        unsigned TMR1IE :1;
        unsigned TMR2IE :1;
        unsigned CCP1IE :1;
        unsigned SSPIE :1;
        unsigned TXIE :1;
        unsigned RCIE :1;
        unsigned ADIE :1;
        unsigned PSPIE :1;
    };
    struct {
        unsigned :4;
        unsigned TX1IE :1;
        unsigned RC1IE :1;
    };
} PIE1bits_t;
extern volatile PIE1bits_t PIE1bits __attribute__((address(0xF9D)));
# 2574 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PIR1 __attribute__((address(0xF9E)));

__asm("PIR1 equ 0F9Eh");


typedef union {
    struct {
        unsigned TMR1IF :1;
        unsigned TMR2IF :1;
        unsigned CCP1IF :1;
        unsigned SSPIF :1;
        unsigned TXIF :1;
        unsigned RCIF :1;
        unsigned ADIF :1;
        unsigned PSPIF :1;
    };
    struct {
        unsigned :4;
        unsigned TX1IF :1;
        unsigned RC1IF :1;
    };
} PIR1bits_t;
extern volatile PIR1bits_t PIR1bits __attribute__((address(0xF9E)));
# 2651 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char IPR1 __attribute__((address(0xF9F)));

__asm("IPR1 equ 0F9Fh");


typedef union {
    struct {
        unsigned TMR1IP :1;
        unsigned TMR2IP :1;
        unsigned CCP1IP :1;
        unsigned SSPIP :1;
        unsigned TXIP :1;
        unsigned RCIP :1;
        unsigned ADIP :1;
        unsigned PSPIP :1;
    };
    struct {
        unsigned :4;
        unsigned TX1IP :1;
        unsigned RC1IP :1;
    };
} IPR1bits_t;
extern volatile IPR1bits_t IPR1bits __attribute__((address(0xF9F)));
# 2728 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PIE2 __attribute__((address(0xFA0)));

__asm("PIE2 equ 0FA0h");


typedef union {
    struct {
        unsigned CCP2IE :1;
        unsigned TMR3IE :1;
        unsigned HLVDIE :1;
        unsigned BCLIE :1;
        unsigned EEIE :1;
        unsigned :1;
        unsigned CMIE :1;
        unsigned OSCFIE :1;
    };
    struct {
        unsigned :2;
        unsigned LVDIE :1;
    };
} PIE2bits_t;
extern volatile PIE2bits_t PIE2bits __attribute__((address(0xFA0)));
# 2794 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PIR2 __attribute__((address(0xFA1)));

__asm("PIR2 equ 0FA1h");


typedef union {
    struct {
        unsigned CCP2IF :1;
        unsigned TMR3IF :1;
        unsigned HLVDIF :1;
        unsigned BCLIF :1;
        unsigned EEIF :1;
        unsigned :1;
        unsigned CMIF :1;
        unsigned OSCFIF :1;
    };
    struct {
        unsigned :2;
        unsigned LVDIF :1;
    };
} PIR2bits_t;
extern volatile PIR2bits_t PIR2bits __attribute__((address(0xFA1)));
# 2860 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char IPR2 __attribute__((address(0xFA2)));

__asm("IPR2 equ 0FA2h");


typedef union {
    struct {
        unsigned CCP2IP :1;
        unsigned TMR3IP :1;
        unsigned HLVDIP :1;
        unsigned BCLIP :1;
        unsigned EEIP :1;
        unsigned :1;
        unsigned CMIP :1;
        unsigned OSCFIP :1;
    };
    struct {
        unsigned :2;
        unsigned LVDIP :1;
    };
} IPR2bits_t;
extern volatile IPR2bits_t IPR2bits __attribute__((address(0xFA2)));
# 2926 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char EECON1 __attribute__((address(0xFA6)));

__asm("EECON1 equ 0FA6h");


typedef union {
    struct {
        unsigned RD :1;
        unsigned WR :1;
        unsigned WREN :1;
        unsigned WRERR :1;
        unsigned FREE :1;
        unsigned :1;
        unsigned CFGS :1;
        unsigned EEPGD :1;
    };
    struct {
        unsigned :6;
        unsigned EEFS :1;
    };
} EECON1bits_t;
extern volatile EECON1bits_t EECON1bits __attribute__((address(0xFA6)));
# 2992 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char EECON2 __attribute__((address(0xFA7)));

__asm("EECON2 equ 0FA7h");




extern volatile unsigned char EEDATA __attribute__((address(0xFA8)));

__asm("EEDATA equ 0FA8h");




extern volatile unsigned char EEADR __attribute__((address(0xFA9)));

__asm("EEADR equ 0FA9h");




extern volatile unsigned char EEADRH __attribute__((address(0xFAA)));

__asm("EEADRH equ 0FAAh");




extern volatile unsigned char RCSTA __attribute__((address(0xFAB)));

__asm("RCSTA equ 0FABh");


extern volatile unsigned char RCSTA1 __attribute__((address(0xFAB)));

__asm("RCSTA1 equ 0FABh");


typedef union {
    struct {
        unsigned RX9D :1;
        unsigned OERR :1;
        unsigned FERR :1;
        unsigned ADDEN :1;
        unsigned CREN :1;
        unsigned SREN :1;
        unsigned RX9 :1;
        unsigned SPEN :1;
    };
    struct {
        unsigned :3;
        unsigned ADEN :1;
    };
    struct {
        unsigned :5;
        unsigned SRENA :1;
    };
    struct {
        unsigned :6;
        unsigned RC8_9 :1;
    };
    struct {
        unsigned :6;
        unsigned RC9 :1;
    };
    struct {
        unsigned RCD8 :1;
    };
} RCSTAbits_t;
extern volatile RCSTAbits_t RCSTAbits __attribute__((address(0xFAB)));
# 3129 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned RX9D :1;
        unsigned OERR :1;
        unsigned FERR :1;
        unsigned ADDEN :1;
        unsigned CREN :1;
        unsigned SREN :1;
        unsigned RX9 :1;
        unsigned SPEN :1;
    };
    struct {
        unsigned :3;
        unsigned ADEN :1;
    };
    struct {
        unsigned :5;
        unsigned SRENA :1;
    };
    struct {
        unsigned :6;
        unsigned RC8_9 :1;
    };
    struct {
        unsigned :6;
        unsigned RC9 :1;
    };
    struct {
        unsigned RCD8 :1;
    };
} RCSTA1bits_t;
extern volatile RCSTA1bits_t RCSTA1bits __attribute__((address(0xFAB)));
# 3230 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TXSTA __attribute__((address(0xFAC)));

__asm("TXSTA equ 0FACh");


extern volatile unsigned char TXSTA1 __attribute__((address(0xFAC)));

__asm("TXSTA1 equ 0FACh");


typedef union {
    struct {
        unsigned TX9D :1;
        unsigned TRMT :1;
        unsigned BRGH :1;
        unsigned SENDB :1;
        unsigned SYNC :1;
        unsigned TXEN :1;
        unsigned TX9 :1;
        unsigned CSRC :1;
    };
    struct {
        unsigned TX9D1 :1;
        unsigned TRMT1 :1;
        unsigned BRGH1 :1;
        unsigned SENDB1 :1;
        unsigned SYNC1 :1;
        unsigned TXEN1 :1;
        unsigned TX91 :1;
        unsigned CSRC1 :1;
    };
    struct {
        unsigned :6;
        unsigned TX8_9 :1;
    };
    struct {
        unsigned TXD8 :1;
    };
} TXSTAbits_t;
extern volatile TXSTAbits_t TXSTAbits __attribute__((address(0xFAC)));
# 3362 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned TX9D :1;
        unsigned TRMT :1;
        unsigned BRGH :1;
        unsigned SENDB :1;
        unsigned SYNC :1;
        unsigned TXEN :1;
        unsigned TX9 :1;
        unsigned CSRC :1;
    };
    struct {
        unsigned TX9D1 :1;
        unsigned TRMT1 :1;
        unsigned BRGH1 :1;
        unsigned SENDB1 :1;
        unsigned SYNC1 :1;
        unsigned TXEN1 :1;
        unsigned TX91 :1;
        unsigned CSRC1 :1;
    };
    struct {
        unsigned :6;
        unsigned TX8_9 :1;
    };
    struct {
        unsigned TXD8 :1;
    };
} TXSTA1bits_t;
extern volatile TXSTA1bits_t TXSTA1bits __attribute__((address(0xFAC)));
# 3486 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TXREG __attribute__((address(0xFAD)));

__asm("TXREG equ 0FADh");


extern volatile unsigned char TXREG1 __attribute__((address(0xFAD)));

__asm("TXREG1 equ 0FADh");




extern volatile unsigned char RCREG __attribute__((address(0xFAE)));

__asm("RCREG equ 0FAEh");


extern volatile unsigned char RCREG1 __attribute__((address(0xFAE)));

__asm("RCREG1 equ 0FAEh");




extern volatile unsigned char SPBRG __attribute__((address(0xFAF)));

__asm("SPBRG equ 0FAFh");


extern volatile unsigned char SPBRG1 __attribute__((address(0xFAF)));

__asm("SPBRG1 equ 0FAFh");




extern volatile unsigned char SPBRGH __attribute__((address(0xFB0)));

__asm("SPBRGH equ 0FB0h");




extern volatile unsigned char T3CON __attribute__((address(0xFB1)));

__asm("T3CON equ 0FB1h");


typedef union {
    struct {
        unsigned :2;
        unsigned NOT_T3SYNC :1;
    };
    struct {
        unsigned TMR3ON :1;
        unsigned TMR3CS :1;
        unsigned nT3SYNC :1;
        unsigned T3CCP1 :1;
        unsigned T3CKPS :2;
        unsigned T3CCP2 :1;
        unsigned RD16 :1;
    };
    struct {
        unsigned :2;
        unsigned T3SYNC :1;
        unsigned :1;
        unsigned T3CKPS0 :1;
        unsigned T3CKPS1 :1;
    };
    struct {
        unsigned :3;
        unsigned SOSCEN3 :1;
        unsigned :3;
        unsigned RD163 :1;
    };
    struct {
        unsigned :7;
        unsigned T3RD16 :1;
    };
} T3CONbits_t;
extern volatile T3CONbits_t T3CONbits __attribute__((address(0xFB1)));
# 3641 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short TMR3 __attribute__((address(0xFB2)));

__asm("TMR3 equ 0FB2h");




extern volatile unsigned char TMR3L __attribute__((address(0xFB2)));

__asm("TMR3L equ 0FB2h");




extern volatile unsigned char TMR3H __attribute__((address(0xFB3)));

__asm("TMR3H equ 0FB3h");




extern volatile unsigned char CMCON __attribute__((address(0xFB4)));

__asm("CMCON equ 0FB4h");


typedef union {
    struct {
        unsigned CM :3;
        unsigned CIS :1;
        unsigned C1INV :1;
        unsigned C2INV :1;
        unsigned C1OUT :1;
        unsigned C2OUT :1;
    };
    struct {
        unsigned CM0 :1;
        unsigned CM1 :1;
        unsigned CM2 :1;
    };
    struct {
        unsigned CMEN0 :1;
        unsigned CMEN1 :1;
        unsigned CMEN2 :1;
    };
} CMCONbits_t;
extern volatile CMCONbits_t CMCONbits __attribute__((address(0xFB4)));
# 3752 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char CVRCON __attribute__((address(0xFB5)));

__asm("CVRCON equ 0FB5h");


typedef union {
    struct {
        unsigned CVR :4;
        unsigned CVRSS :1;
        unsigned CVRR :1;
        unsigned CVROE :1;
        unsigned CVREN :1;
    };
    struct {
        unsigned CVR0 :1;
        unsigned CVR1 :1;
        unsigned CVR2 :1;
        unsigned CVR3 :1;
    };
    struct {
        unsigned :6;
        unsigned CVROEN :1;
    };
} CVRCONbits_t;
extern volatile CVRCONbits_t CVRCONbits __attribute__((address(0xFB5)));
# 3831 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char ECCP1AS __attribute__((address(0xFB6)));

__asm("ECCP1AS equ 0FB6h");


typedef union {
    struct {
        unsigned PSSBD :2;
        unsigned PSSAC :2;
        unsigned ECCPAS :3;
        unsigned ECCPASE :1;
    };
    struct {
        unsigned PSSBD0 :1;
        unsigned PSSBD1 :1;
        unsigned PSSAC0 :1;
        unsigned PSSAC1 :1;
        unsigned ECCPAS0 :1;
        unsigned ECCPAS1 :1;
        unsigned ECCPAS2 :1;
    };
} ECCP1ASbits_t;
extern volatile ECCP1ASbits_t ECCP1ASbits __attribute__((address(0xFB6)));
# 3913 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PWM1CON __attribute__((address(0xFB7)));

__asm("PWM1CON equ 0FB7h");


typedef union {
    struct {
        unsigned PDC :7;
        unsigned PRSEN :1;
    };
    struct {
        unsigned PDC0 :1;
        unsigned PDC1 :1;
        unsigned PDC2 :1;
        unsigned PDC3 :1;
        unsigned PDC4 :1;
        unsigned PDC5 :1;
        unsigned PDC6 :1;
    };
} PWM1CONbits_t;
extern volatile PWM1CONbits_t PWM1CONbits __attribute__((address(0xFB7)));
# 3983 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char BAUDCON __attribute__((address(0xFB8)));

__asm("BAUDCON equ 0FB8h");


extern volatile unsigned char BAUDCTL __attribute__((address(0xFB8)));

__asm("BAUDCTL equ 0FB8h");


typedef union {
    struct {
        unsigned ABDEN :1;
        unsigned WUE :1;
        unsigned :1;
        unsigned BRG16 :1;
        unsigned TXCKP :1;
        unsigned RXDTP :1;
        unsigned RCIDL :1;
        unsigned ABDOVF :1;
    };
    struct {
        unsigned :4;
        unsigned SCKP :1;
        unsigned RXCKP :1;
        unsigned RCMT :1;
    };
    struct {
        unsigned :1;
        unsigned W4E :1;
    };
} BAUDCONbits_t;
extern volatile BAUDCONbits_t BAUDCONbits __attribute__((address(0xFB8)));
# 4073 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned ABDEN :1;
        unsigned WUE :1;
        unsigned :1;
        unsigned BRG16 :1;
        unsigned TXCKP :1;
        unsigned RXDTP :1;
        unsigned RCIDL :1;
        unsigned ABDOVF :1;
    };
    struct {
        unsigned :4;
        unsigned SCKP :1;
        unsigned RXCKP :1;
        unsigned RCMT :1;
    };
    struct {
        unsigned :1;
        unsigned W4E :1;
    };
} BAUDCTLbits_t;
extern volatile BAUDCTLbits_t BAUDCTLbits __attribute__((address(0xFB8)));
# 4155 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char CCP2CON __attribute__((address(0xFBA)));

__asm("CCP2CON equ 0FBAh");


typedef union {
    struct {
        unsigned CCP2M :4;
        unsigned DC2B :2;
    };
    struct {
        unsigned CCP2M0 :1;
        unsigned CCP2M1 :1;
        unsigned CCP2M2 :1;
        unsigned CCP2M3 :1;
        unsigned CCP2Y :1;
        unsigned CCP2X :1;
    };
    struct {
        unsigned :4;
        unsigned DC2B0 :1;
        unsigned DC2B1 :1;
    };
} CCP2CONbits_t;
extern volatile CCP2CONbits_t CCP2CONbits __attribute__((address(0xFBA)));
# 4234 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short CCPR2 __attribute__((address(0xFBB)));

__asm("CCPR2 equ 0FBBh");




extern volatile unsigned char CCPR2L __attribute__((address(0xFBB)));

__asm("CCPR2L equ 0FBBh");




extern volatile unsigned char CCPR2H __attribute__((address(0xFBC)));

__asm("CCPR2H equ 0FBCh");




extern volatile unsigned char CCP1CON __attribute__((address(0xFBD)));

__asm("CCP1CON equ 0FBDh");


typedef union {
    struct {
        unsigned CCP1M :4;
        unsigned DC1B :2;
        unsigned P1M :2;
    };
    struct {
        unsigned CCP1M0 :1;
        unsigned CCP1M1 :1;
        unsigned CCP1M2 :1;
        unsigned CCP1M3 :1;
        unsigned CCP1Y :1;
        unsigned CCP1X :1;
        unsigned P1M0 :1;
        unsigned P1M1 :1;
    };
    struct {
        unsigned :4;
        unsigned DC1B0 :1;
        unsigned DC1B1 :1;
    };
} CCP1CONbits_t;
extern volatile CCP1CONbits_t CCP1CONbits __attribute__((address(0xFBD)));
# 4352 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short CCPR1 __attribute__((address(0xFBE)));

__asm("CCPR1 equ 0FBEh");




extern volatile unsigned char CCPR1L __attribute__((address(0xFBE)));

__asm("CCPR1L equ 0FBEh");




extern volatile unsigned char CCPR1H __attribute__((address(0xFBF)));

__asm("CCPR1H equ 0FBFh");




extern volatile unsigned char ADCON2 __attribute__((address(0xFC0)));

__asm("ADCON2 equ 0FC0h");


typedef union {
    struct {
        unsigned ADCS :3;
        unsigned ACQT :3;
        unsigned :1;
        unsigned ADFM :1;
    };
    struct {
        unsigned ADCS0 :1;
        unsigned ADCS1 :1;
        unsigned ADCS2 :1;
        unsigned ACQT0 :1;
        unsigned ACQT1 :1;
        unsigned ACQT2 :1;
    };
} ADCON2bits_t;
extern volatile ADCON2bits_t ADCON2bits __attribute__((address(0xFC0)));
# 4444 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char ADCON1 __attribute__((address(0xFC1)));

__asm("ADCON1 equ 0FC1h");


typedef union {
    struct {
        unsigned PCFG :4;
        unsigned VCFG :2;
    };
    struct {
        unsigned PCFG0 :1;
        unsigned PCFG1 :1;
        unsigned PCFG2 :1;
        unsigned PCFG3 :1;
        unsigned VCFG0 :1;
        unsigned VCFG1 :1;
    };
    struct {
        unsigned :3;
        unsigned CHSN3 :1;
        unsigned VCFG01 :1;
        unsigned VCFG11 :1;
    };
} ADCON1bits_t;
extern volatile ADCON1bits_t ADCON1bits __attribute__((address(0xFC1)));
# 4529 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char ADCON0 __attribute__((address(0xFC2)));

__asm("ADCON0 equ 0FC2h");


typedef union {
    struct {
        unsigned :1;
        unsigned GO_NOT_DONE :1;
    };
    struct {
        unsigned ADON :1;
        unsigned GO_nDONE :1;
        unsigned CHS :4;
    };
    struct {
        unsigned :1;
        unsigned GO :1;
        unsigned CHS0 :1;
        unsigned CHS1 :1;
        unsigned CHS2 :1;
        unsigned CHS3 :1;
    };
    struct {
        unsigned :1;
        unsigned DONE :1;
    };
    struct {
        unsigned :1;
        unsigned NOT_DONE :1;
    };
    struct {
        unsigned :1;
        unsigned nDONE :1;
    };
    struct {
        unsigned :1;
        unsigned GO_DONE :1;
    };
    struct {
        unsigned :1;
        unsigned GODONE :1;
    };
} ADCON0bits_t;
extern volatile ADCON0bits_t ADCON0bits __attribute__((address(0xFC2)));
# 4648 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short ADRES __attribute__((address(0xFC3)));

__asm("ADRES equ 0FC3h");




extern volatile unsigned char ADRESL __attribute__((address(0xFC3)));

__asm("ADRESL equ 0FC3h");




extern volatile unsigned char ADRESH __attribute__((address(0xFC4)));

__asm("ADRESH equ 0FC4h");




extern volatile unsigned char SSPCON2 __attribute__((address(0xFC5)));

__asm("SSPCON2 equ 0FC5h");


typedef union {
    struct {
        unsigned SEN :1;
        unsigned RSEN :1;
        unsigned PEN :1;
        unsigned RCEN :1;
        unsigned ACKEN :1;
        unsigned ACKDT :1;
        unsigned ACKSTAT :1;
        unsigned GCEN :1;
    };
} SSPCON2bits_t;
extern volatile SSPCON2bits_t SSPCON2bits __attribute__((address(0xFC5)));
# 4731 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char SSPCON1 __attribute__((address(0xFC6)));

__asm("SSPCON1 equ 0FC6h");


typedef union {
    struct {
        unsigned SSPM :4;
        unsigned CKP :1;
        unsigned SSPEN :1;
        unsigned SSPOV :1;
        unsigned WCOL :1;
    };
    struct {
        unsigned SSPM0 :1;
        unsigned SSPM1 :1;
        unsigned SSPM2 :1;
        unsigned SSPM3 :1;
    };
} SSPCON1bits_t;
extern volatile SSPCON1bits_t SSPCON1bits __attribute__((address(0xFC6)));
# 4801 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char SSPSTAT __attribute__((address(0xFC7)));

__asm("SSPSTAT equ 0FC7h");


typedef union {
    struct {
        unsigned :2;
        unsigned R_NOT_W :1;
    };
    struct {
        unsigned :5;
        unsigned D_NOT_A :1;
    };
    struct {
        unsigned BF :1;
        unsigned UA :1;
        unsigned R_nW :1;
        unsigned S :1;
        unsigned P :1;
        unsigned D_nA :1;
        unsigned CKE :1;
        unsigned SMP :1;
    };
    struct {
        unsigned :2;
        unsigned R :1;
        unsigned :2;
        unsigned D :1;
    };
    struct {
        unsigned :2;
        unsigned W :1;
        unsigned :2;
        unsigned A :1;
    };
    struct {
        unsigned :2;
        unsigned nW :1;
        unsigned :2;
        unsigned nA :1;
    };
    struct {
        unsigned :2;
        unsigned R_W :1;
        unsigned :2;
        unsigned D_A :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_WRITE :1;
    };
    struct {
        unsigned :5;
        unsigned NOT_ADDRESS :1;
    };
    struct {
        unsigned :2;
        unsigned nWRITE :1;
        unsigned :2;
        unsigned nADDRESS :1;
    };
    struct {
        unsigned :2;
        unsigned RW :1;
        unsigned START :1;
        unsigned STOP :1;
        unsigned DA :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_W :1;
        unsigned :2;
        unsigned NOT_A :1;
    };
} SSPSTATbits_t;
extern volatile SSPSTATbits_t SSPSTATbits __attribute__((address(0xFC7)));
# 5022 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char SSPADD __attribute__((address(0xFC8)));

__asm("SSPADD equ 0FC8h");




extern volatile unsigned char SSPBUF __attribute__((address(0xFC9)));

__asm("SSPBUF equ 0FC9h");




extern volatile unsigned char T2CON __attribute__((address(0xFCA)));

__asm("T2CON equ 0FCAh");


typedef union {
    struct {
        unsigned T2CKPS :2;
        unsigned TMR2ON :1;
        unsigned TOUTPS :4;
    };
    struct {
        unsigned T2CKPS0 :1;
        unsigned T2CKPS1 :1;
        unsigned :1;
        unsigned T2OUTPS0 :1;
        unsigned T2OUTPS1 :1;
        unsigned T2OUTPS2 :1;
        unsigned T2OUTPS3 :1;
    };
} T2CONbits_t;
extern volatile T2CONbits_t T2CONbits __attribute__((address(0xFCA)));
# 5107 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char PR2 __attribute__((address(0xFCB)));

__asm("PR2 equ 0FCBh");


extern volatile unsigned char MEMCON __attribute__((address(0xFCB)));

__asm("MEMCON equ 0FCBh");


typedef union {
    struct {
        unsigned :7;
        unsigned EBDIS :1;
    };
    struct {
        unsigned :4;
        unsigned WAIT0 :1;
    };
    struct {
        unsigned :5;
        unsigned WAIT1 :1;
    };
    struct {
        unsigned WM0 :1;
    };
    struct {
        unsigned :1;
        unsigned WM1 :1;
    };
} PR2bits_t;
extern volatile PR2bits_t PR2bits __attribute__((address(0xFCB)));
# 5166 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned :7;
        unsigned EBDIS :1;
    };
    struct {
        unsigned :4;
        unsigned WAIT0 :1;
    };
    struct {
        unsigned :5;
        unsigned WAIT1 :1;
    };
    struct {
        unsigned WM0 :1;
    };
    struct {
        unsigned :1;
        unsigned WM1 :1;
    };
} MEMCONbits_t;
extern volatile MEMCONbits_t MEMCONbits __attribute__((address(0xFCB)));
# 5217 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char TMR2 __attribute__((address(0xFCC)));

__asm("TMR2 equ 0FCCh");




extern volatile unsigned char T1CON __attribute__((address(0xFCD)));

__asm("T1CON equ 0FCDh");


typedef union {
    struct {
        unsigned :2;
        unsigned NOT_T1SYNC :1;
    };
    struct {
        unsigned TMR1ON :1;
        unsigned TMR1CS :1;
        unsigned nT1SYNC :1;
        unsigned T1OSCEN :1;
        unsigned T1CKPS :2;
        unsigned T1RUN :1;
        unsigned RD16 :1;
    };
    struct {
        unsigned :2;
        unsigned T1SYNC :1;
        unsigned :1;
        unsigned T1CKPS0 :1;
        unsigned T1CKPS1 :1;
    };
    struct {
        unsigned :3;
        unsigned SOSCEN :1;
        unsigned :3;
        unsigned T1RD16 :1;
    };
} T1CONbits_t;
extern volatile T1CONbits_t T1CONbits __attribute__((address(0xFCD)));
# 5327 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short TMR1 __attribute__((address(0xFCE)));

__asm("TMR1 equ 0FCEh");




extern volatile unsigned char TMR1L __attribute__((address(0xFCE)));

__asm("TMR1L equ 0FCEh");




extern volatile unsigned char TMR1H __attribute__((address(0xFCF)));

__asm("TMR1H equ 0FCFh");




extern volatile unsigned char RCON __attribute__((address(0xFD0)));

__asm("RCON equ 0FD0h");


typedef union {
    struct {
        unsigned NOT_BOR :1;
    };
    struct {
        unsigned :1;
        unsigned NOT_POR :1;
    };
    struct {
        unsigned :2;
        unsigned NOT_PD :1;
    };
    struct {
        unsigned :3;
        unsigned NOT_TO :1;
    };
    struct {
        unsigned :4;
        unsigned NOT_RI :1;
    };
    struct {
        unsigned nBOR :1;
        unsigned nPOR :1;
        unsigned nPD :1;
        unsigned nTO :1;
        unsigned nRI :1;
        unsigned :1;
        unsigned SBOREN :1;
        unsigned IPEN :1;
    };
    struct {
        unsigned BOR :1;
        unsigned POR :1;
        unsigned PD :1;
        unsigned TO :1;
        unsigned RI :1;
    };
} RCONbits_t;
extern volatile RCONbits_t RCONbits __attribute__((address(0xFD0)));
# 5481 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char WDTCON __attribute__((address(0xFD1)));

__asm("WDTCON equ 0FD1h");


typedef union {
    struct {
        unsigned SWDTEN :1;
    };
    struct {
        unsigned SWDTE :1;
    };
} WDTCONbits_t;
extern volatile WDTCONbits_t WDTCONbits __attribute__((address(0xFD1)));
# 5509 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char HLVDCON __attribute__((address(0xFD2)));

__asm("HLVDCON equ 0FD2h");


extern volatile unsigned char LVDCON __attribute__((address(0xFD2)));

__asm("LVDCON equ 0FD2h");


typedef union {
    struct {
        unsigned HLVDL :4;
        unsigned HLVDEN :1;
        unsigned IVRST :1;
        unsigned :1;
        unsigned VDIRMAG :1;
    };
    struct {
        unsigned HLVDL0 :1;
        unsigned HLVDL1 :1;
        unsigned HLVDL2 :1;
        unsigned HLVDL3 :1;
    };
    struct {
        unsigned LVDL0 :1;
        unsigned LVDL1 :1;
        unsigned LVDL2 :1;
        unsigned LVDL3 :1;
        unsigned LVDEN :1;
        unsigned IRVST :1;
    };
    struct {
        unsigned LVV0 :1;
        unsigned LVV1 :1;
        unsigned LVV2 :1;
        unsigned LVV3 :1;
        unsigned :1;
        unsigned BGST :1;
    };
} HLVDCONbits_t;
extern volatile HLVDCONbits_t HLVDCONbits __attribute__((address(0xFD2)));
# 5648 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
typedef union {
    struct {
        unsigned HLVDL :4;
        unsigned HLVDEN :1;
        unsigned IVRST :1;
        unsigned :1;
        unsigned VDIRMAG :1;
    };
    struct {
        unsigned HLVDL0 :1;
        unsigned HLVDL1 :1;
        unsigned HLVDL2 :1;
        unsigned HLVDL3 :1;
    };
    struct {
        unsigned LVDL0 :1;
        unsigned LVDL1 :1;
        unsigned LVDL2 :1;
        unsigned LVDL3 :1;
        unsigned LVDEN :1;
        unsigned IRVST :1;
    };
    struct {
        unsigned LVV0 :1;
        unsigned LVV1 :1;
        unsigned LVV2 :1;
        unsigned LVV3 :1;
        unsigned :1;
        unsigned BGST :1;
    };
} LVDCONbits_t;
extern volatile LVDCONbits_t LVDCONbits __attribute__((address(0xFD2)));
# 5779 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char OSCCON __attribute__((address(0xFD3)));

__asm("OSCCON equ 0FD3h");


typedef union {
    struct {
        unsigned SCS :2;
        unsigned IOFS :1;
        unsigned OSTS :1;
        unsigned IRCF :3;
        unsigned IDLEN :1;
    };
    struct {
        unsigned SCS0 :1;
        unsigned SCS1 :1;
        unsigned :2;
        unsigned IRCF0 :1;
        unsigned IRCF1 :1;
        unsigned IRCF2 :1;
    };
} OSCCONbits_t;
extern volatile OSCCONbits_t OSCCONbits __attribute__((address(0xFD3)));
# 5856 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char T0CON __attribute__((address(0xFD5)));

__asm("T0CON equ 0FD5h");


typedef union {
    struct {
        unsigned T0PS :3;
        unsigned PSA :1;
        unsigned T0SE :1;
        unsigned T0CS :1;
        unsigned T08BIT :1;
        unsigned TMR0ON :1;
    };
    struct {
        unsigned T0PS0 :1;
        unsigned T0PS1 :1;
        unsigned T0PS2 :1;
        unsigned :3;
        unsigned T016BIT :1;
    };
} T0CONbits_t;
extern volatile T0CONbits_t T0CONbits __attribute__((address(0xFD5)));
# 5933 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short TMR0 __attribute__((address(0xFD6)));

__asm("TMR0 equ 0FD6h");




extern volatile unsigned char TMR0L __attribute__((address(0xFD6)));

__asm("TMR0L equ 0FD6h");




extern volatile unsigned char TMR0H __attribute__((address(0xFD7)));

__asm("TMR0H equ 0FD7h");




extern volatile unsigned char STATUS __attribute__((address(0xFD8)));

__asm("STATUS equ 0FD8h");


typedef union {
    struct {
        unsigned C :1;
        unsigned DC :1;
        unsigned Z :1;
        unsigned OV :1;
        unsigned N :1;
    };
    struct {
        unsigned CARRY :1;
        unsigned :1;
        unsigned ZERO :1;
        unsigned OVERFLOW :1;
        unsigned NEGATIVE :1;
    };
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __attribute__((address(0xFD8)));
# 6025 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short FSR2 __attribute__((address(0xFD9)));

__asm("FSR2 equ 0FD9h");




extern volatile unsigned char FSR2L __attribute__((address(0xFD9)));

__asm("FSR2L equ 0FD9h");




extern volatile unsigned char FSR2H __attribute__((address(0xFDA)));

__asm("FSR2H equ 0FDAh");




extern volatile unsigned char PLUSW2 __attribute__((address(0xFDB)));

__asm("PLUSW2 equ 0FDBh");




extern volatile unsigned char PREINC2 __attribute__((address(0xFDC)));

__asm("PREINC2 equ 0FDCh");




extern volatile unsigned char POSTDEC2 __attribute__((address(0xFDD)));

__asm("POSTDEC2 equ 0FDDh");




extern volatile unsigned char POSTINC2 __attribute__((address(0xFDE)));

__asm("POSTINC2 equ 0FDEh");




extern volatile unsigned char INDF2 __attribute__((address(0xFDF)));

__asm("INDF2 equ 0FDFh");




extern volatile unsigned char BSR __attribute__((address(0xFE0)));

__asm("BSR equ 0FE0h");




extern volatile unsigned short FSR1 __attribute__((address(0xFE1)));

__asm("FSR1 equ 0FE1h");




extern volatile unsigned char FSR1L __attribute__((address(0xFE1)));

__asm("FSR1L equ 0FE1h");




extern volatile unsigned char FSR1H __attribute__((address(0xFE2)));

__asm("FSR1H equ 0FE2h");




extern volatile unsigned char PLUSW1 __attribute__((address(0xFE3)));

__asm("PLUSW1 equ 0FE3h");




extern volatile unsigned char PREINC1 __attribute__((address(0xFE4)));

__asm("PREINC1 equ 0FE4h");




extern volatile unsigned char POSTDEC1 __attribute__((address(0xFE5)));

__asm("POSTDEC1 equ 0FE5h");




extern volatile unsigned char POSTINC1 __attribute__((address(0xFE6)));

__asm("POSTINC1 equ 0FE6h");




extern volatile unsigned char INDF1 __attribute__((address(0xFE7)));

__asm("INDF1 equ 0FE7h");




extern volatile unsigned char WREG __attribute__((address(0xFE8)));

__asm("WREG equ 0FE8h");
# 6156 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short FSR0 __attribute__((address(0xFE9)));

__asm("FSR0 equ 0FE9h");




extern volatile unsigned char FSR0L __attribute__((address(0xFE9)));

__asm("FSR0L equ 0FE9h");




extern volatile unsigned char FSR0H __attribute__((address(0xFEA)));

__asm("FSR0H equ 0FEAh");




extern volatile unsigned char PLUSW0 __attribute__((address(0xFEB)));

__asm("PLUSW0 equ 0FEBh");




extern volatile unsigned char PREINC0 __attribute__((address(0xFEC)));

__asm("PREINC0 equ 0FECh");




extern volatile unsigned char POSTDEC0 __attribute__((address(0xFED)));

__asm("POSTDEC0 equ 0FEDh");




extern volatile unsigned char POSTINC0 __attribute__((address(0xFEE)));

__asm("POSTINC0 equ 0FEEh");




extern volatile unsigned char INDF0 __attribute__((address(0xFEF)));

__asm("INDF0 equ 0FEFh");




extern volatile unsigned char INTCON3 __attribute__((address(0xFF0)));

__asm("INTCON3 equ 0FF0h");


typedef union {
    struct {
        unsigned INT1IF :1;
        unsigned INT2IF :1;
        unsigned :1;
        unsigned INT1IE :1;
        unsigned INT2IE :1;
        unsigned :1;
        unsigned INT1IP :1;
        unsigned INT2IP :1;
    };
    struct {
        unsigned INT1F :1;
        unsigned INT2F :1;
        unsigned :1;
        unsigned INT1E :1;
        unsigned INT2E :1;
        unsigned :1;
        unsigned INT1P :1;
        unsigned INT2P :1;
    };
} INTCON3bits_t;
extern volatile INTCON3bits_t INTCON3bits __attribute__((address(0xFF0)));
# 6304 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char INTCON2 __attribute__((address(0xFF1)));

__asm("INTCON2 equ 0FF1h");


typedef union {
    struct {
        unsigned :7;
        unsigned NOT_RBPU :1;
    };
    struct {
        unsigned RBIP :1;
        unsigned :1;
        unsigned TMR0IP :1;
        unsigned :1;
        unsigned INTEDG2 :1;
        unsigned INTEDG1 :1;
        unsigned INTEDG0 :1;
        unsigned nRBPU :1;
    };
    struct {
        unsigned :7;
        unsigned RBPU :1;
    };
} INTCON2bits_t;
extern volatile INTCON2bits_t INTCON2bits __attribute__((address(0xFF1)));
# 6374 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned char INTCON __attribute__((address(0xFF2)));

__asm("INTCON equ 0FF2h");


typedef union {
    struct {
        unsigned RBIF :1;
        unsigned INT0IF :1;
        unsigned TMR0IF :1;
        unsigned RBIE :1;
        unsigned INT0IE :1;
        unsigned TMR0IE :1;
        unsigned PEIE_GIEL :1;
        unsigned GIE_GIEH :1;
    };
    struct {
        unsigned :1;
        unsigned INT0F :1;
        unsigned T0IF :1;
        unsigned :1;
        unsigned INT0E :1;
        unsigned T0IE :1;
        unsigned PEIE :1;
        unsigned GIE :1;
    };
    struct {
        unsigned :6;
        unsigned GIEL :1;
        unsigned GIEH :1;
    };
} INTCONbits_t;
extern volatile INTCONbits_t INTCONbits __attribute__((address(0xFF2)));
# 6491 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile unsigned short PROD __attribute__((address(0xFF3)));

__asm("PROD equ 0FF3h");




extern volatile unsigned char PRODL __attribute__((address(0xFF3)));

__asm("PRODL equ 0FF3h");




extern volatile unsigned char PRODH __attribute__((address(0xFF4)));

__asm("PRODH equ 0FF4h");




extern volatile unsigned char TABLAT __attribute__((address(0xFF5)));

__asm("TABLAT equ 0FF5h");





extern volatile __uint24 TBLPTR __attribute__((address(0xFF6)));


__asm("TBLPTR equ 0FF6h");




extern volatile unsigned char TBLPTRL __attribute__((address(0xFF6)));

__asm("TBLPTRL equ 0FF6h");




extern volatile unsigned char TBLPTRH __attribute__((address(0xFF7)));

__asm("TBLPTRH equ 0FF7h");




extern volatile unsigned char TBLPTRU __attribute__((address(0xFF8)));

__asm("TBLPTRU equ 0FF8h");





extern volatile __uint24 PCLAT __attribute__((address(0xFF9)));


__asm("PCLAT equ 0FF9h");



extern volatile __uint24 PC __attribute__((address(0xFF9)));


__asm("PC equ 0FF9h");




extern volatile unsigned char PCL __attribute__((address(0xFF9)));

__asm("PCL equ 0FF9h");




extern volatile unsigned char PCLATH __attribute__((address(0xFFA)));

__asm("PCLATH equ 0FFAh");




extern volatile unsigned char PCLATU __attribute__((address(0xFFB)));

__asm("PCLATU equ 0FFBh");




extern volatile unsigned char STKPTR __attribute__((address(0xFFC)));

__asm("STKPTR equ 0FFCh");


typedef union {
    struct {
        unsigned STKPTR :5;
        unsigned :1;
        unsigned STKUNF :1;
        unsigned STKFUL :1;
    };
    struct {
        unsigned STKPTR0 :1;
        unsigned STKPTR1 :1;
        unsigned STKPTR2 :1;
        unsigned STKPTR3 :1;
        unsigned STKPTR4 :1;
        unsigned :2;
        unsigned STKOVF :1;
    };
    struct {
        unsigned SP0 :1;
        unsigned SP1 :1;
        unsigned SP2 :1;
        unsigned SP3 :1;
        unsigned SP4 :1;
    };
} STKPTRbits_t;
extern volatile STKPTRbits_t STKPTRbits __attribute__((address(0xFFC)));
# 6691 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile __uint24 TOS __attribute__((address(0xFFD)));


__asm("TOS equ 0FFDh");




extern volatile unsigned char TOSL __attribute__((address(0xFFD)));

__asm("TOSL equ 0FFDh");




extern volatile unsigned char TOSH __attribute__((address(0xFFE)));

__asm("TOSH equ 0FFEh");




extern volatile unsigned char TOSU __attribute__((address(0xFFF)));

__asm("TOSU equ 0FFFh");
# 6726 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18f4620.h" 3
extern volatile __bit ABDEN __attribute__((address(0x7DC0)));


extern volatile __bit ABDOVF __attribute__((address(0x7DC7)));


extern volatile __bit ACKDT __attribute__((address(0x7E2D)));


extern volatile __bit ACKEN __attribute__((address(0x7E2C)));


extern volatile __bit ACKSTAT __attribute__((address(0x7E2E)));


extern volatile __bit ACQT0 __attribute__((address(0x7E03)));


extern volatile __bit ACQT1 __attribute__((address(0x7E04)));


extern volatile __bit ACQT2 __attribute__((address(0x7E05)));


extern volatile __bit ADCS0 __attribute__((address(0x7E00)));


extern volatile __bit ADCS1 __attribute__((address(0x7E01)));


extern volatile __bit ADCS2 __attribute__((address(0x7E02)));


extern volatile __bit ADDEN __attribute__((address(0x7D5B)));


extern volatile __bit ADEN __attribute__((address(0x7D5B)));


extern volatile __bit ADFM __attribute__((address(0x7E07)));


extern volatile __bit ADIE __attribute__((address(0x7CEE)));


extern volatile __bit ADIF __attribute__((address(0x7CF6)));


extern volatile __bit ADIP __attribute__((address(0x7CFE)));


extern volatile __bit ADON __attribute__((address(0x7E10)));


extern volatile __bit AN10 __attribute__((address(0x7C09)));


extern volatile __bit AN11 __attribute__((address(0x7C0C)));


extern volatile __bit AN12 __attribute__((address(0x7C08)));


extern volatile __bit AN4 __attribute__((address(0x7C05)));


extern volatile __bit AN5 __attribute__((address(0x7C20)));


extern volatile __bit AN6 __attribute__((address(0x7C21)));


extern volatile __bit AN7 __attribute__((address(0x7C22)));


extern volatile __bit AN8 __attribute__((address(0x7C0A)));


extern volatile __bit AN9 __attribute__((address(0x7C0B)));


extern volatile __bit BCLIE __attribute__((address(0x7D03)));


extern volatile __bit BCLIF __attribute__((address(0x7D0B)));


extern volatile __bit BCLIP __attribute__((address(0x7D13)));


extern volatile __bit BF __attribute__((address(0x7E38)));


extern volatile __bit BGST __attribute__((address(0x7E95)));


extern volatile __bit BOR __attribute__((address(0x7E80)));


extern volatile __bit BRG16 __attribute__((address(0x7DC3)));


extern volatile __bit BRGH __attribute__((address(0x7D62)));


extern volatile __bit BRGH1 __attribute__((address(0x7D62)));


extern volatile __bit C1INV __attribute__((address(0x7DA4)));


extern volatile __bit C1OUT __attribute__((address(0x7DA6)));


extern volatile __bit C2INV __attribute__((address(0x7DA5)));


extern volatile __bit C2OUT __attribute__((address(0x7DA7)));


extern volatile __bit CARRY __attribute__((address(0x7EC0)));


extern volatile __bit CCP1 __attribute__((address(0x7C12)));


extern volatile __bit CCP10 __attribute__((address(0x7C22)));


extern volatile __bit CCP1IE __attribute__((address(0x7CEA)));


extern volatile __bit CCP1IF __attribute__((address(0x7CF2)));


extern volatile __bit CCP1IP __attribute__((address(0x7CFA)));


extern volatile __bit CCP1M0 __attribute__((address(0x7DE8)));


extern volatile __bit CCP1M1 __attribute__((address(0x7DE9)));


extern volatile __bit CCP1M2 __attribute__((address(0x7DEA)));


extern volatile __bit CCP1M3 __attribute__((address(0x7DEB)));


extern volatile __bit CCP1X __attribute__((address(0x7DED)));


extern volatile __bit CCP1Y __attribute__((address(0x7DEC)));


extern volatile __bit CCP2IE __attribute__((address(0x7D00)));


extern volatile __bit CCP2IF __attribute__((address(0x7D08)));


extern volatile __bit CCP2IP __attribute__((address(0x7D10)));


extern volatile __bit CCP2M0 __attribute__((address(0x7DD0)));


extern volatile __bit CCP2M1 __attribute__((address(0x7DD1)));


extern volatile __bit CCP2M2 __attribute__((address(0x7DD2)));


extern volatile __bit CCP2M3 __attribute__((address(0x7DD3)));


extern volatile __bit CCP2X __attribute__((address(0x7DD5)));


extern volatile __bit CCP2Y __attribute__((address(0x7DD4)));


extern volatile __bit CCP2_PA2 __attribute__((address(0x7C0B)));


extern volatile __bit CCP9E __attribute__((address(0x7C23)));


extern volatile __bit CFGS __attribute__((address(0x7D36)));


extern volatile __bit CHS0 __attribute__((address(0x7E12)));


extern volatile __bit CHS1 __attribute__((address(0x7E13)));


extern volatile __bit CHS2 __attribute__((address(0x7E14)));


extern volatile __bit CHS3 __attribute__((address(0x7E15)));


extern volatile __bit CHSN3 __attribute__((address(0x7E0B)));


extern volatile __bit CIS __attribute__((address(0x7DA3)));


extern volatile __bit CK __attribute__((address(0x7C16)));


extern volatile __bit CKE __attribute__((address(0x7E3E)));


extern volatile __bit CKP __attribute__((address(0x7E34)));


extern volatile __bit CM0 __attribute__((address(0x7DA0)));


extern volatile __bit CM1 __attribute__((address(0x7DA1)));


extern volatile __bit CM2 __attribute__((address(0x7DA2)));


extern volatile __bit CMEN0 __attribute__((address(0x7DA0)));


extern volatile __bit CMEN1 __attribute__((address(0x7DA1)));


extern volatile __bit CMEN2 __attribute__((address(0x7DA2)));


extern volatile __bit CMIE __attribute__((address(0x7D06)));


extern volatile __bit CMIF __attribute__((address(0x7D0E)));


extern volatile __bit CMIP __attribute__((address(0x7D16)));


extern volatile __bit CREN __attribute__((address(0x7D5C)));


extern volatile __bit CS __attribute__((address(0x7C22)));


extern volatile __bit CSRC __attribute__((address(0x7D67)));


extern volatile __bit CSRC1 __attribute__((address(0x7D67)));


extern volatile __bit CVR0 __attribute__((address(0x7DA8)));


extern volatile __bit CVR1 __attribute__((address(0x7DA9)));


extern volatile __bit CVR2 __attribute__((address(0x7DAA)));


extern volatile __bit CVR3 __attribute__((address(0x7DAB)));


extern volatile __bit CVREN __attribute__((address(0x7DAF)));


extern volatile __bit CVROE __attribute__((address(0x7DAE)));


extern volatile __bit CVROEN __attribute__((address(0x7DAE)));


extern volatile __bit CVRR __attribute__((address(0x7DAD)));


extern volatile __bit CVRSS __attribute__((address(0x7DAC)));


extern volatile __bit DA __attribute__((address(0x7E3D)));


extern volatile __bit DC __attribute__((address(0x7EC1)));


extern volatile __bit DC1B0 __attribute__((address(0x7DEC)));


extern volatile __bit DC1B1 __attribute__((address(0x7DED)));


extern volatile __bit DC2B0 __attribute__((address(0x7DD4)));


extern volatile __bit DC2B1 __attribute__((address(0x7DD5)));


extern volatile __bit DONE __attribute__((address(0x7E11)));


extern volatile __bit DT __attribute__((address(0x7C17)));


extern volatile __bit D_A __attribute__((address(0x7E3D)));


extern volatile __bit D_NOT_A __attribute__((address(0x7E3D)));


extern volatile __bit D_nA __attribute__((address(0x7E3D)));


extern volatile __bit EBDIS __attribute__((address(0x7E5F)));


extern volatile __bit ECCPAS0 __attribute__((address(0x7DB4)));


extern volatile __bit ECCPAS1 __attribute__((address(0x7DB5)));


extern volatile __bit ECCPAS2 __attribute__((address(0x7DB6)));


extern volatile __bit ECCPASE __attribute__((address(0x7DB7)));


extern volatile __bit EEFS __attribute__((address(0x7D36)));


extern volatile __bit EEIE __attribute__((address(0x7D04)));


extern volatile __bit EEIF __attribute__((address(0x7D0C)));


extern volatile __bit EEIP __attribute__((address(0x7D14)));


extern volatile __bit EEPGD __attribute__((address(0x7D37)));


extern volatile __bit FERR __attribute__((address(0x7D5A)));


extern volatile __bit FREE __attribute__((address(0x7D34)));


extern volatile __bit GCEN __attribute__((address(0x7E2F)));


extern volatile __bit GIE __attribute__((address(0x7F97)));


extern volatile __bit GIEH __attribute__((address(0x7F97)));


extern volatile __bit GIEL __attribute__((address(0x7F96)));


extern volatile __bit GIE_GIEH __attribute__((address(0x7F97)));


extern volatile __bit GO __attribute__((address(0x7E11)));


extern volatile __bit GODONE __attribute__((address(0x7E11)));


extern volatile __bit GO_DONE __attribute__((address(0x7E11)));


extern volatile __bit GO_NOT_DONE __attribute__((address(0x7E11)));


extern volatile __bit GO_nDONE __attribute__((address(0x7E11)));


extern volatile __bit HLVDEN __attribute__((address(0x7E94)));


extern volatile __bit HLVDIE __attribute__((address(0x7D02)));


extern volatile __bit HLVDIF __attribute__((address(0x7D0A)));


extern volatile __bit HLVDIN __attribute__((address(0x7C05)));


extern volatile __bit HLVDIP __attribute__((address(0x7D12)));


extern volatile __bit HLVDL0 __attribute__((address(0x7E90)));


extern volatile __bit HLVDL1 __attribute__((address(0x7E91)));


extern volatile __bit HLVDL2 __attribute__((address(0x7E92)));


extern volatile __bit HLVDL3 __attribute__((address(0x7E93)));


extern volatile __bit IBF __attribute__((address(0x7CB7)));


extern volatile __bit IBOV __attribute__((address(0x7CB5)));


extern volatile __bit IDLEN __attribute__((address(0x7E9F)));


extern volatile __bit INT0 __attribute__((address(0x7C08)));


extern volatile __bit INT0E __attribute__((address(0x7F94)));


extern volatile __bit INT0F __attribute__((address(0x7F91)));


extern volatile __bit INT0IE __attribute__((address(0x7F94)));


extern volatile __bit INT0IF __attribute__((address(0x7F91)));


extern volatile __bit INT1 __attribute__((address(0x7C09)));


extern volatile __bit INT1E __attribute__((address(0x7F83)));


extern volatile __bit INT1F __attribute__((address(0x7F80)));


extern volatile __bit INT1IE __attribute__((address(0x7F83)));


extern volatile __bit INT1IF __attribute__((address(0x7F80)));


extern volatile __bit INT1IP __attribute__((address(0x7F86)));


extern volatile __bit INT1P __attribute__((address(0x7F86)));


extern volatile __bit INT2 __attribute__((address(0x7C0A)));


extern volatile __bit INT2E __attribute__((address(0x7F84)));


extern volatile __bit INT2F __attribute__((address(0x7F81)));


extern volatile __bit INT2IE __attribute__((address(0x7F84)));


extern volatile __bit INT2IF __attribute__((address(0x7F81)));


extern volatile __bit INT2IP __attribute__((address(0x7F87)));


extern volatile __bit INT2P __attribute__((address(0x7F87)));


extern volatile __bit INTEDG0 __attribute__((address(0x7F8E)));


extern volatile __bit INTEDG1 __attribute__((address(0x7F8D)));


extern volatile __bit INTEDG2 __attribute__((address(0x7F8C)));


extern volatile __bit INTSRC __attribute__((address(0x7CDF)));


extern volatile __bit IOFS __attribute__((address(0x7E9A)));


extern volatile __bit IPEN __attribute__((address(0x7E87)));


extern volatile __bit IRCF0 __attribute__((address(0x7E9C)));


extern volatile __bit IRCF1 __attribute__((address(0x7E9D)));


extern volatile __bit IRCF2 __attribute__((address(0x7E9E)));


extern volatile __bit IRVST __attribute__((address(0x7E95)));


extern volatile __bit IVRST __attribute__((address(0x7E95)));


extern volatile __bit KBI0 __attribute__((address(0x7C0C)));


extern volatile __bit KBI1 __attribute__((address(0x7C0D)));


extern volatile __bit KBI2 __attribute__((address(0x7C0E)));


extern volatile __bit KBI3 __attribute__((address(0x7C0F)));


extern volatile __bit LA0 __attribute__((address(0x7C48)));


extern volatile __bit LA1 __attribute__((address(0x7C49)));


extern volatile __bit LA2 __attribute__((address(0x7C4A)));


extern volatile __bit LA3 __attribute__((address(0x7C4B)));


extern volatile __bit LA4 __attribute__((address(0x7C4C)));


extern volatile __bit LA5 __attribute__((address(0x7C4D)));


extern volatile __bit LA6 __attribute__((address(0x7C4E)));


extern volatile __bit LA7 __attribute__((address(0x7C4F)));


extern volatile __bit LATA0 __attribute__((address(0x7C48)));


extern volatile __bit LATA1 __attribute__((address(0x7C49)));


extern volatile __bit LATA2 __attribute__((address(0x7C4A)));


extern volatile __bit LATA3 __attribute__((address(0x7C4B)));


extern volatile __bit LATA4 __attribute__((address(0x7C4C)));


extern volatile __bit LATA5 __attribute__((address(0x7C4D)));


extern volatile __bit LATA6 __attribute__((address(0x7C4E)));


extern volatile __bit LATA7 __attribute__((address(0x7C4F)));


extern volatile __bit LATB0 __attribute__((address(0x7C50)));


extern volatile __bit LATB1 __attribute__((address(0x7C51)));


extern volatile __bit LATB2 __attribute__((address(0x7C52)));


extern volatile __bit LATB3 __attribute__((address(0x7C53)));


extern volatile __bit LATB4 __attribute__((address(0x7C54)));


extern volatile __bit LATB5 __attribute__((address(0x7C55)));


extern volatile __bit LATB6 __attribute__((address(0x7C56)));


extern volatile __bit LATB7 __attribute__((address(0x7C57)));


extern volatile __bit LATC0 __attribute__((address(0x7C58)));


extern volatile __bit LATC1 __attribute__((address(0x7C59)));


extern volatile __bit LATC2 __attribute__((address(0x7C5A)));


extern volatile __bit LATC3 __attribute__((address(0x7C5B)));


extern volatile __bit LATC4 __attribute__((address(0x7C5C)));


extern volatile __bit LATC5 __attribute__((address(0x7C5D)));


extern volatile __bit LATC6 __attribute__((address(0x7C5E)));


extern volatile __bit LATC7 __attribute__((address(0x7C5F)));


extern volatile __bit LATD0 __attribute__((address(0x7C60)));


extern volatile __bit LATD1 __attribute__((address(0x7C61)));


extern volatile __bit LATD2 __attribute__((address(0x7C62)));


extern volatile __bit LATD3 __attribute__((address(0x7C63)));


extern volatile __bit LATD4 __attribute__((address(0x7C64)));


extern volatile __bit LATD5 __attribute__((address(0x7C65)));


extern volatile __bit LATD6 __attribute__((address(0x7C66)));


extern volatile __bit LATD7 __attribute__((address(0x7C67)));


extern volatile __bit LATE0 __attribute__((address(0x7C68)));


extern volatile __bit LATE1 __attribute__((address(0x7C69)));


extern volatile __bit LATE2 __attribute__((address(0x7C6A)));


extern volatile __bit LB0 __attribute__((address(0x7C50)));


extern volatile __bit LB1 __attribute__((address(0x7C51)));


extern volatile __bit LB2 __attribute__((address(0x7C52)));


extern volatile __bit LB3 __attribute__((address(0x7C53)));


extern volatile __bit LB4 __attribute__((address(0x7C54)));


extern volatile __bit LB5 __attribute__((address(0x7C55)));


extern volatile __bit LB6 __attribute__((address(0x7C56)));


extern volatile __bit LB7 __attribute__((address(0x7C57)));


extern volatile __bit LC0 __attribute__((address(0x7C58)));


extern volatile __bit LC1 __attribute__((address(0x7C59)));


extern volatile __bit LC2 __attribute__((address(0x7C5A)));


extern volatile __bit LC3 __attribute__((address(0x7C5B)));


extern volatile __bit LC4 __attribute__((address(0x7C5C)));


extern volatile __bit LC5 __attribute__((address(0x7C5D)));


extern volatile __bit LC6 __attribute__((address(0x7C5E)));


extern volatile __bit LC7 __attribute__((address(0x7C5F)));


extern volatile __bit LD0 __attribute__((address(0x7C60)));


extern volatile __bit LD1 __attribute__((address(0x7C61)));


extern volatile __bit LD2 __attribute__((address(0x7C62)));


extern volatile __bit LD3 __attribute__((address(0x7C63)));


extern volatile __bit LD4 __attribute__((address(0x7C64)));


extern volatile __bit LD5 __attribute__((address(0x7C65)));


extern volatile __bit LD6 __attribute__((address(0x7C66)));


extern volatile __bit LD7 __attribute__((address(0x7C67)));


extern volatile __bit LE0 __attribute__((address(0x7C68)));


extern volatile __bit LE1 __attribute__((address(0x7C69)));


extern volatile __bit LE2 __attribute__((address(0x7C6A)));


extern volatile __bit LVDEN __attribute__((address(0x7E94)));


extern volatile __bit LVDIE __attribute__((address(0x7D02)));


extern volatile __bit LVDIF __attribute__((address(0x7D0A)));


extern volatile __bit LVDIN __attribute__((address(0x7C05)));


extern volatile __bit LVDIP __attribute__((address(0x7D12)));


extern volatile __bit LVDL0 __attribute__((address(0x7E90)));


extern volatile __bit LVDL1 __attribute__((address(0x7E91)));


extern volatile __bit LVDL2 __attribute__((address(0x7E92)));


extern volatile __bit LVDL3 __attribute__((address(0x7E93)));


extern volatile __bit LVV0 __attribute__((address(0x7E90)));


extern volatile __bit LVV1 __attribute__((address(0x7E91)));


extern volatile __bit LVV2 __attribute__((address(0x7E92)));


extern volatile __bit LVV3 __attribute__((address(0x7E93)));


extern volatile __bit MCLR __attribute__((address(0x7C23)));


extern volatile __bit NEGATIVE __attribute__((address(0x7EC4)));


extern volatile __bit NOT_A __attribute__((address(0x7E3D)));


extern volatile __bit NOT_ADDRESS __attribute__((address(0x7E3D)));


extern volatile __bit NOT_BOR __attribute__((address(0x7E80)));


extern volatile __bit NOT_CS __attribute__((address(0x7C22)));


extern volatile __bit NOT_DONE __attribute__((address(0x7E11)));


extern volatile __bit NOT_MCLR __attribute__((address(0x7C23)));


extern volatile __bit NOT_PD __attribute__((address(0x7E82)));


extern volatile __bit NOT_POR __attribute__((address(0x7E81)));


extern volatile __bit NOT_RBPU __attribute__((address(0x7F8F)));


extern volatile __bit NOT_RD __attribute__((address(0x7C20)));


extern volatile __bit NOT_RI __attribute__((address(0x7E84)));


extern volatile __bit NOT_SS __attribute__((address(0x7C05)));


extern volatile __bit NOT_T1SYNC __attribute__((address(0x7E6A)));


extern volatile __bit NOT_T3SYNC __attribute__((address(0x7D8A)));


extern volatile __bit NOT_TO __attribute__((address(0x7E83)));


extern volatile __bit NOT_W __attribute__((address(0x7E3A)));


extern volatile __bit NOT_WR __attribute__((address(0x7C21)));


extern volatile __bit NOT_WRITE __attribute__((address(0x7E3A)));


extern volatile __bit OBF __attribute__((address(0x7CB6)));


extern volatile __bit OERR __attribute__((address(0x7D59)));


extern volatile __bit OSCFIE __attribute__((address(0x7D07)));


extern volatile __bit OSCFIF __attribute__((address(0x7D0F)));


extern volatile __bit OSCFIP __attribute__((address(0x7D17)));


extern volatile __bit OSTS __attribute__((address(0x7E9B)));


extern volatile __bit OV __attribute__((address(0x7EC3)));


extern volatile __bit OVERFLOW __attribute__((address(0x7EC3)));


extern volatile __bit P1B __attribute__((address(0x7C1D)));


extern volatile __bit P1C __attribute__((address(0x7C1E)));


extern volatile __bit P1D __attribute__((address(0x7C1F)));


extern volatile __bit P1M0 __attribute__((address(0x7DEE)));


extern volatile __bit P1M1 __attribute__((address(0x7DEF)));


extern volatile __bit PA1 __attribute__((address(0x7C12)));


extern volatile __bit PA2 __attribute__((address(0x7C11)));


extern volatile __bit PB2 __attribute__((address(0x7C22)));


extern volatile __bit PC2 __attribute__((address(0x7C21)));


extern volatile __bit PC3E __attribute__((address(0x7C23)));


extern volatile __bit PCFG0 __attribute__((address(0x7E08)));


extern volatile __bit PCFG1 __attribute__((address(0x7E09)));


extern volatile __bit PCFG2 __attribute__((address(0x7E0A)));


extern volatile __bit PCFG3 __attribute__((address(0x7E0B)));


extern volatile __bit PD __attribute__((address(0x7E82)));


extern volatile __bit PD2 __attribute__((address(0x7C20)));


extern volatile __bit PDC0 __attribute__((address(0x7DB8)));


extern volatile __bit PDC1 __attribute__((address(0x7DB9)));


extern volatile __bit PDC2 __attribute__((address(0x7DBA)));


extern volatile __bit PDC3 __attribute__((address(0x7DBB)));


extern volatile __bit PDC4 __attribute__((address(0x7DBC)));


extern volatile __bit PDC5 __attribute__((address(0x7DBD)));


extern volatile __bit PDC6 __attribute__((address(0x7DBE)));


extern volatile __bit PEIE __attribute__((address(0x7F96)));


extern volatile __bit PEIE_GIEL __attribute__((address(0x7F96)));


extern volatile __bit PEN __attribute__((address(0x7E2A)));


extern volatile __bit PGC __attribute__((address(0x7C0E)));


extern volatile __bit PGD __attribute__((address(0x7C0F)));


extern volatile __bit PGM __attribute__((address(0x7C0D)));


extern volatile __bit PLLEN __attribute__((address(0x7CDE)));


extern volatile __bit POR __attribute__((address(0x7E81)));


extern volatile __bit PRSEN __attribute__((address(0x7DBF)));


extern volatile __bit PSA __attribute__((address(0x7EAB)));


extern volatile __bit PSP0 __attribute__((address(0x7C18)));


extern volatile __bit PSP1 __attribute__((address(0x7C19)));


extern volatile __bit PSP2 __attribute__((address(0x7C1A)));


extern volatile __bit PSP3 __attribute__((address(0x7C1B)));


extern volatile __bit PSP4 __attribute__((address(0x7C1C)));


extern volatile __bit PSP5 __attribute__((address(0x7C1D)));


extern volatile __bit PSP6 __attribute__((address(0x7C1E)));


extern volatile __bit PSP7 __attribute__((address(0x7C1F)));


extern volatile __bit PSPIE __attribute__((address(0x7CEF)));


extern volatile __bit PSPIF __attribute__((address(0x7CF7)));


extern volatile __bit PSPIP __attribute__((address(0x7CFF)));


extern volatile __bit PSPMODE __attribute__((address(0x7CB4)));


extern volatile __bit PSSAC0 __attribute__((address(0x7DB2)));


extern volatile __bit PSSAC1 __attribute__((address(0x7DB3)));


extern volatile __bit PSSBD0 __attribute__((address(0x7DB0)));


extern volatile __bit PSSBD1 __attribute__((address(0x7DB1)));


extern volatile __bit __attribute__((__deprecated__)) RA0 __attribute__((address(0x7C00)));


extern volatile __bit __attribute__((__deprecated__)) RA1 __attribute__((address(0x7C01)));


extern volatile __bit __attribute__((__deprecated__)) RA2 __attribute__((address(0x7C02)));


extern volatile __bit __attribute__((__deprecated__)) RA3 __attribute__((address(0x7C03)));


extern volatile __bit __attribute__((__deprecated__)) RA4 __attribute__((address(0x7C04)));


extern volatile __bit __attribute__((__deprecated__)) RA5 __attribute__((address(0x7C05)));


extern volatile __bit __attribute__((__deprecated__)) RA6 __attribute__((address(0x7C06)));


extern volatile __bit __attribute__((__deprecated__)) RA7 __attribute__((address(0x7C07)));


extern volatile __bit __attribute__((__deprecated__)) RB0 __attribute__((address(0x7C08)));


extern volatile __bit __attribute__((__deprecated__)) RB1 __attribute__((address(0x7C09)));


extern volatile __bit __attribute__((__deprecated__)) RB2 __attribute__((address(0x7C0A)));


extern volatile __bit __attribute__((__deprecated__)) RB3 __attribute__((address(0x7C0B)));


extern volatile __bit __attribute__((__deprecated__)) RB4 __attribute__((address(0x7C0C)));


extern volatile __bit __attribute__((__deprecated__)) RB5 __attribute__((address(0x7C0D)));


extern volatile __bit __attribute__((__deprecated__)) RB6 __attribute__((address(0x7C0E)));


extern volatile __bit __attribute__((__deprecated__)) RB7 __attribute__((address(0x7C0F)));


extern volatile __bit RBIE __attribute__((address(0x7F93)));


extern volatile __bit RBIF __attribute__((address(0x7F90)));


extern volatile __bit RBIP __attribute__((address(0x7F88)));


extern volatile __bit RBPU __attribute__((address(0x7F8F)));


extern volatile __bit __attribute__((__deprecated__)) RC0 __attribute__((address(0x7C10)));


extern volatile __bit __attribute__((__deprecated__)) RC1 __attribute__((address(0x7C11)));


extern volatile __bit RC1IE __attribute__((address(0x7CED)));


extern volatile __bit RC1IF __attribute__((address(0x7CF5)));


extern volatile __bit RC1IP __attribute__((address(0x7CFD)));


extern volatile __bit __attribute__((__deprecated__)) RC2 __attribute__((address(0x7C12)));


extern volatile __bit __attribute__((__deprecated__)) RC3 __attribute__((address(0x7C13)));


extern volatile __bit __attribute__((__deprecated__)) RC4 __attribute__((address(0x7C14)));


extern volatile __bit __attribute__((__deprecated__)) RC5 __attribute__((address(0x7C15)));


extern volatile __bit __attribute__((__deprecated__)) RC6 __attribute__((address(0x7C16)));


extern volatile __bit __attribute__((__deprecated__)) RC7 __attribute__((address(0x7C17)));


extern volatile __bit RC8_9 __attribute__((address(0x7D5E)));


extern volatile __bit RC9 __attribute__((address(0x7D5E)));


extern volatile __bit RCD8 __attribute__((address(0x7D58)));


extern volatile __bit RCEN __attribute__((address(0x7E2B)));


extern volatile __bit RCIDL __attribute__((address(0x7DC6)));


extern volatile __bit RCIE __attribute__((address(0x7CED)));


extern volatile __bit RCIF __attribute__((address(0x7CF5)));


extern volatile __bit RCIP __attribute__((address(0x7CFD)));


extern volatile __bit RCMT __attribute__((address(0x7DC6)));


extern volatile __bit __attribute__((__deprecated__)) RD __attribute__((address(0x7D30)));


extern volatile __bit __attribute__((__deprecated__)) RD0 __attribute__((address(0x7C18)));


extern volatile __bit __attribute__((__deprecated__)) RD1 __attribute__((address(0x7C19)));


extern volatile __bit RD163 __attribute__((address(0x7D8F)));


extern volatile __bit __attribute__((__deprecated__)) RD2 __attribute__((address(0x7C1A)));


extern volatile __bit __attribute__((__deprecated__)) RD3 __attribute__((address(0x7C1B)));


extern volatile __bit __attribute__((__deprecated__)) RD4 __attribute__((address(0x7C1C)));


extern volatile __bit __attribute__((__deprecated__)) RD5 __attribute__((address(0x7C1D)));


extern volatile __bit __attribute__((__deprecated__)) RD6 __attribute__((address(0x7C1E)));


extern volatile __bit __attribute__((__deprecated__)) RD7 __attribute__((address(0x7C1F)));


extern volatile __bit RDE __attribute__((address(0x7C20)));


extern volatile __bit __attribute__((__deprecated__)) RE0 __attribute__((address(0x7C20)));


extern volatile __bit __attribute__((__deprecated__)) RE1 __attribute__((address(0x7C21)));


extern volatile __bit __attribute__((__deprecated__)) RE2 __attribute__((address(0x7C22)));


extern volatile __bit __attribute__((__deprecated__)) RE3 __attribute__((address(0x7C23)));


extern volatile __bit RI __attribute__((address(0x7E84)));


extern volatile __bit RJPU __attribute__((address(0x7C07)));


extern volatile __bit RSEN __attribute__((address(0x7E29)));


extern volatile __bit RW __attribute__((address(0x7E3A)));


extern volatile __bit RX __attribute__((address(0x7C17)));


extern volatile __bit RX9 __attribute__((address(0x7D5E)));


extern volatile __bit RX9D __attribute__((address(0x7D58)));


extern volatile __bit RXCKP __attribute__((address(0x7DC5)));


extern volatile __bit RXDTP __attribute__((address(0x7DC5)));


extern volatile __bit R_NOT_W __attribute__((address(0x7E3A)));


extern volatile __bit R_W __attribute__((address(0x7E3A)));


extern volatile __bit R_nW __attribute__((address(0x7E3A)));


extern volatile __bit SBOREN __attribute__((address(0x7E86)));


extern volatile __bit SCK __attribute__((address(0x7C13)));


extern volatile __bit SCKP __attribute__((address(0x7DC4)));


extern volatile __bit SCL __attribute__((address(0x7C13)));


extern volatile __bit SCS0 __attribute__((address(0x7E98)));


extern volatile __bit SCS1 __attribute__((address(0x7E99)));


extern volatile __bit SDA __attribute__((address(0x7C14)));


extern volatile __bit SDI __attribute__((address(0x7C14)));


extern volatile __bit SDO __attribute__((address(0x7C15)));


extern volatile __bit SEN __attribute__((address(0x7E28)));


extern volatile __bit SENDB __attribute__((address(0x7D63)));


extern volatile __bit SENDB1 __attribute__((address(0x7D63)));


extern volatile __bit SMP __attribute__((address(0x7E3F)));


extern volatile __bit SOSCEN __attribute__((address(0x7E6B)));


extern volatile __bit SOSCEN3 __attribute__((address(0x7D8B)));


extern volatile __bit SP0 __attribute__((address(0x7FE0)));


extern volatile __bit SP1 __attribute__((address(0x7FE1)));


extern volatile __bit SP2 __attribute__((address(0x7FE2)));


extern volatile __bit SP3 __attribute__((address(0x7FE3)));


extern volatile __bit SP4 __attribute__((address(0x7FE4)));


extern volatile __bit SPEN __attribute__((address(0x7D5F)));


extern volatile __bit SREN __attribute__((address(0x7D5D)));


extern volatile __bit SRENA __attribute__((address(0x7D5D)));


extern volatile __bit SS __attribute__((address(0x7C05)));


extern volatile __bit SS2 __attribute__((address(0x7C1F)));


extern volatile __bit SSPEN __attribute__((address(0x7E35)));


extern volatile __bit SSPIE __attribute__((address(0x7CEB)));


extern volatile __bit SSPIF __attribute__((address(0x7CF3)));


extern volatile __bit SSPIP __attribute__((address(0x7CFB)));


extern volatile __bit SSPM0 __attribute__((address(0x7E30)));


extern volatile __bit SSPM1 __attribute__((address(0x7E31)));


extern volatile __bit SSPM2 __attribute__((address(0x7E32)));


extern volatile __bit SSPM3 __attribute__((address(0x7E33)));


extern volatile __bit SSPOV __attribute__((address(0x7E36)));


extern volatile __bit START __attribute__((address(0x7E3B)));


extern volatile __bit STKFUL __attribute__((address(0x7FE7)));


extern volatile __bit STKOVF __attribute__((address(0x7FE7)));


extern volatile __bit STKPTR0 __attribute__((address(0x7FE0)));


extern volatile __bit STKPTR1 __attribute__((address(0x7FE1)));


extern volatile __bit STKPTR2 __attribute__((address(0x7FE2)));


extern volatile __bit STKPTR3 __attribute__((address(0x7FE3)));


extern volatile __bit STKPTR4 __attribute__((address(0x7FE4)));


extern volatile __bit STKUNF __attribute__((address(0x7FE6)));


extern volatile __bit STOP __attribute__((address(0x7E3C)));


extern volatile __bit SWDTE __attribute__((address(0x7E88)));


extern volatile __bit SWDTEN __attribute__((address(0x7E88)));


extern volatile __bit SYNC __attribute__((address(0x7D64)));


extern volatile __bit SYNC1 __attribute__((address(0x7D64)));


extern volatile __bit T016BIT __attribute__((address(0x7EAE)));


extern volatile __bit T08BIT __attribute__((address(0x7EAE)));


extern volatile __bit T0CKI __attribute__((address(0x7C04)));


extern volatile __bit T0CS __attribute__((address(0x7EAD)));


extern volatile __bit T0IE __attribute__((address(0x7F95)));


extern volatile __bit T0IF __attribute__((address(0x7F92)));


extern volatile __bit T0PS0 __attribute__((address(0x7EA8)));


extern volatile __bit T0PS1 __attribute__((address(0x7EA9)));


extern volatile __bit T0PS2 __attribute__((address(0x7EAA)));


extern volatile __bit T0SE __attribute__((address(0x7EAC)));


extern volatile __bit T13CKI __attribute__((address(0x7C10)));


extern volatile __bit T1CKI __attribute__((address(0x7C10)));


extern volatile __bit T1CKPS0 __attribute__((address(0x7E6C)));


extern volatile __bit T1CKPS1 __attribute__((address(0x7E6D)));


extern volatile __bit T1OSCEN __attribute__((address(0x7E6B)));


extern volatile __bit T1OSI __attribute__((address(0x7C11)));


extern volatile __bit T1OSO __attribute__((address(0x7C10)));


extern volatile __bit T1RD16 __attribute__((address(0x7E6F)));


extern volatile __bit T1RUN __attribute__((address(0x7E6E)));


extern volatile __bit T1SYNC __attribute__((address(0x7E6A)));


extern volatile __bit T2CKPS0 __attribute__((address(0x7E50)));


extern volatile __bit T2CKPS1 __attribute__((address(0x7E51)));


extern volatile __bit T2OUTPS0 __attribute__((address(0x7E53)));


extern volatile __bit T2OUTPS1 __attribute__((address(0x7E54)));


extern volatile __bit T2OUTPS2 __attribute__((address(0x7E55)));


extern volatile __bit T2OUTPS3 __attribute__((address(0x7E56)));


extern volatile __bit T3CCP1 __attribute__((address(0x7D8B)));


extern volatile __bit T3CCP2 __attribute__((address(0x7D8E)));


extern volatile __bit T3CKPS0 __attribute__((address(0x7D8C)));


extern volatile __bit T3CKPS1 __attribute__((address(0x7D8D)));


extern volatile __bit T3RD16 __attribute__((address(0x7D8F)));


extern volatile __bit T3SYNC __attribute__((address(0x7D8A)));


extern volatile __bit TMR0IE __attribute__((address(0x7F95)));


extern volatile __bit TMR0IF __attribute__((address(0x7F92)));


extern volatile __bit TMR0IP __attribute__((address(0x7F8A)));


extern volatile __bit TMR0ON __attribute__((address(0x7EAF)));


extern volatile __bit TMR1CS __attribute__((address(0x7E69)));


extern volatile __bit TMR1IE __attribute__((address(0x7CE8)));


extern volatile __bit TMR1IF __attribute__((address(0x7CF0)));


extern volatile __bit TMR1IP __attribute__((address(0x7CF8)));


extern volatile __bit TMR1ON __attribute__((address(0x7E68)));


extern volatile __bit TMR2IE __attribute__((address(0x7CE9)));


extern volatile __bit TMR2IF __attribute__((address(0x7CF1)));


extern volatile __bit TMR2IP __attribute__((address(0x7CF9)));


extern volatile __bit TMR2ON __attribute__((address(0x7E52)));


extern volatile __bit TMR3CS __attribute__((address(0x7D89)));


extern volatile __bit TMR3IE __attribute__((address(0x7D01)));


extern volatile __bit TMR3IF __attribute__((address(0x7D09)));


extern volatile __bit TMR3IP __attribute__((address(0x7D11)));


extern volatile __bit TMR3ON __attribute__((address(0x7D88)));


extern volatile __bit TO __attribute__((address(0x7E83)));


extern volatile __bit TRISA0 __attribute__((address(0x7C90)));


extern volatile __bit TRISA1 __attribute__((address(0x7C91)));


extern volatile __bit TRISA2 __attribute__((address(0x7C92)));


extern volatile __bit TRISA3 __attribute__((address(0x7C93)));


extern volatile __bit TRISA4 __attribute__((address(0x7C94)));


extern volatile __bit TRISA5 __attribute__((address(0x7C95)));


extern volatile __bit TRISA6 __attribute__((address(0x7C96)));


extern volatile __bit TRISA7 __attribute__((address(0x7C97)));


extern volatile __bit TRISB0 __attribute__((address(0x7C98)));


extern volatile __bit TRISB1 __attribute__((address(0x7C99)));


extern volatile __bit TRISB2 __attribute__((address(0x7C9A)));


extern volatile __bit TRISB3 __attribute__((address(0x7C9B)));


extern volatile __bit TRISB4 __attribute__((address(0x7C9C)));


extern volatile __bit TRISB5 __attribute__((address(0x7C9D)));


extern volatile __bit TRISB6 __attribute__((address(0x7C9E)));


extern volatile __bit TRISB7 __attribute__((address(0x7C9F)));


extern volatile __bit TRISC0 __attribute__((address(0x7CA0)));


extern volatile __bit TRISC1 __attribute__((address(0x7CA1)));


extern volatile __bit TRISC2 __attribute__((address(0x7CA2)));


extern volatile __bit TRISC3 __attribute__((address(0x7CA3)));


extern volatile __bit TRISC4 __attribute__((address(0x7CA4)));


extern volatile __bit TRISC5 __attribute__((address(0x7CA5)));


extern volatile __bit TRISC6 __attribute__((address(0x7CA6)));


extern volatile __bit TRISC7 __attribute__((address(0x7CA7)));


extern volatile __bit TRISD0 __attribute__((address(0x7CA8)));


extern volatile __bit TRISD1 __attribute__((address(0x7CA9)));


extern volatile __bit TRISD2 __attribute__((address(0x7CAA)));


extern volatile __bit TRISD3 __attribute__((address(0x7CAB)));


extern volatile __bit TRISD4 __attribute__((address(0x7CAC)));


extern volatile __bit TRISD5 __attribute__((address(0x7CAD)));


extern volatile __bit TRISD6 __attribute__((address(0x7CAE)));


extern volatile __bit TRISD7 __attribute__((address(0x7CAF)));


extern volatile __bit TRISE0 __attribute__((address(0x7CB0)));


extern volatile __bit TRISE1 __attribute__((address(0x7CB1)));


extern volatile __bit TRISE2 __attribute__((address(0x7CB2)));


extern volatile __bit TRMT __attribute__((address(0x7D61)));


extern volatile __bit TRMT1 __attribute__((address(0x7D61)));


extern volatile __bit TUN0 __attribute__((address(0x7CD8)));


extern volatile __bit TUN1 __attribute__((address(0x7CD9)));


extern volatile __bit TUN2 __attribute__((address(0x7CDA)));


extern volatile __bit TUN3 __attribute__((address(0x7CDB)));


extern volatile __bit TUN4 __attribute__((address(0x7CDC)));


extern volatile __bit TX __attribute__((address(0x7C16)));


extern volatile __bit TX1IE __attribute__((address(0x7CEC)));


extern volatile __bit TX1IF __attribute__((address(0x7CF4)));


extern volatile __bit TX1IP __attribute__((address(0x7CFC)));


extern volatile __bit TX8_9 __attribute__((address(0x7D66)));


extern volatile __bit TX9 __attribute__((address(0x7D66)));


extern volatile __bit TX91 __attribute__((address(0x7D66)));


extern volatile __bit TX9D __attribute__((address(0x7D60)));


extern volatile __bit TX9D1 __attribute__((address(0x7D60)));


extern volatile __bit TXCKP __attribute__((address(0x7DC4)));


extern volatile __bit TXD8 __attribute__((address(0x7D60)));


extern volatile __bit TXEN __attribute__((address(0x7D65)));


extern volatile __bit TXEN1 __attribute__((address(0x7D65)));


extern volatile __bit TXIE __attribute__((address(0x7CEC)));


extern volatile __bit TXIF __attribute__((address(0x7CF4)));


extern volatile __bit TXIP __attribute__((address(0x7CFC)));


extern volatile __bit UA __attribute__((address(0x7E39)));


extern volatile __bit ULPWUIN __attribute__((address(0x7C00)));


extern volatile __bit VCFG0 __attribute__((address(0x7E0C)));


extern volatile __bit VCFG01 __attribute__((address(0x7E0C)));


extern volatile __bit VCFG1 __attribute__((address(0x7E0D)));


extern volatile __bit VCFG11 __attribute__((address(0x7E0D)));


extern volatile __bit VDIRMAG __attribute__((address(0x7E97)));


extern volatile __bit VPP __attribute__((address(0x7C23)));


extern volatile __bit W4E __attribute__((address(0x7DC1)));


extern volatile __bit WAIT0 __attribute__((address(0x7E5C)));


extern volatile __bit WAIT1 __attribute__((address(0x7E5D)));


extern volatile __bit WCOL __attribute__((address(0x7E37)));


extern volatile __bit WM0 __attribute__((address(0x7E58)));


extern volatile __bit WM1 __attribute__((address(0x7E59)));


extern volatile __bit __attribute__((__deprecated__)) WR __attribute__((address(0x7D31)));


extern volatile __bit WRE __attribute__((address(0x7C21)));


extern volatile __bit WREN __attribute__((address(0x7D32)));


extern volatile __bit WRERR __attribute__((address(0x7D33)));


extern volatile __bit WUE __attribute__((address(0x7DC1)));


extern volatile __bit ZERO __attribute__((address(0x7EC2)));


extern volatile __bit nA __attribute__((address(0x7E3D)));


extern volatile __bit nADDRESS __attribute__((address(0x7E3D)));


extern volatile __bit nBOR __attribute__((address(0x7E80)));


extern volatile __bit nCS __attribute__((address(0x7C22)));


extern volatile __bit nDONE __attribute__((address(0x7E11)));


extern volatile __bit nMCLR __attribute__((address(0x7C23)));


extern volatile __bit nPD __attribute__((address(0x7E82)));


extern volatile __bit nPOR __attribute__((address(0x7E81)));


extern volatile __bit nRBPU __attribute__((address(0x7F8F)));


extern volatile __bit nRD __attribute__((address(0x7C20)));


extern volatile __bit nRI __attribute__((address(0x7E84)));


extern volatile __bit nSS __attribute__((address(0x7C05)));


extern volatile __bit nT1SYNC __attribute__((address(0x7E6A)));


extern volatile __bit nT3SYNC __attribute__((address(0x7D8A)));


extern volatile __bit nTO __attribute__((address(0x7E83)));


extern volatile __bit nW __attribute__((address(0x7E3A)));


extern volatile __bit nWR __attribute__((address(0x7C21)));


extern volatile __bit nWRITE __attribute__((address(0x7E3A)));
# 734 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18_chip_select.h" 2 3
# 8 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 2 3
# 18 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 3
__attribute__((__unsupported__("The " "flash_write" " routine is no longer supported. Please use the MPLAB X MCC."))) void flash_write(const unsigned char *, unsigned int, __far unsigned char *);
__attribute__((__unsupported__("The " "EraseFlash" " routine is no longer supported. Please use the MPLAB X MCC."))) void EraseFlash(unsigned long startaddr, unsigned long endaddr);







# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\errata.h" 1 3
# 26 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 2 3
# 49 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 3
#pragma intrinsic(__nop)
extern void __nop(void);
# 158 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 3
__attribute__((__unsupported__("The " "Read_b_eep" " routine is no longer supported. Please use the MPLAB X MCC."))) unsigned char Read_b_eep(unsigned int badd);
__attribute__((__unsupported__("The " "Busy_eep" " routine is no longer supported. Please use the MPLAB X MCC."))) void Busy_eep(void);
__attribute__((__unsupported__("The " "Write_b_eep" " routine is no longer supported. Please use the MPLAB X MCC."))) void Write_b_eep(unsigned int badd, unsigned char bdat);
# 178 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\pic18.h" 3
unsigned char __t1rd16on(void);
unsigned char __t3rd16on(void);






#pragma intrinsic(_delay)
extern __attribute__((nonreentrant)) void _delay(unsigned long);
#pragma intrinsic(_delaywdt)
extern __attribute__((nonreentrant)) void _delaywdt(unsigned long);
#pragma intrinsic(_delay3)
extern __attribute__((nonreentrant)) void _delay3(unsigned char);
# 32 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\xc.h" 2 3
# 9 "Liofilizador Placa Mae.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 1 3
# 25 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 411 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct __locale_struct * locale_t;
# 25 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 2 3


void *memcpy (void *restrict, const void *restrict, size_t);
void *memmove (void *, const void *, size_t);
void *memset (void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void *memchr (const void *, int, size_t);

char *strcpy (char *restrict, const char *restrict);
char *strncpy (char *restrict, const char *restrict, size_t);

char *strcat (char *restrict, const char *restrict);
char *strncat (char *restrict, const char *restrict, size_t);

int strcmp (const char *, const char *);
int strncmp (const char *, const char *, size_t);

int strcoll (const char *, const char *);
size_t strxfrm (char *restrict, const char *restrict, size_t);

char *strchr (const char *, int);
char *strrchr (const char *, int);

size_t strcspn (const char *, const char *);
size_t strspn (const char *, const char *);
char *strpbrk (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *restrict, const char *restrict);

size_t strlen (const char *);

char *strerror (int);
# 65 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\string.h" 3
char *strtok_r (char *restrict, const char *restrict, char **restrict);
int strerror_r (int, char *, size_t);
char *stpcpy(char *restrict, const char *restrict);
char *stpncpy(char *restrict, const char *restrict, size_t);
size_t strnlen (const char *, size_t);
char *strdup (const char *);
char *strndup (const char *, size_t);
char *strsignal(int);
char *strerror_l (int, locale_t);
int strcoll_l (const char *, const char *, locale_t);
size_t strxfrm_l (char *restrict, const char *restrict, size_t, locale_t);




void *memccpy (void *restrict, const void *restrict, int, size_t);
# 10 "Liofilizador Placa Mae.c" 2


# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\time.h" 1 3
# 33 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\time.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 76 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long time_t;
# 293 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef void * timer_t;




typedef int clockid_t;




typedef long clock_t;
# 313 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
struct timespec { time_t tv_sec; long tv_nsec; };





typedef int pid_t;
# 33 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\time.h" 2 3







struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long __tm_gmtoff;
 const char *__tm_zone;
};

clock_t clock (void);
time_t time (time_t *);
double difftime (time_t, time_t);
time_t mktime (struct tm *);
size_t strftime (char *restrict, size_t, const char *restrict, const struct tm *restrict);
struct tm *gmtime (const time_t *);
struct tm *localtime (const time_t *);
char *asctime (const struct tm *);
char *ctime (const time_t *);
int timespec_get(struct timespec *, int);
# 73 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\time.h" 3
size_t strftime_l (char * restrict, size_t, const char * restrict, const struct tm * restrict, locale_t);

struct tm *gmtime_r (const time_t *restrict, struct tm *restrict);
struct tm *localtime_r (const time_t *restrict, struct tm *restrict);
char *asctime_r (const struct tm *restrict, char *restrict);
char *ctime_r (const time_t *, char *);

void tzset (void);

struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};
# 102 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\time.h" 3
int nanosleep (const struct timespec *, struct timespec *);
int clock_getres (clockid_t, struct timespec *);
int clock_gettime (clockid_t, struct timespec *);
int clock_settime (clockid_t, const struct timespec *);
int clock_nanosleep (clockid_t, int, const struct timespec *, struct timespec *);
int clock_getcpuclockid (pid_t, clockid_t *);

struct sigevent;
int timer_create (clockid_t, struct sigevent *restrict, timer_t *restrict);
int timer_delete (timer_t);
int timer_settime (timer_t, int, const struct itimerspec *restrict, struct itimerspec *restrict);
int timer_gettime (timer_t, struct itimerspec *);
int timer_getoverrun (timer_t);

extern char *tzname[2];





char *strptime (const char *restrict, const char *restrict, struct tm *restrict);
extern int daylight;
extern long timezone;
extern int getdate_err;
struct tm *getdate (const char *);
# 12 "Liofilizador Placa Mae.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 1 3
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3





typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 137 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 246 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 399 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const

int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 13 "Liofilizador Placa Mae.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdbool.h" 1 3
# 14 "Liofilizador Placa Mae.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\math.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\math.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 1 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 173 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 209 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 139 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 139 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\stdint.h" 2 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\math.h" 2 3





# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 33 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\bits/alltypes.h" 3
typedef float float_t;




typedef double double_t;
# 15 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\math.h" 2 3
# 42 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\math.h" 3
int __fpclassifyf(float);







int __signbitf(float);
# 59 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\math.h" 3
double acos(double);
float acosf(float);
long double acosl(long double);



double acosh(double);
float acoshf(float);
long double acoshl(long double);



double asin(double);
float asinf(float);
long double asinl(long double);



double asinh(double);
float asinhf(float);
long double asinhl(long double);



double atan(double);
float atanf(float);
long double atanl(long double);



double atan2(double, double);
float atan2f(float, float);
long double atan2l(long double, long double);



double atanh(double);
float atanhf(float);
long double atanhl(long double);



double cbrt(double);
float cbrtf(float);
long double cbrtl(long double);



double ceil(double);
float ceilf(float);
long double ceill(long double);



double copysign(double, double);
float copysignf(float, float);
long double copysignl(long double, long double);



double cos(double);
float cosf(float);
long double cosl(long double);



double cosh(double);
float coshf(float);
long double coshl(long double);



double erf(double);
float erff(float);
long double erfl(long double);



double erfc(double);
float erfcf(float);
long double erfcl(long double);



double exp(double);
float expf(float);
long double expl(long double);



double exp2(double);
float exp2f(float);
long double exp2l(long double);



double expm1(double);
float expm1f(float);
long double expm1l(long double);



double fabs(double);
float fabsf(float);
long double fabsl(long double);



double fdim(double, double);
float fdimf(float, float);
long double fdiml(long double, long double);



double floor(double);
float floorf(float);
long double floorl(long double);



double fma(double, double, double);
float fmaf(float, float, float);
long double fmal(long double, long double, long double);



double fmax(double, double);
float fmaxf(float, float);
long double fmaxl(long double, long double);



double fmin(double, double);
float fminf(float, float);
long double fminl(long double, long double);



double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);



double frexp(double, int *);
float frexpf(float, int *);
long double frexpl(long double, int *);



double hypot(double, double);
float hypotf(float, float);
long double hypotl(long double, long double);



int ilogb(double);
int ilogbf(float);
int ilogbl(long double);



double ldexp(double, int);
float ldexpf(float, int);
long double ldexpl(long double, int);



double lgamma(double);
float lgammaf(float);
long double lgammal(long double);



long long llrint(double);
long long llrintf(float);
long long llrintl(long double);



long long llround(double);
long long llroundf(float);
long long llroundl(long double);



double log(double);
float logf(float);
long double logl(long double);



double log10(double);
float log10f(float);
long double log10l(long double);



double log1p(double);
float log1pf(float);
long double log1pl(long double);



double log2(double);
float log2f(float);
long double log2l(long double);



double logb(double);
float logbf(float);
long double logbl(long double);



long lrint(double);
long lrintf(float);
long lrintl(long double);



long lround(double);
long lroundf(float);
long lroundl(long double);



double modf(double, double *);
float modff(float, float *);
long double modfl(long double, long double *);



double nan(const char *);
float nanf(const char *);
long double nanl(const char *);



double nearbyint(double);
float nearbyintf(float);
long double nearbyintl(long double);



double nextafter(double, double);
float nextafterf(float, float);
long double nextafterl(long double, long double);



double nexttoward(double, long double);
float nexttowardf(float, long double);
long double nexttowardl(long double, long double);




double pow(double, double);
__attribute__((nonreentrant)) float powf(float, float);
long double powl(long double, long double);



double remainder(double, double);
float remainderf(float, float);
long double remainderl(long double, long double);



double remquo(double, double, int *);
float remquof(float, float, int *);
long double remquol(long double, long double, int *);



double rint(double);
float rintf(float);
long double rintl(long double);



double round(double);
float roundf(float);
long double roundl(long double);



double scalbln(double, long);
float scalblnf(float, long);
long double scalblnl(long double, long);



double scalbn(double, int);
float scalbnf(float, int);
long double scalbnl(long double, int);



double sin(double);
float sinf(float);
long double sinl(long double);



double sinh(double);
float sinhf(float);
long double sinhl(long double);



double sqrt(double);
float sqrtf(float);
long double sqrtl(long double);



double tan(double);
float tanf(float);
long double tanl(long double);



double tanh(double);
float tanhf(float);
long double tanhl(long double);



double tgamma(double);
float tgammaf(float);
long double tgammal(long double);



double trunc(double);
float truncf(float);
long double truncl(long double);
# 423 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c99\\math.h" 3
extern int signgam;

double j0(double);
double j1(double);
double jn(int, double);

double y0(double);
double y1(double);
double yn(int, double);
# 15 "Liofilizador Placa Mae.c" 2

# 1 "./global.h" 1
# 20 "./global.h"
#pragma config OSC = INTIO67
#pragma config FCMEN = OFF
#pragma config IESO = OFF


#pragma config PWRT = ON
#pragma config BOREN = SBORDIS
#pragma config BORV = 3


#pragma config WDT = ON
#pragma config WDTPS = 16384


#pragma config CCP2MX = PORTC
#pragma config PBADEN = ON
#pragma config LPT1OSC = OFF
#pragma config MCLRE = ON


#pragma config STVREN = ON
#pragma config LVP = OFF
#pragma config XINST = OFF


#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF


#pragma config CPB = OFF
#pragma config CPD = OFF


#pragma config WRT0 = OFF
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT3 = OFF


#pragma config WRTC = OFF
#pragma config WRTB = OFF
#pragma config WRTD = OFF


#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF


#pragma config EBTRB = OFF
# 225 "./global.h"
struct {
    unsigned flag_usart_rx : 1 ;
    unsigned flag_usart_error : 1 ;
    unsigned flag_power_off : 1 ;
    unsigned flag_led_tmr0 : 1 ;
    unsigned flag_led_usart : 1 ;
    unsigned flag_led_memory : 1 ;
    unsigned flag_capture_datalog : 1 ;
    unsigned flag_edit_temperatura: 1 ;
} statusgen ;
# 248 "./global.h"
union {
      unsigned char bits;
      struct {
             unsigned flag_global_datalog : 1 ;
             unsigned flag_global_aquecimento : 1 ;
             unsigned flag_global_condensador : 1 ;
             unsigned flag_global_vacuo : 1 ;
             unsigned flag_time_process : 1 ;
             unsigned flag_call_work : 1 ;

             };
      } statuspower;
# 270 "./global.h"
struct{
        unsigned flag_save_time :1;
        unsigned flag_wakeup :1;
        unsigned flagSendDataFix :1;
        unsigned flag_proculus_hs :1;
        unsigned flag_Vacuo_estava_ligado :1;
        unsigned flag_generico :1;
        unsigned flag_recomunication :1;
}statusgen1;
# 288 "./global.h"
struct{
        unsigned flag_main_loop_WDT :1;
}statusWDT;


typedef struct{
    unsigned int milisegundo;
    unsigned char segundo;
    unsigned char minuto;
    unsigned char hora;
}t_rtc;

volatile t_rtc rtc;
# 16 "Liofilizador Placa Mae.c" 2

# 1 "./Liofilizador Placa Mae.h" 1
# 13 "./Liofilizador Placa Mae.h"
typedef struct{
           int *entrada[15];
           float fator[15];
           char canal[15];
           char icone[15];
           char vpIcone[15];
     int cor[15];
              } T_mapa;



typedef struct{
        unsigned char plataforma;

                 int setpoint;
        unsigned char tempoON;
        unsigned char tempoOFF;
        unsigned char histerese;
                 char receita[9];
        unsigned int status ;
} t_liofilizador;




typedef struct{
    unsigned char plataforma;
    int setpoint;
    unsigned int potenciaON;
    unsigned int potenciaOFF;
    unsigned char histerese;
    unsigned char receita[10];
    unsigned int status0;
} t_aquecimento;

typedef struct{
    int setpoint;
    unsigned int potenciaON;
    unsigned int potenciaOFF;
    unsigned char histerese;
             char nome[10];
} t_receita;

typedef struct{
    char date[10];
    char time[10];
} t_tempo;

typedef struct{
    t_tempo inicio;
    unsigned int start_add;
    t_tempo fim;
    unsigned int end_add;
    unsigned int amostra;
    unsigned int pontos;
} t_fat;


unsigned char countboard(void);
int Send_To_Slave(char destino, char comando, char size, char * buffer);
int Send_To_Slave_EMULA(char destino, char comando, char size, char * buffer);
void ShowSensorRealTimeHS(void);
void showTotalReset(void);
void AcordaFilha(void);


void SaveLiofilizadorOnMemory(char index,t_liofilizador *liofilizador);
void ShowStaticValueGrid(unsigned char tupla);

void ShowAndSetSlaveParameters(unsigned char tupla);
void Comando_Protocolo_Serial(void);
void Send_to_PC(unsigned char size);

void Upload_Data_to_Slave(void);
void Decodify_Command(void);
void SEND_REPLY_OK(void);


void global_datalog(void);
void global_condensador(void);
void global_vacuo(void);
void global_aquecimento(void);

void Exibe_Hora_Data(char showseconds);
void Exibe_Tempo_de_Processo(void);

void DataBaseBackupMain(unsigned char tupla);
void Formatar_Banco_de_Dados(char inicio, char total);
void Salva_Seguranca(void);
void Formatar_Datalog(void);
void ShowMessage(char mensagem[30],unsigned int delay, char SoundType, char retem);

void Comando_Microcomputador(void);
void Comando_Display(void);


void Inicializar_Seguranca(void);

void SaveBlackoutStatus(void);
void SaveBlackoutStatusRuning(void);
void RecallBlackoutStatus(void);

void Check_And_Send_Capture_Datalog(void);
void save_datalog(unsigned long add_datalog);

void Contagem_Tempo_de_Processo(char value);
void Carregar_tempo_de_datalog(void);

void Carrega_Tupla_Receita(char index, t_receita *receita);

void ShowHardwareInfo(void);

void Global_Aquecimento_Switch(unsigned char estado);
void Gerenciador_de_Senha(void);
void Gerenciador_de_Senha_Global(void);
void Icones_de_alarmes(void);

void Condensador_Switch(unsigned char estado);
void Vaccum_Switch(unsigned char estado);
void TrendCurveFuncao(char funcao);
char buscaIndex(char *buffer,char valor);

void Exibe_Receita(int add_receita);
void Grava_Receita(char index, t_receita *receita);
void Formatar_Lista_de_Receitas(void);
void Formatar_Dados_de_Seguranca(void);
void Carregar_Parametros_de_Seguranca(void);

void Gravar_Status_da_Senha_Global(void);
void Carregar_Status_da_Senha_Global(void);

void Atualizar_Lista_de_Receitas(void);

int Tupla_Log_Free(void);
void Write_Fat(char value);
void Memo2Graphic(char SlaveBoardAdd, char chipNumber, int add_24C1025, char LCDchannel);

void Buffer_Manager(void);


unsigned int Captura_Pagina(void);
_Bool memory_test(char board, char chip, int value, int inicialadd, int finaladd);
char menorValorDisponivel(char * trendCurve);


 void Set_Receita(unsigned char index, char status);

void pagina_15(void);
void pagina_19(void);
void pagina_23(void);
void pagina_25(void);
void pagina_29(void);
void pagina_31(void);
void pagina_47(void);
void pagina_49(void);

char MenorCanalLivre(void);

void Incrementa_Contador_de_Repique_do_Vacuo(void);
void Carregar_Display_Schematic_Color(void);
void Ligar_Cargas_Compassadamente(void);

void Teste24cXXXX(void);
# 17 "Liofilizador Placa Mae.c" 2

# 1 "./isr.h" 1
# 13 "./isr.h"
# 1 "./proculus.h" 1
# 57 "./proculus.h"
typedef struct {
    unsigned int header;
    unsigned char size;
    unsigned char function;
    unsigned int vp;
    unsigned char length;
    unsigned int dado[15];
    unsigned char page;
    unsigned char button;
    unsigned char status;
    }t_proculus;


typedef struct{
              unsigned char plataforma;
              unsigned int temperaturaatual;
              unsigned int setpoint;
              unsigned char tempoON;
              unsigned char tempoOFF;
              } t_visaogeral;


void PROCULUS_REG_Write(unsigned char *vetor, unsigned char size);
void PROCULUS_REG_Read(unsigned char reg, unsigned char size, unsigned char *retorno);
void PROCULUS_Read_RTC(char *date, char *time);
void PROCULUS_Write_RTC(char *date, char *time);
void PROCULUS_Control_Activation(char value);

void PROCULUS_VP_Write(unsigned int vp,char *vetor,char size);


void PROCULUS_VP_Read(unsigned int vp,char *vetor,char size);







void PROCULUS_VP_Write_Byte(unsigned int vp,char value);
unsigned char PROCULUS_VP_Read_Byte(unsigned int vp);



void PROCULUS_VP_Write_UInt16(unsigned int vp, unsigned int value);
unsigned int PROCULUS_VP_Read_UInt16(unsigned int vp);



void PROCULUS_VP_Write_Int16(unsigned int vp, int value);
unsigned int PROCULUS_VP_Read_Int16(int vp);



long PROCULUS_VP_Read_Long32(unsigned int vp);
void PROCULUS_VP_Write_Long32(unsigned int vp, unsigned long value);



void PROCULUS_VP_Write_Float24(unsigned int vp, float value);
float PROCULUS_VP_Read_Float24(unsigned int vp);

void PROCULUS_VP_Write_Float32(unsigned int vp, float value);
float PROCULUS_VP_Read_Float32(unsigned int vp);




void PROCULUS_VP_Write_Double24(unsigned int vp, double value);
double PROCULUS_VP_Read_Double24(unsigned int vp);

void PROCULUS_VP_Write_Double32(unsigned int vp, double value);
double PROCULUS_VP_Read_Double32(unsigned int vp);


void PROCULUS_VP_Write_String(unsigned int vp, char *text);
void PROCULUS_VP_Read_String(unsigned int vp, char *text);







unsigned char PROCULUS_Read_Version(void);
void PROCULUS_Buzzer(unsigned int time_ms_x_10);
void PROCULUS_Show_Screen(unsigned int screen);
void PROCULUS_Reset(void);
char PROCULUS_TPFLAG_Read(void);
void PROCULUS_TPFLAG_Write(char value);

void PROCULUS_Buffer_to_Proculus(t_proculus *proculus);

void PROCULUS_OK(void);
void PROCULUS_NOK(void);

void PROCULUS_Delay(unsigned int tempo_ms);

unsigned int PROCULUS_Get_Page(void);

void PROCULUS_Popup(char value);

void PROCULUS_graphic_plot(unsigned char lcd_channel, unsigned int value);

void PROCULUS_Clear_Line_Graphic(char channel);
# 13 "./isr.h" 2



void __attribute__((picinterrupt(("low_priority")))) isr(void);
# 18 "Liofilizador Placa Mae.c" 2


# 1 "./usart.h" 1
# 20 "./usart.h"
# 1 "./protocolo.h" 1
# 22 "./protocolo.h"
typedef struct {
        int header;
        char origem;
        char destino;
        char command;
        char size;
        char value[74];
} t_usart_protocol;
# 21 "./usart.h" 2
# 35 "./usart.h"
void USART_to_Protocol(t_usart_protocol *usart_protocol);
void USART_init(unsigned long baudrate);
void USART_putc(unsigned char value);
void USART_put_int(unsigned int value);
void USART_put_sint(int value);
void USART_put_float24(float value);
void USART_put_long(unsigned long value);
void USART_put_string(char *vetor);
void USART_put_buffer(char *vetor, char size);
unsigned char USART_input_buffer(void);
# 20 "Liofilizador Placa Mae.c" 2

# 1 "./I2C.h" 1
# 11 "./I2C.h"
void I2C_Master_Init(const unsigned long c);
void I2C_Slave_Init(short address);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
void I2C_Master_Write(unsigned d);
unsigned short I2C_Master_Read(unsigned short a);
# 21 "Liofilizador Placa Mae.c" 2

# 1 "./adc.h" 1
# 15 "./adc.h"
void My_ADC_init(void);
double My_ADC_Read(unsigned char canal);



void My_ADC_init(void) ;
float ADC_Read(unsigned char canal) ;
float ADC_Read_NTC(unsigned char canal) ;
unsigned int LerADcomFiltro(unsigned char canal) ;
unsigned int NovoADCon(unsigned char canal) ;
unsigned int captura();
void ADCON_set(unsigned char canal);
# 22 "Liofilizador Placa Mae.c" 2

# 1 "./timedate.h" 1
# 19 "./timedate.h"
void my_delay_ms(long time);
void my_delay_ms_TMR1(long time);
void my_delay_ms_CLRWDT(long time);
# 23 "Liofilizador Placa Mae.c" 2

# 1 "./util.h" 1



void print(char *texto);
void bcd2str(char valor, char *dado);
char str2bcd(char *value);
void clear_screen(void);
int my_pow(int rad, int exp);

char* itoa(int num, char* str, int base);
char * reverse( char * s );
char *ultoa(unsigned long num, char *str, int radix);
# 24 "Liofilizador Placa Mae.c" 2

# 1 "./protocolo.h" 1
# 25 "Liofilizador Placa Mae.c" 2

# 1 "./eeprom.h" 1
# 14 "./eeprom.h"
void EEPROM_Write_Byte(unsigned int addr, unsigned char dado);
unsigned char EEPROM_Read_Byte(unsigned int addr);
void EEPROM_Write_Integer(unsigned int addr, unsigned int dado);
int EEPROM_Read_Integer(unsigned int addr);
void EEPROM_Write_Float(unsigned int addr,float dado);
float EEPROM_Read_Float(unsigned int addr);
void EEPROM_Write_Double(unsigned int addr,double dado);
float EEPROM_Read_Double(unsigned int addr);


void EEPROM_Write_ULong24(unsigned int addr,long dado);
long EEPROM_Read_ULong24(unsigned int addr);
void EEPROM_Write_Long32(unsigned int addr,long dado);
long EEPROM_Read_Long32(unsigned int addr);

void EEPROM_Write_String(unsigned int addr,char *dado);
void EEPROM_Read_String(unsigned int addr,char *dado);

void EEPROM_Write_Buffer(unsigned int addr,char *dado,char size);
void EEPROM_Read_Buffer(unsigned int addr,char *dado,char size);
# 26 "Liofilizador Placa Mae.c" 2

# 1 "./EEPROM_24C1025.h" 1
# 16 "./EEPROM_24C1025.h"
void EEPROM_24C1025_Write_Buffer(unsigned char chip_add,
                                  unsigned long mem_add,
                                 unsigned char sizedata,
                                            char *data);

void EEPROM_24C1025_Read_Buffer(unsigned char chip_add,
                                 unsigned long mem_add,
                                unsigned char sizedata,
                                           char *data);

void EEPROM_24C1025_Read_Str(unsigned char chip_add, unsigned long mem_add,char *texto);
void EEPROM_24C1025_Write_Str(unsigned char chip_add, unsigned long mem_add,char *data);


void EEPROM_24C1025_Write_Byte(unsigned char chip_add, unsigned long mem_add, char *data);
unsigned char EEPROM_24C1025_Read_Byte(unsigned char chip_add, unsigned long mem_add);
void EEPROM_24C1025_Write_Int(unsigned char chip_add, unsigned long mem_add, char *data);
unsigned int EEPROM_24C1025_Read_Int(unsigned char chip_add, unsigned long mem_add);

void EEPROM_24C1025_Fill_All(unsigned char chip_add, unsigned char value);
# 27 "Liofilizador Placa Mae.c" 2

# 1 "./voltagem.h" 1
# 12 "./voltagem.h"
int VOLTAGEM_read(char canal);
# 28 "Liofilizador Placa Mae.c" 2

# 1 "./versao.h" 1
# 29 "Liofilizador Placa Mae.c" 2
# 50 "Liofilizador Placa Mae.c"
const char *boardtype[5]={"Mother Board",
                          "Vaccum Board",
                          "PT100 Board ",
                          "NTC Board   ",
                          "Relay_Board "};
# 64 "Liofilizador Placa Mae.c"
volatile unsigned char usart_buffer[74];
volatile unsigned char usart_buffer_fila[6][74];
# 74 "Liofilizador Placa Mae.c"
volatile unsigned int tempodecorrido ;
volatile unsigned int tempocaptura ;
volatile unsigned int tempocapturaconstante ;

volatile unsigned char processo_segundo ;
volatile unsigned char processo_minuto ;
volatile unsigned char processo_hora ;



volatile unsigned int tmr_led_memory;
volatile unsigned int Delay_Led_Memory;

volatile unsigned int tmr_led_usart;
volatile unsigned int Delay_Led_Usart;

volatile unsigned int tmr_led_tmr0;
volatile unsigned int Delay_Led_Tmr0;




volatile unsigned int delaycheckscreen;
volatile signed int senhacount;
volatile unsigned int delay_update_display;



t_usart_protocol usart_protocol;
t_proculus proculus;
t_liofilizador liofilizador[10];
t_receita receita;
t_fat processo;



char texto[74];
char buffer[74];



char maincnt;
unsigned int pagina=15;
unsigned int paginamemo=15;
# 130 "Liofilizador Placa Mae.c"
volatile unsigned char flag_senha_global_liberada;
volatile unsigned char flag_senha_liberada;
volatile unsigned char totalboard;
volatile signed int senhacount;
unsigned long senha_atual;
char senhavetor[4];


int Condensador ;
int Vacuometro ;
int Voltimetro ;

int Seg_Condensador ;
int Seg_Vacuo ;
int Seg_Aq_cond ;
int Seg_Aq_vacuo ;
int leitura[0x0F] ;


char Index_Receita;
char Index_Sel_Rec;


unsigned long add_datalog;

char returnToScreen;

volatile char MonitorBuffer;



char trendExist;
int trendvp=0x0310;
char icone ;


unsigned char nabucodonozor=0;

unsigned int vpPrint=2000;

volatile unsigned char flag_array_slave_WDT[15];

unsigned char memo_statuspower;

volatile unsigned char delay_condensador;

int index;
int Tamanho_Display;
int TrendColor[13];

T_mapa mapa;


void main(void)
{
     my_delay_ms_CLRWDT(100);

     OSCCONbits.IRCF0=1;
     OSCCONbits.IRCF1=1;
     OSCCONbits.IRCF2=1;
     OSCTUNEbits.PLLEN=1;

     TRISA=0b11101111;
     TRISB=0b00000001;
     TRISC=0b11110000;
     TRISD=0b11100011;
     TRISE=0xFF;




     T0CONbits.T0CS = 0;
     T0CONbits.PSA = 0;
     T0CONbits.T0PS1 = 1;
     T0CONbits.T0PS1 = 1;
     T0CONbits.T0PS2 = 1;
     INTCON2bits.TMR0IP =0;
     INTCONbits.T0IE =1;



     RBIF=0;
     INTCONbits.INT0IE =0;


     PIR1bits.TMR1IF = 0;
     IPR1bits.TMR1IP=0;
     TMR1H = 0x0B;
     TMR1L = 0xBA;
     TMR1CS = 0;
     T1CKPS0 = 1;
     T1CKPS1 = 1;
     T1RUN=1;
     T1OSCEN=1;
     PIE1bits.TMR1IE=1;
     TMR1ON = 1;





     INTCONbits.PEIE =1;




     INTCONbits.GIE =1;






     Delay_Led_Tmr0=0;
     PORTBbits.RB7=0;
     Delay_Led_Usart=0;
     PORTBbits.RB6=0;
     Delay_Led_Memory=0;
     PORTBbits.RB5=0;



     USART_init(115200);
     My_ADC_init();
     I2C_Master_Init(100000);
     my_delay_ms_CLRWDT(500);
# 329 "Liofilizador Placa Mae.c"
     {
     unsigned int reset;
     reset=EEPROM_Read_Integer(34);
     if(reset==0xFFFF)
       {
       EEPROM_Write_Integer(34,0);
       EEPROM_Write_Integer(0xE8,0);
       }
     reset++;
     EEPROM_Write_Integer(34,reset);
     statusgen1.flag_Vacuo_estava_ligado=0;

     }




     Tamanho_Display=EEPROM_Read_Integer(0xFA);
     my_delay_ms_CLRWDT(300);
     print("JJ Cientifica Ind. e Com. de Eq. Cientificos.");
     my_delay_ms_CLRWDT(300);
     print("Inicializando o Sistema...");
     my_delay_ms_CLRWDT(300);
     print("Analisando Hardware. Aguarde...");
     my_delay_ms_CLRWDT(300);
     PROCULUS_VP_Read_String(1990, buffer);
     strcpy(texto,"* : Display      ");
     strcat(texto,buffer);
     print(texto);
     my_delay_ms_CLRWDT(300);
     ShowHardwareInfo();





     if(EEPROM_Read_Byte(52)==0xFF)
       {
       print("Formatando memoria principal...");
       Formatar_Banco_de_Dados(0,10);
       Formatar_Lista_de_Receitas();
       Formatar_Dados_de_Seguranca();
       Formatar_Datalog();
       flag_senha_global_liberada=0;
       flag_senha_liberada=0;
       Gravar_Status_da_Senha_Global();
       EEPROM_Write_Byte(16,0);
       EEPROM_Write_Integer(0x09,10);
       EEPROM_Write_Long32(11,123456);
       TrendCurveFuncao(0);
       EEPROM_Write_Byte(17,0);
       EEPROM_Write_Byte(18,0);
       }
     RecallBlackoutStatus();
     TrendCurveFuncao(1);
     senha_atual=EEPROM_Read_Long32(11);
     Carregar_Status_da_Senha_Global();
     Carregar_Parametros_de_Seguranca();
     Carregar_tempo_de_datalog();



     print("Analisando dados...");
     for(char i=0;i<15;i++)
        {
        __asm("CLRWDT");
        ShowStaticValueGrid(i);
        }






     for(char i=0;i<8;i++)
         {
         __asm("CLRWDT");
         Exibe_Receita(i);
         }

     senha_atual=EEPROM_Read_Long32(11);

     Carregar_Status_da_Senha_Global();



     ShowSensorRealTimeHS();



     Carregar_Parametros_de_Seguranca();
     Carregar_tempo_de_datalog();






     Exibe_Tempo_de_Processo();
     Icones_de_alarmes();

     pagina=0;
     paginamemo=0;
     maincnt=0;
     delaycheckscreen=0;
     MonitorBuffer=0;

     Vacuometro=0;
     Voltimetro=0;
     Condensador=0;


     Exibe_Hora_Data(0);
     rtc.milisegundo=0;
     rtc.segundo=0;


     processo_segundo=0;
     memo_statuspower=statuspower.bits;
     delay_condensador=0;






        add_datalog=0;
        Ligar_Cargas_Compassadamente();
        PROCULUS_Show_Screen(15);
        while(1)
             {
             statusWDT.flag_main_loop_WDT=1;

             Buffer_Manager();


             statusgen1.flag_proculus_hs=1;
             if(delaycheckscreen>1000)
               {
               delaycheckscreen=0;
               pagina = Captura_Pagina();
               if(pagina!=paginamemo)
                  {
                  paginamemo=pagina;
                  }
               }
             statusgen1.flag_proculus_hs=0;

                statusgen1.flag_proculus_hs=1;
                if(rtc.milisegundo<2) if(pagina!=25) Exibe_Hora_Data(0);
                if(statuspower.flag_time_process==1) SaveBlackoutStatusRuning();
                Exibe_Tempo_de_Processo();
                Icones_de_alarmes();

                Gerenciador_de_Senha();
                Gerenciador_de_Senha_Global();
                statusgen1.flag_proculus_hs=0;
                global_datalog();

                global_vacuo();

                global_condensador();

                global_aquecimento();


                statusgen1.flag_proculus_hs=1;
                if(memo_statuspower!=statuspower.bits)
                  {
                  PROCULUS_OK();
                  SaveBlackoutStatus();
                  memo_statuspower=statuspower.bits;
                  }


                if((processo_segundo==0) || (processo_segundo==30))
                    {
                    if(statusgen1.flag_wakeup==1)
                       {
                       statusgen1.flag_wakeup=0;
                       AcordaFilha();
                       }
                    }
                else
                    {
                    statusgen1.flag_wakeup=1;
                    }
                Check_And_Send_Capture_Datalog();
                statusgen1.flag_proculus_hs=0;

                ShowSensorRealTimeHS();

                showTotalReset();





            statusgen1.flag_proculus_hs=1;
            switch(pagina)
                  {






                  case 19:
                  case 21:


                           for(char i=0; i<10; i++)
                               {

                               if(PROCULUS_VP_Read_UInt16(7+i)==1)
                                  {
                                  PROCULUS_VP_Write_UInt16(7+i,0);
                                  Index_Sel_Rec=i;
                                  if(Index_Sel_Rec<=4)
                                     {
                                     returnToScreen=19;
                                     PROCULUS_Show_Screen(27);
                                     }
                                  else
                                     {
                                     returnToScreen=21;
                                     PROCULUS_Show_Screen(28);
                                     }
                                  }
                               }
                          pagina_19();
                          break;
                  case 23:
                          if(PROCULUS_VP_Read_UInt16(1)==1)
                             {
                             PROCULUS_VP_Write_UInt16(1,0);
                             pagina_23();
                             }
                          break;

                  case 25:
                         if(maincnt==0)
                            {
                            Exibe_Hora_Data(1);
                            maincnt++;
                            }
                          if(PROCULUS_VP_Read_UInt16(152)==1)
                             {
                             PROCULUS_VP_Write_UInt16(152,0);
                             Exibe_Hora_Data(1);
                             }
                          if(PROCULUS_VP_Read_UInt16(174)==1)
                             {
                             PROCULUS_VP_Write_UInt16(174,0);
                             pagina_25();
                             }
                          break;
                  case 27:
                  case 28:
                          for(Index_Receita=0;Index_Receita<8;Index_Receita++)
                              {
                              if(PROCULUS_VP_Read_UInt16(0x0020+Index_Receita)==1)
                                 {
                                 PROCULUS_VP_Write_UInt16(0x0020+Index_Receita,0);
                                 PROCULUS_Show_Screen(returnToScreen);
                                 Carrega_Tupla_Receita(Index_Receita, &receita);
                                 Set_Receita(Index_Sel_Rec,1);
                                 }
                              }

                              if(PROCULUS_VP_Read_UInt16(17)==1)
                                 {
                                 PROCULUS_VP_Write_UInt16(17,0);
                                 PROCULUS_Show_Screen(returnToScreen);
                                 }

                              if(PROCULUS_VP_Read_UInt16(18)==1)
                                 {
                                 PROCULUS_VP_Write_UInt16(18,0);
                                 receita.histerese=0;
                                 strcpy(receita.nome,"");
                                 receita.potenciaOFF=0;
                                 receita.potenciaON=0;
                                 receita.setpoint=0;
                                 Set_Receita(Index_Sel_Rec,0);
                                 PROCULUS_Show_Screen(returnToScreen);
                                 }

                          break;

                  case 29:
                          if(PROCULUS_VP_Read_UInt16(175)==1)
                             {
                             PROCULUS_VP_Write_UInt16(175,0);
                             pagina_29();
                             }
                          break;
                  case 31:
                          {


                          unsigned long dica;

                          dica=~(senha_atual^0xE4BA2F10);

                          ultoa(dica,texto,16);

                          PROCULUS_VP_Write_String(1660,texto);
                          my_delay_ms_TMR1(500);
                          }
                          if(PROCULUS_VP_Read_UInt16(386)==1)
                             {
                             PROCULUS_VP_Write_UInt16(386,0);
                             pagina_31();
                             }
                          break;
                  case 35:
                            {
                            int tv;
                            char total;
                            static int canal=0;
                            statusgen1.flag_proculus_hs=1;






                            for(trendvp=0x0310;trendvp<0x031D;trendvp++)
                                  {
                                  icone=trendvp-0x0310;
                                  if(PROCULUS_VP_Read_UInt16(trendvp)==14)
                                          {
                                          if(flag_senha_liberada)
                                               {

                                               if(Tamanho_Display==50)canal=icone;
                                               if(Tamanho_Display==80)canal=MenorCanalLivre();

                                               if(canal<8)
                                                  {
                                                  PROCULUS_VP_Write_UInt16(0x310+icone,icone+1);
                                                  PROCULUS_VP_Write_UInt16((canal*10+1789),(canal<<8)|(0x0001));
                                                  PROCULUS_VP_Write_UInt16((canal*10+1787),TrendColor[icone]);


                                                  mapa.canal[canal]=canal;
                                                  mapa.icone[canal]=icone+1;
                                                  mapa.vpIcone[icone]=icone+1;
                                                  mapa.cor[canal]=TrendColor[icone];
                                                  mapa.fator[canal]=1.0;
                                                  mapa.entrada[canal]=&leitura[(icone<3)?(icone):((icone)+1)];

                                                  mapa.fator[canal]=1.0;

                                                  if(icone==0)mapa.fator[canal]=0.4546;
                                                  if(icone==1)mapa.fator[canal]=0.05;




                                                  TrendCurveFuncao(2);
                                                  }
                                               else
                                                  {
                                                  PROCULUS_VP_Write_UInt16((canal*10+1789),(canal<<8)|(0x0A00));
                                                  PROCULUS_VP_Write_UInt16((canal*10+1787),0xFFFF);
                                                  PROCULUS_VP_Write_UInt16(trendvp,-1);
                                                  }
                                               }
                                          else
                                               {
                                               PROCULUS_NOK();
                                               PROCULUS_VP_Write_UInt16(trendvp,-1);
                                               PROCULUS_Popup(0x52);
                                               }
                                          }
                                     else
                                      if((PROCULUS_VP_Read_UInt16(trendvp)>=15)&&(PROCULUS_VP_Read_UInt16(trendvp)<=30))
                                          {
                                          if(flag_senha_liberada)
                                               {
                                               char canal_aleatorio, canal_sequencial;

                                               canal_sequencial=buscaIndex(mapa.icone,icone+1);
                                               canal_aleatorio=mapa.icone[icone]-1;

                                               PROCULUS_VP_Write_UInt16(trendvp,-1);
                                               PROCULUS_VP_Write_UInt16((canal_sequencial*10+1789),0x0A00);
                                               PROCULUS_VP_Write_UInt16((canal_sequencial*10+1787),0xFFFF);

                                                                                       mapa.entrada[canal_sequencial]=((void*)0);
                                               mapa.canal[canal_sequencial]=0X0A;
                                               mapa.icone[canal_sequencial]=-1;
                                               mapa.vpIcone[icone]=-1;
                                               mapa.cor[canal_sequencial]=0xFFFF;
                                                                                   mapa.fator[canal_sequencial]=0.0;


                                               TrendCurveFuncao(2);
                                               }
                                          else
                                               {
                                               PROCULUS_NOK();
                                               PROCULUS_Popup(0x52);
                                               if(Tamanho_Display==50)PROCULUS_VP_Write_UInt16(trendvp,mapa.icone[icone]);
                                               if(Tamanho_Display==80)PROCULUS_VP_Write_UInt16(trendvp,mapa.vpIcone[icone]);
                                               }
                                          }
                                  }






                            statusgen1.flag_proculus_hs=0;
                            break;
                            }
                  case 47:
                          Atualizar_Lista_de_Receitas();

                          for(Index_Receita=0;Index_Receita<8;Index_Receita++)
                              {

                              if(PROCULUS_VP_Read_UInt16(0x0020+Index_Receita)==1)
                                 {
                                 PROCULUS_VP_Write_UInt16(0x0020+Index_Receita,0);
                                 pagina_47();
                                 break;
                                 }
                              }

                          break;
                  case 49:
                          {
                          pagina_49();
                          }
                          break;
                  }

                       statusgen1.flag_recomunication =1;
                 while(statusgen1.flag_recomunication==1){
                       statusgen1.flag_recomunication =0;
                      _delay((unsigned long)((200)*(32000000/4000.0)));
                      USART_putc(0xCD);USART_putc(0xCD);USART_putc(0xCD);
                      USART_putc(0xCD);USART_putc(0xCD);
                      for(unsigned int tempo=0; tempo<200; tempo++)
                          {
                          if(statusgen.flag_usart_rx==1) break;
                          my_delay_ms_CLRWDT(1);
                          }



                      if(statusgen.flag_usart_rx)
                         {
                         Comando_Protocolo_Serial();
                         statusgen1.flag_recomunication=1;
                         }


                      if(statusgen.flag_usart_rx)
                         {
                         Comando_Display();
                         statusgen1.flag_recomunication=1;
                         }

                 }


            }

}

unsigned char countboard()
         {
         unsigned char retorno;
         retorno=0;
         for(char destino=0;destino<0x0F;destino++)
             {
             if(Send_To_Slave(destino, 0x03, 0, buffer)!=-1) retorno++;
             }
         return retorno;
         }



 int Send_To_Slave(char destino, char comando, char size, char * buffer)
{
     unsigned int contador;
     int retorno=-1;
     char i;

     USART_put_int(0xAABB);
     USART_putc(0x00);
     USART_putc(destino);
     USART_putc(comando);
     USART_putc(size);
     for(i=0;i<size;i++)
          USART_putc(buffer[i]);
     _delay((unsigned long)((80)*(32000000/4000000.0)));


     statusgen.flag_usart_rx=0;
     for(int contador=0;contador<400;contador++)
         {
          _delay((unsigned long)((200)*(32000000/4000000.0)));
          if(statusgen.flag_usart_rx==1)
             {
             _delay((unsigned long)((2)*(32000000/4000.0)));
             statusgen.flag_usart_rx=0;
             size=usart_buffer[5];
             retorno = (usart_buffer[6]<<8)|(usart_buffer[7]);
             for(i=0;i<size;i++)
                 buffer[i]=usart_buffer[i+6];
             contador=0;
             break;
             }
          }
     return retorno;
}




int Send_To_Slave_EMULA(char destino, char comando, char size, char * buffer)
{
 switch(destino)
       {
       case 0:
             break;
       case 1:if(buffer[0]==0)
                        return 100;
              else
   return 200;
       break;
       case 2:if(buffer[0]==0)
                 return 300;
              else
   return -1;
       break;
       case 3:if(buffer[0]==0)
                        return 400;
                else
                        return 500;
         break;
       case 4:if(buffer[0]==0)
                        return 600;
                else
                        return 700;
         break;
       case 5:if(buffer[0]==0)
                        return 800;
                else
                        return 900;
         break;
       case 6:if(buffer[0]==0)
                        return 1000;
                else
                        return 1100;
         break;
       case 7:if(buffer[0]==0)
                        return 1200;
                else
                        return 1300;
         break;
    }
    return 0;
}
# 907 "Liofilizador Placa Mae.c"
void ShowSensorRealTimeHS(void)
     {
     char bb[3];
     char SlaveBoard;
     char canal;
     char tupla;
     int vp, vpicone;





     my_delay_ms(32);

     for(tupla=0;tupla<(totalboard*2);tupla++)
        {
        SlaveBoard = (tupla / 2)+1;
        canal = tupla % 2;
        bb[0]=canal;
        leitura[tupla]=Send_To_Slave(SlaveBoard, 0X1A, 1, bb);
# 936 "Liofilizador Placa Mae.c"
        flag_array_slave_WDT[SlaveBoard]=1;
        }



     my_delay_ms(50);
     statusgen1.flag_proculus_hs=1;
     for(tupla=0;tupla<(totalboard*2);tupla++)
        {
        switch(tupla)
              {
              case 0:
                     PROCULUS_VP_Write_UInt16(153,leitura[tupla]);
                     Voltimetro=leitura[tupla];
                     break;
              case 1:
                     PROCULUS_VP_Write_UInt16(151,leitura[tupla]);
                     Vacuometro=leitura[tupla];
                     break;
              case 2:
                     PROCULUS_VP_Write_UInt16(150,leitura[tupla]);
                     Condensador=leitura[tupla];
                     break;
              case 3:

                     break;
              default:
                  canal=tupla-4;
                  vp = 230+(canal*12);
                  vpicone = 400+canal;
                  PROCULUS_VP_Write_UInt16(vp+1,leitura[canal+4]);

                  if(leitura[canal+4]<-400)PROCULUS_VP_Write_UInt16(vpicone,1);
                  else if(leitura[canal+4]==-1)PROCULUS_VP_Write_UInt16(vpicone,0);
                  else PROCULUS_VP_Write_UInt16(vpicone,3);

                  break;
              }
        }
      statusgen1.flag_proculus_hs=0;

     }
# 987 "Liofilizador Placa Mae.c"
void Carrega_Tupla_Receita(char index, t_receita *receita){
     unsigned int addeeprom;

     addeeprom=256 +16*index;

     receita->setpoint=EEPROM_Read_Integer(addeeprom+0);
     receita->potenciaON=EEPROM_Read_Byte (addeeprom+2);
     receita->potenciaOFF=EEPROM_Read_Byte(addeeprom+3);
     receita->histerese=EEPROM_Read_Byte (addeeprom+4);
     EEPROM_Read_String(addeeprom+5,texto);
     strcpy(receita->nome,texto);
}

void Grava_Receita(char index, t_receita *receita){
     unsigned int addeeprom;
     unsigned int vp;

     addeeprom=256 +16*index;

     EEPROM_Write_Integer(addeeprom+0 ,receita->setpoint);
     EEPROM_Write_Byte (addeeprom+2 ,receita->potenciaON);
     EEPROM_Write_Byte (addeeprom+3 ,receita->potenciaOFF);
     EEPROM_Write_Byte (addeeprom+4 ,receita->histerese);
     EEPROM_Write_String (addeeprom+5 ,receita->nome);
}




void Exibe_Receita(int index){
     unsigned int addeeprom;
     unsigned int vp;

     addeeprom=256 +16*index;
     vp =420 +10*index;


     PROCULUS_VP_Write_UInt16(vp+0,EEPROM_Read_Integer(addeeprom));
     PROCULUS_VP_Write_UInt16(vp+1,EEPROM_Read_Byte(addeeprom+2));
     PROCULUS_VP_Write_UInt16(vp+2,EEPROM_Read_Byte(addeeprom+3));
     PROCULUS_VP_Write_UInt16(vp+3,EEPROM_Read_Byte(addeeprom+4));
     EEPROM_Read_String(addeeprom+5,texto);
     texto[8]=0;
     PROCULUS_VP_Write_String(vp+4,texto);
}
# 1050 "Liofilizador Placa Mae.c"
void DataBaseBackupMain(unsigned char tupla)
      {
      unsigned int vp;
      unsigned char addEEPROM;

      vp = 230+(tupla*12);
      addEEPROM = ((tupla)*18)+52;


      EEPROM_Write_Byte (addEEPROM+0 ,tupla);

      EEPROM_Write_Integer(addEEPROM+1 ,PROCULUS_VP_Read_UInt16(vp+2));
      EEPROM_Write_Byte (addEEPROM+3 ,PROCULUS_VP_Read_UInt16(vp+3));
      EEPROM_Write_Byte (addEEPROM+4 ,PROCULUS_VP_Read_UInt16(vp+4));
      EEPROM_Write_Byte (addEEPROM+5 ,PROCULUS_VP_Read_UInt16(vp+5));
      PROCULUS_VP_Read_String(vp+6,texto);
      EEPROM_Write_String (addEEPROM+6 ,texto);
      EEPROM_Write_Integer(addEEPROM+16,PROCULUS_VP_Read_UInt16(vp+11));

      }
# 1087 "Liofilizador Placa Mae.c"
 void SaveLiofilizadorOnMemory(char index,t_liofilizador *liofilizador)
      {
      char CanalAD;
      unsigned char addEEPROM;
      addEEPROM = (index*18)+52;
      CanalAD = (unsigned char) (index % 2);

      EEPROM_Write_Byte(addEEPROM+0,liofilizador->plataforma);

      EEPROM_Write_Integer(addEEPROM +1 , liofilizador->setpoint);
      EEPROM_Write_Byte(addEEPROM +3 , liofilizador->tempoON);
      EEPROM_Write_Byte(addEEPROM +4 , liofilizador->tempoOFF);
      EEPROM_Write_Byte(addEEPROM +5 , liofilizador->histerese);
      EEPROM_Write_String(addEEPROM +6 , liofilizador->receita);
      EEPROM_Write_Integer(addEEPROM +16 , liofilizador->status);
      }




 void Set_Receita(unsigned char index, char status)
      {
      int vp;
      unsigned int addEEPROM;

      addEEPROM = 256 +16*index;
      vp = 230+(index*12);

      PROCULUS_VP_Write_UInt16(vp+2,receita.setpoint);
      PROCULUS_VP_Write_UInt16(vp+3,receita.potenciaON);
      PROCULUS_VP_Write_UInt16(vp+4,receita.potenciaOFF);
      PROCULUS_VP_Write_UInt16(vp+5,receita.histerese);
      PROCULUS_VP_Write_String(vp+6,receita.nome);
      if(status==1)
         PROCULUS_VP_Write_UInt16(vp+11,1);
      else
         PROCULUS_VP_Write_UInt16(vp+11,0);
      }






 void ShowStaticValueGrid(unsigned char tupla)
      {
      char CanalAD;
      char SlaveBoard;
      int vp, vpicone;
      char bb[2];
      unsigned char addEEPROM;
      int temperatura;


      addEEPROM = (tupla*18)+52;
      CanalAD = (unsigned char) (tupla % 2);
      bb[0] = CanalAD;
      SlaveBoard = (unsigned char) (tupla / 2)+1;
      vp = 230+(tupla*12);


      if(tupla>=4){
         tupla-=4;
         addEEPROM = (tupla*18)+52;
         CanalAD = (unsigned char) (tupla % 2);
         bb[0] = CanalAD;
         SlaveBoard = (unsigned char) (tupla / 2)+1+2;
         vp = 230+(tupla*12);
         vpicone = 400+tupla;
         PROCULUS_VP_Write_UInt16(vp+0,EEPROM_Read_Byte (addEEPROM+0)+1);
         PROCULUS_VP_Write_UInt16(vp+2,EEPROM_Read_Integer (addEEPROM+1));
         PROCULUS_VP_Write_UInt16(vp+3,EEPROM_Read_Byte (addEEPROM+3));
         PROCULUS_VP_Write_UInt16(vp+4,EEPROM_Read_Byte (addEEPROM+4));
         PROCULUS_VP_Write_UInt16(vp+5,EEPROM_Read_Byte (addEEPROM+5));
         EEPROM_Read_String(addEEPROM+6,texto);
         PROCULUS_VP_Write_String(vp+6,texto);
         PROCULUS_VP_Write_UInt16(vp+11,EEPROM_Read_Integer(addEEPROM+16));
         }
}
# 1174 "Liofilizador Placa Mae.c"
void save_datalog(unsigned long add_datalog){
     char index;
     char bb[4];
     char boardadd;


     bb[0]=((char *)&add_datalog)[3];
     bb[1]=((char *)&add_datalog)[2];
     bb[2]=((char *)&add_datalog)[1];
     bb[3]=((char *)&add_datalog)[0];
     Send_To_Slave(0xFF, 0x02 , 4, bb);

     for(index=0;index<(totalboard*2);index++)
  {
         if(mapa.entrada[index]!=((void*)0))
            {
            PROCULUS_graphic_plot(mapa.canal[index]+1,*mapa.entrada[index]*mapa.fator[index]);
            }
         }
}
# 1203 "Liofilizador Placa Mae.c"
 void ShowAndSetSlaveParameters(unsigned char tupla)
      {
      unsigned char CanalAD;
      unsigned char SlaveBoard;
      unsigned char addEEPROM;
      unsigned int vp;
      unsigned char bb[2];


      vp = 230+(tupla*12);

      addEEPROM = (tupla*18)+52;
      CanalAD = (unsigned char) (tupla % 2);
      SlaveBoard = (unsigned char) (tupla / 2);

      bb[0] = CanalAD;
      PROCULUS_VP_Write_UInt16(vp+0,EEPROM_Read_Byte(addEEPROM+0));





      PROCULUS_VP_Write_UInt16(vp+2,EEPROM_Read_Integer(addEEPROM+1));
      PROCULUS_VP_Write_UInt16(vp+3,EEPROM_Read_Byte (addEEPROM+3));
      PROCULUS_VP_Write_UInt16(vp+4,EEPROM_Read_Byte (addEEPROM+4));
      PROCULUS_VP_Write_UInt16(vp+5,EEPROM_Read_Byte (addEEPROM+5));
      EEPROM_Read_String (addEEPROM+6,texto);
      PROCULUS_VP_Write_String(vp+6,texto);
      PROCULUS_VP_Write_UInt16(vp+11,EEPROM_Read_Integer(addEEPROM+16));

      }
# 1243 "Liofilizador Placa Mae.c"
void Send_to_PC(unsigned char size){


     USART_put_int(0xAABB);
     USART_putc(usart_protocol.destino);
     USART_putc(usart_protocol.origem);
     USART_putc(usart_protocol.command);
     USART_putc(size);
# 1261 "Liofilizador Placa Mae.c"
}




void Comando_Microcomputador(void){
     USART_to_Protocol(&usart_protocol);
     if(usart_protocol.header==0xAABB)
        if(usart_protocol.destino==0x00)
        {
        Decodify_Command();
        statusgen.flag_usart_rx=0;
        }
}





void Decodify_Command(void){
    int dados;
    char tempchar;
    int tempint;
    unsigned long add_24LCxxxx;

    ((char *)&add_24LCxxxx)[3]=(usart_protocol.value[1]);
    ((char *)&add_24LCxxxx)[2]=(usart_protocol.value[2]);
    ((char *)&add_24LCxxxx)[1]=(usart_protocol.value[3]);
    ((char *)&add_24LCxxxx)[0]=(usart_protocol.value[4]);

    switch(usart_protocol.command){
# 1323 "Liofilizador Placa Mae.c"
        case 0x08:
             EEPROM_Write_Byte((int)usart_protocol.value[0]<<8 |
                               (int)usart_protocol.value[1]<<0,
                               usart_protocol.value[2]
                               );
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case 0x09:
             tempchar=EEPROM_Read_Byte((int)usart_protocol.value[0]<<8 |
                                       (int)usart_protocol.value[1]<<0
                                       );
             Send_to_PC(1);
             USART_putc(tempchar);
             break;
        case 0x0A:
             {
             unsigned char add;
             add=usart_protocol.value[0];
             dados=(usart_protocol.value[1]<<8)|usart_protocol.value[2];
             EEPROM_Write_Integer(add,dados);
             Send_to_PC(3);
             SEND_REPLY_OK();
             }
             break;
        case 0x0B:
             tempint=EEPROM_Read_Integer(usart_protocol.value[0]);
             Send_to_PC(2);
             USART_put_int(tempint);
             break;

        case 0x0C :
             EEPROM_Write_String(usart_protocol.value[0],
                                &usart_protocol.value[1]);
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case 0x0D:
             {

             EEPROM_Read_String(usart_protocol.value[0],texto);
             Send_to_PC(sizeof(texto));
             USART_put_string(texto);
             break;
             }


        case 0x11:
             EEPROM_24C1025_Write_Byte(usart_protocol.value[0],
                                                  add_24LCxxxx,
                                      &usart_protocol.value[5]);
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case 0x12:
             tempchar=EEPROM_24C1025_Read_Byte(usart_protocol.value[0],
                                                         add_24LCxxxx);


             Send_to_PC(1);
             USART_putc(tempchar);
             break;
        case 0x13:
             {
             char valor[2];
             valor[0]=(usart_protocol.value[5]);
             valor[1]=(usart_protocol.value[6]);
             EEPROM_24C1025_Write_Int(usart_protocol.value[0],
                                                 add_24LCxxxx,
                                                       valor);
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
             }
        case 0x14:
             tempint=EEPROM_24C1025_Read_Int(usart_protocol.value[0],
                                                       add_24LCxxxx);
             Send_to_PC(2);
             USART_put_int(tempint);
             break;


        case 0x18:
             {
             char sizedata;
             sizedata=usart_protocol.value[5];
             EEPROM_24C1025_Read_Buffer(usart_protocol.value[0],
                                        add_24LCxxxx,
                                        sizedata,
                                        buffer);



             Send_to_PC(sizedata);
             USART_put_buffer(buffer,sizedata);
             }
             break;

        case 0x17:
             EEPROM_24C1025_Write_Buffer(usart_protocol.value[0],
                                         add_24LCxxxx,
                                         usart_protocol.value[5],
                                         &usart_protocol.value[6]);

             Send_to_PC(3);
             SEND_REPLY_OK();
             break;

        case 0x15 :
             EEPROM_24C1025_Write_Str(usart_protocol.value[0],
                                                 add_24LCxxxx,
                                    &usart_protocol.value[5]);
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case 0x16:
             {
             EEPROM_24C1025_Read_Str(usart_protocol.value[0],
                                                add_24LCxxxx,
                                                      texto);

             Send_to_PC(strlen(texto));
             USART_put_string(texto);
             break;
             }

        case 0x19:
             EEPROM_24C1025_Fill_All(usart_protocol.value[0],
                                     usart_protocol.value[1]);
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
# 1538 "Liofilizador Placa Mae.c"
        case 0X21:
             PROCULUS_Buzzer((usart_protocol.value[0]<<8)+
                             (usart_protocol.value[1]));
             Send_to_PC(3);
             SEND_REPLY_OK();
# 1585 "Liofilizador Placa Mae.c"
    }
}

void SEND_REPLY_OK(void){
     USART_put_string("OK");
}


void Comando_Protocolo_Serial(void){

        unsigned char size, i, OrigemMemo;

        USART_to_Protocol(&usart_protocol);
        if(usart_protocol.header==0xAABB)
            {
            if(usart_protocol.origem==0xC0)
                {
                Delay_Led_Usart=5;
                if(usart_protocol.destino==0x00)
                   {
                   Decodify_Command();
                   statusgen.flag_usart_rx=0;
                   }
                else
                   {




                   OrigemMemo=usart_protocol.origem;
                   Send_To_Slave(usart_protocol.destino,
                                 usart_protocol.command,
                                 usart_protocol.size,
                                 usart_protocol.value
                                 );
                   statusgen.flag_usart_rx=0;







                   USART_to_Protocol(&usart_protocol);
                   USART_put_int(0xAABB);
                   USART_putc(usart_protocol.origem);
                   USART_putc(OrigemMemo);
                   USART_putc(usart_protocol.command);
                   USART_putc(usart_protocol.size);
                   for(i=0;i<usart_protocol.size;i++)
                         USART_putc(usart_protocol.value[i]);

                   statusgen.flag_usart_rx=0;
                   }
                }
        statusgen.flag_usart_rx=0;
        }
}


void Formatar_Banco_de_Dados(char inicio, char total){
     for(char j=inicio;j<(inicio+total);j++)
          {

          liofilizador[j].plataforma=j;
          liofilizador[j].setpoint=0;
          liofilizador[j].tempoON=0;
          liofilizador[j].tempoOFF=0;
          liofilizador[j].histerese=0;
          strcpy(liofilizador[j].receita,"");
          liofilizador[j].status=0;
          SaveLiofilizadorOnMemory(j,&liofilizador[j]);
          }

}



void Upload_Data_to_Slave(void){
     char index;
     char board;
     char canal;
     char addEEPROM;
     char buffer[3];
     int temp;


     for(index=4;index<15;index++){
         board=(index/2)+1;
         canal=(index%2);
         addEEPROM = ((index-4)*18)+52;





         temp=EEPROM_Read_Integer(addEEPROM+1);
         buffer[0]=(canal*7)+0;
         buffer[1]=((char *)&temp)[1];
         buffer[2]=((char *)&temp)[0];
         Send_To_Slave(board,0x0A,3,buffer);
         _delay((unsigned long)((150)*(32000000/4000.0)));

         buffer[0]=(canal*7)+2;
         buffer[1]=EEPROM_Read_Byte(addEEPROM+3);
         Send_To_Slave(board,0x08,2,buffer);
         _delay((unsigned long)((150)*(32000000/4000.0)));

         buffer[0]=(canal*7)+3;
         buffer[1]=EEPROM_Read_Byte(addEEPROM+4);
         Send_To_Slave(board,0x08,2,buffer);
         _delay((unsigned long)((150)*(32000000/4000.0)));

         buffer[0]=(canal*7)+4;
         buffer[1]=EEPROM_Read_Byte(addEEPROM+5);
         Send_To_Slave(board,0x08,2,buffer);
         _delay((unsigned long)((150)*(32000000/4000.0)));

         temp=EEPROM_Read_Integer(addEEPROM+16);
         buffer[0]=(canal*7)+5;
         buffer[1]=((char *)&temp)[1];
         buffer[2]=((char *)&temp)[0];
         Send_To_Slave(board,0x0A,3,buffer);
         _delay((unsigned long)((150)*(32000000/4000.0)));
         if(canal==1) Send_To_Slave(board,0x01,0,buffer);

         }

}



void ShowMessage(char mensagem[20],unsigned int delay, char SoundType, char retem){
     char texto[30];


     strcpy(texto,"                             ");
     texto[(30-strlen(mensagem))/2]=0;
     strcat(texto,mensagem);
     PROCULUS_VP_Write_String(180,texto);
     my_delay_ms(delay);
     if(!retem) PROCULUS_VP_Write_String(180,"");
}


void global_datalog(void){
        if((PROCULUS_VP_Read_UInt16(2)==1)&&(statuspower.flag_global_datalog==0))
           {
            char bb[2];
            Send_To_Slave(0xFF, 0x00 , 0, bb);
            Carregar_tempo_de_datalog();
            statuspower.flag_global_datalog=1;
           }
        else if((PROCULUS_VP_Read_UInt16(2)==0)&&(statuspower.flag_global_datalog==1))
               {

               statuspower.flag_global_datalog=0;
               }
}




void Condensador_Switch(unsigned char estado){
     char buffer[2];
     buffer[0]=0;
     buffer[1]=estado;
     Send_To_Slave(0x02,0x26,2,buffer);
}

void Vaccum_Switch(unsigned char estado){
     char buffer[2];
     buffer[0]=0;
     buffer[1]=estado;
     Send_To_Slave(0x01,0x26,2,buffer);
}


void global_condensador(void){
        if((PROCULUS_VP_Read_UInt16(0x03)==1)&&(statuspower.flag_global_condensador==0))
            {
            if(delay_condensador==0)
               {
               statuspower.flag_global_condensador=1;
               Condensador_Switch(1);
               }
            else
               {
               PROCULUS_Buzzer(1000);
               PROCULUS_VP_Write_UInt16(0x03,0);
               }
            }
        if((PROCULUS_VP_Read_UInt16(0x03)==0)&&(statuspower.flag_global_condensador==1))
           {
           statuspower.flag_global_condensador=0;
           Condensador_Switch(0);
           delay_condensador=30;
           }
}




void global_vacuo(void){
        if((PROCULUS_VP_Read_UInt16(0x04)==1)&&(statuspower.flag_global_vacuo==0))
           {
           statuspower.flag_global_vacuo=1;
           if(Condensador<Seg_Condensador)
              {
              Vaccum_Switch(1);
              Contagem_Tempo_de_Processo(1);
              }
           else
              {
              Vaccum_Switch(0);
              Incrementa_Contador_de_Repique_do_Vacuo();
              }
           }
        else if((PROCULUS_VP_Read_UInt16(0x04)==0)&&(statuspower.flag_global_vacuo==1))
                {
                statuspower.flag_global_vacuo=0;
                Vaccum_Switch(0);
                PROCULUS_VP_Write_UInt16(6,0);

                PROCULUS_Popup(0x42);
                PROCULUS_VP_Write_UInt16(0x0016,0);
                for(int i=0;i<10000;i++)
                     {
                     my_delay_ms(1);
                     if (PROCULUS_VP_Read_UInt16(6)!=0) break;
                     __asm("CLRWDT");
                     }

                if(PROCULUS_VP_Read_UInt16(6)==241)
                     {
                     Contagem_Tempo_de_Processo(0);
                     processo_hora=0;
                     processo_minuto=0;
                     PROCULUS_OK();
                     }


                }
        else if((PROCULUS_VP_Read_UInt16(0x04)==1)&&(statuspower.flag_global_vacuo==1))
                {
                if(Condensador<Seg_Condensador)
                   {
                   Vaccum_Switch(1);
                   statusgen1.flag_Vacuo_estava_ligado=1;
                   }
                else
                   {
                   Vaccum_Switch(0);
                   Incrementa_Contador_de_Repique_do_Vacuo();
                   }
                }
}


void Global_Aquecimento_Switch(unsigned char estado){
     char buffer[2];
     unsigned char board;
     for(board=3;board<(totalboard*2-1);board++)
        {

        buffer[0]=estado;
        Send_To_Slave(board,0x2A,1,buffer);
        }
}


void global_aquecimento(void){
        if((PROCULUS_VP_Read_UInt16(5)==1)&&(statuspower.flag_global_aquecimento==0))
           {
           if((Condensador<Seg_Aq_cond)&&(Vacuometro<Seg_Aq_vacuo))
                     {
                     statuspower.flag_global_aquecimento=1;
                     Global_Aquecimento_Switch(1);
                     }
           }
        if((PROCULUS_VP_Read_UInt16(5)==0)&&(statuspower.flag_global_aquecimento==1))
           {
           Global_Aquecimento_Switch(0);
           statuspower.flag_global_aquecimento=0;
           PROCULUS_VP_Write_String(1970,"");
           }
        else if ((PROCULUS_VP_Read_UInt16(5)==1)&&(statuspower.flag_global_aquecimento==1))
           {
           if((Condensador>Seg_Aq_cond)||(Vacuometro>Seg_Aq_vacuo))
              {
              statuspower.flag_global_aquecimento=0;


              Global_Aquecimento_Switch(0);

              }
           }

}






void Comando_Display(void){
unsigned char i;

  PROCULUS_Buffer_to_Proculus(&proculus);
  if(proculus.header==0x5AA5)
     {
     statusgen.flag_usart_rx=0;
     if(proculus.page==0x15) pagina_15();
     if(proculus.page==0x19) pagina_19();
     if(proculus.page==0x23) pagina_23();
     if(proculus.page==0x25) pagina_25();
     if(proculus.page==0x29) pagina_29();
     if(proculus.page==0x31) pagina_31();
     if(proculus.page==0x47) pagina_47();
     if(proculus.page==0x49) pagina_49();
     proculus.header=0;
     }
}


void pagina_49(void){
     t_liofilizador liofilizador;

     if(PROCULUS_VP_Read_UInt16(390)==1)
                   {

                   receita.setpoint=0;
                   receita.potenciaON=0;
                   receita.potenciaOFF=0;
                   receita.histerese=0;
                   strcpy(receita.nome,"");
                   Grava_Receita(Index_Receita, &receita);
                   Exibe_Receita(Index_Receita);

                   PROCULUS_VP_Write_UInt16(410,0);
                   PROCULUS_VP_Write_UInt16(411,0);
                   PROCULUS_VP_Write_UInt16(412,0);
                   PROCULUS_VP_Write_UInt16(413,0);
                   PROCULUS_VP_Write_String(414,"");

                   Atualizar_Lista_de_Receitas();
                   PROCULUS_VP_Write_UInt16(390,0);

                   PROCULUS_Popup(0x60);
                   PROCULUS_OK();
                   PROCULUS_VP_Write_String(1910,"Item Excluido com sucesso!");
                   my_delay_ms(1500);
                   PROCULUS_VP_Write_String(1910,"");
                   }




     if(PROCULUS_VP_Read_UInt16(391)==1)
                   {

                   receita.setpoint=PROCULUS_VP_Read_UInt16(410);
                   receita.potenciaON=PROCULUS_VP_Read_UInt16(411);
                   receita.potenciaOFF=PROCULUS_VP_Read_UInt16(412);
                   receita.histerese=PROCULUS_VP_Read_UInt16(413);
                   PROCULUS_VP_Read_String(414,receita.nome);
                   Grava_Receita(Index_Receita, &receita);


                   Atualizar_Lista_de_Receitas();
                   PROCULUS_VP_Write_UInt16(391,0);

                   PROCULUS_Popup(0x51);
                   PROCULUS_OK();
                   PROCULUS_VP_Write_String(1910,"Dados Gravados com sucesso!");
                   my_delay_ms(1500);
                   PROCULUS_VP_Write_String(1910,"");
                   }


     if(PROCULUS_VP_Read_UInt16(392)==1)
                   {

                   PROCULUS_VP_Write_String(1910,"Aguarde... Carregando Dados!");
                   Carrega_Tupla_Receita(Index_Receita, &receita);
                   PROCULUS_VP_Write_String(1910,"Aguarde... Armazenando Dados!");
                   for(char i=0;i<(totalboard-2)*2;i++)
                       {

                       liofilizador.plataforma=i;
                       liofilizador.setpoint=receita.setpoint;
                       liofilizador.tempoON=receita.potenciaON;
                       liofilizador.tempoOFF=receita.potenciaOFF;
                       liofilizador.histerese=receita.histerese;
                       strcpy(liofilizador.receita,receita.nome);
                       liofilizador.status=1;
                       SaveLiofilizadorOnMemory(i,&liofilizador);
                       }
                   PROCULUS_VP_Write_String(1910,"Aguarde... Transferindo dados para placas externas!");
                   Upload_Data_to_Slave();
                   PROCULUS_VP_Write_String(1910,"Aguarde... Atualizando Tabela!");
                   for(char i=0;i<15;i++)ShowStaticValueGrid(i);
                   for(char i=0;i<10;i++)ShowAndSetSlaveParameters(i);


                   PROCULUS_VP_Write_UInt16(392,0);
                   PROCULUS_Popup(0x60);
                   PROCULUS_OK();
                   PROCULUS_VP_Write_String(1910,"");
                   }

     if(PROCULUS_VP_Read_UInt16(393)==1)
                   {
                   PROCULUS_VP_Write_UInt16(393,0);
                   PROCULUS_Show_Screen(47);
                   }

}


void pagina_47(void){
     t_receita receita;
     if(flag_senha_liberada)
         {
         PROCULUS_Show_Screen(49);

         Carrega_Tupla_Receita(Index_Receita, &receita);

         PROCULUS_VP_Write_UInt16(410,receita.setpoint);
         PROCULUS_VP_Write_UInt16(411,receita.potenciaON);
         PROCULUS_VP_Write_UInt16(412,receita.potenciaOFF);
         PROCULUS_VP_Write_UInt16(413,receita.histerese);
         PROCULUS_VP_Write_String(414,receita.nome);
         }
     else
         {
         PROCULUS_Popup(0x52);
         PROCULUS_NOK();
         }



}






void pagina_15(void){
   if(proculus.button==3)
      {
      PROCULUS_Buzzer(2000);
      }

   if(proculus.button==2)
      {
      if(proculus.status==0){


         PORTDbits.RD2=1;
          }
      }


   if (proculus.button==5)
      {
      if(proculus.status==1)
         {



         maincnt=0;
         }
     }

}



void pagina_19(void)
{

       if(PROCULUS_VP_Read_UInt16(168)==1)
         {
         PROCULUS_VP_Write_UInt16(168,0);
         if(flag_senha_liberada)
            {
            for(char i=0;i<15;i++)
                {

                ShowStaticValueGrid(i);
                }
            PROCULUS_OK();
            }
         else
            {
            PROCULUS_Popup(0x52);
            PROCULUS_NOK();
            }
         }




       if(PROCULUS_VP_Read_UInt16(167)==1)
         {
         PROCULUS_VP_Write_UInt16(167,0);
         if(flag_senha_liberada)
            {
             ShowMessage("Gravando Dados, Aguarde!",2000,0,1);
             for(char i=0;i<10;i++)
                 {

                 DataBaseBackupMain(i);
                 }
             ShowMessage("SUCESSO!!!",2000,1,0);
             PROCULUS_OK();
            }
         else
            {
            PROCULUS_Popup(0x52);
            PROCULUS_NOK();
            }
         }



       if(PROCULUS_VP_Read_UInt16(166)==1)
         {
         PROCULUS_VP_Write_UInt16(166,0);
         if(flag_senha_liberada)
            {
             ShowMessage("Descarregando Dados",2000,0,1);
             Upload_Data_to_Slave();
             ShowMessage("SUCESSO!!!",2000,1,0);
             PROCULUS_OK();
            }
         else
            {
            PROCULUS_Popup(0x52);
            PROCULUS_NOK();
            }
         }





       if(PROCULUS_VP_Read_UInt16(169)==1)
         {
         PROCULUS_VP_Write_UInt16(169,0);
         if(flag_senha_liberada)
            {
             char inicio;
             ShowMessage("Formatando",2000,0,1);

             if(pagina==19)inicio=0;
             if(pagina==21)inicio=5;


             Formatar_Banco_de_Dados(inicio,5);
             for(char i=0;i<15;i++)
                 {

                 ShowStaticValueGrid(i);
                 }
             PROCULUS_OK();
             ShowMessage("SUCESSO!",2000,1,0);
            }
         else
            {
            PROCULUS_Popup(0x52);
            PROCULUS_NOK();
            }
         }

}



void pagina_23(void)
{
    if(flag_senha_liberada)
      {
        Seg_Condensador=PROCULUS_VP_Read_UInt16(210);
        Seg_Vacuo=PROCULUS_VP_Read_UInt16(211);
        Seg_Aq_cond=PROCULUS_VP_Read_UInt16(212);
        Seg_Aq_vacuo=PROCULUS_VP_Read_UInt16(213);
        Tamanho_Display=PROCULUS_VP_Read_UInt16(214);

        EEPROM_Write_Integer(0x01,Seg_Condensador);
        EEPROM_Write_Integer(0x03,Seg_Vacuo);
        EEPROM_Write_Integer(0x05,Seg_Aq_cond);
        EEPROM_Write_Integer(0x07,Seg_Aq_vacuo);
        EEPROM_Write_Integer(0xFA,Tamanho_Display);
        TrendCurveFuncao(1);

        PROCULUS_Popup(0x51);
        PROCULUS_OK();
        Carregar_Parametros_de_Seguranca();

     }
    else
     {
     PROCULUS_Popup(0x52);
     PROCULUS_NOK();
     }
}
# 2202 "Liofilizador Placa Mae.c"
void pagina_25(void)
{

    if(flag_senha_liberada)
       {
       char date[10];
       char time[10];
       PROCULUS_VP_Read_String(20,date);
       PROCULUS_VP_Read_String(30,time);
       PROCULUS_Write_RTC(date,time);
       PROCULUS_Popup(0x51);
       PROCULUS_OK();
       }
    else
       {
       PROCULUS_Popup(0x52);
       PROCULUS_NOK();
       }

}




void pagina_29(void)
  {
    if(flag_senha_liberada)
         {
          EEPROM_Write_Integer(0x09,PROCULUS_VP_Read_UInt16(172));
          Carregar_tempo_de_datalog();
          PROCULUS_Popup(0x51);
          PROCULUS_OK();
         }
     else
         {
         PROCULUS_Popup(0x52);
         PROCULUS_NOK();
         }
  }



void pagina_31(void){
         unsigned long nova_senha, confirma_senha;
         char senhavetor[4];

         nova_senha =PROCULUS_VP_Read_Double32(382);
         confirma_senha=PROCULUS_VP_Read_Double32(384);


         PROCULUS_VP_Read(380,senhavetor,4);
         senha_atual=((unsigned long)senhavetor[0]<<24)+
                     ((unsigned long)senhavetor[1]<<16)+
                     ((unsigned long)senhavetor[2]<< 8)+
                     ((unsigned long)senhavetor[3]<< 0);

         PROCULUS_VP_Read(382,senhavetor,4);
         nova_senha =((unsigned long)senhavetor[0]<<24)+
                     ((unsigned long)senhavetor[1]<<16)+
                     ((unsigned long)senhavetor[2]<< 8)+
                     ((unsigned long)senhavetor[3]<< 0);


         PROCULUS_VP_Read(384,senhavetor,4);
         confirma_senha=((unsigned long)senhavetor[0]<<24)+
                        ((unsigned long)senhavetor[1]<<16)+
                        ((unsigned long)senhavetor[2]<< 8)+
                        ((unsigned long)senhavetor[3]<< 0);



         if((senha_atual==0) ||
            (nova_senha ==0) ||
            (confirma_senha==0))
            {

            PROCULUS_Popup(0x23) ;
            }
         else
         if(senha_atual==EEPROM_Read_Long32(11))
            {
            if(nova_senha==confirma_senha)
               {
               EEPROM_Write_Long32(11,nova_senha) ;
               senha_atual=nova_senha;
               Gravar_Status_da_Senha_Global();
               PROCULUS_VP_Write_Long32(380,0);
               PROCULUS_VP_Write_Long32(382,0);
               PROCULUS_VP_Write_Long32(384,0);
               PROCULUS_Popup(0x22) ;
               }
            else
               {

               PROCULUS_Popup(0X21) ;
               }
            }
         else
            {


            PROCULUS_Popup(0X20) ;
            }

}



void Exibe_Hora_Data(char showseconds){
     char date[10];
     char time[10];

     PROCULUS_Read_RTC(date,time);
     if(showseconds==0) time[5]=0;
     PROCULUS_VP_Write_String(20,date);
     PROCULUS_VP_Write_String(30,time);
}







void Inicializar_Seguranca(void){
     Seg_Condensador=EEPROM_Read_Integer(0x01);
     Seg_Vacuo=EEPROM_Read_Integer(0x03);
     Seg_Aq_cond=EEPROM_Read_Integer(0x05);
     Seg_Aq_vacuo=EEPROM_Read_Integer(0x07);
     PROCULUS_VP_Write_UInt16(210,Seg_Condensador);
     PROCULUS_VP_Write_UInt16(211,Seg_Vacuo);
     PROCULUS_VP_Write_UInt16(212,Seg_Aq_cond);
     PROCULUS_VP_Write_UInt16(213,Seg_Aq_vacuo);
}





void Check_And_Send_Capture_Datalog(void){
     if(statuspower.flag_global_datalog==1)
       {
       if(statusgen.flag_capture_datalog==1)
         {
         statusgen.flag_capture_datalog=0;
         _delay((unsigned long)((25)*(32000000/4000.0)));
         save_datalog(add_datalog);
         add_datalog+=2;


         }
       }
}
# 2363 "Liofilizador Placa Mae.c"
void Contagem_Tempo_de_Processo(char value){
    if(value)
      {
      if(statuspower.flag_time_process==0)
         {
         processo_minuto=0;
         processo_hora=0;
         }
      PROCULUS_VP_Write_String(1970,"Executando Processo...");
      statuspower.flag_time_process=1;

      }
    else
      {
      PROCULUS_VP_Write_String(1970,"");
      statuspower.flag_time_process=0;
      rtc.milisegundo=725;

      }

}

void SaveBlackoutStatusRuning(void){
     if(processo_minuto%10==0)
       {
       if(statusgen1.flag_save_time==0)
          {
          statusgen1.flag_save_time=1;
          PROCULUS_OK();
          EEPROM_Write_Byte(17,processo_hora);
          EEPROM_Write_Byte(18,processo_minuto);
          }
       }
     else
       {
       statusgen1.flag_save_time=0;
       }
}


void SaveBlackoutStatus(void){
     EEPROM_Write_Byte(16,statuspower.bits);
     EEPROM_Write_Byte(17,processo_hora);
     EEPROM_Write_Byte(18,processo_minuto);
}




void RecallBlackoutStatus(void){
     statuspower.bits=EEPROM_Read_Byte(16);
     processo_hora=EEPROM_Read_Byte(17);
     processo_minuto=EEPROM_Read_Byte(18);

     if(statuspower.flag_global_datalog) PROCULUS_VP_Write_UInt16(2,1);
     if(statuspower.flag_global_condensador) PROCULUS_VP_Write_UInt16(3,1);
     if(statuspower.flag_global_vacuo) PROCULUS_VP_Write_UInt16(4,1);
     if(statuspower.flag_global_aquecimento) PROCULUS_VP_Write_UInt16(5,1);


     statuspower.flag_global_datalog=0;
     statuspower.flag_global_condensador=0;
     statuspower.flag_global_vacuo=0;
     statuspower.flag_global_aquecimento=0;
}





void Carregar_tempo_de_datalog(void){
     tempocapturaconstante=(EEPROM_Read_Integer(0x09)*1000);
     tempocaptura=tempocapturaconstante;
}


void Gerenciador_de_Senha(void){
     unsigned long senha;

    PROCULUS_VP_Read(155,senhavetor,4);
    senha=((unsigned long)senhavetor[0]<<24)+
          ((unsigned long)senhavetor[1]<<16)+
          ((unsigned long)senhavetor[2]<< 8)+
          ((unsigned long)senhavetor[3]<< 0);


    if(senha!=0)
        {
        if(senha==senha_atual)
           {
           senha=0;
           senhacount=30000;
           flag_senha_liberada=1;
           PROCULUS_VP_Write_UInt16(154,1);
           PROCULUS_VP_Write_UInt16(155,0);
           PROCULUS_VP_Write_UInt16(156,0);
           PROCULUS_OK();
           }
        }


    if((flag_senha_liberada==1)&&(senhacount<0))
        {
        flag_senha_liberada=0;
        PROCULUS_VP_Write_UInt16(154,0);
        PROCULUS_NOK();
        }


    if(PROCULUS_TPFLAG_Read()==0x5A)
       {
       senhacount=30000;
       PROCULUS_TPFLAG_Write(0);
       }

}




void Gerenciador_de_Senha_Global(void){
     unsigned long senha;

    PROCULUS_VP_Read(179,senhavetor,4);
    senha=((unsigned long)senhavetor[0]<<24)+
          ((unsigned long)senhavetor[1]<<16)+
          ((unsigned long)senhavetor[2]<< 8)+
          ((unsigned long)senhavetor[3]<< 0);


    if(senha!=0)
        {
        if(senha==senha_atual)
           {
           senha=0;
           PROCULUS_VP_Write_Long32(179,0);
           if(PROCULUS_VP_Read_UInt16(178)==1)
              {
              flag_senha_global_liberada=0;
              flag_senha_liberada=0;
              senhacount=-1;
              PROCULUS_VP_Write_UInt16(178,0);
              PROCULUS_VP_Write_UInt16(154,0);
              }
           else if(PROCULUS_VP_Read_UInt16(178)==0)
              {
              flag_senha_global_liberada=1;
              flag_senha_liberada=1;
              senhacount=10;
              PROCULUS_VP_Write_UInt16(178,1);
              PROCULUS_VP_Write_UInt16(154,1);
              }
           Gravar_Status_da_Senha_Global();
           PROCULUS_OK();
           }
        }

}




void Icones_de_alarmes(void){

     if (Condensador<Seg_Condensador)
         PROCULUS_VP_Write_UInt16(176,1);
     else
         PROCULUS_VP_Write_UInt16(176,0);

     if (Vacuometro<Seg_Vacuo)
         PROCULUS_VP_Write_UInt16(177,1);
     else
         PROCULUS_VP_Write_UInt16(177,0);

}

void Formatar_Lista_de_Receitas(void){
     t_receita receita;
     for(char i=0;i<8;i++)
        {

        receita.setpoint=0;
        receita.potenciaON=0;
        receita.potenciaOFF=0;
        receita.histerese=0;
        strcpy(receita.nome,"");
        Grava_Receita(i, &receita);
        }
}

void Carregar_Parametros_de_Seguranca(void){
     Seg_Condensador=EEPROM_Read_Integer(0x01);
     Seg_Vacuo=EEPROM_Read_Integer(0x03);
     Seg_Aq_cond=EEPROM_Read_Integer(0x05);
     Seg_Aq_vacuo=EEPROM_Read_Integer(0x07);
     PROCULUS_VP_Write_UInt16(210,Seg_Condensador);
     PROCULUS_VP_Write_UInt16(211,Seg_Vacuo);
     PROCULUS_VP_Write_UInt16(212,Seg_Aq_cond);
     PROCULUS_VP_Write_UInt16(213,Seg_Aq_vacuo);

     PROCULUS_VP_Write_UInt16(172,EEPROM_Read_Integer(0x09));
}

void Formatar_Dados_de_Seguranca(void){
     EEPROM_Write_Integer(0x01,-150);
     EEPROM_Write_Integer(0x03,10000);
     EEPROM_Write_Integer(0x05,-150);
     EEPROM_Write_Integer(0x07,8000);
     EEPROM_Write_Integer(0xFA,50);
}

void Carregar_Status_da_Senha_Global(void){
     flag_senha_global_liberada=EEPROM_Read_Byte(15);
     if(flag_senha_global_liberada)
        {
        PROCULUS_VP_Write_UInt16(178,1);
        flag_senha_liberada=1;
        senhacount=10;
        PROCULUS_VP_Write_UInt16(154,1);
        }
     else
        {
        PROCULUS_VP_Write_UInt16(178,0);
        flag_senha_liberada=0;
        senhacount=-1;
        PROCULUS_VP_Write_UInt16(154,0);
        }
}

void Gravar_Status_da_Senha_Global(void){
     EEPROM_Write_Byte(15,flag_senha_global_liberada);
}


void Formatar_Datalog(void){
    int i;
    for(i=500;i<=720;i+=20)
       {

       PROCULUS_VP_Write_String(i,"");
       PROCULUS_VP_Write_String(i+3,"");
       PROCULUS_VP_Write_String(i+13,"");
       }
}



int Tupla_Log_Free(void){
    int i;
    for(i=500;i<=720;i+=20)
        {
        PROCULUS_VP_Read_String(i,texto);
        if(strlen(texto)==0) break;
        my_delay_ms_CLRWDT(500);
        }
    return i;
}


void Write_Fat(char value){
     char date[10];
     char time[10];
     char index;
     unsigned long add_memo;


     PROCULUS_Read_RTC(date,time);
     if(value==1)
       {
       strcpy(processo.inicio.date,date);
       strcpy(processo.inicio.time,time);
       processo.pontos=0;
       }
     else
       {
       strcpy(processo.fim.date,date);
       strcpy(processo.fim.time,time);
       processo.amostra=EEPROM_Read_Integer(0x09);


       for(index=0;index<9; index++)
           {

           add_memo=index*(sizeof(t_fat)+1);
           if(EEPROM_24C1025_Read_Byte(0,add_memo)==0xFF)
              {
              processo.start_add=add_memo;
              processo.end_add=add_memo+processo.pontos;
              }
           }


       }
}


void Memo2Graphic(char SlaveBoardAdd, char chipNumber, int add_24C1025, char LCDchannel){
     char bb[3];
     int value;

     bb[0]=chipNumber;
     bb[1]=((char *)&add_24C1025)[1];
     bb[2]=((char *)&add_24C1025)[0];

     value=Send_To_Slave(SlaveBoardAdd, 0x14, 3, bb);


     PROCULUS_graphic_plot(LCDchannel, value);
}



void Buffer_Manager(void)
     {
     char i;
     if(statusgen.flag_usart_rx==0)
         {
         for(i=6;i>0;i--)
           {

           if(usart_buffer_fila[i-1][0]!=0)
              {
              for(char j=0;j<74;j++)
                  {

                  usart_buffer[j]=usart_buffer_fila[i-1][j];
                  }
              usart_buffer_fila[i-1][0]=0;
              statusgen.flag_usart_rx=1;
              MonitorBuffer=i-1;
              break;
              }
           }
         }
}







unsigned int Captura_Pagina(void){
    unsigned int pagina[5];
    unsigned int retorno=0;

    while(retorno==0)
       {

       for(char i=0;i<5;i++)
          pagina[i]=PROCULUS_Get_Page();

          retorno=pagina[0];
          for(char i=1;i<5;i++)
             {
             if(pagina[0]!=pagina[i])
                {
                retorno=0;
                break;
                }
             }
       }
    return retorno;
}


_Bool memory_test(char board, char chip, int value, int inicialadd, int finaladd)
     {
     char txt[30];
     char bb[5];
     int salva=0;
     int ler=0;

     strcpy(texto,"BOARD =");
     itoa(board,txt,16);
     strcat(texto,txt);
     print(texto);



             for(int add=inicialadd; add<=finaladd; add++)
                {

                bb[0]=chip;
                bb[1]=((char *)&add)[1];
                bb[2]=((char *)&add)[0];
                bb[3]=((char *)&salva)[1];
                bb[4]=((char *)&salva)[0];
                Send_To_Slave(board, 0x13, 5, bb);

                bb[0]=chip;
                bb[1]=((char *)&add)[1];
                bb[2]=((char *)&add)[0];
                ler=Send_To_Slave(board, 0x14, 3, bb);


                strcpy(texto,"W 0x");
                itoa(add,txt,16);
                strcat(texto,txt);
                strcpy(txt," = ");
                strcat(texto,txt);
                itoa(value,txt,10);
                strcat(texto,txt);


                if(salva==ler)
                   {
                   strcpy(txt," Iguais.");
                   }
                else
                   {
                   strcpy(txt," diferentes.");

                   }
                strcat(texto,txt);
                print(texto);
                value++;
                }
     return 1;
     }



char menorValorDisponivel(char * trendCurve){
     unsigned char icone;
     char i,j,p;

      icone=0;
      for(p=1;p<14;p++)
         {
         trendExist=0;
         for(i=1;i<14;i++)
            {
            for(j=i;j<14;j++)
               {

               if(trendCurve[j]==p)
                  {
                  trendExist=1;
                  break;
                  }
               }
            if(trendExist==1)
               {
               break;
               }
            }
         if(trendExist==0)
           {
           icone=p;
           break;
            }
         }

     return icone;
}



void Exibe_Tempo_de_Processo(void){
     if(statuspower.flag_time_process)
       {
       char temp0,temp1;

       temp0=processo_hora/10;
       temp1=processo_hora%10;
       PROCULUS_VP_Write_UInt16(40,temp0);
       PROCULUS_VP_Write_UInt16(41,temp1);

       PROCULUS_VP_Write_UInt16(42,1);

       temp0=processo_minuto/10;
       temp1=processo_minuto%10;
       PROCULUS_VP_Write_UInt16(43,temp0);
       PROCULUS_VP_Write_UInt16(44,temp1);
       }
}



void Atualizar_Lista_de_Receitas(void){
     for(char i=0;i<8;i++)
        {

        Exibe_Receita(i);
        }
}





void TrendCurveFuncao(char funcao){
     char figura;
     char canal;
     int cor;
     char i, index;
     Carregar_Display_Schematic_Color();
     switch(funcao)
           {
           case 0:
                       for(i=0;i<13;i++)
                          {
                          mapa.cor[i]=0xFFFF;
        mapa.canal[i]=0x0A;
        mapa.icone[i]=-1;
                          mapa.vpIcone[i]=-1;
                          mapa.entrada[i]=((void*)0);
                          mapa.fator[i]=0;

                          EEPROM_Write_Byte(19+i,mapa.vpIcone[i]);
                          EEPROM_Write_Byte(0xEA+i,mapa.icone[i]);
                          EEPROM_Write_Byte(36+i,mapa.canal[i]);

                          PROCULUS_VP_Write_UInt16(0x0310+i,-1);
                          PROCULUS_VP_Write_UInt16((i*10+1789),0x0A00);
                          PROCULUS_VP_Write_UInt16((i*10+1787),0xFFFF);
                          }
                       break;
           case 1:

                       EEPROM_Read_Buffer(19,mapa.vpIcone,15);
                       EEPROM_Read_Buffer(0xEA,mapa.icone,15);
                       EEPROM_Read_Buffer(36,mapa.canal,15);




                       for(i=0;i<13;i++)
                          {
                          figura=mapa.vpIcone[i];
                          if(figura!=255)
                             {
                             PROCULUS_VP_Write_UInt16(0x0310+i, figura);
                             }
                          else
                            {
                            PROCULUS_VP_Write_UInt16(0x0310+i,-1);
                            }
                          }


                       for(i=0;i<13;i++)
                          {
                          if(mapa.canal[i]<8)
                             {
        cor=TrendColor[mapa.icone[i]-1];
        }
     else
        {
        cor=0xFFFF;
        }
     PROCULUS_VP_Write_UInt16((i*10+1787),cor);
     mapa.cor[i]=cor;
     }


                       for(i=0;i<13;i++)
                          {
                          canal=mapa.canal[i];
     if((canal>=0)&&(canal<=7))
        {
                             PROCULUS_VP_Write_UInt16((i*10+1789),(canal<<8)|(0x0001));
               }
     else
               {
                             PROCULUS_VP_Write_UInt16((i*10+1789),0x0A00);
        }
     }




                          for(index=0;index<8;index++)
                              {
                              if(mapa.canal[index]!=0x0A)
                                 {
                                 mapa.entrada[mapa.canal[index]]=&leitura[(mapa.icone[mapa.canal[index]]-1<3)?(mapa.icone[mapa.canal[index]]-1):((mapa.icone[mapa.canal[index]]-1)+1)];
                                 mapa.fator[mapa.canal[index]]=1.0;
                                 if(mapa.canal[index]==0)mapa.fator[mapa.canal[index]]=0.4546;
                                 if(mapa.canal[index]==1)mapa.fator[mapa.canal[index]]=0.05;
                                 }
                              }


                       break;
           case 2:
                       for(i=0;i<14;i++)
                           {
                           mapa.vpIcone[i]=PROCULUS_VP_Read_UInt16(0x0310+i);
      mapa.canal[i]=PROCULUS_VP_Read_UInt16(i*10+1789)>>8;
                           }
                       EEPROM_Write_Buffer(19,&mapa.vpIcone[0],15);
                       EEPROM_Write_Buffer(0xEA,&mapa.icone[0],15);
                       EEPROM_Write_Buffer(36,&mapa.canal[0],15);
                       break;


           }
}




char buscaIndex(char *buffer,char valor)
{
 char i;
 for(i=0;i<13;i++)
    {
    if(buffer[i]==valor) break;
    }
 return i;
}




void AcordaFilha(){
     statuspower.flag_global_datalog=0;
     statuspower.flag_global_condensador=0;
     statuspower.flag_global_vacuo=0;
     statuspower.flag_global_aquecimento=0;
}


void showTotalReset(void){
    clear_screen();
    print("-----RELATORIO TECNICO----");

    print("Reinicializacoes:");
    if(PROCULUS_VP_Read_UInt16(0x00AA)==1)
      {
      char bb[3];
      int valor;
      char placa;
      char vetor[3];
      PROCULUS_VP_Write_UInt16(0x00AA,0);
      PROCULUS_Show_Screen(0);
      valor=EEPROM_Read_Integer(34);
      itoa(valor,buffer,10);
      strcpy(texto,"Placa 0 = ");
      strcat(texto,buffer);
      print(texto);
      for(placa=1;placa<=totalboard;placa++)
          {

          strcpy(texto,"Placa ");
          itoa(placa,buffer,10);
          strcat(texto,buffer);
          strcpy(buffer," = ");
          strcat(texto,buffer);
          bb[0]=0x10;
          valor=Send_To_Slave(placa,0x0B,1,bb);
          itoa(valor,buffer,10);
          strcat(texto,buffer);
          print(texto);
          }

      print("Desligar do Vacuo:");
      valor=EEPROM_Read_Integer(0xE8);
      itoa(valor,texto,10);
      strcat(texto," vez(es).");
      print(texto);

      my_delay_ms_CLRWDT(15000);
      PROCULUS_Show_Screen(15);
      }

}


void ShowHardwareInfo(){
     char i;
     char destino;
     char tipo;
     int resposta;
     char versao[10];
     Send_To_Slave(destino, 0x03, 0, buffer);
     totalboard=0;
     strcpy(texto,"");
     strcat(texto,"* : Mother Board ");
     strcat(texto,"v1.0.14");
     print(texto);
     for(destino=1;destino<15;destino++)
        {
        my_delay_ms_CLRWDT(100);
        Buffer_Manager();
        resposta = Send_To_Slave(destino, 0x03, 0, buffer);
        tipo=((char *)&resposta)[1];
        if(resposta!=-1)
            {
            totalboard++;
            strcpy(texto,"");
            itoa(destino,texto,10);
            strcat(texto," : ");
            strcat(texto, boardtype[tipo]);
            strcat(texto," ");
            strcpy(buffer," ");
            Send_To_Slave(destino, 0x2B, 0, buffer);
            strcat(texto,buffer);
            print(texto);
            }
        }



     if(totalboard==0)
        {
        print("Nenhuma Placa conectada!");
        }
     else
        {
        itoa(totalboard,texto,10);
        strcat(texto," placa(s) encontrada(s).");
        print(texto);
        }


}

char MenorCanalLivre()
     {
     unsigned char canal, canalLivre, canalBusca, busca, Exist;
     canal=0x0A;
     for(canalLivre=0;canalLivre<8;canalLivre++)
     {

     Exist=0;
     for(canalBusca=0;canalBusca<13;canalBusca++)
        {
        busca=mapa.canal[canalBusca];

     if(canalLivre==busca)
    {

    Exist=1;
    break;
    }
     }
  if(Exist==0)
    {

    canal=canalLivre;
    break;
    }
  }

  return canal;
  }





void Incrementa_Contador_de_Repique_do_Vacuo(){
     int valor;
     if(statusgen1.flag_Vacuo_estava_ligado==1)
       {
       statusgen1.flag_Vacuo_estava_ligado=0;
       valor=EEPROM_Read_Integer(0xE8);
       valor++;
       EEPROM_Write_Integer(0xE8,valor);
       }
}


void Carregar_Display_Schematic_Color(){

     Tamanho_Display=EEPROM_Read_Integer(0xFA);
     PROCULUS_VP_Write_UInt16(214,Tamanho_Display);

     if(Tamanho_Display==50){
          TrendColor[0] =0xF800;
          TrendColor[1] =0x03E0;
          TrendColor[2] =0x001F;
          TrendColor[3] =0xFFFF;
          TrendColor[4] =0xFFFF;
          TrendColor[5] =0xFFFF;
          TrendColor[6] =0xFFFF;
          TrendColor[7] =0xFFFF;
          TrendColor[8] =0xFFFF;
          TrendColor[9] =0xFFFF;
          TrendColor[10]=0xFFFF;
          TrendColor[11]=0xFFFF;
          TrendColor[12]=0xFFFF;
     }
     else if(Tamanho_Display==80){
          TrendColor[0] =0x0000;
          TrendColor[1] =0x39E7;
          TrendColor[2] =0x6B6D;
          TrendColor[3] =0x7800;
          TrendColor[4] =0x9A23;
          TrendColor[5] =0xF800;
          TrendColor[6] =0xFBE0;
          TrendColor[7] =0xFBF7;
          TrendColor[8] =0xD540;
          TrendColor[9] =0x03E0;
          TrendColor[10]=0x07E0;
          TrendColor[11]=0x001F;
          TrendColor[12]=0xF81F;
          }
     else {
          TrendColor[0] =0xFFFF;
          TrendColor[1] =0xFFFF;
          TrendColor[2] =0xFFFF;
          TrendColor[3] =0xFFFF;
          TrendColor[4] =0xFFFF;
          TrendColor[5] =0xFFFF;
          TrendColor[6] =0xFFFF;
          TrendColor[7] =0xFFFF;
          TrendColor[8] =0xFFFF;
          TrendColor[9] =0xFFFF;
          TrendColor[10]=0xFFFF;
          TrendColor[11]=0xFFFF;
          TrendColor[12]=0xFFFF;

          }
}

void Ligar_Cargas_Compassadamente(){
     int valor;
     PROCULUS_VP_Write_UInt16(0x02,0);
     PROCULUS_VP_Write_UInt16(0x03,0);
     PROCULUS_VP_Write_UInt16(0x04,0);
     PROCULUS_VP_Write_UInt16(0x05,0);
     statuspower.flag_time_process=0;

     statuspower.bits=EEPROM_Read_Byte(16);
     if(statuspower.bits!=0)
          {
          print("Cond. de blackout encontrada!");
          print("Acionando Cargas, Aguarde...");

          Contagem_Tempo_de_Processo(0);

          if(statuspower.flag_global_datalog==1)
             {

             statuspower.flag_global_datalog=0;
             print("1-DataLog");
             PROCULUS_VP_Write_UInt16(0x02,1);
             global_datalog();



             PROCULUS_Show_Screen(35);
             {
             int valorLido;
             char bb[5];
             unsigned long add_eeprom;

             for(add_eeprom=0;add_eeprom<600;add_eeprom+=2)
                  {
                  bb[0]=0;
                  bb[1]=((char *)&add_eeprom)[3];
                  bb[2]=((char *)&add_eeprom)[2];
                  bb[3]=((char *)&add_eeprom)[1];
                  bb[4]=((char *)&add_eeprom)[0];
                  valorLido=Send_To_Slave(1, 0x14, 5, bb);
                  my_delay_ms_CLRWDT(50);
                  PROCULUS_graphic_plot(1,valorLido);
                  }


             }
            }

          if(statuspower.flag_global_condensador==1)
            {
            statuspower.flag_global_condensador=0;
            print("2-Condensador.");
            PROCULUS_VP_Write_UInt16(0x03,1);
            global_condensador();
            my_delay_ms_CLRWDT(10000);
            }


          if(statuspower.flag_global_vacuo==1)
            {
            statuspower.flag_global_vacuo=0;
            statuspower.flag_time_process=1;
            print("3-Vacuo.");
            PROCULUS_VP_Write_UInt16(0x04,1);
            global_vacuo();
            my_delay_ms_CLRWDT(10000);
            }


          if(statuspower.flag_global_aquecimento==1)
            {
            statuspower.flag_global_aquecimento=0;
            print("4-Aquecimento");
            PROCULUS_VP_Write_UInt16(0x05,1);
            global_aquecimento();
            my_delay_ms_CLRWDT(10000);
            }
          PROCULUS_Show_Screen(15);
          }
     memo_statuspower=statuspower.bits;
}





void Teste24cXXXX(void){
     unsigned char chip, placa,canal;
     unsigned long add_eeprom;
     unsigned int valor;
     int valorLido;
     char bb[5];
     Tamanho_Display=80;
     PROCULUS_Show_Screen(0);


     add_eeprom=0;
     placa=1;
     canal=0;
     chip=0;

     while(1)
          {
          add_eeprom=0;
          save_datalog(add_eeprom);

          strcpy(texto,"Analogica Canal 0 = ");
          bb[0]=canal;
          valorLido=Send_To_Slave(placa, 0X1A, 1, bb);
          itoa(valorLido,buffer,10);
          strcat(texto,buffer);
          print(texto);

          bb[0]=chip;
          bb[1]=((char *)&add_eeprom)[3];
          bb[2]=((char *)&add_eeprom)[2];
          bb[3]=((char *)&add_eeprom)[1];
          bb[4]=((char *)&add_eeprom)[0];
          valorLido=Send_To_Slave(placa, 0x14, 5, bb);
          strcpy(texto,"Memoria chip 0 =");
          itoa(valorLido,buffer,10);
          strcat(texto,buffer);
          print(texto);

          my_delay_ms_CLRWDT(500);
          }
}
