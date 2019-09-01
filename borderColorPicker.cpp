#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{
/* Your code here! */
    color = fillColor;
    im = img;
    tol = tolerance;
    ctr = center;
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{

/* Your code here! */
    int height = (int)im.height();
    int width = (int)im.width();
    HSLAPixel* pixel = im.getPixel(x,y);
    if((x+3) > width-1 || im.getPixel(x+3,y)->dist(ctr) > tol)
        return color;
    if((x-3) < 0 || im.getPixel(x-3,y)->dist(ctr) > tol)
        return color;
    if((y+3) > height-1 || im.getPixel(x,y+3)->dist(ctr) > tol)
        return color;
    if((y-3) < 0 || im.getPixel(x,y-3)->dist(ctr) > tol)
        return color;
    for(int i = x-2; i < x+3; i++){
        for(int j = y-2; j < y+3; j++){
            
                if((i < 0) || (j < 0) || (i > width-1) || (j > height-1) || (im.getPixel(i,j)->dist(ctr) > tol))
                    return color;
            
        }
    }
    return *pixel;
}
