#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
using namespace std;

class DosyaIslem{
	private:
		string filePath;
	public:
		DosyaIslem(string); // Constructor
		string GetFirstNumber(); // ilk sayıyı döndüren metod
		string GetSecondNumber(); // ikinci sayıyı döndüren metod
};

#endif