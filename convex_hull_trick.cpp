#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

#define m first
#define b second
#define inf (2e18)

using namespace std;
typedef pair<ll, ll> pii;

vector<pii> lines;

double intersection(pii l1, pii l2) {
  return 1.0 * (l2.b - l1.b) / (l1.m - l2.m);
}

void add_line(pii& ln) {
  if (!lines.size()) {
    lines.push_back(ln);
    return;
  }

  while(lines.size() >= 2) {
    double i12 = intersection(lines[lines.size() - 2], lines[lines.size() - 1]);
    double i13 = intersection(lines[lines.size() - 2], ln);

    if (i13 < i12) lines.pop_back();
    else break;
  }

  lines.push_back(ln);

}

ll query(double x) {
  int lo = 0, hi = lines.size();
  // lines[lo].left <= x <= lines[hi].right
  while(lo < hi) {
    int mid = (lo + hi) / 2;

    double left = -inf, right = inf;
    if (mid != 0) left = intersection(lines[mid - 1], lines[mid]);
    if (mid != lines.size() - 1) right = intersection(lines[mid], lines[mid + 1]);

    if (left > x)
      hi = mid - 1;
    else if (right < x)
      lo = mid + 1;
    else
      lo = hi = mid;
  }

  return lines[lo].m * x + lines[lo].b;
}

// for example see cf 319C
int main() {
  vector<pii> inp{{14, 0}, { -5, 10}, {2, 3}, {7, 1}};
  sort(all(inp), [&](const pii & a, const pii & b) {
    return a.m > b.m || (a.m == b.m && a.b < b.b);
  });

  int sp = 0;
  for(int i = 1; i < inp.size(); i++)
    if (inp[i].m != inp[sp].m)
      inp[++sp] = inp[i];
  inp.resize(sp + 1);

  for(pii& ln : inp)
    add_line(ln);

  for (double x = 0; x < 2; x += 0.1)
    cout << x << ": " << query(x) << "\n";

}
