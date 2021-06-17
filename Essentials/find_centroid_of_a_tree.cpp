#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<int> sz;

int dfs(int u, int p) {
  sz[u] = 1;
  for(int v : edges[u]) {
    if(v != p) {
      sz[u] += dfs(v, u);
    }
  }
  return sz[u];
}
int dfs_2(int u, int p, int n) {
  for(int v : edges[u]) {
    if(v != p && sz[v] > n / 2) {
      return dfs_2(v, u, n);
    }
  }
  return u;
} 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  edges.resize(N);
  sz.resize(N);

  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int n = dfs(0, -1);
  int centroid = dfs_2(0, -1, n);
  cout << centroid + 1 << '\n';
}

