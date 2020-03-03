/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef COLOR
#define COLOR

#include <iostream>
#include <fstream>

using namespace std;
class Color
{
  private:
    unsigned char shapeR;
    unsigned char shapeG;
    unsigned char shapeB;

  public:
    //Setter for color, accepts r, g, b values.
    void setColor(int are, int gee, int be);
    //Regular constructor
    Color(unsigned char are, unsigned char gee, unsigned char be);
    //Default constructor
    Color ();
    //Getters for values
    unsigned char getR();
    unsigned char getG();
    unsigned char getB();



};

#endif
