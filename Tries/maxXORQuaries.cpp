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
class Solution {
public:
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

    int maxXOR(int num ,  Node* root){

        Node* node = root;
        int maxXOR = 0;
        for(int i =31 ; i>=0 ; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1-bit)){
                maxXOR = maxXOR | (1<<i);
                node = node->get(1-bit);
            }
            else if(node->containsKey(bit)){
                node = node->get(bit);
            }
            else{
                return -1;
            }
        }
        return maxXOR;
        
    }

    vector<int> maxXorQueries(vector<int>& arr, vector<vector<int>>& queries){
        vector<int> ans;
        for(auto q : queries){
            int x = q[0];
            int a = q[1];
            Node* root = new Node();
            bool inserted = false;
            for(int num : arr){
                if(num <= a){
                    insert(num , root);
                    inserted = true;
                }
            }
            if(!inserted){
                ans.push_back(-1);
            } else {
                ans.push_back(maxXOR(x , root));
            }
            delete root;
        }
        return ans;
    }
};


int main() {
    vector<int> arr = {3, 10, 5, 25, 2, 8};

    // Display the given array
    cout << "Given Array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Queries in {x, m} format
    vector<vector<int>> queries = {
        {0, 1}, {1, 2}, {0, 3}, {3, 3}
    };

    // Display queries
    cout << "Queries: ";
    for (auto query: queries) {
        cout << query[0] << " " << query[1] << ", ";
    }
    cout << endl;

    // Create solution object
    Solution obj;

    // Get results for queries
    vector<int> result = obj.maxXorQueries(arr, queries);

    // Display results
    cout << "Result of Max XOR Queries:" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Query " << i+1 << ": " << result[i] << endl;
    }

    return 0;
}