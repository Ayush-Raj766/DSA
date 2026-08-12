#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        string t = '1' + s + '1';
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (t[i] == '0') {
                int l = i - 1, r = i + 1;
                while (l >= 0 && t[l] == '1') l--;
                while (r <= n + 1 && t[r] == '1') r++;
                int len = r - l - 1;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "0100110";
    cout << sol.maxActiveSectionsAfterTrade(s) << endl;
    return 0;
}