#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), ans;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int x : a) {
    if(ans.empty() || x>ans.back()) {
      ans.push_back(x);
    } else {
      auto it = lower_bound(ans.begin(), ans.end(), x);
      *it = x;
    }
  }
  //now the size of ans vector is the LIS very well, but
  //the vector ans may or may not be a subsequence of initial array
  
  //For eg, a -> 1 4 5 2, then ans -> 1 2 5 -> which is NOT a subsequence of 1 4 5 2
  cout << (int)ans.size() << '\n'; 
  return 0;
}
