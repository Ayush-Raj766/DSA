#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class linklist
{
public:
    node *head;
    node *tail;
    linklist()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int val)
    {
        node *newNode = new node(val);
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void deleteNode()
    {
        node *toDelete = tail;
        if (head == NULL && tail == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else
        {
            tail = tail->prev;
            delete toDelete;
            tail->next = NULL;
        }
    };
    void display()
    {
        node *temp = head;
        if (temp != NULL)
        {
            cout << "NULL <-> ";
            while (temp != NULL)
            {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    linklist ll;
    vector<int> arr = {2, 5, 8, 7, 78};
    for (int i = 0; i < arr.size(); i++)
    {
        ll.insert(arr[i]);
    }
    // int val;
    // cout<<"Enter a value to insert: ";
    // cin>>val;
    // ll.insert(val);
    ll.display();
    ll.deleteNode();
    ll.display();
    return 0;
}