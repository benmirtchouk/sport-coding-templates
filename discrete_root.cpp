#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

#define MOD 998244353
//g is a generator mod MOD
#define g 3

using namespace std;
typedef long long ll;

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

//find x s.t. a^x = b (mod m)
ll discrete_log(ll a, ll b) {
  ll n = sqrt(MOD) + 1;
  unordered_map<ll, ll> f1;

  ll an = 1, anp = 1;
  forn(i, n) an = (an * a) % MOD;
  for(int p = 0; p <= n; p++) {
    f1[anp] = p;
    anp = (anp * an) % MOD;
  }

  ll aq = 1;
  for(int q = 0; q <= n; q++) {
    ll f2 = (b * aq) % MOD;
    if (f1.find(f2) != f1.end())
      return (n * f1[f2] - q + MOD) % MOD;

    aq = (aq * a) % MOD;
  }

  return -1;
}

// find x s.t. x^k = a (mod m)
ll discrete_root(ll k, ll a) {
  //x = g^y -> a = (g^k)^y
  ll gk = exp(g, k);
  ll y = discrete_log(gk, a);
  return exp(g, y);
}

int main() {
  cout << discrete_root(27, 100) << "\n";
}
