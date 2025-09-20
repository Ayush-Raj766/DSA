#include<bits/stdc++.h>
using namespace std;

vector<int> primeFactorization(int n){
    vector<int>fact;
    while((n& 1)==0){
        fact.push_back(2);
        n>>=1;
    }
    for(int i=3 ; i*i<=n ; i=i+2){
        while(n%i ==0){
            fact.push_back(i);
            n=n/i;
        }
    }
    if(n>2){
        fact.push_back(n);
    }
    return fact;
}

int main() {
    vector<int> queries = {12, 18, 7};
    vector<vector<int>> result;

    for (int num : queries) {
        result.push_back(primeFactorization(num));
    }

    // Print result
    for (auto &vec : result) {
        cout << "[ ";
        for (int f : vec) cout << f << " ";
        cout << "]\n";
    }
    return 0;
}