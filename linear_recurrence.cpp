#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Mn;

ll exp(ll a, ll p, ll mod) {
  if (!a) return 0;
  ll ans = 1;
  while(p) {
    if (p & 1)
      ans = (ans * a) % mod;
    a = (a * a) % mod;
    p >>= 1;
  }
  return ans;
}

int N = 3;

Mn mult(Mn a, Mn b, ll mod) {
  Mn ans(N, vector<ll>(N));
  forn(i, N) forn(j, N) forn(k, N) {
    ans[i][k] += a[i][j] * b[j][k];
    ans[i][k] %= mod;
  }

  return ans;
}

Mn exp(Mn A, ll p, ll mod) {
  Mn ans(N, vector<ll>(N));
  forn(i, N) ans[i][i] = 1;
  while(p) {
    if (p & 1) ans = mult(ans, A, mod);
    A = mult(A, A, mod);
    p >>= 1;
  }
  return ans;
}

int main() {
  ll n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;

  Mn M{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
  M = exp(M, n - 3, MOD - 1);

  ll x = M[2][0], y = M[2][1], z = M[2][2];
  ll p = ((x + 2 * y + 3 * z - n) % (MOD - 1) + MOD - 1) % (MOD - 1);

  ll ans = exp(c, p, MOD);
  ans = (ans * exp(f1, x, MOD)) % MOD;
  ans = (ans * exp(f2, y, MOD)) % MOD;
  ans = (ans * exp(f3, z, MOD)) % MOD;

  cout << ans << "\n";
}
