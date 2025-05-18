/*
A company has n employees, who form a tree hierarchy where each 
employee has a boss, except for the general director.
Your task is to process q queries of the form: who is the lowest 
common boss of employees a and b in the hierarchy?
*/

// https://cses.fi/problemset/task/1688/

#include <bits/stdc++.h>
 
using namespace std;
 
struct segtree {
   vector<int> t;
   segtree(int _n = 1) {
      t.resize(4 * _n); //
   }
 
   int merge(const int& a, const int& b) {
      return a + b; //
   }
 
   void update(int id, int l, int r, int pos, int val) {
      if(l == r) {
         t[id] = val;
         return;
      }
 
      int m = (l + r) >> 1;
      if(pos <= m)
         update(id<<1, l, m, pos, val);
      else
         update(id<<1 | 1, m + 1, r, pos, val);
 
      t[id] = merge(t[id<<1], t[id<<1 | 1]); 
   }
   int query(int id, int l, int r, int lq, int rq) {
      if(lq > rq)
         swap(lq, rq);
 
      if(lq > r || l > rq) 
         return 0; //
 
      if(lq <= l && r <= rq) 
         return t[id];
 
      int m = (l + r) >> 1;
      int L = query(id<<1, l, m, lq, rq);
      int R = query(id<<1 | 1, m + 1, r, lq, rq);
      return merge(L, R);
   }
};
 
struct HLD {
   int n, built = 0;
   vector<vector<int>> edges;
   vector<int> parent, depth, heavy, location;
   vector<int> order, top, values;
   segtree tree;
 
   HLD(int _n, const vector<int> &_values = {}) {
      n = _n;
      top.resize(n);
      edges.resize(n);
      parent.resize(n);
      depth.resize(n);
      heavy.resize(n);
      values = _values;
      location.resize(n);
      iota(top.begin(), top.end(), 0);
      iota(heavy.begin(), heavy.end(), 0);
 
      if(values.empty())
         values.resize(n);
      tree = segtree(n);
   }
 
   HLD(const vector<vector<int>> &_edges, const vector<int> &_values = {}) {
      HLD((int) _edges.size(), _values);
      values = _values;
      edges = _edges;
   }
 
   void add_edge (int a, int b) {
      edges[a].push_back (b);
      edges[b].push_back (a);
   }
 
   int Dfs (int a, int pr) {
      int sz = 1, best = -1;
      for (int b : edges[a]) 
         if (b != pr) {
            parent[b] = a;
            depth[b] = depth[a] + 1;
            int x = Dfs (b, a);
            if (x > best) 
               best = x, heavy[a] = b;
 
            sz += x;
         }
 
      return sz;
   }
 
   void Decompose (int a, int pr) {
      order.push_back (a);
      if (heavy[a] ^ a) {
         top[heavy[a]] = top[a];
         Decompose (heavy[a], a);
      }
 
      for (int b : edges[a])
         if (b != pr && b != heavy[a])
            Decompose (b, a);
   }
 
   void build() {
      Dfs (0, -1);
      Decompose (0, -1);
 
      for (int j = 0; j < n; ++j)
         location[order[j]] = j;
 
      for (int j = 0; j < n; ++j)
         tree.update (1, 0, n - 1, j, values[order[j]]);
 
      built = 1;
   }
 
   //Update value of node = val
   void Modify (int node, int val) {
      int j = location[node];
      tree.update (1, 0, n - 1, j, val);
   }
 
   //Returns value of associative function on simple path from a to b. Works in logn
   array<int, 2> Query (int a, int b) {
      if (built == 0) {
         cout << "PLS BUILD!\n";
         return {-1, -1};
      }
 
      int ret = 0, lca = -1;
      while (true) {
         int u = top[a], v = top[b];
         if (u == v) {
            //TODO: Take care of case when location[a] > location[b];
            ret = tree.merge (ret, tree.query (1, 0, n - 1, location[a], location[b]));
            lca = (depth[a] > depth[b] ? b : a);
            break;
         }
 
         if (depth[u] < depth[v])
            swap (a, b), swap (u, v);
 
         ret = tree.merge (ret, tree.query (1, 0, n - 1, location[a], location[u]));
         a = parent[u];
      }
 
      return {ret, lca};
   }
};
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int N, Q;
   cin >> N >> Q;
 
   vector<int> values (N);
   HLD hld (N, values);
 
   for (int i = 1; i < N; ++i) {
      int e;
      cin >> e;
      --e;
      hld.add_edge (i, e);
   }
 
   hld.build();
 
   for (int q = 0; q < Q; ++q) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      cout << hld.Query (a, b)[1] + 1 << '\n';
   }
}