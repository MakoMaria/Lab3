#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {

public:
    LinkedList();
    ~LinkedList();

    void addToStart(int value);
    void removeFromStart();
    void printList() const;
    bool isEmpty() const;

    Node* head;
};

#endif
