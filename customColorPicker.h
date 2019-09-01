#ifndef CUSTOMCOLORPICKER_H
#define CUSTOMCOLORPICKER_H

#include "colorPicker.h"

class customColorPicker : public colorPicker
{
  public:
    /**
     * Constructs a new customColorPicker.
     *
     * @param fillColor Color for the border .
     * @param tolerance used to determine the border of the fill.
     * @param center the color used to determine whether or not a point is within
     *          the fill region. 
     */

    customColorPicker(HSLAPixel fillColor,PNG & img, double tolerance, HSLAPixel center);

    /**
     * Picks the color for pixel (x, y). If the x or y coordinate is 
     * near the border of the fill, or the border of the image, 
     * the fillColor will be returned.
     * Otherwise, the current color of (x,y) will be returned.
     *
     * @param x The x coordinate to pick a color for.
     * @param y The y coordinat to pick a color for.
     * @return The color chosen for (x, y).
     */
    virtual HSLAPixel operator()(int x, int y);

  private:
    HSLAPixel color; /**< Color used for the grid border. */
    PNG im;
    double tol;
    HSLAPixel ctr;
    int colorData[10][10];
};
#endif