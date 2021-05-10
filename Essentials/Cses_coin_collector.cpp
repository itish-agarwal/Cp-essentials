#include <bits/stdc++.h>
 
using namespace std;
#define int long long 

vector<vector<int>> edges, g, rev_edges;
vector<bool> visited;
stack<int> tt, topo_sort;
 
void dfs(int u) {
  if(visited[u]) return;
  visited[u] = true;
  for(int v : edges[u]) {
    dfs(v);
  }
  tt.push(u);
}
void dfs_rev(int u, vector<int>& x) {
  if(visited[u]) return;
  visited[u] = true;
  x.push_back(u);
  for(int v : rev_edges[u]) {
    dfs_rev(v, x);
  }
}
void dfs_topo(int u) {
  if(visited[u]) return;
  visited[u] = true;
  for(int v : g[u]) {
    dfs_topo(v);
  }
  topo_sort.push(u);
}
//Usage -> vector<int> a, cout << a << '\n'
ostream& operator << (ostream& stream, const vector<int>& v) {
  for(auto x : v) stream << x << " ";
  return stream;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n, e;
  cin >> n >> e;
 
  edges.resize(n + 1);
  rev_edges.resize(n + 1);
  visited.resize(n + 1);

  vector<int> coins(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> coins[i];
  }
 
  while(e--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    rev_edges[b].push_back(a);
  }
 
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      dfs(i);
    }
  }
 
  int u = tt.top();
 
  for(int i = 0; i <= n; i++) {
    visited[i] = false;
  }
 
  vector<int> ans(n + 1);
 
  int k = 0;
  while(!tt.empty()) {
    int u = tt.top();
    tt.pop();
    vector<int> strongly_connected;
    dfs_rev(u, strongly_connected);
    if(!strongly_connected.empty()) {
      for(int node : strongly_connected) {
        ans[node] = k + 1;
      }
      k += 1;
    }
  }

  vector<vector<int>> ret(n + 1);

  for(int i = 1; i <= n; i++) {
    ret[ans[i]].push_back(i);
  }

  // vector<vector<int>> g(k + 1);
  g.resize(k + 1);

  vector<int> A(k + 1);

  for(int i = 1; i <= k; i++) {
    for(int node : ret[i]) {
      A[i] += coins[node];
    }
    for(int node : ret[i]) {
      for(int v : edges[node]) {
        if(ans[v] != ans[node]) {
          g[ans[node]].push_back(ans[v]);
        }
      }
    }
  }

  // k nodes now;
  for(int i = 0; i <= n; i++) {
    visited[i] = false; 
  }

  for(int i = 1; i <= k; i++) {
    if(!visited[i]) {
      dfs_topo(i);
    }
  }

  vector<int> x;
  while(!topo_sort.empty()) {
    x.push_back(topo_sort.top());
    topo_sort.pop();
  }
  // cout << x << endl;

  map<int, int> index;
  for(int i = 0; i < k; i++) {
    index[x[i]] = i;
  }

  vector<int> dp(k);
  dp.back() = A[x.back()];

  for(int i = k - 2; i >= 0; i--) {
    int node = x[i];
    dp[i] = A[node];
    for(int v : g[node]) {
      int in = index[v];
      dp[i] = max(dp[i], A[node] + dp[in]);
    }
  }

  int max_coins = 0;
  for(int possible : dp) {
    max_coins = max(max_coins, possible);
  }

  cout << max_coins << '\n';

}