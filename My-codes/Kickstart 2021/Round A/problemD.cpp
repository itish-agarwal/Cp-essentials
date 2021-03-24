#include <bits/stdc++.h>

using namespace std;

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
void test_case() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int> (n));
  vector<vector<int>> b(n, vector<int> (n));
  vector<int> row(n), col(n);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> b[i][j];
    }
  }
  for(auto& it : row) cin >> it;
  for(auto& it : col) cin >> it;
  vector<tuple<int, int, int>> ret;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(a[i][j] < 0) {
        int u = i, v = j + n, cost = -b[i][j];
        ret.emplace_back(cost, u, v);
      }
    }
  }
  sort(ret.begin(), ret.end());
  dsu d(n + n);
  int ans = 0;
  for(auto it : ret) {
    int u = get<1>(it), v = get<2>(it), cost = -get<0>(it);
    if(d.belong(u, v)) {
      ans += cost;
    } else {
      d.unite(u, v);
    }
  }
  cout << ans << '\n';
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int nr = 1; nr <= tt; nr++) {
    cout << "Case #" << nr << ": ";
    test_case();
  }
}
