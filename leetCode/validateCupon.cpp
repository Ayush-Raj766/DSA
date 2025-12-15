#include<bits/stdc++.h>
using namespace std;

bool isValidString(string& str){
     if (str.empty()) return false;
   for (unsigned char c : str) {
        if (!(isalnum(c) || c == '_')) {
            return false;
        }
    }
    return true;
}

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive){

     unordered_map<string, int> order = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };
     vector<vector<string>> buckets(4);

    int n = code.size();

    for(int i = 0 ; i< n; i++){
        if(!isActive[i]) continue;
        if(!isValidString(code[i])) continue;
        if (!order.count(businessLine[i])) continue;

        buckets[order[businessLine[i]]].push_back(code[i]);
    }

    vector<string> res;
    for (int i = 0; i < 4; i++) {
        sort(buckets[i].begin(), buckets[i].end());
        res.insert(res.end(), buckets[i].begin(), buckets[i].end());
    }

    return res;
}

int main() {
    vector<string>  code ={"GROCERY15","ELECTRONICS_50","DISCOUNT10"};
    vector<string> businessLine = {"grocery","electronics","invalid"};
    vector<bool> isActive = {false,true,true};

     vector<string> ans = validateCoupons(code, businessLine, isActive);

    for (auto& s : ans) {
        cout << s << " ";
    }

    return 0;
}