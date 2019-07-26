#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000000007
#define MODe (MOD-1)
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Mn;

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

Mn mult(Mn a, Mn b) {
  assert(a[0].size() == b.size());

  Mn ans(a.size(), vector<ll>(b[0].size()));
  forn(i, a.size()) forn(j, b.size()) forn(k, b[0].size()) {
    ans[i][k] += (a[i][j] * b[j][k]) % MODe;
    ans[i][k] %= MODe;
  }

  return ans;
}

Mn exp(Mn A, ll p) {
  if (p == 1) return A;
  if (p % 2) return mult(A, exp(A, p - 1));
  Mn X = exp(A, p / 2);
  return mult(X, X);
}

int main() {
  ll n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;

  Mn M{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
  M = exp(M, n - 3);

  ll x = M[2][0], y = M[2][1], z = M[2][2];
  ll p = ((x + 2 * y + 3 * z - n) % MODe + MODe) % MODe;

  ll ans = exp(c, p);
  ans = (ans * exp(f1, x)) % MOD;
  ans = (ans * exp(f2, y)) % MOD;
  ans = (ans * exp(f3, z)) % MOD;

  cout << ans << "\n";
}
