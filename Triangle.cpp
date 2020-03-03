/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Triangle.h"
using namespace std;

//Default constructor & initialization list.
Triangle::Triangle() : x1(0), x2(0), x3(0), y1(0), y2(0), y3(0) {}

//Regular constructor & initialization list.
Triangle::Triangle(int ex1, int ex2, int ex3, int why1, int why2, int why3) :
  x1(ex1), x2(ex2), x3(ex3), y1(why1), y2(why2), y3(why3) {}

//This function takes in a referance to the input file as a parameter.
//The function then reads in the values for the shape.
//Function then sets the color for the current shape passing in r, g, and b.
void Triangle::readInfo(ifstream& refIn)
{
  int r, g, b;

  //Stores in private variables.
  refIn >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;

  //Sets the color of the shape
  c.setColor(r, g, b);
}

//This function accepts a referance to an image.
//Function "draws" the current shape by looping through the image and setting
//the current point's pixel data to the desired color if the point is within
//the area of the shape.
void Triangle::draw(Image& refImage)
{
  int w, h;
  int temp;

  //Gets the height and width from header.
  int row = refImage.getH();
  int col = refImage.getW();

  //Regular constructor for triangle.
  Triangle tri(x1, x2, x3, y1, y2, y3);

  //Creates an empty vector of Points.
  vector <Point> points;

  //Creates points and passes in the private member data.
  Point p1(x1, y1);
  Point p2(x2, y2);
  Point p3(x3, y3);

  //Pushes back those points onto the vector.
  points.push_back(p1);
  points.push_back(p2);
  points.push_back(p3);

  //Sets the private member pts to the passed in vector.
  tri.setPoint(points);

  //Loops through the sizes of the image vector, meant to set colors
  for (h = 0; h < row; h++)
  {
    for (w = 0; w < col; w++)
    {
      //Sets temp equal to the result of the hit function
      Point currPoint(w, h);
      Point& refPoint = currPoint;
      temp = tri.isHit(refPoint);

      //If the point is within the Triangle, sets the pixel to these colors
      if (temp == 1)
      {
        //Sets the r, g, b for the image vector in refImage, passing in the
        //color and the x and y.
        refImage.setR(c.getR(), h, w);
        refImage.setG(c.getG(), h, w);
        refImage.setB(c.getB(), h, w);
      }
    }
  }
}

//Boolian function that accepts a referance to a vector of points as parameter.
//Functin tests the current point with the points of the triangle.
//Determines if the point is withing the area of the Triangle.
//Returns either true or false.
bool Triangle::isHit(Point& test)
{
  //Math to determine if the point is within the area of the triangle.
  //Gets the x and y value of test by using getters.
  double a = ((pts.at(1).getY() - pts.at(2).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(2).getX()
    - pts.at(1).getX()) * (test.getY() -  pts.at(2).getY())) /
    ((pts.at(1).getY() - pts.at(2).getY()) *
    (pts.at(0).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(1).getX()) * (pts.at(0).getY() - pts.at(2).getY()));

  double b = ((pts.at(2).getY() - pts.at(0).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(0).getX()
    - pts.at(2).getX()) * (test.getY() -  pts.at(2).getY())) /
    ((pts.at(1).getY() - pts.at(2).getY()) *
    (pts.at(0).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(1).getX()) * (pts.at(0).getY() - pts.at(2).getY()));

  double c = 1 - a - b;

  //Returns 1 if in the boundaries
  if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
  {
    return 1;
  }

  //Returns 0 if not in the boundaries
  else
  {
    return 0;
  }
}

//Sets the pts private member equal to the passed in point vector.
void Triangle::setPoint(vector <Point> point)
{
  pts = point;
}
