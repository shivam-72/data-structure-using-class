#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include"binarytree.h"
typedef binarytreenode<int> b;
b* takeinput(){
    int rootdata;
    cout<<"enter data";
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    b* root=new b(rootdata);
    queue<b*>q1;
    q1.push(root);
    while(q1.size()!=0){
        b*front=q1.front();
        q1.pop();
        int leftchilddata;
        cout<<"enter the left child of"<<front->data<<endl;
        cin>>leftchilddata;
        if(leftchilddata!=-1){
            b*leftchild=new b(leftchilddata);
            front->left=leftchild;
            q1.push(leftchild);
        }
         cout<<"right child of "<<front->data<<'\n';
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata!=-1){
             b*rightnode=new b(rightchilddata);
             front->right=rightnode;
             q1.push(rightnode);

        }

    }
    return root;
}
void preorder(b*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(b*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
     cout<<root->data<<" ";
}
void inorder(b*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void levelorder(binarytreenode<int>*root){
    if(root==NULL){
        return;
    }
    queue<binarytreenode<int>*>q;
    q.push(root);
    while(q.size()!=0){
       binarytreenode<int>*front=q.front();
       q.pop();
       cout<<front->data <<" ";
       if(front->left != NULL){
           q.push(front->left);
           //cout<<" L :"<<front->left->data;
       }
       if(front->right !=NULL){
           q.push(front->right);
          // cout<<" R :"<<front->right->data;
       }
       //cout<<endl;
    }
}
int main()
{
     b*root=takeinput();
    /* inorder(root);
     cout<<endl;
     levelorder(root);
     cout<<endl;
     preorder(root);
     cout<<endl;*/
     postorder(root);
      
    return 0;
}