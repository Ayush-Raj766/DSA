#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        int l=0;
        int ans=0;
        unordered_map<char,int> map;
        for(int r =0;r<n;r++){
            map[s[r]]++;
            while(map.size()>k){
                map[s[l]]--;
                if(map[s[l]]==0){
                    map.erase(s[l]);
                }
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "eceba";
    int k = 2;
    cout << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}