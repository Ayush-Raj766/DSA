#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* add1 (Node* head){
    Node* temp = head;
    Node* lastNonNine = NULL;
    while (temp->next != NULL) {
        if (temp->data != 9) {
            lastNonNine = temp;
        }
        temp = temp->next;
    }

    // Now temp is the last node
    if (temp->data < 9) {
        temp->data++;
        return head;
    }

        if (lastNonNine != NULL) {
        lastNonNine->data++;
        lastNonNine = lastNonNine->next;
        while (lastNonNine != NULL) {
            lastNonNine->data = 0;
            lastNonNine = lastNonNine->next;
        }
        return head;
    }

    // All digits were 9
    Node* newHead = new Node(1);
    newHead->next = head;
    while (head != NULL) {
        head->data = 0;
        head = head->next;
    }
    return newHead;

}



int main()
{
    vector<int> arr = {1, 2, 9, 9, 9};
    int N = 3;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    printLL(head);
    add1(head);
    printLL(head);
    return 0;
}