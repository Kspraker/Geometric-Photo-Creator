/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

/*This program uses c++, multiple files, vectors, inheritance, polymorphism,
virtual functions, and multiple files to read the name, points and color
of shapes defined in a text file and print out the picture it makes.*/

#include <iostream>
#include <fstream>
#include "src/Point.h"
#include "src/Image.h"
#include "src/Color.h"
#include "src/Quadrilateral.h"
#include "src/Triangle.h"
#include "src/Circle.h"
#include "src/Shape.h"
using namespace std;

int main(int argc, char* argv[])
{
  //Opens the input file
  ifstream inFile;
  inFile.open(argv[1]);

  //Validity check for the input file
  if (!inFile.is_open())
  {
    cout << "Can't open the input file " << argv[1] <<endl;
    return -1;
  }

  //Opens the output file
  ofstream outFile;
  outFile.open(argv[2]);

  //Validity check for the output file
  if (!outFile.is_open())
  {
    cout << "Can't open the out file " << argv[2] << endl;
    return -1;
  }

  //Creating referance variables for the output and input file pointers
  ifstream& refIn = inFile;
  ofstream& refOut = outFile;

  //Creating an instance of the image class, passing in the referance to the
  //text file, this creates and sets all the varibles for image
  Image image(refIn);
  //Creating a referance variable for the image variable
  Image& refImage = image;

  //Creating a vector of shape pointers
  vector <Shape*> shapeVec;

  int i = 0;
  string shapeName;

  //Loops while the input file can still store another string, i.e. the name
  //of a shape.
  while (inFile >> shapeName)
  {
    if (shapeName == "Circle")
    {
      //Pushes back memory for an instance of the shape.
      shapeVec.push_back(new Circle());

      //Sets the name of the shape.
      shapeVec.at(i)->setName(shapeName);
    }

    if (shapeName == "Triangle")
    {
      //Pushes back memory for an instance of the shape.
      shapeVec.push_back(new Triangle());

      //Sets the name of the shape.
      shapeVec.at(i)->setName(shapeName);
    }

    if (shapeName == "Quadrilateral")
    {
      //Pushes back memory for an instance of the shape.
      shapeVec.push_back(new Quadrilateral());

      //Sets the name of the shape.
      shapeVec.at(i)->setName(shapeName);
    }

    //Calls the readInfo function for the current shape
    shapeVec.at(i)->readInfo(refIn);
    //Calls the draw function for the current shape
    shapeVec.at(i)->draw(refImage);
    //increments i
    i++;
  }

  //Prints the image
  image.print(refOut);

  //Closes the files
  inFile.close();
  outFile.close();

  return 0;
}
