#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000000007
using namespace std;
typedef long long ll;

struct num {
  num(ll x=0): x(x) {}
  num& operator+=(const num& m) { x = (x + m.x) % MOD; return *this; }
  num& operator*=(const num& m) { x = (x * m.x) % MOD; return *this; }

  num exp(ll p) {
    if (p < 0) p = p % (MOD - 1) + MOD - 1;
    num a = x, ans = 1;
    while(p) {
      if (p & 1) ans *= a;
      a *= a;
      p >>= 1;
    }
    return ans;
  }

  ll x;
};

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

int main() {


}
