/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Color.h"

//Default constructor, uses initialization list.
Color::Color() : shapeR(0), shapeG(0), shapeB(0) {}

//Regular constructor, uses initialization list, passes in r, g, b.
Color::Color(unsigned char are, unsigned char gee, unsigned char be) :
  shapeR(are), shapeG(gee), shapeB(be){}

//Function accepts the r, g, and b values as a parameter.
//Function sets the private variables color for the shape to the passed in
//colors.
void Color::setColor(int are, int gee, int be)
{
  shapeR = are;
  shapeG = gee;
  shapeB = be;
}

//Gets the value for r from the color private member. Returns R.
unsigned char Color::getR()
{
  return shapeR;
}

//Gets the value for g from the color private member. Returns G.
unsigned char Color::getG()
{
  return shapeG;
}

//Gets the value for b from the color private member. Returns B.
unsigned char  Color::getB()
{
  return shapeB;
}
