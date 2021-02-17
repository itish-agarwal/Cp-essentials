#include <bits/stdc++.h>

using namespace std;
#define int long long

const int nax = 1e5 + 78;
vector<vector<int>> g(nax);
int n, k, u, v;

// for a node u, find number of vertices in its subtree such that 
// dist(i, u) == j;
void dfs1(int u, int p, int indp[][505]) {
  for(int i = 0; i <= k; i++) {
    indp[u][i] = 0;
  }
  indp[u][0] = 1;
  for(auto v : g[u]) {
    if(v!=p) {
      dfs1(v, u, indp);
      for(int i = 1; i <= k; i++) {
        indp[u][i] += indp[v][i-1];
      }
    }
  }
}
void dfs2(int u, int p, int indp[][505], int outdp[][505]) {
  for(int i = 0; i <= k; i++) {
    outdp[u][i] = 0;
  }
  if(p!=-1) {
    outdp[u][1] = 1;
    for(int i = 2; i <= k; i++) {
      outdp[u][i] = outdp[p][i-1] + (indp[p][i-1] - indp[u][i-2]);
    }
  }
  for(auto v : g[u]) {
    if(v!=p) {
      dfs2(v, u, indp, outdp);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n >> k;
    for(int i = 0; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++) {
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    // root the tree at node 1
    int indp[n+2][505], outdp[n+2][505];
    dfs1(1, -1, indp);
    dfs2(1, -1, indp, outdp);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += indp[i][k] + outdp[i][k];
    }
    cout << ans / 2 << '\n';
  }
  return 0;
}
    

