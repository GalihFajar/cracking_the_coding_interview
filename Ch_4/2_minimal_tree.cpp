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

unordered_map<int, bool> m;

vector<int> makeSubArray(vector<int> &inputArray, int leftMost, int rightMost)
{
    vector<int> v;
    for (int i = leftMost; i <= rightMost; i++)
    {
        v.push_back(inputArray[i]);
    }

    return v;
}

Node *makeBinaryTree(vector<int> &listInput, int listInputSize)
{
    int middle = (listInput.size() - 1) / 2;
    Node *head = new Node(listInput[middle]);
    vector<int> leftArray;
    vector<int> rightArray;
    int middleLeft;
    int middleRight;
    if (middle - 1 >= 0)
        leftArray = makeSubArray(listInput, 0, middle - 1);
    if (middle + 1 < listInputSize)
        rightArray = makeSubArray(listInput, middle + 1, listInput.size() - 1);

    if (!leftArray.empty())
    {
        middleLeft = leftArray[leftArray.size() / 2];
        head->left = makeBinaryTree(leftArray, listInputSize);
    }
    if (!rightArray.empty())
    {

        middleRight = rightArray[rightArray.size() / 2];
        head->right = makeBinaryTree(rightArray, listInputSize);
    }

    return head;
}

void printBFS(Node *head)
{
    queue<Node *> q;
    q.push(head);

    while (!q.empty())
    {
        Node *current = q.front();
        cout << current->value << endl;
        q.pop();
        if (current->left)
        {
            q.push(current->left);
        }
        if (current->right)
        {
            q.push(current->right);
        }
    }
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *output = makeBinaryTree(v, (v.size()));
    printBFS(output);

    vector<int> v2{1, 2, 3};
    printBFS(makeBinaryTree(v2, v2.size()));
}