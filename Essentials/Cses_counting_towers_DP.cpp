/* idea is -> 
dp[i][0] -> number of ways to build level 1....i such that i + 1 level is not 
linked together
dp[i][1] -> number of ways to build level 1....i such that i + 1 level is linked
(ie, is one tile of width 2);
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  const int nax = 1e6 + 7;
  vector<vector<int>> dp(nax, vector<int> (2, 0));
  dp[0][0] = dp[0][1] = 1;

  for(int i = 1; i < nax; i++) {
    dp[i][0] = (dp[i - 1][1] + 4LL*dp[i - 1][0]) % mod;
    dp[i][1] = (2LL*dp[i - 1][1] + dp[i - 1][0]) % mod;
  }
  
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << '\n';
  }
}

