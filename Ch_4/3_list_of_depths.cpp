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

class LinkedList
{
public:
    int value;
    LinkedList *next;

    LinkedList(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

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

unordered_map<int, vector<Node *>> m;

void treeMapping(Node *head, int currentDepth)
{
    m[currentDepth].push_back(head);
    if (head->left)
    {
        // m[currentDepth + 1].push_back(head->left);
        treeMapping(head->left, currentDepth + 1);
    }
    if (head->right)
    {
        // m[currentDepth + 1].push_back(head->right);
        treeMapping(head->right, currentDepth + 1);
    }
}

void printLinkedList(LinkedList *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

LinkedList *vectorToLinkedList(vector<Node *> v)
{
    LinkedList *li = new LinkedList(v[0]->value);
    LinkedList *iter = li;
    if (v.size() == 1)
    {
        return li;
    }
    else
    {
        for (int i = 1; i < v.size(); i++)
        {
            iter->next = new LinkedList(v[i]->value);
            iter = iter->next;
        }
    }
    return li;
}

vector<LinkedList *> treeDepth(unordered_map<int, vector<Node *>> m)
{
    vector<LinkedList *> v;
    for (auto x : m)
    {
        LinkedList *li = vectorToLinkedList(x.second);
        v.push_back(li);
    }
    return v;
}

int main()
{
    vector<int> v{3, 4, 5, 70, 90, 100, 203, 500};
    Node *output = makeBinaryTree(v, (v.size()));

    treeMapping(output, 0);
    vector<LinkedList *> vd;
    vd = treeDepth(m);
    for (auto x : vd)
    {
        printLinkedList(x);
    }
}