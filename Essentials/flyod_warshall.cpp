//Single source shortest paths -> for weighted graphs (directed/undirected)
//Dijkstra algorithm

#include <bits/stdc++.h>

using namespace std;
#define int long long

int dist[404][404], par[404][404];

void printPath(int i, int j) {
  if(i != j) {
    printPath(i, par[i][j]);
    return;
  }
  cout << j << endl;
  return;
}

void solve() {
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i!=j) {
        dist[i][j] = 1e9;
      }
    }
  }

  while(e--) {
    int a, b, w;
    cin >> a >> b >> w;
    dist[a][b] = min(dist[a][b], w);
  }

  //What does par[i][j] store?
  //par[i][j]        i->x->y->.....->par[i][j]->j

  //par[i][j] stores that for the optimal path, what is the node that occurs just before j
  for(int i= 0;i < n;i++) {
    for(int j = 0; j < n; j++) {
      par[i][j] = i;
    }
  }

  //Run the flyod warshall loops
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          par[i][j] = par[k][j];
        }
      }
    }
  }

  printPath(x, y);
  //Find the that gives us the shortest path between any pair of vertices
  //We create another array par[][]

}



signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  solve();
}
  