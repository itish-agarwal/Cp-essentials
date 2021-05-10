#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 1e9 + 7;

vector<vector<pair<int, int>>> edges;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, e;
  cin >> n >> e;
  edges.resize(n + 1);

  const int INF = 2e18 + 7;
  vector<int> dist(n + 1, INF);

  while(e--) {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a].emplace_back(b, w);
  }

  vector<int> count_dp(n + 1), min_dp(n + 1, INF), max_dp(n + 1, 0);
  count_dp[1] = 1;
  dist[1] = 0;

  min_dp[1] = 0;

  //count_dp[i] -> number of shortest paths from 1 to i
  set<pair<int, int>> s;
  s.insert({0, 1});

  while(!s.empty()) {
    int u = s.begin() -> second;
    s.erase(s.begin());
    for(auto p : edges[u]) {
      int v = p.first;
      int w = p.second;
      if(dist[u] + w < dist[v]) {
        s.erase({dist[v], v});
        dist[v] = dist[u] + w;
        s.insert({dist[v], v});
        min_dp[v] = min_dp[u] + 1;
        max_dp[v] = max_dp[u] + 1;
        count_dp[v] = count_dp[u];
      } else if(dist[u] + w == dist[v]) {
        add_self(count_dp[v], count_dp[u]);
        min_dp[v] = min(min_dp[v], min_dp[u] + 1);
        max_dp[v] = max(max_dp[v], max_dp[u] + 1);
      }
    }
  }
  cout << dist[n] << " " << count_dp[n] << " " << min_dp[n] << " " << max_dp[n] << '\n';
}