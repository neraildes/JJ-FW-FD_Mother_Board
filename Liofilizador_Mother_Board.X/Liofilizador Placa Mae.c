/*------------------------------------------------------------------------------
 * LIOFILIZADOR JJ CIENTIFICA
 * DATA 05/01/2019
 * COMPILADOR XC8 Free
 * NIVEL DE OTIMIZAÇÃO  2
 * MICROCONTROLADOR - PIC18F4620
 * 
 * *NERA-TEMPORARIO - Busca para acertar programa
 * 
------------------------------------------------------------------------------*/

#include <xc.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <proc/pic18f4620.h>
#include "global.h"
#include "Liofilizador Placa Mae.h"
#include "isr.h"
#include "proculus.h"
#include "usart.h"
#include "I2C.h"
#include "adc.h"
#include "timedate.h"
#include "util.h"
#include "protocolo.h"
#include "eeprom.h"
#include "EEPROM_24C1025.h"
#include "voltagem.h"
#include "versao.h"

//------------------------TUPLA DE AQUECIMENTO----------------------------------
//PARA EEPROM INTERNA (0x3FF)
#define OFFSET_EEPROM       52     //Deslocamento para deixar os primeiros bytes livres (10)
#define TUPLA_EEPROM_SIZE   18     //Tamanho maximo de uma tupla na eeprom (18)
#define TUPLA_VP_SIZE       12     //Tamanho maximo de uma tupla no display(12)


//-------------------------TUPLA DE FAT8----------------------------------------
//PARA EEPROM EXTERNA (0x1FFFF)
#define FAT8_VP_SIZE       30
#define OFFSET_EEPROM_FAT8 0x10
#define EEPROM_FAT8_SIZE   54

//--------------------------COMUNICAÇÃO I2C - Pinos config----------------------
#define CLK at PORTCbits.RD3       //I2C CLOCK
#define DTA at PORTCbits.RD4       //I2C DATA

//------------------Conversaando com o procedimento TrendCurve------------------
#define FORMAT  0  //
#define LOAD    1  // Constantes do TrendCurveFuncao
#define SAVE    2  //

#define PPCANAL 1789 //O Canal utiliza PP
#define PPCOR   1787

#define FATOR_PADRAO 1.0
#define FATOR_TENSAO 0.4546
#define FATOR_VACUO  0.05



/*----------------------------------------------------------------------------*/
volatile unsigned char usart_buffer[USART_BUFFER_SIZE]; 

volatile unsigned int  tempodecorrido        ;
volatile unsigned int  tempocaptura          ; //variavel de captura de dados para memoria datalog
volatile unsigned int  tempocapturaconstante ; //variavel de memoria

volatile unsigned int  processo_totalminuto;
volatile unsigned char processo_segundo ;
volatile unsigned char processo_minuto ;
volatile unsigned char processo_hora   ;

//==============================================================================

volatile unsigned int tmr_led_memory;
volatile unsigned int Delay_Led_Memory;

volatile unsigned int tmr_led_usart;
volatile unsigned int Delay_Led_Usart;

volatile unsigned int tmr_led_tmr0;
volatile unsigned int Delay_Led_Tmr0;


//------------------------------------------------------------------------------

volatile unsigned int delaycheckscreen;
volatile signed int senhacount;
volatile unsigned int delay_update_display;

//------------------------------------------------------------------------------

t_usart_protocol usart_protocol;
t_proculus       proculus;
t_liofilizador   liofilizador[10];
t_receita        receita;

t_fat8           fat8;
//------------------------------------------------------------------------------

char  texto[74];
char  buffer[74];

//------------------------------------------------------------------------------

char maincnt;
unsigned int  pagina=15;
unsigned int  paginamemo=15;


//------------------------------------------------------------------------------
//Tempo entre ligamento de dispositivos após retorno de blackout
//A definição está na função Ligar_Cargas_Compassadamente().
unsigned int timerDatalog=0;
unsigned int timerCondensador=0;
unsigned int timerVacuo=0;
unsigned int timerAquecimento=0;
unsigned int timerEstante=0;

//------------------------------------------------------------------------------

volatile unsigned char flag_senha_global_liberada;
volatile unsigned char flag_senha_liberada;
volatile unsigned char totalboard;
volatile signed int senhacount;
unsigned long senha_atual;
char senhavetor[4];

unsigned char erroSemPlaca[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//------------------------------------------------------------------------------
int Condensador     ; 
int Condensador1    ;
int Vacuometro      ;
int Voltimetro      ;

char MSG_Deseja_Encerrar_Processo;


int Seg_Condensador ;   //Valor mínimo necessário para ligar o vácuo
int Seg_Vacuo       ;   //Valor mínimo necessário para ligar o aquecimento
int Seg_Aq_cond     ;
int Seg_Aq_vacuo    ;
int leitura[0x0F]   ;


char Index_Receita;
char Index_Sel_Rec;


unsigned long add_datalog;

char returnToScreen;

volatile char MonitorBuffer;

char trendExist;
int  trendvp=0x0310;
char icone ; 

unsigned int vpPrint=2000;

volatile unsigned char flag_array_slave_WDT[15];

unsigned char memo_statuspower;

volatile unsigned char delay_condensador;  //Tempo de 30 Segundos para Religar Condensador.

int index;
int  Tamanho_Display;
char maxlineDATALOG;

int TrendColor[13];

T_mapa mapa;

void main(void) 
{
     
     my_delay_ms_CLRWDT(100);
     
     OSCCONbits.IRCF0=1; //Frequencia do oscilador interno = 8Mhz
     OSCCONbits.IRCF1=1;
     OSCCONbits.IRCF2=1;
     OSCCONbits.SCS0 =0;
     OSCCONbits.SCS1 =0;
     OSCTUNEbits.PLLEN=1; //pll 8*4 = 32Mhz
      
     TRISA=0b11101111;    //Inicializa Portas
     TRISB=0b00000001;
     TRISC=0b11110000;
     TRISD=0b11100011;
     TRISE=0xFF;
    
     //-------------------------------------------------------------------------
     T0CONbits.T0CS  = 0;
     T0CONbits.PSA   = 0;
     T0CONbits.T0PS1 = 1;
     T0CONbits.T0PS1 = 1;
     T0CONbits.T0PS2 = 1;      
     INTCON2bits.TMR0IP =0;  //Timer zero, interrupção em baixa prioridade
     INTCONbits.T0IE    =1;  //Timer0 habilitado
     
     
     //-------------------------------------------------------------------------
     RBIF=0;
     INTCONbits.INT0IE   =0;  //Interrupção em RB0 desligada
     
     //-------------------------------------------------------------------------
     PIR1bits.TMR1IF = 0;   // Reset the TMR1IF flag bit
     IPR1bits.TMR1IP=0;     //Timer 1 com interrupção de baixa prioridade     
     TMR1H = 0x0B;          // Set initial value for the timer TMR1
     TMR1L = 0xBA;
     TMR1CS = 0;            // Timer1 counts pulses from internal oscillator
     T1CKPS0 = 1;           // Assigned prescaler rate is 1:8 
     T1CKPS1 = 1; 
     T1RUN=1;
     T1OSCEN=1;
     PIE1bits.TMR1IE=1;      // Enable interrupt flag_time_process          
     TMR1ON = 1;             // Turn the timer TMR1 on 
     //IPEN=1;  //Habilita prioridade na interrupção.    
     
     //-------------------------------------------------------------------------
     INTCONbits.PEIE    =1;  //Habilita Interrupção em Perifericos  
     
     //-------------------------------------------------------------------------    
     //INTCONbits.GIEL     =1;  //Global Interrupt                           
     //INTCONbits.GIEH     =1;  //Global Interrupt  
     INTCONbits.GIE        =1;  //Global Interrupt 
     //=========================================================================

     //--------------------- INICIALIZA PERIFERICOS-----------------------------
     USART_init(115200);
     My_ADC_init();
     I2C_Master_Init(100000);
     my_delay_ms_CLRWDT(500);          
     
     //=========================================================================
     Delay_Led_Tmr0=0;
     flag_led_tmr0=0;
     Delay_Led_Usart=0;
     flag_led_usart=0;
     Delay_Led_Memory=0;
     flag_led_memory=0; 
     
    //--------------------------------------------------------------------------
     Tamanho_Display=EEPROM_Read_Integer(0xFA);
     if(Tamanho_Display==50)
        maxlineDATALOG=9;     
     else if(Tamanho_Display==80)
        maxlineDATALOG=12;
     else if(Tamanho_Display==81)
            {
            maxlineDATALOG=8; 
            }
     

     //-------------------------------------------------------------------------
     flag_proculus_hs=FALSE;     
     clear_screen();
     PROCULUS_Show_Screen(0);     
     my_delay_ms_CLRWDT(300); 
     print("JJ Cientifica Ind. e Com. de Eq. Cient. Ltda.");     
     my_delay_ms_CLRWDT(300);
     print("CNPJ: 05.678.930/0001-12");     
     //-------------------------------------------------------------------------     
     {
     //-----------TOTALIZADOR DE REINICIO DE MODULO USART -------------              
     unsigned int reset_usart;    
     reset_usart=EEPROM_Read_Integer(34);
     if(reset_usart==0xFFFF)
       {  
       EEPROM_Write_Integer(34,0);   //Totalizador de Reset
       }
     }
     
     //-------------------------------------------------------------------------
     if(EEPROM_Read_Byte(OFFSET_EEPROM)==0xFF)
       {         
       print("Aguarde, preparando a maquina para"); 
       print("a primeira inicializacao.");
       Formatar_Banco_de_Dados(0,10);
       Formatar_Lista_de_Receitas();
       Formatar_Dados_de_Seguranca();
       Formatar_Datalog();
       flag_senha_global_liberada=FALSE;
       flag_senha_liberada=FALSE;
       Gravar_Status_da_Senha_Global();
       EEPROM_Write_Byte(16,0);// statuspower (byte de status)
       EEPROM_Write_Integer(0x09,10); // Valor inicial do tempo de captura de log
       EEPROM_Write_Long32(11,123456);//Valor inicial da senha do administrador  
       TrendCurveFuncao(FORMAT); 
       EEPROM_Write_Byte(17,0);//processo_Hora
       EEPROM_Write_Byte(18,0);//processo_Minuto   
       Format_FAT8_Table();          //Inicializa tabela de Datalog 
       EEPROM_24C1025_Write_Int (0,0,0); //Inicializa numero de processo
       EEPROM_24C1025_Write_Long(0,2,0); //Inicializa add_datalog
       EEPROM_Write_Integer(0xFA,50);      //Resolucao padrao do display
       } 
     //print("Analisando status de blackout...");
     RecallBlackoutStatus();     
     TrendCurveFuncao(LOAD);
     senha_atual=EEPROM_Read_Long32(11);
     Carregar_Status_da_Senha_Global(); 
     print("Carregando parametros de seguranca...");
     Carregar_Parametros_de_Seguranca();
     Carregar_tempo_de_datalog(); //Intervalo de capturas
     print("Inicializando datalog...");
     add_datalog=EEPROM_24C1025_Read_Long (0,2); //Inicializa add_datalog
     

     

 
     //------------Valores Iniciais da tela Principal---------------------------

     
     //======================== INFORMAÇÕES INICIAIS ===========================     
     print("Analisando dados, aguarde...");  
     for(char i=0;i<15;i++)
        {
        asm("CLRWDT"); 
        ShowStaticValueGrid(i);
        }    
     //-----------------------Carrega valores de sensores-----------------------
     
     
          
     //------------------------Carrega Lista de Receita-------------------------
     for(char i=0;i<8;i++)
         {
         asm("CLRWDT");
         Exibe_Receita(i);
         }
     //-------------------------------------------------------------------------
     senha_atual=EEPROM_Read_Long32(11);
     //-------------------------Carrega Status de Senha-------------------------
     Carregar_Status_da_Senha_Global();     
     
     
    //==========================================================================
     ShowSensorRealTimeHS();
     /*-------------------------------------------------------------------------
                          INICIALIZAÇAO DOS PARAMETROS
     -------------------------------------------------------------------------a*/
     Carregar_Parametros_de_Seguranca();
     Carregar_tempo_de_datalog();
     //-------------------------------------------------------------------------

     
     //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
     //                       M  A  I  N      L  O  O  P
     //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 
     Exibe_Tempo_de_Processo();
     Icones_de_alarmes();        
  
     pagina=0;
     paginamemo=0;
     maincnt=0;     
     delaycheckscreen=0;     
     MonitorBuffer=0;
     //-------------------------
     Vacuometro=0;
     Voltimetro=0;
     Condensador=0;
     Condensador1=0;  //Utilizado em máquinas com 2 condensadores

     //-----------------------------
     /*Exibição e controle de mensagem para encerrar o processo. Esta variável
      permite que o programa rode enquanto é exibida a pergunta para encerrar
      o processo permitindo que os paramentros de temperatura do condensador e
      pressão sejam atualizados.
     */
     MSG_Deseja_Encerrar_Processo=0;

     //--------timer 1----------
     Exibe_Hora_Data(FALSE); //Exibe data e Hora sem os segundos (FALSE)   
     rtc.milisegundo=0;
     rtc.segundo=0;
     //processo_hora=EEPROM_Read_Byte(17);
     //processo_minuto=EEPROM_Read_Byte(18);
     processo_segundo=0;
     memo_statuspower=statuspower.bits;
     delay_condensador=0;
     
     //PROCULUS_VP_Write_UInt16(62,1);
     
     
     //=========================================================================
     //                              M A I N
     //=========================================================================
        FAT8_Show();
        
       
        PROCULUS_VP_Write_UInt16(0x40,0); //Icone do computador conectado
        flag_pc_conected                 =FALSE;
        flag_autoriza_click_datalog      =0;
        flag_autoriza_click_condensador  =0;
        flag_autoriza_click_vacuo        =0;
        flag_autoriza_click_aquecimento  =0;        
        
        
        //PROCULUS_Show_Screen(15);     
        PROCULUS_VP_Write_UInt16(1,0); //ACENDE ICONE TEIMOSO
        flag_usart_error=0;
        
     print("Analisando Hardware. Aguarde..."); 
     placasFilhasInit();  //Inicializa comunicação com Placas Filhas;
     ShowHardwareInfo();   
     //showMemoryInfo();
     Ligar_Cargas_Compassadamente();
     my_delay_ms_CLRWDT(2500);        
     PROCULUS_Show_Screen(15);     
     
     
     
        while(1)
             {
             
             flag_main_loop_WDT=TRUE;       
             
             //=========================SELECAO DE PAGINA============================
             flag_proculus_hs=TRUE;
             if(delaycheckscreen>1000)
               {
               delaycheckscreen=0;      
               pagina = PROCULUS_Get_Page();
               if(pagina!=paginamemo)
                  {
                  paginamemo=pagina;                  
                  }//pagina!= 
               }              
             //flag_proculus_hs=FALSE;
             //-----------------------------------------------------------------
                flag_proculus_hs=TRUE;
                if(rtc.segundo<5) if(pagina!=25) Exibe_Hora_Data(FALSE); //Exibe data e hora sem segundos
                if(flag_time_process==TRUE) SaveBlackoutStatusRuning(); //Salva status e tempo de processo a cada 10 minutos
                Exibe_Tempo_de_Processo();
                Icones_de_alarmes();    
                flag_proculus_hs=FALSE;
                
                
                Gerenciador_de_Senha();  //Habilita acesso global por 30 segundos
                Gerenciador_de_Senha_Global(); //Libera Senha Global eternamente                
                
                
                //------------------CODIGO RAPIDO---------------------
                ShowSensorRealTimeHS();                          
                //----------------------------------------------------                  
                global_datalog(); // LEITURA DOS SENSORES                 
                if(Tamanho_Display==81) global_refrigeracao_fluido();
                global_condensador();   
                global_vacuo(); 
                global_aquecimento();                                
                
                
                if(PROCULUS_VP_Read_UInt16(100)==1) RelatorioTecnico(); //Exibe relatório técnico
                
               
                
                
                //INDICA SE OCORREU TRAVAMENTO DO RX DAS PLACAS
                if(flag_usart_error==TRUE) Delay_Led_Memory=200;                 

                
                
                switch(MSG_Deseja_Encerrar_Processo)
                      {
                      case 1:PROCULUS_Popup(DESEJA_ENCERRAR_PROCESSO);
                             PROCULUS_VP_Write_UInt16(0x0016,0); 
                             MSG_Deseja_Encerrar_Processo=2;
                             break;
                      case 2:if(PROCULUS_VP_Read_UInt16(6)==240)//SIM, Encerra
                               { 
                               Contagem_Tempo_de_Processo(FALSE);
                               processo_hora=0;
                               processo_minuto=0;                                                              
                               MSG_Deseja_Encerrar_Processo=0;
                               SaveBlackoutStatusRuning();                                
                               //Exibe_Tempo_de_Processo();
                               }  
                             if (PROCULUS_VP_Read_UInt16(6)==250)//NAO Encerra
                               {
                               MSG_Deseja_Encerrar_Processo=0;  
                               PROCULUS_Buzzer(15000); //Não
                               }
                             break;
                      }                  
                  
                
                flag_proculus_hs=TRUE;
                
                
                gravarStatusDosBotoes();                

                /*--------------------------------------------------------------
                 * Esta função não pode ser utilizada porque ela restarta o
                 * contador de datalog
                 *--------------------------------------------------------------
                if((processo_segundo==0) || (processo_segundo==30))
                    { 
                    if(flag_wakeup==1)
                       {
                       flag_wakeup=0; 
                       AcordaFilha(); 
                       }        
                    }
                else
                    {
                    flag_wakeup=1;
                    }         
                --------------------------------------------------------------*/
                   
                           
                if(flag_pc_conected==FALSE) Check_And_Send_Capture_Datalog();
                flag_proculus_hs=FALSE;
                

                
                //showTotalReset();

                          


            //=================AJUSTA O CONTADOR DE ACORDO COM A PÁGINA=============
            flag_proculus_hs=TRUE;    
            switch(pagina)
                  {                
                  //case 15: //---------------- PAGINA PRINCIPAL----------------------                            
                           //ShowStaticValueGrid(maincnt);   //Atualiza tudo                    
                           //maincnt++;
                           //if(maincnt>=15) maincnt=0; 
                
                           //break;
                  case 132: //------------PAGINA PARA SETAR AQUECIMENTO--------------
                  case 19:    
                  case 21:  //Exibe somente os 5 primeiros dados da tupla
                            //Permite rolagem                           
                      
                           //---------------------------------------------------
                  
                           for(char i=0; i<10; i++)
                               {
                               //flag_main_loop_WDT=1;
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
                  case 23:// Página de parâmetros de segurança                                       
                  case 135:    
                          if(PROCULUS_VP_Read_UInt16(1)==1)
                             { 
                             PROCULUS_VP_Write_UInt16(1,0);
                             pagina_23(); //Salva Parametros
                             }                          
                          break;                        

                  case 25: // Ajuste de data e hora
                         if(maincnt==0)
                            {
                            Exibe_Hora_Data(TRUE);
                            maincnt++;
                            }
                          if(PROCULUS_VP_Read_UInt16(152)==1)
                             { 
                             PROCULUS_VP_Write_UInt16(152,0);
                             Exibe_Hora_Data(TRUE);
                             }                                                     
                          if(PROCULUS_VP_Read_UInt16(174)==1)
                             { 
                             PROCULUS_VP_Write_UInt16(174,0);
                             pagina_25(); //Salva Data e Hora
                             } 
                          break; 
                  case 27:
                  case 28://Selecao de Receita- Pagina 1
                          for(Index_Receita=0;Index_Receita<8;Index_Receita++)        
                              {
                              if(PROCULUS_VP_Read_UInt16(0x0020+Index_Receita)==1) //Selecionou algo
                                 {
                                 PROCULUS_VP_Write_UInt16(0x0020+Index_Receita,0); //Desabilita pra não entrar de  
                                 PROCULUS_Show_Screen(returnToScreen);
                                 Carrega_Tupla_Receita(Index_Receita, &receita);
                                 Set_Receita(Index_Sel_Rec,TRUE); // Index_Sel_Rec                                 
                                 }                               
                              }                        

                              if(PROCULUS_VP_Read_UInt16(17)==1) //Menu ESC
                                 {
                                 PROCULUS_VP_Write_UInt16(17,0);
                                 PROCULUS_Show_Screen(returnToScreen);
                                 }   
                          
                              if(PROCULUS_VP_Read_UInt16(18)==1) //Menu Excluir
                                 {
                                 PROCULUS_VP_Write_UInt16(18,0);
                                 receita.histerese=0;
                                 strcpy(receita.nome," ");
                                 receita.potenciaOFF=0;
                                 receita.potenciaON=0;
                                 receita.setpoint=0;
                                 Set_Receita(Index_Sel_Rec,FALSE); // In
                                 PROCULUS_Show_Screen(returnToScreen);
                                 }                           
                          
                          break;

                  case 29: // Ajuste de tempo de captura de datalog
                  case 133://   e exibição de todos os datalogs 
                          {
                          for(char i=0;i<maxlineDATALOG;i++) //Exibe Grafico Armazenado na Memoria  
                             {                                 
                             if(PROCULUS_VP_Read_UInt16(0x1017+(i*30))==1)
                               {
                               PROCULUS_VP_Write_UInt16(0x1017+(i*30),0);
                               FAT8_Load(i);
                               PROCULUS_Show_Screen(35);
                               PROCULUS_Clean_All_Line_Graphic();
                               Plotar_Grafico_Gravado();
                               break;  
                               } 
                             }                           

                          if(PROCULUS_VP_Read_UInt16(0x30)==1) //Apaga dados do datalog
                             { 
                             PROCULUS_VP_Write_UInt16(0x30,0);
                             Format_FAT8_Table(); 
                             }                            
                         
                          FAT8_Show();  
                               
                          if(PROCULUS_VP_Read_UInt16(175)==1) //Grava tempo de captura
                             { 
                             PROCULUS_VP_Write_UInt16(175,0);
                             pagina_29(); 
                             }  
                          } 
                          break;
                  case 31: //Troca de Senha
                          {
                          #define KEY 0xE4BA2F10 
                             
                          unsigned long dica;
                          
                          dica=~(senha_atual^KEY);
                          
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
                  case 35:// Seleciona cor da linha do grafico. Imprimindo cores correspondentes.
                            {   
                            int tv;                            
                            char total;
                            static int canal=0;
                            flag_proculus_hs=TRUE;
                            
                            if((flag_pc_conected)&&(flag_global_vacuo)&&(flag_global_datalog))  
                              {  
                              PROCULUS_Popup(GRAFICO_SOMENTE_NO_PC);
                              PROCULUS_Show_Screen(15);
                              break;  
                              }
                            
                            
                            for(trendvp=0x0310;trendvp<0x031D;trendvp++)
                                  {	
                                  icone=trendvp-0x0310;					  								  
                                  if(PROCULUS_VP_Read_UInt16(trendvp)==14)
                                          {
                                          if(flag_senha_liberada)
                                               {

                                               if(Tamanho_Display==50)canal=icone;
                                               else
                                               if(Tamanho_Display==80)canal=MenorCanalLivre();
                                               else
                                               if(Tamanho_Display==81)canal=MenorCanalLivre();

                                               if(canal<8)
                                                  { 											                                                                 
                                                  PROCULUS_VP_Write_UInt16(0x310+icone,icone+1); //Colore o quadrado com uma cor fixa 
                                                  PROCULUS_VP_Write_UInt16((canal*10+PPCANAL),(canal<<8)|(0x0001)); //Seta um canal para um dos 13 icones
                                                  PROCULUS_VP_Write_UInt16((canal*10+PPCOR),TrendColor[icone]);     //Seta uma cor de linha do grafico											                                             


                                                  mapa.canal[canal]=canal;   //Seleciona um Canal
                                                  mapa.icone[canal]=icone+1;              //Registra qual icone está sendo tratado
                                                  mapa.vpIcone[icone]=icone+1;
                                                  mapa.cor[canal]=TrendColor[icone];
                                                  mapa.fator[canal]=1.0;
                                                  mapa.entrada[canal]=&leitura[saltaIndice4(icone)];    //Aponta para uma leitura

                                                  mapa.fator[canal]=FATOR_PADRAO;                  //Fator Padrão

                                                  if(icone==0)mapa.fator[canal]=FATOR_TENSAO;      //Fator para Tensão
                                                  if(icone==1)mapa.fator[canal]=FATOR_VACUO;      //Fator para Vacuo


                                                  //PROCULUS_Clear_Line_Graphic(icone);
                                                                                              //PROCULUS_VP_Write_UInt16(1000+canal,*mapa.entrada[canal]*mapa.fator[canal]);      
                                                  TrendCurveFuncao(SAVE); //Salva os icones acionados
                                                  } 
                                               else
                                                  {	
                                                  PROCULUS_VP_Write_UInt16((canal*10+PPCANAL),(canal<<8)|(0x0A00)); //Canal
                                                  PROCULUS_VP_Write_UInt16((canal*10+PPCOR),0xFFFF);//Cor                                               
                                                  PROCULUS_VP_Write_UInt16(trendvp,-1);  
                                                  }
                                               }
                                          else
                                               {
                                               PROCULUS_NOK();
                                               PROCULUS_VP_Write_UInt16(trendvp,-1);
                                               PROCULUS_Popup(ACESSO_NEGADO);                                               
                                               }
                                          }
                                     else 
                                      if((PROCULUS_VP_Read_UInt16(trendvp)>=15)&&(PROCULUS_VP_Read_UInt16(trendvp)<=30))
                                          {
                                          if(flag_senha_liberada)
                                               {
                                               char canal_aleatorio, canal_sequencial;

                                               canal_sequencial=buscaIndex(mapa.icone,icone+1);
                                               canal_aleatorio=mapa.icone[icone]-1; 	                           //canal para lista aleatoria                                         

                                               PROCULUS_VP_Write_UInt16(trendvp,-1);                            //Apaga o quadrado colorido do display 
                                               PROCULUS_VP_Write_UInt16((canal_sequencial*10+PPCANAL),0x0A00);  //Libera o canal utilizado
                                               PROCULUS_VP_Write_UInt16((canal_sequencial*10+PPCOR),0xFFFF);               //Torna a cor padrao do canal em branco 

                                                                                       mapa.entrada[canal_sequencial]=NULL;                             //Torna a entrada do canal NULL  
                                               mapa.canal[canal_sequencial]=0X0A;                               //Seleciona um Canal
                                               mapa.icone[canal_sequencial]=-1;                                 //Registra qual icone está sendo tratado
                                               mapa.vpIcone[icone]=-1;                                          //Desliga ícone aleatorio
                                               mapa.cor[canal_sequencial]=0xFFFF;                               //Desliga a Cor           
                                                                                   mapa.fator[canal_sequencial]=0.0;                                //Fator padrão para Temperatura

                                                                                       //PROCULUS_Clear_Line_Graphic(canal+1);               //Apaga a Linha desenhada  										                      
                                               TrendCurveFuncao(SAVE);								//Salva as alterações		                                  
                                               }
                                          else
                                               {
                                               PROCULUS_NOK();
                                               PROCULUS_Popup(ACESSO_NEGADO);                                               
                                               if(Tamanho_Display==50)PROCULUS_VP_Write_UInt16(trendvp,mapa.icone[icone]); 
                                               if(Tamanho_Display==80)PROCULUS_VP_Write_UInt16(trendvp,mapa.vpIcone[icone]);                                                                         
                                               }
                                          }                                  
                                  }	
                                  
                                  
	


                            
                            flag_proculus_hs=FALSE;                            
                            break;
                            }
                  case 47: //Lista de Receitas
                          Atualizar_Lista_de_Receitas();

                          for(Index_Receita=0;Index_Receita<8;Index_Receita++)        
                              {
                              //flag_main_loop_WDT=1;
                              if(PROCULUS_VP_Read_UInt16(0x0020+Index_Receita)==1)
                                 {
                                 PROCULUS_VP_Write_UInt16(0x0020+Index_Receita,0);                                 
                                 pagina_47();                                 
                                 break;
                                 }                               
                              }                             
                                                     
                          break;  
                  case 49: //Edicao de receita
                          {
                          pagina_49();                    
                          }
                          break;
                  }//switch pagina          
            
                
                ouve_comunicacao(); 
        }
      
}
//------------------------------------------------------------------------------
unsigned char countboard()
         {
         unsigned char retorno;
         retorno=0;
         for(char destino=0;destino<0x0F;destino++)
             {
             if(Send_To_Slave(destino, COMANDO_QUEM_EH_VOCE, 0, buffer)!=-1) retorno++;                 
             my_delay_ms_CLRWDT(100);
             }
         return retorno;
         } 


//------------------------------------------------------------------------------
//SEND TO SLAVE
 int  Send_To_Slave(char destino, char comando, char size, char * buffer)
{
     unsigned int contador;
     int retorno=0xFFFF;
     signed char sizereturn;
     char flag_is_buffer;
     
     char i;
     
     flag_is_buffer=0;
     if(
       (comando==COMMAND_IEE_R_BUF)||
       (comando==COMMAND_IEE_R_STR)||
       (comando==COMMAND_EEE_R_BUF)||
       (comando==COMMAND_EEE_R_STR)||
       (comando==COMMAND_VERSION)       
       )
       { 
       flag_is_buffer=1;  
       sizereturn=buffer[5]; //Pega o tamanho do buffer em EEE_R_BUF 
       } 
       
     
     USART_put_int(HEADER_LIOFILIZADOR);
     USART_putc(BOARD_ADD);
     USART_putc(destino);
     USART_putc(comando);
     USART_putc(size);
     for(i=0;i<size;i++)
          USART_putc(buffer[i]);     
     __delay_us(80); //Para efeito de debug, vizualiza após ultimo byte ser enviado
     
     
     flag_usart_rx=0;
     for(int contador=0;contador<RX_MAX_WAIT_TIME;contador++)
         {
          __delay_us(200);
          if(flag_usart_rx==1)
             {
             __delay_ms(2);             
             if(flag_is_buffer) 
                usart_buffer[5]=sizereturn;
             else
                usart_buffer[5]=2;
             
             for(i=0;i<usart_buffer[5];i++)
                 buffer[i]=usart_buffer[i+6]; 
             retorno = (usart_buffer[6]<<8)|(usart_buffer[7]);
             contador=0;
             break;
             }
          } 
     

       if(flag_usart_rx==0) 
         {
         usart_buffer[5]=2;  
         usart_buffer[6]=0xFF;
         usart_buffer[7]=0xFF;
         retorno=0xFFFF; 
         if(flag_is_buffer)     
           {  
           usart_buffer[5]=sizereturn;
           for(i=0;i<sizereturn;i++) usart_buffer[6+i]=0xFF;                       
           }
         }  
     flag_usart_rx=0;           
     return retorno;
}



int  Send_To_Slave_EMULA(char destino, char comando, char size, char * buffer)
{
	switch(destino)
	      {
	      case 0://printf("Erro no código. Endereco zero é da placa mae!");
	      	     break;
	      case 1:if(buffer[0]==0)                    
                        return 100;  //VOLTIMETRO                    
	             else
			return 200; //VACUO  
		     break;
	      case 2:if(buffer[0]==0)
	                return 300;   //CONDENSADOR
	             else
			return -1;   
		     break;
	      case 3:if(buffer[0]==0)                      
                        return 400;                    
	               else                    
                        return 500;//sin(tmp01)*500;                    				       
		       break;
	      case 4:if(buffer[0]==0)                      
                        return 600;                   
	               else                    
                        return 700;//sin(tmp01)*500;                    				       
		       break;
	      case 5:if(buffer[0]==0)                      
                        return 800;                    
	               else                    
                        return 900;//sin(tmp01)*500;                    				       
		       break;
	      case 6:if(buffer[0]==0)                      
                        return 1000;                    
	               else                    
                        return 1100;//sin(tmp01)*500;                    				       
		       break;
	      case 7:if(buffer[0]==0)                      
                        return 1200;                    
	               else                    
                        return 1300;//sin(tmp01)*500;                    				       
		       break;	  		 				 				 				 				 			 				 				 				 	
		  }
    return 0;
}
 




 
 
 
void ShowSensorRealTimeHS(void)
     {     
     char bb[3];
     char SlaveBoard;
     char canal;
     char tupla;
     int  vp, vpicone;
     
     //*NERA-TEMPORARIO
     //Estas variáveis devem ser apagadas
     static char flag_contabilizado=0;     
     
     
     //-------------------------LEITURA DAS PLACAS------------------------------
     //Faz leitura de todas as tuplas, inclusive da tupla vazia da placa 2.
     //Inicia no vetor numero zero.
     //-------------------------------------------------------------------------
     my_delay_ms(32);
     
     for(tupla=0;tupla<(totalboard*2);tupla++)
        { 
        SlaveBoard  = (tupla / 2)+1; 
        canal = tupla % 2;
        bb[0]=canal; 
        leitura[tupla]=Send_To_Slave(SlaveBoard, COMMAND_READ_ANALOG, 1, bb); //Alternar com EMULA
        
        if(leitura[tupla]==-1)         //Se a leitura der SEM PLACA
           {  
           if(erroSemPlaca[tupla]<10)  //Se o contador for menor que 10
             {  
             erroSemPlaca[tupla]++;    //Incrementar contador
             leitura[tupla]=0;         //Leitura da tupla igual a zero
             }
           }
        else
           {
           erroSemPlaca[tupla]=0;      //Se leitura de placa for valor válido
                                       //Zerar contador de erros e apresentar
                                       //a leitura.
           }        
        flag_array_slave_WDT[SlaveBoard]=TRUE;
        }
     
     //-------------------------------------------------------------------------
     if(Tamanho_Display==81)
       {      
       leitura[5]=leitura[6];  
       }
     
     //APAGAR ESTE TESTE
     /*
     leitura[0]=800;
     leitura[1]=700;
     leitura[2]=600;
     leitura[3]=500;
     leitura[4]=400;
     leitura[5]=300;
     leitura[6]=200;
     */
     
     //------------------------GRAVA NO DISPLAY---------------------------------
     my_delay_ms(50);
     flag_proculus_hs=TRUE; 
     for(tupla=0;tupla<(totalboard*2);tupla++)
        { 
        switch(tupla)
              {
              case 0://PLACA 1 CANAL 0 - VOLTIMETRO
                     PROCULUS_VP_Write_UInt16(153,leitura[tupla]);
                     Voltimetro=leitura[tupla];                     
                     break;               
              case 1://PLACA 1 CANAL 1 - VACUOMETRO
                     if((leitura[tupla]>=10)&&(leitura[tupla<=2000])) //Proteção contra erro de comunicação                         
                       {                   
                       PROCULUS_VP_Write_UInt16(151,leitura[tupla]); //Vacuometro 
                       Vacuometro=leitura[tupla];
                       }      
                     else
                       {
                       //=================REINICIAR SERIAL======================                         
                         char erro;                            
                         unsigned int reset;
                         INTCONbits.PEIE=0;                         
                         RCSTAbits.SPEN=0;
                         RCSTAbits.CREN=0;
                         RCSTAbits.FERR=0;
                         RCSTAbits.OERR=0;
                         TXSTAbits.TXEN=0;                         
                         erro=RCREG;
                         erro=RCREG;
                         erro=RCREG;                         
                         usart_buffer[0]=0;
                         TRISCbits.RC6=1;
                         TRISCbits.RC7=1;
                         //- - - - - - - - - - - - - - - - - -                         
                         reset=EEPROM_Read_Integer(34);
                         reset++;
                         EEPROM_Write_Integer(34,reset);
                         //- - - - - - - - - - - - - - - - - -                         
                         my_delay_ms_CLRWDT(1000);            
                         INTCONbits.PEIE=1;                         
                         //- - - - - - - - - - - - - - - - - - - - - - - - - - -
                         USART_init(115200);
                         //- - - - - - - - - - - - - - - - - - - - - - - - - - -                          
                       }  
                       
                     break;  
              case 2://Placa 2 Canal 0 - CONDENSADOR
                                                                   
                    PROCULUS_VP_Write_UInt16(150,leitura[tupla]);  
                    Condensador=leitura[tupla];
                     break; 
              case 3://Placa 2 Canal 1 - RESERVADO (UTILIZA O COMUM NO RELE)
                     //---------------------------------------------------------                          
                     //com sensor de condensador 1
                       
                     //sem sensor nesta tupla
                     break;
                     
              default:
                  if((Tamanho_Display==81)&&(tupla==6))  //Se houver uma placa de condensador com ID 4 (4a posicao)
                     {                                   //Então é liofilizador de 400 KG.
                     PROCULUS_VP_Write_UInt16(140,leitura[tupla]); ////Condensador         
                     //--------------------*NERA-TEMPORARIO---------------------
                     //Condensador1=leitura[tupla];                     
                     if(leitura[tupla]!=-1)         //Caso ocorra erro de comunicação,
                       {                            //Jamais considerar -1 como valor válido
                       Condensador1=leitura[tupla]; //Para não desligar o vácuo.
                       }                     
                     }
                  else
                     {
                     canal=tupla-4;
                     vp    = 230+(canal*TUPLA_VP_SIZE);
                     vpicone     = 400+canal;
                     PROCULUS_VP_Write_UInt16(vp+1,leitura[canal+4]);     
 
                     if(leitura[canal+4]<-400)PROCULUS_VP_Write_UInt16(vpicone,1); //sem sensor
                     else if(leitura[canal+4]==-1)PROCULUS_VP_Write_UInt16(vpicone,0); //sem placa                 
                     else PROCULUS_VP_Write_UInt16(vpicone,3); //Temperatura normal                                        
                      }                  
                  break;
              }  
        }
      flag_proculus_hs=FALSE;        
     
     }
 
 


 
 
 
 

void Carrega_Tupla_Receita(char index, t_receita *receita){
     unsigned int addeeprom;
     
     addeeprom=OFFSET_EEPROM_RECEITA+RECEITA_EEPROM_SIZE*index;
    
     receita->setpoint=EEPROM_Read_Integer(addeeprom+0); //Setpoint
     receita->potenciaON=EEPROM_Read_Byte (addeeprom+2); //Pot>
     receita->potenciaOFF=EEPROM_Read_Byte(addeeprom+3); //Pot<
     receita->histerese=EEPROM_Read_Byte  (addeeprom+4); //Histerese
     EEPROM_Read_String(addeeprom+5,texto); //Receita
     strcpy(receita->nome,texto);
}


   
     


void Grava_Receita(char index, t_receita *receita){
     unsigned int addeeprom;
     unsigned int vp;
     
     addeeprom=OFFSET_EEPROM_RECEITA+RECEITA_EEPROM_SIZE*index;
     
     EEPROM_Write_Integer(addeeprom+0 ,receita->setpoint); //Setpoint
     EEPROM_Write_Byte   (addeeprom+2 ,receita->potenciaON); //Pot>
     EEPROM_Write_Byte   (addeeprom+3 ,receita->potenciaOFF); //Pot<
     EEPROM_Write_Byte   (addeeprom+4 ,receita->histerese); //Histerese
     EEPROM_Write_String (addeeprom+5 ,receita->nome); //Receita
}


void Exibe_Receita(int index){
     unsigned int addeeprom;
     unsigned int vp;
     
     addeeprom=OFFSET_EEPROM_RECEITA+RECEITA_EEPROM_SIZE*index;
     vp       =OFFSET_VP_RECEITA+VP_RECEITA_SIZE*index;
     
     
     PROCULUS_VP_Write_UInt16(vp+0,EEPROM_Read_Integer(addeeprom));   //SetPoint
     PROCULUS_VP_Write_UInt16(vp+1,EEPROM_Read_Byte(addeeprom+2));    // POT>
     PROCULUS_VP_Write_UInt16(vp+2,EEPROM_Read_Byte(addeeprom+3));    // POT<
     PROCULUS_VP_Write_UInt16(vp+3,EEPROM_Read_Byte(addeeprom+4));    // Histerese
     EEPROM_Read_String(addeeprom+5,texto); //Receita
     texto[8]=0;
     PROCULUS_VP_Write_String(vp+4,texto);  // Nome da Receita 8 Letras   
}















 //------------------------------------------------------------------------------
//Alterar parametros de liofilizacao

void DataBaseBackupMain(unsigned char tupla)
      {
      unsigned int  vp;
      unsigned char addEEPROM;

      vp         = 230+(tupla*TUPLA_VP_SIZE);
      addEEPROM  = ((tupla)*TUPLA_EEPROM_SIZE)+OFFSET_EEPROM;
      
      
      //EEPROM_Write_Byte   (addEEPROM+0 ,tupla);//PROCULUS_VP_Read_UInt16(vp+0)); //Plataforma
      //----------------Reservado para leitura em tempo real -------------------
      EEPROM_Write_Integer(addEEPROM+1 ,PROCULUS_VP_Read_UInt16(vp+2)); //Setpoint
      EEPROM_Write_Byte   (addEEPROM+3 ,PROCULUS_VP_Read_UInt16(vp+3)); //Pot>
      EEPROM_Write_Byte   (addEEPROM+4 ,PROCULUS_VP_Read_UInt16(vp+4)); //Pot<
      EEPROM_Write_Byte   (addEEPROM+5 ,PROCULUS_VP_Read_UInt16(vp+5)); //Histerese
      PROCULUS_VP_Read_String(vp+6,texto);
      EEPROM_Write_String (addEEPROM+6 ,texto); //Receita
      EEPROM_Write_Integer(addEEPROM+16,PROCULUS_VP_Read_UInt16(vp+11)); //Status
      
      }


void FAT8_Save(unsigned char tupla){
     unsigned long addEEPROM;
     
     
     if(tupla>(maxlineDATALOG-1)) 
       {  
       if((PROCULUS_VP_Read_UInt16(2)==1)&&(PROCULUS_Get_Page()!=0))
         {
         PROCULUS_Buzzer(1000);       
         PROCULUS_VP_Write_UInt16(2,0);
         PROCULUS_Popup(LISTA_DE_DATALOG_COMPLETA);
         return;
         }
       }
     else
       {
       if(PROCULUS_Get_Page()!=0) //Não está inicializando
          { 
          if(PROCULUS_VP_Read_UInt16(2)==1) //Está Ligando o Datalog 
            {  
            //PROCULUS_Popup(DATALOG_INICIALIZADO_SUCESSO);
            //PROCULUS_VP_Write_String(1940,"Inicializando o Datalog...");
            //1940 neera  
            }
          }
       }
     

     //vp         = 0x1000+(tupla*FAT8_VP_SIZE);
     addEEPROM  = (tupla*EEPROM_FAT8_SIZE)+OFFSET_EEPROM_FAT8;
  
     EEPROM_24C1025_Write_Int (0,addEEPROM+0,  fat8.processo.processo_number);  //2
     EEPROM_24C1025_Write_Str (0,addEEPROM+2,  fat8.processo.inicio.time);      //10  
     EEPROM_24C1025_Write_Str (0,addEEPROM+12, fat8.processo.inicio.date);      //10
     EEPROM_24C1025_Write_Str (0,addEEPROM+22, fat8.processo.fim.time);         //10
     EEPROM_24C1025_Write_Str (0,addEEPROM+32, fat8.processo.fim.date);         //10
     EEPROM_24C1025_Write_Byte(0,addEEPROM+42, fat8.processo.amostra);          //1
     EEPROM_24C1025_Write_Long(0,addEEPROM+43, fat8.processo.add_start);        //4
     EEPROM_24C1025_Write_Long(0,addEEPROM+47, fat8.processo.add_end);          //4
     EEPROM_24C1025_Write_Int (0,addEEPROM+51, fat8.processo.minutes);          //2
     EEPROM_24C1025_Write_Byte(0,addEEPROM+53, fat8.processo.all_flags);        //1
     
     //PROCULUS_VP_Write_String(1940,"");
}


void Grava_Info_Aquecimento(char tupla)
{
    //t_receita receita[10];
    unsigned long addEEPROM;    
    
    for(char index=0;index<10;index++)
       {
       LoadLiofilizadorOnMemory(index, &liofilizador[index]);
       }
    
    for(char i=0;i<10;i++)
       {
       addEEPROM=(i*16)+0x2A0+(tupla*10*16); 
       EEPROM_24C1025_Write_Int (0,addEEPROM+ 0,liofilizador[i].setpoint);
       EEPROM_24C1025_Write_Byte(0,addEEPROM+ 2,liofilizador[i].tempoON);
       EEPROM_24C1025_Write_Byte(0,addEEPROM+ 3,liofilizador[i].tempoOFF);       
       EEPROM_24C1025_Write_Byte(0,addEEPROM+ 4,liofilizador[i].histerese);
       EEPROM_24C1025_Write_Str (0,addEEPROM+ 5,liofilizador[i].receita);
       EEPROM_24C1025_Write_Byte(0,addEEPROM+15,liofilizador[i].status);
       }
}
    


void FAT8_Load(unsigned char tupla){
     unsigned long addEEPROM;
     
     if(tupla>(maxlineDATALOG-1)) 
       {  
       return;
       } 
     
     addEEPROM  = (tupla*EEPROM_FAT8_SIZE)+OFFSET_EEPROM_FAT8;
     
     fat8.processo.processo_number=EEPROM_24C1025_Read_Int(0,addEEPROM+0);      //2
     EEPROM_24C1025_Read_Str(0, addEEPROM+2, fat8.processo.inicio.time);        //10
     EEPROM_24C1025_Read_Str(0, addEEPROM+12, fat8.processo.inicio.date);       //10
     EEPROM_24C1025_Read_Str(0, addEEPROM+22, fat8.processo.fim.time);          //10 
     EEPROM_24C1025_Read_Str(0, addEEPROM+32, fat8.processo.fim.date);          //10
     fat8.processo.amostra=EEPROM_24C1025_Read_Byte  (0,addEEPROM+42);          //1
     fat8.processo.add_start=EEPROM_24C1025_Read_Long(0,addEEPROM+43);          //4
     fat8.processo.add_end=EEPROM_24C1025_Read_Long  (0,addEEPROM+47);          //4
     fat8.processo.minutes=EEPROM_24C1025_Read_Int   (0,addEEPROM+51);          //2     
     fat8.processo.all_flags=EEPROM_24C1025_Read_Byte(0,addEEPROM+53);          //1
}

void FAT8_Show(){
     unsigned int  vp;
     
     for(char tupla=0;tupla<maxlineDATALOG;tupla++)
        { 
        vp=0x1000+(tupla*FAT8_VP_SIZE);
        FAT8_Load(tupla);     
        PROCULUS_VP_Write_UInt16(vp+0,fat8.processo.processo_number);
        PROCULUS_VP_Write_String(vp+1,fat8.processo.inicio.date);
        PROCULUS_VP_Write_String(vp+11,fat8.processo.inicio.time);
        PROCULUS_VP_Write_UInt16(vp+21,fat8.processo.minutes);
        
        
    
        PROCULUS_VP_Write_UInt16(vp+24,fat8.processo.add_start);
        PROCULUS_VP_Write_UInt16(vp+25,fat8.processo.add_end); 
        }
     
}









//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//Salva uma tupla do liofilizador na memoria EEPROM interna com o endereço
//inicial igual OFFSET_EEPROM.
 void SaveLiofilizadorOnMemory(char index,t_liofilizador *liofilizador)
      {
      char CanalAD;
      unsigned char addEEPROM;
      addEEPROM  = (index*TUPLA_EEPROM_SIZE)+OFFSET_EEPROM;
      CanalAD    = (unsigned char) (index % 2);
      
      EEPROM_Write_Byte(addEEPROM+0,liofilizador->plataforma);
      //------ RESERVADO PARA LEITURA EM TEMPO REAL ----------
      EEPROM_Write_Integer(addEEPROM    +1 , liofilizador->setpoint);
      EEPROM_Write_Byte(addEEPROM       +3 , liofilizador->tempoON);
      EEPROM_Write_Byte(addEEPROM       +4 , liofilizador->tempoOFF);
      EEPROM_Write_Byte(addEEPROM       +5 , liofilizador->histerese);
      EEPROM_Write_String(addEEPROM     +6 , liofilizador->receita);
      EEPROM_Write_Integer(addEEPROM   +16 , liofilizador->status);
      }
      

 
 
 //XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
//Salva uma tupla do liofilizador na memoria EEPROM interna com o endereço
//inicial igual OFFSET_EEPROM.
 void LoadLiofilizadorOnMemory(char index,t_liofilizador *liofilizador)
      {
      //char CanalAD;
      unsigned char addEEPROM;
      addEEPROM  = (index*TUPLA_EEPROM_SIZE)+OFFSET_EEPROM;
      //CanalAD    = (unsigned char) (index % 2);
      
      liofilizador->plataforma= EEPROM_Read_Byte(addEEPROM+0);
      //------ RESERVADO PARA LEITURA EM TEMPO REAL ----------
      liofilizador->setpoint  = EEPROM_Read_Integer(addEEPROM+ 1);
      liofilizador->tempoON   = EEPROM_Read_Byte(addEEPROM   + 3);
      liofilizador->tempoOFF  = EEPROM_Read_Byte(addEEPROM   + 4);
      liofilizador->histerese = EEPROM_Read_Byte(addEEPROM   + 5);
      EEPROM_Read_String(addEEPROM + 6,liofilizador->receita);
      liofilizador->status    = EEPROM_Read_Integer(addEEPROM+16);
      }

 
 
 
 
 
 
 
 
 
 
 
 
 
 void Set_Receita(unsigned char index, char status)
      {
      int  vp;
      //unsigned int addEEPROM;

      //addEEPROM   = OFFSET_EEPROM_RECEITA+RECEITA_EEPROM_SIZE*index;
      vp          = 230+(index*TUPLA_VP_SIZE);              
     
      PROCULUS_VP_Write_UInt16(vp+2,receita.setpoint);     
      PROCULUS_VP_Write_UInt16(vp+3,receita.potenciaON);   
      PROCULUS_VP_Write_UInt16(vp+4,receita.potenciaOFF);  
      PROCULUS_VP_Write_UInt16(vp+5,receita.histerese);    
      PROCULUS_VP_Write_String(vp+6,receita.nome);
      if(status==TRUE)
         PROCULUS_VP_Write_UInt16(vp+11,1); //Status                            
      else
         PROCULUS_VP_Write_UInt16(vp+11,0); //Status 
      }
  
 

 
//-----------------------------------------------------------------------------
 //Preenchimento de dados estaticos da tela principal
 void ShowStaticValueGrid(unsigned char tupla)
      {
      char CanalAD;
      char SlaveBoard;
      int  vp, vpicone;
      char  bb[2];
      unsigned char addEEPROM;
      int temperatura;


      addEEPROM   = (tupla*TUPLA_EEPROM_SIZE)+OFFSET_EEPROM;
      CanalAD     = (unsigned char) (tupla % 2);
      bb[0]       = CanalAD;
      SlaveBoard  = (unsigned char) (tupla / 2)+1;
      vp          = 230+(tupla*TUPLA_VP_SIZE);              


      if(tupla>=4){
         tupla-=4;
         addEEPROM   = (tupla*TUPLA_EEPROM_SIZE)+OFFSET_EEPROM;
         CanalAD     = (unsigned char) (tupla % 2);
         bb[0]       = CanalAD;
         SlaveBoard  = (unsigned char) (tupla / 2)+1+2;
         vp          = 230+(tupla*TUPLA_VP_SIZE);
         vpicone     = 400+tupla;               
         PROCULUS_VP_Write_UInt16(vp+0,EEPROM_Read_Byte    (addEEPROM+0)+1); //Plataforma
         PROCULUS_VP_Write_UInt16(vp+2,EEPROM_Read_Integer (addEEPROM+1)); //SetPoint 1e2
         PROCULUS_VP_Write_UInt16(vp+3,EEPROM_Read_Byte    (addEEPROM+3)); //Pot>
         PROCULUS_VP_Write_UInt16(vp+4,EEPROM_Read_Byte    (addEEPROM+4)); //Pot<
         PROCULUS_VP_Write_UInt16(vp+5,EEPROM_Read_Byte    (addEEPROM+5)); //Histerese
         EEPROM_Read_String(addEEPROM+6,texto); //Nome da Receita
         PROCULUS_VP_Write_String(vp+6,texto);
         PROCULUS_VP_Write_UInt16(vp+11,EEPROM_Read_Integer(addEEPROM+16)); //Status                             
         }
} 


 

 
 

//Salva e atualiza grafico
void save_datalog(unsigned long add_datalog){
     char index;
     char bb[4];
     char boardadd;
     
     //===================================================================================
     bb[0]=High (add_datalog);
     bb[1]=Lower(add_datalog);
     bb[2]=Hi   (add_datalog);
     bb[3]=Lo   (add_datalog);
     Send_To_Slave(TODOS, COMMAND_SAVE_LOG , 4, bb);
     //===================================================================================
     //Faz o grafico em tempo real
     for(index=0;index<(totalboard*2);index++)
	 {
         if(mapa.entrada[index]!=NULL) 
            {	
            PROCULUS_graphic_plot(mapa.canal[index]+1,*mapa.entrada[index]*mapa.fator[index]);
            }
         }      
}


 

//------------------------------------------------------------------------------
 //Alterar parametros de liofilizacao
 //Rolar tela para visualizar os outros dados
 //Salvar dados
 //Código Funcionando Perfeitamente
 void ShowAndSetSlaveParameters(unsigned char tupla)
      {
      unsigned char CanalAD;
      unsigned char SlaveBoard;
      unsigned char addEEPROM;
      unsigned int  vp;
      unsigned char bb[2];
      //char texto[15];
 
      vp         = 230+(tupla*TUPLA_VP_SIZE);
      //tupla     += offset;
      addEEPROM  = (tupla*TUPLA_EEPROM_SIZE)+OFFSET_EEPROM;
      CanalAD    = (unsigned char) (tupla % 2);
      SlaveBoard = (unsigned char) (tupla / 2);

      bb[0]      = CanalAD;
      //PROCULUS_VP_Write_UInt16(vp+0,EEPROM_Read_Byte(addEEPROM+0)); //---------------------   //Plataforma
      
      //PROCULUS_VP_Write_UInt16(170,((tupla/9.0)*100.0)); //Progresso em porcentagem
      
      //-- NESTA POSICAO (vp+1) é feito a leitura em tempo real        //Temperatura em tempo real
      
      PROCULUS_VP_Write_UInt16(vp+2,EEPROM_Read_Integer(addEEPROM+1));  //SetPoint
      PROCULUS_VP_Write_UInt16(vp+3,EEPROM_Read_Byte   (addEEPROM+3));  ///Pot>
      PROCULUS_VP_Write_UInt16(vp+4,EEPROM_Read_Byte   (addEEPROM+4));  //Pot<
      PROCULUS_VP_Write_UInt16(vp+5,EEPROM_Read_Byte   (addEEPROM+5));  //Histerese
      EEPROM_Read_String (addEEPROM+6,texto);
      PROCULUS_VP_Write_String(vp+6,texto);                             //Receita
      PROCULUS_VP_Write_UInt16(vp+11,EEPROM_Read_Integer(addEEPROM+16));//Status
       
      }








//------------------------------------------------------------------------------
void Send_to_PC(unsigned char size){
//     unsigned char i;
     //
     USART_put_int(HEADER_LIOFILIZADOR);
     USART_putc(usart_protocol.destino);
     USART_putc(usart_protocol.origem);
     USART_putc(usart_protocol.command);
     USART_putc(size);
     
     //USART_putc(0x0D);
     //USART_putc(0x17);
     /*        
     USART_put_int(usart_protocol.header);
     USART_putc(BOARD_ADD);
     USART_putc(0xC0);
     USART_putc(usart_protocol.command);
     USART_putc(size);
     */ 
}




void Comando_Microcomputador(void){
     USART_to_Protocol(&usart_protocol);
     if(usart_protocol.header==HEADER_LIOFILIZADOR)
        if(usart_protocol.destino==BOARD_ADD) 
        { 
        Decodify_Command();
        flag_usart_rx=0;
        }    
}




//------------------------------------------------------------------------------
void Decodify_Command(void){
    int  dados;
    char tempchar;
    int  tempint;
    unsigned long add_24LCxxxx;
    unsigned char add_Chip;
    
    
    add_Chip = usart_protocol.value[0];
    High(add_24LCxxxx)=(usart_protocol.value[1]);
    Lower(add_24LCxxxx)=(usart_protocol.value[2]);
    Hi(add_24LCxxxx)=(usart_protocol.value[3]);
    Lo(add_24LCxxxx)=(usart_protocol.value[4]);    
    
    //__delay_ms(50);

    switch(usart_protocol.command){
        /*
        case COMMAND_PING:
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case COMMAND_PONG:
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case COMMAND_POWER_ON:
             Send_to_PC(3);
             SEND_REPLY_OK();
             POWER_ON();
             break;
        case COMMAND_POWER_OFF:
             Send_to_PC(3);
             SEND_REPLY_OK();
             POWER_OFF();
             break;
        case COMMAND_UPDATE_ON:
             Send_to_PC(3);
             SEND_REPLY_OK();
             UPDATE_ENABLE();
             break;
        case COMMAND_UPDATE_OFF:
             Send_to_PC(3);
             SEND_REPLY_OK();
             UPDATE_DISABLE();
             break;
         */ 
        //---------------------- EEPROM INTERNA --------------------------------
        case COMMAND_IEE_W_BYTE:
             EEPROM_Write_Byte((int)usart_protocol.value[0]<<8 | //____Endereco 0x3FF
                               (int)usart_protocol.value[1]<<0,  //
                               usart_protocol.value[2]  
                               );
             Send_to_PC(3);
             SEND_REPLY_OK();
             Recarregar_Parametros_de_Configuracao();
             break;
        case COMMAND_IEE_R_BYTE:
             tempchar=EEPROM_Read_Byte((int)usart_protocol.value[0]<<8 |
                                       (int)usart_protocol.value[1]<<0
                                       );            
             Send_to_PC(1);
             USART_putc(tempchar);              
             break;
        case COMMAND_IEE_W_INT:
             {
             int add;
             int dado;
             add=  (int)(usart_protocol.value[0]<<8) | (int)usart_protocol.value[1]<<0;
             dados=(int)(usart_protocol.value[2]<<8) | (int)usart_protocol.value[3]<<0;
             EEPROM_Write_Integer(add,dados);
             Send_to_PC(3);
             SEND_REPLY_OK();
             Recarregar_Parametros_de_Configuracao();
             }
             break;
        case COMMAND_IEE_R_INT:
             tempint=EEPROM_Read_Integer((int)usart_protocol.value[0]<<8 |
                                         (int)usart_protocol.value[1]<<0
                                          );         
             Send_to_PC(2);
             USART_put_int(tempint);
             break;
             
        case COMMAND_IEE_W_STR :
             EEPROM_Write_String((int)usart_protocol.value[0]<<8 |
                                 (int)usart_protocol.value[1]<<0 ,
                                     &usart_protocol.value[2]);       
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;            
        case COMMAND_IEE_R_STR:
             {
             //unsigned char texto[20];
             EEPROM_Read_String((int)usart_protocol.value[0]<<8 |
                                (int)usart_protocol.value[1]<<0 ,
                                 texto);
             Send_to_PC(sizeof(texto));
             USART_put_string(texto);
             break;
             }

        //---------------------- EEPROM EXTERNA --------------------------------
        case COMMAND_EEE_W_BYTE:
             EEPROM_24C1025_Write_Byte(usart_protocol.value[0],      //CHIP NUMBER
                                                  add_24LCxxxx,      //ADD of Memory                                                  
                                       usart_protocol.value[5]);     //VALUE
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case COMMAND_EEE_R_BYTE:
             tempchar=EEPROM_24C1025_Read_Byte(usart_protocol.value[0],  //CHIP NUMBER
                                                         add_24LCxxxx);  //ADD of Memory
             
             
             Send_to_PC(1);
             USART_putc(tempchar);
             break;
        case COMMAND_EEE_W_INT:
             {
             EEPROM_24C1025_Write_Int(usart_protocol.value[0],  //CHIP NUMBER
                                                 add_24LCxxxx,  //Add of memory
                                   (int)usart_protocol.value[5]<<8 |
                                        usart_protocol.value[6]                                  
                                                             );  //
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
             }
        case COMMAND_EEE_R_INT:
             tempint=EEPROM_24C1025_Read_Int(usart_protocol.value[0],    //CHIP NUMBER
                                                       add_24LCxxxx);
             Send_to_PC(2);
             USART_put_int(tempint);
             break;
             
        case COMMAND_EEE_W_32B:
             {
                 
             }
             break;
             
        case COMMAND_EEE_R_32B:     
             {
             unsigned long retorno32b;    
             retorno32b=EEPROM_24C1025_Read_Long(usart_protocol.value[0],    //CHIP NUMBER
                                                          add_24LCxxxx);
             Send_to_PC(4);
             USART_putc(High(retorno32b));
             USART_putc(Lower(retorno32b));             
             USART_putc(Hi(retorno32b));
             USART_putc(Lo(retorno32b));
             }
             break;
        case COMMAND_EEE_R_BUF:
             {                 
             char sizedata;
             sizedata=usart_protocol.value[5];
             Send_to_PC(sizedata);             
             EEPROM_24C1025_Read_Buffer_to_USART(add_Chip,     //CHIP NUMBER
                                                 add_24LCxxxx, //Add of memory
                                                 sizedata,     //SIZEDATA
                                                 buffer);      //Buffer of data              
             //USART_put_buffer(buffer,sizedata); 
             }
             break;
             
        case COMMAND_EEE_W_BUF: 
             EEPROM_24C1025_Write_Buffer(usart_protocol.value[0],     //CHIP NUMBER
                                         add_24LCxxxx,     //ADD Long
                                         usart_protocol.value[5],     //SIZEDATA
                                         &usart_protocol.value[6]);    //Inicio do Buff
             
             Send_to_PC(3);
             SEND_REPLY_OK();            
             break;                    

        case COMMAND_EEE_W_STR :
             EEPROM_24C1025_Write_Str(usart_protocol.value[0],   //CHIP NUMBER
                                                 add_24LCxxxx,   //ENDERECO 24LCXXXX
                                    &usart_protocol.value[5]);   //Ponteiro String
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        case COMMAND_EEE_R_STR:
             {
             EEPROM_24C1025_Read_Str(usart_protocol.value[0],       //CHIP NUMBER
                                                add_24LCxxxx,   //ENDERECO 24LCXXXX
                                                      texto);
                      
             Send_to_PC(strlen(texto));
             USART_put_string(texto);
             break;
             }

        case COMMAND_EEE_FILL_ALL:
             EEPROM_24C1025_Fill_All(usart_protocol.value[0], //chip_add, 
                               (int)(usart_protocol.value[1]<<8)|//unsigned char value
                                     usart_protocol.value[2]);
             Send_to_PC(3);
             SEND_REPLY_OK();            
             break;
             
          
        case COMMAND_PROC_CLOCK_R:             
             Send_to_PC(2);
             USART_putc(processo_hora);
             USART_putc(processo_minuto);
             break;
             
        case COMMAND_CLK_RTC_R:
             {
             char date[10];
             char time[10];

             PROCULUS_Read_RTC(date,time);             
             Send_to_PC(9);
             if((usart_protocol.value[0])==0)
                {                 
                USART_put_string(date);                
                }  
             else
                {                  
                USART_put_string(time);  //  HH:MM:SS                
                }
             
             }
             break; 
             
        case COMMAND_CLK_RTC_W:
             {
             char date[10];
             char time[10];
             char i;
             
             for(i=0;i<8;i++)
                {
                date[i]=usart_protocol.value[i];
                }
             date[8]=0;
             
             for(i=0;i<8;i++)
                {
                time[i]=usart_protocol.value[i+8];
                }
             time[8]=0;
             
             PROCULUS_Write_RTC(date,time);
             
             }
             break;
             
        case COMMAND_LCD_W_VP_INT:
             PROCULUS_VP_Write_Int16((usart_protocol.value[0]<<8)|
                                     (usart_protocol.value[1]<<0),
                                     (usart_protocol.value[2])<<0|
                                     (usart_protocol.value[3])<<8);
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
             
        case COMMAND_LCD_R_VP_INT:
             {           
             PORTDbits.RD5=1; //Fix Apagar Debug                  
             tempint=PROCULUS_VP_Read_Int16((usart_protocol.value[0]<<8)+
                                             (usart_protocol.value[1]));

             PORTDbits.RD5=0; //Fix Apagar Debug              
             PORTDbits.RD5=1; //Fix Apagar Debug   
             Send_to_PC((strlen(texto)));
             USART_put_int(tempint);
             PORTDbits.RD5=0; //Fix Apagar Debug
             break;
             }
        
        /*
        case COMMAND_LCD_W_VP_STR:
            
            break;
        
        case COMMAND_LCD_R_VP_STR:
            
            break; 
        */    

        case COMMAND_PROCULUS_Buzzer:
             PROCULUS_Buzzer((usart_protocol.value[0]<<8)+
                             (usart_protocol.value[1]));
             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        
        case COMMAND_LDC_PAGE:
             PROCULUS_Show_Screen((usart_protocol.value[0]<<8)+
                                  (usart_protocol.value[1]));
             Send_to_PC(3);
             SEND_REPLY_OK();            
             break;
        
        case COMMAND_CONTROL_ACTIVE: 
             PROCULUS_Popup(usart_protocol.value[0]);
             Send_to_PC(3);
             SEND_REPLY_OK();         
             break;
        
        case COMMAND_READ_INTERVAL:
             tempint=EEPROM_Read_Integer(0x09);             
             Send_to_PC(2);
             USART_put_int(tempint);
             //SEND_REPLY_OK();             
             break;
             
        case COMMAND_SHOW_PROGRAM:
             //for(char i=0;i<15;i++)
             ShowStaticValueGrid(usart_protocol.value[0]+4);
             Send_to_PC(3);
             SEND_REPLY_OK();            
             break;
        
        case COMMAND_READ_TOTALBOARD:
             Send_to_PC(1);
             USART_putc(totalboard);
             break;
             
        case COMMAND_FORMAT:
             Formatar_Banco_de_Dados(0,10);
             for(char i=0;i<15;i++) ShowStaticValueGrid(i);
             Send_to_PC(3);
             SEND_REPLY_OK();             
             break;
        
        case COMMAND_UPLOAD_PRG:
             Upload_Data_to_Slave();
             Send_to_PC(3);
             SEND_REPLY_OK();                         
             break;
             
        case COMMAND_LCD_W_VP_STR:
             PROCULUS_VP_Write_String((usart_protocol.value[0]<<8)|
                                      (usart_protocol.value[1]),
                                     &(usart_protocol.value[2]));

             Send_to_PC(3);
             SEND_REPLY_OK();
             break;
        
        case COMMAND_LCD_R_VP_STR:
             {             
             PROCULUS_VP_Read_String((usart_protocol.value[0]<<8)+
                                     (usart_protocol.value[1]),
                                      texto);
             Send_to_PC((strlen(texto)));
             USART_put_string(texto);
             break;
             }
        case COMMAND_READ_PROCESS:
             tempint=EEPROM_24C1025_Read_Int (0,0);
             tempint++;
             Send_to_PC(2);
             USART_put_int(tempint);             
             //EEPROM_24C1025_Write_Int (0,0,tempint);
             break;
        
        case COMMAND_CHANGE_FLAG:    
             switch(usart_protocol.value[0])
                {  
                case 2:if(usart_protocol.value[1]>0)
                          flag_autoriza_click_datalog=1;
                       else           
                          flag_autoriza_click_datalog=0;                           
                       break;
                       
                case 3:if(usart_protocol.value[1]>0)
                          flag_autoriza_click_condensador=1;
                       else           
                          flag_autoriza_click_condensador=0;                           
                       break;
                       
                case 4:if(usart_protocol.value[1]>0)
                          flag_autoriza_click_vacuo=1;
                       else           
                          flag_autoriza_click_vacuo=0;                           
                       break;
                       
                case 5:if(usart_protocol.value[1]>0)
                          flag_autoriza_click_aquecimento=1;
                       else           
                          flag_autoriza_click_aquecimento=0;                           
                       break;                       
                }
             Send_to_PC(3);
             SEND_REPLY_OK();            
             break;        
    }
}

void SEND_REPLY_OK(void){
     USART_put_string("OK");
}


void Comando_Protocolo_Serial(void){
 //======================= COMUNICACAO COM O PC =========================
        unsigned char size, i, DestinoMemo, ComandoMemo;
               
        USART_to_Protocol(&usart_protocol);
        if(usart_protocol.header==HEADER_LIOFILIZADOR)   
            {            
            if(usart_protocol.origem==0xC0)
                {
                Delay_Led_Usart=DEFAULT_LEDS;
                if(usart_protocol.destino==0x00)
                   {
                   Decodify_Command();
                   flag_usart_rx=0;
                   }
                else //Destino Placa Filha
                   { 
                   /*
                   Origem = 0XC0
                   Destino= 0X01 a 0X0F
                   */
                   DestinoMemo=usart_protocol.destino;
                   Send_To_Slave(usart_protocol.destino,
                                 usart_protocol.command,
                                 usart_protocol.size,
                                 usart_protocol.value
                                 );
                   flag_usart_rx=0;
                   
                   /*
                   Origem = 0x01 a 0x0F
                   Destino = 0x00                  
                   */
                   
                   
                   USART_to_Protocol(&usart_protocol);
                   USART_put_int(HEADER_LIOFILIZADOR);
                   USART_putc(DestinoMemo);//usart_protocol.origem);// 0X01 a 0x0F
                   USART_putc(0xC0);
                   USART_putc(usart_protocol.command);
                   USART_putc(usart_protocol.size);                                                         
                   for(i=0;i<usart_protocol.size;i++)
                         USART_putc(usart_protocol.value[i]);
                   //SEND_REPLY_OK();
                   
                   flag_usart_rx=0;               
                   }
                }
        flag_usart_rx=0;     
        }//HEADER_LIOFILIZADOR
}






void Formatar_Banco_de_Dados(char inicio, char total){
     for(char j=inicio;j<(inicio+total);j++)
          {
          //flag_main_loop_WDT=1;
          liofilizador[j].plataforma=j;          
          liofilizador[j].setpoint=0;
          liofilizador[j].tempoON=0;
          liofilizador[j].tempoOFF=0;
          liofilizador[j].histerese=0;
          strcpy(liofilizador[j].receita," ");          
          liofilizador[j].status=0;      
          SaveLiofilizadorOnMemory(j,&liofilizador[j]);          
          }
    
}


//Provavel ponto que está dando erro
void Upload_Data_to_Slave(void){
     char index;   
     char board;
     char canal;
     char addEEPROM;
     char buffer[3];
     int  temp;
     

     for(index=4;index<15;index++){
         board=(index/2)+1;
         canal=(index%2);         
         addEEPROM  = ((index-4)*TUPLA_EEPROM_SIZE)+OFFSET_EEPROM;
         
         //-----------------------PLATAFORMA--------------------------
         //temp=EEPROM_Read_Integer(addEEPROM+0);
         
         //-----------------------SETPOINT--------------------------
         temp=EEPROM_Read_Integer(addEEPROM+1);
         buffer[0]=(canal*7)+0;
         buffer[1]=Hi(temp);
         buffer[2]=Lo(temp);
         Send_To_Slave(board,COMMAND_IEE_W_INT,3,buffer);
         __delay_ms(150);
         //-----------------------TEMPO ON---------------------------
         buffer[0]=(canal*7)+2;
         buffer[1]=EEPROM_Read_Byte(addEEPROM+3);
         Send_To_Slave(board,COMMAND_IEE_W_BYTE,2,buffer);
         __delay_ms(150);
         //-----------------------TEMPO OFF---------------------------
         buffer[0]=(canal*7)+3;
         buffer[1]=EEPROM_Read_Byte(addEEPROM+4);
         Send_To_Slave(board,COMMAND_IEE_W_BYTE,2,buffer);   
         __delay_ms(150);
         //----------------------- HISTERESE---------------------------
         buffer[0]=(canal*7)+4;
         buffer[1]=EEPROM_Read_Byte(addEEPROM+5);
         Send_To_Slave(board,COMMAND_IEE_W_BYTE,2,buffer);  
         __delay_ms(150);
         //-----------------------STATUS------------------------------
         temp=EEPROM_Read_Integer(addEEPROM+16);
         buffer[0]=(canal*7)+5;
         buffer[1]=Hi(temp);
         buffer[2]=Lo(temp);
         Send_To_Slave(board,COMMAND_IEE_W_INT,3,buffer); 
         __delay_ms(150);
         if(canal==1) Send_To_Slave(board,COMMAND_LOAD_WORK,0,buffer); // Status
        
         }

}



void ShowMessage(char mensagem[20],unsigned int delay, char SoundType, char retem){
     char texto[30];
     //unsigned char center=0;
     //if (SoundType==SOUND_OK) PROCULUS_OK();
     strcpy(texto,"                             ");
     texto[(30-strlen(mensagem))/2]=0;
     strcat(texto,mensagem);
     PROCULUS_VP_Write_String(180,texto);
     my_delay_ms(delay);
     if(!retem) PROCULUS_VP_Write_String(180,"");
}



void global_porta(void){
     char bbb[2];    
     if((PROCULUS_VP_Read_UInt16(19)==1)&&(flag_global_porta==0))
       {
         flag_global_porta=1;
         bbb[0]=1; //Rele 1 da placa PT100
         bbb[1]=1; //ESTADO LIGADO             
         Send_To_Slave(0x02,COMMAND_RELAY,2,bbb);          
       }
     
     if((PROCULUS_VP_Read_UInt16(19)==0)&&(flag_global_porta==1))
       {  
         flag_global_porta=0;
         bbb[0]=1; //Rele 1 da placa PT100
         bbb[1]=0; //ESTADO DESLIGADO             
         Send_To_Slave(0x02,COMMAND_RELAY,2,bbb);           
       }       
}


void global_datalog(void){
    
        if((PROCULUS_VP_Read_UInt16(2)==1)&&(flag_global_datalog==0)) //LIGAR
           {
            char bb[2];            
            
            if(testa_modo_conectado(2,0)==0) 
              {  
              PROCULUS_Popup(DISPLAY_BLOQUEADO);
              return;
              }  
            flag_global_datalog=1;           
            if(flag_pc_conected==FALSE)
                {    
                Send_To_Slave(TODOS, COMMAND_SYNCRONIZE , 0, bb);
                Carregar_tempo_de_datalog(); 
                if(Find_Fat8_Running()==-1) //Se nao está rodando datalog
                  {                
                  PROCULUS_Clean_All_Line_Graphic();                
                  FAT8_Write_Process_Inicialize();              
                  Grava_Info_Aquecimento(Find_Fat8_Free()-1);//Grava info para relatorio
                  }
                else
                  {  
                  fat8.index=Find_Fat8_Running();
                  if(fat8.index!=-1)
                     {                                     
                     FAT8_Load(fat8.index); 
                     add_datalog=EEPROM_24C1025_Read_Long (0,2); 
                     processo_totalminuto=EEPROM_24C1025_Read_Int(0,6);
                     fat8.processo.add_end=add_datalog;
                     }              
                  }
                }
            else //O computador está executando o trabalho
                {    
                FAT8_Write_Process_Inicialize();              
                Grava_Info_Aquecimento(Find_Fat8_Free()-1);//Grava info para relatorio                
                }
            
           }
        else if((PROCULUS_VP_Read_UInt16(2)==0)&&(flag_global_datalog==1)) //Desligar
               {
            
               if(testa_modo_conectado(2,1)==0) 
                 {  
                 PROCULUS_Popup(DISPLAY_BLOQUEADO);  
                 return;
                 }                   
               flag_global_datalog=0;
               FAT8_Write_Process_Finalize();               
               }       
}




void Condensador_Switch(unsigned char estado){
     char buffer[2];
     buffer[0]=0;
     buffer[1]=estado; 
     Send_To_Slave(0x02,COMMAND_RELAY,2,buffer);
}

void Vaccum_Switch(unsigned char estado){
     char buffer[2];
     buffer[0]=0;
     buffer[1]=estado;
     Send_To_Slave(0x01,COMMAND_RELAY,2,buffer);          
}


void global_condensador(void){     
        if((PROCULUS_VP_Read_UInt16(0x03)==1)&&(flag_global_condensador==0))
            {
            if(testa_modo_conectado(3,0)==0) 
              {  
              PROCULUS_Popup(DISPLAY_BLOQUEADO);  
              return;
              }
            
            if(!DelayBackupReturn(0x03, &timerCondensador,"Acionando Condensador! Aguarde...")) return;
            
            if(delay_condensador==0) //Aguarda os 30 segundos para ativar condensador
               {
               flag_global_condensador=1; 
               Condensador_Switch(ON);              
               }
            else
               {
               PROCULUS_Buzzer(1000);
               PROCULUS_Popup(AGUARDE_30_SEGUNDOS);
               PROCULUS_VP_Write_UInt16(0x03,0); 
               } 
            }
        else
        if((PROCULUS_VP_Read_UInt16(0x03)==0)&&(flag_global_condensador==1))
           {
           if(testa_modo_conectado(3,1)==0) 
              {  
              PROCULUS_Popup(DISPLAY_BLOQUEADO);  
              return;
              }               
           flag_global_condensador=0; 
           Condensador_Switch(OFF);
           timerCondensador=0;
           delay_condensador=30; //Intervalo para conseguir religar o condensador
           }    
        else
        if((PROCULUS_VP_Read_UInt16(0x03)==1)&&(flag_global_condensador==1))        
           {
           //Não exite dependência a ser checada 
           }
        else
        if((PROCULUS_VP_Read_UInt16(0x03)==0)&&(flag_global_condensador==0))            
           {
           timerCondensador=0; 
           }
}




void global_vacuo(void){ 
        char count;   

        if((PROCULUS_VP_Read_UInt16(0x04)==1)&&(flag_global_vacuo==0)) 
           {  
           if(testa_modo_conectado(4,0)==0) 
             {  
             PROCULUS_Popup(DISPLAY_BLOQUEADO);  
             return; 
             }
               
           if(Condensador<Seg_Condensador)
              {               
              if(!DelayBackupReturn(0x04, &timerVacuo,"Acionando Vacuo! Aguarde...")) return;
              flag_global_vacuo=1;
              Vaccum_Switch(TRUE);              
              Contagem_Tempo_de_Processo(TRUE);               
              }
           else
              { 
              Vaccum_Switch(FALSE); 
              Incrementa_Contador_de_Repique_do_Vacuo();              
              }
           }
        else if((PROCULUS_VP_Read_UInt16(0x04)==0)&&(flag_global_vacuo==1))
                {                
                if(testa_modo_conectado(4,1)==0)
                  {  
                  PROCULUS_Popup(DISPLAY_BLOQUEADO);  
                  return;
                  }                    
                flag_global_vacuo=0;
                Vaccum_Switch(FALSE); 
                timerVacuo=0;
                PROCULUS_VP_Write_UInt16(6,0);                
                MSG_Deseja_Encerrar_Processo=1;                                   
                }
        else if((PROCULUS_VP_Read_UInt16(0x04)==1)&&(flag_global_vacuo==1))
                {
                if(Condensador<(Seg_Condensador))   //Histerese do condensador = -3
                   {                    
                   flag_Vacuo_estava_ligado=1; 
                   Vaccum_Switch(TRUE);                     
                   }
                else
                   { 
                   Vaccum_Switch(FALSE);   
                   Incrementa_Contador_de_Repique_do_Vacuo();
                   }            
                }
        else if((PROCULUS_VP_Read_UInt16(0x04)==0)&&(flag_global_vacuo==0))
                {
                timerVacuo=0; 
                }
}        


void Global_Aquecimento_Switch(unsigned char estado){
     char buffer[2]; 
     unsigned char board;
     
     if(Tamanho_Display!=81) Rele_Comum_Aquecimento(estado);
     
     for(board=3;board<(totalboard*2-1);board++)
        {
        buffer[0]=estado;
        Send_To_Slave(board,COMMAND_GLOBAL_HOT,1,buffer);               
        }     
}


void global_aquecimento(void){  
        if(testa_modo_conectado(5,1)==0)
          {  
          PROCULUS_Popup(DISPLAY_BLOQUEADO);  
          return;
          }    
        
        
        if((PROCULUS_VP_Read_UInt16(5)==1)&&(flag_global_aquecimento==0))
           {              
           if((Condensador<Seg_Aq_cond)&&(Vacuometro<Seg_Aq_vacuo)) 
              { 
              if(!DelayBackupReturn(0x05, &timerAquecimento,"Acionando Aquecimento! Aguarde...")) return;               
              
              flag_global_aquecimento=1;
              Global_Aquecimento_Switch(ON); 
              }
           else
              {
              flag_global_aquecimento=0; 
              Global_Aquecimento_Switch(OFF); 
              timerAquecimento=0;
              } 
           }    
           
        else
        if((PROCULUS_VP_Read_UInt16(5)==0)&&(flag_global_aquecimento==1))
           {           
           flag_global_aquecimento=0; 
           Global_Aquecimento_Switch(OFF); 
           //if((Tamanho_Display==80)||(Tamanho_Display==50))
           //    Rele_Comum_Aquecimento(FALSE);            
           }    
        else
        if((PROCULUS_VP_Read_UInt16(5)==1)&&(flag_global_aquecimento==1))
           {           
           if((Condensador<Seg_Aq_cond)&&(Vacuometro<(Seg_Aq_vacuo))) //Histerese do vácuo 200 
              {                
              Global_Aquecimento_Switch(ON); 
              }
           else
              {             
              Global_Aquecimento_Switch(OFF); 
              } 
           } 
        else
        if((PROCULUS_VP_Read_UInt16(5)==0)&&(flag_global_aquecimento==0))
           {         
           timerAquecimento=0; 
           }
}       


void global_refrigeracao_fluido(void){
     
     char bbb[2];
     
     if((PROCULUS_VP_Read_UInt16(62)==1)&&(flag_regrigeracao_fluido==0))
       {  
       if(testa_modo_conectado(4,0)==0) 
         {  
         PROCULUS_Popup(DISPLAY_BLOQUEADO);  
         return; 
         }     
         
         if(!DelayBackupReturn(62, &timerEstante,"Acionando Estante! Aguarde...")) return;
         flag_regrigeracao_fluido=1;         
         Rele_Comum_Aquecimento(1); //Controla a saida da estante
       }
     
     
     if((PROCULUS_VP_Read_UInt16(62)==0)&&(flag_regrigeracao_fluido==1))
       {  
       if(testa_modo_conectado(4,0)==0) 
         {  
         PROCULUS_Popup(DISPLAY_BLOQUEADO);  
         return; 
         }                         
         flag_regrigeracao_fluido=0;    
         Rele_Comum_Aquecimento(0); //Controla a saida da estante
      }  
}



void Comando_Display(void){                        
unsigned char i;    
//=================== COMUNICACAO SERIAL PARA PROCULUS =================
  PROCULUS_Buffer_to_Proculus(&proculus);
  if(proculus.header==PROCULUS_HEADER)
     {
     flag_usart_rx=0;     
     if(proculus.page==0x15) pagina_15();  // Visualização de todos os parmetros
     if(proculus.page==0x19) pagina_19();  // Tela de edição de aquecimento    
     if(proculus.page==0x23) pagina_23();  // Salvar dados de Segurança.
     if(proculus.page==0x25) pagina_25();  // Editar e Salvar Data e Hora
     if(proculus.page==0x29) pagina_29();  // Captura de Datalog, alteração de valor   
     if(proculus.page==0x31) pagina_31();  // ALTERAR SENHA 
    if(proculus.page==0x47) pagina_47();  // Lista de Receita
     if(proculus.page==0x49) pagina_49();  // Edicao de Receita  
     proculus.header=0;
     }//Header                  
} //funcao   


void pagina_49(void){ //EDIÇÃO DE 1 RECEITA COM OPÇÕES    
     t_liofilizador liofilizador;
     
     if(PROCULUS_VP_Read_UInt16(390)==1)
                   {                        
                   //Excluir
                   receita.setpoint=0;
                   receita.potenciaON=0;
                   receita.potenciaOFF=0;
                   receita.histerese=0;
                   strcpy(receita.nome," ");           
                   Grava_Receita(Index_Receita, &receita);                   
                   Exibe_Receita(Index_Receita); 

                   PROCULUS_VP_Write_UInt16(410,0);
                   PROCULUS_VP_Write_UInt16(411,0);
                   PROCULUS_VP_Write_UInt16(412,0);
                   PROCULUS_VP_Write_UInt16(413,0);
                   PROCULUS_VP_Write_String(414,"");

                   Atualizar_Lista_de_Receitas();
                   PROCULUS_VP_Write_UInt16(390,0);

                   PROCULUS_Popup(OP_REALIZADA_COM_SUCESSO);
                   PROCULUS_OK();
                   PROCULUS_VP_Write_String(1910,"Item Excluido com sucesso!"); 
                   my_delay_ms(1500);
                   PROCULUS_VP_Write_String(1910,""); 
                   }
                   
                   
                   
                   
     if(PROCULUS_VP_Read_UInt16(391)==1)
                   {                                           
                   //Gravar
                   receita.setpoint=PROCULUS_VP_Read_UInt16(410);
                   receita.potenciaON=PROCULUS_VP_Read_UInt16(411);
                   receita.potenciaOFF=PROCULUS_VP_Read_UInt16(412);
                   receita.histerese=PROCULUS_VP_Read_UInt16(413);
                   PROCULUS_VP_Read_String(414,receita.nome);
                   Grava_Receita(Index_Receita, &receita);               
                   //PROCULUS_Control_Activation(POPUP_SALVO_COM_SUCESSO);
                   
                   Atualizar_Lista_de_Receitas();
                   PROCULUS_VP_Write_UInt16(391,0);
                   
                   PROCULUS_Popup(SALVO_COM_SUCESSO);
                   PROCULUS_OK();
                   PROCULUS_VP_Write_String(1910,"Dados Gravados com sucesso!"); 
                   my_delay_ms(1500);
                   PROCULUS_VP_Write_String(1910,"");                   
                   }
                   
                   
     if(PROCULUS_VP_Read_UInt16(392)==1)
                   {                                           
                   //Aplicar
                   PROCULUS_VP_Write_String(1910,"Aguarde... Carregando Dados!"); 
                   Carrega_Tupla_Receita(Index_Receita, &receita); 
                   PROCULUS_VP_Write_String(1910,"Aguarde... Armazenando Dados!");
                   for(char i=0;i<(totalboard-2)*2;i++)
                       { 
                       //flag_main_loop_WDT=1;
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
                   PROCULUS_Popup(OP_REALIZADA_COM_SUCESSO);
                   PROCULUS_OK();
                   PROCULUS_VP_Write_String(1910,"");
                   } 
                   
     if(PROCULUS_VP_Read_UInt16(393)==1) //Voltar
                   {
                   PROCULUS_VP_Write_UInt16(393,0);                     
                   PROCULUS_Show_Screen(47);
                   }           
     
}


void pagina_47(void){  //Selecionar uma receita da lista para edição
     t_receita receita;
     if(flag_senha_liberada)
         { 
         PROCULUS_Show_Screen(49); //Chama a tela de Edição
         //Index_Receita=proculus.button;
         Carrega_Tupla_Receita(Index_Receita, &receita);

         PROCULUS_VP_Write_UInt16(410,receita.setpoint);   //SetPoint
         PROCULUS_VP_Write_UInt16(411,receita.potenciaON);    // POT>
         PROCULUS_VP_Write_UInt16(412,receita.potenciaOFF);    // POT<
         PROCULUS_VP_Write_UInt16(413,receita.histerese);    // Histerese
         PROCULUS_VP_Write_String(414,receita.nome);  // Nome da Receita 8 Letras          
         }
     else
         {
         PROCULUS_Popup(ACESSO_NEGADO);
         PROCULUS_NOK();
         }          
 
    

}




//-----------------------------------Pagina 15----------------------------------
//Exibe todos os parâmetros.
void pagina_15(void){  //Tela Principal
   if(proculus.button==3)
      { 
      PROCULUS_Buzzer(2000); 
      }

   if(proculus.button==2)
      { //Desligar o sistema
      if(proculus.status==0){
         //Send_To_PC(3);
         //SEND_REPLY_OK();
         POWER_OFF();
          }//status 0
      } //botao 2


   if (proculus.button==5) //Entra em tela de aquecimento
      {                    //para visualização e edição
      if(proculus.status==1)
         {
         //pagina=19;
         //PROCULUS_Show_Screen(19);                                     
         //PROCULUS_OK();
         maincnt=0; 
         }
     }//Botao 5

}// PAGINA 15


//---------------------------- Pagina 19 ---------------------------------------
void pagina_19(void)  //Setar e gravar individualmente aquecimento
{
       bool flag_upLoadTambem=false;
       
       if(PROCULUS_VP_Read_UInt16(168)==1) //UNDO
         {  
         PROCULUS_VP_Write_UInt16(168,0);   
         if(flag_senha_liberada)  
            { 
            for(char i=0;i<15;i++) 
                {
                //flag_main_loop_WDT=1;
                ShowStaticValueGrid(i);
                }
            PROCULUS_OK();
            }
         else
            { 
            PROCULUS_Popup(ACESSO_NEGADO);
            PROCULUS_NOK();                                 
            }                                     
         }

       
       

       if(PROCULUS_VP_Read_UInt16(167)==1) //GRAVAR
         {
         PROCULUS_VP_Write_UInt16(167,0);  
         if(flag_senha_liberada)  
            {                                
             ShowMessage("Gravando Dados, Aguarde!",2000,SOUND_SINGLE,TRUE);
             for(char i=0;i<10;i++)
                 {
                 //flag_main_loop_WDT=1;
                 DataBaseBackupMain(i);
                 }       
             

             
             //if(Tamanho_Display==50) 
             //   {  
                flag_upLoadTambem=true;
             //   }
             //else
             //   {
             //   ShowMessage("SUCESSO!!!",2000,SOUND_OK,FALSE);                               
             //   PROCULUS_OK();                 
             //   PROCULUS_Popup(SALVO_COM_SUCESSO);  
             //   }
             
            }
         else
            { 
            PROCULUS_Popup(ACESSO_NEGADO);
            PROCULUS_NOK();                                 
            }             
         }



       if((PROCULUS_VP_Read_UInt16(166)==1)||(flag_upLoadTambem)) //UPLOAD
         {
         flag_upLoadTambem=false;  
         PROCULUS_VP_Write_UInt16(166,0);  
         if(flag_senha_liberada)  
            {      
             //if(Tamanho_Display==50) PROCULUS_Popup(SALVO_COM_SUCESSO);
             ShowMessage("Descarregando Dados",2000,SOUND_SINGLE,TRUE); 
             Upload_Data_to_Slave();
             ShowMessage("SUCESSO!!!",2000,SOUND_OK,FALSE);                                  
             PROCULUS_OK();
             if(Tamanho_Display==50) PROCULUS_Popup(SALVO_COM_SUCESSO);
            }
         else
            { 
            PROCULUS_Popup(ACESSO_NEGADO);
            PROCULUS_NOK();                                 
            }             
         }

       
       
       
       
       if(PROCULUS_VP_Read_UInt16(169)==1) //FORMAT
         {
         PROCULUS_VP_Write_UInt16(169,0);  
         if(flag_senha_liberada)  
            {                                     
             char inicio;
             ShowMessage("Formatando",2000,SOUND_SINGLE,TRUE);
             
             if(pagina==19)inicio=0; 
             if(pagina==21)inicio=5;
             //PROCULUS_VP_Write_UInt16(395,inicio); //FIX APAGAR
             
             Formatar_Banco_de_Dados(inicio,5);
             for(char i=0;i<15;i++) 
                 {
                 //flag_main_loop_WDT=1;
                 ShowStaticValueGrid(i);             
                 }
             PROCULUS_OK();             
             ShowMessage("SUCESSO!",2000,SOUND_OK,FALSE);                                 
            }
         else
            { 
            PROCULUS_Popup(ACESSO_NEGADO);
            PROCULUS_NOK();                                 
            }         
         }                  

}// Pagina 19

//-----------------------------Pagina 23----------------------------------------
//Salva dados de Segurança.
void pagina_23(void)  //Salvar Parametros *Obs. Aqui escolhe o subtipo de placa                  
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
        TrendCurveFuncao(LOAD);
        //Carregar_Display_Schematic_Color();
        PROCULUS_Popup(SALVO_COM_SUCESSO);
        PROCULUS_OK();
        Carregar_Parametros_de_Seguranca();
        
     }
    else
     {   
     PROCULUS_Popup(ACESSO_NEGADO);    
     PROCULUS_NOK();
     }
}   







//------------------------------- Pagina 25-------------------------------------
void pagina_25(void)  //SALVAR DATA E HORA
{

    if(flag_senha_liberada)                           
       { 
       char date[10];
       char time[10];           
       PROCULUS_VP_Read_String(20,date); 
       PROCULUS_VP_Read_String(30,time);                        
       PROCULUS_Write_RTC(date,time); 
       PROCULUS_Popup(SALVO_COM_SUCESSO);
       PROCULUS_OK();
       }   
    else
       {                           
       PROCULUS_Popup(ACESSO_NEGADO);
       PROCULUS_NOK();
       }                             

}



//---------------------------- pagina 29----------------------------------------
void pagina_29(void) //VISUALIZAR GRAFICO DE LISTA DE GRAFICOS SALVOS.   
  { 
    if(flag_senha_liberada)
         {
          EEPROM_Write_Integer(0x09,PROCULUS_VP_Read_UInt16(172));
          Carregar_tempo_de_datalog();
          PROCULUS_Popup(SALVO_COM_SUCESSO);
          PROCULUS_OK();
         }
     else
         {
         PROCULUS_Popup(ACESSO_NEGADO);
         PROCULUS_NOK();
         }                    
  } 


//----------------------------ALTERAR SENHA-----------------------------------
void pagina_31(void){  //Manipulação de senha local e global
         unsigned long nova_senha, confirma_senha;
         char senhavetor[4];
         
         nova_senha    =PROCULUS_VP_Read_Double32(382);
         confirma_senha=PROCULUS_VP_Read_Double32(384);

            
         PROCULUS_VP_Read(380,senhavetor,4);  //Lê registrador do teclado 4Bytes
         senha_atual=((unsigned long)senhavetor[0]<<24)+
                     ((unsigned long)senhavetor[1]<<16)+
                     ((unsigned long)senhavetor[2]<< 8)+
                     ((unsigned long)senhavetor[3]<< 0);                           

         PROCULUS_VP_Read(382,senhavetor,4);  //Lê registrador do teclado 4Bytes
         nova_senha =((unsigned long)senhavetor[0]<<24)+
                     ((unsigned long)senhavetor[1]<<16)+
                     ((unsigned long)senhavetor[2]<< 8)+
                     ((unsigned long)senhavetor[3]<< 0);                          


         PROCULUS_VP_Read(384,senhavetor,4);  //Lê registrador do teclado 4Bytes
         confirma_senha=((unsigned long)senhavetor[0]<<24)+
                        ((unsigned long)senhavetor[1]<<16)+
                        ((unsigned long)senhavetor[2]<< 8)+
                        ((unsigned long)senhavetor[3]<< 0);                          



         if((senha_atual==0) ||
            (nova_senha ==0) ||
            (confirma_senha==0))
            { 
            //PROCULUS_VP_Write_String(1660,"Nenhuma senha deve ser zero");                          
            PROCULUS_Popup(SENHA_ZERO_INVALIDA) ;
            }
         else
         if(senha_atual==EEPROM_Read_Long32(11))
            { 
            if(nova_senha==confirma_senha)
               {// Cadastrada com Sucesso
               EEPROM_Write_Long32(11,nova_senha) ;
               senha_atual=nova_senha;               
               Gravar_Status_da_Senha_Global();
               PROCULUS_VP_Write_Long32(380,0);
               PROCULUS_VP_Write_Long32(382,0);   //Nova senha cadastrada com sucesso!
               PROCULUS_VP_Write_Long32(384,0);
               PROCULUS_Popup(SENHA_CADASTRADA_SUCESSO) ;               
               } 
            else
               {
               //PROCULUS_VP_Write_String(1660,"A nova senha nao conferem "); 
               PROCULUS_Popup(SENHAS_DIFERENTES) ;
               }                             
            }
         else
            { 
            //Senha atual invalida 
            //PROCULUS_VP_Write_String(1660,"Senha atual invalida"); 
            PROCULUS_Popup(SENHA_INVALIDA) ;
            }

}



void Exibe_Hora_Data(char showseconds){
     char date[10];
     char time[10];     
     
     PROCULUS_Read_RTC(date,time);
     if(showseconds==FALSE) time[5]=0;
     PROCULUS_VP_Write_String(20,date);
     PROCULUS_VP_Write_String(30,time);            
}






//Inicializa parametros de segurança.
void Inicializar_Seguranca(void){
     Seg_Condensador=EEPROM_Read_Integer(0x01);
     Seg_Vacuo=EEPROM_Read_Integer(0x03);
     Seg_Aq_cond=EEPROM_Read_Integer(0x05);
     Seg_Aq_vacuo=EEPROM_Read_Integer(0x07);        
     PROCULUS_VP_Write_UInt16(210,Seg_Condensador); // Segurança Condensador
     PROCULUS_VP_Write_UInt16(211,Seg_Vacuo); // Segurança Vacuo
     PROCULUS_VP_Write_UInt16(212,Seg_Aq_cond); // Seguranca aquec. cond.
     PROCULUS_VP_Write_UInt16(213,Seg_Aq_vacuo); // Seguranca aquec. Vacuo
}





void Check_And_Send_Capture_Datalog(void){     
     if(flag_global_datalog==1)
       { 
       if(flag_capture_datalog==1)
         {  
         flag_capture_datalog=0;          
         if(!flag_pc_conected)
            { 
            __delay_ms(25); //EVITA LEITURA -1.0Volts
            save_datalog(add_datalog);         
            add_datalog+=2;
            }
         }
       }
}





 


void Contagem_Tempo_de_Processo(char value){
    if(value)
      { 
      if(flag_time_process==FALSE) 
         { 
         processo_minuto=0;
         processo_hora=0;
         }
      PROCULUS_VP_Write_String(1970,"Executando Processo...");  
      flag_time_process=TRUE;      
       //Write_Fat(TRUE);
      }
    else
      {  
      PROCULUS_VP_Write_String(1970,"");  
      flag_time_process=0;
      rtc.milisegundo=725;     
      //Write_Fat(FALSE);
      }        
        
}

void SaveBlackoutStatusRuning(void){
     if(processo_minuto%10==0)          
       {              
       if(flag_save_time==0)  
          {
          flag_save_time=1;
         
          //PROCULUS_OK();
          
          EEPROM_Write_Byte(17,processo_hora);     //Hora
          EEPROM_Write_Byte(18,processo_minuto);   //Minuto  
          
          
          fat8.index=Find_Fat8_Running();
          
         
          
          
          if(fat8.index!=-1)
             {
             
             FAT8_Load(fat8.index);                    
             fat8.processo.add_end=add_datalog;
              
             FAT8_Save(fat8.index);
             
             EEPROM_24C1025_Write_Long (0,2,add_datalog); //Salvar add_datalog
             EEPROM_24C1025_Write_Int  (0,6,processo_totalminuto); //Salvar TotalMinuto              
              
             }
          }
       }                     
     else
       {  
       flag_save_time=0;       
       } 
   
}
     


void SaveBlackoutStatus(void){
        
     EEPROM_Write_Byte(17,processo_hora);     //Hora
     EEPROM_Write_Byte(18,processo_minuto);   //Minuto  
}




void RecallBlackoutStatus(void){
     statuspower.bits=EEPROM_Read_Byte(16);     
     processo_hora=EEPROM_Read_Byte(17);
     processo_minuto=EEPROM_Read_Byte(18);

     if(flag_global_datalog) PROCULUS_VP_Write_UInt16(2,1);
     if(flag_global_condensador) PROCULUS_VP_Write_UInt16(3,1);
     if(flag_global_vacuo) PROCULUS_VP_Write_UInt16(4,1);
     if(flag_global_aquecimento) PROCULUS_VP_Write_UInt16(5,1);
     
     if(Tamanho_Display==81)
       {    
       if(flag_regrigeracao_fluido) PROCULUS_VP_Write_UInt16(62,1);  
       flag_regrigeracao_fluido=0;
       }
     
     //if(flag_global_porta) PROCULUS_VP_Write_UInt16(19,1);
     //flag_time_process = autometico ao carregar;
     
     flag_global_datalog=0;     
     flag_global_condensador=0;
     flag_global_vacuo=0; 
     flag_global_aquecimento=0;  
     
     
     //flag_global_porta=0;
}





void Carregar_tempo_de_datalog(void){
     tempocapturaconstante=(EEPROM_Read_Integer(0x09)*1000);
     tempocaptura=tempocapturaconstante;     
}


void Gerenciador_de_Senha(void){
     unsigned long senha;
    //=================== ENTRAR COM A SENHA DO ADMINISTRADOR===============
    PROCULUS_VP_Read(155,senhavetor,4);  //Lê registrador do teclado 4Bytes
    senha=((unsigned long)senhavetor[0]<<24)+
          ((unsigned long)senhavetor[1]<<16)+
          ((unsigned long)senhavetor[2]<< 8)+
          ((unsigned long)senhavetor[3]<< 0);  


    if(senha!=0)
        { 
        if(senha==senha_atual)
           { 
           senha=0; 
           senhacount=TIME_PASSWORD; 
           flag_senha_liberada=TRUE;
           PROCULUS_VP_Write_UInt16(154,1); //torna o icone da senha verde    
           PROCULUS_VP_Write_UInt16(155,0); //VP Duplo do teclado onde
           PROCULUS_VP_Write_UInt16(156,0); // eh armazenado a senha           
           PROCULUS_OK();
           }
        }


    if((flag_senha_liberada==TRUE)&&(senhacount<0))
        {           
        flag_senha_liberada=FALSE; 
        PROCULUS_VP_Write_UInt16(154,0); //torna o icone vermelho 
        PROCULUS_NOK(); 
        }              


    if(PROCULUS_TPFLAG_Read()==0x5A) //Se houver toque no display
       { 
       senhacount=TIME_PASSWORD;     //Reiniciar o contador
       PROCULUS_TPFLAG_Write(0);     //Reinicia o reg. de toque
       }   
    //----------------------------------------------------------------------
}




void Gerenciador_de_Senha_Global(void){
     unsigned long senha;
    //=================== ENTRAR COM A SENHA DO ADMINISTRADOR===============
    PROCULUS_VP_Read(179,senhavetor,4);  //Lê registrador do teclado 4Bytes
    senha=((unsigned long)senhavetor[0]<<24)+
          ((unsigned long)senhavetor[1]<<16)+
          ((unsigned long)senhavetor[2]<< 8)+
          ((unsigned long)senhavetor[3]<< 0);  


    if(senha!=0)
        { 
        if(senha==senha_atual)
           { 
           senha=0; //Zera Senha a ser testada          
           PROCULUS_VP_Write_Long32(179,0); // Zerar o teclado
           if(PROCULUS_VP_Read_UInt16(178)==1) //Icone
              { 
              flag_senha_global_liberada=FALSE; 
              flag_senha_liberada=FALSE;
              senhacount=-1;
              PROCULUS_VP_Write_UInt16(178,0); //torna o icone da senha GLOBAL vermelho.
              PROCULUS_VP_Write_UInt16(154,0); //torna o icone da senha vermelho
              }        
           else if(PROCULUS_VP_Read_UInt16(178)==0)          
              { 
              flag_senha_global_liberada=TRUE; 
              flag_senha_liberada=TRUE;
              senhacount=10;
              PROCULUS_VP_Write_UInt16(178,1); //torna o icone da senha GLOBAL verde
              PROCULUS_VP_Write_UInt16(154,1); //torna o icone da senha verde
              }                
           Gravar_Status_da_Senha_Global();
           PROCULUS_OK();
           }
        }
    //----------------------------------------------------------------------
}




void Icones_de_alarmes(void){     
     //-------------------------------------------------------------------------    
     if (Condensador<Seg_Condensador)       
         PROCULUS_VP_Write_UInt16(176,1);         
     else         
         PROCULUS_VP_Write_UInt16(176,0);
     //-------------------------------------------------------------------------    
     if (Vacuometro<Seg_Vacuo)  
     {         
         PROCULUS_VP_Write_UInt16(177,1);         
     }
     else         
     {
         PROCULUS_VP_Write_UInt16(177,0);
     }
     //-------------------------------------------------------------------------
}

void Formatar_Lista_de_Receitas(void){
     t_receita receita;
     for(char i=0;i<8;i++) 
        { 
        //flag_main_loop_WDT=1; 
        receita.setpoint=0;
        receita.potenciaON=0;
        receita.potenciaOFF=0;
        receita.histerese=0;
        strcpy(receita.nome," ");           
        Grava_Receita(i, &receita);        
        } 
}

void Carregar_Parametros_de_Seguranca(void){     
     Seg_Condensador=EEPROM_Read_Integer(0x01);
     Seg_Vacuo=EEPROM_Read_Integer(0x03);
     Seg_Aq_cond=EEPROM_Read_Integer(0x05);
     Seg_Aq_vacuo=EEPROM_Read_Integer(0x07);     
     PROCULUS_VP_Write_UInt16(210,Seg_Condensador); // Segurança Condensador
     PROCULUS_VP_Write_UInt16(211,Seg_Vacuo); // Segurança Vacuo
     PROCULUS_VP_Write_UInt16(212,Seg_Aq_cond); // Seguranca aquec. cond.
     PROCULUS_VP_Write_UInt16(213,Seg_Aq_vacuo); // Seguranca aquec. Vacuo 
     
     PROCULUS_VP_Write_UInt16(172,EEPROM_Read_Integer(0x09)); //Tempo de captura do grafico       
}

void Formatar_Dados_de_Seguranca(void){
     EEPROM_Write_Integer(0x01,-150);    //Condensador
     EEPROM_Write_Integer(0x03,10000);   //Vacuo
     EEPROM_Write_Integer(0x05,-150);    //Condensador aquecimento
     EEPROM_Write_Integer(0x07,8000);    //Vacuo aquecimento     
}

void Carregar_Status_da_Senha_Global(void){
     flag_senha_global_liberada=EEPROM_Read_Byte(15);
     if(flag_senha_global_liberada)
        { 
        PROCULUS_VP_Write_UInt16(178,1);//torna o icone da senha global verde 
        flag_senha_liberada=TRUE;
        senhacount=10;
        PROCULUS_VP_Write_UInt16(154,1); //torna o icone da senha verde
        }
     else
        { 
        PROCULUS_VP_Write_UInt16(178,0);//torna o icone da senha global vermelho  
        flag_senha_liberada=FALSE;
        senhacount=-1;
        PROCULUS_VP_Write_UInt16(154,0); //torna o icone da senha vermelho
        }
}

void Gravar_Status_da_Senha_Global(void){
     EEPROM_Write_Byte(15,flag_senha_global_liberada);
}


void Formatar_Datalog(void){
    int i;
    for(i=500;i<=720;i+=20)    
       {
       //flag_main_loop_WDT=1; 
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
     
     //fat_processo.
      
     
     PROCULUS_Read_RTC(date,time);

     
      
}


void Memo2Graphic(char SlaveBoardAdd, char chipNumber, int add_24C1025, char LCDchannel){
     char bb[3];
     int  value;
     
     bb[0]=chipNumber;
     bb[1]=Hi(add_24C1025);
     bb[2]=Lo(add_24C1025);        
     
     value=Send_To_Slave(SlaveBoardAdd, COMMAND_EEE_R_INT, 3, bb);
     //itoa(value,texto,10);
     //print(texto);     
     PROCULUS_graphic_plot(LCDchannel, value);
}  




//------------------------------------------------------------------------------
//unsigned int Captura_Pagina(void){
//    unsigned int pagina[5];    
//    unsigned int retorno=0;   
//    
//    while(retorno==0)
//       { 
//       //flag_main_loop_WDT=1; 
//       for(char i=0;i<5;i++) 
//          pagina[i]=PROCULUS_Get_Page();
//
//          retorno=pagina[0];
//          for(char i=1;i<5;i++)
//             {
//             if(pagina[0]!=pagina[i]) 
//                { 
//                retorno=0;
//                break;
//                }
//             }    
//       }
//    return retorno;
//}


_Bool memory_test(char board, char chip, int value, int inicialadd, int finaladd)
     {    
     char txt[30];
     char bb[5];    
     int salva=0;
     int ler=0;
     //PROCULUS_Show_Screen(0); //35grafico , 0 Print
     strcpy(texto,"BOARD =");
     itoa(board,txt,16);
     strcat(texto,txt);
     print(texto);
             
             
             
             for(int add=inicialadd; add<=finaladd; add++)             
                {
                //flag_main_loop_WDT=1; 
                bb[0]=chip;  //chip
                bb[1]=Hi(add); //___ADD
                bb[2]=Lo(add); //      
                bb[3]=Hi(salva); //___VALUE
                bb[4]=Lo(salva); //              
                Send_To_Slave(board, COMMAND_EEE_W_INT, 5, bb); 
                
                bb[0]=chip;
                bb[1]=Hi(add);
                bb[2]=Lo(add);
                ler=Send_To_Slave(board, COMMAND_EEE_R_INT, 3, bb); 
                //ler=salva;
                        
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
                   //return FALSE;
                   }
                strcat(texto,txt);
                print(texto);
                value++;
                }                       
     return TRUE;
     }        



char menorValorDisponivel(char * trendCurve){
     unsigned char icone; 
     char i,j,p;    
      //=====================================================
      icone=0;
      for(p=1;p<14;p++)
         {
         trendExist=FALSE;
         for(i=1;i<14;i++)
            { 
            for(j=i;j<14;j++)
               {
               //flag_main_loop_WDT=1; 
               if(trendCurve[j]==p) 
                  { 
                  trendExist=TRUE;
                  break;
                  }
               }
            if(trendExist==TRUE)
               {
               break;
               }
            }
         if(trendExist==FALSE)
           { 
           icone=p;  
           break;  
            }
         }
      //----------------------------------------------------
     return icone;
}      



void Exibe_Tempo_de_Processo(void){
     //if(flag_time_process)
     //  {
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
      // }
}



void Atualizar_Lista_de_Receitas(void){
     for(char i=0;i<8;i++)                         
        {
        //flag_main_loop_WDT=1; 
        Exibe_Receita(i);        
        }     
}





void TrendCurveFuncao(char funcao){
     char figura;
     char canal;
     int  cor;
     char i, index;
     Carregar_Display_Schematic_Color();
     switch(funcao)
           {
           case FORMAT:
                       for(i=0;i<13;i++)
                          { 
                          mapa.cor[i]=0xFFFF;
						  mapa.canal[i]=0x0A;                          
						  mapa.icone[i]=-1;                          
                          mapa.vpIcone[i]=-1;
                          mapa.entrada[i]=NULL;
                          mapa.fator[i]=0;
                          
                          EEPROM_Write_Byte(19+i,mapa.vpIcone[i]);
                          EEPROM_Write_Byte(0xEA+i,mapa.icone[i]);        
                          EEPROM_Write_Byte(36+i,mapa.canal[i]);
                          
                          PROCULUS_VP_Write_UInt16(0x0310+i,-1);           //Figura
                          PROCULUS_VP_Write_UInt16((i*10+PPCANAL),0x0A00); //Canal
                          PROCULUS_VP_Write_UInt16((i*10+PPCOR),0xFFFF);   //Cor 
                          }               
                       break;
           case   LOAD:
                      
                       EEPROM_Read_Buffer(19,mapa.vpIcone,15);
                       EEPROM_Read_Buffer(0xEA,mapa.icone,15);
                       EEPROM_Read_Buffer(36,mapa.canal,15);
                       


                       //-----------------------------------ICONE------------------------------------
                       for(i=0;i<13;i++)
                          {                          
                          figura=mapa.vpIcone[i];
                          if(figura!=255) 
                             {							   
                             PROCULUS_VP_Write_UInt16(0x0310+i, figura); //Figura -quadro colorido                             
                             }
                          else
                            {							
                            PROCULUS_VP_Write_UInt16(0x0310+i,-1);                            
                            }
                          }
                       
                       //------------------------------------COR-------------------------------------
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
			  PROCULUS_VP_Write_UInt16((i*10+PPCOR),cor);
			  mapa.cor[i]=cor; 		
			  }
                          
                       //--------------------------------------CANAL------------------------------------------
                       for(i=0;i<13;i++)
                          { 
                          canal=mapa.canal[i];
			  if((canal>=0)&&(canal<=7))
			     {
                 PROCULUS_VP_Write_UInt16((i*10+PPCANAL),(canal<<8)|(0x0001)); //Canal Associado                             						     	
		         }
			  else	 
		         {							 
                 PROCULUS_VP_Write_UInt16((i*10+PPCANAL),0x0A00); //Canal                             
			     }
			  }
					      
                       
                       
                          //----------------------------------------VALOR-----------------------------------------------
                          for(index=0;index<8;index++)
                              {                                       
                              if(mapa.canal[index]!=0x0A)
                                 {                       
                                 mapa.entrada[mapa.canal[index]]=&leitura[saltaIndice4(mapa.icone[mapa.canal[index]]-1)];
                                 mapa.fator[mapa.canal[index]]=FATOR_PADRAO;                                                
                                 if(mapa.canal[index]==0)mapa.fator[mapa.canal[index]]=FATOR_TENSAO;
                                 if(mapa.canal[index]==1)mapa.fator[mapa.canal[index]]=FATOR_VACUO;                                                                
                                 }
                              }
                          				      
					      
                       break;
           case   SAVE:
                       for(i=0;i<14;i++)   
                           {
                           mapa.vpIcone[i]=PROCULUS_VP_Read_UInt16(0x0310+i);
			   mapa.canal[i]=PROCULUS_VP_Read_UInt16(i*10+PPCANAL)>>8;	
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
     flag_global_datalog=0;
     flag_global_condensador=0;
     flag_global_vacuo=0;     
     flag_global_aquecimento=0;         
     //flag_global_porta;
}


void RelatorioTecnico(void){
     int  valor;
     PROCULUS_Show_Screen(0);
     clear_screen();
     print("-----RELATORIO TECNICO----");
     ShowHardwareInfo();
     showMemoryInfo();
     valor=EEPROM_Read_Integer(34);
     itoa(valor,buffer,10);
     strcpy(texto,"SERIAL MODULE RECOVER = ");
     strcat(texto,buffer);
     print(texto);
     
     my_delay_ms_CLRWDT(10000);
     PROCULUS_VP_Write_UInt16(100,0);
     PROCULUS_Show_Screen(15);     
     
     /*
     print("SERIAL MODULE UPDATE = ")
             
             
             
     print("Serao impressas informacoes");
     print("sobre este hardware...");
     
     
     
     my_delay_ms_CLRWDT(10000);
     PROCULUS_VP_Write_UInt16(100,0);
     PROCULUS_Show_Screen(15);
     /*     
     
     
     
     
    print("Reinicializacoes:");
    if(PROCULUS_VP_Read_UInt16(0x00AA)==1)                   
      {
      char bb[3];
      int  valor; 
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
          //flag_main_loop_WDT=1;
          strcpy(texto,"Placa ");
          itoa(placa,buffer,10); 
          strcat(texto,buffer);
          strcpy(buffer," = ");
          strcat(texto,buffer);
          bb[0]=0x10;
          valor=Send_To_Slave(placa,COMMAND_IEE_R_INT,1,bb);
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
       
    */ 
            
}



void ShowHardwareInfo(){
     char i;
     char destino;   
     char tipo=0;
     int  resposta;
     char versao[10];     
     
     my_delay_ms_CLRWDT(300);
     PROCULUS_VP_Read_String(1990, buffer);
     strcpy(texto,"* : Display      ");
     strcat(texto,buffer);
     print(texto);
     my_delay_ms_CLRWDT(500);     
     
     
     Send_To_Slave(destino, COMANDO_QUEM_EH_VOCE, 0, buffer);
     
     
     totalboard=0;
     strcpy(texto,"");
     strcat(texto,"* : Mother Board ");
     strcat(texto,FVERSION);
     print(texto);
     
     for(destino=1;destino<15;destino++)
        {
        my_delay_ms_CLRWDT(100); 
        //flag_proculus_hs=FALSE;
        resposta = Send_To_Slave(destino, COMANDO_QUEM_EH_VOCE, 0, buffer);
        
        if(resposta!=-1)
            {
            tipo=Lo(resposta);
            totalboard++;
            strcpy(texto,"");
            itoa(destino,texto,10); 
            strcat(texto," : ");             
            strcat(texto, boardtype[tipo][0]);
            strcat(texto," ");
            strcpy(buffer," ");
            Send_To_Slave(destino, COMMAND_VERSION, 0, buffer);
            strcat(texto,buffer);
            print(texto);
            }
        }

     print("..................................");     
          
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
    print("----------------------------------");
}

char MenorCanalLivre()
     {
     unsigned char canal, canalLivre, canalBusca, busca, Exist;	
     canal=0x0A;	
     for(canalLivre=0;canalLivre<8;canalLivre++)
	    {	    	
	    //printf("Buscando existencia de canal %d\n",canalLivre);
	    Exist=FALSE;
	    for(canalBusca=0;canalBusca<13;canalBusca++)		
	       {	       
	       busca=mapa.canal[canalBusca];
	       //printf("Varrendo figura %d=%d    \n",canalLivre,busca);
		   if(canalLivre==busca)
			 {
			 //printf("Existe o canal %d\n",canalLivre);	
			 Exist=TRUE;
			 break;	
			 }  
		   }
		if(Exist==FALSE)
		  {
		  //printf("NAO Existe o canal %d\n",canalLivre);	
		  canal=canalLivre;	
		  break;
		  }		   
		}
	 //printf("Retornando canal %d\n",canal);	
	 return canal;	
	 }


void Incrementa_Contador_de_Repique_do_Vacuo(){
     int valor;
     if(flag_Vacuo_estava_ligado==1)
       {
       flag_Vacuo_estava_ligado=0;      
       valor=EEPROM_Read_Integer(0xE8);
       valor++;
       EEPROM_Write_Integer(0xE8,valor); 
       }
}


void Carregar_Display_Schematic_Color(){
    
    //Para escolher uma cor, visite o site:
    // http://www.rinkydinkelectronics.com/calc_rgb565.php
     
     Tamanho_Display=EEPROM_Read_Integer(0xFA);     
     PROCULUS_VP_Write_UInt16(214,Tamanho_Display);
     
     if(Tamanho_Display==50){               
          TrendColor[0] =0xF800; //Vermelho vivo
          TrendColor[1] =0x05A0; //Verde Claro
          TrendColor[2] =0x001F; //Azul                              
          TrendColor[3] =0x0000; //Preto
          TrendColor[4] =0xD540; //Amarelo Escuro
          TrendColor[5] =0xF81F; //Roxo
          TrendColor[6] =0xFBE0; //Laranja
          TrendColor[7] =0xFFFF; //BRANCO
          TrendColor[8] =0xFFFF; //BRANCO
          TrendColor[9] =0xFFFF; //BRANCO
          TrendColor[10]=0xFFFF; //BRANCO
          TrendColor[11]=0xFFFF; //BRANCO
          TrendColor[12]=0xFFFF; //BRANCO
     }
     else if(Tamanho_Display==80){             
          TrendColor[0] =0x0000; //Preto
          TrendColor[1] =0x39E7; //Cinza escuro
          TrendColor[2] =0x6B6D; //Cinza claro
          TrendColor[3] =0x7800; //Marron Escuro
          TrendColor[4] =0x9A23; //Marron Claro
          TrendColor[5] =0xF800; //Vermelho vivo
          TrendColor[6] =0xFBE0; //Laranja
          TrendColor[7] =0xFBF7; //Rosa
          TrendColor[8] =0xD540; //Amarelo Escuro
          TrendColor[9] =0x03E0; //Verde Escuro
          TrendColor[10]=0x05A0; //Verde Claro 
          TrendColor[11]=0x001F; //Azul 
          TrendColor[12]=0xF81F; //Roxo
          }     
     else if(Tamanho_Display==81)
          { 
          TrendColor[0] =0xFBF7; //Rosa          
          TrendColor[1] =0x05A0; //Verde
          TrendColor[2] =0x001F; //Azul  
          TrendColor[3] =0xF800; //Vermelho vivo 
          TrendColor[4] =0x0000; //Preto                   
          TrendColor[5] =0xFFFF; //BRANCO
          TrendColor[6] =0xFFFF; //BRANCO
          TrendColor[7] =0xFFFF; //BRANCO
          TrendColor[8] =0xFFFF; //BRANCO
          TrendColor[9] =0xFFFF; //BRANCO
          TrendColor[10]=0xFFFF; //BRANCO
          TrendColor[11]=0xFFFF; //BRANCO
          TrendColor[12]=0xFFFF; //BRANCO                    
          }
     else {
          TrendColor[0] =0xFFFF; //BRANCO
          TrendColor[1] =0xFFFF; //BRANCO
          TrendColor[2] =0xFFFF; //BRANCO                          
          TrendColor[3] =0xFFFF; //BRANCO
          TrendColor[4] =0xFFFF; //BRANCO
          TrendColor[5] =0xFFFF; //BRANCO
          TrendColor[6] =0xFFFF; //BRANCO
          TrendColor[7] =0xFFFF; //BRANCO
          TrendColor[8] =0xFFFF; //BRANCO
          TrendColor[9] =0xFFFF; //BRANCO
          TrendColor[10]=0xFFFF; //BRANCO
          TrendColor[11]=0xFFFF; //BRANCO
          TrendColor[12]=0xFFFF; //BRANCO          
          }     
}


void Ligar_Cargas_Compassadamente(){    
     #define TIMEBLACKOUT 30
     int valor;    
     
     PROCULUS_VP_Write_UInt16(0x02,0); //DATALOG
     PROCULUS_VP_Write_UInt16(0x03,0); //CONDENSADOR
     PROCULUS_VP_Write_UInt16(0x04,0); //VACUO
     PROCULUS_VP_Write_UInt16(0x05,0); //AQUECIMENTO
     //PROCULUS_VP_Write_UInt16(0x13,0); //PORTA
     flag_time_process=FALSE;

     statuspower.bits=EEPROM_Read_Byte(16);      
     
     
     if(statuspower.bits!=0)
          {   
          print("Houve BLACKOUT!");
          print("Ativando Recuperacao!");          
          
          Contagem_Tempo_de_Processo(FALSE);  
          
          if(flag_global_datalog==1)
             {              
             flag_global_datalog=0;
             print("-DataLog.");
             PROCULUS_VP_Write_UInt16(0x02,1); //Datalog
             timerDatalog=0;             
             }          
          
          if((Tamanho_Display==81)&&(flag_regrigeracao_fluido))
            {   
            flag_regrigeracao_fluido=0;
            print("-Estante.");
            PROCULUS_VP_Write_UInt16(0x13,1);//Porta 
            timerEstante=TIMEBLACKOUT;
            }
          else
            timerEstante=0;
          

          
          if(flag_global_condensador==1)
            { 
            flag_global_condensador=0;
            print("-Condensador.");
            PROCULUS_VP_Write_UInt16(0x03,1);  //Condensador
            timerCondensador=TIMEBLACKOUT;
            }
          else
            timerCondensador=0;
          
          
          if(flag_global_vacuo==1)
            {
            flag_global_vacuo=0;
            flag_time_process=TRUE;
            print("-Bomba de vacuo.");
            PROCULUS_VP_Write_UInt16(0x04,1);  //Vacuo
            timerVacuo=TIMEBLACKOUT;
            }
          else
            timerVacuo=0;
          
          if(flag_global_aquecimento==1)
            {   
            flag_global_aquecimento=0;
            print("-Aquecimento.");
            PROCULUS_VP_Write_UInt16(0x05,1);//Aquecimento 
            timerAquecimento=TIMEBLACKOUT;
            }
          else
            {  
            timerAquecimento=0;  
            }
          
          my_delay_ms_CLRWDT(3500);
                     
          }
     //memo_statuspower=statuspower.bits;      
     
}





void Plotar_Grafico_Gravado(void)
{
    /*--------------------------------------------------------------------------
     *                  A R E A    D E    T E S T E
     -------------------------------------------------------------------------*/ 
     float RESOLUCAOX;
     char bb[5];
     char SlaveBoard;
     char canal;
     char tupla;  
     unsigned long add_datalog;
     
     if(Tamanho_Display==80)
        RESOLUCAOX=566.0 ;
     else if(Tamanho_Display==50)
             RESOLUCAOX=321.0 ;
     
     char flag_exit;
     int  leitura[14];
     float tempfloat;
     unsigned long value;
     
     PROCULUS_Show_Screen(35);
     PROCULUS_OK();
     add_datalog=fat8.processo.add_start;
     tempfloat=0.0;
     flag_exit=FALSE;
     do{          
          //Capturando dados das placas
          __delay_ms(50);
          flag_exit=FALSE;
          for(tupla=0;tupla<(totalboard*2);tupla++)
             { 
             if(tupla==3)continue;
             SlaveBoard  = (tupla / 2)+1; 
             canal = tupla % 2;
             
             bb[0]=canal;
             bb[1]=High (add_datalog);
             bb[2]=Lower(add_datalog);
             bb[3]=Hi   (add_datalog);
             bb[4]=Lo   (add_datalog);      
             leitura[tupla]=Send_To_Slave(SlaveBoard, COMMAND_EEE_R_INT, 5, bb);
             asm("CLRWDT");
             }
          
          //  plotando no grafico
          __delay_ms(50);
          for(char i=0;i<totalboard*2;i)
             {
             switch(i++)
                   {
                   case 0: PROCULUS_graphic_plot(i,(leitura[i]*FATOR_TENSAO));break;
                   case 1: PROCULUS_graphic_plot(i,(leitura[i]*FATOR_VACUO));break;
                  default: PROCULUS_graphic_plot(i,(leitura[i]*FATOR_PADRAO));break;
                   }               
             }  

          tempfloat+=((fat8.processo.add_end-fat8.processo.add_start)/2.0)/RESOLUCAOX;
          value= round(tempfloat);
          add_datalog=(value*2)+fat8.processo.add_start;
          
          TRISDbits.RD6=0;
          PORTDbits.RD6=1;           
          if(PROCULUS_Get_Page()!=35) 
            {
            PORTDbits.RD6=0;  
            TRISDbits.RD7=0;
            PORTDbits.RD7=1; 
            __delay_us(500);
            PORTDbits.RD7=0;            
            PROCULUS_Clean_All_Line_Graphic();            
            break;                            
            }  
          PORTDbits.RD6=0;
  
       }while(add_datalog<fat8.processo.add_end); 
}     


void Format_FAT8_Table(){

    fat8.processo.processo_number=0;    
    strcpy(fat8.processo.inicio.date," ");
    strcpy(fat8.processo.inicio.time," ");    
    strcpy(fat8.processo.fim.date," ");
    strcpy(fat8.processo.fim.time," ");    
    fat8.processo.amostra=0;
    fat8.processo.add_start=0;
    fat8.processo.add_end=0;
    fat8.processo.minutes=0;
    fat8.processo.all_flags=0;
    
    for(char tupla=0;tupla<maxlineDATALOG;tupla++) FAT8_Save(tupla);
    
    EEPROM_24C1025_Write_Long (0,2,0); //Inicializa add_datalog 
    add_datalog=0;
}



void FAT8_Write_Process_Inicialize()
    {
    unsigned int NumProcesso;
    char time[10];
    char date[10];
    
    fat8.index=Find_Fat8_Free();

    NumProcesso=EEPROM_24C1025_Read_Int (0,0);
    NumProcesso++;
    if(NumProcesso>9999) NumProcesso=0;
    EEPROM_24C1025_Write_Int (0,0,NumProcesso);

    PROCULUS_Read_RTC(date,time);
    
    processo_totalminuto=0;
    
    add_datalog=EEPROM_24C1025_Read_Long (0,2); //Inicializa add_datalog
    
    fat8.processo.processo_number=NumProcesso;    
    strcpy(fat8.processo.inicio.date,date);
    strcpy(fat8.processo.inicio.time,time);    
    strcpy(fat8.processo.fim.date,"");
    strcpy(fat8.processo.fim.time,"");            
    fat8.processo.amostra=EEPROM_Read_Integer(0x09);
    fat8.processo.add_start=add_datalog;        
    fat8.processo.add_end=0;
    fat8.processo.minutes=0;
    fat8.processo.flag_download=0;
    fat8.processo.flag_view=0;
    fat8.processo.flag_finalized=0;
    fat8.processo.flag_running=1;
    
    

          
    FAT8_Save(fat8.index);
    FAT8_Show();
    }


void FAT8_Write_Process_Finalize(){
    unsigned char NumProcesso;
    unsigned char index;
    char time[10];
    char date[10];
    
    fat8.index=Find_Fat8_Running();
    FAT8_Load(fat8.index);    
    
    if(flag_pc_conected==TRUE)
      {
      strcpy(fat8.processo.fim.date,fat8.processo.inicio.date);
      strcpy(fat8.processo.fim.time,fat8.processo.inicio.time);               
      fat8.processo.minutes=0;
      }
    else
      {  
      PROCULUS_Read_RTC(date,time);    
      strcpy(fat8.processo.fim.date,date);
      strcpy(fat8.processo.fim.time,time);       
      fat8.processo.minutes=processo_totalminuto;
      }

    //fat8.processo.processo_number=NumProcesso;    
    //strcpy(fat8_processo.inicio.date,date);
    //strcpy(fat8_processo.inicio.time,time);    
    //strcpy(fat8.processo.fim.date,date);
    //strcpy(fat8.processo.fim.time,time);            
    //fat8.processo.amostra=EEPROM_Read_Integer(0x09);
    //fat8.processo.add_start=0;        
    fat8.processo.add_end=add_datalog;
    //fat8.processo.minutes=processo_totalminuto;
    fat8.processo.flag_running=0;
    fat8.processo.flag_download=0;
    fat8.processo.flag_view=0;
    fat8.processo.flag_finalized=1;
    FAT8_Save(fat8.index);
    FAT8_Show(); 
    if(flag_pc_conected==FALSE) add_datalog+=2;
    EEPROM_24C1025_Write_Long (0,2,add_datalog); //Armazena add_datalog
    
}



char Find_Fat8_Free(){
     char i;
     char resultado=-1;
     
     for(i=0;i<maxlineDATALOG;i++)
        {
        FAT8_Load(i);
        if((fat8.processo.flag_running==0)&&(!fat8.processo.flag_finalized)) 
           {
            resultado=i;
            break;
           } 
        }    
     return resultado;
}


signed char Find_Fat8_Running(){
     char i;
     signed char resultado=-1;

     for(i=0;i<maxlineDATALOG;i++)
        {
        FAT8_Load(i);
        if(fat8.processo.flag_running) 
          {  
          resultado=i;  
          break;
          }
        }    
     return resultado;
}



void Preenche_Dados_da_FAT8(){
     char time[10];
     char date[10]; 

     PROCULUS_Read_RTC(date,time);

     fat8.processo.processo_number=0;   
     strcpy(fat8.processo.inicio.date,date);
     strcpy(fat8.processo.inicio.time,time);    
     strcpy(fat8.processo.fim.date,date);
     strcpy(fat8.processo.fim.time,time);            
     fat8.processo.amostra=0;
     fat8.processo.add_start=0;        
     fat8.processo.add_end=add_datalog;
     fat8.processo.minutes=0;
     fat8.processo.flag_running=0;
     fat8.processo.flag_download=0;
     fat8.processo.flag_view=0;
     fat8.processo.flag_finalized=0;    
}


void Recarregar_Parametros_de_Configuracao(void){
     Carregar_Parametros_de_Seguranca();
}



void ouve_comunicacao(void){
     /*-------------------------------------------------------------------------
      Esta função ouve a comunicação do pc para tratar como comando da placa ou
      comando do display. É necessário saber se o computador está conectado para
      fazer o gráfico na memória do hardware ou fazer o grafico na memória do pc.
      Caso count seja zero, não está entrando em execução de comandos e logo o
      pc está desconectado, caso seja maior que 0, o pc está conectado.
     --------------------------------------------------------------------------*/
     static char count=0;
     __delay_ms(100);     

            
      flag_pc_conected=FALSE;
            flag_recomunication =TRUE; 
      while(flag_recomunication==TRUE){ 
            flag_recomunication =FALSE;   
           __delay_ms(200);

           USART_putc(0xCD);USART_putc(0xCD);
           USART_putc(0xCD);USART_putc(0xCD);
           USART_putc(0xCD);USART_putc(0xCD);
           
           for(unsigned int tempo=0; tempo<350; tempo++)
               {
               if(flag_usart_rx==TRUE) break;                           
               my_delay_ms_CLRWDT(1);
               }            


           //------------INTERPRETA COMANDO DO MICROCOMPUTADOR-------------------- 
           if(flag_usart_rx)
              {          
              Comando_Protocolo_Serial(); 
              flag_recomunication=TRUE;
              if(count<5)count++;
              //flag_pc_conected=TRUE;              
              }                    

           //----------------INTERPRETA COMANDO DO DISPLAY----------------
           if(flag_usart_rx)
              { 
              Comando_Display();
              flag_recomunication=TRUE;
              if(count<5)count++;
              //flag_pc_conected=TRUE;              
              }  
           
           //global_porta();
           
      }  
      
      if(count>0)
         { 
         count--;
         flag_pc_conected=TRUE;
         PROCULUS_VP_Write_UInt16(0x40,1); //Icone do computador conectado
         }
      else
         { 
         flag_pc_conected=FALSE; 
         PROCULUS_VP_Write_UInt16(0x40,0); //Icone do computador conectado
         }  
            
      if(flag_autoriza_click_datalog) PROCULUS_Buzzer(10);
       
}


char testa_modo_conectado(unsigned int add, char estado){
            
     if(flag_pc_conected)
       {               
       switch(add)
          {
           case 2: 
                 if(!flag_autoriza_click_datalog)
                    {
                    PROCULUS_VP_Write_UInt16(add,estado);
                    PROCULUS_Popup(FUNCAO_INDISP_MODO_CONNECTADO); 
                    PROCULUS_Buzzer(3000);                
                    return 0;               
                    }
                  flag_autoriza_click_datalog=0; 
                  break;
           case 3: 
                 if(!flag_autoriza_click_condensador)
                    {
                    PROCULUS_VP_Write_UInt16(add,estado);
                    PROCULUS_Popup(FUNCAO_INDISP_MODO_CONNECTADO); 
                    PROCULUS_Buzzer(3000);                
                    return 0;               
                    }               
                  flag_autoriza_click_condensador=0; break;
           case 4: 
                 if(!flag_autoriza_click_vacuo)
                    {
                    PROCULUS_VP_Write_UInt16(add,estado);
                    PROCULUS_Popup(FUNCAO_INDISP_MODO_CONNECTADO); 
                    PROCULUS_Buzzer(3000);                
                    return 0;               
                    }               
                  flag_autoriza_click_vacuo=0; 
                  break;
           case 5: 
                 if(!flag_autoriza_click_aquecimento)
                    {
                    PROCULUS_VP_Write_UInt16(add,estado);
                    PROCULUS_Popup(FUNCAO_INDISP_MODO_CONNECTADO); 
                    PROCULUS_Buzzer(3000);                
                    return 0;               
                    }               
                  flag_autoriza_click_aquecimento=0; 
                  break;
          }     
       //flag_autoriza_click=0;
       }
     return 1;
}                



void Rele_Comum_Aquecimento(char status){
    //-------------------------------------------------------------------------
    //  Controla a ligação comum do aquecimento evitando que o usuário tome 
    //  choque quando for limpar a máquina.
    //  Este comando é aplicado à placa 2
    //-------------------------------------------------------------------------
     char bbb[3]; 
     bbb[0]=1; //Rele 1 da placa PT100
     bbb[1]=status; //ESTADO LIGADO             
     Send_To_Slave(0x02,COMMAND_RELAY,2,bbb);    
}


//void retornoDeBackup(uint16_t vp, uint16_t *tempo, char texto[30])
unsigned char DelayBackupReturn(unsigned int vp, unsigned int *tempo, char texto[20])
{       
    uint8_t retorno=TRUE;
    
    if(*tempo)
      {
      PROCULUS_VP_Write_String(1940,texto);
      while(*tempo)
           {
           (*tempo)--;
           Icones_de_alarmes();      
           ShowSensorRealTimeHS();
           asm("CLRWDT");           
           if(PROCULUS_VP_Read_UInt16(vp)!=1)
             {  
             PROCULUS_VP_Write_UInt16(vp,0);  
             (*tempo)=0;
             retorno=FALSE;
             switch(vp)  
                {     
                 case 0x03: Condensador_Switch(OFF); break;       //Condensador
                 case 0x04:      Vaccum_Switch(OFF); break;       //Vacuo
                 case 0x05: Global_Aquecimento_Switch(OFF); break; //Aquecimento
                } 
             }  
           else
           if(PROCULUS_VP_Read_UInt16(vp)==0)
             {
             retorno = FALSE;
             (*tempo)=0;
             break;
             }  
           }       
      PROCULUS_VP_Write_String(1940,"");
     }
    
    return retorno;      
}


void gravarStatusDosBotoes()
{
if(memo_statuspower!=statuspower.bits) 
  {                  
  EEPROM_Write_Byte(16,statuspower.bits);  //Todos os Status  
  memo_statuspower=statuspower.bits;
  }        
}

void placasFilhasInit(){
     for(char i=0;i<15;i++){
         my_delay_ms_CLRWDT(300);
         Send_To_Slave(i, COMANDO_QUEM_EH_VOCE, 0, buffer); 
     }    
}



void showMemoryInfo()    
{

    char texto[50];
    char msg[50];
    int  tmpValue;
    int  compara;
    char falha=0;
    char tipo;    
    
    print("TESTE DE MEMORIA.");
    strcpy(texto,boardtype[0][0]);
    strcpy(msg,"00 : ");
    strcat(msg,texto);
    strcat(msg," ch:0");
    if(gravaMaeConfere(0,0x00,0xABCD)==false)        
      {  
      strcat(msg," erro!");
      falha++;
      print(msg);
      }       
    
    for(char placa=1;placa<=totalboard;placa++)
       {       
       for(char canal=0;canal<2;canal++)
          {
          strcpy(msg,"");
          strcpy(texto,"");
          itoa(placa,texto,10);
          if(placa<10) strcat(msg,"0");              
          strcat(msg, texto);
          strcat(msg, " : ");           
          tipo = Send_To_Slave(placa, COMANDO_QUEM_EH_VOCE, 0, buffer);
          strcpy(texto, boardtype[tipo][0]);
          strcat(msg,texto);           
           
          strcat(msg," ch:");
          strcpy(texto,"");
          itoa(canal,texto,10);
          strcat(msg,texto);
          strcat(msg," erro! ");
          
          
          if(Tamanho_Display!=81)
            {  
            if(!((placa==2)&&(canal==1)))               
               {
               if(gravaFilhaConfere(placa,canal,0x00,0xABCD)==false)
                 {  
                 print(msg);
                 falha++;
                 }                
               }
            }  
          else
            {  
            if(
              !((placa==2)&&(canal==1)) &&                                   
              !((placa==4)&&(canal==1))                    
              )
              {  
               if(gravaFilhaConfere(placa,canal,0x00,0xABCD)==false)
                {  
                print(msg);
                falha++;
                }                                
              }
            }          
          }       
       }
    
    print("..................................");
    if(falha>0)
      {  
      strcpy(msg,"Falha em memoria(s) = ");
      itoa(falha,texto,10);
      strcat(msg,texto);      
      strcat(msg,".");
      print(msg);
      }
    else
      {
      print("Nenhuma falha nas memorias!");
      }  
    print("Fim do teste de memoria.");
    print("----------------------------------");
    my_delay_ms_CLRWDT(4000);      
}



_Bool gravaFilhaConfere(char placa,char chip, unsigned long add, int valueWrite)
{
     int tempValue;
     unsigned int confere;
     char bb[7];

     //Armazena valor temporario para posterior restauração
     my_delay_ms_CLRWDT(100);
     bb[0]=chip;            //Numero do Chip     
     bb[1]=High(add);
     bb[2]=Lower(add);
     bb[3]=Hi(add);         //Endereço destino 
     bb[4]=Lo(add);      
     tempValue=Send_To_Slave(placa, COMMAND_EEE_R_INT, 5, bb);           
     
     
     //Grava um valor inteiro para ser comparado com sua leitura
     my_delay_ms_CLRWDT(100);
     bb[0]=chip;            //Numero do Chip     
     bb[1]=High(add);
     bb[2]=Lower(add);
     bb[3]=Hi(add);         //Endereço destino 
     bb[4]=Lo(add);     
     bb[5]=Hi(valueWrite);  //Valor a ser gravado  
     bb[6]=Lo(valueWrite); 
     Send_To_Slave(placa, COMMAND_EEE_W_INT, 7, bb);
     
     //Lê o valor inteiro e guarda em 'confere'.
     my_delay_ms_CLRWDT(100); 
     bb[0]=chip;            //Numero do Chip     
     bb[1]=High(add);
     bb[2]=Lower(add);
     bb[3]=Hi(add);         //Endereço destino 
     bb[4]=Lo(add);     
     confere=Send_To_Slave(placa, COMMAND_EEE_R_INT, 5, bb);
     


     
     if(valueWrite==confere)
       {  
       //Restaura o valor original daquele endereço de memória  
       my_delay_ms_CLRWDT(100);  
       bb[0]=chip;            //Numero do Chip     
       bb[1]=High(add);
       bb[2]=Lower(add);
       bb[3]=Hi(add);         //Endereço destino 
       bb[4]=Lo(add);         
       bb[5]=Hi(tempValue);
       bb[6]=Lo(tempValue);
       Send_To_Slave(placa, COMMAND_EEE_W_INT, 7, bb);  
       return true;  
       }
     else
       {         
       return false;
       }
     //print("............................");
}



_Bool gravaMaeConfere(char chip, unsigned long add, int valueWrite)
{
    int tempValue;
    int compara;
    
    tempValue=EEPROM_24C1025_Read_Int (chip,add);
    my_delay_ms_CLRWDT(100); 
    EEPROM_24C1025_Write_Int(chip,add,valueWrite);
    my_delay_ms_CLRWDT(100); 
    compara=EEPROM_24C1025_Read_Int (chip,add);
    my_delay_ms_CLRWDT(100); 
    
    if(valueWrite==compara)
      {  
      EEPROM_24C1025_Write_Int(chip,add,tempValue);  
      return true;
      }
    else
      {
      return false;  
      }
}