#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class binarytreenode{
    public:
    T data;
    binarytreenode<T>*left;
    binarytreenode<T>*right;
    binarytreenode(T data){
     this->data=data;
     left=NULL;
     right=NULL;
    }
    ~binarytreenode(){
        delete left;
        delete right;
    }
};
binarytreenode<int>*takeinput(){
       int rootdata;
       cout<<"enter rootdata"<<endl;
       cin>>rootdata;
       if(rootdata==-1){
           return NULL;
       }
       binarytreenode<int>*root=new binarytreenode<int>(rootdata);
       queue<binarytreenode<int>*>q;
       q.push(root);
       while(q.size()!=0){
           binarytreenode<int>*front =q.front();
           q.pop();
           cout<<"enter left childdata of"<<front->data<<endl;
           int leftchilddata;
           cin>>leftchilddata;
           if(leftchilddata!=-1){
            binarytreenode<int>*leftchild=new binarytreenode<int>(leftchilddata);
            front->left=leftchild;
            q.push(leftchild);
           }
           cout<<"enter right childdata"<<front->data<<endl;
           int rightchilddata;
           cin>>rightchilddata;
           if(rightchilddata!=-1){
               binarytreenode<int>*rightchild=new binarytreenode<int>(rightchilddata);
               front->right=rightchild;
               q.push(rightchild);
           }

       }
       return root;
}
void print(binarytreenode<int>*root){
    if(root==NULL){
        return;
    }
    queue<binarytreenode<int>*>q;
    q.push(root);
    while(q.size()!=0){
         binarytreenode<int>*front=q.front();
         q.pop();
         cout<<front->data<<":";
         if(front->left!=NULL){
             q.push(front->left);
             cout<<front->left->data<<",";
         }
         if(front->right!=NULL){
             q.push(front->right);
             cout<<front->right->data;
         }
         cout<<endl;

    }
}
int height(binarytreenode<int>*root){
      if(root==NULL){
          return 0;
      }
      return 1 + max(height(root->left), height(root->right));
}
int diameter(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    int option1=height(root->left)+height(root->right);
    int option2=diameter(root->left);
    int option3=diameter(root->right);
    return max(option1,max(option2,option3));
}
//betteraproachof diameter
pair<int,int>heightdiameter(binarytreenode<int>*root){
     if (root==NULL){
         pair<int,int>p;
         p.first=0;
         p.second=0;
         return p;
     }
     pair<int,int>leftans=heightdiameter(root->left);
     pair<int,int>rightans=heightdiameter(root->right);
     int ld=leftans.second;
     int lh=leftans.first;
     int rd=rightans.second;
     int rh=rightans.first;
     int height= 1+ max(lh,rh);
     int diameter=max(lh+rh,max(ld,rd));
     pair<int,int>p;
     p.first=height;
     p.second=diameter;
     return p;
}
void printnormal(binarytreenode<int>*root){
    if(root==NULL){
        return;
    }
     cout<<root->data<<" :";
     if(root->left!=NULL){
         cout<<root->left->data<<",";
     }
     if(root->right!=NULL){
        cout<<root->right->data<<",";
     }
     cout<<endl;
     printnormal(root->left);
     printnormal(root->right);
}
int main()
{
    binarytreenode<int>*root=takeinput();
    printnormal(root);
    pair<int,int>p=heightdiameter(root);
    cout<<"height :"<<p.first<<endl;
    cout<<"Diameter :"<<p.second<<endl;

    return 0;
}