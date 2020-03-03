/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include "Quadrilateral.h"
using namespace std;

//Default constructor, uses initialization list
Quadrilateral::Quadrilateral() : x1(0), x2(0), x3(0), x4(0), y1(0), y2(0),
  y3(0), y4(0) {}

//Regular constructor, uses initialization list, passes in 8 variables
Quadrilateral::Quadrilateral (int x1, int y1, int x2, int y2, int  x3, int  y3,
  int  x4, int  y4) : x1(x1), x2(x2), x3(x3), x4(x4), y1(y1), y2(y2), y3(y3),
  y4(y4) {}

//Function that accepts a referance to the input file as a parameter.
//This function stores the points into the private members of the current
//shape and stores the color values into the private members of color.
void Quadrilateral::readInfo(ifstream& refIn)
{
  int r, g, b;

  //Getting and storing the values/information from the input file.
  refIn >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> r >> g >> b;

  //Using a setter for the color, passing in the r, g, and b value.
  c.setColor(r, g, b);
}

//This function accepts a referance to an image.
//Function "draws" the current shape by looping through the image and setting
//the current point's pixel data to the desired color if the point is within
//the area of the shape.
void Quadrilateral::draw(Image& refImage)
{
  int w, h, temp;

  //Gets and stores height and width using getters.
  int row = refImage.getH();
  int col = refImage.getW();

  //Passing in values using the regular constructor for the quad class.
  Quadrilateral quad(x1,y1, x2, y2, x3, y3, x4, y4);

  //Creates an empty vector.
  vector <Point> points;

  //Creats a point for each point in the shape, passing in the x and y values.
  Point p1(x1, y1);
  Point p2(x2, y2);
  Point p3(x3, y3);
  Point p4(x4, y4);

  //Pushes those points onto the back of the point vector.
  points.push_back(p1);
  points.push_back(p2);
  points.push_back(p3);
  points.push_back(p4);

  //Sets the pts private member by passing in that vector of points.
  quad.setPoint(points);

  //Loops through the sizes of the image vector, meant to set colors
  for (h = 0; h < row; h++)
  {
    for (w = 0; w < col; w++)
    {
      //Creates a point for the current x and y.
      Point currPoint(w, h);

      //Creates a referance to the current point
      Point& refPoint = currPoint;

      //Sets the temp variable equal to the result of this shapes hit function
      temp = quad.isHit(refPoint);

      //If the point is within the Quadrilateral, sets the pixel here
      //to the color defined in the text document for this particular shape.
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
//Functin tests 4 different triangles in order to adequetly test if the
//current point is within the area of the quadrilateral.
//Returns either true or false.
bool Quadrilateral::isHit(Point& test)
{
  //This is the formula to determine if the point is within a triangle.
  //Uses getters to get the values of the x and y coordinates at whatever
  //point is specified in the vector.
  double a = ((pts.at(1).getY() - pts.at(2).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(2).getX() - pts.at(1).getX()) * (test.getY() -
    pts.at(2).getY())) / ((pts.at(1).getY() - pts.at(2).getY()) *
    (pts.at(0).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(1).getX()) * (pts.at(0).getY() - pts.at(2).getY()));

  double b = ((pts.at(2).getY() - pts.at(0).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(0).getX() - pts.at(2).getX()) * (test.getY() -
    pts.at(2).getY())) / ((pts.at(1).getY() - pts.at(2).getY()) *
    (pts.at(0).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(1).getX()) * (pts.at(0).getY() - pts.at(2).getY()));

  double c = 1 - a - b;

  //This formula for determining if the point is within a different triangle
  double d = ((pts.at(3).getY() - pts.at(2).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(2).getX() - pts.at(3).getX()) * (test.getY() -
    pts.at(2).getY())) / ((pts.at(3).getY() - pts.at(2).getY()) *
    (pts.at(0).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(3).getX()) * (pts.at(0).getY() - pts.at(2).getY()));

  double e = ((pts.at(2).getY() - pts.at(0).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(0).getX() - pts.at(2).getX()) * (test.getY() -
    pts.at(2).getY())) / ((pts.at(3).getY() - pts.at(2).getY()) *
    (pts.at(0).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(3).getX()) * (pts.at(0).getY() - pts.at(2).getY()));

  double f = 1 - d - e;

  //Same as above but for a 3rd triangle
  double g = ((pts.at(1).getY() - pts.at(2).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(2).getX() - pts.at(1).getX()) * (test.getY() -
    pts.at(2).getY())) / ((pts.at(1).getY() - pts.at(2).getY()) *
    (pts.at(3).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(1).getX()) * (pts.at(3).getY() - pts.at(2).getY()));

  double h = ((pts.at(2).getY() - pts.at(3).getY()) * (test.getX() -
    pts.at(2).getX()) + (pts.at(3).getX() - pts.at(2).getX()) * (test.getY() -
    pts.at(2).getY())) / ((pts.at(1).getY() - pts.at(2).getY()) *
    (pts.at(3).getX() - pts.at(2).getX()) + (pts.at(2).getX() -
    pts.at(1).getX()) * (pts.at(3).getY() - pts.at(2).getY()));

  double i = 1 - g - h;

  //Same as above but for a final triangle
  double j = ((pts.at(1).getY() - pts.at(3).getY()) * (test.getX() -
    pts.at(3).getX()) + (pts.at(3).getX() - pts.at(1).getX()) * (test.getY() -
    pts.at(3).getY())) / ((pts.at(1).getY() - pts.at(3).getY()) *
    (pts.at(0).getX() - pts.at(3).getX()) + (pts.at(3).getX() -
    pts.at(1).getX()) * (pts.at(0).getY() - pts.at(3).getY()));


  double k = ((pts.at(3).getY() - pts.at(0).getY()) * (test.getX() -
    pts.at(3).getX()) + (pts.at(0).getX() - pts.at(3).getX()) * (test.getY() -
    pts.at(3).getY())) / ((pts.at(1).getY() - pts.at(3).getY()) *
    (pts.at(0).getX() - pts.at(3).getX()) + (pts.at(3).getX() -
    pts.at(1).getX()) * (pts.at(0).getY() - pts.at(3).getY()));

  double l = 1 - j - k;

  //Returns 1 if in the boundaries of the first triangle
  if (a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
  {
    return 1;
  }

  //Returns 1 if in the boundaries of the second triangle
  else if(d >= 0 && d <= 1 && e >= 0 && e <= 1 && f >= 0 && f <= 1)
  {
    return 1;
  }

  //Returns 1 if in the boundaries of the third triangle
  else if(g >= 0 && g <= 1 && h >= 0 && h <= 1 && i >= 0 && i <= 1)
  {
    return 1;
  }

  //Returns 1 if in the boundaries of the final triangle, thus covering the
  //whole area of the quadrilateral.
  else if(j >= 0 && j <= 1 && k >= 0 && k <= 1 && l >= 0 && l <= 1)
  {
    return 1;
  }

  //Returns 0 if none of the above are true, meaning the current point is not
  //within the quadrilateral.
  else
  {
    return 0;
  }
}

//Function to set the private member pts to the vector of points for the shape
void Quadrilateral::setPoint(vector <Point> point)
{
  pts = point;
}
