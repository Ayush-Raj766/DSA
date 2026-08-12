#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow!=nullptr || slow->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};

int main()
{
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
    if(sol.hasCycle(head)){
        cout<<"Cycle is present in the linked list"<<endl;
    }
    else{
        cout<<"Cycle is not present in the linked list"<<endl;
    }

    return 0;
}