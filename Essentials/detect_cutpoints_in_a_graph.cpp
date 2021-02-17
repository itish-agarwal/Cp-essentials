#include <bits/stdc++.h>

using namespace std;

struct graph {
  int n, timer;
  set<int> cuts;
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
    cuts.clear();
  }
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  void dfs(int a, int parent = -1) {
    visited[a] = true;
    tin[a] = low[a] = timer++;
    int children = 0;
    for(auto b : g[a]) {
      if(b != parent) {
        if(visited[b]) {
          low[a] = min(low[a], tin[b]);
        } else {
          dfs(b, a);
          low[a] = min(low[a], low[b]);
          if(low[b] >= tin[a] && parent != -1) {
            //cout << "CUTS " << a << '\n';
            cuts.insert(a);
          }
          ++children;
        }
      }
    }
    if(parent == -1 && children > 1) {
      //cout << "CUTS " << a << '\n';
      cuts.insert(a);
    }
  }  
  int get_cutpoints() {
    for(int i = 1; i <= n; ++i) {
      if(!visited[i]) {
        dfs(i);
      }
    }
    return (int)cuts.size();
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while(1) {
    int n, m;
    cin >> n >> m;
    if(!n && !m) goto done;
    graph g(n);
    while(m--) {
      int u, v;
      cin >> u >> v;
      g.add_edge(u, v);
    }
    cout << g.get_cutpoints() << '\n';
  }
  done: return 0;
}
