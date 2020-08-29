#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    vector<Node *> adjacent;
    bool visited;
    Node(string data)
    {
        this->data = data;
        this->adjacent = {};
        this->visited = false;
    }
};

class Graph
{
public:
    vector<Node *> nodes;
    unordered_map<Node *, vector<bool>> dependencies;
    Graph(vector<Node *> nodes)
    {
        this->nodes = nodes;
    }

    Node *searchNode(Node *node)
    {
        if (this->nodes.empty())
        {
            return NULL;
        }

        for (auto x : this->nodes)
        {
            if (x->data == node->data)
                return x;
        }
        return NULL;
    }

    void printDependencies()
    {
        for (auto x : this->dependencies)
        {
            cout << x.first->data << " ";
            for (auto y : x.second)
                cout << y << " ";
            cout << endl;
        }
    }
};

Graph *makeGraph(vector<Node *> inputProjects, vector<pair<Node *, Node *>> inputDependencies)
{
    Graph *outputGraph = new Graph({});
    //Inserting node into graph array
    for (auto inputProject : inputProjects)
    {
        vector<bool> temp;
        outputGraph->dependencies[inputProject] = temp;
        outputGraph->nodes.push_back(inputProject);
    }
    // Constructing map of dependencies
    for (auto inputDependency : inputDependencies)
    {
        Node *nodeOnGraphArray = outputGraph->searchNode(inputDependency.first);
        nodeOnGraphArray->adjacent.push_back(outputGraph->searchNode(inputDependency.second));
        Node *temp = outputGraph->searchNode(inputDependency.second);
        outputGraph->dependencies[temp].push_back(true);
    }

    return outputGraph;
}

vector<Node *> makeVectorOfNode(vector<string> v)
{
    vector<Node *> outputVector;
    for (auto x : v)
    {
        Node *temp = new Node(x);
        outputVector.push_back(temp);
    }
    return outputVector;
}

vector<pair<Node *, Node *>> makeVectorOfDependency(vector<pair<string, string>> v)
{
    vector<pair<Node *, Node *>> outputVector;
    for (auto x : v)
    {
        Node *pair_1 = new Node(x.first);
        Node *pair_2 = new Node(x.second);
        outputVector.push_back(make_pair(pair_1, pair_2));
    }
    return outputVector;
}

Node *selectStart(Graph *graph)
{
    if (graph->nodes.empty())
        return NULL;
    int isValid = false;
    for (auto x : graph->dependencies)
    {
        isValid = isValid || x.second.empty();
    }
    if (!isValid)
        return NULL;
    for (auto node : graph->nodes)
    {
        if (!(node->adjacent.empty()) && graph->dependencies[node].empty())
        {
            return node;
        }
    }
    return NULL;
}

void printBFSHelper(Node *node, Graph *graph)
{
    queue<Node *> q;
    q.push(node);
    node->visited = true;

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";
        for (auto input : current->adjacent)
        {
            // cout << input->data << " <----" << endl;
            if (!graph->dependencies[input].empty())
            {
                graph->dependencies[input].pop_back();
            }
            // graph->printDependencies();
            if (graph->dependencies[input].empty())
            {
                q.push(input);
                input->visited = true;
            }
            // cout << q.empty() << " <--- isQueueEmpty" << endl;
        }
    }
    // cout << "terminate" << endl;
}

void printBFS(Graph *graph)
{
    for (auto node : graph->nodes)
    {
        if (node->adjacent.empty() && graph->dependencies[node].empty())
            cout << node->data << " ";
    }
    Node *start = selectStart(graph);
    if (start == NULL)
    {
        cout << "ERROR!" << endl;
        return;
    }
    printBFSHelper(start, graph);
    for (auto node : graph->nodes)
    {
        if (!node->visited and graph->dependencies[node].empty())
            printBFSHelper(node, graph);
    }
}

vector<Node *> inputProjects()
{
    string input;
    vector<string> inputArray;
    while (cin >> input)
    {
        inputArray.push_back(input);
    }
    return makeVectorOfNode(inputArray);
}

vector<pair<Node *, Node *>> inputDependencies()
{
    string inputA;
    string inputB;
    // int count = 2;
    vector<pair<string, string>> inputArray;
    while (cin >> inputA >> inputB)
    {
        pair<string, string> temp = {inputA, inputB};
        inputArray.emplace_back(temp);
    }
    return makeVectorOfDependency(inputArray);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // vector<string> inputProjects{"a", "b", "c", "d", "e", "f"};
    // vector<pair<string, string>> inputDependency{{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}};
    // vector<string> inputProjects{"a", "b", "c", "d", "e"};
    // vector<pair<string, string>> inputDependency{{"a", "b"}, {"b", "c"}, {"c", "d"}, {"e", "d"}, {"a", "e"}};
    // vector<Node *> projectsNode = makeVectorOfNode(inputProjects);
    vector<Node *> projectsNode = inputProjects();
    vector<pair<Node *, Node *>> dependencyNode = inputDependencies();
    // vector<pair<Node *, Node *>> dependencyNode = makeVectorOfDependency(inputDependency);
    Graph *graph = makeGraph(projectsNode, dependencyNode);
    printBFS(graph);
}
