/*
for each position i=0…n−1 we'll find the values 
d1[i] and d2[i], denoting the number of palindromes 
accordingly with odd and even lengths with centers 
in the position i.

a b a b a b c
  <---3--->
    d1[3] = 3;

c b a a b d
  <---2->
      d2[3]=2
*/  

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;

  int N = S.size();
  vector<int> d1(N);

  for(int i = 0, l = 0, r = -1; i < N; i++) {
    int k = (i > r ? 1 : min(d1[l + r - i], r - i + 1));
    while(i - k >= 0 && i + k < N && S[i - k] == S[i + k])
      k++;
    d1[i] = k--;
    if(i + k > r) {
      l = i - k;
      r = i + k;
    }
  }

  vector<int> d2(N);
  for(int i = 0, l = 0, r = -1; i < N; i++) {
    int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
    while(i - k - 1 >= 0 && i + k < N && S[i - k - 1] == S[i + k]) 
      k++;
    d2[i] = k--;
    if(i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }


  for(int x : d1) 
    cout << x << " ";

  cout << '\n';

  for(int x : d2)
    cout << x << " " ;

}