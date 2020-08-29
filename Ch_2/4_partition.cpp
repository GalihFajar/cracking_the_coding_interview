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

Node *returnLastNode(Node *node)
{
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

Node *partition(Node *head, Node *last, int x)
{
    unordered_map<Node *, bool> m;
    Node *current = head;
    Node *prev = NULL;
    Node *next = current->next;
    while (current->next != NULL)
    {
        //Butuh special case dimana value headnya lebih  dari x
        if (current->value >= x && m.count(current) <= 0)
        {
            if (prev == NULL)
            {
                m[current] = true;
                current->next = NULL;
                last->next = current;
                current = next;
                head = current;
                next = next->next;
                last = last->next;
            }
            else
            {

                m[current] = true;
                prev->next = current->next;
                current->next = NULL;
                last->next = current;
                current = next;
                next = next->next;
                last = last->next;
            }
        }
        else
        {
            // cout << "masuk" << endl;
            prev = current;
            current = current->next;
            next = next->next;
        }
    }
    return head;
}

int main()
{
    Node *li = new Node(1);
    appendLinkedList(li, 4);
    appendLinkedList(li, 10);
    appendLinkedList(li, 9);
    appendLinkedList(li, 5);
    appendLinkedList(li, 6);
    appendLinkedList(li, 2);
    appendLinkedList(li, 1);

    Node *lastnode = returnLastNode(li);
    li = partition(li, lastnode, 5);
    printLinkedList(li);
}