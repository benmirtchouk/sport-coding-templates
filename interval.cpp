#include <bits/stdc++.h>
#define inf (1e9)
#define low first
#define high second

typedef pair<int, int> pii;

set<pii> intervals;

struct I_Nd {
  I_Nd(int a, int b): i(a, b), mx(b), l(0), r(0) {}
  I_Nd(pii p): i(p.low, p.high), mx(p.high), l(0), r(0) {}

  pii i;
  int mx;
  I_Nd *l, *r;
};

I_Nd* insert(I_Nd *r, pii i) {
  if (r == 0)
    return new I_Nd(i);

  int l = r->i.low;

  if (i.low < l)
    r->l = insert(r->l, i);
  else
    r->r = insert(r->r, i);

  if (r->mx < i.high)
    r->mx = i.high;

  return r;
}

bool overlap(pii i1, pii i2) {
  return i1.low <= i2.high && i2.low <= i1.high;
}

pii search(I_Nd *r, pii i) {
  if (r == 0) return {-1,-1};

  if (overlap(r->i, i))
    return r->i;

  if (r->l != 0 && r->l->mx >= i.low)
    return search(r->l, i);

  return search(r->r, i);
}
