#include <bits/stdc++.h>

using namespace std;
#define int long long

class dsu {
  public:
    vector<int> p, rank;
    dsu(int _n) {
      p.resize(_n);
      rank.assign(_n, 1);
      iota(p.begin(), p.end(), 0);
    }
    inline int get(int x) {
      return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    void unite(int x, int y) {
      x = get(x);
      y = get(y);
      if(x!=y) {
        if(rank[x] >= rank[y]) {
          p[y] = x;
          rank[x] += rank[y];
        } else {
          p[x] = y;
          rank[y] += rank[x];
        }
      }
    }
    inline bool belong(int x, int y) {
      return get(x) == get(y);
    }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int ans = 0;
    dsu d(n+1);
    for(int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      ans += d.rank[d.get(u)]*d.rank[d.get(v)];
      d.unite(u, v);
    }
    int u, v;
    cin >> u >> v;
    cout << ans << endl;
  }
  return 0;
}