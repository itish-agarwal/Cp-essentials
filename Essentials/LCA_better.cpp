/*
int up[N][LOG];
up[i][j] -> 2^j th ancestor of i
for v = 0 .... N-1
up[v][0] = parent[v];
up[v][1] = up[up[v][0]][0];
up[v][2] = up[up[v][1]][1];
and so on...*/

#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 10000;
const int LOG = 17;
vector<int> children[MAX_N];
int up[MAX_N][LOG], depth[MAX_N];

void dfs(int a) {
  for(int b : children[a]) {
    up[b][0] = a;
    depth[b] = depth[a] + 1;
    for(int j = 1; j < LOG; j++) {
      up[b][j] = up[ up[b][j-1] ][j-1];
    }
    dfs(b);
  }
}
int get_lca(int a, int b) {
  //make a deeper
  if(depth[b] > depth[a]) swap(a, b);
  int k = depth[a] - depth[b];
  for(int j = LOG - 1; j >= 0; j--) {
    if(k & (1 << j)) {
      a = up[a][j];
    }
  }
  if(a == b) return a;
  for(int j = LOG - 1; j >= 0; j--) {
    if(up[a][j] != up[b][j]) {
      a = up[a][j];
      b = up[b][j];
    }
  }
  return up[a][0];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int v = 0; v < n; v++) {
    int cnt;
    cin >> cnt;
    while(cnt--) {
      int c;
      cin >> c;
      children[v].push_back(c);
    }
  }
  dfs(0);
  int qq;
  cin >> qq;
  while(qq--) {
    int a, b;
    cin >> a >> b;
    cout << get_lca(a, b) << '\n';
  }
}