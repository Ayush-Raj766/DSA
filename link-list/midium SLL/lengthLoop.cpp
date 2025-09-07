#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

int firstNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow= slow->next;
        
        if(fast == slow){
            int count = 1;
            fast = fast->next;
            while(slow != fast){
                
                fast = fast->next;
                count++;
            }
            return count;
        }

    }
    return -1;
}



int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(12);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    int loopStartNode = firstNode(head);

    cout << "Length of the loop is: " << loopStartNode << endl;

    return 0;
}