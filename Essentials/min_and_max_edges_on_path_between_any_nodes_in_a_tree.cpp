#include <bits/stdc++.h>

using namespace std;
const int nax = 1e5 + 7;
const int MAXLOG = 31;

vector<vector<int>> g(nax);
int a[nax], h[nax], par[nax][MAXLOG];
int least[nax][MAXLOG], most[nax][MAXLOG];
vector<pair<int, pair<int, int>>> edges;

void dfsh(int u, int p = -1) {
  if(p > -1) h[u] = h[p] + 1;
  for(auto v : g[u]) {
    if(v != p) {
      dfsh(v, u);
    }
  }
}
void dfs(int u, int p = -1) {
  par[u][0] = p;
  if(p > -1) {
    least[u][0] = a[u];
    most[u][0] = a[u];
  } else {
    least[u][0] = nax+nax;
    most[u][0] = -1;
  }
  for(int i = 1; i < MAXLOG; ++i) {
    if(par[u][i-1] + 1) {
      par[u][i] = par[par[u][i-1]][i-1];
      least[u][i] = min(least[u][i-1], least[par[u][i-1]][i-1]);
      most[u][i] = max(most[u][i-1], most[par[u][i-1]][i-1]);
    }
  }
  for(auto v : g[u]) {
    if(v != p) {
      dfs(v, u);
    }
  }
}
pair<int, int> query(int u, int v) {
  if(h[v] < h[u]) swap(u, v);
   //cout<<"DFDSFDS "  << u << " " << v << '\n';
  int mn = nax+nax, mx = -1;
  for(int i = MAXLOG - 1; i >= 0; --i) {
    if(par[v][i] + 1 && h[par[v][i]] >= h[u]) { 
      mn = min(mn, least[v][i]);
      mx = max(mx, most[v][i]);
      v = par[v][i];
    }
  }  
  if(v == u) return {mn, mx};
  for(int i = MAXLOG - 1; i >= 0; --i) {
    if(par[v][i] - par[u][i]) {
      mn = min(mn, least[v][i]);
      mx = max(mx, most[v][i]);
      v = par[v][i];
      mn = min(mn, least[u][i]);
      mx = max(mx, most[u][i]);
      u = par[u][i];
    }
  }   
  mn = min(mn, a[u]);
  mn = min(mn, a[v]);
  
  mx = max(mx, a[u]);
  mx = max(mx, a[v]);
  return {mn, mx};
}
int main() {
  int tt;
  scanf("%d", &tt);
  //while(tt--) {
  for(int nr = 1; nr <= tt; nr++) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= n; ++i) g[i].clear();
    memset(h, 0, sizeof(h));
    memset(par, -1, sizeof(par));
    edges.clear();
    for(int i = 1; i < n; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      edges.push_back({u, {v, w}});
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfsh(1, -1);
    for(auto& it : edges) {
      int u = it.first;
      int v = it.second.first;
      if(h[u] > h[v]) {
        it.first = v;
        it.second.first = u;
      }
    }
    for(auto it : edges) {
      int up = it.first;
      int down = it.second.first;
      int w = it.second.second;
      a[down] = w;
    }
    cout << "Case " << nr << ":\n";
    dfs(1, -1);
    int q;
    cin >> q;
    while(q--) {
      int u, v;
      cin >> u >> v;
      pair<int, int> answer = query(u, v);
      cout << answer.first << " " << answer.second << '\n';
    }
  }
}

