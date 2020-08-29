#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    bool mark = false;
    vector<Node *> children;

    Node(int value)
    {
        this->value = value;
    }
};

class Graph
{
public:
    vector<Node *> nodes;
};

void printBFSHelper(Node *node)
{
    queue<Node *> q;
    node->mark = true;
    q.push(node);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        printf("%d\n", temp->value);

        for (auto x : temp->children)
        {
            if (x->mark == false)
            {
                x->mark = true;
                q.push(x);
            }
        }
    }
}

bool printBFSHelper(Node *nodeA, Node *nodeB)
{
    queue<Node *> q;
    nodeA->mark = true;
    q.push(nodeA);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        for (auto x : temp->children)
        {
            if (x == nodeB)
                return true;
            if (x->mark == false)
            {
                x->mark = true;
                q.push(x);
            }
        }
    }
    return false;
}

void printBFS(Graph *graph)
{

    for (auto x : graph->nodes)
    {
        if (x->mark == false)
        {
            printBFSHelper(x);
        }
    }

    for (auto x : graph->nodes)
    {
        x->mark = false;
    }
}

int main()
{

    Graph *g = new Graph();
    Node *n0 = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    (g->nodes).push_back(n0);
    (g->nodes).push_back(n1);
    (g->nodes).push_back(n2);
    (g->nodes).push_back(n3);
    (g->nodes).push_back(n4);
    (g->nodes).push_back(n5);
    (g->nodes).push_back(n6);

    n0->children.push_back(n1);
    n1->children.push_back(n2);
    n2->children.push_back(n0);
    n2->children.push_back(n3);
    n3->children.push_back(n2);

    n4->children.push_back(n5);
    n5->children.push_back(n6);
    n6->children.push_back(n4);

    cout << printBFSHelper(n5, n4) << endl;

    // printBFS(g);
    // printBFS(g);

    return 0;
}