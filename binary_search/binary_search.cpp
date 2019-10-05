#include <bits/stdc++.h>
using namespace std;

int binary_search(vector < int > &a, int n, int k){
  int l = 0, r = n-1;
  while(l<=r){
    int m = (l+r)/2;
    if(a[m] == k) return m;
    else if(k < a[m]) r = m-1;
    else l = m+1;
  }
  return -1;
}

int main(){
  int n;
  cin >> n;
  vector < int > v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  int k;
  while(cin >> k){
    int resp = binary_search(v, n, k);
    if(resp==-1) cout << "Not found" << endl;
    else cout << "Found it in position " << resp << endl;
  }
  return 0;
}
