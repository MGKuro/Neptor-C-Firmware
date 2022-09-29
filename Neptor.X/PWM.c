#include <xc.h>
#include "DBot.h"

void M1Left(int PWM){

    if(PWM == 0){M1PIN1 = 1;}
    
    else if(PWM < PWM_Limit){
      
        if(M1Step < PWM){
            M1PIN1 = 0;
            M1Step++;
        }
        else if(M1Step < PWM_Limit){
            M1PIN1 = 1;
            M1Step++;
        }
        else if(M1Step >= PWM_Limit){
            M1Step=0;
        }   
    }
    
    else {M1PIN1=0;}

}

void M1Right(int PWM){

    if(PWM == 0){M1PIN2 = 1;}
    
    else if(PWM < PWM_Limit){
      
        if(M1Step < PWM){
            M1PIN2 = 0;
            M1Step++;
        }
        else if(M1Step < PWM_Limit){
            M1PIN2 = 1;
            M1Step++;
        }
        else if(M1Step >= PWM_Limit){
            M1Step=0;
        }   
    }
    
    else {M1PIN2=0;}

}

void M2Left(int PWM){

    if(PWM == 0){M2PIN1 = 1;}
    
    else if(PWM < PWM_Limit){
      
        if(M2Step < PWM){
            M2PIN1 = 0;
            M2Step++;
        }
        else if(M2Step < PWM_Limit){
            M2PIN1 = 1;
            M2Step++;
        }
        else if(M2Step >= PWM_Limit){
            M2Step=0;
        }   
    }
    
    else {M2PIN1=0;}

}

void M2Right(int PWM){

    if(PWM == 0){M2PIN2 = 1;}
    
    else if(PWM < PWM_Limit){
      
        if(M2Step < PWM){
            M2PIN2 = 0;
            M2Step++;
        }
        else if(M2Step < PWM_Limit){
            M2PIN2 = 1;
            M2Step++;
        }
        else if(M2Step >= PWM_Limit){
            M2Step=0;
        }   
    }
    
    else {M2PIN2=0;}

}
