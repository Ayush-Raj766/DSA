#include<bits/stdc++.h>
using namespace std;

class Solution{
    public : 

    int fib(int n, vector<int> &dp) {
    dp[0]= 0;
    dp[1]= 1;

    for(int i = 2 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
    }
};

int main() {
    int n;
    cout << "enter the number =";
    cin >> n;

    vector<int> dp(n + 1, -1);

    Solution obj;

    cout << obj.fib(n, dp) << endl;
    return 0;
}