#include <iostream>
using namespace std;
#include <climits> //for INT_MIN
class stackarray
{
    int *data;
    int nextindex;
    int capacity;

public:
    stackarray(int totalsize)
    {
        data = new int[totalsize];
        nextindex = 0;
        capacity = totalsize;
    }
    int size()
    {
        return nextindex;
    }
    bool isEmpty()
    {
        if (nextindex == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int element)
    {
        if (nextindex == capacity)
        {
            cout << "stackfull" << endl;
            return;
        }
        data[nextindex] = element;
        nextindex++;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return INT_MIN;
        }
        nextindex--;
        return data[nextindex];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return INT_MIN;
        }
         return data[nextindex - 1];
    }
};
int main()
{
    stackarray s(5);
    s.push(4);
    s.push(5);
    s.push(9);
    s.push(10);
    s.push(1);
    s.push(12);
    cout << s.top();
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << s.isEmpty();
    return 0;
}