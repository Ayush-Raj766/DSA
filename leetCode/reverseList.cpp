#include<bits/stdc++.h>
using namespace std;


class ListNode{
    public:
    int val ;
    ListNode* next;

    ListNode(int x){
        val = x ;
        next = nullptr;
    }


};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        

        while(curr != nullptr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
        

    }
};

int main() {
    ListNode *head = new ListNode(2);
    ListNode *sec = new ListNode(8);
    ListNode *third = new ListNode(25);
    ListNode *forth = new ListNode(12);
    ListNode *fifth = new ListNode(21);
    ListNode *sixth = new ListNode(28);
    ListNode *seventh = new ListNode(26);
    ListNode *eighth = new ListNode(2);

    head->next = sec;
    sec->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next=sixth;
    sixth->next=seventh;
    seventh->next=eighth;
    eighth->next=third;
    Solution sol;
    sol.reverseList(head);
    return 0;
}