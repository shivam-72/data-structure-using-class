#include <iostream>
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

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
            //or tail=newnode;
        }
        cin >> data;
    }
    return head;
}
node* insert(node *head, int index, int data)
{
    node *newnode = new node(data);
    node *temp = head;
    if (index == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    else
    {      
        int count=0;
        
            while (temp!=NULL && count < index - 1)
            {
                temp = temp->next;
                count++;
            }
          if(temp!=NULL){
            node *a = temp->next;
            temp->next = newnode;
            newnode->next = a;
          }
    }
    return head;
}
void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = takeinput();
    print(head);
    int data, i;
    cin >> data >> i;
    head=insert(head, i, data);
    print(head);
    return 0;
}