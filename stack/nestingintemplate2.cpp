#include <iostream>
using namespace std;
template <typename T, typename P>
class pairs
{
private:
    T x;
    P y;

public:
     void setdataX(T x)
    {
        this->x = x;
    }
    T getdataX()
    {
        return x;
    }
   void setdataY(P y)
    {
        this->y = y;
    }
    P getdataY()
    {
        return y;
    }
};
int main()
{
    pairs<int, char> p1;
    p1.setdataX(23);
    p1.setdataY(24.996);
    cout<<p1.getdataX()<<" "<<p1.getdataY();
    cout<<endl;
    pairs<pairs<int,int>,int>p2;
    p2.setdataY(40);
    pairs<int,int>p4;
    p4.setdataX(30);
    p4.setdataY(35);
    p2.setdataX(p4);
    cout<<p2.getdataX().getdataX()<<" "<<p2.getdataX().getdataY()<<" "<<p2.getdataY();

    return 0;
}