#include "RPN.hpp"

bool RPN::is_operator(const std::string& s)
{
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int RPN::perform_operation(int a, int b, const std::string& op) 
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/") {
        if (b == 0) {
            throw DivisionByZeroException();
        }
        return a / b;
    }
    throw InvalidOperatorException();
}


int RPN::evaluate(const std::string& expression)
{
    std::stringstream ss(expression); 
    std::string token;
    std::stack<int> stack;

    while (ss >> token)
    {
        if (is_operator(token))
        {
            if (stack.size() < 2) {
                throw InvalidExpressionException();
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            int result = perform_operation(a, b, token);
            stack.push(result);
        }
        else
        {
            if (token.size() != 1 || !std::isdigit(token[0])) {
                throw InvalidTokenException();
            }
            int num = token[0] - '0';
            stack.push(num);
        }
    }
    if (stack.size() != 1) {
        throw InvalidExpressionException();
    }

    return stack.top();
}
