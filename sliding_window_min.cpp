#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;
typedef long long ll;

deque<int> Q;
void push(int x) {
  while (!Q.empty() && Q.back() > x)
    Q.pop_back();
  Q.push_back(x);
}

void one_dim() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  forn(i, n) cin >> v[i];

  forn(i, n) {
    push(v[i]);

    if (i >= k - 1) {
      cout << "[" << i - k << ", " << i << "] -> " << Q.front() << "\n";

      if (Q.front() == v[i - k + 1])
        Q.pop_front();
    }
  }
}

void two_dim() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  vector<vector<int>> v(n, vector<int>(m));
  forn(i, n) forn(j, m) cin >> v[i][j];

  vector<vector<int>> rows(n, vector<int>(m - b + 1));
  forn(i, n) {
    Q.clear();
    forn(j, m) {
      push(v[i][j]);

      if (j >= b - 1) {
        rows[i][j - b + 1] = Q.front();

        if (Q.front() == v[i][j - b + 1])
          Q.pop_front();
      }
    }
  }

  vector<vector<int>> ans(n - a + 1, vector<int>(m - b + 1));
  forn(j, m - b + 1) {
    Q.clear();
    forn(i, n) {
      push(rows[i][j]);

      if (i >= a - 1) {
        ans[i - a + 1][j] = Q.front();

        if (Q.front() == rows[i - a + 1][j])
          Q.pop_front();
      }
    }
  }

  ll f = 0;
  forn(i, n - a + 1) forn(j, m - b + 1) f += ans[i][j];
  cout << f << "\n";
}

int main() {
//  one_dim();
  two_dim();

}
