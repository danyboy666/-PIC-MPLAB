/////////////////////////////////////////////////////////////////////////////
//                                                                         // 
// Laboratoire de l'horloge numérique - partie 3                           //
// avec microcontrôleur PIC16F877                                          //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
//                                                                         // 
// 244Lab05                                                                //
// Dany et Amélie                                                          //
// le 22 Février 2011                                                      //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "main.h"


void main()
{

   #define  mins PIN_C0
   #define  hrs  PIN_C1
   #define  AmPm PIN_C2
   
   int8 Hr1=2;
   int8 Hr10=1;
   int8 Min1=0;
   int8 Min10=0;
   int8 j=0;
      
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);

   output_b(0);
   output_low(hrs);
   output_high(mins);

While (TRUE) {
   
for(j=1;j<2;j=j+1){
      
 output_toggle(hrs);
 output_toggle(mins);
 output_b((Hr10<<4)+(Hr1));
 
 delay_ms(10);
 
 output_toggle(hrs);
 output_toggle(mins);
 output_b((Min10<<4)+(Min1));
 
 delay_ms(10);
 
}; 
 
 Min1=Min1+1;




If (Min1==10){
 
   Min1=0;
   Min10=Min10+1;

      if (Min10==6){
         
         Min10=0;
         Hr1=Hr1+1;
         };
         
         if ((Hr10==15)&&(Hr1==10)){
                  
                Hr10=1;
                Hr1=0;
                };
            
                   if ((Hr10==1)&&(Hr1==3)){
               
                     Hr1=1;
                     Hr10=15;
                   
              
                      output_toggle(AmPm);
                  
                  };
                  
                  
                     
                  
                  
 };
  

 };

}



 
