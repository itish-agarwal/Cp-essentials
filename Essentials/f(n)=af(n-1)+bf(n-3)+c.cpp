#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 10007;

struct Mat {
  vector<vector<int>> mat;
  int row, col;
  Mat(int r, int c) {
    row = r;
    col = c;
    mat = vector<vector<int>> (row, vector<int>  (col, 0));
  }
};
Mat multiply(const Mat& a, const Mat& b) {
  Mat ans(a.row, b.col);
  for(int i = 0; i < ans.row; i++) {
    for(int k = 0; k < a.col; k++) {
      if(a.mat[i][k]) {
        for(int j = 0; j < ans.col; j++) {
          ans.mat[i][j] += ((long long)a.mat[i][k] * b.mat[k][j]) % mod;
          ans.mat[i][j] %= mod;
        }
      }
    }
  }
  return ans;
}
Mat raise(const Mat& a, int n) {
  if(n == 0) {
    Mat id(a.row, a.col);
    for(int i = 0; i < a.row; i++) {
      id.mat[i][i] = 1;
    }
    return id;
  }
  Mat half = raise(a, n/2);
  half = multiply(half, half);
  if(n % 2) {
    half = multiply(half, a);
  }
  return half;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int z = 1; z <= tt; z++) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    Mat M(4, 4);
    M.mat[0][0] = a;
    M.mat[0][2] = b;
    M.mat[0][3] = c;

    M.mat[1][0] = 1;
    M.mat[2][1] = 1;
    M.mat[3][3] = 1;

    Mat d = raise(M, n);

    cout << "Case " << z << ": " << d.mat[2][3] << '\n';
  }
}
