#include<bits/stdc++.h>
using namespace std;

bool findDig(int num){
    bool flag = false;
    while(num > 0){
        int dig = num%10;
        if(dig == 3 || dig == 4 || dig == 7) return false;
        if(dig == 2 || dig == 5 || dig == 6 || dig == 9) flag = true;
        num /= 10;
    }
    return flag;
}

int rotatedDigits(int n) {
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(findDig(i)) count++;
    }
    return count;
}

int main() {
    int n = 33 ;
    cout<< rotatedDigits(n);
    return 0;
}