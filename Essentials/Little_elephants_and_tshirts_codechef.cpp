#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
string str, word;

void add(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> ret[n + 1];
    getline(cin, str);
    for(int i = 0; i < n; i++) {
      getline(cin, str);
      stringstream iss(str);
      while(iss >> word) {
        int foo = stoi(word);
        ret[i].push_back(foo);
      }
    }
    map<int, vector<int>> can;
    for(int i = 0; i < n; i++) {
      for(int x : ret[i]) {
        can[x].push_back(i);
      }
    }
    vector<vector<int>> tshirts;
    for(pair<int, vector<int>> pp : can) {
      tshirts.push_back(pp.second);
    }
    int t = tshirts.size();
    vector<vector<int>> dp(1 << n, vector<int> (t + 1, 0));
    for(int j = 0; j <= t; j++) {
      dp[(1 << n) - 1][j] = 1;
    }     
    for(int mask = (1 << n) - 2; mask >= 0; mask--) {
      for(int i = t - 1; i >= 0; i--) {
        dp[mask][i] = dp[mask][i + 1];
        for(int person : tshirts[i]) {
          if(mask & (1 << person)) {
            
          } else {
            add(dp[mask][i], dp[mask | (1 << person)][i + 1]);
          }
        }
      }
    }
    cout << dp[0][0] << '\n';    
  }
}
