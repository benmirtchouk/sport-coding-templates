#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

vector<int> zfun(string& s) {
  int n = s.size();
  vector<int> z(n);

  int l = 0, r = 0;
  for(int i = 1; i < n; i++) {
    if (r >= i)
      z[i] = min(z[i - l], r - i + 1);
    while(i + z[i] < n && s[i + z[i]] == s[z[i]])
      z[i]++;
    if (i + z[i] - 1 > r) {
      r = i + z[i] - 1;
      l = i;
    }
  }
  z[0] = n; // beware sometimes you don't want this

  return z;
}


int main() {
  ios;
  string s;
  cin >> s;
  int n = s.size();

  vector<int> z = zfun(s);

  forn(i, n) cout << z[i] << " \n"[i == n - 1];
}
