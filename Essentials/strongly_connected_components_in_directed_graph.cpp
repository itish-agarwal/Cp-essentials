/*
1) Create an empty stack ‘S’ and do DFS traversal of a graph. 
In DFS traversal, after calling recursive DFS for adjacent vertices 
of a vertex, push the vertex to stack. In the above graph, if we start DFS 
from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. Let the popped 
 vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). 
 The DFS starting from v prints strongly connected component of v. 
 In the above example, we process vertices in order 0, 3, 4, 2, 1 
 (One by one popped from stack).
*/

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> edges, rev_edges;
vector<int> visited;
stack<int> s;

void dfs(int u) {
  if(visited[u]) return ;
  visited[u] = true;
  for(int v : edges[u]) {
    dfs(v);
  }
  s.push(u);
}
void dfs_helper(int u, vector<int>& x) {
  if(visited[u]) return;
  visited[u] = true;
  x.push_back(u);
  for(int v : rev_edges[u]) {
    dfs_helper(v, x);
  }
}
//Usage -> vector<int> a, cout << a << '\n'
ostream& operator << (ostream& stream, const vector<int>& v) {
  for(auto x : v) stream << x << " ";
  return stream;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, e;
  cin >> n >> e;
  edges.resize(n + 1);
  rev_edges.resize(n + 1);
  visited.resize(n + 1);

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


  for(int i = 0; i <= n; i++) {
    visited[i] = false;
  }

  while(!s.empty()) {
    int u = s.top();
    s.pop();

    if(!visited[u]) {

      vector<int> strongly_connected;

      dfs_helper(u, strongly_connected);
      //gives one SCC of the directed graph

      cout << strongly_connected << '\n';
    }
  }
}