/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Point.h"

//Function that accepts an x value as a parameter. Sets the private member
//equal to the passed in value.
void Point::setX(double ex)
{
  x = ex;
}

//Function that accepts an y value as a parameter. Sets the private member
//equal to the passed in value.
void Point::setY(double why)
{
  y = why;
}

//Function has no parameters. Returns the value of x.
double Point::getX()
{
  return x;
}

//Function has no parameters. Returns the value of y.
double Point::getY()
{
  return y;
}

//Default Constructor
Point::Point()
{
  x = 0;
  y = 0;
}

//Regular Constructor
Point::Point(double ex, double why)
{
  x = ex;
  y = why;
}
//Deconstructor
Point::~Point()
{
}
