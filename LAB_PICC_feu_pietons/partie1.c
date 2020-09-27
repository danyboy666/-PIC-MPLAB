/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//                             244Lab04                                    //
// Laboratoire de pratique faisant clignoter six LED actives sur niveau    //
// sur niveau haut en alternance avec microcontrôleur PIC16F877.           //
// Connecté sur les bornes de sorties RB0 à RB5                            //
//                                                                         //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
//                                                                         // 
// Rédigé Par: Dany et Amélie                                              //
// Groupe: 2471                                                            //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////


#include "\\TgeSrv1\Élèves_Dossiers\echaa013\Bureau\244Lab4\partie1.h"

   
   #define bpieton PIN_A0
   #define rouge_P PIN_C1
  
   
   int1 appui;
   int k;
   Int i;
   Int1 interdit=0;
   
void feupieton ();


void main()
{
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);

   appui=FALSE;

   output_b(0);

DO {
      
     output_b(0b00001001);    
      
      k=1;
      
      While(k<10){
            delay_ms(300);
            k=k+1;
         if(input(bpieton)==0)appui=true;
         
         interdit=~interdit;
         output_bit(rouge_P,interdit) ;
      };
            
      output_b(0b00001010);
      
      k=1;
      
      While(k<10){
            delay_ms(300);
            k=k+1;
         if(input(bpieton)==0)appui=true;
         
         interdit=~interdit;
         output_bit(rouge_P,interdit) ;
      };
      
      if(appui==true)feupieton();
         
      output_b(0b00100100);
      
      k=1;
      
      While(k<10){
            delay_ms(300);
            k=k+1;
         if(input(bpieton)==0)appui=true;
         
         interdit=~interdit;
         output_bit(rouge_P,interdit) ;
         
      };
       
         output_b(0b00010100);
         
         k=1;
      
      While(k<10){
            delay_ms(300);
            k=k+1;
         if(input(bpieton)==0)appui=true;
         
         interdit=~interdit;
         output_bit(rouge_P,interdit) ;
      };
      
     if (appui==true)feupieton();
   }  
    
While (TRUE);
}

void feupieton (){

      output_c(0b00000000);
      output_b(0b00000000);
      delay_ms(500);
      output_b(0b00001100);
  For (i=1;i<=5;++i){
      output_c(0b00000001);
      delay_ms(1000);
      output_c(0b00000000);
      delay_ms(500);
   
  }
 
   appui = false;
 
}
