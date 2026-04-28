#include<bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int numOfWays(int n){


    long long A[n]  , B[n];

    A[1] = 6;
    B[1] = 6;
    int res;

    for(int i = 2 ; i<=n ; i++){
        A[i] = ((3 * A[i-1]) + (2 * B[i-1])) % MOD;
        B[i] = ((2 * A[i-1]) + (2 * B[i-1])) % MOD;
    }

    res = (A[n] + B[n]) % MOD;
    cout<<res<<endl;
    return res;
}

int main() {
    int n =5000;
    numOfWays(n);
    return 0;
}