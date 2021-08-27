#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

class Node{
    private:
        int data;
		Node* next;
		Node* prev;
	public:
        Node();
		Node(const int&, Node*, Node*);
        friend class Iterator; //Node sınıfındaki private alanları Iterator sınıfında kullanabilmek için friend sınıf olarak tanımladım.
        friend class DoublyLinkedList; //Node sınıfındaki private alanları DoublyLinkedList sınıfında kullanabilmek için friend sınıf olarak tanımladım.
        friend class ComparisonList; //Node sınıfındaki private alanları ComparisonList sınıfında kullanabilmek için friend sınıf olarak tanımladım.
};

#endif