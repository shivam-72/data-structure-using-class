//all operations are order of 1.
#include<iostream>
#include<climits>
using namespace std;
template<typename T>
class stackarray{
    T*data;
    int nextindex;
    int capacity;
    public:
    stackarray(){
     data=new T[4];
     nextindex=0;
     capacity=4;
    }
    int size(){
        return nextindex;
    }
    bool isEmpty(){
        if(nextindex==0){
            return true;
        }
        else{
            return false;
        }
    }
    void push(T element){
        if(nextindex==capacity){
         T*newdata=new T[2*capacity];
         for(int i=0;i<capacity;i++){
             newdata[i]=data[i];
         }
         capacity *=2;
         delete []data;
         data=newdata;
        }
        data[nextindex]=element;
        nextindex++;
    }
    void insert(int i,T element){
        if(i<nextindex){
            data[i]=element;
        }
        else if(nextindex==i){
            push(element);
        }
        else{
            return ;
        }
        
    }
    T pop(){
        if(nextindex==0){
            cout<<"stack is empty";
            return 0;
        }
        nextindex--;
         return data[nextindex];
    }
    T top(){
        if (nextindex == 0)
        {
            cout << "stack is empty";
            return 0;
        }
        return data[nextindex];
    }
    void print(){
        for(int i=0;i<nextindex;i++){
            cout<<data[i]<<endl;
        }
    }
};
int main(){
    stackarray<int>s1;
    // s1.push(40);
    // s1.push(30);
    // s1.push(20);
    // s1.push(10);
    // s1.push(5);
    // s1.print();
    // cout<<endl;
    //s1.insert(0,5);
    //s1.pop();
    s1.pop();
    stackarray<char>s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    
    s2.print();
    


    return 0;
}