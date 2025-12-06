#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    Node* children[26];
    // int count;
    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        // count = 0;
    }
    void put(char ch){
        children[ch - 'a'] = new Node();
    }
    bool containsKey(char ch){
        return children[ch - 'a'] != nullptr;
    }
    Node* get(char ch){
        return children[ch - 'a'];
    }
    ~Node(){
        for(int i=0;i<26;i++){
            if(children[i]){
                delete children[i];
            }
        }
    }
};

int countDistinctSubstring(string s){
    Node* root = new Node();
    int n = s.length();
    int count = 0;
    for(int i = 0; i<n ; i++){
        Node* node = root;
        for(int j = i;j<n ; j++){
            char ch = s[j];
            if(!node->containsKey(ch)){
                node->put(ch);
                count++;
            }
            node = node->get(ch);
        }
    }
    delete root;
    return count + 1; // +1 for empty substring


}

int main() {
    string s;
    s = "abc";
    cout<< countDistinctSubstring(s)<<endl;
    return 0;
}