#include "NumberTwo.hpp"
#include <iostream>
#include <sstream>

ProccessToNumberTwo::ProccessToNumberTwo(string numberTwo)
{
    this->NumberTwo = numberTwo;
    string* ArrayOfNumberTwo;
    int* IntArrayOfNumberTwo;
    this->arrayOfNumberTwo = ArrayOfNumberTwo;
    this->intArrayOfNumberTwo = IntArrayOfNumberTwo;
    this->arrayICount = 0;
}

//yüzler basamagı 1 ile başlayanları kontrol eden metod
void ProccessToNumberTwo::ControlOfNumberTwo()
{
    int numberTwoLength = NumberTwo.length();

    for (int i=0; i<numberTwoLength; i+=3)
    {
        //yüzler basamagı 0 olan varsa 1 ile değiştirdim
        if (NumberTwo[i] == '0')
        {
            NumberTwo[i] = '1';
        }
    }
}

//dinamik olarak ele alınan ikinci sayının oluşturulacak diziye verilecek olan uzunlugunu döndüren metod
int ProccessToNumberTwo::ArrayLength()
{
    return NumberTwo.length()/3;
}

//sayıyı int tipe dönüştürüp 3erli şekilde diziye atan metod
int* ProccessToNumberTwo::ThreesArrayOfNumberTwo()
{
    ControlOfNumberTwo();
    const string numberTwo = NumberTwo; //dizi olusturmak için sayıyı const değişkene atadım
    int numberTwoLength = numberTwo.length(); //sayımın uzunlugunu aldım
    arrayICount = numberTwoLength/3; //her eleman 3 basamaklı olacagı için 3e böldüm
    arrayOfNumberTwo = new string[arrayICount]; //string dizimi olusturdum

    int firstIndex = 0;
    int secondIndex = 3;

    //string elemanları diziye attım
    for (int i = 0; i < arrayICount; i++)
    {
        arrayOfNumberTwo[i] = numberTwo.substr(firstIndex,secondIndex);
        firstIndex+=3;
    }

    /*string dizimin içindeki verileri integer diziye atma işlemlerim*/
    intArrayOfNumberTwo = new int[arrayICount];
    
    int number; 

    //her indexteki değerleri tek tek dolaşıp int türüne çevirip int dizisine attığım döngü
    for (int i = 0; i < arrayICount; i++)
    {
        stringstream geek(arrayOfNumberTwo[i]); //string ddeğeri int türüne dönüştürdüm
        geek>>number; //int değeri number değişkenine attım
        intArrayOfNumberTwo[i] = number; //number değişkenini int dizisine attım
    }
    return intArrayOfNumberTwo;
}

//destructor metodum
ProccessToNumberTwo::~ProccessToNumberTwo(){
    arrayICount = 0;
    delete(arrayOfNumberTwo);
    delete(intArrayOfNumberTwo);
}