#include <bits/stdc++.h>

using namespace std;
#define int long long

const int nax = 1e5 + 678;
vector<vector<int>> g(nax);
int N, s, a[nax], par[nax], indp[nax], outdp[nax], sum_sub[nax];

// finds indp and sum of a subtree
void dfs1(int u, int p) {
  sum_sub[u] = a[u];
  indp[u] = 0;
  par[u] = p;
  for(auto v : g[u]) {
    if(v!=p) {
      dfs1(v, u);
      sum_sub[u] += sum_sub[v];
      indp[u] += indp[v] + sum_sub[v];
    }
  }
}
// fills outdp
void dfs2(int u, int p) {
  if(p == -1) {
    outdp[u] = 0;
  } else {
    outdp[u] = outdp[p] + s - sum_sub[p] + indp[p] - indp[u] - sum_sub[u] + sum_sub[p] - sum_sub[u];
  }
  for(auto v : g[u]) {
    if(v!=p) {
      dfs2(v, u);
    }
  }
}    
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    s = 0;
    cin >> N;
    for(int i = 0; i <= N; i++) {
      g[i].clear();
    }
    for(int i = 1; i <= N; i++) {
      cin >> a[i];
      s += a[i];
    }
    for(int i = 1; i < N; i++) {
      int u, v;
      cin >> u >> v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1);  
    set<int> m;
    for(int i = 1; i <= N; i++) {
      m.insert(indp[i] + outdp[i]);
    }
    cout << *m.rbegin() << " " << *m.begin() << '\n';
  }
  return 0;
}

