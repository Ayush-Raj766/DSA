#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    
    Node* children[26];
    bool isEnd;
    int stringLength;

    Node() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
        stringLength = 0;
    }

    bool containKey(char ch){
        return children[ch-'a'] != nullptr;
    }

    void put(char ch , Node* node){
        children[ch -'a'] =  node;
    }

    Node* get(char ch){
        return children[ch-'a'];
    }

    void setEnd(){
        isEnd = true;
    }
    bool isEndNode(){
        return isEnd;
    }
};

class Trie {
    public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containKey(ch)){
                node->put(ch , new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
        node->stringLength = word.length();
    } 
};

string largestWordPrefix(vector<string>& words) {
    Trie trie;
    for(const string& word : words) {
        trie.insert(word);
    }
    string longestWord = "";
    for(const string&word : words){
        Node* node = trie.root;
        bool isComplete = true;
        for (char ch : word){
            if(node->containKey(ch)){
                node = node->get(ch);
                if(!node->isEndNode()){
                    isComplete =false;
                    break;
                }
            }
        }
        if(isComplete && word.length() > longestWord.length()) {
            longestWord = word;
        }
    }
    return longestWord;
}



int main() {
    vector<string> nums = { "n", "ni", "nin", "ninj" , "ninja" , "nil"};
    cout << largestWordPrefix(nums) << endl;
    
    
    return 0;
}