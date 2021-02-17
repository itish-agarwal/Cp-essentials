#include <bits/stdc++.h>

using namespace std;
#define int long long 

class dsu {
public:
  vector<int> p, rank;
  dsu(int n) {
    p.resize(n);
    rank.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(rank[x] < rank[y]) {
      p[x] = y;
    } else {
      p[y] = x;
      if(rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  }
  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }
};
signed main() {
  int tt;
  cin >> tt;
  while(tt--) {
    int N, R, c, r;
    cin >> N >> R >> c >> r;
    dsu d(N+1);
    priority_queue<pair<int, pair<int, int>>> pq;
    while(R--) {
      int u, v;
      cin >> u >> v;
      pq.push(make_pair(-r, make_pair(u, v)));
    }
    for(int i = 1; i <= N; i++) {
      pq.push(make_pair(-c, make_pair(0, i)));
    }
    int ans = 0;
    while(!pq.empty()) {
      int u = pq.top().second.first;
      int v = pq.top().second.second;
      int cost = -pq.top().first;
      pq.pop();
      if(!d.belong(u, v)) {
        ans += cost;
        d.unite(u, v);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}