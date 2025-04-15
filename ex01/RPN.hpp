#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <exception>


class RPN
{
    public:
    static bool is_operator(const std::string& s);
    static int perform_operation(int a, int b, const std::string& op);
    static int evaluate(const std::string& expression);

    class InvalidOperatorException : public std::exception {
        public:
            virtual const char* what() const throw(){
                return "Error: Invalid operator.";
            }
    };

    class InvalidTokenException : public std::exception {
        public:
            virtual const char* what() const throw(){
                return "Error: Invalid token (must be a number or operator).";
            }
    };

    class DivisionByZeroException : public std::exception {
        public:
            virtual const char* what() const throw(){
                return "Error: Division by zero.";
            }
    };

    class InvalidExpressionException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Error: Invalid expression.";
            }
    };
};
