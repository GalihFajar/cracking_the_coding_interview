#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
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

//Assumption : every number in the trees are distinct;

bool dfs(Node *node, int target)
{
    bool returnValue = false;
    if (node->value == target)
    {
        return true;
    }
    if (node->left)
    {
        returnValue = returnValue || dfs(node->left, target);
    }
    if (node->right)
    {
        returnValue = returnValue || dfs(node->right, target);
    }
    return returnValue;
}

Node *firstCommonAncestor(Node *root, int target_1, int target_2)
{
    // Run BFS
    queue<Node *> q;
    q.push(root);
    Node *output;
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        // cout << current->value << endl;
        bool isAncestor = false;
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
        isAncestor = dfs(current, target_1) && dfs(current, target_2);
        if (isAncestor)
            output = current;
        // cout << current->value << " " << isAncestor << endl;
    }
    return output;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Tree Initiation
    Node *root = new Node(1);
    // root->left = new Node(2);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->left->left = new Node(6);
    // root->left->left->right = new Node(7);

    // root->right = new Node(3);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(9);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);

    cout << firstCommonAncestor(root, 3, 5)->value << endl;
}