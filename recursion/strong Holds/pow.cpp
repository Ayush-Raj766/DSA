#include<bits/stdc++.h>
using namespace std;

// double power(double x , int n){
//     if(n==0) return 1.0;
//     double ans = 1.0;
//     for(int i = 1;i<=n;i++){
//         ans = ans * x;
//     }
//     return ans;
// }

double power(double x ,  int n){
    if(n==0) return 1.0;
    double half = power(x, n/2);
    if(n%2==0){
        return half * half;
    }else{
        return half * half * x;
    }
}

int main() {
    int n;
    double x;
    cout << "Enter a number and its exponent: ";
    cin >> x >> n;
    double result = power(x, n);
    cout << x << " raised to the power of " << n << " is " << result << endl;
    return 0;
}