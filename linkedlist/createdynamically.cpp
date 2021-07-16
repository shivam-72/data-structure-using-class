#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(node *head)
{
    node *temp = head; //to use the adress of head pointer again we
    while (temp != 0)
    {                              //should assign it to other pointer so when temp
        cout << temp->data << " "; //is zero head will be safe.(original value)
        temp = temp->next;
    }
}

int main()
{
    node*n1=new node(10);
    node*n2=new node(20);
    node*n3=new node(30);
    node*n4=new node(50);
    node*head=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    print(head);
    return 0;
}