#include <bits/stdc++.h>
using namespace std;

class MyQueue
{

public:
    stack<int> s1;
    stack<int> s2;

    void pushQ(int x)
    {
        if (s1.empty())
        {
            s1.push(x);
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(x);

            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    void popQ()
    {
        s1.pop();
    }

    void printQ()
    {
        stack<int> s1_copy = s1;
        while (!s1_copy.empty())
        {
            cout << s1_copy.top() << endl;
            s1_copy.pop();
        }
    }
};

int main()
{
    MyQueue *q = new MyQueue();
    q->pushQ(1);
    q->pushQ(2);
    q->pushQ(3);
    q->pushQ(4);
    q->pushQ(5);
    q->pushQ(6);

    q->popQ();

    q->printQ();
}