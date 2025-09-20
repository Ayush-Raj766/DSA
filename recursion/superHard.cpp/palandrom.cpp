#include <bits/stdc++.h>
using namespace std;

// Check if a string is palindrome
bool isPalindrome(const string &s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

vector<vector<string>> palPartition(string str, int index, vector<string> current) {
    vector<vector<string>> result;

    // If we reached the end of the string, add current partition
    if (index == str.size()) {
        result.push_back(current);
        return result;
    }

    // Try every possible cut
    for (int i = index; i < str.size(); i++) {
        string sub = str.substr(index, i - index + 1);
        if (isPalindrome(sub)) {
            current.push_back(sub); // choose
            vector<vector<string>> temp = palPartition(str, i + 1, current);
            result.insert(result.end(), temp.begin(), temp.end());
            current.pop_back(); // backtrack
        }
    }

    return result;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    vector<string> current;
    vector<vector<string>> ans = palPartition(str, 0, current);

    cout << "Palindromic partitions are:\n";
    for (auto &vec : ans) {
        cout << "[ ";
        for (auto &part : vec) {
            cout << part << " ";
        }
        cout << "]\n";
    }

    return 0;
}
