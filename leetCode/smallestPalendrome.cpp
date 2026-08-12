#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        
        string left = "", mid = "";
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                mid += (char)(i+'a');
                freq[i]--;
            }
        }
        for(int i=0;i<26;i++){
            while(freq[i]>0){
                left+=string(freq[i]/2,char('a'+i));
                freq[i]%=2;
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
}; 


int main() {
    string s = "abbba";
    int k = 1;
    Solution sol;
    cout << sol.smallestPalindrome(s, k) << endl;
    return 0;
}