#include "bits/stdc++.h"
using namespace std;

vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; ++i)
        for (int neigh : adj[i])
            in_degree[neigh]++;

    for (int i = 0; i < n; ++i)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;
    while (current < (int) order.size()) {
        int node = order[current++];

        for (int neigh : adj[node])
            if (--in_degree[neigh] == 0)
                order.push_back(neigh);
    }

    return order;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
    }    

    vector<int> s = topological_sort(adj);

    for (int x : s){
        cout<<x+1<<endl;
    }
}