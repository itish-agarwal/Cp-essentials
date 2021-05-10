/* Extended Euclidean Algorithm gives us an answer for the case
 * ax + by = gcd(a, b)
 * it gives us values of x and y
 */
 
#include <bits/stdc++.h>

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a = 36;
  int b = 90;
  Triplet ans = extendedEuclid(a, b);
  cout << ans.gcd << " " << ans.x << " " << ans.y << '\n';
}
