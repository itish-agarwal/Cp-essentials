#include <bits/stdc++.h>

using namespace std;

vector<int> LPS(string S) {
  int N = S.size();
  //Assumes 1 indexed
  vector<int> lps(N + 1, -1);
  int i = 0, j = -1;
  while(i < N) {
    while(j != -1 && S[i] != S[j])
      j = lps[j];
    i++;
    j++;
    lps[i] = j;
  }
  return lps;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  S += S;
  int N = S.size();
  vector<int> lps = LPS(S);

  int k = 0;

  for(int j = 1; j < N; j++) {
    int i = lps[j - k - 1];
    while(i != -1 && S[j] != S[k + i + 1]) {
      if(S[j] < S[k + i + 1]) 
        k = j - i - 1;
      i = lps[i];
    }
    if(i == -1 && S[j] != S[k + i + 1]) {
      if(S[j] < S[k + i + 1]) 
        k = j;
      lps[j - k] = -1;
    } else {
      lps[j - k] = i + 1;
    }
  }

  cout << S.substr(k, N / 2) << '\n';

  return 0;
}