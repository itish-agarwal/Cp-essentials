#include <bits/stdc++.h>
 
using namespace std;
#define int long long 

int f(int l1, int l2) {
  if(l1<2 || l2<2) return 0;
  return min(l1, l2/2) + min(l2, l1/2) - 2;
}
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
  int rowLR[n][m], colTB[n][m], rowRL[n][m], colBT[n][m];
  
  for(int i = 0;i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(!j || !g[i][j]) {
        rowLR[i][j] = g[i][j];
      } else {
        if(g[i][j-1]) {
          rowLR[i][j] = rowLR[i][j-1] + 1;
        } else {
          rowLR[i][j] = 1;
        }
      }
      //cout << rowLR[i][j] << " ";
    }
  }
  for(int j = 0; j < m; ++j) {
    for(int i = 0; i < n; ++i) {
      if(!i || !g[i][j]) {
        colTB[i][j] = g[i][j];
      } else {
        if(g[i-1][j]) {
          colTB[i][j] = colTB[i-1][j] + 1;
        } else {
          colTB[i][j] = 1;
        }
      }
    }
  }
  
  for(int i = 0; i < n; ++i) {
    for(int j = m-1; j >= 0; --j) {
      if(j==m-1 || !g[i][j]) {
        rowRL[i][j] = g[i][j];
      } else {
        if(g[i][j+1]) {
          rowRL[i][j] = rowRL[i][j+1] + 1;
        } else {
          rowRL[i][j] = 1;
        }
      }
    }
  }
  
  for(int j = 0; j < m; ++j) {
    for(int i = n-1; i >= 0; --i) {
      if(i==n-1 || !g[i][j]) {
        colBT[i][j] = g[i][j];
      } else {
        if(g[i+1][j]) {
          colBT[i][j] = colBT[i+1][j] + 1;
        } else {
          colBT[i][j] = 1;
        }
      }
      //cout << colBT[i][j] << " ";
    }
    //cout << '\n';
  }
  
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      int l1 = rowLR[i][j], l2 = colTB[i][j];
      ans += f(l1, l2);
      l1 = rowRL[i][j]; l2 = colTB[i][j];
      ans += f(l1, l2);
      l1 = rowLR[i][j]; l2 = colBT[i][j];
      ans += f(l1, l2);
      l1 = rowRL[i][j]; l2 = colBT[i][j];
      ans += f(l1, l2);
      //cout << i << " " << j << " " << ans << '\n';
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
