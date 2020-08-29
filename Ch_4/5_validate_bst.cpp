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

void printInOrder(Node *node)
{
    if (node->left)
    {
        printInOrder(node->left);
    }
    printf("%d ", node->value);
    if (node->right)
    {
        printInOrder(node->right);
    }
}

//O(n) space
// vector<int> vect;
// void validateBST(Node *node)
// {
//     if(node -> left){
//         validateBST(node -> left);
//     }
//     vect.push_back(node -> value);
//     if()
// }

/** Utility **/
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
/************/
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *head = makeBinaryTree(v, v.size());
    printInOrder(head);
    cout << endl;
    cout << validateBST(head) << endl;
}

/* Too complex, too slow */
// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int value;
//     Node* left;
//     Node* right;

//     Node(int value) {
//         this->value = value;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// bool validateBSTLeft(Node* node, Node* next) {
//     if (next == NULL) return 1;
//     if (next->value < node->value && validateBSTLeft(node, next->left) && validateBSTLeft(node, next->right)) {
//         return 1;
//     }
//     return 0;
// }

// bool validateBSTRight(Node* node, Node* next) {
//     if (next == NULL) return 1;
//     if (next->value > node->value && validateBSTRight(node, next->left) && validateBSTRight(node, next->right)) {
//         return 1;
//     }

//     return 0;
// }

// bool validateBST(Node* node) {
//     if (node == NULL) return true;
//     if (node->left == NULL && node->right == NULL) {
//         return true;
//     }

//     int leftValue = node->left->value;
//     int rightValue = node->right->value;

//     if (!((validateBSTLeft(node, node->left)) && (validateBSTRight(node, node->right)))) return false;

//     if ((leftValue < rightValue) && validateBST(node->left) && validateBST(node->right))
//         return true;

//     return false;
// }

// int main() {
//     Node* head = new Node(6);
//     head->left = new Node(4);
//     head->right = new Node(10);
//     head->left->left = new Node(1);
//     head->left->right = new Node(5);

//     bool b = validateBST(head);

//     cout << b << endl;
// }