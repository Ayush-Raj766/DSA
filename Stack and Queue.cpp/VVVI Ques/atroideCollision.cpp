#include<bits/stdc++.h>
using namespace std;

vector <int> asteroidCollision(vector <int> & atro){
    int n =atro.size();
    stack<int>st;
    for(int i = 0 ;i<n;i++){
        bool distoryed = false;
        while(!st.empty() && st.top()>0 && atro[i]<0){
            if(abs(st.top()) < abs(atro[i])){
                st.pop();
                continue;
            }
            if(abs(st.top()) == abs(atro[i])){
                st.pop();
            }

            distoryed = true;
            break;
        }
         if (!distoryed) {
            st.push(atro[i]);
        }
    }
    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }

    return result;
} 

int main() {
    vector<int> asteroids = {5, 10, -5}; // you can change input here
    vector<int> result = asteroidCollision(asteroids);

    cout << "Final state of asteroids: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}