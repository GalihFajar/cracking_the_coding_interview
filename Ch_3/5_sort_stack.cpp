#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s)
{
    stack<int> tempStack;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        while (!tempStack.empty() && tempStack.top() < temp)
        {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    return tempStack;
}

void printStack(stack<int> &s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

int main()
{
    stack<int> s;
    int input = 0;

    while (cin >> input)
        s.push(input);

    stack<int> sorted = sortStack(s);
    printStack(sorted);
}