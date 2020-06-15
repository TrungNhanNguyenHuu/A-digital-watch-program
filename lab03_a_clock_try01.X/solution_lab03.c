#include "solution_lab03.h"

void LCDInit(void){
    InitBBSPI();
    TRISFbits.TRISF6 = 0; //RF6 pin is outpu and it controls the reset pin of MCP23S17
    LATFbits.LATF6 = 0; // RF6 value is '0' (clear, reset MCP23S17)
    __delay_ms(5);//
    LATFbits.LATF6 = 1;
    Port_BBSPIInit (PORTA_DIR);     // initialize MCP23S17 PORTA
    Port_BBSPIInit (PORTB_DIR);     // initialize MCP23S17 PORTB
    WritePort_BBSPI (PORTA_ADD, 0);
    __delay_ms(10); // required by display controller to allow power to stabilize//
    LCDPutInst(0x32);               // required by display initialization
    LCDPutInst(FUNCTION_SET);       // set interface size, # of lines and font
    LCDPutInst(DISPLAY_SETUP);      // turn on display and sets up cursor
    LCDPutInst(0x01);               // clear the display
    LCDPutInst(ENTRY_MODE);         // set cursor movement direction
}

void InitBBSPI (void){
    TRISAbits.TRISA2 = 0; //RA2 pin is output
    LATAbits.LATA2 = 1; //RA2 pin value is HIGH
    
    TRISCbits.TRISC4 = 1; //RC4 pin is input
    LATCbits.LATC4 = 1; // RC4 pin value is HIGH
    
    TRISCbits.TRISC5 = 0; //RC5 pin is output
    LATCbits.LATC5 = 0; // RC5 value is '0' (clear)
    
    TRISCbits.TRISC3 = 0; //RC3 pin is ouput 
    LATCbits.LATC3 = 0; //RC3 value is '0' (clear)
}

void Port_BBSPIInit(unsigned char port_dir){
    LATAbits.LATA2 = 0; //// lower (RA2) CS to initialize SPI write operation on MCP923S17
    SendByteBBSPI(0x40);        // transmit device opcode (slave address and write enable)
    SendByteBBSPI(port_dir);    // point to address of IODIRx(I/O Direction register of PORTx)
    SendByteBBSPI(0x00);        // set all PORTx pins as output
    LATAbits.LATA2 = 1;                 // end sequence
}

void SendByteBBSPI (unsigned char output) {
    unsigned char bitcount;
    unsigned char input = output;
    
    for(bitcount=0;bitcount<8;bitcount++)
    {
       // transmit data MSB
        if(output & 0x80)                // condition if transmit byte MSB is 1
            LATCbits.LATC5 = 1;                // make SDO pin output high
        else                             // condition if byte MSB is 0
            LATCbits.LATC5 = 0;                // make SDO pin output low
        // receive dummy data
        if (LATCbits.LATC4)                     // condition if receive byte MSB is 1
            input = (input << 1) | 0x1;  // shift input 1 bit to the left and move carry bit to LSB
        else                             // condition if receive bit is 0
            input = input << 1;          // shift input 1 bit to the left
        LATCbits.LATC3 = 1;                           // set the SCLK pin
        NOP();NOP();NOP();NOP();NOP();NOP();    // produces ~50% duty cycle clock
        NOP();NOP();NOP();NOP();NOP();NOP();
        LATCbits.LATC3 = 0;                           // clear the SCLK pin
        output <<= 1;                           // shift output 1 bit to the left
    }
}

void WritePort_BBSPI (unsigned char port_add, unsigned char a){
    LATAbits.LATA2 = 0; // lower CS to initialize SPI write operation on MCP923S17
    SendByteBBSPI(0x40);        // transmit device opcode (slave address and write enable)
    SendByteBBSPI(port_add);    // point to address of GPIOx (General Purpose I/O of PORTx)
    SendByteBBSPI(a);           // write value to GPIOx
    LATAbits.LATA2 = 1;                 // end sequence  
}

void LCDPutInst (unsigned char ch){
    __delay_ms(2);
    WritePort_BBSPI (PORTA_ADD, instr);       // prepare to send instruction to LCD
    __delay_ms(1);
    WritePort_BBSPI (PORTB_ADD, ch);          // write the instruction to be sent to LCD
    __delay_ms(1);
    WritePort_BBSPI (PORTA_ADD,send_instr);   // send instruction to LCD
    __delay_ms(1);
    WritePort_BBSPI (PORTA_ADD, 0x00);        // stop sending instruction to LCD
}

void LCDPutChar (unsigned char ch){
    __delay_ms(2);
    WritePort_BBSPI (PORTA_ADD, data);        // prepare to send data to LCD
    __delay_ms(1);
    WritePort_BBSPI (PORTB_ADD, ch);          // write the character to be displayed
    __delay_ms(1);
    WritePort_BBSPI (PORTA_ADD, send_data);   // send data to LCD
    __delay_ms(1);
    WritePort_BBSPI (PORTA_ADD, 0x00);        // stop sending data to LCD
}

void LCDPutStr (const char *ptr){
    while(*ptr) LCDPutChar(*(ptr++));
}