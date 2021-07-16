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
        }
        cin >> data;
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
}
node* dlete(node *head, int i)
{
    int count = 0;
    node *temp = head;
    if(i==0){
        head=head->next;
        delete temp;
       return head;
    }
   else{ while (count < i - 1 && temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    if(temp!=NULL){
    node *a = NULL;
    node *b = NULL;
    a = temp->next;
    b = a->next;
    temp->next = b;
    delete a;}
   }
   return head; 
}
int main()
{
    node *head = takeinput();
    print(head);
    head=dlete(head, 8);
    cout<<endl;
    print(head);
    return 0;
}