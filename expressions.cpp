#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to get precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

// Function to evaluate the string expression
int expression(string expression)
{
    stack<int> values; // Stack to store values
    stack<char> ops;   // Stack to store operators

    for (int i = 0; i < expression.size(); ++i)
    {
        if (isspace(expression[i]))
            continue; // Skip spaces

        // If it's a digit, form the complete number
        if (isdigit(expression[i]))
        {
            int value = 0;
            while (i < expression.size() && isdigit(expression[i]))
            {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            values.push(value);
            i--; // Adjust index because the loop will increment it
        }
        // If it's an opening parenthesis, push to ops stack
        else if (expression[i] == '(')
        {
            ops.push(expression[i]);
        }
        // If it's a closing parenthesis, solve the entire expression inside the parentheses
        else if (expression[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop(); // Pop the '('
        }
        // If it's an operator, apply the operators with higher or equal precedence first
        else if (isOperator(expression[i]))
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i]))
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(expression[i]);
        }
    }

    // Apply remaining operators to remaining values
    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    // The result will be the only value left in the stack
    return values.top();
}

void solver(vector<string> &result, string num, string curr, int i, int target)
{
    if (i >= num.size())
    {
        int val = expression(curr);
        if (target == val)
            result.push_back(curr);
        return;
    }

    curr.push_back(num[i]);
    if (i + 1 != num.size())
        curr.push_back('+');
    solver(result, num, curr, i + 1, target);
    curr.pop_back();
    curr.pop_back();

    // if(i + 1 != num.size())
    curr.push_back('-');
    curr.push_back(num[i]);
    solver(result, num, curr, i + 1, target);
    curr.pop_back();
    curr.pop_back();

    // if(i + 1 != num.size())
    curr.push_back('*');
    curr.push_back(num[i]);
    solver(result, num, curr, i + 1, target);
    //	curr.pop_back();
}

vector<string> addOperator(string num, int target)
{
    vector<string> result;
    solver(result, num, "", 0, target);
    return result;
}

int main()
{
    string s = "123", s2 = "232", s3 = "3456237490";
    vector<string> result;
    result = addOperator(s, 6);

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    result = addOperator(s2, 8);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    result = addOperator(s3, 9191);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}
