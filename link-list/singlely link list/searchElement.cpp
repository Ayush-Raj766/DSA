#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*  next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class linklist{
    public:
    node* head;
    linklist(){
        head = NULL;
    }
    void insert(int val){
        node* newnode = new node(val);
        if(head == NULL){
            head = newnode;
            return;
        }
        node* temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next=newnode;
    }

    bool search(int target){
        node* temp = head;
        while(temp != NULL){
            if(temp->data == target){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};


int main() {
    vector<int> arr = {2, 5, 8, 7 , 78};
    linklist ll;
    for(int i=0; i<arr.size(); i++){
        ll.insert(arr[i]);
    }
    int target = 658;
    if(ll.search(target)){
        cout << "Element found";
    }
    else{
        cout << "Element not found";
    }
    return 0;
}













// #include<bits/stdc++.h>
// using namespace std;

// class node{
// public:
//     int data;
//     node* next;
//     node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class linklist{
// public:
//     node* head;
//     linklist(){
//         head = NULL;
//     }

//     void insert(int val){
//         node* newnode = new node(val);
//         if(head == NULL){
//             head = newnode;
//             return;   // ✅ stop here, avoids self-loop
//         }
//         node* temp = head;
//         while(temp->next != NULL){
//             temp = temp->next;
//         }
//         temp->next = newnode;
//     }

//     bool search(int target){
//         node* temp = head;
//         while(temp != NULL){  // ✅ check all nodes
//             if(temp->data == target){
//                 return true;
//             }
//             temp = temp->next;
//         }
//         return false;
//     }
// };

// int main() {
//     vector<int> arr = {2, 5, 8, 7 , 78};
//     linklist ll;
//     for(int i=0; i<arr.size(); i++){
//         ll.insert(arr[i]);
//     }

//     int target = 7;
//     if(ll.search(target)){
//         cout << "Element found";
//     } else {
//         cout << "Element not found";
//     }
//     return 0;
// }
