/*******************
*Kaleb Spraker
*CPSC 1020 001, F18
*ksprake@clemson.edu
********************/

#include <iostream>
#include <fstream>
#include "Header.h"
#include "Pixel.h"
using namespace std;

#ifndef IMAGE
#define IMAGE


//This class relates to both the pixels and header as a whole
class Image
{
  //Private variables
  private:
    Header header;
    vector< vector<Pixel> > image;

  //Public Functions
  public:
    //Default constructor for the image, has no parameters
    Image();

    //Regular constructor for the image, passes in the referance to the input
    Image(ifstream& in);

    //Function that prints out the image, passes in the referance to the
    //output file
    void print(ofstream& out);

    //Function to read in the pixels for the image, passes in the referance to
    //the input file
    void readPixels(ifstream& in);

    //Getters for the height and width.
    int getH();
    int getW();

    //Setters for the pixel values.
    void setR(unsigned int are, int h, int w);
    void setG(unsigned int gee, int h, int w);
    void setB(unsigned int be, int h, int w);
};

#endif
