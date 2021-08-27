#include "ComparisonLists.hpp"

ComparisonList::ComparisonList()
{
    DosyaIslem file("doc/Sayilar.txt"); //hangi dosyamın okunacağını belirttim

    //İLK SAYI İÇİN İŞLEMLER
    ProccessToNumberOne proccessToNumberOne(file.GetFirstNumber()); // ilk sayımın işlemlerini yapmamı sağlayacak nesnemi oluşturdum
    this->indexcount = proccessToNumberOne.ArrayLength(); //ilk sayımın 3'erli hali için dizi uzunlugunu değişkene attım
    this->numberone = new int[indexcount]; //ilk sayımı üçerli olucak şekilde dinamik alacak dizimi tanımladım
    numberone = proccessToNumberOne.ThreesArrayOfNumberOne(); //dizime sayıları attım

    //İKİNCİ SAYI İÇİN İŞLEMLER
    ProccessToNumberTwo proccessToNumberTwo(file.GetSecondNumber());
    this->indexcount2 = proccessToNumberTwo.ArrayLength();
    this->numbertwo = new int[indexcount2];
    numbertwo = proccessToNumberTwo.ThreesArrayOfNumberTwo();

    this->firstList = new DoublyLinkedList(); //yeni liste olusturdum
    this->secondList = new DoublyLinkedList(); 
    
    firstList->ArrayToList(indexcount,numberone,firstList); //listeye dizi içindeki elemanları ekleyecek olan metodu cagırdım
    secondList->ArrayToList(indexcount2,numbertwo,secondList);

}

// iki farklı listenin karşılıklı düğümlerini değiştirmek için yazdıgım metod
void ComparisonList::ReplaceWithNode(Node* firNode,Node* secNode){

    Node* tempNext; //swap işlemim için yardımcı bir düğüm 

    //listenin son elemanıysa swap işlemlerini ona göre şekillendirdim
    if (firNode->next == 0 || secNode->next == 0)
    {
        //düğümlerin nextini ve nextinin previni değiştirme işlemlerim
        tempNext = firNode->next;
        firNode->next = secNode->next;
        secNode->next = tempNext;
        
        //düğümlerin previni ve previnin nextini değiştirme işlemlerim
        tempNext = firNode->prev;
        firNode->prev = secNode->prev;
        secNode->prev=tempNext;
        tempNext->next = secNode;
        firNode->prev->next = firNode;
    }
    else{
        //düğümlerin nextini ve nextinin previni değiştirme işlemlerim
        tempNext = firNode->next;
        firNode->next = secNode->next;
        firNode->next->prev = firNode;
        secNode->next = tempNext;
        tempNext->prev = secNode;
        
        //düğümlerin previni ve previnin nextini değiştirme işlemlerim
        tempNext = firNode->prev;
        firNode->prev = secNode->prev;
        secNode->prev=tempNext;
        tempNext->next = secNode;
        firNode->prev->next = firNode;
    }  
}

//Karsılıklı iki düğümü karşılastırmak için yazdıgım metod
void ComparisonList::ComparisonProccess(Node *firstListNode,Node *secondListNode)
{
    firstListNode = firstList->node(); //ilk parametreye ilk listemin head pointerını verdim
    secondListNode = secondList->node(); //ikinci parametreye ikinci listemin head pointerını verdim

    //düğümlerin listenin sonuna gidene kadar döngünün içinde kalmasını sağladım
    while(firstListNode->next!=NULL && secondListNode->next!=NULL)
    {
        if(firstListNode->next->data > secondListNode->next->data)
        {
            //firstList->AllReversed(firstList);
        }
        else if(firstListNode->next->data == secondListNode->next->data)
        {
            //secondList->AllReversed(secondList);
        }
        else if(firstListNode->next->data < secondListNode->next->data)
        {
            ReplaceWithNode(firstListNode->next,secondListNode->next); //iki düğümün adreslerini değiştiren metodu cagırdım
        }

        firstListNode=firstListNode->next; //düğümleri bir ilerlettim
        secondListNode=secondListNode->next;
    }

    cout<<"Sayi1 : ";
    firstList->PrintAll(); //ilk listem için son halini ekrana yazdıran metodu kullandım
    cout<<"Sayi2 : ";
    secondList->PrintAll(); //ikinci listem için son halini ekrana yazdıran metodu kullandım
}

ComparisonList::~ComparisonList(){
    indexcount = 0;
    indexcount2 = 0;
    delete(numberone);
    delete(numbertwo);
    delete(firstList);
    delete(secondList);
}