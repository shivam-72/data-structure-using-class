#include <iostream>
using namespace std;
template <typename T>
class queue
{
public:
    T *data;
    int nextindex;
    int capacity;
    int firstindex;
    int size;

    queue()
    {
        data = new T[4];
        nextindex = 0;
        capacity = 4;
        firstindex = -1;
        size = 0;
    }
    bool isempty()
    {
        return size == 0;
    }
    int getsize()
    {
        return size;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            T *newdata = new T[2 * capacity];
            int j = 0;
            for (int i = firstindex; i < capacity; i++)
            {
                newdata[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstindex; i++)
            {
                newdata[j] = data[i];
                j++;
            }

            delete[] data;
            data = newdata;
            firstindex = 0;
            nextindex = capacity;
            capacity *= 2;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1) % capacity;
        if(firstindex==-1){
          firstindex++;
        }
        size++;
    }
    T deque()
    {
        if (isempty())
        {
            cout << "queue is empty";
            return 0;
        }
        else
        {
            T ans = data[firstindex];
            firstindex = (firstindex + 1) % capacity;
            size--;

            if (size == 0)
            {
                nextindex = 0;
                firstindex = -1;
            }
            return ans;
        }
    }
    T front()
    {
        if (isempty())
        {
            cout << "queue is empty";
            return 0;
        }
        return data[firstindex];
    }
};
int main()
{
    queue<int> q1;
    q1.enqueue(23);
    q1.enqueue(45);
    q1.enqueue(46);
    q1.enqueue(49);
    q1.enqueue(48);
    cout << q1.front();
    cout << q1.deque();
    cout << q1.deque();
    cout << q1.deque();
    cout << q1.deque();
    cout << q1.deque();
    cout << q1.isempty();
    cout << q1.front();
    return 0;
}