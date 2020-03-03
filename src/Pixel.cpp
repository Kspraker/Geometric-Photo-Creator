/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Pixel.h"

//Gets the current value of r and returns it, has no parameters
//Returns value of r.
unsigned char Pixel::getR()
{
  return r;
}

//Gets the current value of g and returns it, has no parameters
//Returns value of g.
unsigned char Pixel::getG()
{
  return g;
}

//Gets the current value of b and returns it, has no parameters
//Returns value of b.
unsigned char Pixel::getB()
{
  return b;
}

//Sets the value of r to whatever unsigned char is passed in
void Pixel::setR(double are)
{
  r = are;
}

//Sets the value of b to whatever unsigned char is passed in
void Pixel::setB(double be)
{
  b = be;
}

//Sets the value of g to whatever unsigned char is passed in
void Pixel::setG(double gee)
{
  g = gee;
}
