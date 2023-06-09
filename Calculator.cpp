#include "Stack.h"
#include <iostream>

class Calculator {
private:
    bool isOperator(char c);
    int performOperation(char operation, int operand1, int operand2);

public:
    int evaluate(const std::string& expression);
};

int Calculator::evaluate(const std::string& expression) {
    Stack stack;

    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (isOperator(c)) {
            if (stack.isEmpty()) {
                std::cout << "Invalid expression!" << std::endl;
                return 0;
            }

            int operand2 = stack.pop();

            if (stack.isEmpty()) {
                std::cout << "Invalid expression!" << std::endl;
                return 0;
            }

            int operand1 = stack.pop();

            if (c == '/' && operand2 == 0) {
                std::cout << "Invalid expression! Division by zero." << std::endl;
                return 0;
            }

            int result = performOperation(c, operand1, operand2);
            stack.push(result);
        }
    }

    if (stack.isEmpty()) {
        std::cout << "Invalid expression!" << std::endl;
        return 0;
    }

    return stack.pop();
}

bool Calculator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int Calculator::performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            std::cout << "Invalid operation!" << std::endl;
            return 0;
    }
}
