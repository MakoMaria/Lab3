#ifndef INFIXCALCULATOR_H
#define INFIXCALCULATOR_H

#include <string>
#include "Calculator.h"
#include "Stack.h"
#include "Queue.h"

class InfixCalculator {
private:
    bool isOperator(char c);
    int getPrecedence(char c);
    std::string convertToPostfix(const std::string& infixExpression);

public:
    int evaluate(const std::string& infixExpression);
};

#endif
