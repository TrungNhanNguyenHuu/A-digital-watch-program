#ifndef SETUP_BASIC_H
#define	SETUP_BASIC_H

#ifdef _18F8722
#pragma config  OSC = HSPLL
#pragma config 	FCMEN = OFF
#pragma config 	IESO = OFF
#pragma config 	PWRT = OFF
#pragma config 	BOREN = OFF
#pragma config 	WDT = OFF
#pragma config 	MCLRE = ON
#pragma config 	LVP = OFF
#pragma config 	XINST = OFF
#endif

#define _XTAL_FREQ 10000000 // 10 MHz for HSPLL mode

#include <xc.h>
#include <stdio.h> //C program basic

void system_initialize(void);       //
void pin_manager(void);
void oscillator_initialize(void);
void interrupt_initialize(void);
void timer_0_initialize(void);      //
volatile unsigned short timer0ReloadVal; // a variable 16 bits used in function timer_0_initialize(), 2 bytes x 8 bits;

void __interrupt() function_interrupt(void);

#include "solution_lab03.h"
#include "solution02_lab03.h"

//int count_01_second = 0;
//int flag_veryfirst01 = 0;

//int count = 0;//flag for test :)
//int count02 = 0; // for test :)
#endif

