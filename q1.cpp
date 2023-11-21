#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Create the classes here
class Shape
{
public:
    string type;

    void printMyType()
    {
        cout << type;
    }
};

class square : Shape
{
public:
    int s;
    square(int a)
    {
        a = s;
    }

    void calculateArea()
    {
        cout << s * s;
    }

    void printMyType()
    {
        cout << "square";
    }
};

class rectangle : Shape
{
public:
    int l;
    int b;

    void calculateArea()
    {
        cout << l * b;
    }

    void printMyType()
    {
        cout << "rectangle";
    }
};

int main()
{
    square o1(58);
    o1.printMyType();
    o1.calculateArea();

    return 0;
}