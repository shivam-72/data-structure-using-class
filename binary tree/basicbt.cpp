#include <iostream>
#include <bits/stdc++.h>
#include "binarytree.h"
using namespace std;
binarytreenode<int> *takeinput()
{
    int rootdata;
    cout << "Enter  data: " << endl;
    cin >> rootdata;
    if(rootdata ==-1){
        return NULL;
    }
    binarytreenode<int> *root = new binarytreenode<int>(rootdata);
    binarytreenode<int>*leftchild=takeinput();
    binarytreenode<int>*rightchild=takeinput();
    root->left=leftchild;
    root->right=rightchild;
   
   return root;
}
//take input level wise node
binarytreenode<int>*takeinput2(){
    int rootdata;
    cout<<"enter data"<<'\n';
    cin>>rootdata;
     if(rootdata ==-1){
        return NULL;
    }
    binarytreenode<int>*root= new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*>q;
    q.push(root);
    while(q.size()!=0){
        binarytreenode<int>*front=q.front();
        q.pop();
        cout<<"enter left child of"<< front->data<<'\n';
        int leftchilddata;
        cin>>leftchilddata; 
        if(leftchilddata!=-1){
             binarytreenode<int>*leftnode=new binarytreenode<int>(leftchilddata);
             front->left=leftnode;
             q.push(leftnode);
        }
        cout<<"right child of "<<front->data<<'\n';
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
             binarytreenode<int>*rightnode=new binarytreenode<int>(rightchilddata);
             front->right=rightnode;
             q.push(rightnode);

        }
    }
    return root;
}
void print(binarytreenode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << "L: " << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << " R: " << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}
void printlvlwise(binarytreenode<int>*root){
    if(root==NULL){
        return;
    }
    queue<binarytreenode<int>*>q;
    q.push(root);
    while(q.size()!=0){
       binarytreenode<int>*front=q.front();
       q.pop();
       cout<<front->data <<" :";
       if(front->left != NULL){
           q.push(front->left);
           cout<<" L :"<<front->left->data;
       }
       if(front->right !=NULL){
           q.push(front->right);
           cout<<" R :"<<front->right->data;
       }
       cout<<endl;
    }
}
int countnode(binarytreenode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+countnode(root->left)+countnode(root->right);
   /* int i=1;
    i+=countnode(root->left);
    i+=countnode(root->right);

    return i;*/
}
int main()
{
   /* binarytreenode<int> *root = new binarytreenode<int>(1);
    binarytreenode<int> *node1 = new binarytreenode<int>(2);
    binarytreenode<int> *node2 = new binarytreenode<int>(3);
    root->left = node1;
    root->right = node2;*/
    binarytreenode<int>*root=takeinput2();
    printlvlwise(root);
    cout<<countnode(root); 
    delete root; 
    return 0;
    //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
}