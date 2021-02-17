#include <bits/stdc++.h>

using namespace std;

struct tree {
  vector<vector<int>> g;
  const int MAXLOG = 30;
  vector<vector<int>> par, dp;
  vector<int> h, a;
  int n;
  tree(int _n) {
    n = _n;
    g.resize(_n + 2);
    par = vector<vector<int>> (_n+2, vector<int> (MAXLOG, -1));
    dp = vector<vector<int>> (_n+2, vector<int> (MAXLOG, 0));
    h = vector<int> (_n+2, 0);
    a = vector<int> (_n+2);
  }
  void add_edge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }
  void dfs(int v, int p = -1) {
    par[v][0] = p;
    dp[v][0] = a[v];
    if(p + 1) h[v] = h[p] + 1;
    for(int i = 1; i < MAXLOG; ++i) {
      if(par[v][i-1] + 1) {
        par[v][i] = par[par[v][i-1]][i-1];
        dp[v][i] = __gcd(dp[v][i-1], dp[par[v][i-1]][i-1]);
      }
    }
    for(auto u : g[v]) {
      if(u != p) {
        dfs(u, v);
      }
    }
  }
  int GCD(int v, int u) {
    if(h[v] < h[u]) swap(v, u);
    int answer = 0;
    for(int i = MAXLOG - 1; i >= 0; --i) {
      if(par[v][i] + 1 && h[par[v][i]] >= h[u]) {
        answer = __gcd(answer, dp[v][i]);
        v = par[v][i];
      }
    }
    //now h[v] = h[u]
    if(v == u) return __gcd(answer, a[v]);
    for(int i = MAXLOG - 1; i >= 0; --i) {
      if(par[v][i] - par[u][i]) {
        answer = __gcd(answer, dp[v][i]);
        v = par[v][i];
        answer = __gcd(answer, dp[u][i]);
        u = par[u][i];
      }
    }
    return __gcd(answer, __gcd(a[u], __gcd(a[v], a[par[v][0]])));
  }
  void run_dfs() {
    dfs(1, -1);
  }
  int get_gcd(int v, int u) {
    return GCD(v, u);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    tree t(n);
    for(int i = 1; i <= n; ++i) {
      cin >> t.a[i];
    }
    for(int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      t.add_edge(u, v);
    }
    t.run_dfs();
    int q;
    cin >> q;
    while(q--) {
      int u, v;
      cin >> u >> v;
      cout << t.get_gcd(u, v) << '\n';
    }
  }
}

