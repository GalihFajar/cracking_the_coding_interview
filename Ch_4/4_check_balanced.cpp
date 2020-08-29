#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
        this->height = 0;
    }
};

/********** UTILITY FUNCTIONS *******/

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
        cout << current->value << " " << current->height << endl;
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

/**********************************/


//pseudo height (height actually equals depth here)
int MAX_DEPTH = 0;
void maxDepth(Node* root) {
    if (root->left) {
        root->left->height = root->height + 1;
        MAX_DEPTH = max(MAX_DEPTH, root->left->height);
        maxDepth(root->left);
    }
    if (root->right) {
        root->right->height = root->height + 1;
        MAX_DEPTH = max(MAX_DEPTH, root->right->height);
        maxDepth(root->right);
    }
}


void treeHeight(Node* root) {
    maxDepth(root);
    root->height = MAX_DEPTH - root->height;
    if (root->left) {
        treeHeight(root->left);
    }
    if (root->right) {
        treeHeight(root->right);
    }
}



int calculateTreeHeight(Node* node, int depth) {
    if (node == NULL) return 0;
    int height_left = 0;
    int height_right = 0;
    if (node->left == NULL && node->right == NULL)
        return depth;
    if (node->left) {
        height_left = height_left + calculateTreeHeight(node->left, depth + 1);
    }
    if (node->right) {
        height_right = height_right + calculateTreeHeight(node->right, depth + 1);

    }

    return max(height_right, height_left);
}

bool isBalanced(Node* node) {
    if (node == NULL) return 1;
    int leftHeight = calculateTreeHeight(node->left, 0);
    int rightHeight = calculateTreeHeight(node->right, 0);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right))
        return 1;

    return 0;

}


int main() {
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Node* b= makeBinaryTree(v, v.size());
    maxDepth(b);
    printBFS(b);
    cout << endl;
    cout << calculateTreeHeight(b, 0) << endl;
    cout << calculateTreeHeight(b->left->left, 0) << endl;
    cout << calculateTreeHeight(b->left->right, 0) << endl;
    cout << isBalanced(b) << endl;

    cout << endl;
    Node* c = new Node(5);
    c->left = new Node(4);
    c->left->left = new Node(3);
    c->left->left->left = new Node(2);
    c->left->left->left->left= new Node(1);
    c->left = new Node(10);
    cout << isBalanced(c) << endl;
}