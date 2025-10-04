#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s , int k){
    int map[26]={0};
    int l=0;
    // int r=0;
    int maxFreq=0;
    int ans=0;
    int n=s.length();
    for(int r=0;r<n;r++){
        map[s[r]-'A']++;
        maxFreq =max(maxFreq ,map[s[r]-'A']);

        while ((r - l + 1) - maxFreq > k) {
            map[s[l] - 'A']--;
            l++;
        }
        ans = max(ans,r-l+1);
    }
    return ans;
}

int main() {
    string s = "AABABCCAABAABC";
    int k = 3;
    cout << characterReplacement(s, k) << endl;  // Output: 4
    return 0;
}