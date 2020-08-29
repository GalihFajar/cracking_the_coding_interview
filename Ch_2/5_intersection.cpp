#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
};

Node *intersection(Node *nodeA, Node *nodeB)
{

    unordered_map<Node *, bool> m;

    while (nodeA != NULL)
    {
        m[nodeA] = true;
        nodeA = nodeA->next;
    }

    while (nodeB != NULL)
    {
        if (m.count(nodeB))
            return nodeB;
        nodeB = nodeB->next;
    }
    return NULL;
}