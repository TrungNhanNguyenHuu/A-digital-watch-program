#include "solution02_lab03.h"

void display_normal_clock (void){
    switch(current_state){
        case mode_zero:{
            //
            if (flag_for_dot_dot == 0){
                flag_for_dot_dot = 1;
                LCDPutInst(0x80);
                LCDPutChar(hr/10+'0');
                LCDPutChar(hr%10+'0');
                LCDPutChar(':');
                LCDPutChar(min/10+'0');
                LCDPutChar(min%10+'0');
                LCDPutChar(':');
                LCDPutChar(sec/10+'0');
                LCDPutChar(sec%10+'0');
            }
            //
            if (flag_change_normal_sec == 1){
                flag_change_normal_sec = 0;
                LCDPutInst(0x86);
                LCDPutChar(sec/10+'0');
                LCDPutChar(sec%10+'0');
            }
            if (flag_change_normal_min == 1){
                flag_change_normal_min = 0;
                LCDPutInst(0x83);
                LCDPutChar(min/10+'0');
                LCDPutChar(min%10+'0');
            }
            if (flag_change_normal_hour == 1){
                flag_change_normal_hour = 0;
                LCDPutInst(0x80);
                LCDPutChar(hr/10+'0');
                LCDPutChar(hr%10+'0');
            }
            break;
        }
        
        case mode_one:{
            if (flag_change_normal_sec == 1){
                flag_change_normal_sec = 0;
                LCDPutInst(0x86);
                LCDPutChar(sec/10+'0');
                LCDPutChar(sec%10+'0');
            }
            if (flag_change_normal_min == 1){
                flag_change_normal_min = 0;
                LCDPutInst(0x83);
                LCDPutChar(min/10+'0');
                LCDPutChar(min%10+'0');
            }
            if (flag_change_normal_hour == 1){
                flag_change_normal_hour = 0;
                LCDPutInst(0x80);
                LCDPutChar(hr/10+'0');
                LCDPutChar(hr%10+'0');
            }
            blink_2sec = blink_2sec + 1;
            LCDPutInst(0x80);
            if (blink_2sec == second_1s/2){
                LCDPutChar('_');
                LCDPutChar('_');
            }
            if (blink_2sec == second_1s){
                blink_2sec = 0;
                LCDPutChar(hr/10+'0');
                LCDPutChar(hr%10+'0');
            }
            break;
        }
        
        case mode_two:{
            if (flag_change_normal_sec == 1){
                flag_change_normal_sec = 0;
                LCDPutInst(0x86);
                LCDPutChar(sec/10+'0');
                LCDPutChar(sec%10+'0');
            }
            if (flag_change_normal_min == 1){
                flag_change_normal_min = 0;
                LCDPutInst(0x83);
                LCDPutChar(min/10+'0');
                LCDPutChar(min%10+'0');
            }
            if (flag_change_normal_hour == 1){
                flag_change_normal_hour = 0;
                LCDPutInst(0x80);
                LCDPutChar(hr/10+'0');
                LCDPutChar(hr%10+'0');
            }
            blink_2sec = blink_2sec + 1;
            LCDPutInst(0x83);
            if (blink_2sec == second_1s/2){
                LCDPutChar('_');
                LCDPutChar('_');
            }
            if (blink_2sec == second_1s){
                blink_2sec = 0;
                LCDPutChar(min/10+'0');
                LCDPutChar(min%10+'0');
            }
            break;
        }
        
        case mode_three:{
            if (flag_change_normal_sec == 1){
                flag_change_normal_sec = 0;
                LCDPutInst(0x86);
                LCDPutChar(sec/10+'0');
                LCDPutChar(sec%10+'0');
            }
            if (flag_change_normal_min == 1){
                flag_change_normal_min = 0;
                LCDPutInst(0x83);
                LCDPutChar(min/10+'0');
                LCDPutChar(min%10+'0');
            }
            if (flag_change_normal_hour == 1){
                flag_change_normal_hour = 0;
                LCDPutInst(0x80);
                LCDPutChar(hr/10+'0');
                LCDPutChar(hr%10+'0');
            }
            blink_2sec = blink_2sec + 1;
            LCDPutInst(0x86);
            if (blink_2sec == second_1s/2){
                LCDPutChar('_');
                LCDPutChar('_');
            }
            if (blink_2sec == second_1s){
                blink_2sec = 0;
                LCDPutChar(sec/10+'0');
                LCDPutChar(sec%10+'0');
            }
            break;
        }
        
        case mode_four:{
            if ((flag_change_normal_sec00_2 == 1) || (stopwatch_firsttime == 0)){
                flag_change_normal_sec00_2 = 0;
                LCDPutInst(0x86);
                LCDPutChar(sec0_01/10+'0');
                LCDPutChar(sec0_01%10+'0');
            }
            if ((flag_change_normal_sec2 == 1) || (stopwatch_firsttime == 0)) {
                flag_change_normal_sec2 = 0;
                LCDPutInst(0x83);
                LCDPutChar(sec2/10+'0');
                LCDPutChar(sec2%10+'0');
            }
            if ((flag_change_normal_min2 == 1) || (stopwatch_firsttime == 0)){
                stopwatch_firsttime = 1;
                flag_change_normal_min2 = 0;
                LCDPutInst(0x80);
                LCDPutChar(min2/10+'0');
                LCDPutChar(min2%10+'0');
            }
            flag_for_dot_dot = 0;
            break;
        }
    }
}

void normal_clock_run (void){
    sec++;                      // Increment seconds
    flag_change_normal_sec = 1;
    if (sec > 59) {               // Condition if seconds is greater than 59
        sec = 0;                // Set seconds to 0
        min++;                  // Increment minutes
        flag_change_normal_sec = 1;
        flag_change_normal_min = 1;
    }
    if (min > 59) {               // Condtion if minutes is greater than 59
        min = 0;                // Set minutes to 0
        hr++;                   // Increment hours
        flag_change_normal_min = 1;
        flag_change_normal_hour = 1;
    }
    if (hr > 23 && min == 0 && sec == 0) {    //Condition if clock reaches (24:00:00)
        hr = 0;                     // Set hour to 0
        flag_change_normal_hour = 1;
    }
    //display_normal_clock();                   // Display clock
}

void return_basic_display(void){
    LCDPutInst(0x80);
    LCDPutChar(hr/10+'0');
    LCDPutChar(hr%10+'0');
    LCDPutChar(':');
    LCDPutChar(min/10+'0');
    LCDPutChar(min%10+'0');
    LCDPutChar(':');
    LCDPutChar(sec/10+'0');
    LCDPutChar(sec%10+'0');    
}

void modify_hour(void){
    if (PORTBbits.RB0 == 0){
        RB0_press_count = RB0_press_count + 1;
        if (RB0flag == 0){
            RB0flag = 1;
            hr = hr + 1;
            if (hr > 23){
            hr = 0;
            }
            flag_change_normal_hour = 1;
            display_normal_clock();
        }
        if (RB0_press_count > second_1s){
            count_change_time = count_change_time + 1;
            if (count_change_time == (second_1s/5)){
                count_change_time = 0;
                hr = hr + 1;
                if (hr > 23){
                    hr = 0;
                }
                flag_change_normal_hour = 1;
                display_normal_clock();
            }
        }
    }
    else {
        RB0flag = 0;
        RB0_press_count = 0;
        count_change_time = 0;
    }
}

void modify_min(void){
    if (PORTBbits.RB0 == 0){
        RB0_press_count = RB0_press_count + 1;
        if (RB0flag == 0){
            RB0flag = 1;
            min = min + 1;
            if (min > 59){
            min = 0;
            }
            flag_change_normal_min = 1;
            display_normal_clock();
        }
        if (RB0_press_count > second_1s){
            count_change_time = count_change_time + 1;
            if (count_change_time == (second_1s/5)){
                count_change_time = 0;
                min = min + 1;
                if (min > 59){
                    min = 0;
                }
                flag_change_normal_min = 1;
                display_normal_clock();
            }
        }
    }
    else {
        RB0flag = 0;
        RB0_press_count = 0;
        count_change_time = 0;
    }    
}

void modify_sec(void){
    if (PORTBbits.RB0 == 0){
        RB0_press_count = RB0_press_count + 1;
        if (RB0flag == 0){
            RB0flag = 1;
            sec = sec + 1;
            if (sec > 59){
            sec = 0;
            }
            flag_change_normal_sec = 1;
            display_normal_clock();
        }
        if (RB0_press_count > second_1s){
            count_change_time = count_change_time + 1;
            if (count_change_time == (second_1s/5)){
                count_change_time = 0;
                sec = sec + 1;
                if (sec > 59){
                    sec = 0;
                }
                flag_change_normal_sec = 1;
                display_normal_clock();
            }
        }
    }
    else {
        RB0flag = 0;
        RB0_press_count = 0;
        count_change_time = 0;
    }
}

void readButton_RA5(void){
    if ((RA5flag == 0)&&(PORTAbits.RA5 == 0)){
        RA5flag = 1;
        if (current_state == mode_zero){
            current_state = mode_one;
            return;
        }
        if (current_state == mode_one){
            current_state = mode_two;
            return_basic_display();
            return;
        }
        if (current_state == mode_two){
            current_state = mode_three;
            return_basic_display();
            return;
        }
        if (current_state == mode_three){
            current_state = mode_four;
            return;
        }
        if (current_state == mode_four){
            current_state = mode_zero;
            return;
        }
    }
    if (PORTAbits.RA5 != 0){
        RA5flag = 0;
    }
}

void FSM_of_me(void){
    readButton_RA5();
    count_1sec = count_1sec + 1;
    if (count_1sec == second_1s){
        count_1sec = 0;
        normal_clock_run();
    }
    switch(current_state){
        case mode_zero: {
            display_normal_clock();
            
            //reset_the stopwatch
            sec0_01 = 0;
            sec2 = 0;
            min2 = 0;
            number_press = 0;
            count_1sec_stopwatch = 0;
            stopwatch_firsttime = 0;
            break;
        }
        case mode_one: {
            display_normal_clock();
            modify_hour();
            break;
        }
        case mode_two: {
            display_normal_clock();
            modify_min();
            break;
        }
        case mode_three: {
            display_normal_clock();
            modify_sec();
            break;
        }
        case mode_four: {
            stopwatch_mode();
            display_normal_clock();
            break;
        }
    }
}

void stopwatch_mode(void){
    if ((PORTBbits.RB0 == 0)&&(RB0flag == 0)){
        RB0flag = 1;
        number_press = number_press + 1;
    }
    
    if (PORTBbits.RB0 != 0){
        RB0flag = 0;
    }
    
    if (number_press % 2 != 0){
        count_1sec_stopwatch = count_1sec_stopwatch + 1;
        if (count_1sec_stopwatch == second_1s/100){
            count_1sec_stopwatch = 0;
            
            sec0_01++;                      
            flag_change_normal_sec00_2 = 1;
            if (sec0_01 > 99) {            
                sec0_01 = 0;              
                sec2++;                  
                flag_change_normal_sec00_2 = 1;
                flag_change_normal_sec2 = 1;
            }
            if (sec2 > 59) {            
                sec2 = 0;               
                min2++;                
                flag_change_normal_sec2 = 1;
                flag_change_normal_min2 = 1;
            }
            if (min2 > 59 && sec2 == 0 && sec0_01 == 0) {  
                min2 = 0;                   
                flag_change_normal_min2 = 1;
            }
        }
    }
    else{
        sec0_01 = sec0_01;
        sec2 = sec2;
        min2 = min2;
        count_1sec_stopwatch = 0;
    }
}