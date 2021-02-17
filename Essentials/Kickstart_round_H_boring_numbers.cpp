#include <bits/stdc++.h>

using namespace std;

int len, dp[20][2][2][505];
string L, R;

bool isprime(int n) {
  if(n == 1) return 0;
  if(n == 2) return 1;
  for(int i = 2; i*i <= n; i++) {
    if(n%i == 0) {
      return 0;
    }
  }
  return 1;
}
int rec(int id, int lo, int hi, int diff) {
  if(id==len) {
    return diff>0 && isprime(diff);
  }
  if(dp[id][lo][hi][diff] <= -1) {
    int ans = 0;
    int loLim = 0, hiLim = 9;
    if(lo) {
      loLim = L[id]-'0';
    }
    if(hi) {
      hiLim = R[id]-'0';
    }
    for(int i = loLim; i <= hiLim; i++) {
      int newLow = lo, newHigh = hi;
      if(i!=loLim) newLow = 0;
      if(i!=hiLim) newHigh = 0;
      if((len-id) % 2) {
        ans += rec(id+1, newLow, newHigh, diff - i);
      } else {
        ans += rec(id+1, newLow, newHigh, diff + i);
      }
    }
    dp[id][lo][hi][diff] = ans;    
  }
  return dp[id][lo][hi][diff];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> L >> R;
    len = L.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0) << '\n';
  }
  return 0;
}
    
    
