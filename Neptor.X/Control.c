#include <xc.h>
#include "DBot.h"

int i = 0;

void MoveForward(void){
    M1Right(0);
    M1Left(MotorPWM);
    M2Left(0);
    M2Right(MotorPWM);
}

void MoveBackward(void){
    M1Left(0);
    M1Right(MotorPWM);
    M2Right(0);
    M2Left(MotorPWM);
}

void MoveLeft(void){
    M1Left(0);
    M1Right(MotorPWM);
    M2Right(0);
    M2Left(MotorPWM);
    
}

void MoveRight(void){
    M1Left(0);
    M1Right(MotorPWM);
    M2Left(0);
    M2Right(MotorPWM);
}

void Stop(void){
    M1Left(0);
    M1Right(0);
    M2Left(0);
    M2Right(0);
}

void RobotControl(void){
    
    //MANUAL MODE
    if(ManualMode == 1){
    
        if(Pressed == 0){Stop();}
        
        else if(Pressed == 1){MoveForward();}
        
        else if(Pressed == 2){MoveBackward();}
        
        else if(Pressed == 3){MoveLeft();}
        
        else if(Pressed == 4){MoveRight();}

    }    
    
    //AUTO MODE
    else if(ManualMode == 0){  
        
        if(SL == 1 || SR == 1 || SB == 0){//Controlamos el robot, mirando SR, SL y SB.   
            
            /*La variable i permite moverse por pasos mientras se chequea SR, SL y SB a razón de 1 seg.*/
        
            if(i<=4){
              MoveForward();
              Delay_Seg(1);
              i++;
            }
            else if(4<i<=7){
              MoveLeft();
              Delay_Seg(1);
              i++;
            }
            else if(7<i<=12){
              MoveForward();
              Delay_Seg(1);
              i++;
            }
            else if(12<i<=15){
              MoveRight();
              Delay_Seg(1);
              i++;
            }
            else if(15<i<=18){
            MoveRight();
            Delay_Seg(1);
            i++;
            }
            else{i=0;}
        
        }
        else if(SL == 0 || SR == 0 || SB == 1){//Nos retiramos del obstáculo.
            
            Stop();
            MoveBackward();
            Delay_Seg(2);
            Stop();
            MoveRight();
            Delay_Seg(3);
            Stop();
            
        }
    
    }
    


}
