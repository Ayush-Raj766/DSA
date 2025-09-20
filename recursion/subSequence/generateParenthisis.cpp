#include<bits/stdc++.h>
using namespace std;

void generateParentheses(int n , int open , int close , string current , vector<string> &result){
    if(current.size() == 2*n){
        result.push_back(current);
        return;
    }

    if(open < n){
        generateParentheses(n , open+1 , close , current +"(" , result);
    }
    if(close < open){
        generateParentheses(n , open , close+1 , current +")" , result);
    }
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;
    vector<string> result;
    generateParentheses(n, 0, 0, "", result);
    cout << "Generated Parentheses: " << endl;
    for (auto s : result) {
        cout << s << endl;
    }
    return 0;
}