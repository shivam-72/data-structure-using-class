#include <iostream>
#include "treenode.h"
#include <queue>
using namespace std;
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
treenode<int> *takeInput2()
{
    int rootdata;
    cout << "Enter root data";
    cin >> rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    queue<treenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        treenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        int n;
        cout << "enter the no. of children of " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childdata;
            cout << "enter the value of " << i << " th children of " << front->data << endl;
            cin >> childdata;
            treenode<int> *child = new treenode<int>(childdata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }
    return root;
}
void printtree(treenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ,";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children[i]);
    }
}
int numnd(treenode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numnd(root->children[i]);
    }
    return ans;
}
int main()
{
    // treenode<int> *root = new treenode<int>(1);
    // treenode<int> *node1 = new treenode<int>(2);
    // treenode<int> *node2 = new treenode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // printtree(root);
    treenode<int> *root = takeInput2();
    printtree(root);
    cout << numnd(root);

    return 0;
}