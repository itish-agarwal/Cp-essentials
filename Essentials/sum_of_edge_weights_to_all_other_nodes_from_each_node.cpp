#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;

#define int long long
vector<vector<pair<int, int>>> g;
vector<int> down, up, sz;
int n;

void dfs_1(int a, int parent) {
  down[a] = 0;
  sz[a] = 1;
  for(auto it : g[a]) {
    int b = it.first;
    int w = it.second;
    if(b != parent) {
      dfs_1(b, a);
      down[a] += (down[b] + w * sz[b]);
      sz[a] += sz[b];
    }
  }
}
void dfs_2(int a, int parent, int w) {
  if(parent != -1) {
   //up[node]=up[p[node]]+((n-sz[node])*road[node])+down[p[node]]-(sz[node]*road[node])-down[node];
   up[a] = up[parent] + (n-sz[a])*w + down[parent] - (sz[a]*w) - down[a];
  }
  for(auto it : g[a]) {
    int b = it.first;
    int w = it.second;
    if(b != parent) {
      dfs_2(b, a, w);
    }
  }
}  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;
  g.resize(n + 1);
  down.resize(n + 1);
  up.resize(n + 1);
  sz.resize(n + 1);
  for(int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  dfs_1(1, -1);
  dfs_2(1, -1, 0);
  for(int i = 1; i <= n; ++i) {
    cout << down[i] + up[i] << " " ;
  }
}
  
