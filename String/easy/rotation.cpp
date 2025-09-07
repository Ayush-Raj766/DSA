#include<bits/stdc++.h>
using namespace std;
bool isRotation(string s1 , string s2){
    if(s1.length()!= s2.length()) return false;
    for(int i = 0 ; i<s1.length() ; i++){
        s1 = s1 + s1[0];
        s1.erase(0,1);
        if(s1 == s2) {
            return true;
        }
    }
    // int temp = s1[0];
    // for(int i = 0 ; i<s1.length() ;i++){
    //     s1[i] = s1[i+1];
        
    // }
    // s1[s1.length()-1] = temp;
    // if(s1 == s2) {
    //         return true;
    //     }
    return false;
}
int main() {
    string s1, s2;
    cout<<"Enter  string: ";
    cin>>s1;
    cout<<"Enter goal string: ";
    cin>>s2;
    if(isRotation(s1, s2)) {
        cout<<"Strings are rotation of each other"<<endl;
    } else {
        cout<<"Strings are not rotation of each other"<<endl;
    }
    return 0;
}