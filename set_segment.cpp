#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define inf 1000000000
using namespace std;
typedef long long ll;

struct segset {
  segset(): seg(), length(0) {}

  void insert(ll a, ll b) {
    if (seg.size() == 0) {
      seg.insert({a, b});
      length = b - a;
      return;
    }
    pair<ll, ll> nw{a, b};

    auto lo = seg.upper_bound({a, inf});
    if (lo != seg.begin()) {
      --lo;
      if (lo->second >= a)
        nw.first = lo->first;
    }

    auto hi = seg.upper_bound({b, inf});
    if (hi != seg.begin()) {
      --hi;
      if (hi->second >= b)
        nw.second = hi->second;
    }

    while(seg.size() > 0) {
      auto it = seg.lower_bound({nw.first, -inf});
      if (it == seg.end() || it->second > nw.second) break;

      length -= (it->second - it->first);
      seg.erase(it);
    }

    length += (nw.second - nw.first);
    seg.insert(nw);
  }

  set<pair<ll, ll>> seg;
  ll length;
};

int main() {
  int n;
  cin >> n;

  segset segs;
  forn(i, n) {
    int l, r;
    cin >> l >> r;
    segs.insert(l, r);
    cout << segs.length << "\n";
  }
}
