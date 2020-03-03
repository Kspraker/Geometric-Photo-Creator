/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef HEADER
#define HEADER

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

class Header
{
  //Private variables
  private:
    string magicNum;
    int width;
    int height;
    int maxVal;

  //Public Functions
  public:
     //Default constructor using initialization list
     Header() : magicNum("P6"), width(0), height(0), maxVal(255) {}

     //Regular constructor using initialization list
     Header(string m, int w, int h, int max) :
       magicNum(m), width(w), height(h), maxVal(max) {}

    //Getters that return the private variables
    string getNum();
    int getW();
    int getH();
    int getMax();

    //Setters that set the private variables to the parameter passed in
    void setH(int h);
    void setW(int w);
};

#endif
