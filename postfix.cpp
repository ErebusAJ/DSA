#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluatePostfixExpression(const string &expression)
{
    stack<int> operands;

    stringstream ss(expression);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            // If the token is a number, push it onto the stack
            int operand = stoi(token);
            operands.push(operand);
        }
        else
        {
            // If the token is an operator, pop the top two operands and perform the operation
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            char op = token[0];

            switch (op)
            {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            default:
                cerr << "Invalid operator: " << op << endl;
                return -1;
            }
        }
    }

    if (!operands.empty())
    {
        return operands.top();
    }
    else
    {
        cerr << "Invalid expression" << endl;
        return -1;
    }
}

int main()
{
    string expression = "5 3 + 4 * 2 /";
    int result = evaluatePostfixExpression(expression);
    if (result != -1)
    {
        cout << "Result: " << result << endl;
    }
    return 0;
}
