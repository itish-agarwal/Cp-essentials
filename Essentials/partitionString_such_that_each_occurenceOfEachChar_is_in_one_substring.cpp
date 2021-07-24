
#include <bits/stdc++.h>

using namespace std;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while(tests--) {
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> mp;
    for(int i = 0; i < n; i++) {
      mp[s[i]] = i;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
      int to = mp[s[i]];
      int j = i;
      while(j<n && j<=to) {
        to = max(to, mp[s[j]]);
        j++;
      }
      ans.push_back(j-i);
      i = j-1;
    }
    for(int x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
  return 0;
}

