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
    // assumed linked list is not empty
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

void deleteMiddleNode(Node *li)
{
    Node *tortoise = li;
    Node *hare = li;
    Node *tortoise_prv;

    while (hare != NULL && hare->next != NULL)
    {
        tortoise_prv = tortoise;
        tortoise = tortoise->next;
        hare = hare->next->next;
    }

    tortoise_prv->next = tortoise->next;
}

int main()
{
    Node *li = new Node(0);
    appendLinkedList(li, 1);
    appendLinkedList(li, 2);
    appendLinkedList(li, 3);
    printLinkedList(li);
    deleteMiddleNode(li);
    printLinkedList(li);
}