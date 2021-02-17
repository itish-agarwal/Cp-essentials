//Question
//Given a tree, for all nodes, find
//sum of distances of this node to all other nodes#else 
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g;
const int nax = 1e5 + 555;
int N, indp[nax], outdp[nax], sz[nax], par[nax];

//finds size and indp
void dfs1(int u, int p) {
  par[u] = p;
  sz[u] = 1;
  indp[u] = 0;
  for(auto v : g[u]) {
    if(v!=p) {
      dfs1(v, u);
      sz[u] += sz[v];
      indp[u] += indp[v] + sz[v];
    }
  }
}

//finds outdp
void dfs2(int u, int p) {
  //find the outdp of this node and then 
  //only go to child
  if(p == -1) {
    //node is root;
    outdp[u] = 0;
  } else {
    outdp[u] = outdp[p] + indp[p] + N - 2*sz[u] - indp[u]; 
  }  
  for(auto v : g[u]) {
    if(v!=p) {
      dfs2(v, u);
    }
  }
}  

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  //take input of graph
  //root the tree at any node
  //and call dfs1(root, -1) and then dfs2(root, -1);
  
  
  return 0;
}

