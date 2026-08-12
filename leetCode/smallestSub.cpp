#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        stack<char> st;
        vector<int> lastIndex(26, -1);
        for(int i = 0; i < n; i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        vector<bool> inStack(26, false);
        for(int i = 0; i < n; i++) {
            char c = s[i];
            if(inStack[c - 'a']) continue;
            while(!st.empty() && st.top() > c && lastIndex[st.top() - 'a'] > i) {
                inStack[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            inStack[c - 'a'] = true;
        }
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
};

int main() {
    Solution sol;
    string s = "bcabc";
    string result = sol.smallestSubsequence(s);
    cout << "Smallest Subsequence: " << result << endl;
    
    return 0;
}