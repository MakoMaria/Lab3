#include "Stack.h"
#include <iostream>

void Stack::push(int value) {
    list.addToStart(value);
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return 0;
    }

    int topValue = list.head->data;
    list.removeFromStart();
    return topValue;
}

int Stack::top() {
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return 0;
    }

    return list.head->data;
}

bool Stack::isEmpty() {
    return list.isEmpty();
}
