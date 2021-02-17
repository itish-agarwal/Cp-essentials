#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

string L, R; ll d;
int len;

//do not take tight bound for low, it is anyway 1;

ll dp[10002][2][2][101];

void add_self(ll& a, ll b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

ll rec(ll id, ll lo, ll hi, ll rem) {
  if(id == len) {
    return rem==0;
  }
  if(dp[id][lo][hi][rem]==-1) {
    ll ans = 0;
    int loLim = 0, hiLim = 9;
    if(hi) {
      hiLim = R[id]-'0';
    }
    if(lo) {
      loLim = L[id]-'0';
    }
    for(int i = loLim; i <= hiLim; i++) {
      ll newHigh = hi;
      ll newLow = lo;
      if(i!=hiLim) {
        newHigh = 0;
      }
      if(i!=loLim) {
        newLow = 0;
      }
      ll newRem = (rem + i)%d;
      add_self(ans, rec(id+1, newLow, newHigh, newRem));
    }
    dp[id][lo][hi][rem] = ans;
  }
  return dp[id][lo][hi][rem];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> L >> R >> d;
  while((int)L.size() < (int)R.size()) {
    L = '0' + L;
  }
  //L = string('0', (int)R.size()-(int)L.size()) + L;
  len = R.size();
  memset(dp, -1, sizeof(dp));
  ll ans = rec(0, 1, 1, 0);
  cout << ans << '\n';
  return 0;
}
  
  
