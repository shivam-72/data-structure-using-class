#include <iostream>
using namespace std;
template <typename T>
class node
{
    public:
    T data;
    node<T> *next;


    node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class queue
{
private:
    node<T> *head;
    node<T> *tail;
    int size;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {

        node<T> *newnode = new node<T>(element);
        if (size == 0)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }
        size++;
    }
    T front(){
        if (size == 0)
        {
            cout << "queue is empty";
            return 0;
        }
        return head->data;
    }
    T dequeue(){
        if(size==0){
            cout<<"queue is empty";
            return 0;
        }
        T ans= head->data;
        node<T>*temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }
};
int main()
{
    queue<int> q1;
    q1.enqueue(15);
    q1.enqueue(20);
    q1.enqueue(25);
    q1.enqueue(30);
    q1.enqueue(35);
    cout << q1.front();
    cout << q1.dequeue();
    cout << q1.dequeue();
    cout << q1.getsize();


    return 0;
}