#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MAXN 200000
using namespace std;
typedef long long ll;

ll mx[4 * MAXN], lazy[4 * MAXN];

void push_down(int x, int l, int r) {
  if (l != r) {
    lazy[x * 2] += lazy[x];
    lazy[x * 2 + 1] += lazy[x];
  }

  mx[x] += lazy[x];
  lazy[x] = 0;
}

ll get_max(int n, int l, int r, int lo, int hi) {
  push_down(n, l, r);

  if (l >= lo && r <= hi)
    return mx[n];
  else if (!(lo > r || l > hi) && l != r) {
    int c = (l + r) / 2;
    return max(get_max(n * 2, l, c, lo, hi), get_max(n * 2 + 1, c + 1, r, lo, hi));
  }

  return -1;
}

ll get_max(int lo, int hi) {
  return get_max(1, 1, MAXN, lo, hi);
}

void increment(int n, int l, int r, int lo, int hi, ll val) {
  push_down(n, l, r);

  if (l >= lo && r <= hi) {
    lazy[n] += val;
    push_down(n, l, r);
  } else if (!(lo > r || l > hi)) {
    assert(l != r);
    int c = (l + r) / 2;

    increment(n * 2, l, c, lo, hi, val);
    increment(n * 2 + 1, c + 1, r, lo, hi, val);

    mx[n] = max(mx[n * 2], mx[n * 2 + 1]);
  }
}

void increment(int lo, int hi, ll val) {
  increment(1, 1, MAXN, lo, hi, val);
}

int n;
vector<vector<int>> amx;

void gen_table(vector<int>& v) {
  int lg2 = 1, tmp = n;
  while((tmp /= 2) && ++lg2);

  amx = vector<vector<int>>(n, vector<int>(lg2 + 1));
  forn(i, n) amx[i][0] = v[i];

  forn(sz, lg2) for(int i = 0; i < n - (1 << sz); i++)
    amx[i][sz + 1] = max(amx[i][sz], amx[i + (1 << sz)][sz]);
}

int get_mx(int l, int r) {
  int lg2 = 0, sz = r - l;
  while((sz /= 2) && ++lg2);

  return max(amx[l][lg2], amx[r - (1 << lg2) + 1][lg2]);
}

int main() {
  ios;
  int m;
  cin >> n >> m;

  vector<int> a(n);
  forn(i, n) cin >> a[i];
  gen_table(a);

  vector<int> g(m, -1);
  vector<pair<int, int>> q(m);
  forn(i, m) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1)
      g[i] = get_mx(l - 1, r - 1);
    else
      q[i] = {l, r};
  }

  forn(i, m) {
    if (g[i] == -1)
      g[i] = get_max(q[i].first, q[i].second);

    increment(i + 1, i + 1, g[i]);
    cout << g[i] << "\n";
  }
}
