#ifndef SOLUTION_LAB03_H
#define	SOLUTION_LAB03_H

#include "setup_basic.h"

#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))

#define PORTA_DIR               0x00        // I/O Direction register of PORTA
#define PORTB_DIR               0x01        // I/O Direction register of PORTB
#define PORTA_ADD               0x12        // address of General Purpose I/O of PORTA
#define PORTB_ADD               0x13        // address of General Purpose I/O of PORTB

// selecting between instruction register or data register
#define instr        0x00
#define data         0x80

// to send instruction or data to LCD
#define send_instr   0x40
#define send_data    0xC0

// Display controller setup commands
#define FUNCTION_SET        0x3C                         // 8 bit interface, 2 lines, 5x8 font
#define ENTRY_MODE          0x06                         // increment mode
#define DISPLAY_SETUP       0x0C                         // display on, cursor off, blink offd

// Command set for LCD display controller
#define LCD_CLEAR           0x01
#define LCD_HOME            0x02
#define LCD_CURSOR_BACK     0x10
#define LCD_CURSOR_FWD      0x14
#define LCD_PAN_LEFT        0x18
#define LCD_PAN_RIGHT       0x1C
#define LCD_CURSOR_OFF      0x0C
#define LCD_CURSOR_ON       0x0E
#define LCD_CURSOR_BLINK    0x0F
#define LCD_CURSOR_LINE1    0x80
#define LCD_CURSOR_LINE2    0xC0

void LCDInit(void);
void InitBBSPI(void);
void Port_BBSPIInit(unsigned char port_dir);
void SendByteBBSPI (unsigned char output);
void WritePort_BBSPI (unsigned char port_add, unsigned char a);
void LCDPutInst (unsigned char ch);

void LCDPutChar (unsigned char ch);
void LCDPutStr (const char *ptr);

#endif

