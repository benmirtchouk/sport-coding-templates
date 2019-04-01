#include <bits/stdc++.h>

#define inf (1e9)

using namespace std;

typedef pair<int, int> pii;

set<pii> segments;

void prnt() {
  for (auto it = segments.begin(); it != segments.end(); it++)
    cout << "[" << it->first << ", " << it->second << "] ";
  cout << "\n\n";
}

bool ins(int st, int en) {
  if (!segments.size()) {
    segments.insert({st, en});
    return 1;
  }

  auto lo = segments.upper_bound({st, inf});
  auto hi = segments.upper_bound({en, inf});
  if (hi != segments.begin()) hi--;
  bool sub = 0;
  if (lo != segments.begin()) {
    lo--;
    sub = 1;
  }

  bool stin = lo != segments.end() && (lo->first <= st && st <= lo->second);
  if (sub && !stin && lo != segments.end()) {
    lo++;
    stin = lo != segments.end() && (lo->first <= st && st <= lo->second);
  }
  bool enin = hi != segments.end() && (hi->first <= en && en <= hi->second);

  if (lo == hi && stin && enin)
    return 0;
  if (lo == hi && !stin && !enin) {
    if (st <= lo->first && hi->second <= en)
      segments.erase(lo,++hi);
    segments.insert({st, en});
    return 1;
  }

  int mn = st, mx = en;

  if (stin) mn = min(mn, lo->first);
  if (enin) mx = max(mx, hi->second);

  segments.erase(lo, ++hi);
  segments.insert(pii{mn, mx});

  return 1;
}

int main() {
  ins(5, 6);
  prnt();
  ins(1, 3);
  prnt();
  ins(2, 4);
  prnt();
  ins(10, 14);
  prnt();
  ins(-3, 0);
  prnt();
  ins(4, 5);
  prnt();
  ins(5, 7);
  prnt();
  ins(3, 4);
  prnt();
  ins(8, 9);
  prnt();
  ins(-1, 8);
  prnt();

  return 0;
}
