#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  int N = S.size();

  //lps[i] -> for the substring S[0...i - 1];
  //longest profer (do not include full substring till i - 1)
  //suffix which is also a prefix
    
  //a b a c a b a d
  //0 0 1 0 1 2 3 0

  vector<int> lps(N + 1);

  int i = 0, j = -1;

  lps[0] = -1;

  while(i < N) {
    while(j != -1 && S[j] != S[i])
      j = lps[j];
    i++;
    j++;
    lps[i] = j;
  } 

  for(int i = 1; i <= N; i++)
    cout << lps[i] << " ";
  
}












//  #include <bits/stdc++.h>

// using namespace std;

// signed main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);
  
//   string s;
//   cin >> s;
//   int n = s.size();

//   int lps[n+1];
//   int i = 0, j = -1;
//   lps[0] = -1;

//   while(i < n) {
//     while(j!=-1 && s[j]!=s[i]) {
//       j = lps[j];
//     }
//     i++;
//     j++;
//     lps[i] = j;
//   }

//   for(int i = 1; i <= n; i++) {
//     cout << lps[i] << " ";
//   }
//   cout << '\n';
//   return 0;
// }
