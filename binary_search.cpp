#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  forn(i, n) cin >> a[i];
  sort(all(a), greater<int>());

  function<bool(int)> check = [&](int d) {
    ll w = 0;
    forn(i, n) w += max(a[i] - i / d, 0);
    return w >= m;
  };

  int lo = 0, hi = n;
  if (!check(hi)) {
    cout << "-1\n";
    return 0;
  }

  while(lo + 1 < hi) { // (lo, hi]
    int mid = (lo + hi) / 2;

    if (check(mid))
      hi = mid;
    else
      lo = mid;
  }

  cout << hi << "\n";
}
