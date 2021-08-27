#ifndef NUMBERTWO_HPP
#define NUMBERTWO_HPP

#include <iostream>
using namespace std;

class ProccessToNumberTwo
{
    private:
        string NumberTwo;
        string* arrayOfNumberTwo;
		int* intArrayOfNumberTwo;
		int arrayICount;
    public:
        ProccessToNumberTwo(string);
        void ControlOfNumberTwo();
        int ArrayLength();
        int* ThreesArrayOfNumberTwo();
        ~ProccessToNumberTwo(); //Destructor
};

#endif