#include <bits/stdc++.h>
 
using namespace std;
 
struct Tree {
 
  //TODO: Do not forget to call run_dfs
  //TODO: Sum of weights may overflow int

  vector<vector<pair<int, int>>> edges;
  int root, N, take_weight_input;
  vector<int> depth, par;
 
  const int LOG = 22;
  vector<vector<int>> up, weights;
 
  //initialise with number of nodes, root
  Tree(int n, int r, bool is_weighted) {
    N = n;
    root = r;
    edges.resize(N);
    take_weight_input = is_weighted;
    up = vector<vector<int>> (N, vector<int> (LOG, r));
    weights = vector<vector<int>> (N, vector<int> (LOG));
    depth.resize(N);
    par.assign(N, r);
  }
 
  void add_edge(int a, int b, int w = 1) {
    //TODO: check here if indexing is correct
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }
 
  void run_dfs() {
    Dfs(root, -1);
  }
 
  void Dfs(int a, int pr) {
    for(auto it : edges[a]) {
      int b = it.first, w = it.second;
      if(b != pr) {
        par[b] = a;
        up[b][0] = a;
        weights[b][0] = w;
        depth[b] = depth[a] + 1;
        for(int j = 1; j < LOG; j++)
          up[b][j] = up[ up[b][j - 1] ][j - 1];
 
        for(int j = 1; j < LOG; j++) 
          weights[b][j] = weights[b][j - 1] + weights[up[b][j - 1]][j - 1];
        Dfs(b, a);
      }
    }
  }
 
  //returns pair -> lca, dist between two nodes
  pair<int, int> lca_dist(int a, int b) {
    //Assumes a and b are 0 indexed
    if(depth[b] > depth[a])
      swap(a, b);
 
    int res = 0, k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; j--) {
      if(k & (1 << j)) {
        res += weights[a][j];
        a = up[a][j];
      }
    }
 
    if(a == b)
      return make_pair(a, res);
 
    for(int j = LOG - 1; j >= 0; j--) {
      if(up[a][j] != up[b][j]) {
        res += weights[a][j] + weights[b][j];
        a = up[a][j];
        b = up[b][j];
      }
    }
    return make_pair(par[a], res + weights[a][0] + weights[b][0]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int N, qq;
  cin >> N >> qq;
 
  Tree T(N, 0, false);
 
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    T.add_edge(a, b);
  }
 
  T.run_dfs();
 
  while(qq--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cout << T.lca_dist(a, b).second << '\n';
  }
}