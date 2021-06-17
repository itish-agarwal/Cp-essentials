#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 1e9 + 7;

void add_self(int& a, int b) {
  a = (a + b) % mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  function<int(int, int)> power = [&](int A, int B) {
    int res = 1;
    while(B > 0) {
      if(B & 1) {
        res = (res * A) % mod;
      }
      A = (A * A) % mod;
      B /= 2;
    }
    return res;
  };
  int tests;
  cin >> tests;
  while(tests--) {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(N + 1, vector<int> (2));
    dp[0][0] = dp[0][1] = 1;
    dp[1][1] = 21;
    dp[1][0] = 5;

    int S = (K == 1 ? 105 : 130);

    for(int i = 2; i <= N; i++) {
      dp[i][1] = (21LL * (dp[i - 1][1] + dp[i - 1][0])) % mod;

      dp[i][0] = S;
      if(i - K >= 0) {
        S = (S - (power(5LL, K ) * dp[i - K][1]) % mod + mod) % mod;
      }
      S = (5LL * S + 5LL * dp[i][1]) % mod;
    }
    
    int ans = (dp[N][0] + dp[N][1]) % mod;
    if(K == 0)
      ans = power(21LL, N);
    cout << ans << '\n';
  }
  return 0;
}
