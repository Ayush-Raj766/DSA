#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l=0;
        // int count =0;
        int sum=0;
        int a=-1,b=-1,c=-1;
        for(int r= 0 ; r<n ;r++){
            if(s[r]=='a') a=r;
            if(s[r]=='b') b=r;
            if(s[r]=='c') c=r;
            if(a!=-1 && b!=-1 && c!=-1) {
                sum += min({a,b,c})+1;
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    string s = "bbacba";
    cout << sol.numberOfSubstrings(s) << endl;
    return 0;
}