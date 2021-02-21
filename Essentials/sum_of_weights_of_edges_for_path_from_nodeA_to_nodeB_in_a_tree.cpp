#include <bits/stdc++.h>

using namespace std;
#define int long long
const int nax = 1e5 + 7;
vector<vector<pair<int, int>>> g(nax);

const int MAXLOG = 31;
int par[nax][MAXLOG];
int h[nax];

void dfs(int v, int p = -1) {
  par[v][0] = p;
  if(p + 1) h[v] = h[p] + 1;
  for(int i = 1; i < MAXLOG; ++i) {
    if(par[v][i-1] + 1) {
      par[v][i] = par[par[v][i-1]][i-1];
    }
  }
  for(auto u : g[v]) {
    if(u.first != p) {
      dfs(u.first, v);
    }
  }
}
int LCA(int v, int u) {
  if(h[v] < h[u]) swap(v, u);
  for(int i = MAXLOG - 1; i >= 0; --i) {
    if(par[v][i] + 1 && h[par[v][i]] >= h[u]) {
      v = par[v][i];
    }
  }
  //now h[v] == h[u];
  if(v == u) return v;
  for(int i = MAXLOG - 1; i >= 0; --i) {
    if(par[v][i] - par[u][i]) {
      v = par[v][i];
      u = par[u][i];
    }
  }
  return par[v][0];
}
void dfss(int u, int p, int pre, vector<int>& val) {
  for(auto it : g[u]) {
    if(it.first != p) {
      val[it.first] += pre + it.second;
      dfss(it.first, u, val[it.first], val);
    }
  }
}  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int nr = 1; nr <= tt; nr++) {
    int n, q, root;
    cin >> n >> q >> root;
    memset(h, 0, sizeof(h));
    memset(par, -1, sizeof(par));
    for(int i = 0; i <= n; ++i) g[i].clear();
    for(int i = 1; i < n; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    dfs(root, -1);
    vector<int> val( n + 1 );
    dfss(root, -1, 0, val);
    while(q--) {
      int u, v;
      cin >> u >> v;
      int ans = val[u] + val[v];
      int lca = LCA(u, v);
      ans -= 2*val[lca];
      cout << ans << '\n';
    }
  }
}
    
    

