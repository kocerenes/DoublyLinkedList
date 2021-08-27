#include "DoublyLinkedList.hpp"
using namespace std;

//Constructor
DoublyLinkedList::DoublyLinkedList()
{
    this->head = new Node();
    this->size = 0;
}

Iterator DoublyLinkedList::IterateFromPrevIndex(int index) const
{
    if (!(index < 0 || index > Count()))
    {
        int i = 0;
        Iterator itr(head);
        while (!itr.IsEndNode() && index != i++)
            itr.StepNext();
        return itr;
    }
    return NULL;
}

//ilk düğümü döndürür
Iterator DoublyLinkedList::IterateFromFirstNode() const
{
    if (!IsEmpty())
        return Iterator(head->next);
    return NULL;
}

//head'i döndürür
Node* DoublyLinkedList::node()
{
    return head; 
}

//headin nexti nullsa listenin boş oldugunu döndürür
bool DoublyLinkedList::IsEmpty() const
{
    return head->next == NULL;
}

//liste boyutunu döndüren metod
int DoublyLinkedList::Count() const
{
    return size;
}

//Listenin sonuna eleman ekleyen metod
void DoublyLinkedList::Add(const int &obj)
{
    Insert(Count(), obj);
}

//belirttiğimiz indexe eleman ekleyen metod
void DoublyLinkedList::Insert(int index, const int &obj)
{
    Iterator itr;
    itr = IterateFromPrevIndex(index);
    Node *newNext = itr.current->next;
    itr.current->next = new Node(obj, newNext, itr.current);
    if (newNext != NULL){
        newNext->prev = itr.current->next;
    }
    size++;
}

// parametre olarak yolladıgım int türündeki diziyi doublylinkedListe in sonuna ekleyen metod
void DoublyLinkedList::ArrayToList(int aSize,int *array,DoublyLinkedList *doubly){
    for (int i=0;i<aSize; i++)
    {
        doubly->Add(array[i]);
    }
}

//listeyi tersine çeviren metodum
void DoublyLinkedList::AllReversed(DoublyLinkedList* list){

    Node* temp = NULL;
    Node* current = list->head; //listemin head düğümünü currenta verdim

    //current NULL olana kadar döngüye soktum
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL){
        list->head = temp->prev;
    }
    
}

void DoublyLinkedList::RemoveAt(int index)
{
    Iterator itr;
    itr = IterateFromPrevIndex(index);
    if (itr.current->next != NULL)
    {
        Node *oldNode = itr.current->next;
        itr.current->next = itr.current->next->next;
        if (oldNode->next != NULL)
            oldNode->next->prev = oldNode->prev;
        delete oldNode;
        size--;
    }
}

//liste içindeki sayıların tamamını yazdırmak için metod
void DoublyLinkedList::PrintAll(){
    //itr yi headden başlatıp birer düğüm ilerleten döngüye aldım
    for (Iterator itr = node(); itr.current != NULL; itr.StepNext())
    {
        //varsayılan olarak kontroller sonucu 0 gelen değer olursa 0'ı yazdırmayan kontrolü yaptım
        if(itr.GetCurrentData() == 0){
            continue;
        }
        cout<<itr.GetCurrentData(); //iteratorun üzerinde oldugu düğümün datasını yazdırdım
    }
    cout<<endl;
}

//verdiğim indexe kadar olan sayıları tersten yazdıran metod
void DoublyLinkedList::PrintAllFromIndexReversed(int index)
{
    for (Iterator itr = IterateFromPrevIndex(index + 1); itr.current != head; itr.StepBack())
        cout << itr.GetCurrentData() << " ";
    cout<<endl;
}

//listenin tamamını tersten yazdıran metod
void DoublyLinkedList::PrintAllReversed()
{
    PrintAllFromIndexReversed(size - 1);
}

//listenin içini boşaltan metod
void DoublyLinkedList::Clear()
{
    while (!IsEmpty())
    {
        RemoveAt(0);
    }
}

//listeden kalan tüm çöpleri temizleyen yıkıcı metod
DoublyLinkedList::~DoublyLinkedList()
{
    Clear();
    delete head;
}