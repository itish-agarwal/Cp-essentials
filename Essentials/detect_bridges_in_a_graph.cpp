#include <bits/stdc++.h>

using namespace std;

struct graph {
  int n, timer;
  vector<vector<int>> g;
  vector<pair<int, int>> bridges;
  vector<int> visited, tin, low;
  graph(int _n) {
    n = _n;
    g.resize(_n + 2);
    visited.resize(_n + 2);
    tin.assign(_n + 2, -1);
    low.assign(_n + 2, -1);
    timer = 0;
  }
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  void dfs(int a, int parent = -1) {
    visited[a] = true;
    tin[a] = low[a] = timer++;
    for(int b : g[a]) {
      if(b != parent) {
        if(visited[b]) {
          low[a] = min(low[a], tin[b]);
        } else {
          dfs(b, a);
          low[a] = min(low[a], low[b]);
          if(low[b] > tin[a]) {
            bridges.emplace_back(min(a, b), max(a, b));
          }
        }
      }
    }
  }
  vector<pair<int, int>> get_bridges() {
    for(int i = 1; i <= n; ++i) {
      if(!visited[i]) {
        dfs(i);
      }
    }
    sort(bridges.begin(), bridges.end());
    return bridges;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int nr = 1; nr <= tt; nr++) {
    int n, m;
    cin >> n >> m;
    graph g(n);
    while(m--) {
      int u, v;
      cin >> u >> v;
      g.add_edge(u, v);
    }
    vector<pair<int, int>> ans = g.get_bridges();
    cout << "Caso #" << nr << '\n';
    if(ans.empty()) {
      cout << "Sin bloqueos\n";
    } else {      
      cout << (int)ans.size() << '\n';
      for(auto it : ans) {
        cout << it.first << " " << it.second << '\n';
      }
    }
  }
}
