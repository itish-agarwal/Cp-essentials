#include <bits/stdc++.h>

using namespace std;
#define int long long 

vector<vector<pair<int, int>>> g;
vector<int> par, dist, vis;
int n, e, inf;

void dijkstra(int sc) {

  dist[sc] = 0;
  par[sc] = -1;

  priority_queue<pair<int, int>> pq;
  //-dist, node
  pq.push(make_pair(0, sc));

  while(!pq.empty()) {

    pair<int, int> fs = pq.top();
    pq.pop();

    int u = fs.second;
      
    if(vis[u]) {
      continue;
    }
    vis[u] = true;
    for(auto p : g[u]) {
      int v = p.first;
      int wt = p.second;
      if(dist[u] + wt < dist[v]) {	
		cout << v << endl;
        dist[v] = dist[u] + wt;
        par[v] = u;
        pq.push(make_pair(-dist[v], v));
      }
    }
  }
  return;
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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  inf = 1e18 + 555;
  cin >> n >> e;
  g.resize(n+1);
  par.resize(n+1);
  dist.assign(n+1, inf);
  vis.assign(n+1, false);

  while(e--) {
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back(make_pair(b, w));
    g[b].push_back(make_pair(a, w));
  }

  dijkstra(6);
  
  if(dist[n]==inf) {
    cout << "-1\n";
    return 0;
  }
  cout << '\n';
  return 0;
}




  
