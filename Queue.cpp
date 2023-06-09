#include "Queue.h"
#include <iostream>

void Queue::enqueue(int value) {
    list.addToStart(value);
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return 0;
    }

    Node* current = list.head;
    Node* prev = nullptr;
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    int frontValue = current->data;
    if (prev != nullptr) {
        prev->next = nullptr;
    } else {
        list.head = nullptr;
    }

    delete current;
    return frontValue;
}

int Queue::front() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return 0;
    }

    Node* current = list.head;
    while (current->next != nullptr) {
        current = current->next;
    }

    return current->data;
}

bool Queue::isEmpty() {
    return list.isEmpty();
}
