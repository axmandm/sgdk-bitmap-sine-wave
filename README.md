Draws sine and cosine waves on screen, using the line drawing techniques from https://github.com/axmandm/sgdk-bitmap-line

There are some small additions to the code, to prevent flickiering of the lines/pixels drawn:

`BMP_setBufferCopy(TRUE); // if we do not do this, the bitmap pixels and lines will flicker when drawing`

This needs to be used in conjuction with:

`BMP_flip(FALSE);`

If BMP_flip(TRUE), then BMP_setBufferCopy(TRUE) has no effect.
