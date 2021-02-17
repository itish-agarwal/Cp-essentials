#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> down, up, par, sz;
vector<vector<int>> g;
int n, a, b;

void dfs_one(int a, int parent) {
  down[a] = 0;
  sz[a] = 1LL;
  par[a] = parent;
  for(auto b : g[a]) {
    if(b != parent) {
      dfs_one(b, a);
      down[a] += (down[b] + sz[b]);
      sz[a] += sz[b];
    }
  }
}
void dfs_two(int a, int parent) {
  if(parent == -1) {
    up[a] = 0;
  } else {
    up[a] = up[parent] + (ll)n - sz[parent] + down[parent] - down[a] - sz[a] + sz[parent] - sz[a];
  }
  for(auto b : g[a]) {
    if(b != parent) {
      dfs_two(b, a);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  g.resize(n + 1);
  down.resize(n + 1);
  up.resize(n + 1);
  par.resize(n + 1);
  sz.resize(n + 1);
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs_one(0, -1);
  dfs_two(0, -1);
  for(int i = 0; i < n; ++i) {
    cout << down[i] + up[i] << " " ;
  }
  cout << '\n';
  return 0;
}   
