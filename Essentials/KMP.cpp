	#include <bits/stdc++.h>

using namespace std;
#define int long long

void LPS(string s, vector<int> lps)

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  cin >> s;
  int n = s.size();

  int lps[n+1];
  int i = 0, j = -1;
  lps[0] = -1;

  while(i < n) {
    while(j!=-1 && s[j]!=s[i]) {
      j = lps[j];
    }
    i++;
    j++;
    lps[i] = j;
  }

  for(int i = 1; i <= n; i++) {
    cout << lps[i] << " ";
  }
  cout << '\n';
  return 0;
}
