//If x is period of string, than the string 
//has same character after every x positions

//Find smallest possible period of string

//ababab -> period 2
//abaaba -> period 3
//aaaaaa -> period 1
//abdcef -> period 6
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tests;
  cin >> tests;
  while(tests--) {
    string S;
    cin >> S;
    int N = S.size();

    //build lps array
    vector<int> lps(N + 1, -1);
    int i = 0, j = -1;

    while(i < N) {
      while(j != -1 && S[i] != S[j])
        j = lps[j];
      i++;
      j++;
      lps[i] = j;
    }

    //period can be only N - lps[N];
    int p = N - lps[N];

    //this should divide the length of string

    if(N % p) 
      p = N;

    cout << p << '\n';
    
    if(tests)
      cout << '\n';
  }
  return 0;

}