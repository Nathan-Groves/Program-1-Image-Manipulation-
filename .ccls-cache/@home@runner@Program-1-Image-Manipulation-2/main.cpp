/*
Nathan Groves, Jayden Fleisher
1/23/21
This program reads in the RGB values from an input file
and inverts the values by subtracting the initial values from
255 using a function (the max value possible)
*/

#include <iostream>
#include <fstream>
using namespace std;

//function prototype to perform the mathematics operation
int calcNum (int x);

//struct to hold all the RGB values
struct imageValues 
{
int R;
int G;
int B;
};

int main() 
{

  //variables to hold ppm file type, width, height, max value, and
  // array of structs 
  string ppmfile;
  int pictureWidth, pictureHeight, maxValue;
  imageValues picture[256][256];


  ifstream infile;
  ofstream outfile;
  infile.open("bot.dat");
  outfile.open("output.txt");

// read in the initial data and print it to the output file
infile >> ppmfile >> pictureWidth >> pictureHeight >> maxValue;
outfile << ppmfile << endl << pictureWidth << " " << pictureHeight << endl << maxValue << endl;

//so long as the input file has not been fully read through,
// continue the loop
while (!infile.eof())
{
  //nested for loop to read in the data and subtract the initial 
  //RGB value from 255 using a function in order to invert 
  //the colors
  for (int i = 0; i <256; i++)
  {
    for (int j = 0; j < 256; j++)
    {
    infile >> picture[i][j].R >> picture[i][j].G >> picture[i][j].B;

    outfile << calcNum(picture[i][j].R) << " " << calcNum(picture[i][j].G) << " " <<  calcNum(picture[i][j].B) << " ";

    }
  //create break line to provide for better formatting
    outfile << endl;
  }
}

infile.close();
outfile.close();
return 0;
  
} 

//take in a variable and subtract it from 255, then 
//return that number
int calcNum (int x)
{
return 255 - x;
}