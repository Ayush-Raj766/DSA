#include<bits/stdc++.h>
using namespace std;

int smallestRepunitDivByK(int k) {
if(k %2 == 0 || k %5 ==0){
    return -1;
}
int n =1;
int length =1;

while(n % k != 0){
    n= (n*10 +1)%k;
    length++;
    
}
    return length;
}

int main() {
    int k ;
    cout<<"enter nor=";
    cin>>k;
    smallestRepunitDivByK(k);
    cout<<smallestRepunitDivByK(k);
    return 0;
}