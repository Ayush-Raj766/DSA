#include<bits/stdc++.h>
using namespace std;

int x = 31;
int m = 1e9 + 9;
int N = 1e5 + 7;
vector<long long> power(N);
void Power(){
    power[0]=1;
    for(int i = 1; i<N;i++){
        power[i] = (power[i-1] *x)%m;
    }
}
vector <int> search(string pat, string txt){
      Power();
    int t = txt.size();
    int p = pat.size();
    vector<long long> hash(t+1,0);
    for(int i = 0; i<t ; i++){
        hash[i+1] = (hash[i] + (txt[i]-'a'+1)*power[i])%m;
    }

    long long hash_pat = 0;
    for(int i = 0; i<p ; i++){
        hash_pat = (hash_pat + (pat[i]-'a'+1)*power[i])%m;
    }
    vector<int> occurences;
    for( int i =0 ; i + p - 1 < t ;i++){
        long long curr_hash = (hash[i+p] - hash[i] + m)%m;
        if(curr_hash == (hash_pat * power[i])%m){
            occurences.push_back(i);
        }
    }
    return occurences;

}

int main() {
    string text;
    text = "ababcabcababc";
    string pattern;
    pattern = "abc";
    // search(text ,pattern);
    cout << "Pattern found at indices: ";
    vector<int> result = search(pattern, text);
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}