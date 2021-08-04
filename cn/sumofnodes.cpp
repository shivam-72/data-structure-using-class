#include<iostream>
#include<bits/stdc++.h>
#include"treenode.h"
using namespace std;
treenode<int>*takeinput(){
    int rootdata;
    cout<<"enter root data";
    cin>>rootdata;
    treenode<int>*root=new treenode<int>(rootdata);
    cout<<"no. of children of "<<rootdata<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        treenode<int>*output=takeinput();
        root->children.push_back(output);
    }
    return root;
}
 void print(treenode<int>*root){
     cout<<root->data<<":";
     for(int i=0;i<root->children.size();i++){
         cout<<root->children[i]->data<<",";
     }
     cout<<endl;
     for(int i=0;i<root->children.size();i++){
         print(root->children[i]);
     }

 } 
 int sumn(treenode<int>*root){
     int sum=root->data;
     for(int i=0;i<root->children.size();i++){
         sum+=sumn(root->children[i]);
     }
     return sum;
 }
 void printatlevelk(treenode<int>*root,int k){
       if(k==0){
           cout<<root->data<<endl;
           return;
       }
       for(int i=0;i<root->children.size();){
           printatlevelk(root->children[i],k-1);
       }
 }
 int countleaf(treenode<int>*root){
     if(root==NULL){
         return 0;
     }
        if(root->children.size()==0){
            return 1;
        }
        int num=0;
        for(int i=0;i<root->children.size();i++){
           num+= countleaf(root->children[i]);
        }
        return num;
 }
 
int main()
{
    treenode<int>*root=takeinput();
    //print(root);
   // cout<<sumn(root);
    // printatlevelk(root,0);

    return 0;
}