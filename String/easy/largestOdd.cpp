#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout<<"enter the string: ";
    getline(cin , s);
    int n = s.length();
    for(int i =n-1 ; i>=0 ; i--){
        if((s[i])%2!=0){
            if(s[0] == '0'){
                cout << "Largest odd number: " << s.substr(1 , i) << endl;
            }
            else{
                cout << "Largest odd number: " << s.substr(0 , i+1) << endl;
            }
            return 0;
        }
    }
    cout << "No odd number found" << endl;
    return 0;
}