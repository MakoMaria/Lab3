#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::addToStart(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::removeFromStart() {
    if (isEmpty()) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}
