#include<bits/stdc++.h>
using namespace std;


vector<string> letterCombinations(string digits , vector<string> &mapping, int index , string current){
    vector<string> result;
    if(digits.empty()) return result;
    if(index == digits.size()){
        result.push_back(current);
        return result;
    }
    string letters = mapping[digits[index] - '0'];
    for(char c : letters){
        vector<string> temp = letterCombinations(digits, mapping, index + 1, current + c);
        result.insert(result.end(), temp.begin(), temp.end());
    }
    return result;
}

int main() {
    
    vector<string> mapping = {
        "",    // 0
        "",    // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs",// 7
        "tuv", // 8
        "wxyz" // 9
    };
    string digits;
    cout << "Enter the digits: ";
    cin >> digits;
    vector<string> ans = letterCombinations(digits , mapping, 0, "");
    cout << "Possible combinations are:\n";
    for (auto &s : ans) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}