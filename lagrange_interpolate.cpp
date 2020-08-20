#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 998244353
using namespace std;
typedef long long ll;

ll fact[MAXN], invfact[MAXN];

// p = { f(0), f(1), ..., f(n) }
// return f(x)
ll lagrange(vector<ll>& p, ll x) {
  int n = p.size() - 1;
  if (x <= n) return p[x];

  vector<ll> pref(n + 1, 1), suf(n + 1, 1);
  for (int i = 0; i < n; i++) pref[i + 1] = pref[i] * (x - i) % MOD;
  for (int i = n; i > 0; i--) suf[i - 1] = suf[i] * (x - i) % MOD;

  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ll tmp = p[i] * pref[i] % MOD * suf[i] % MOD * invfact[i] % MOD * invfact[n - i] % MOD;
    if ((n - i) & 1) ans -= tmp;
    else ans += tmp;
    ans %= MOD;
  }

  return (ans + MOD) % MOD;
}

int main() {
  fact[0] = 1;
  for(int i = 1; i < MAXN; i++)
    fact[i] = i * fact[i - 1] % MOD;
  invfact[MAXN - 1] = exp(fact[MAXN - 1], MOD - 2);
  for(int i = MAXN - 2; i >= 0; i--)
    invfact[i] = i * invfact[i + 1] % MOD;
}
