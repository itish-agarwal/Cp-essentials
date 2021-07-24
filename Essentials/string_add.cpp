#include <bits/stdc++.h>

using namespace std;

string add(string a, string b) {
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--) {
        if(a[i] > '9') {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9') {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    while(a[0] == '0') 
      a = a.substr(1);   
    return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << add("200", "13421") <<endl;


}