#include <bits/stdc++.h>

#define inf (LLONG_MAX/2)

using namespace std;
typedef long long ll;

class R_Tree {
public:
  R_Tree(int x): maxn(x), sz(4 * x + 1), sum(4 * x + 1), mx(4 * x + 1), lazy(4 * x + 1) {};

  void push_down(int x, int l, int r) {
    if (l != r) {
      lazy[2 * x] += lazy[x];
      lazy[2 * x + 1] += lazy[x];
    }

    mx[x] += lazy[x];
    sum[x] += lazy[x] * (r - l + 1);
    lazy[x] = 0;
  }

  ll get_sum(int n, int l, int r, int lo, int hi) {
    ll ans = 0;

    push_down(n, l, r);

    if (l >= lo && r <= hi)
      ans += sum[n];
    else if (!(lo > r || l > hi) && l != r) {
      int c = (l + r) / 2;
      ans += get_sum(2 * n, l, c, lo, hi);
      ans += get_sum(2 * n + 1, c + 1, r, lo, hi);
    }

    return ans;
  }

  ll get_sum(int lo, int hi) {
    return get_sum(1, 1, maxn, lo, hi);
  }

  ll get_max(int n, int l, int r, int lo, int hi) {
    ll ans = -inf;

    push_down(n, l, r);

    if (l >= lo && r <= hi)
      ans = max(ans, mx[n]);
    else if (!(lo > r || l > hi) && l != r) {
      int c = (l + r) / 2;
      ans = max(get_max(2 * n, l, c, lo, hi), get_max(2 * n + 1, c + 1, r, lo, hi));
    }

    return ans;
  }

  ll get_max(int lo, int hi) {
    return get_max(1, 1, maxn, lo, hi);
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
      int c = (l + r) / 2;
      sum[n] += val * overlap(lo, hi, l, r);

      if (l != r) {
        increment(2 * n, l, c, lo, hi, val);
        increment(2 * n + 1, c + 1, r, lo, hi, val);
      }

      mx[n] = sum[n];
      if (l != r)
        mx[n] = max(mx[2 * n], mx[2 * n + 1]);
    }
  }

  void increment(int lo, int hi, ll val) {
    increment(1, 1, maxn, lo, hi, val);
  }

  int maxn, sz;
  vector<ll> sum, mx, lazy;
};

int main(){

}
