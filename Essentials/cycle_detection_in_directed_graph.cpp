#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& edges, vector<bool>& vis, vector<bool>& in_stack) {
	if(vis[u]) return false;
	vis[u] = in_stack[u] = true;
	for(auto v : edges[u]) {
		dfs(v, edges, vis,  in_stack);
		if(vis[v] && in_stack[v]) {
			return true;
		}		
	}
	in_stack[u] = false;
	return false;
}
bool cycleInGraph(vector<vector<int>> edges) {
  int n = edges.size();
	vector<bool> vis(n), in_stack(n);
	for(int i = 0; i < n; ++i) {
		if(!vis[i]) {
			bool b = dfs(i, edges, vis, in_stack);
			if(b) return true;
		}
	}
	return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  
  
}
