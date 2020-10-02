#include <bits/stdc++.h>
using namespace std;

int max_subarray(vector <int> &v){
    int max_now = v[0], max_global = v[0];
    for(int i = 1; i < v.size(); i++){
        max_now = max(max_now + v[i], v[i]);
        max_global = max(max_now, max_global);
    }
    return max_global;
}

int main(){
    int n;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    cout << max_subarray(v) << '\n';

}
