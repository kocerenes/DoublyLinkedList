#ifndef COMPARISONLISTS_HPP
#define COMPARISONLISTS_HPP

#include "File.hpp"
#include "NumberOne.hpp"
#include "NumberTwo.hpp"
#include "Node.hpp"
#include "Iterator.hpp"
#include "DoublyLinkedList.hpp"

using namespace std;

class ComparisonList{
    private:
        DoublyLinkedList *firstList;
        DoublyLinkedList *secondList;

        int indexcount;
        int* numberone;
        int indexcount2;
        int* numbertwo;

    public:
        ComparisonList();
        void ReplaceWithNode(Node*,Node*); //iki karşılıklı düğümü değiştirmeye yarayan metodun imzası
        void ComparisonProccess(Node*,Node*); //iki karşılıklı düğümü karşılaştırmaya yarayan metodun imzası
        ~ComparisonList(); //Destructor
};
#endif