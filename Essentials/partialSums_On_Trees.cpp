#include <bits/stdc++.h>

using namespace std;
#define int long long

struct tree {
  vector<vector<int>> g;
  const int MAXLOG = 30;
  vector<vector<int>> par;
  vector<int> h, a;
  int n;
  tree(int _n) {
    n = _n;
    g.resize(_n + 2);
    par = vector<vector<int>> (_n+2, vector<int> (MAXLOG, -1));
    h = vector<int> (_n+2, 0);
    a = vector<int> (_n+2, 0);
  }
  void add_edge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }
  void Ldfs(int v, int p = -1) {
    par[v][0] = p;
    if(p + 1) h[v] = h[p] + 1;
    for(int i = 1; i < MAXLOG; ++i) {
      if(par[v][i-1] + 1) {
        par[v][i] = par[par[v][i-1]][i-1];
      }
    }
    for(auto u : g[v]) {
      if(u != p) {
        Ldfs(u, v);
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
  void run_Ldfs() {
    Ldfs(1, -1);
  }
  void query(int u, int v, int val) {
    a[u] += val;
    a[v] += val;
    int lca = LCA(u, v);
    a[lca] -= val;
    int plca = par[lca][0];
    if(plca > -1) {
      a[plca] -= val;
    }
  }
  void dfs(int u, int p = -1) {
    for(auto v : g[u]) {
      if(v != p) {
        dfs(v, u);
      }
    }
    if(p > -1) {
      a[p] += a[u];
    }
  }  
  void run_dfs() {
    dfs(1, -1);
  }    
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    tree t(n);
    for(int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      t.add_edge(u, v);
    }
    t.run_Ldfs();
    int q;
    cin >> q;
    while(q--) {
      int u, v, val;
      cin >> u >> v >> val;
      t.query(u, v, val);
    }
    t.run_dfs();
    for(int i = 1; i <= n; ++i) {
      cout << t.a[i] << " ";
    }
    cout << '\n';
  }
}

