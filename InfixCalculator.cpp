#include "InfixCalculator.h"
#include <iostream>

int InfixCalculator::evaluate(const std::string& infixExpression) {
    Calculator calculator;
    std::string postfixExpression = convertToPostfix(infixExpression);
    return calculator.evaluate(postfixExpression);
}

bool InfixCalculator::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int InfixCalculator::getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

std::string InfixCalculator::convertToPostfix(const std::string& infixExpression) {
    std::string postfixExpression;
    Stack stack;

    for (char c : infixExpression) {
        if (isdigit(c)) {
            postfixExpression += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfixExpression += stack.pop();
            }

            if (!stack.isEmpty() && stack.top() == '(') {
                stack.pop();
            } else {
                std::cout << "Invalid expression!" << std::endl;
                return "";
            }
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && getPrecedence(c) <= getPrecedence(stack.top())) {
                postfixExpression += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        if (stack.top() == '(') {
            std::cout << "Invalid expression!" << std::endl;
            return "";
        }
        postfixExpression += stack.pop();
    }

    return postfixExpression;
}
