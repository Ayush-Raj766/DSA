#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n<m) return "";
        unordered_map<char,int> map;
        for( int i=0;i<m;i++){
            map[t[i]]++;
        }
         int count =0;
    int l=0;
    int minlen = INT_MAX;
    int start = 0;
    for (int r=0;r<n;r++){
            if(map[s[r]] > 0) {
                count++;
                map[s[r]]--;
            }
            else if(map[s[r]] <= 0){
                map[s[r]]--;
            }

        while(count==m){
            minlen = min(minlen,r - l + 1);
            start = l;
            map[s[l]]++;
            if(map[s[l]]>0){
                count--;
            }
            l++;
        }
    }
    return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};

int main() {
        string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    Solution sol;
    string result = sol.minWindow(s, t);

    if (result.empty())
        cout << "No valid substring found.\n";
    else
        cout << "Smallest window substring: " << result << "\n";

    return 0;
    return 0;
}