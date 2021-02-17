#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int nax = 17;

ll will_get[(1<<nax)], dp[(1<<nax)];
int n, a[nax][nax];

ll rec(int mask) {
  if(!mask) return 0LL;
  if(dp[mask] <= -1) {
    ll answer = 0;
    for(int submask = mask; submask; submask = (submask-1)&mask) {
      ll maybe = will_get[submask] + rec(mask^submask);
      answer = max(answer, maybe);
    }
    dp[mask] = answer;
  }
  return dp[mask];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  for(int mask = 1; mask < (1<<n); ++mask) {
    int in = -1;
    for(int i = 0; i < n; i++) {
      if(mask>>i & 1) {
        in = i;
        break;
      }
    }
    ll result = 0;
    for(int i = in + 1; i < n; i++) {
      if(mask>>i & 1) {
        result += (ll)a[in][i];
      }
    }
    will_get[mask] = result + will_get[mask^(1<<in)];
  }
  cout << rec((1<<n)-1) << '\n';
  return 0;
} 
    

