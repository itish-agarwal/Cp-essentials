#include <bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e18 + 344;

int n, x, y, z, a[55];
bool done[55][55];
//done[i][j] stores if the range i->j is done or not;

int dp[55][55][55];
//for a particular value of l, r -> calculate for all possible values of xx
int rec(int l, int r, int xx) {
  //optimal cost for merging l->r segment into value xx;
  if(done[l][r]) {
    return dp[l][r][x];
  }
  
  if(l == r) {
    if(a[l]==x) {
      return 0;
    }
    return inf;
  }
  
  for(int i = 0; i < 50; i++) {
    dp[l][r][i] = inf;
  }
  for(int mid = l; mid < r; mid++) {
    for(int fs = 0; fs < 50; fs++) {
      for(int ls = 0; ls < 50; ls++) {
        dp[l][r][(fs*x + ls*y + z)%50] = min(dp[l][r][(fs*x + ls*y + z)%50], dp[l][mid][fs] + dp[mid+1][r][ls] + fs*ls);
      }
    }
  }
  done[l][r] = done;
  return dp[l][r][xx];
}  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x >> y >> z;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = inf;
  for(int i = 0;i < 50 ;i++) {
    ans = min(ans, rec(0, n-1, i));
  }
  cout<<ans<<'\n';
  return 0;
}
   
