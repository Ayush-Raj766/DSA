#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string say (string s){
        string ans = "";
        int n = s.size();
        if(n == 0) return "1";
        for(int i = 0; i < n; ){
            int count = 1;
            while(i<n-1 && s[i] == s[i+1]){
                i++;
                count++;
            }
            ans += to_string(count);
            ans += s[i];
            i++;
    }
       return ans;
       
}

    string countAndSay(int n) {
        string ans = "";
        while(n--){
            ans = say(ans);
        }
        return ans;
    }
};

int main() {
    Solution solver;
    int n = 5;
    cout << "Count and Say term " << n << ": " << solver.countAndSay(n) << endl;
    return 0;
}