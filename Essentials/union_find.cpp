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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  
}

