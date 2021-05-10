#include <bits/stdc++.h>

using namespace std;
const int nax = 12;
using ll = long long;
ll dp[nax][nax][(1<<nax)];
int N, M, And;

ll rec(int i, int j, int mask) {
  if(dp[i][j][mask] > -1) {
    return dp[i][j][mask];
  }
  int first = mask & (1<<(M-1));
  int last = (!j ? 1 : mask & 1);
  if(i==N-1 && j==M-1) {
    ll res;
    if(!first) {
      if(!last) res = 0;
      else res = 1;
    } else {
      if(!last) res = 1;
      else res = 0;
    }
    dp[i][j][mask] = res;
    return res;
  }
  ll answer = 0;
  int new_i = i, new_j = j + 1;
  if(new_j == M) {
    new_i++;
    new_j = 0;
  }
  if(!first) {
    int new_mask = mask*2;
    new_mask &= And;
    new_mask |= 1;
    answer += rec(new_i, new_j, new_mask);
    if(!last && i==N-1) answer = 0;
    dp[i][j][mask] = answer;
    return answer;
  }
  int new_mask = mask;
  if(last) {
    //left cell is blocked -> forced to occupy this;
    new_mask *= 2;
    new_mask &= And;
    answer += rec(new_i, new_j, new_mask);
    new_mask = mask;
  } else {
    if(i+1 < N) {
      new_mask *= 2;
      new_mask &= And;
      answer += rec(new_i, new_j, new_mask);
      new_mask = mask;
    } 
    new_mask |= 1;
    new_mask *= 2;
    new_mask &= And;
    new_mask |= 1;
    answer += rec(new_i, new_j, new_mask);
  }
  dp[i][j][mask] = answer;
  return answer;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {      
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    int mask = (1<<M) - 1;
    And = mask;
    ll answer = rec(0, 0, mask);
    cout << answer << '\n';
  }
  return 0;
}