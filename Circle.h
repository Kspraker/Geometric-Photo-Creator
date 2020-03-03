/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Shape.h"
using namespace std;

class Circle:public Shape
{
    private:
      double centerX;
      double centerY;
      double radius;

    public:
      //Default constructor
      Circle();
      //Regular constructor
      Circle(double, double, double);
      //Deconstructor
      virtual ~Circle(){}
      //virtual functions
      void readInfo(ifstream&);
      void setPoint(vector <Point>);
      bool isHit(Point&);
      void draw(Image&);

};

#endif
