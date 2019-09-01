#include "stripeColorPicker.h"

stripeColorPicker::stripeColorPicker(HSLAPixel fillColor, int stripeSpacing)
{
/* your code here! */
    color = fillColor;
    spacing = stripeSpacing;
}

HSLAPixel stripeColorPicker::operator()(int x, int y)
{
/* your code here! */
    HSLAPixel white;
    white.h = 0;
    white.s = 0;
    white.l = 1;
    if (x % spacing == 0){
        return color;
    }
    return white;
}
