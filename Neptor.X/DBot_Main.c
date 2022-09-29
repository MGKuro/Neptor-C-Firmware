/*
 * File:   DBot_Main.c
 * Author: Mauro Gación
 *
 * Created on 27 de noviembre de 2018, 18:26
 */


////////////////////////////////////////////////////////////////////
//                                                                //
//                            INCLUDES                            //
//                                                                //
////////////////////////////////////////////////////////////////////

#include <xc.h>
#include <pic16f628a.h>
#include "DBot.h"

////////////////////////////////////////////////////////////////////
//                                                                //
//                      CONFIGURATION BITS                        //
//                                                                //
////////////////////////////////////////////////////////////////////

// PIC16F628a Configuration Bit Settings

// CONFIG
#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSC oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable bit (RB4/PGM pin has PGM function, low-voltage programming enabled)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

////////////////////////////////////////////////////////////////////
//                                                                //
//                          DECLARATIONS                          //
//                                                                //
////////////////////////////////////////////////////////////////////

void GeneralConfig(void);
void __interrupt() GeneralInterrupt(void);


////////////////////////////////////////////////////////////////////
//                                                                //
//                           VARIABLES                            //
//                                                                //
////////////////////////////////////////////////////////////////////

unsigned char HC06_Data[3];
int Data_Length = 0;

////////////////////////////////////////////////////////////////////
//                                                                //
//                              MAIN                              //
//                                                                //
////////////////////////////////////////////////////////////////////

void main(void){
    
    GeneralConfig(); //Configuración general.
    
    while(1){RobotControl();} //Bucle infinito.
     
    return;
}

////////////////////////////////////////////////////////////////////
//                                                                //
//                           FUNCTIONS                            //
//                                                                //
////////////////////////////////////////////////////////////////////

void GeneralConfig(void){

    //Oscilador
    OSCF = 1; // Internal oscillator at 4MHz
    //OSCCON = 0b00111000; //Internal 8MHz
    
    //Pines analógicos a digitales.
    CMCON = 0b00000111; //Comparator off, pins as digital I/O.
    
    //TRIS PIN
    TRISSL = 1;
    TRISSR = 1;
    
    TRIS1M1 = 0;
    TRIS2M1 = 0;
    TRIS1M2 = 0;
    TRIS2M2 = 0;
    M1PIN1 = 1;
    M1PIN2 = 1;
    M2PIN1 = 1;
    M2PIN2 = 1;
    
    TRISRX = 1;
    TRISTX = 1;
     
    //USART
    USARTConfig(); //USART Config
     
    //HC06 Config
    Delay_HalfSeg(1);
    HC06Config();
    
    PIE1bits.RCIE = 1; //USART Receive Interruption enabled.
     
    //Timer Config
    TMR1 = 255254; //Preload (1 us)
    T1CON = 0b01000001;
    PIE1bits.TMR1IE = 1; //Timer1 Interrupt enabled.
    INTCONbits.INTE = 1; //Interrupt from INT Pin.
    OPTION_REGbits.INTEDG = 1; //Interrupt at rise edge.
    INTCONbits.PEIE = 1; //PIR1 and PIR2 interrupt registers active.
    INTCONbits.GIE = 1; //Global interrupt enabled.
    
    

}



void __interrupt() GeneralInterrupt(void){

    if(PIR1bits.RCIF == 1){ //Si es provocada por recepción del USART
        
        Data_Length = USARTRead(HC06_Data); //Recepción.
        ReceiveControl(HC06_Data); //Variable control. 
        
    }
    
    if(PIR1bits.TMR1IF == 1){
        
      RobotControl(); //Control del robot      
      PIR1bits.TMR1IF = 0; //Clear flag
    
    }
    
    if(INTF == 1){ //INterrupt by INT pin.
    
        //BLABLABLABLA
    
    }

} 


