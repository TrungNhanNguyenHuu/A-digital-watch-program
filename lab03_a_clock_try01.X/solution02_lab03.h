#ifndef SOLUTION02_LAB03_H
#define	SOLUTION02_LAB03_H

#include "setup_basic.h"
#include "solution_lab03.h"

//
void display_normal_clock (void);
volatile unsigned char hr = 0, min = 0, sec = 0;
void normal_clock_run (void);
int count_1sec = 0;

unsigned char flag_for_dot_dot = 0;
unsigned char flag_change_normal_hour = 0;
unsigned char flag_change_normal_min = 0;
unsigned char flag_change_normal_sec = 0;
//

//working with button
unsigned char RA5flag = 0;

unsigned char RB0flag = 0;
int RB0_press_count = 0;
int count_change_time = 0;
//

//modify hour, min, second
void modify_hour(void);
void modify_min(void);
void modify_sec(void);
void return_basic_display(void);
//

int blink_2sec = 0;

void stopwatch_mode(void);
volatile unsigned char min2 = 0, sec2 = 0, sec0_01 = 0;
unsigned char flag_change_normal_min2 = 0;
unsigned char flag_change_normal_sec2 = 0;
unsigned char flag_change_normal_sec00_2 = 0;
int number_press = 0;
unsigned char stopwatch_firsttime = 0;
int count_1sec_stopwatch = 0;


void readButton_RA5(void);
#define second_1s 396           //100  //
//define for my Finite State Machine for RA5 first // just doing example
enum {mode_zero, mode_one, mode_two, mode_three, mode_four} MY_FSM;
unsigned char current_state = mode_zero; //current_state variable is 1 byte (8 bits)
void FSM_of_me(void);
//

#endif

