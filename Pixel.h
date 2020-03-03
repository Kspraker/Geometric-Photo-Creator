/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef PIXEL
#define PIXEL

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

//Represents an RGB pixel with integer values between 0 and 255
class Pixel
{
  //Private variables
  private:
    unsigned char r;
    unsigned char g;
    unsigned char b;

  //Public variables
  public:
    //Default Constructor using an initialization list
    Pixel() : r(255), g(255), b(255) {}

    //Regular Constructor using an initialization list
     Pixel(unsigned char are, unsigned char gee, unsigned char be) :
       r(are), g(gee), b(be) {}

    //Getters that return the private variables
    unsigned char getR();
    unsigned char getB();
    unsigned char getG();

    //Setters that set the private variables equal to the paramter passed in
    void setR(double are);
    void setG(double gee);
    void setB(double be);
};

#endif
