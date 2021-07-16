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
class stack
{
public:
    node<T> *head;
    int size;
    stack()
    {
        head = NULL;
        size = 0;
    }
    bool isEMpty()
    {
        return size == 0;
    }
    int sizof()
    {
        return size;
    }
    void push(T element)
    {
        node<T> *newnode = new node<T>(element);
        newnode->next = head;
        head = newnode;
        size++;
    }
    T pop()
    {
        if (head == NULL)
        {
            cout << "stack is empty";
            return 0;
        }
        else
        {
            T ans = head->data;
            node<T> *temp = head;
            head->next = head;
            delete temp;
            size--;
            return ans;
        }
    }
    T top(){

        if (head == NULL)
    {
        cout << "stack is empty";
        return 0;
    }
    {
        T ans = head->data;
        return ans;
    }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << head->data << endl;
            head=head->next;
        }
    }
};
int main(){
    stack<char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    s2.print();
}