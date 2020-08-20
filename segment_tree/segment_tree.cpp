#include <bits/stdc++.h>

#define MAXN 200000
#define inf (LLONG_MAX/2)

using namespace std;

typedef long long ll;

ll sum[4 * MAXN], mn[4 * MAXN], lazy[4 * MAXN];

void push_down(int x, int l, int r) {
  if (l != r) {
    lazy[x * 2] += lazy[x];
    lazy[x * 2 + 1] += lazy[x];
  }

  mn[x] += lazy[x];
  sum[x] += lazy[x] * (r - l + 1);
  lazy[x] = 0;
}

ll get(int n, int l, int r, int idx) {
  while(l != r) {
    int c = (l + r) / 2;

    push_down(n, l, r);

    if (idx <= c) {
      n = 2 * n;
      r = c;
    } else {
      n = 2 * n + 1;
      l = c + 1;
    }
  }

  push_down(n, l, r);
  return sum[n];
}

int get(int idx) {
  return get(1, 1, MAXN, idx);
}

ll get_sum(int n, int l, int r, int lo, int hi) {
  push_down(n, l, r);

  if (l >= lo && r <= hi)
    return sum[n];
  else if (!(lo > r || l > hi) && l != r) {
    int c = (l + r) / 2;
    return get_sum(n * 2, l, c, lo, hi) + get_sum(n * 2 + 1, c + 1, r, lo, hi);
  }

  return 0;
}

ll get_sum(int lo, int hi) {
  return get_sum(1, 1, MAXN, lo, hi);
}

ll get_min(int n, int l, int r, int lo, int hi) {
  push_down(n, l, r);

  if (l >= lo && r <= hi)
    return mn[n];
  else if (!(lo > r || l > hi) && l != r) {
    int c = (l + r) / 2;
    return min(get_min(n * 2, l, c, lo, hi), get_min(n * 2 + 1, c + 1, r, lo, hi));
  }

  return inf;
}

ll get_min(int lo, int hi) {
  return get_min(1, 1, MAXN, lo, hi);
}

int overlap(int a, int b, int c, int d) {
  int ideal = (d - c + 1) + (b - a + 1);
  int actual = max(d, b) - min(a, c) + 1;

  return ideal - actual;
}

void increment(int n, int l, int r, int lo, int hi, ll val) {
  push_down(n, l, r);

  if (l >= lo && r <= hi) {
    lazy[n] += val;
    push_down(n, l, r);
  } else if (!(lo > r || l > hi)) {
    assert(l != r);
    int c = (l + r) / 2;
    sum[n] += val * overlap(lo, hi, l, r);

    increment(n * 2, l, c, lo, hi, val);
    increment(n * 2 + 1, c + 1, r, lo, hi, val);

    mn[n] = min(mn[n * 2], mn[n * 2 + 1]);
  }
}

void increment(int lo, int hi, ll val) {
  increment(1, 1, MAXN, lo, hi, val);
}
