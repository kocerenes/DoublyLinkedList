#ifndef NUMBERONE_HPP
#define NUMBERONE_HPP

#include <iostream>
using namespace std;

class ProccessToNumberOne{
	private:
		string NumberOne;
		string* arrayOfNumberOne;
		int* intArrayOfNumberOne;
		int arrayICount;
	public:
		ProccessToNumberOne(string);
		void ControlOfNumberOne(); //sayilarin yüzler basasmağini kontrol eden metod
		int ArrayLength(); // dizilerin uzunlugunu dinamik olarak getiren metod
        int* ThreesArrayOfNumberOne(); //sayıları üçerli int diziye atan metod
		~ProccessToNumberOne(); //Destructor
};
#endif