/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef SHAPE
#define SHAPE

#include <iostream>
#include <fstream>
#include <string>
#include "Color.h"
#include "Point.h"
#include "Image.h"
using namespace std;

class Shape
{
    //protected means derived classes have direct access to the data members
    protected:
        Color c;
        string name;
        vector <Point> pts;

    public:
        Shape();
        virtual void readInfo(ifstream&) = 0;
        virtual void setPoint(vector <Point>) = 0;
        virtual bool isHit(Point&) = 0;
        virtual void draw(Image&) = 0;
        virtual ~Shape(){}
        vector <Point> getPoints()const;
        void setName(string);
        string getName() const;
};

#endif
