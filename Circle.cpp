/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Circle.h"
#include <math.h>
using namespace std;

//Default Constructor with initialization list
Circle::Circle() : centerX(0), centerY(0), radius(0) {}

//Regular Constructor with initialization list
Circle::Circle(double x, double y, double rad) : centerX(x), centerY(y),
  radius(rad) {}

//This function takes in a referance to the input file as a parameter.
//The function then reads in the values for the shape.
//Function then sets the color for the current shape passing in r, g, and b.
void Circle::readInfo(ifstream& refIn)
{
  int red, green, blue;

  //Stores values into private variables.
  refIn >> centerX >> centerY >> radius >> red >> green >> blue;

  //Sets the color for this shape passing in the specified values.
  c.setColor(red, green, blue);
}

//This function accepts a referance to an image.
//Function "draws" the current shape by looping through the image and setting
//the current point's pixel data to the desired color if the point is within
//the area of the shape.
void Circle::draw(Image& refImage)
{
  int w, h, temp;

  //Gets and stores height and width using getters.
  int row = refImage.getH();
  int col = refImage.getW();

  //Creates a blank vector of points.
  vector <Point> points;

  //Creates a point variable passing in the center point for circle.
  Point point(centerX, centerY);

  //Pushes back that point onto the point vector.
  points.push_back(point);

  //Passing in values using the regular constructor for the circle class.
  Circle cir(centerX, centerY, radius);

  //Sets the pts for this shape by passing in the point vector.
  cir.setPoint(points);

  //Loops through the sizes of the image vector, meant to set colors
  for (h = 0; h < row; h++)
  {
    for (w = 0; w < col; w++)
    {
      //Creates a point variable for the current x and y.
      Point currPoint(w, h);

      //Creates a referance for the current point.
      Point& refPoint = currPoint;

      //Sets temp equal to the result of the hit function, passing in a
      //referance to the current point.
      temp = cir.isHit(refPoint);

      //If the hit function returns true, sets value to specified color.
      //If not true, keeps the color defined in the pixel default constructor.
      if (temp == 1)
      {
        //Uses setters in the image class to set the r, g, and b values of the
        //2D vector in image, passing in a getter for the color and the
        //current x and y coordinate.
        refImage.setR(c.getR(), h, w);
        refImage.setG(c.getG(), h, w);
        refImage.setB(c.getB(), h, w);
      }
    }
  }
}

//Boolian function that accepts a referance to a vector of points as parameter.
//Functin tests the current point with the center point and radius.
//Determines if the point is withing the area of the circle.
//Returns either true or false.
bool Circle::isHit(Point& refPoint)
{
  double squareX, squareY, total, value;

  //Calculation for x squared.
  squareX = pow((refPoint.getX() - pts.at(0).getX()), 2);

  //Calculation for y squared.
  squareY = pow((refPoint.getY() - pts.at(0).getY()), 2);

  //Adds for total.
  total = squareX + squareY;

  //Value is the square root of the total.
  value = sqrt(total);

  //Returns true if the value is less than the radius.
  if (value < radius)
  {
    return true;
  }

  //Returns false if the value is greater than the radius.
  else
  {
    return false;
  }
}

//Sets the pts private member equal to the passed in point vector.
void Circle::setPoint(vector <Point> point)
{
  pts = point;
}
