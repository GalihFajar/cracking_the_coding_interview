#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<pair<int, int>> s;
    MinStack()
    {
    }

    void pop()
    {
        s.pop();
    }

    void push(int x)
    {
        if (s.empty())
        {
            s.push(make_pair(x, x));
        }
        else
        {
            s.push(make_pair(x, min(x, s.top().second)));
        }
    }

    int getMin()
    {
        return s.top().second;
    }
};

int main()
{
    MinStack *stack = new MinStack();
    stack->push(10);
    stack->push(1);
    stack->push(-1);
    stack->push(3);
    cout << stack->getMin() << endl;
}