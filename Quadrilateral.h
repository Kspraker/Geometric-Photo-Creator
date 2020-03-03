/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Shape.h"
using namespace std;

class Quadrilateral : public Shape
{
    private:
      int x1;
      int x2;
      int x3;
      int x4;
      int y1;
      int y2;
      int y3;
      int y4;

    public:
      //Default Constructor
      Quadrilateral();
      //Regular constructor, passing in 8 ints
      Quadrilateral(int, int, int, int, int, int, int, int);
      //Destructor
      virtual ~Quadrilateral(){}
      //Virtual functions from shape
      void readInfo(ifstream&);
      void setPoint(vector <Point>);
      bool isHit(Point&);
      void draw(Image&);
};

#endif
