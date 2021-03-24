#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
vector<pair<int, int>> go{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void test_case() {
  int n, m;
  cin >> n >> m;
  int g[n][m];
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      cin >> g[i][j];
    }
  }
  int ans = 0;
  multiset<pair<int, pair<int, int>>> s;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      s.insert({-g[i][j], {i, j}});
    }
  }
  while(!s.empty()) {
    auto it = *s.begin();
    s.erase(s.find(it));
    int x = it.second.first;
    int y = it.second.second;
    for(auto c : go) {
      int xn = x + c.first;
      int yn = y + c.second;
      if(xn>=0 && yn>=0 && xn<n && yn<m && abs(g[xn][yn]-g[x][y])>1) {
        int mx = abs(g[xn][yn] - g[x][y]);
        ans += mx - 1;
        s.erase(s.find({-g[xn][yn], {xn, yn}}));
        g[xn][yn] += mx - 1;
        s.insert({-g[xn][yn], {xn, yn}});
      }
    }
  }
  cout << ans << '\n';        
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int nr = 1; nr <= tt; nr++) {
    cout << "Case #" << nr << ": ";
    test_case();
  }
}
