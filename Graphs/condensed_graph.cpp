#include "bits/stdc++.h"
using namespace std;

class CondensedGraph {
    int N;
    vector<bool> visited;
    vector<vector<int>> edges, components, adj_scc;

public:
    CondensedGraph(int n, vector<vector<int>> _edges) {
        N = n;
        edges = _edges;
        adj_scc.resize(n);
    }

    void dfs(int v, vector<vector<int>>& adj, vector<int>& output) {
        visited[v] = true;
        for (int u : adj[v])
            if (!visited[u])
            dfs(u, adj, output);

        output.push_back(v); 
    }

    void build_strongly_connected_components() {
        // Sorted list of G by exit times
        vector<int> order;
        visited.assign(N, false);

        for (int x = 0; x < N; ++x)
            if (!visited[x])
                dfs(x, edges, order);

        // Create adjacency list of G^T
        vector<vector<int>> adj_rev(N);
        for (int x = 0; x < N; ++x)
            for (int y : edges[x])
                adj_rev[y].push_back(x);

        visited.assign(N, false);
        reverse(order.begin(), order.end());

        vector<int> roots(N, 0);

        for (int v : order)
            if (!visited[v]) {
                vector<int> component;
                dfs(v, adj_rev, component);
                components.push_back(component);

                int root = *min_element(component.begin(), component.end());
                for (int node : component)
                    roots[node] = root;
            }

        for (int x = 0; x < N; ++x)
            for (int y : edges[x])
                if (roots[x] != roots[y]) 
                    adj_scc[roots[x]].push_back(roots[y]);
    }

    vector<vector<int>> get_components() {
        return components;
    }

    vector<vector<int>> get_scc_adjacency_list() {
        return adj_scc;
    }
};

vector<int> topological_sort(const vector<vector<int>>& edges) {
    int n = edges.size();

    vector<int> in_degree(n);
    for (int x = 0; x < n; ++x)
        for (int y : edges[x])
            in_degree[y]++;

    vector<int> order;
    for (int x = 0; x < n; ++x)
        if (in_degree[x] == 0)
            order.push_back(x);

    int current = 0;
    while (current < (int) order.size()) {
        int x = order[current++];

        for (int y : edges[x]) {
            in_degree[y]--;
            if (in_degree[y] == 0)
                order.push_back(y);
        }
    }

    return order;
}

int getMaxVisitableWebpages(int N, vector<int> L) {
    // Write your code here

    vector<vector<int>> adj(N);
    for (int j = 0; j < N; ++j) {
        adj[j].push_back(L[j] - 1);
    }

    CondensedGraph graph(N, adj);
    graph.build_strongly_connected_components();

    auto components = graph.get_components();
    // for(auto v:components){
    //     for(auto x:v){
    //         cout<<x+1<<" ";
    //     }cout<<endl;
    // }

    auto adj_scc = graph.get_scc_adjacency_list();

    vector<int> component_size(N);
    for (auto component : components)
        for (int node : component) {
            int root = *min_element(component.begin(), component.end());
            component_size[root] = (int) component.size();
        }

    for(int i=0;i<N;++i){
        cout<<i+1<<" CSZ: "<<component_size[i]<<endl;
    }

    for (int i=0;i<N;++i){
        cout<<i+1<<" : ";
        for(int j:adj_scc[i])
            cout<<j+1 << " ";

        cout<<endl;
    }

    vector<int> order = topological_sort(adj_scc);

    vector<int> indices(N);
    for (int j = 0; j < (int) order.size(); ++j)
        indices[order[j]] = j;

    vector<int> dp(N);
    for (int x = 0; x < N; ++x)
        dp[x] = component_size[order[x]];

    for (int x = 0; x < N; ++x) {
        for (int y : adj_scc[order[x]]) {
            int y_in = indices[y];
            dp[y_in] = max (dp[y_in], dp[x] + component_size[y]);
        }
        cout<<"DP\n";
        for(int i=0;i<N;++i)
            cout<<dp[i]<<" ";
        cout<<endl;
    }

    for (int x : order)
        cout << x + 1 <<  " ";

    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n; 
    vector<int>l(n);
    for(auto&x:l)
        cin>>x;

    int j=getMaxVisitableWebpages(n,l);cout<<"ANSWER: "<<j<<endl;
}