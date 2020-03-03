/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#ifndef POINT
#define POINT


//Creating a class called Point
class Point
{
  private:
    //Data Member
    double x;
    double y;

  public:
    //Setters
    void setX (double);
    void setY (double);
    //Getters
    double getX();
    double getY();
    //Default Constructor
    Point();
    //Regular Constructor
    Point(double, double);
    ~Point();
};

#endif
