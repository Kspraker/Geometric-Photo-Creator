/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Shape.h"
#include <math.h>
using namespace std;

class Triangle : public Shape
{
    private:
      int x1;
      int x2;
      int x3;
      int y1;
      int y2;
      int y3;

    public:
      //Default constructor
      Triangle();
      //Regular constructor
      Triangle(int, int, int, int, int, int);
      //Virtual functions from shape
      void readInfo(ifstream&);
      void setPoint(vector <Point>);
      bool isHit(Point&);
      void draw(Image&);
      //deconstructor
      virtual ~Triangle(){}
};

#endif
