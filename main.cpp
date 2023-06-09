#include <iostream>
#include "InfixCalculator.h"

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infixExpression);

    InfixCalculator infixCalculator;
    int result = infixCalculator.evaluate(infixExpression);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
