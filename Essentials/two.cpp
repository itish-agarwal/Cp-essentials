#include <bits/stdc++.h>

using namespace std;
using lli = long long;

const int nax = 1e5 + 66;
int n, D, arr[nax];

map<lli, lli> compVal;

int t[4*nax];
#define mid ((l+r)/2)

void update(int index, int l, int r, int pos, int val) {
  if(pos<l || pos>r) {
    return;
  }
  if(l==r) {
    t[index] = max(t[index], val);
    return;
  }
  int mid = (l+r)/2;
  update(2*index, l, mid, pos, val);
  update(2*index+1, mid+1, r, pos, val);
  t[index] = max(t[2*index], t[2*index+1]);
}
int query(int index, int l, int r, int lq, int rq) {
  if(lq>r || l>rq) {
    return 0;
  }
  if(lq<=l && r<=rq) {
    return t[index];
  }
  int mid = (l+r)/2;
  return max(query(2*index, l, mid, lq, rq), query(2*index+1, mid+1, r, lq, rq));
} 
#undef mid

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    compVal[arr[i]];
  }
  cin >> D;
  int cnt = 0;
  for(auto &it : compVal) {
    it.second = cnt++;
  }

  int dp[n];
  int ans = 0;
  memset(dp, sizeof(dp), 0);
  for(int i = 0; i < n; i++) {
    int lo = arr[i]-D;
    int hi = arr[i]+D;
    auto it = compVal.upper_bound(hi);
    --it;
    hi = it->second;
    it = compVal.lower_bound(lo);
    lo = it->second;

    dp[i] = query(1, 0, cnt, lo, hi);

    update(1, 0, cnt, compVal[arr[i]], dp[i]);
    ans = max(ans, dp[i]);
  }
