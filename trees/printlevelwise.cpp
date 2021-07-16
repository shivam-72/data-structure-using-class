#include <iostream>
#include "treenode.h"
#include <queue>
using namespace std;
void prntlvlwise(treenode<int> *root)
{
    cout << root->data << ":";
    queue<treenode<int> *> nodes;
    nodes.push(root);
    while (nodes.size() != 0)
    {
        treenode<int> *front = nodes.front();
        nodes.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ",";
            front->children.push_back(root->children[i]);
                nodes.push(root->children[i]);
        }
       
    }
    
}
treenode<int> *takeInput()
{
    int rootdata;
    cout << "Enterdata";
    cin >> rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    int n;
    cout << "enter the no. of children of " << rootdata << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        treenode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

int main()
{
    treenode<int> *root = takeInput();
    prntlvlwise(root);

    return 0;
}