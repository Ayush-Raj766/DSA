#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        unordered_map<char, int> freq;
        stack<char> st;
        int ans = 0;
        for (char c : word) {
            freq[c]++;
        }

        for (auto it : freq) {
            st.push(it.first);
        }

        int pushes = 1;
        while(!st.empty()) {
            char c = st.top();
            st.pop();
            ans += freq[c] * pushes;
            if(st.size() % 8 == 0) {
                pushes++;
            }
        }
    

        return ans;
    }
};

int main() {
    Solution sol;
    string word = "aaaaaaa";
    cout << sol.minimumPushes(word) << endl;
    return 0;
}