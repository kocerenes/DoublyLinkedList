#include "Iterator.hpp"

Iterator::Iterator()
{
    this->current = NULL;
}

Iterator::Iterator(Node *node)
{
    this->current = node;
}

bool Iterator::IsEndNode()
{
    return current == NULL;
}

//liste üzerinde bir adım ilerleyen metod
void Iterator::StepNext()
{
    if (!IsEndNode())
        current = current->next;
}

//liste üzerinde bir adım geri giden metod
void Iterator::StepBack()
{
    if (!IsEndNode())
        current = current->prev;
}

//üzerinde bulundugumuz düğümün datasını getiren metod
int &Iterator::GetCurrentData() const
{
    return current->data;
}