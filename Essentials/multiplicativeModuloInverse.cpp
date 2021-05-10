/*
 * mul...mod..inverse of a number 'a' with respect to
 * a number 'm' is a number 'b' such that (a*b)mod m == 1
 * now, 
 * (a*b-1)%modm == 0
 * a*b-1 = m*q (for some q)
 * a*b - m*q == 1
 * a*b + m*Q == 1
 * for soln to exist, gcd(a, m) == 1
 * this is example of extended euclidean algo then
 * => apply EEA on ax+by == 1 and whatever is value of x, is
 * value of b, ie, mul..mod..inverse of a wrt m
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

int multiplicativeModInverse(int a, int m) {
  Triplet ans = extendedEuclid(a, m);
  return ans.x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a = 5;
  int b = 17;
  cout << multiplicativeModInverse(a, b) << '\n';
}
