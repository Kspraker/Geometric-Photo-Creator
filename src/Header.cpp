/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Header.h"

//Gets the current magic Number and returns it, has no parameters
string Header::getNum()
{
  return magicNum;
}

//Gets the current width and returns it, has no parameters
int Header::getW()
{
  return width;
}

//Gets the current height and returns it, has no parameters
int Header::getH()
{
  return height;
}

//Gets the current max value and returns it, has no parameters
int Header::getMax()
{
  return maxVal;
}

//Sets the current height equal to whatever integer parameter is passed in
void Header::setH(int h)
{
  height = h;
}

//Sets the current width equal to whatever integer parameter is passed in
void Header::setW(int w)
{
  width = w;
}
