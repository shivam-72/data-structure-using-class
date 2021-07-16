#include<iostream>
using namespace std;
class dynamic
{
    int *data;
    int nextindex;
    int capacity;

public:
    dynamic()
    {
        data = new int[5];
        nextindex = 0;
        capacity = 5;
    }
    void add(int element)
    {
        if (nextindex == capacity){
            int*newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newdata[i]=data[i];
            }
            delete []data;
            data=newdata;
            capacity*=2;
        }
        data[nextindex]=element;
        nextindex++;
    }
    int get(int i){
        if(i<nextindex)
       return data[i];
       else
       return -1;
    }
    void insert(int i,int element){
        if(i<nextindex){
            data[i]=element;
        }
        else if(i==nextindex){
            add(element);
        }
        else
        return ;
    }
    void print(){
        for(int i=0;i<nextindex;i++){
            cout<<data[i]<<" ";
        }
    }
};
int main(){
    dynamic d1;
    d1.add(4);
    d1.add(6);
    d1.add(7);
    d1.add(9);
    d1.add(11);
    d1.add(2);
    d1.add(0);
    d1.insert(0,20);
    d1.print();






    return 0;
}