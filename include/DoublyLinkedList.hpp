#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <Iterator.hpp>
using namespace std;

class DoublyLinkedList
{
private:
    Node* head;
    int size;
public:
    DoublyLinkedList();
    friend class ComparisonLists;
    Iterator IterateFromPrevIndex(int)const;
    Iterator IterateFromFirstNode()const;
    Node* node();
    bool IsEmpty()const;
    int Count() const;
    void Add(const int&);
    void Insert(int, const int&);
    void ArrayToList(int,int*,DoublyLinkedList*);
    void AllReversed(DoublyLinkedList*);
    void RemoveAt(int);
    void PrintAll();
    void PrintAllFromIndexReversed(int);
    void PrintAllReversed();
    void Clear();
    ~DoublyLinkedList(); //Destructor
};
#endif