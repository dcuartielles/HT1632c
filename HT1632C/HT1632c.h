#ifndef __HT1632C_h__
#define __HT1632C_h__

/*
 * HT1632C.h
 * defintions for Holtek ht1632 LED driver.
 */


#if !defined(DEBUGPRINT)
#define DEBUGPRINT(fmt, args...)
#endif

#include <Arduino.h>
#include <avr/pgmspace.h>

/*
 * commands written to the chip consist of a 3 bit "ID", followed by
 * either 9 bits of "Command code" or 7 bits of address + 4 bits of data.
 */
#define HT1632_ID_CMD 4		/* ID = 100 - Commands */
#define HT1632_ID_RD  6		/* ID = 110 - Read RAM */
#define HT1632_ID_WR  5		/* ID = 101 - Write RAM */
#define HT1632_ID_BITS (1<<2)   /* IDs are 3 bits */

#define HT1632_CMD_SYSDIS 0x00	/* CMD= 0000-0000-x Turn off oscil */
#define HT1632_CMD_SYSON  0x01	/* CMD= 0000-0001-x Enable system oscil */
#define HT1632_CMD_LEDOFF 0x02	/* CMD= 0000-0010-x LED duty cycle gen off */
#define HT1632_CMD_LEDON  0x03	/* CMD= 0000-0011-x LEDs ON */
#define HT1632_CMD_BLOFF  0x08	/* CMD= 0000-1000-x Blink ON */
#define HT1632_CMD_BLON   0x09	/* CMD= 0000-1001-x Blink Off */
#define HT1632_CMD_SLVMD  0x10	/* CMD= 0001-00xx-x Slave Mode */
#define HT1632_CMD_MSTMD  0x14	/* CMD= 0001-01xx-x Master Mode */
#define HT1632_CMD_RCCLK  0x18	/* CMD= 0001-10xx-x Use on-chip clock */
#define HT1632_CMD_EXTCLK 0x1C	/* CMD= 0001-11xx-x Use external clock */
#define HT1632_CMD_COMS00 0x20	/* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_COMS01 0x24	/* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_COMS10 0x28	/* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_COMS11 0x2C	/* CMD= 0010-ABxx-x commons options */
#define HT1632_CMD_PWM    0xA0	/* CMD= 101x-PPPP-x PWM duty cycle */
#define HT1632_CMD_BITS (1<<7)

//#define Number_of_Displays 2
//#define CHIP_MAX 4*Number_of_Displays //Four HT1632Cs on one board
//#define X_MAX 32*Number_of_Displays
//#define Y_MAX 16

#define CLK_DELAY


// possible values for a pixel;
//RANDOMCOLOR for each line a different color
//MULTICOLOR for each point a different random color
#define BLACK  0
#define GREEN  1
#define RED    2
#define ORANGE 3
#define RANDOMCOLOR 4 // only for scrolling functions
#define MULTICOLOR 5

// insert here the number of columns of your font files 
// the compiler will comment how large the number of columns
// should be
#define NCOLUMNS 8

#define LONGDELAY 1000  // This delay BETWEEN demos

#define plot(x,y,v)  ht1632_plot(x,y,v)
//#define cls          ht1632_clear
#define clearScreen  ht1632_clear

//**************************************************************************************************
//Function Name: calcBit
//Function Feature: calculate the bitval of y
//Input Argument: y: Y coordinate
//Output Argument: bitval
//**************************************************************************************************
#define calcBit(y) (8>>(y&3))

/*
 *  Class definition
 */
class HT1632c {

  public:
      // constructor
      HT1632c(bool debug = false);
      HT1632c(int da, int wr, int cs, int cl, bool debug = false);
      HT1632c(int a, int da, int wr, int cs, int cl, bool debug = false);

      /*
       * Set these variable to the values of the pins connected to the SureElectronics Module
       */
      byte ht1632_data;  // Data pin 
      byte ht1632_wrclk; // Write clock pin 
      byte ht1632_cs;    // Chip Select 
      byte ht1632_clk;   // clock pin 

      /*
       * how many displays, chips and max size?
       */
      byte Number_of_Displays;
      byte CHIP_MAX; // 4*Number_of_Displays, Four HT1632Cs on one board
      byte X_MAX; // 32*Number_of_Displays
      byte Y_MAX; // 16

      // original functions
      void OutputCLK_Pulse(void); //Output a clock pulse
      void OutputA_74164(unsigned char x); //Input a digital level to 74164
      void ChipSelect(int select);
      void ht1632_writebits (byte bits, byte firstbit);
      void ht1632_sendcmd (byte chipNo, byte command);
      void ht1632_senddata (byte chipNo, byte address, byte data);
      void ht1632_setup();
      byte xyToIndex(byte x, byte y);
      int get_pixel(byte x, byte y);
      void ht1632_plot (int x, int y, byte color);
      void ht1632_clear();
      void ht1632_putchar(int x, int y, char c, byte color=GREEN);
      void ht1632_putcharsizecolor(int x, int y,unsigned char c,  char size, byte color, byte secondcolor, unsigned char fontname[][NCOLUMNS],  int columncountfont, char rowcountfont, char oddeven);
      void ht1632_putcharsize1D(int x, int y,unsigned char c,  char size, byte color,  byte secondcolor,unsigned char * fontname,  char columncountfont, char rowcountfont, char oddeven);
      void ht1632_putbigbitmap(int x, int y, byte color, byte secondcolor,  unsigned char * bitmapname, int columncountbitmap, byte rowcountbitmap, char oddeven);
      void scrollbitmapxcolor(int y, byte color, byte secondcolor,unsigned char * bitmapname,int columncountbitmap, byte rowcountbitmap,char oddeven,int delaytime);
      void scrollbitmapycolor(int x,byte color, byte secondcolor,unsigned char * bitmapname ,int columncountbitmap, byte rowcountbitmap,char oddeven, int delaytime);
      void scrolltextxcolor(int y,char Str1[ ], byte color, int delaytime);  
      void scrolltextsizexcolor(int y,char Str1[ ], char size, byte color, byte secondcolor,  unsigned char fontname[][NCOLUMNS], int columncountfont, char rowcountfont, char oddeven, int delaytime);
       void scrolltextsizey(int x,char Str1[ ], char size, byte color, byte secondcolor, unsigned char fontname[][NCOLUMNS], int columncountfont, char rowcountfont, char oddeven, int delaytime);
      void scrolltextsize1Dxcolor(int y, char Str1[ ], char size,  byte color, byte secondcolor, unsigned char * fontname,   int columncountfont, char rowcountfont, char oddeven, int delaytime);

      // Arduino styled functions on top of the original code
      void setup();
      void cls();
      void putChar(char c, int x, int y, byte color=GREEN);
      void text(char str[], int x, int y, int color = ORANGE);
      void text(int num, int x, int y, int color = GREEN);
      void image(unsigned char * bitmapName, int x, int y, int width, int height, byte color = GREEN, byte secondColor = BLACK, char oddEven = 'G');

    private:
      // shall we print out debug information?
      bool debug;

      int numdigits(int n);
      int extractDigit(int number, int place);
};

#endif

