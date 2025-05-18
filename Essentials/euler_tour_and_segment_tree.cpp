/*
You are given a rooted tree consisting of n nodes. The nodes are numbered 
1,2,... ,n, and node 1 is the root. Each node has a value.
Your task is to process following types of queries:

1. Change the value of node s to x
2. Calculate the sum of values in the subtree of node s

https://cses.fi/problemset/task/1137/
*/

#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
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
 
vector<vector<int>> edges;
vector<int> e;
 
void dfs(int u, int p) {
  e.push_back(u);
  for(int v : edges[u]) {
    if(v != p) {
      dfs(v, u);
    }
  }
  e.push_back(u);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int N, Q;
  cin >> N >> Q;
 
  vector<int> val(N);
  for(int i = 0; i < N; i++) {
    cin >> val[i];
  }
 
  edges.resize(N);
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
 
  dfs(0, -1);
 
  vector<int> start(N, -1), last(N, -1);
 
  for(int i = 0; i < N + N; i++) {
    if(start[e[i]] == -1) {
      start[e[i]] = i;
    } else {
      last[e[i]] = i;
    }
  }
  segtree tree(N + N);
  for(int i = 0; i < N + N; i++) {
    int node = e[i];
    if(start[node] == i) {
      tree.update(1, 0, N + N - 1, i, val[node]);
    }
  }
  while(Q--) {
    int tt;
    cin >> tt;
    if(tt == 1) {
      int node, v;
      cin >> node >> v;
      node -= 1;
      int in = start[node];
      tree.update(1, 0, N + N - 1, in, v);
    } else {
      int node;
      cin >> node;
      node -= 1;
      cout << tree.query(1, 0, N + N - 1, start[node], last[node]) << '\n';
    }
  }
}