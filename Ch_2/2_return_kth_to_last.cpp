#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value = 0, Node *next = NULL)
    {
        this->value = value;
        this->next = next;
    }
};

void appendLinkedList(Node *li, int inputValue)
{

    Node *current = li;
    while (current != NULL)
    {
        if (current->next == NULL)
        {
            current->next = new Node(inputValue);
            return;
        }
        current = current->next;
    }
}

void printLinkedList(Node *li)
{
    while (li != NULL)
    {
        printf("%d ", li->value);
        li = li->next;
    }
    printf("\n");
}

Node *returnKthtoLast(Node *li, int K)
{
    //Begin from 0 == head
    int temp = 0;
    Node *reNode;
    while (li != NULL && temp <= K)
    {
        if (temp == K)
        {
            reNode = li;
        }
        li = li->next;
        temp++;
    }

    // cout << reNode->value << endl;
    return reNode;
}

void destroyLinkedList(Node *node)
{
    while (node != NULL)
    {
        node->value = 0;
        node = node->next;
    }
}

int main()
{
    Node *li = new Node(1);
    appendLinkedList(li, 2);
    appendLinkedList(li, 3);
    appendLinkedList(li, 4);
    appendLinkedList(li, 5);
    appendLinkedList(li, 6);
    Node *temp = returnKthtoLast(li, 2);
    printLinkedList(li);
    printLinkedList(temp);
}