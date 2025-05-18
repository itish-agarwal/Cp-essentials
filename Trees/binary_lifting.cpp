#include "bits/stdc++.h"
using namespace std;

class Tree {
    int N, root, LOG;
    vector<vector<int>> adj, up;
    vector<int> parent, depth;

public:
    Tree(int _n, int _root, int _log) {
        N = _n;
        root = _root;
        LOG = _log;
        adj.resize(N);
        up = vector<vector<int>> (_n, vector<int> (_log, _root));
        parent = vector<int> (_n, _root);
        depth.resize(N);
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void Dfs(int a, int par) {
        for (int b : adj[a]) 
            if (b != par) {
                parent[b] = a;
                up[b][0] = a;
                depth[b] = depth[a] + 1;
                for (int j = 1; j < LOG; ++j)
                    up[b][j] = up[ up[b][j-1] ][j-1];

                Dfs(b, a);
            }
    }

    int get_lca(int a, int b) {
        if (depth[b] > depth[a])
            swap(a, b);

        int k = depth[a] - depth[b];
        a = get_kth_ancestor(a, k);

        if (a == b)
            return a;

        for (int j = LOG - 1; j >= 0; --j) 
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }

        return parent[a];
    }

    int get_kth_ancestor(int a, int k) {
        if (k > depth[a])
            return -1;

        int node = a;
        for (int j = LOG - 1; j >= 0; --j)
            if (k & (1 << j))
                node = up[node][j];

        return node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;

    Tree *tree = new Tree(N, 0, 23);

    for (int j = 1; j < N; ++j) {
        int par;
        cin >> par;
        tree->add_edge(j, --par);
    }

    tree->Dfs(0, -1);

    while (Q-- > 0) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        cout << tree->get_lca(a, b) + 1 << '\n';
    }
}