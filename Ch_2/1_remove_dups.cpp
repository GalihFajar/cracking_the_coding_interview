#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data = 0, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
    }

    void append(int input)
    {
        Node *TEMP = this;
        Node *NEW_NODE = new Node();
        if (this == NULL)
        {
            this->data = input;
            return;
        }
        while (1)
        {
            if (TEMP->next == NULL)
            {
                NEW_NODE->data = input;
                NEW_NODE->next = NULL;
                TEMP->next = NEW_NODE;
                return;
            }
            TEMP = TEMP->next;
        }
    }

    Node *deleteNode(Node *head, int value)
    {
        Node *current = head;
        if (head->data == value)
        {
            return head->next;
        }
        while (current->next != NULL)
        {
            if (current->next->data == value)
            {
                current->next = current->next->next;
                return head;
            }
            current = current->next;
        }
        return head;
    }

    void printLinkedList()
    {
        Node *node = this;
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
        cout << "\n";
    }

    void deleteDups()
    {
        Node *iter = this;
        Node *prev = NULL;
        unordered_map<int, bool> m;
        while (iter != NULL)
        {
            if (m.count(iter->data))
            {
                prev->next = iter->next;
                iter = iter->next;
            }
            else
            {
                if (!m.count(iter->data))
                    m[iter->data] = true;
                prev = iter;
                iter = iter->next;
            }
        }
    }
};

Node *arrayToLinkedList(vector<int> &input)
{
    Node *head;
    for (int i = 0; i < input.size(); i++)
    {
        head->append(input[i]);
    }
    return head;
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    Node *l1;
    l1 = arrayToLinkedList(v);
    l1->printLinkedList();
}