#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createList(vector<int> &vals){
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for(int i = 1 ; i <vals.size() ; i++){
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* current = head;
    while(current != nullptr){
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

 ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<pair<int, ListNode*> , vector<pair<int, ListNode*>> , greater<pair<int , ListNode*>>> minHeap;

    for(auto listHead :lists){
        if(listHead){
            minHeap.push({listHead->val , listHead});
        }
    }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!minHeap.empty()){
            auto [val , node] = minHeap.top();
            minHeap.pop();
            temp->next = node;
            temp = temp->next;
            if(node->next){
                minHeap.push({node->next->val , node->next});
            }
        }
        return dummy->next;
 }



int main() {
    vector<int> list1 = {1, 2, 3, 4};
    vector<int> list2 = {-4, -3};
    vector<int> list3 = {-5, -3, 1, 2, 3, 4};

    // Convert vectors into linked lists
    ListNode* head1 = createList(list1);
    ListNode* head2 = createList(list2);
    ListNode* head3 = createList(list3);

    vector<ListNode*> heads = {head1, head2, head3};

    cout << "Merging k sorted linked lists..." << endl;

    ListNode* merged = mergeKLists(heads);

    cout << "Merged List:" << endl;
    printList(merged);
    return 0;
}