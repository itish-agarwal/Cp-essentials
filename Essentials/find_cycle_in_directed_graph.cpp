/*We will run a series of DFS in the graph. 
Initially all vertices are colored white (0). 
From each unvisited (white) vertex, start the DFS, 
mark it gray (1) while entering and mark it black (2) on exit. 
If DFS moves to a gray vertex, then we have found a cycle 
(if the graph is undirected, the edge to parent is not considered). 
The cycle itself can be reconstructed using parent array.
*/
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges;
vector<int> color, parent;

int cycle_start = -1, cycle_end;

bool has_cycle(int u) {
  color[u] = 1;
  for(int v : edges[u]) { 
    if(color[v] == 0) {
      parent[v] = u;
      if(has_cycle(v)) {
        return true;
      }
    } else if(color[v] == 1) {
      cycle_start = v;
      cycle_end = u;
      return true;
    }
  }
  color[u] = 2;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, e;
  cin >> n >> e;
  edges.resize(n + 1);
  color.resize(n + 1);  
  parent.resize(n + 1);

  //0 -> not visited
  //1 -> on entering
  //2 -> on leaving

  while(e--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  } 
  for(int i = 1; i <= n; i++) {
    if(color[i] == 0 && has_cycle(i)) {
      break;
    }
  }
  if(cycle_start == -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector<int> cycle;
  cycle.push_back(cycle_start);

  for(int x = cycle_end; x != cycle_start; x = parent[x]) {
    cycle.push_back(x);
  }

  cycle.push_back(cycle_start);

  reverse(cycle.begin(), cycle.end());

  cout << (int)cycle.size() << '\n';
  for(int node : cycle) {
    cout << node << " ";
  }
  cout << '\n';
}