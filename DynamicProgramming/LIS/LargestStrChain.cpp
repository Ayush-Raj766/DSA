#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool check(string &a , string &b){
        int n = a.size();
        int m = b.size();
        if(n != m + 1){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j == m;
    }

    int  solve(int prev , int curr , vector<string>&words , vector<vector<int>>&dp){
        if(curr ==  words.size()){
            return 0;
        }

        if(dp[prev + 1][curr] != -1){
            return dp[prev + 1][curr];
        }

        int len = 0;

        len = 0 + solve(prev , curr + 1 , words , dp);
        if(prev == -1 || check(words[curr] , words[prev])){
            len = max(len , 1 + solve(curr , curr + 1 , words , dp));
        }
        return dp[prev + 1][curr] = len;

    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end() , [](string &a , string &b){
            return a.size() < b.size();
        });

        vector<vector<int>> dp(n+1, vector<int>(n, -1)); 

        return solve(-1 ,  0 , words , dp);

    }
};

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    Solution sol;
    int lengthOfLongestChain = sol.longestStrChain(words);
    cout << lengthOfLongestChain << endl;
    
    return 0;
}