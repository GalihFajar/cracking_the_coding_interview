#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node *parent;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;
    }
};

int MIN = 99999;

Node *returnMinimumNode(Node *node)
{

    while (node)
    {
        if (node->left == NULL && node->right == NULL)
        {
            return node;
        }
        node = node->left;
    }
}

void insert(Node *node, int insertedValue)
{
    if (insertedValue <= node->value)
    {
        if (node->left)
        {
            insert(node->left, insertedValue);
        }
        else
        {
            node->left = new Node(insertedValue);
            node->left->parent = node;
        }
    }
    else
    {
        if (node->right)
        {
            insert(node->right, insertedValue);
        }
        else
        {
            node->right = new Node(insertedValue);
            node->right->parent = node;
        }
    }
}

Node *searchAndReturnNode(Node *node, int target)
{
    while (node)
    {
        if (target == node->value)
            return node;
        if (target < node->value)
        {
            node = node->left;
        }
        else if (target > node->value)
        {
            node = node->right;
        }
    }
    return NULL;
}

int successesor(Node *node)
{
    if (node->right != NULL)
    {
        return returnMinimumNode(node->right)->value;
    }
    else
    {
        if (node->parent == NULL)
            return 0;
        Node *temp = node->parent;
        while (temp)
        {
            if (temp->left == node)
                return node->parent->value;
            node = temp;
            temp = temp->parent;
        }
        return 0;
    }
}

int main()
{
    Node *tree_1 = new Node(20);
    insert(tree_1, 8);
    insert(tree_1, 22);
    insert(tree_1, 4);
    insert(tree_1, 12);
    insert(tree_1, 10);
    insert(tree_1, 14);
    // Node *a = tree_1->left;
    // a->value = 100;
    // cout << tree_1->left->value << endl;

    int input;
    cin >> input;
    Node *node = searchAndReturnNode(tree_1, input);
    cout << successesor(node) << endl;
}