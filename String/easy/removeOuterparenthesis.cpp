#include<bits/stdc++.h>
using namespace std;

string RemoveOuterParentheses(string s , int n){
    string result = "";
    int d = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(d>0){
                result+=s[i];
            }
            d++;
        }
        else{
            d--;
            if(d>0){
                result +=s[i];
            }
        }
    }
    return result;
}

int main() {
    int n ;
    cout<<"size of string: ";
    cin>>n;
    string s;
    cout<<"enter the string: ";
    cin>>s;

    cout<<"Resultant string: "<<RemoveOuterParentheses(s ,n)<<endl;
    return 0;
}