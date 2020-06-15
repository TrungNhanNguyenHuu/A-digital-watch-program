#include "setup_basic.h"

void system_initialize(void){
    pin_manager();
    oscillator_initialize();
    interrupt_initialize();
    timer_0_initialize();
}

void pin_manager(void){
    TRISD = 0x00;
    LATD = 0x00;
    
    TRISBbits.TRISB0 = 1;
    
    TRISAbits.TRISA5 = 1;
    ADCON1 = 0b00001111;
}

void oscillator_initialize(void){
    OSCCON = 0b01110000; 
    OSCTUNE = 0b01000000;
}

void interrupt_initialize(void){
    RCONbits.IPEN = 0; //no low priority or high priority
    
    //clear all interrupt priority bit of TIMER 0
    INTCON2bits.TMR0IP = 0;      
}

void timer_0_initialize(void){
    T0CON = 0b00001000;
    TMR0H = 0x9E;
    TMR0L = 0x58;// 10 milliseconds to run from this -> 2^16
    
    timer0ReloadVal = TMR0;
    
    INTCONbits.TMR0IF = 0; //clear the interrupt flag of Timer 0 before enabling the interrupt
    INTCONbits.TMR0IE = 1; //enabling Timer 0 interrupt;
    T0CONbits.TMR0ON = 1; // Timer 0 starts to run
}

void __interrupt() function_interrupt(void){
    if ((INTCONbits.TMR0IE == 1) &&(INTCONbits.TMR0IF == 1)){
        INTCONbits.TMR0IF = 0; // set the flag off
        TMR0H = (timer0ReloadVal >> 8);
        TMR0L = (unsigned char) timer0ReloadVal; // unsigned char is 1 byte (8 bits)
        
        //example code
        //if (PORTAbits.RA5 == 0){
        //if (PORTBbits.RB0 == 0){
        //    LATD = 0xFF;
        //}
        //else{
        //    LATD = 0x00;
        //}
        
        //count02 = count02 + 1;
        //if ((count == 0)&&(count02 == 1915)){ 
        //if (count == 0){
        //    count = 1;
        //    count02 = 0;
            // Initialize LCD
        //    LCDInit();
    
            // Display Intro text on LCD
        //    LCDPutInst(LCD_CURSOR_LINE1);
            //LCDPutStr("Microchip PICDEM");
        //    LCDPutStr("PIC18");
        //    LCDPutInst(0x0F);
        //    LCDPutInst(0x02);
        //    LCDPutInst(LCD_CURSOR_LINE2);
            //LCDPutStr(" PIC18 Explorer ");
        //    LCDPutStr("Microchip PICDEM");
        //}
        
        //if (flag_veryfirst01 == 0){
        //    flag_veryfirst01 = 1;
        //    LCDInit();
        //    display_normal_clock();
        //}
        //count_01_second = count_01_second + 1;
        //if (count_01_second == 383){
        //    count_01_second = 0;
        //    normal_clock_run();
        //}
     
        FSM_of_me();
    }
}
 
