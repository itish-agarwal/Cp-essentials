#include <bits/stdc++.h>

using namespace std;
#define int long long 
const int mod = 10;

struct Mat {
  vector<vector<int>> mat;
  int row, col;
  Mat(int r, int c) {
    row = r;
    col = c;
    mat = vector<vector<int>> (row, vector<int>  (col, 0));
  }
};
Mat identity(int r, int c) {
  Mat id(r, c);
  for(int i = 0; i < r; i++) {
    id.mat[i][i] = 1;
  }
  return id;
}
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
Mat add(const Mat& a, const Mat& b) {
  Mat ans(a.row, b.col);
  for(int i = 0; i < a.row; i++) {
    for(int j = 0; j < a.col; j++) {
      ans.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;
    }
  }
  return ans;
}
Mat raise(const Mat& a, int n) {
  if(n == 0) {
    return identity(a.row, a.col);
  }
  Mat half = raise(a, n/2);
  half = multiply(half, half);
  if(n % 2) {
    half = multiply(half, a);
  }
  return half;
}
Mat func(Mat A, int n) {
  if(n == 1) {
    return A;
  }
  Mat Aa = raise(A, n / 2);
  Mat half = multiply(func(A, n / 2), add(identity(A.row, A.col), Aa));
  if(n % 2) {
    Mat Aaa = multiply(Aa, Aa);
    Aaa = multiply(Aaa, A);
    half = add(half, Aaa);
  }
  return half;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for(int z = 1; z <= tt; z++) {
    int n, k;
    cin >> n >> k;
    Mat A(n, n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> A.mat[i][j];
      }
    }
    cout << "Case " << z << ":\n";
    Mat ans = func(A, k);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << ans.mat[i][j] % mod;
      }
      cout << '\n';
    }
  }
}
