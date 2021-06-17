/*
 The Z-function for this string is an array of
 length n where the i-th element is equal to 
 the greatest number of characters starting 
 from the position i that coincide with the 
 first characters of s.

In other words, z[i] is the length of the longest
 common prefix between s and the suffix of s starting
  at i
  */

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  int N = S.size();

  //Assumes 0 based only
  vector<int> Z(N);

  for(int i = 1, l = 0, r = 0; i < N; i++) {
    if(i <= r) 
      Z[i] = min(r - i + 1, Z[i - l]);
    while(i + Z[i] < N && S[Z[i]] == S[i + Z[i]])
      Z[i] += 1;
    if(i + Z[i] - 1 > r) {
      l = i;
      r = i + Z[i] - 1;
    }
  }

  for(int i = 0; i < N; i++)
    cout << Z[i] << " ";
  
}