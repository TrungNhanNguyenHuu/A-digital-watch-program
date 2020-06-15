/*
 * File:   main.c
 * Author: NGUYEN HUU TRUNG NHAN - Student ID: 1752392
 * Lab 03: A clock
 * Created on September 20, 2019, 2:21 PM
 */
#include "setup_basic.h"
void main(void){
    system_initialize();
    LCDInit();//
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    while(1){
        
    }
    return;//should never reach this line
}