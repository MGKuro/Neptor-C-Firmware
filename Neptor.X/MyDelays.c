#include <xc.h>
#define _XTAL_FREQ 8000000

void Delay_HalfSeg(unsigned int j){

    int i;
    
    j=j*50;
    
    for(i=0;i<j;i++){
    
        __delay_ms(10);
    
    }
}

void Delay_Seg(unsigned int j){

    int i;
    
    j=j*100;
    
    for(i=0;i<j;i++){
    
        __delay_ms(10);
    
    }
}
