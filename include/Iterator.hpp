#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <Node.hpp>

class Iterator{
    private:
        Node* current;
	public:
		Iterator();
		Iterator(Node*);
		bool IsEndNode();
		void StepNext();
		void StepBack();
		int& GetCurrentData()const;
        friend class DoublyLinkedList;
};
#endif