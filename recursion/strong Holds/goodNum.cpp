#include <bits/stdc++.h>
using namespace std;

// double goodNum(int n)
// {
//     double ans = 1.0;
//     for (int i = 0; i < n; i++)
//     {
//         if (i % 2 == 0)
//         {
//             ans = ans * 5;
//         }
//         else
//         {
//             ans = ans * 4;
//         }
//     }
//     return ans;
// }
long long MOD = 1e9 + 7;
long long power(long long x ,  int n){
    if(n==0) return 1;
    long long half = power(x, n/2);
    if(n%2==0){
        return (half * half) % MOD;
    }else{
        return (half * half * x) % MOD;
    }
}

long long goodNum(int n){
    long long even = (n + 1) / 2; // Count of even positions
    long long odd = n / 2;        // Count of odd positions
    long long pow5 = power(5, even) % MOD;
    long long pow4 = power(4, odd) % MOD;
    return (pow5 * pow4) % MOD;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    long long result = goodNum(n);
    cout << "The good number for " << n << " is: " << result << endl;
    return 0;
}