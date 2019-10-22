#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000003
using namespace std;
typedef long long ll;

// n = rows, m = cols
int n = 11;
int m = n + 1;

ll exp(ll a, ll p) {
  if (!a) return 0;
  ll ans = 1;
  while(p) {
    if (p & 1)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    p >>= 1;
  }
  return ans;
}

ll inv(ll x) {
  return exp(x, MOD - 2);
}

void eliminate(vector<ll>& row, vector<ll>& one, int col) {
  ll v = row[col];
  forn(i, m) {
    row[i] -= v * one[i];
    row[i] = (row[i] % MOD + MOD) % MOD;
  }
}

int main() {
  vector<ll> y(n);
  forn(i, n) {
    cout << "? " << i << endl;
    cin >> y[i];
  }

  vector<vector<ll>> M(n, vector<ll>(m));

  // build matrix [[1,0,0,...,y0], [1,1,1,...,y1], [1,2,4,...,y2], ...]
  forn(i, n) {
    M[i][0] = 1;
    for(int j = 1; j < m - 1; j++)
      M[i][j] = (M[i][j - 1] * i) % MOD;
    M[i][m - 1] = y[i];
  }

  forn(i, min(n, m)) {
    // find first row with nonzero element in column i and make it row i
    for(int j = i; j < n; j++) if (M[j][i] != 0) {
        swap(M[i], M[j]);
        break;
      }

    // set M[i][i] to 1
    ll f = inv(M[i][i]);
    forn(j, m) {
      M[i][j] *= f;
      M[i][j] %= MOD;
    }

    // set M[x][i] to 0 for x != i
    forn(j, n) if (j != i) eliminate(M[j], M[i], i);
  }

  forn(i, n) forn(j, m) cout << M[i][j] << "\t\n"[j == m - 1];
}
