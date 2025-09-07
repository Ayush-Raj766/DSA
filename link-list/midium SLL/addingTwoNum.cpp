#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1 , ListNode* l2){
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    int carry = 0 ;
    while(temp1 !=0 || temp2 != 0){
        int sum = carry;
        if(temp1){
            sum = sum + temp1->val;
        }
        if(temp2){
            sum = sum + temp2->val;
        }
        ListNode* newNode = new ListNode(sum%10);
        carry = sum /10;
        curr->next = newNode;
        curr = curr->next;
        if(temp1){
            temp1 = temp1->next;
        }
        if(temp2){
            temp2 = temp2->next;
        }
    }
    if(carry){
        ListNode* newNode = new ListNode(carry);
        curr->next = newNode;
        newNode->next=NULL;
    }
    return dummy->next;
}

int main() {
     ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* sum_list = addTwoNumbers(l1, l2);

    cout << "Sum List: ";
    printList(sum_list);
    return 0;
}