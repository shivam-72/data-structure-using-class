#include <iostream>
using namespace std;
template <typename T>
class queue
{
    T *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;

public:
    queue(int s)
    {
        data = new int[s];
        firstindex = -1;
        nextindex = 0;
        size = 0;
        capacity = s;
    }
    bool isempty()
    {
        if (firstindex = -1)
        {
            return true;
        }
        else
            return false;
    }
    int getsize()
    {
        return size;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            cout << "queue is full";
            return ;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1) % capacity;
        if (firstindex == -1)
        {
            firstindex++;
        }
        size++;
    }
    T dequeue()
    {
        if (firstindex == -1)
        {
            cout << "queue is empty";
            return 0;
        }
        T ans = data[firstindex];
        firstindex = (firstindex + 1) % capacity;
        size--;

        if (size == 0)
        {
            firstindex = -1;
            nextindex = 0;
        }
        return ans;
    }
    T front()
    {
        if (firstindex == -1)
        {
            cout << "queue is empty";
            return 0;
        }
        return data[firstindex];
    }
};
int main()
{
    queue<int> q1(5);
    q1.enqueue(15);
    q1.enqueue(20);
    q1.enqueue(25);
    q1.enqueue(30);
    q1.enqueue(35);
    cout << q1.front();
    cout << q1.dequeue();
    cout << q1.dequeue();
    cout<< q1.getsize();

    return 0;
}