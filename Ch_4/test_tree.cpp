#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

int main()
{
    Node *node = new Node(10);
    node->left = new Node(19);
    node->right = new Node(20);

    cout << node->value << " " << node->left->value << " " << node->right->value << endl;
    delete node;
}