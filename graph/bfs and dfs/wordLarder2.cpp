#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level =0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            if(vec.size() > level){
                level++;
                for (auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();

            }
            string word = vec.back();
            for(int i = 0 ; i < word.size() ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        usedOnLevel.push_back(word);
                        if(word == endWord){
                            ans.push_back(vec);
                        }
                        else{
                            q.push(vec);
                        }
                        vec.pop_back();
                    }

                }
                word[i] = original;
            }
        }
        return ans;

    }
};

int main() {
     vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj;
    vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        for (auto &seq : ans) {
            for (auto &word : seq) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    return 0;
}