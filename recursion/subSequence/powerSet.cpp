#include<bits/stdc++.h>
using namespace std;

void powerSet(string s , string f , int i){
    if(i == s.length()){
        cout << f << " ";
        return;
    }
    f = f + s[i];
    powerSet(s , f , i+1);
    f.pop_back();
    powerSet(s , f , i+1);

}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    powerSet(str , "", 0);
    return 0;
}