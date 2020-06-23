#include <genesis.h>
#include <bmp.h>

int main()
{

  //Initialise the bitmap engine
  BMP_init(FALSE, BG_A, PAL0, FALSE);
  BMP_setBufferCopy(TRUE); // if we do not do this, the bitmap pixels and lines will flicker when drawing

  //Set the colour of the line. We are using pallete 0 for the bitmap, so we have 0->15. 15 is used for white text, so we set an unused pallet colour, 14 to blue - RGB 0000FF. We also want a red line, so we set 12 to red - RGB FF0000. We may as well set green as well :)
  u16 colour_red = RGB24_TO_VDPCOLOR(0xff0000);
  u16 colour_green = RGB24_TO_VDPCOLOR(0x00ff00);
  u16 colour_blue = RGB24_TO_VDPCOLOR(0x0000ff);
  VDP_setPaletteColor(12, colour_red);
  VDP_setPaletteColor(13, colour_green);
  VDP_setPaletteColor(14, colour_blue);

  //When we are working in bitmap mode, we must left shift the colours, or we get gaps in pixels drawn
  int pal_red = 12;
  pal_red |= pal_red << 4;

  int pal_green = 13;
  pal_green |= pal_green << 4;

  int pal_blue = 14;
  pal_blue |= pal_blue << 4;

  //Draw the vertical axis
  Line a;
  a.pt1.x = 0;
  a.pt1.y = 0;
  a.pt2.x = 0;
  a.pt2.y = 160;
  a.col = pal_blue;

  //Draw the horizontal axis
  Line b;
  b.pt1.x = 0;
  b.pt1.y = 80;
  b.pt2.x = 255;
  b.pt2.y = 80;
  b.col = pal_blue;

  while(TRUE)
  {

      //Draw the graph axes
      BMP_drawLine(&a);
      BMP_drawLine(&b);

      //The loop to draw the sine wave
      int i;
      for (i = 1; i < 255; i ++)
      {
        BMP_setPixel(i, 80 + sinFix16(i*8), pal_red);

        //We may as well draw cosine while we are here :)
        BMP_setPixel(i, 80 + cosFix16(i*8), pal_green);

        BMP_flip(FALSE);
      }

  }
  return 0;
}
