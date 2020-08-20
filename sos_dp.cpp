// https://codeforces.com/contest/165/submission/64617686

#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

const int MAXB = 22;
const int ALL = (1 << MAXB) - 1;

int neg(int x) {
  return ALL ^ x;
}

int main() {
  ios;
  int n;
  cin >> n;

  vector<int> have(1 << MAXB, -1);
  vector<int> v(n);
  forn(i, n) {
    cin >> v[i];
    have[neg(v[i])] = v[i];
  }

  for(int i = 0; i < MAXB; i++) forn(bm, 1 << MAXB) {
    if (bm & 1 << i)
      have[bm ^ 1 << i] = max(have[bm ^ 1 << i], have[bm]);
  }

  for(int x : v) cout << have[x] << " ";
  cout << "\n";
}
