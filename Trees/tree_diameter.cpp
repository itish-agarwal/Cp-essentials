#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int>> edges;
int N, INF = 2e9 + 7;
 
//dist, node
pair<int, int> f(int sc) {
 
  vector<int> dist(N, INF);
  dist[sc] = 0;
  queue<int> q;
  q.push(sc);
 
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    for(auto v : edges[u]) {
      if(dist[v] >= INF) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
 
  int mx = -1, node = -1;
  for(int i = 0; i < N; i++) {
    if(dist[i] > mx) {
      mx = dist[i];
      node = i;
    }
  }
 
  return {mx, node};
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
 
  edges.resize(N);
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
 
  pair<int, int> p = f(0);
 
  p = f(p.second);
 
  cout << p.first << '\n'; 
}
