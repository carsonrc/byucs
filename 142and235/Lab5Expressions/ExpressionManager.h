//
// Created by carso on 7/19/2021.
//

#ifndef LAB5EXPRESSIONS_EXPRESSIONMANAGER_H
#define LAB5EXPRESSIONS_EXPRESSIONMANAGER_H

#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <utility>
#include <bits/stdc++.h>
#include <iosfwd>

#include "ExpressionManagerInterface.h"

std::map<char, int> opPrecedence = { {'(', 0},
                                {'+', 1},
                                {'-', 1},
                                {'*', 2},
                                {'/', 2},
                                {'%', 2} };

class ExpressionManager : public ExpressionManagerInterface
{
private:
    string expression;
public:
    explicit ExpressionManager(string expression) {this->expression = std::move(expression);}
    ~ExpressionManager() override = default;

    void setExpression(string expression) {this->expression = std::move(expression);}
    string getExpression() {return this->expression;}

    /** Return the integer value of the infix expression */
    int value() override
    {
        return 0;
    };

    /** Return the infix items from the expression
        Throw an error if not a valid infix expression as follows:
        First check to see if the expression is balanced ("Unbalanced"),
        then throw the appropriate error immediately when an error is found
        (ie., "Missing Operand", "Illegal Operator", "Missing Operator") */
    std::string infix() override
    {
        std::istringstream holder(expression);
        string data;
        string whole;
        int numOperands = 0;
        int numOperators = 0;

        do
        {
            holder >> data;
            if (data == "@")
            {
                throw string("Illegal Operator \n");
            }
            if (data == "+" || data == "-" || data == "*" || data == "/" || data == "%")
            {
                numOperators++;
            }
            if (is_number(data))
            {
                numOperands++;
            }
            whole = whole + " " + data;
        } while (holder);

        if (numOperators > numOperands)
        {
            throw string("Missing Operand \n");
        }

        for (int i = 0; i < data.size(); i++)
        {
            whole.pop_back();
        }

        return whole;
    };

    /** Return a postfix representation of the infix expression */
    std::string postfix() override
    {
        return "";
    };

    /** Return a prefix representation of the infix expression */
    std::string prefix() override
    {
        return "";
    };

    /** Return the infix vector'd expression items */
    std::string toString() const override
    {
        return "";
    };
    bool is_number(const std::string& s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
};
#endif //LAB5EXPRESSIONS_EXPRESSIONMANAGER_H
