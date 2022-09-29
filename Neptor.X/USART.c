//USART Functions

#include <xc.h>
#include "DBot.h"



void USARTConfig(void){ //USART Configuration

    //BAUDRATE (9600) = Fosc/(64*(SPBRG+1))
    
    SPBRG = 32; 
    TXSTA = 0b00100010;
    RCSTA = 0b10010110; 

}

void USARTWrite(char *text, int length){

    int i=0;
    
    for(i=0;i<length;i++){
    
        while(!TXSTAbits.TRMT);
        TXREG = text[i];
    }

}

int USARTRead(char *Rxdata){

    int j=0;
    
    while(PIR1bits.RCIF){
         
            if(RCSTAbits.OERR == 1) //Overrun error           
               {RCSTAbits.CREN = 0; //Clear overrun error (disable receiver)                              
                RCSTAbits.CREN = 1;} //Enable receiver       
            if(RCSTAbits.FERR == 1) //Framing error bit
               {RCSTAbits.SPEN = 0; //Serial Port Disable
                RCSTAbits.SPEN = 1;}
                       
            Rxdata[j]=RCREG; 
            j++;
   
        }
    
    return j;

}

void HC06Config(void){

    
    while(!TXSTAbits.TRMT);
    USARTWrite("AT+ROLE=S",9);
    while(!TXSTAbits.TRMT);
    Delay_HalfSeg(1);
    USARTWrite("AT+MODE=0",9);
    while(!TXSTAbits.TRMT);
    USARTWrite("AT+NAMEDeskBot",14);
    while(!TXSTAbits.TRMT);
    Delay_HalfSeg(1);
    USARTWrite("AT+PIN1234",10);

}

int DataCompare(unsigned char Buffer[], unsigned char Data[], unsigned int length){

    int i = 0;
    
    while(i<length){
    
        if(Buffer[i] == Data[i]){
        
            i++;
            if(i==length){
            
                return 1;
            
            }
            
        }
        
        if(Buffer[i] != Data[i]){
        
            i=length;
            return 0;
        
        }           
        
    }
    
}

void ReceiveControl(char *Rxdata){

    if(DataCompare(Rxdata, "M",1)){
        ManualMode = 1;
        Stop();
    }
    else if(DataCompare(Rxdata, "A",1)){       
        ManualMode = 0;
    }

    else if(DataCompare(Rxdata, "U",1)){Pressed = 1;}
    else if(DataCompare(Rxdata, "D",1)){Pressed = 2;}
    else if(DataCompare(Rxdata, "L",1)){Pressed = 3;}
    else if(DataCompare(Rxdata, "R",1)){Pressed = 4;}
    else if(DataCompare(Rxdata, "S",1)){Pressed = 0;}
    

}
