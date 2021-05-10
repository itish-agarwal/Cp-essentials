#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 2e18 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, e, k;
  cin >> n >> e >> k;

  vector<vector<pair<int, int>>> edges(n + 1);

  while(e--) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].emplace_back(v, w);
  }

  priority_queue<pair<int, int>, 
                 vector<pair<int, int>>, 
                 greater<pair<int, int>>> pq;

  vector<vector<int>> dist(n + 1, vector<int> (k, INF));

  dist[1][0] = 0;

  pq.push({0, 1});

  while(!pq.empty()) {
    int u = pq.top().second;
    int d = pq.top().first;

    pq.pop();

    if(dist[u][k - 1] < d) continue;

    for(auto p : edges[u]) {
      int v = p.first;
      int wt = p.second;
      if(d + wt < dist[v][k - 1]) {
        dist[v][k - 1] = d + wt;
        pq.push({d + wt, v});
        sort(dist[v].begin(), dist[v].end());
      }
    }
  }

  for(int j = 0; j < k; j++) {
    cout << dist[n][j] << " ";
  }
  cout << '\n';
}