//problem - Given a tree with profits associated
// with each node, find the maximum profit you can take
// by choosing at most k nodes of the tree with the contraint
// that you cannot choose two adjacent nodes

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int nax = 5e3 + 44;
const int inf = 2e18 + 666;
vector<vector<int>> g(nax);
int n, sz[nax], profit[nax];

void dfs(int u, int p, vector<vector<vector<int>>>& dp) {
  sz[u] = 1;
  for(int k = 0; k <= n; k++) {
    for(int j = 0; j < 2; j++) {
      dp[u][j][k] = -inf;
    }
  }
  
  dp[u][0][0] = 0;
  dp[u][1][1] = profit[u];
  
  for(auto v : g[u]) {
    if(v!=p) {
      dfs(v, u, dp);
      for(int i = sz[u]; i >= 0; --i) {
        for(int j = sz[v]; j >= 0; --j) {
          if(dp[u][0][i] > -inf && max(dp[v][0][j], dp[v][1][j]) > -inf) {
            dp[u][0][i+j] = max(dp[u][0][i+j], dp[u][0][i] + max(dp[v][0][j], dp[v][1][j]));
          }
          if(dp[u][1][i] > -inf && dp[v][0][j] > -inf) {
            dp[u][1][i+j] = max(dp[u][1][i+j], dp[u][1][i] + dp[v][0][j]);
          }
        }
      }
      sz[u] += sz[v];
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n;
    for(int i = 0; i <= n; i++) g[i].clear();
    for(int i = 1; i <= n; i++) {
      cin >> profit[i];
    }
    for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (n+1)));
    dfs(1, -1, dp);
    for(int i = 1; i <= n; i++) {
      int res = max(dp[1][0][i], dp[1][1][i]);
      if(res <= -inf) {
        cout << "F ";
      } else {
        cout << res << " ";
      }
    }
    cout << '\n';
  }
  return 0;
}
