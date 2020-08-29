#include <bits/stdc++.h>
using namespace std;

//Linked-list based queue
//Type val == 1 -> cat
//Type val == 2 -> dog
class Shelter
{
public:
    int val;
    Shelter *next;

    Shelter(int val = 0, Shelter *next = NULL)
    {
        this->val = val;
        this->next = next;
    }

    void enqueue(int input)
    {
        Shelter *head = this;
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = new Shelter(input);
    }

    void printShelter()
    {
        Shelter *iter = this;
        while (iter != NULL)
        {
            cout << iter->val << " ";
            iter = iter->next;
        }
        cout << endl;
    }

    Shelter *dequeueAny()
    {
        return this->next;
    }

    Shelter *dequeueCat()
    {
        if (this->val == 1)
        {
            return this->next;
        }
        else
        {
            Shelter *new_head = this;
            Shelter *iter = new_head;
            Shelter *prev_iter = new_head;
            while (iter != NULL)
            {
                if (iter->val == 1)
                {
                    prev_iter->next = iter->next;
                    return new_head;
                }
                prev_iter = iter;
                iter = iter->next;
            }
            return new_head;
        }
    }

    Shelter *dequeueDog()
    {
        if (this->val == 2)
        {
            return this->next;
        }
        else
        {
            Shelter *new_head = this;
            Shelter *iter = new_head;
            Shelter *prev_iter = new_head;
            while (iter != NULL)
            {
                if (iter->val == 2)
                {
                    prev_iter->next = iter->next;
                    return new_head;
                }
                prev_iter = iter;
                iter = iter->next;
            }
            return new_head;
        }
    }
};

int main()
{
    Shelter *s1 = new Shelter(2);
    s1->enqueue(2);
    s1->enqueue(2);
    s1->enqueue(2);
    s1->enqueue(2);
    s1->enqueue(1);
    s1->printShelter();
    s1 = s1->dequeueCat();
    s1 = s1->dequeueDog();
    s1->printShelter();
}