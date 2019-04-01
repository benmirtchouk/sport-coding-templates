#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

class R_Tree {
public:
  R_Tree(int n): maxn(n), sum(4 * n + 1), flipped(4 * n + 1) {};

  void push_down(int n, int l, int r) {
    if (!flipped[n]) return;

    if (l != r) {
      flipped[2 * n] = !flipped[2 * n];
      flipped[2 * n + 1] = !flipped[2 * n + 1];
    }

    sum[n] = (r - l + 1) - sum[n];
    flipped[n] = 0;
  }

  int get_sum(int n, int l, int r, int lo, int hi) {
    push_down(n, l, r);

    if (l >= lo && r <= hi)
      return sum[n];
    else if (!(lo > r || l > hi) && l != r) {
      int c = (l + r) / 2;
      return get_sum(2 * n, l, c, lo, hi) +
             get_sum(2 * n + 1, c + 1, r, lo, hi);
    }

    return 0;
  }

  void flip(int n, int l, int r, int lo, int hi) {
    push_down(n, l, r);

    if (l >= lo && r <= hi) {
      flipped[n] = !flipped[n];
      push_down(n, l, r);
    } else if (!(lo > r || l > hi) && l != r) {
      int c = (l + r) / 2;
      flip(2 * n, l, c, lo, hi);
      flip(2 * n + 1, c + 1, r, lo, hi);
      sum[n] = sum[2 * n] + sum[2 * n + 1];
    }
  }

  int get_sum(int lo, int hi) {
    return get_sum(1, 1, maxn, lo, hi);
  }

  void flip(int lo, int hi) {
    flip(1, 1, maxn, lo, hi);
  }

  int maxn;
  vector<int> sum;
  vector<bool> flipped;
};

int main() {
  R_Tree t(10);

  for(int i = 1; i <= 10; i++) cout << t.get_sum(i, i) << " \n"[i == 10];
  t.flip(3, 5);
  for(int i = 1; i <= 10; i++) cout << t.get_sum(i, i) << " \n"[i == 10];
  t.flip(1, 4);
  for(int i = 1; i <= 10; i++) cout << t.get_sum(i, i) << " \n"[i == 10];


}
