/* Extended Euclidean Algorithm gives us an answer for the case
 * ax + by = gcd(a, b)
 * it gives us values of x and y
 */

/* 
It is based on finding gcd using euclidean algo
gcd(a, b) = (b == 0 ? a : gcd(b, a mod b))

Let g = gcd(a, b);

Let's say we know the coefficients for b, a mod b -> say (x1, y1);
Let (x, y) be answer for a, b -> a * x + b * y = g;
We want to find (x, y) knowing (x1, y1);

Then, b * x1 + (a mod b) * y1 = g
a mod b = (a - (a / b) * b)

Then g = a * y1 + b * (x1 - y1 * (a / b));
Comparing, we get

x = y1
y = x1 - y1 * (a / b);
*/
#include <bits/stdc++.h>

using namespace std;

//returns gcd of a and b and values of x and y(passed by reference)
int gcd(int a, int b, int& x, int& y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, x, y;
  cin >> a >> b;

  int g = gcd(a, b, x, y);

  cout << x << " " << y << '\n';

}