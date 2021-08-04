#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class treenode{
    public:
    T data;
    vector<treenode<T>*>children;
    treenode(T data){
        this-> data=data;
    }
    ~treenode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};
treenode<int>* takeinput(){
      int rootdata;
      cout<<"Enter root data"<<endl;
      cin>>rootdata;
      treenode<int>*root=new treenode<int>(rootdata);
      queue<treenode<int>*>q;
      q.push(root);
      while(q.empty()==false){
          treenode<int>*front=q.front();
          q.pop();
          int n;
          cout<<"how many children of "<<front->data<<endl;
          cin>>n;
        for(int i=0;i<n;i++){
            int childdata;
            cout<<"value of "<<i<<"th child of"<<front->data<<endl;
            cin>>childdata;
            treenode<int>*child=new treenode<int>(childdata);
            front->children.push_back(child);
            q.push(child);
        }
      }
    return root;
}
void preorder(treenode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++){
      preorder(root->children[i]);
    }

}
void postorder(treenode<int>*root){
     if(root==NULL){
         return ;
     }
     
     for(int i=0;i<root->children.size();i++){
      postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}
void deletetree(treenode<int>*root){
    for(int i=0;i<root->children.size();i++){
        deletetree(root->children[i]);
    }
    delete root;
}
int main()
{
    treenode<int>* root=takeinput();
    postorder(root);
    //deletetree(root);//one way of doing one more way is destructor.
    delete root;//destructor will be called.

    return 0;
}