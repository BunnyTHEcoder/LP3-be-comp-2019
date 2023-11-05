/******************************************************************************
BunnyTHEcoder
*******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareNode
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

void print(Node *root, string str)
{
    if (!root)
    {
        return;
    }
    if (root->data != '$')
    {
        cout << root->data << ": " << str << endl;
    }
    print(root->left, str + '0');
    print(root->right, str + '1');
}

void buildTree(char data[], int freq[], int size)
{
    priority_queue<Node *, vector<Node *>, CompareNode> minHeap;

    for (int i = 0; i < size; i++)
    {
        minHeap.push(new Node(data[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();

        Node *right = minHeap.top();
        minHeap.pop();

        Node *top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    print(minHeap.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    buildTree(arr, freq, size);

    return 0;
}
