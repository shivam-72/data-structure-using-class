#include<iostream>
#include<bits/stdc++.h>
#include"binarytree.h"
using namespace std;
//in->inorder.
//post->postorder.
//inS->inorderstart.
//inE->inorderend.
//postS->postorderstart.
//postE->postorderend.
binarytreenode<int>*buildtreehelper(int*in,int*post,int inS,int inE,int postS,int postE){
     if(inS>inE){
         return NULL;
     }
     int rootdata=post[postE];
     int rootindex=-1;
     for(int i=inS;i<=inE;i++){
         if(in[i]==rootdata){
             rootindex=i;
             break;
         }
     }
     int lpostS=postS;
     int rinS=rootindex+1;
     int linS=inS;
     int linE=rootindex-1;
     int lpostE=linE-linS+lpostS;
     int rpostE=postE-1;
     int rinE=inE;
     int rpostS=rinS-rinE+rpostE;
     binarytreenode<int>*root=new binarytreenode<int>(rootdata);
     root->left=buildtreehelper(in,post,linS,linE,lpostS,lpostE);
     root->right=buildtreehelper(in,post,rinS,rinE,rpostS,rpostE);
     return root;
}
binarytreenode<int>*buildtree(int* in,int* post,int size){
    return buildtreehelper(in,post,0,size-1,0,size-1);
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
    int post[]={4, 5 ,2 ,8 ,9, 6, 7, 3 ,1};
    binarytreenode<int>*root=buildtree(in,post,9);
    print(root);
    inorder(root);

    return 0;
}