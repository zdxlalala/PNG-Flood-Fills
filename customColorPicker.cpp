#include "customColorPicker.h"

customColorPicker::customColorPicker(HSLAPixel fillColor, PNG & img, double tolerance, HSLAPixel center)
{
/* Your code here! */
    color = fillColor;
    im = img;
    tol = tolerance;
    ctr = center;

    for(int i = 0; i<10 ; i++){
        for (int j = 0; j<10; j++){
            colorData[i][j] = 0;
        }
    }

    for(int i = 3; i<7; i++){
        colorData[i][4] = 1;
        colorData[i][5] = 1;
    }

    for(int i = 3; i<7; i++){
        colorData[4][i] = 1;
        colorData[5][i] = 1;
    }
}

HSLAPixel customColorPicker::operator()(int x, int y)
{

/* Your code here! */
    int height = (int)im.height();
    int width = (int)im.width();
    HSLAPixel* pixel = im.getPixel(x,y);
    HSLAPixel yellow;
    yellow.s = 1;
    yellow.l = 0.5;
    yellow.h = 60;

    int currX = x%10;
    int currY = y%10;
    if(pixel->dist(ctr) <= tol)
        if(colorData[currX][currY]==0)
            return color;
        else
            return yellow;
    
    return *pixel;
}