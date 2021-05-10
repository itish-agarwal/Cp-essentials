/* You are allowed absolute or relative error upto 1e-9
Absolute error is checked when dealing with values less than 1
Relative error is checked when dealing with values greater than 1
*/


#include <bits/stdc++.h>

using namespace std;

void test(double hidden) {
    double low = 0, high = 1e9;
    for(int rep = 0; rep < 40; ++rep) {
        double mid = (low + high)/2;
        if(rep == 0) mid = 1;
        else if(high > 1) mid = sqrt(low * high);

        if(mid < hidden) low = mid;
        else high = mid;
    }
    double ans = (low + high) / 2;
    printf(" correct answer: %0.12lf\n", hidden);
    printf("     our answer: %0.12lf\n", ans);
    printf("      abs error: %0.12lf\n", abs(hidden - ans));
    printf("relative answer: %0.12lf\n", abs(hidden - ans) / hidden);
}

/* for interval 0-1, absolute matters
for interval > 1,, relative matters
*/

//for big values of high and low (and close to each other);
//never use (high - low > 1e-9) 
// -> it can enter infinite low

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  test(0.2313244);
  test(12231.32324421);
}