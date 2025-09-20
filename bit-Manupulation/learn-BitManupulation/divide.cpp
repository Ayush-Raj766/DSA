#include<bits/stdc++.h>
using namespace std;

void  divide(int n , int d){
    int count = 0;
    int sum = 0;
    sum =  sum +d;
    while(sum <= n){
        sum =  sum +d;
        count++;
    }
    cout<<"result = "<<count;
}

int main() {
    int n ,d;
    cout<<"enter number = ";
    cin>>n;
    cout<<"enter divisor = ";
    cin>>d;
    divide(n,d);
    return 0;
}