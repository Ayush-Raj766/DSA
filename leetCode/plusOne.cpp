#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits){
    int n = digits.size();
    for(int i = n-1 ; i>=0 ; i--){
        if(digits[i]<9){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    vector<int> digits = {9};
    plusOne(digits);
    for(int i = 0 ; i<digits.size() ; i++){
        cout<<digits[i]<<" ";
    }
    return 0;
}