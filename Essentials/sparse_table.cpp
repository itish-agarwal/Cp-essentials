/*
A company has n employees, who form a tree hierarchy where each 
employee has a boss, except for the general director.
Your task is to process q queries of the form: who is the lowest 
common boss of employees a and b in the hierarchy?
*/

// https://cses.fi/problemset/task/1688/

#include <bits/stdc++.h>
 
using namespace std;
 
template <class T>
struct SparseTable {
public:
  int N;
  vector<int> compute, comparator;
  vector<vector<T>> tab;
 
  T merge(const T& a, const T& b) {
    return (comparator[a] < comparator[b] ? a : b);
  }
 
  SparseTable(const vector<T>& values = {}, const vector<T>& depths = {}) {
    int N = values.size();
    compute.resize(N + 1);
    comparator = depths;
    for(int i = 2; i <= N; ++i) 
      compute[i] = compute[i / 2] + 1;
 
    const int log = 32 - __builtin_clz(N);
    tab.resize(log);
 
    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }
 
  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};
struct LCA {
  int n = 0, root = 0;
  vector<vector<int>> edges;
  vector<int> parent, depth, subtree_size;
  vector<int> euler2, euler, first_occurence;
  SparseTable<int>* st;
 
  LCA(int _n, int _root) {
    n = _n;
    root = _root;
    edges.assign(n, {});
    parent.resize(n);
    depth.resize(n);
    subtree_size.resize(n);
    first_occurence.assign(n, -1);
  }
 
  LCA(const vector<vector<int>>& adj, int root) {
    LCA((int) adj.size(), root);
    edges = adj;
  }
 
  void add_edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
 
  void build() {
    function<void(int, int)> Dfs = [&](int a, int pr) {
      euler2.push_back(a);
      euler.push_back(a);
      subtree_size[a] = 1;
      parent[a] = pr;
      for(int b : edges[a]) {
        if(b != pr) {
          depth[b] = depth[a] + 1;
          parent[b] = a;
          Dfs(b, a);
          euler2.push_back(a);
        }
      }
      euler.push_back(a);
    };
 
    Dfs(root, -1);
 
    for(int i = 0; i < 2 * n; ++i)
      if(first_occurence[euler2[i]] == -1) 
        first_occurence[euler2[i]] = i;
 
    st = new SparseTable<int> (euler2, depth);
  }
 
  int get_lca(int a, int b) {
    a = first_occurence[a];
    b = first_occurence[b];
 
    if(a > b)
      swap(a, b);
 
    return st -> query(a, b);
  }
};
 
void test_case() {
  int N, Q;
  cin >> N >> Q;
 
  LCA lca(N, 0);
  for(int i = 1; i < N; ++i) {
    int p;
    cin >> p;
    p--;
    lca.add_edge(i, p);
  }
  lca.build();
 
  for(int q = 0; q < Q; ++q) {
    int a, b;
    cin >> a >> b;
    --a, --b;
 
    cout << lca.get_lca(a, b) + 1 << '\n';
  }
} 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();
}