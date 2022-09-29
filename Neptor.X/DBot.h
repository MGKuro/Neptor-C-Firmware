/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */


////////////////////////////////////////////////////////////////////
//                                                                //
//                       GLOBAL VARIABLES                         //
//                                                                //
////////////////////////////////////////////////////////////////////

int ManualMode = 0;
int Pressed = 0;
/*0 - Nothing
  1 - Forward
  2 - Backward
  3 - Left
  4 - Right*/

int M1Step = 0;
int M2Step = 0;

int MotorPWM = 10;
int PWM_Limit = 10;

////////////////////////////////////////////////////////////////////
//                                                                //
//                            DEFINES                             //
//                                                                //
////////////////////////////////////////////////////////////////////

/*
 * RA0 = IR1
 * RA1 = N/A
 * RA2 = M3
 * RA3 = M4
 * RA4 = N/A
 * RA5 = MCLR
 * RA6 = N/A
 * RA7 = IR2
 * RB0 = M2
 * RB1 = HC05_TX
 * RB2 = HC05_RX
 * RB3 = M1
 * RB4 = M0
 * RB5 = Bumper
 * RB6 = PGC
 * RB7 = PGD
 */

//Pin Defines
#define TRIS1M1 TRISBbits.TRISB3
#define TRIS2M1 TRISBbits.TRISB0
#define TRIS1M2 TRISAbits.TRISA2
#define TRIS2M2 TRISAbits.TRISA3
#define TRISSL TRISAbits.TRISA0
#define TRISSR TRISAbits.TRISA7
#define M2PIN2 PORTAbits.RA2
#define M2PIN1 PORTAbits.RA3 
#define M1PIN1 PORTBbits.RB3
#define M1PIN2 PORTBbits.RB0 
#define SR PORTAbits.RA7
#define SB PORTBbits.RB5
#define SL PORTAbits.RA0
#define TRISRX TRISBbits.TRISB5
#define TRISTX TRISBbits.TRISB4

////////////////////////////////////////////////////////////////////
//                                                                //
//                           USART.c                              //
//                                                                //
////////////////////////////////////////////////////////////////////


void USARTConfig(void); //USART Configuration
void USARTWrite(char *text, int length); //USART Transmition
int USARTRead(char *Rxdata); //USART Reception, return "length" as int.

void HC06Config(void); //HC06 Module Config.
int DataCompare(unsigned char Buffer[], unsigned char Data[], unsigned int length); //Char compare.
void ReceiveControl(char *Rxdata); //Change variable according to button pressed.


////////////////////////////////////////////////////////////////////
//                                                                //
//                         MyDelays.c                             //
//                                                                //
////////////////////////////////////////////////////////////////////

void Delay_HalfSeg(unsigned int j);
void Delay_Seg(unsigned int j);

////////////////////////////////////////////////////////////////////
//                                                                //
//                             PWM.c                              //
//                                                                //
////////////////////////////////////////////////////////////////////

void M1Left(int PWM); //Motor 1 a la izquierda
void M1Right(int PWM); //Motor 1 a la derecha
void M2Left(int PWM); //Motor 2 a la izquierda
void M2Right(int PWM); //Motor 2 a la derecha

////////////////////////////////////////////////////////////////////
//                                                                //
//                           Control.c                            //
//                                                                //
////////////////////////////////////////////////////////////////////

void MoveForward(void); //Avanzar
void MoveBackward(void); //retroceder
void MoveLeft(void); //Girar a la izquierda
void MoveRight(void); //Girar a la derecha.
void Stop(void); //Detenerse

void RobotControl(void); //Control general del robot

