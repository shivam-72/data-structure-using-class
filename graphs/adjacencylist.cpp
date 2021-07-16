#include<iostream>
#include<list>
using namespace std;
class graph{
    int v;
    list<int>*l;
    public:
    graph(int v){
     this->v=v;
     l=new list<int>[v];
    }
    void addedge(int i,int j,bool undir=true){
        
    }
};
int main()
{
    return 0;
}