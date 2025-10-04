#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int key;
    int val;
    node *next;
    node *prev;
    node(int a, int b)
    {
        key = a;
        val = b;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
public:
    int capacity;
    map<int, node *> mp;
    // node *head, *tail;
    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    void addnoode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next=newnode;
        temp->prev=newnode;

    }
    void deletenode( node* delnode){
        delnode->prev->next=delnode->next;
        delnode->next->prev=delnode->prev;
    }
    int get(int key){
        if(mp.find(key) !=mp.end()){
            node* findnode = mp[key];
            int res = findnode->val;
            mp.erase(key);
            deletenode(findnode);
            addnoode(findnode);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    void put(int key , int val){
        if(mp.find(key) !=mp.end()){
            node* findnode =mp[key];
            mp.erase(key);
            deletenode(findnode);
        }
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnoode(new node(key,val));
        mp[key] = head->next;
    }
    void displayCache() {
        node* cur = head->next;
        cout << "Cache state: ";
        while (cur != tail) {
            cout << "{" << cur->key << "," << cur->val << "} ";
            cur = cur->next;
        }
        cout << endl;
    }

};

int main()
{
    LRUCache cache(5);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);
    cache.put(4, 40);
    cache.put(5, 50);
    cache.displayCache();

    cout << "Get 3 -> " << cache.get(3) << endl; // moves 3 to head
    cache.displayCache();

    cache.put(6, 60); // removes LRU (key=1)
    cache.displayCache();

    cache.put(7, 70); // removes LRU (key=2)
    cache.displayCache();

    return 0;
}