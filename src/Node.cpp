#include "Node.hpp"

Node::Node(){
    this->data=0;
	this->next=NULL;
	this->prev=NULL;
}

Node::Node(const int& data = int(), Node* next = NULL, Node* prev = NULL)
{
    this->data=data;
	this->next=next;
	this->prev=prev;
}