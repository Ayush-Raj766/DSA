#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class linklist
{
public:
    node *head;
    linklist()
    {
        head = NULL;
    }
    void insert(int val)
    {
        node *n = new node(val);
        if (head == NULL)
        {
            head = n;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    node *reverseRecursion(node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node *newHead = reverseRecursion(head->next);
        node *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};

int main()
{
    linklist ll;
    vector<int> arr = {1, 2, 3, 4, 5, 7};
    for (int i = 0; i < arr.size(); i++)
    {
        ll.insert(arr[i]);
    }
    ll.display();
    ll.head = ll.reverseRecursion(ll.head);
    ll.display();
    return 0;
}