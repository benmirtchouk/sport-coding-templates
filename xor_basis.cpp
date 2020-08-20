#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
typedef long long ll;

// dim
const int d = 20;

struct basis {
  basis(): sz(0), b(d) {}
  void insert(ll bm) {
    forn(i, d) if (bm >> i & 1)
      if (!b[i]) {
        b[i] = bm;
        sz++;
        return;
      } else bm ^= b[i];
  }
  bool has(ll bm) {
    forn(i, d) if (bm >> i & 1)
      if (!b[i]) return 0;
      else bm ^= b[i];
    assert(!bm);
    return 1;
  }

  vector<ll> b;
  int sz;
};

int main() {
  basis b;
  while(true){
    ll x;
    cin >> x;
    if (b.has(x)) cout << "already inside\n";
    else b.insert(x);
  }
}
