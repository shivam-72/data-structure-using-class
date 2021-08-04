#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class treenode
{
public:
    T data;
    vector<treenode<T> *> children;

    treenode(T data)
    {
        this->data = data;
    }
};
treenode<int> *takeinput()
{
    int rootdata;
    cout << "enter root data";
    cin >> rootdata;
    treenode<int> *root = new treenode<int>(rootdata);
    queue<treenode<int> *> q1;
    q1.push(root);
    while (q1.empty() == false)
    {
        treenode<int> *front = q1.front();
        q1.pop();
        int n;
        int childdata;
        cout << "no. of children of " << front->data<<endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "enter the value of " << i << " th children of " << front->data << endl;
            cin >> childdata;
            treenode<int> *child = new treenode<int>(childdata);
            front->children.push_back(child);
            q1.push(child);
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
void printlvl(treenode<int>*root){
      queue<treenode<int> *>q;
      q.push(root);
     while(q.empty()==false){
         treenode<int>*front=q.front();
         q.pop();
         cout<<front->data<<":";
         for(int i = 0; i < front->children.size(); i++){
             cout<<front->children[i]->data<<",";
         }
         for(int i=0;i< front->children.size(); i++){
             q.push(front->children[i]);
         }
         cout<<endl;
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
    treenode<int> *root=takeinput();
   // printlvl(root);
   // cout<<endl;
    //printtree(root);
    cout<<numnd(root);
    return 0;
}