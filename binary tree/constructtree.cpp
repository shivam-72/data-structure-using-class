//with inorder and preorder constructtree.
#include<iostream>
#include<bits/stdc++.h>
#include"binarytree.h"
using namespace std;
//in->inorder.
//pre->preorder.
//inS->inorderstart.
//inE->inorderend. 
//preS->preorderstart.
//preE->preorderend.
//linS->left inorderstart.
//linE-> left inorderend. 
//lpreS->left preorderstart.
//lpreE->left preorderend.
//rinS->right inorderstart.
//rinE->right inorderend. 
//rpreS->right preorderstart.
//rpreE->right preorderend.
binarytreenode<int>*buildtreehelper(int*in,int*pre,int inS,int inE,int preS,int preE){
      if(inS>inE){
          return NULL;
      }
      int rootdata=pre[preS];
      int rootindex=-1;
      for(int i=inS;i<=inE;i++){
          if(in[i]==rootdata){
              rootindex=i;
              break;
          }
      }
      
      int lpreS=preS+1;
      int rpreE=preE;
      int linS=inS;
      int linE=rootindex-1;
      int rinS=rootindex+1;
      int lpreE=linE-linS+lpreS;
      int rinE=inE;
      int rpreS=lpreE+1;
      binarytreenode<int>*root=new binarytreenode<int>(rootdata);
      root->left=buildtreehelper(in,pre,linS,linE,lpreS,lpreE);
      root->right=buildtreehelper(in,pre,rinS,rinE,rpreS,rpreE);
      return root;
}
binarytreenode<int>*buildtree(int* in,int* pre,int size){
    return buildtreehelper(in,pre,0,size-1,0,size-1);
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
void inorder(binarytreenode<int> *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
int main()
{
    int in[]={4,2,5,1,8,6,9,3,7};
    int pre[]={1,2,4,5,3,6,8,9,7};
    binarytreenode<int>*root=buildtree(in,pre,9);
    print(root);
    cout<<endl;
    inorder(root);
    return 0;
}