#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int val)
    {
        data = val;
        next = NULL;
        child = NULL;
    }
};

Node *createChildList(vector<int> arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        temp->child = new Node(arr[i]);
        temp = temp->child;
    }
    return head;
}
void printInput2D(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *tempChild = temp->child;
        while (tempChild != NULL)
        {
            cout << tempChild->data << " -> ";
            tempChild = tempChild->child;
        }
        cout << endl;
        temp = temp->next;
    }
}

Node* mergeTwoLists(Node* list1 , Node* list2){
    if(!list1) return list2;
    if(!list2) return list1;

    Node* result;

    if(list1->data > list2->data){
        result = list2;
        result->child = mergeTwoLists(list1 , list2->child);
    }
    if(list1->data < list2->data){
        result = list1;
        result->child = mergeTwoLists(list1->child , list2);
    }
    return result;
}
Node *flatten(Node *head)
{
    if (!head || !head->next)
        return head;

    head->next = flatten(head->next);

    head = mergeTwoLists(head, head->next);

    return head;
}
void printFlattened(Node* head) {
    while (head) {
        cout << head->data << endl;
        cout << "↓"<<endl;
        head = head->child;
    }
    cout << "NULL";
}


int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = createChildList({7, 8, 30});
    head->next->child = createChildList({20});
    head->next->next->child = createChildList({22, 50});
    head->next->next->next->child = createChildList({35, 40, 45});

    cout << "Input Linked List (2D Representation):" << endl;
    printInput2D(head);

    Node *flatHead = flatten(head);
    cout << "\nFlattened Linked List:" << endl;
    printFlattened(flatHead);
    return 0;
}