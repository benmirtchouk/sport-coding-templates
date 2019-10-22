#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

// this solves codeforces.com/contest/13/problem/E

int sq = sqrt(1e5), n;
vector<int> a, cnt, f;
// cnt[i] = number of steps leave block i/sq
// f[i] = idx of last before exit

void calc(int b) {
  int first = b * sq, last = min((b + 1) * sq - 1, n - 1);

  for (int i = last; i >= first; i--) {
    int nxt = i + a[i];

    if (nxt > last) {
      cnt[i] = 1;
      f[i] = i;
    } else {
      cnt[i] = 1 + cnt[nxt];
      f[i] = f[nxt];
    }
  }
}

int main() {
  ios;
  int q, t, idx, b;
  cin >> n >> q;

  a.resize(n);
  f.resize(n);
  cnt.resize(n);

  forn(i, n) cin >> a[i];
  for(int i = 0; i * sq < n; i++) calc(i);

  while(q--) {
    cin >> t;

    if (t == 0) {
      cin >> idx >> b;
      idx--;

      a[idx] = b;
      calc(idx / sq);
    } else if (t == 1) {
      cin >> idx;
      idx--;

      int hop = 0, prev = idx;
      while(idx < n) {
        hop += cnt[idx];

        idx = f[idx];
        prev = f[idx];
        idx += a[idx];
      }

      cout << prev + 1 << " " << hop << "\n";
    }
  }
}
