#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
typedef long long ll;

int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll exp(ll a, int p, ll m) {
  if (!a) return 0;
  ll ans = 1;
  while(p) {
    if (p & 1)
      ans = (ans * a) % m;
    a = (a * a) % m;
    p >>= 1;
  }
  return ans;
}

bool miller_rabin(ll n) {
  if (n == 1) return 0;
  int r = 0, i;
  ll cpn = n - 1;
  while(cpn & 1 == 0) {
    r++;
    cpn /= 2;
  }
  int d = (n - 1) >> r;

  for(int p : prime) {
    if (n == p) return 1;
    ll x = exp(p, d, n);
    if (x == 1 || x == n - 1) continue;
    for(i = 0; i < r - 1; i++) {
      x = (x * x) % n;
      if (x == n - 1) break;
    }
    if (i != r - 1) return 0;
  }

  return 1;
}

int main() {
//  ll n;
//  cin >> n;
  int cnt = 0;
  for(ll n = 1; n <= 1e5; n++) {
    cnt += miller_rabin(n);
  }
  cout << cnt << "\n";
}
