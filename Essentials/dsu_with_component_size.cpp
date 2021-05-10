#include <bits/stdc++.h>

using namespace std;
#define int long long 

class dsu {
public:
  vector<int> p, sz;
  dsu(int _n) {
    p.resize(_n);
    sz.assign(_n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x != y) {
      if(sz[x] < sz[y]) {
        p[x] = y;
        sz[y] += sz[x];
      } else {
        p[y] = x;
        sz[x] += sz[y];
      }
    }
  }
  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }
  inline int get_size(int x) {
    return sz[get(x)];
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  dsu d(n);

  int components = n;
  set<int> s;
  for(int i = 0; i < n; i++) {
    s.insert(d.get_size(i));
  }
  while(m--) {
    int a, b;
    cin >> a >> b;
    a -= 1;
    b -= 1;
    if(d.belong(a, b)) {
      cout << components << " " << *s.rbegin() << '\n';
    } else {
      s.erase(d.get_size(a));
      s.erase(d.get_size(b));
      d.unite(a, b);
      components -= 1;
      s.insert(d.get_size(a));
      cout << components << " " << *s.rbegin() << '\n';
    }
  }
}