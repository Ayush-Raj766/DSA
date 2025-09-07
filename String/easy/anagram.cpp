#include<bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cout<<"Enter first string: ";
    cin>>s1;
    cout<<"Enter second string: ";
    cin>>s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 == s2) {
        cout<<"Strings are anagrams of each other"<<endl;
    } else {
        cout<<"Strings are not anagrams of each other"<<endl;
    }
    return 0;
}