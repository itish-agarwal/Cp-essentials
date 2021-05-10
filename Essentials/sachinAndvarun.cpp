#include <bits/stdc++.h>
#define int long long

using namespace std;

class Triplet {
  public:
    int x, y, gcd;
};
Triplet extendedEuclid(int a, int b) {
  //Base Case
  if(b == 0) {
    Triplet ans;
    ans.x = 1;
    ans.y = 0;
    ans.gcd = a;
    return ans;
  }
  //Accroding to EEA, 
  Triplet smallAns = extendedEuclid(b, a%b);
  Triplet ans;
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a/b)*smallAns.y;
  return ans;
}   
int multiplicativeModInverse(int a, int m) {
  Triplet ans = extendedEuclid(a, m);
  return (ans.x%m + m) % m;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b, d;
    cin >> a >> b >> d;
    int g = __gcd(a, b);
    if(d % g) {
      cout << "0\n";
      continue;
    }
    if(d == 0) {
      cout << "1\n";
      continue;
    }
    a /= g;
    b /= g;
    d /= g;
    
    int y1 = (d%a) * multiplicativeModInverse(b,a);
    y1 %= a; 
    int firstValue = d/b;
    if(d < y1*b) {
      cout << "0\n";        
    } else {
      int n = (firstValue - y1) / a;
      cout << n + 1 << '\n';
    }
  }
}
