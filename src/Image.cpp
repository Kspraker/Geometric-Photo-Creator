/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include <iostream>
#include <fstream>
#include "Image.h"
using namespace std;

//Default constructor for the Image class. Sets header equal to the Default
//constructor for header, and image equal to a blank 2D vector. Contains no
//parameters.
Image::Image()
{
  //Sets header equal to the default constructor of the Header class
  header = Header();

  //Creating an empty and blank 2D vector of type Pixel
  vector< vector<Pixel> > blank;

  //Setting image equal to this blank vector
  image = blank;
}

//This function is the regular constructor for Image. It calls the regular
//constructor for the header and sets the image's private member, header, equal
//to that regular constructor. This function also creates and sizes a 2D
//vector, and sets the image equal to it. The only parameter for this function
//is the referance for the input.
Image::Image(ifstream& in)
{
  string magic;
  int w, h, max;

  //Obtains and stores the header information
  in >> magic >> w >> h >> max;

  //Calls the regular constructor and passes in the header info
  Header header(magic, w, h, max);

  //Sets the private member header equal to the header variable just created
  this->header = header;

  //Creates an empty 2D vector of type Pixel
  vector< vector<Pixel> > vec2D;

  //Sizes the vector for the number of rows and columns
  vec2D.resize(h, vector<Pixel>(w));
  image = vec2D;
}

//This function prints the image. It first prints the header, then loops
//through the vector, which contains the pixels, and prints them out to the
//output file. The only parameter in this fuction is the referance to the
//output file.
void Image::print(ofstream& outFile)
{
  //Prints the header for the image by using the get function in the Header
  //class
  outFile << this->header.getNum() << " " << this->header.getW() << " " <<
    this->header.getH() << " " << this->header.getMax() << endl;

  //Loops through the vector
  for (int i = 0; i < this->header.getH(); i++)
  {
    for (int j = 0; j < this->header.getW(); j++)
    {
      //Prints the current r, g, and b values in the vector to the outfile
      //using the get functions in the Pixel class
       outFile << image[i][j].getR() << image[i][j].getG() <<
         image[i][j].getB();
    }
  }
}

//Function has no parameters. Returns the height of the header.
int Image::getH()
{
  //Calls the get function for height.
  return header.getH();
}

//Function has no parameters. Returns the width of the header.
int Image::getW()
{
  //Calls the get function for width.
  return header.getW();
}

//Function accepts a color, x, and y as it's parameter.
//Function then sets the current red ppixel of the private image vector at
//x and y to the color passed in.
void Image::setR(unsigned int are, int h, int w)
{
  //Calls the setR function passing in the color.
  image.at(h).at(w).setR(are);
}

//Function accepts a color, x, and y as it's parameter.
//Function then sets the current green pixel of the private image vector at
//x and y to the color passed in.
void Image::setG(unsigned int gee, int h, int w)
{
  //Calls the setG function passing in the color.
  image.at(h).at(w).setG(gee);
}

//Function accepts a color, x, and y as it's parameter.
//Function then sets the current blue pixel of the private image vector at
//x and y to the color passed in.
void Image::setB(unsigned int be, int h, int w)
{
  //Calls the setB function passing in the color.
  image.at(h).at(w).setB(be);
}
