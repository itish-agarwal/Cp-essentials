#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

string a; ll d;
int len;

//do not take tight bound for low, it is anyway 1;

ll dp[10002][2][101];

void add_self(ll& a, ll b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

ll rec(ll id, ll hi, ll rem) {
  if(id == len) {
    return rem==0;
  }
  if(dp[id][hi][rem]==-1) {
    ll ans = 0;
    int loLim = 0, hiLim = 9;
    if(hi) {
      hiLim = a[id]-'0';
    }
    for(int i = loLim; i <= hiLim; i++) {
      ll newHigh = hi;
      if(i!=hiLim) {
        newHigh = 0;
      }
      ll newRem = (rem + i)%d;
      add_self(ans, rec(id+1, newHigh, newRem));
    }
    dp[id][hi][rem] = ans;
  }
  return dp[id][hi][rem];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> d;
  len = a.size();
  memset(dp, -1, sizeof(dp));
  cout << (rec(0, 1, 0)-1+mod)%mod << '\n';
  return 0;
} 
  
