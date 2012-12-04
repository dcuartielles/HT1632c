#include "images.h"
#include <avr/pgmspace.h>

/***********************************************************************
 * Demo Bitmap data 
 * replace it with your own data
 *
 ***********************************************************************
 * How to make bitmaps for the matrix
 * 1. Gimp
 *  Either import or draw your bitmap.
 *  For using the bitmaps with the matrix, you have to rotate it clockwise 90°.
 *  Save it as X-Bitmap, don't check the X10 option.
 *  Then open the xbm file, add PROGMEM before or after the bitmap name(=bitmap name+"_bits[]"), call the bitmap by with its name.
 *
 *  2. The Dot Factory (http://www.pavius.net/downloads/tools/53-the-dot-factory)
 *  This a good windows software for using fonts but bitmaps, too.
 *  For using bitmaps/fonts select the tool icon, check "Flip X", "90°" at Flip/Rotate. "Width" at Fixed, "MsbFirst" if it wasn't.
 *  You can import any bitmap.
 *  Push Generate, replace the "const uint_8" " with "unsigned char PROGMEM" and call the bitmap by with its name.
 ***********************************************************************/

#define Arduino_logo_width 16
#define Arduino_logo_height 32

unsigned char PROGMEM Arduino_logo[] = {
   0xc0, 0x07, 0xf0, 0x1f, 0xf8, 0x3f, 0x3c, 0x78, 0x1e, 0x70, 0x0e, 0xe0,
   0x8e, 0xe1, 0x0e, 0xe1, 0x86, 0xe1, 0x0e, 0xe1, 0x0e, 0xe1, 0x1e, 0x70,
   0x1c, 0x78, 0x7c, 0x3c, 0xf8, 0x1e, 0xe0, 0x0f, 0xe0, 0x0f, 0xf0, 0x1f,
   0x78, 0x3e, 0x3c, 0x78, 0x1c, 0x70, 0x0e, 0x70, 0x8e, 0xe1, 0x8e, 0xe5,
   0xc6, 0xe7, 0x8e, 0xe1, 0x0e, 0xe1, 0x1e, 0x70, 0x1c, 0x78, 0xfc, 0x3c,
   0xf8, 0x3f, 0xe0, 0x0f };
