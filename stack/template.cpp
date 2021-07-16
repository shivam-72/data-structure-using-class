#include<iostream>
using namespace std;
template <typename T>
class pr{
    private:
    T x;
    T y;
    public:
    void setX(T x){
        this->x=x;
    }
    T getX(){
        return x;
    }
    void setY(T y){
        this->y=y;
    }
    T getY(){
        return y;
    }

};
int main(){
    pr <int> p1;
    p1.setX(10);
    p1.setY(20);
    cout<<p1.getX();
    pr<double>p2;
    p2.setX(27.99);
    p2.setY(80.56);
   cout<<p2.getX();
   pr<char>p3;
   p3.setX('a');
   cout<<p3.getX();

    return 0;
    
}