#include <bits/stdc++.h>
using namespace std;

class SetOfStacks
{
public:
    int limit;
    vector<stack<pair<int, int>>> v;
    SetOfStacks(int limit = 5)
    {

        this->limit = limit;
    }

    void pushPlate(int x)
    {
        stack<pair<int, int>> s;
        if (v.empty() || v.back().top().second >= this->limit)
        {
            s.push(make_pair(x, 1));
            v.push_back(s);
        }
        else
        {

            v.back().push(make_pair(x, v.back().top().second + 1));
        }
    }

    int topPlate()
    {
        return v.back().top().first;
    }

    int numberOfStacks()
    {
        return v.size();
    }

    void printStack(stack<pair<int, int>> s)
    {
        while (!s.empty())
        {
            cout << s.top().first << " " << s.top().second << endl;
            s.pop();
        }
    }

    void printAllStacks()
    {
        for (auto x : v)
        {
            this->printStack(x);
            cout << endl;
        }
    }

    void popPlate()
    {
        v.back().pop();
    }

    void popAt(int index)
    {
        //First stack of plates at index 0
        v[index].pop();
    }
};

int main()
{

    int stackLimit = 0;
    int input;
    cin >> stackLimit;
    SetOfStacks *s = new SetOfStacks(stackLimit);
    while (cin >> input)
    {
        s->pushPlate(input);
    }

    // cout << s->topPlate() << endl;
    s->printAllStacks();
    printf("Number of stacks : %d", s->numberOfStacks());
}