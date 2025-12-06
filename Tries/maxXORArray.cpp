#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* children[2];
    Node(){
        children[0] = nullptr;
        children[1] = nullptr;
    }

    bool containsKey(int b){
        return children[b]!=nullptr;
    }
    void put(int b , Node* node){
        children[b]= node;
    }
    Node* get(int b){
        return children[b];
    }


    ~Node(){
        if(children[0]){
            delete children[0];
        }
        if(children[1]){
            delete children[1];
        }
    }
};

void insert(int num , Node* root){
    Node* node =root;
        for(int i =31 ; i>=0 ; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit , new Node());
            }
            node = node->get(bit);
        }
}

int maxXOR(int num , Node* root){
    Node* node = root;
    int maxXOR = 0;
    for(int i =31 ; i>=0 ; i--){
        int bit = (num >> i) & 1;
        if(node->containsKey(1-bit)){
            maxXOR = maxXOR | (1<<i);
            node = node->get(1-bit);
        }
        else{
            node = node->get(bit);
        }
    }
    return maxXOR;
}

int findMaximumXOR(vector<int>& nums){
    Node* root = new Node();
    for(int num :nums){
        insert(num, root);
    }
    int maxXORValue = 0;
    for(int num : nums){
        int currentXOR = maxXOR(num , root);
        maxXORValue = max(maxXORValue , currentXOR);
    }
    return maxXORValue;
}

int main() {
    vector<int> nums = {14,70,53,83,49,91,36,80,92,51,66,70};
    findMaximumXOR(nums);
    cout<< findMaximumXOR(nums)<<endl;
    return 0;
}   