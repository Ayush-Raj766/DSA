#include <bits/stdc++.h>
using namespace std;

// Helper function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;         // 0 and 1 are not prime
    if (n == 2) return true;         // 2 is prime
    if (n % 2 == 0) return false;    // even numbers >2 are not prime

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> queries = {{2, 9}, {4, 7}};
    vector<int> result;

    // Process each query
    for (auto &q : queries) {
        int L = q[0], R = q[1];
        int count = 0;

        for (int i = L; i <= R; i++) {
            if (isPrime(i)) count++;
        }

        result.push_back(count);
    }

    // Print output
    cout << "[ ";
    for (int x : result) cout << x << " ";
    cout << "]" << endl;

    return 0;
}
