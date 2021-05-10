/*You are given a tree of N nodes numbered from 1 to N. 
The ith edge connecting node ui and vi has a weight of wi.

Your target is to handle the queries of the following two types:

"1 i c" : Update the weight of ith edge with the new weight c. 
(1 represents the query type).

"2 u v" : Find the length of the path from node u to v. 
(2 represents the query type).
*/

#include <bits/stdc++.h>

using namespace std;

struct segtree {
  vector<int> t;
  segtree(int _n) {
    //initialise t
    t.resize(4*_n);
  }
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] = val;
      return;
    }
    int mid = (l + r)/2;
    if(pos <= mid) {
      update(2*id, l, mid, pos, val);
    } else {
      update(2*id+1, mid+1, r, pos, val);
    }
    //update t[id] here;
    t[id] = t[2*id] + t[2*id + 1];
  }
  //change return type of query if wanted
  int query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) return 0;//see to this
    if(lq <= l && r <= rq) return t[id];
    int mid = (l + r)/2;
    int L = query(2*id, l, mid, lq, rq);
    int R = query(2*id+1, mid+1, r, lq, rq);
    return L + R;
  }
};

const int nax = 1e5 + 7;
const int LOG = 25;

vector<vector<int>> g(nax);
vector<int> tour, depth(nax), par(nax);
vector<vector<int>> up(nax, vector<int> (LOG));

void dfs(int u, int parent) {
  par[u] = parent;
  tour.push_back(u);
  for(auto v : g[u]) {
    if(v != parent) {
      up[v][0] = u;
      depth[v] = depth[u] + 1;
      for(int j = 1; j < LOG; j++) {
        up[v][j] = up[ up[v][j - 1] ][j - 1];
      }
      dfs(v, u);
    }
  }
  tour.push_back(u);
}
int get_lca(int a, int b) {
  if(depth[b] > depth[a]) swap(a, b);
  int k = depth[a] - depth[b];
  for(int j = LOG - 1; j >= 0; j--) {
    if(k & (1 << j)) {
      a = up[a][j];
    }
  }
  if(a == b) {
    return a;
  }
  for(int j = LOG - 1; j >= 0; j--) {
    if(up[a][j] != up[b][j]) {
      a = up[a][j];
      b = up[b][j];
    }
  }
  return par[a];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;

  vector<tuple<int, int, int>> edges;
  for(int i = 1; i < N; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.emplace_back(u, v, w);
  }
  for(int i = 0; i <= N; i++) {
    par[i] = 1;
    for(int j = 0; j < LOG; j++) {
      up[i][j] = 1;
    }
  }

  dfs(1, -1);

  map<int, int> B, E;

  for(int i = 1; i <= N; i++) B[i] = E[i] = -1;

  for(int i = 0; i < (int)tour.size(); i++) {
    int node = tour[i];
    if(B[node] == -1) B[node] = i;
    E[node] = i;
  }

  vector<int> A(N + N);

  map<int, int> store;
  for(auto it : edges) {
    int u = get<0>(it), v = get<1>(it), w = get<2>(it);
    if(depth[u] > depth[v]) {
      store[u] = w;
    } else {
      store[v] = w;
    }
  }

  for(int i = 1; i <= N; i++) {
    A[B[i]] = store[i];
    A[E[i]] = -store[i];
  }

  segtree tree(N + N);
  for(int i = 0; i < N + N; i++) {
    tree.update(1, 0, N + N - 1, i, A[i]);
  } 

  int qq;
  cin >> qq;

  while(qq--) {
    int op;
    cin >> op;
    if(op == 1) {
      int i, c;
      cin >> i >> c;
      --i;
      int u = get<0>(edges[i]);
      int v = get<1>(edges[i]);
      int w = get<2>(edges[i]);
      if(depth[u] > depth[v]) {
        tree.update(1, 0, N + N - 1, B[u], c);
        tree.update(1, 0, N + N - 1, E[u], -c);
      } else {
        tree.update(1, 0, N + N - 1, B[v], c);
        tree.update(1, 0, N + N - 1, E[v], -c);
      }
    } else {
      int u, v;
      cin >> u >> v;  

      int lca = get_lca(u, v);

      int b = B[lca] + 1;
      int answer = 0;

      int e = B[u];
      answer += tree.query(1, 0, N + N - 1, b, e);

      e = B[v];
      answer += tree.query(1, 0, N + N - 1, b, e);
      cout << answer << '\n';
    }
  }
}