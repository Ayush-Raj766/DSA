#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    Node* children[26];
    int countEndWith;
    int countPrefix;

    Node(){
        countEndWith = 0;
        countPrefix = 0;
        for(int i = 0 ; i<26;i++){
            children[i] = nullptr;
        }
    }

    bool containskey(char ch){
        return (children[ch-'a'] != nullptr);
    }

    void put(char ch , Node* node){
        children[ch -'a'] =  node;
    }
    Node* get(char ch){
        return children[ch -'a'];
    }
    void increaseEnd(){
        countEndWith++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void deleteEnd(){
        countEndWith--;
    }
    void reducePrefix(){
        countPrefix--;
    }

    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    }
};

class Trie {
    public:
    Node* root;

    Trie(){
        root = new Node();
    }
    ~Trie(){
        delete root;
    }

    void insert(string word){
        Node*  node = root;
        for(char ch : word){
            if(!node->containskey(ch)){
                node->put(ch , new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node* node = root;
        for(char ch : word){
            if(node->containskey(ch)){
                node =node->get(ch);
            }
            else{
                return 0;
            }
        }
        return node->countEndWith;
    }

    int countWordsStartingWith(string prefix){
        Node* node = root;
        for(char ch :prefix){
            if(node->containskey(ch)){
                node = node->get(ch);
            }
            else{
                return 0;
            }
        }
        return node->countPrefix;
    }

    void erase(string word){
        Node* node = root;
        for(char ch : word){
            if(node->containskey(ch)){
                node = node->get(ch);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("apple");
    cout << "Inserting strings 'apple' twice into Trie" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'apple' from trie" << endl;
    trie.erase("apple");
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    return 0;
}