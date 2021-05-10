#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> edges;
const int INF = 2e9 + 7;
vector<int> par, dist, vis;
int n, e;

void dijkstra(int sc) {
  dist[sc] = 0;
  set<pair<int, int>> q;
  q.insert({0, sc});
  while(!q.empty()) {
    int u = q.begin() -> second;
    q.erase(q.begin());
    for(auto p : edges[u]) {
      int v = p.first;
      int w = p.second;
      if(dist[u] + w < dist[v]) {
        q.erase({dist[v], v});
        dist[v] = dist[u] + w;
        par[v] = u;
        q.insert({dist[v], v});
      }
    }
  }
}
void print(int cur, int dest) {
  if(cur == dest) {
    cout << cur << " ";
    return;
  }
  print(par[cur], dest);
  cout << cur << " ";
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> e;

  edges.resize(n+1);
  par.resize(n+1);
  dist.assign(n+1, INF);
  vis.assign(n+1, false);

  while(e--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(make_pair(b, -1));
  }

  dijkstra(1);
  if(dist[n] >= INF) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  cout << -dist[n] + 1 << '\n';
  print(n, 1);
}




  
