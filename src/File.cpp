#include "File.hpp"
#include <fstream>

DosyaIslem::DosyaIslem(string filepath){
    this->filePath = filepath;
}

// # işaretinden önceki sayıyı getiren metod
string DosyaIslem::GetFirstNumber(){
    ifstream file;
    file.open (filePath);
    string numberOne;
    char x;
    
    x = file.get();

    // # işaretini görene kadar okutup sayi1 değişkenime attım
    while ( x != '#' )
    {
        numberOne = numberOne + x;
        x = file.get();
    }
    return numberOne; // numberone'i döndürdüm
}

// # işaretinden sonraki sayıyı getiren metod
string DosyaIslem::GetSecondNumber(){
    ifstream file;
    file.open (filePath);
    string numberTwo;
    char x;
    
    x = file.get();

    //kare işaretini görene kadar okuttum
    while ( x != '#' )
    {
        x = file.get();
    }

    x = file.get(); //kare işaretini x değişkenime attım

    //dosyanın sonuna kadar okuyan döngü
    while (!file.eof())
    {
        //kare işaretini görünce sayi2 değişkenime eklemeden atlamasını sağladım
        if (x=='#')
        {
            continue;
        }
        
        numberTwo = numberTwo + x;
        x = file.get();
    }
    return numberTwo;
}
