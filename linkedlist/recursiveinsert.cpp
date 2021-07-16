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
            cout << head->data<<" ";
            head = head->next;
        }
    }
    node *insert(node *head, int i, int data)
    {
        node *temp = head;
        node *newnode = new node(data);
        if (i == 0)
        {
            newnode->next = head;
            head = newnode;
            return head;
        }
        else
        {
            int count = 0;
            while (count < i - 1 && temp != NULL)
            {
                temp = temp->next;
                count++;
            }
            if (temp != NULL)
            {
                node *a = temp->next;
                temp->next = newnode;
                newnode->next = a;
            }
        }
        return head;
    }
    node *dlete(node *head, int i)
    {
        node *temp = head;
        if (i == 0)
        {
            head = head->next;
            delete temp;
            return head;
        }
        else
        {
            int count = 0;
            while (count < i - 1 && temp != NULL)
            {
                temp = temp->next;
                count++;
            }
            node *p = temp->next;

            temp->next = p->next;
        }
        return head;
    }

int main()
{

    node *head = takeinput();
    print(head);
    head=insert(head,2,9);
    cout<<endl;
    print(head);
    cout<<endl;
    head=dlete(head,0);
    print(head);

    return 0;
}