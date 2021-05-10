
#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
int h, w;

vector<vector<int>> dp;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
void generate_new_masks(int current_mask, int i, int mask, vector<int>& new_masks) {
  if(i == h) {
    new_masks.push_back(current_mask);
    return;
  }
  if(mask & (1 << i)) {
    generate_new_masks(current_mask, i + 1, mask, new_masks);
  }
  if(!(mask & (1 << i))) {
    generate_new_masks(current_mask ^ (1 << i), i + 1, mask, new_masks);
  }

  if(i + 1 < h && !(mask & (1 << i)) && !(mask & (1 << (i + 1)))) {
    generate_new_masks(current_mask, i + 2, mask, new_masks);
  }
}
int rec(int j, int mask) {
  if(j == w) {
    return mask == 0;
  }
  if(dp[j][mask] > -1) {
    return dp[j][mask];
  }
  int ans = 0;

  vector<int> new_masks;

  generate_new_masks(0, 0, mask, new_masks);

  for(int new_m : new_masks) {
    add_self(ans, rec(j + 1, new_m));
  }
  return dp[j][mask] = ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w;

  dp = vector<vector<int>> (w + 1, vector<int> (1 << h, -1));

  cout << rec(0, 0) << '\n';
  return 0;
}
