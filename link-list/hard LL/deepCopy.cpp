// #include<bits/stdc++.h>
// using namespace std;
// class Node{
// public:
//     int data;
//     Node* next;
//     Node* random;

//     Node(int val){
//         data = val;
//         next = NULL;
//         random = NULL;
//     }
// };


// int main() {
//     Node* head = new Node(7);
//     head->next = new Node(14);
//     head->next->next = new Node(21);
//     head->next->next->next = new Node(28);

//     // Assigning random pointers
//     head->random = head->next->next;
//     head->next->random = head;
//     head->next->next->random = head->next->next->next;
//     head->next->next->next->random = head->next;

//     cout << "Original Linked List with Random Pointers:" << endl;
//     printClonedLinkedList(head);

//     // Clone the linked list
//     Node* clonedList = cloneLL(head);

//     cout << "\nCloned Linked List with Random Pointers:" << endl;
//     printClonedLinkedList(clonedList);

//     return 0;
// }