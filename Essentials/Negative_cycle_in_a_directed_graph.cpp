#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
const int INF = 2e16 + 7;
 
vector<vector<int>> g;
vector<bool> visited;
 
vector<int> dfs(int u, int dest) {
  if(u == dest) {
    return {u};
  }
  visited[u] = true;
  for(int v : g[u]) {
    if(!visited[v]) {
      vector<int> possible = dfs(v, dest);
      if(!possible.empty()) {
        possible.emplace_back(u);
        return possible;
      }
    }
  }
  return {};
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n, m;
  cin >> n >> m;
 
  vector<tuple<int, int, int>> edges;
 
  g.resize(n + 1);
  visited.resize(n + 1);
 
  while(m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v);
    edges.emplace_back(u, v, w);
  }
 
  vector<int> dist(n + 1, INF);
  dist[1] = 0;
 
  for(int i = 0; i < n - 1; i++) {
    for(auto e : edges) {
      int u = get<0>(e);
      int v = get<1>(e);
      int w = get<2>(e);
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  } 
 
  bool negative_cycle = false;
    
  int vu = -1;

  for(auto e : edges) {
    int u = get<0>(e);
    int v = get<1>(e);
    int w = get<2>(e);
    if(dist[u] + w < dist[v]) {
      vu = u;
      break;
    }
  }
  if(vu == -1) {
    cout << "NO\n";
    return 0;
  }

  for(int i = 0; i <= n; i++) {
    dist[i] = INF;
  }

  dist[vu] = 0;

  vector<int> parent(n + 1);
  int x;

  for(int i = 0; i < n; i++) {
    x = -1;
    for(auto e : edges) {
      int u = get<0>(e);
      int v = get<1>(e);
      int w = get<2>(e);
      if(dist[u] < INF) {
        if(dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          parent[v] = u;
          x = v;
        }
      }
    }
  }

  cout << "YES\n";
  int y = x;
  for(int i = 0; i < n; i++) {
    y = parent[y];
  }
  vector<int> path;
  for(int cur = y; ; cur = parent[cur]) {
    path.emplace_back(cur);
    if(cur == y && (int)path.size() > 1) {
      break;
    }
  }

  reverse(path.begin(), path.end());
  for(int node : path) {
    cout << node << " ";
  }
  cout << '\n';
}