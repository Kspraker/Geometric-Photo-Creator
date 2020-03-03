/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Shape.h"
using namespace std;

//Default constructor for the shape base class.
Shape::Shape()
{
  //Sets the private member c equal to the a defaulted color variable.
  Color color;
  c = color;

  //Sets name to blank.
  name = "blank";

  //Creates a blank vector of points. Sets the pts private member to that
  //vector.
  vector <Point> blank;
  pts = blank;
}

//Accepts no paramters and returns the pts private member.
vector <Point> Shape::getPoints() const
{
  return pts;
}

//Function accepts a string variable and sets the name equal to the parameter.
void Shape::setName(string n)
{
  name = n;
}

//Function accepts no parameter and returns the private member name.
string Shape::getName() const
{
 return name;
}
