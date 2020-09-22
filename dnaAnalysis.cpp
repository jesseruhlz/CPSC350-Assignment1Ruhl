#include "DNA.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "math.h" // for RAND
#include <iomanip>

using namespace std;

dnaAnalysis::dnaAnalysis()
{
  string fileName;
  while(true)
  {
    //asking user for a .txt file of DNA to analyze
    cout << "Enter file name to analyze: " << endl;
    cin >>fileName;

    string line;
    int numOfLines = 0, charCount = 0;
    char character;
    double mean, variance, standDeviation;


    //this is used to calculate the number of lines within the .txt file
    ifstream myfile (fileName);
      while (getline(myfile, line)){
        ++numOfLines;
      }
    myfile.close();
    //cout << "Number of lines in text file: " << numOfLines << endl;


    //this is used to calclate the sum of chars in the .txt file
    ifstream fin(fileName);
    while (fin >> character) ++charCount;
      myfile.close();


    //finding the mean of the given .txt file
    mean = (double)charCount / (double)numOfLines;


    // finding the variance of the given .txt file
    myfile.open(fileName);
    while (getline(myfile, line))
    {
      variance += pow(( line.size() - mean),2);
    }
    myfile.close();
    variance = variance / numOfLines - 1;


    //finding the standard Deviation of the given .txt file
    standDeviation = sqrt(variance);

    // probability of each nucleotide
    // only four options so it should be 1/4 for each nucleotide
    double nucleotideProb;
    double a = 1.0, b = 4.0, c = 16.0;
    nucleotideProb = a / b;

    // 16 options for bigram therefore there is a 1/16 chance for each
    double bigramProb = a /c;

    // printing out the anlysis of the given .txt file
    cout << "The Sum of the length of the DNA string is: " << charCount << endl;
    cout << "The Mean of the length of the DNA string is: " << mean << endl;
    cout << "The Variance of the length of the DNA string is: " << variance << endl;
    cout << "The Standard Deviation of the length of the DNA string is: " << standDeviation << endl;
    cout << "Here is the relative probability of each nucleotide: " << endl << endl;
    cout << "A:" << setw(10) << nucleotideProb << endl;
    cout << "C:" << setw(10) << nucleotideProb << endl;
    cout << "T:" << setw(10) << nucleotideProb << endl;
    cout << "G:" << setw(10) << nucleotideProb << endl << endl;

    cout << "Here is the relative probability of each nucleotide bigram: " << endl << endl;
    cout << "AA:" << setw(10) << bigramProb << endl;
    cout << "AC:" << setw(10) << bigramProb << endl;
    cout << "AT:" << setw(10) << bigramProb << endl;
    cout << "AG:" << setw(10) << bigramProb << endl;
    cout << "CA:" << setw(10) << bigramProb << endl;
    cout << "CC:" << setw(10) << bigramProb << endl;
    cout << "CT:" << setw(10) << bigramProb << endl;
    cout << "CG:" << setw(10) << bigramProb << endl;
    cout << "TA:" << setw(10) << bigramProb << endl;
    cout << "TC:" << setw(10) << bigramProb << endl;
    cout << "TT:" << setw(10) << bigramProb << endl;
    cout << "TG:" << setw(10) << bigramProb << endl;
    cout << "GA:" << setw(10) << bigramProb << endl;
    cout << "GC:" << setw(10) << bigramProb << endl;
    cout << "GT:" << setw(10) << bigramProb << endl;
    cout << "GG:" << setw(10) << bigramProb << endl << endl;


    //code for generating 1000 DNA strings here
    const int MAX = 8;
    char sequence[MAX] = {'A', 'T', 'C', 'G','a','t','c','g'};
    srand(time(NULL));

    //first using for loop to determine how many lines of DNA strings
    // in this case, hw calls for 1000
    //using 10 temporarily to make sure it is working properly first
    for (int i = 0; i < 1000; i++)
    {
      // using Box-Muller to generate random length of the 1000 strings
      // using variance and mean to correlate with the found data above
      string res = "";
      double u = ((double) rand() / (RAND_MAX));// * 2 - 1;
      double v = ((double) rand() / (RAND_MAX));// * 2 - 1;
      double r = u * u + v * v;
      if (r == 0 || r > 1);
        //double c = sqrt(-2 * log(r) / r);
      int c = sqrt(-2 * log(u)) * cos(2 * M_PI * v);

      // D is the randomly generated length of string
      int D = (standDeviation * c) + mean;

      // using for loop to generate the 1000 strings of DNA
      // could not figure out how to generate random DNA strings w/o not using
      // an array to choose what characters should be in the strings
      for (int j = 0; j < D; j++)
      {
          res = res + sequence[rand() % MAX];
      }
      cout << res << endl;
    }

    // propmt to ask the user if they want to add another .txt file to analyze
    char command;
    cout << "Do you want to process another list (Y/N)? " << endl;
    cin >> command;
    if (command == 'n' || command == 'N')
    {
      break;
    }
  }
  //return 0;
}
