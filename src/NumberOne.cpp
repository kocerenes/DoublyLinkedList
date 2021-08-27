#include "NumberOne.hpp"
#include <iostream>
#include <sstream>

ProccessToNumberOne::ProccessToNumberOne(string numberOne){
    this->NumberOne = numberOne;
    string* ArrayOfNumberOne;
    int* IntArrayOfNumberOne;
    this->arrayOfNumberOne = ArrayOfNumberOne;
    this->intArrayOfNumberOne = IntArrayOfNumberOne;
    this->arrayICount = 0;
}

//yüzler basamagı 1 ile başlayanları kontrol eden metod
void ProccessToNumberOne::ControlOfNumberOne()
{
    int numberOneLength = NumberOne.length(); //sayımın uzunlugunu aldım

    //birinci sayımın yüzler basamagını döngüye aldım
    for (int i=0; i<numberOneLength; i+=3)
    {
        //yüzler basamagı 0 olan varsa 1 ile değiştirdim
        if (NumberOne[i] == '0')
        {
            NumberOne[i] = '1';
        }
    }   
}

//dinamik olarak ele alınan ilk sayının oluşturulacak diziye verilecek olan uzunlugunu döndüren metod
int ProccessToNumberOne::ArrayLength()
{
    return NumberOne.length()/3;
}

//sayıyı int tipe dönüştürüp 3erli şekilde diziye atan metod
int* ProccessToNumberOne::ThreesArrayOfNumberOne()
{
    ControlOfNumberOne(); //önce sayıların yüzler basamagini kontrol ettirdik
    const string numberOne = NumberOne; //dizi olusturmak için sayıyı const değişkene atadım
    int numberOneLength = numberOne.length(); //sayımın uzunlugunu aldım
    arrayICount = numberOneLength/3; //her eleman 3 basamaklı olacagı için 3e böldüm
    arrayOfNumberOne = new string[arrayICount]; //string dizimi olusturdum
    
    int firstIndex = 0;
    int secondIndex = 3;

    //string elemanları diziye attım
    for (int i = 0; i < arrayICount; i++)
    {
        arrayOfNumberOne[i] = numberOne.substr(firstIndex,secondIndex); // 3'erli ayırdım
        firstIndex+=3;
    }

    /*string dizimin içindeki verileri integer diziye atma işlemlerim*/
    intArrayOfNumberOne = new int[arrayICount];
    
    int number; 

    //her indexteki değerleri tek tek dolaşıp int türüne çevirip int dizisine attığım döngü
    for (int i = 0; i < arrayICount; i++)
    {
        stringstream geek(arrayOfNumberOne[i]); //string ddeğeri int türüne dönüştürdüm
        geek>>number; //int değeri number değişkenine attım
        intArrayOfNumberOne[i] = number; //number değişkenini int dizisine attım
    }
    
    return intArrayOfNumberOne;
}

//destructor metodum
ProccessToNumberOne::~ProccessToNumberOne(){
    arrayICount = 0;
    delete(arrayOfNumberOne);
    delete(intArrayOfNumberOne);
}

