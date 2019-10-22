#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

// 998244353 = 1 + 119 * 2^23
// 3 = generator mod 998244353
#define MOD 998244353
#define C 23
#define K 119
#define R 3

using namespace std;
typedef long long ll;

struct num {
  num(ll x = 0): x((x % MOD + MOD) % MOD) {}
  num& operator+=(const num& m) {
    x = (x + m.x) % MOD;
    return *this;
  }
  num& operator-=(const num& m) {
    x = (x - m.x + MOD) % MOD;
    return *this;
  }
  num& operator*=(const num& m) {
    x = (x * m.x) % MOD;
    return *this;
  }

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

num operator*(num a, num b) {
  num ret(a);
  ret *= b;
  return ret;
}
num operator+(num a, num b) {
  num ret(a);
  ret += b;
  return ret;
}
num operator-(num a, num b) {
  num ret(a);
  ret -= b;
  return ret;
}

void prnt(vector<num>& v) {
  cout << "[";
  forn(i, v.size()) cout << v[i].x << " ]"[i == v.size() - 1];
}

vector<num> ntt(vector<num> a, bool inverse = false) {
  int n = a.size();
  if (n == 1) return a;

  vector<num> even(n / 2), odd(n / 2);
  forn(i, n / 2) {
    even[i] = a[2 * i];
    odd[i] = a[2 * i + 1];
  }
  vector<num> lhs = ntt(even, inverse), rhs = ntt(odd, inverse);

  num w(1);
  ll c = (MOD - 1) / n;
  num w_n = num(R).exp(c);
  if (inverse) w_n = w_n.exp(-1);

  vector<num> out(n);
  forn(k, n / 2) {
    out[k] = lhs[k] + w * rhs[k];
    out[k + n / 2] = lhs[k] - w * rhs[k];
    w *= w_n;
  }

  return out;
}

vector<num> multiply(vector<num> a, vector<num> b) {
  int n;
  for(n = 1; n < max(a.size(), b.size()); n *= 2);

  a.resize(2 * n);
  b.resize(2 * n);
  n *= 2;

  vector<num> pt_a = ntt(a), pt_b = ntt(b), pt_c(n);
  forn(i, n) pt_c[i] = pt_a[i] * pt_b[i];

  vector<num> c = ntt(pt_c, true);
  forn(i, n) c[i] *= num(n).exp(-1);

  return c;
}

int main() {
  int n = 2;
  vector<num> a{5, -3, 2, 3, 8}, b{ -1, 4, -1};

  auto c = multiply(a, b);
  cout << "c coeff form:\n";
  forn(i, c.size()) cout << c[i].x << "\n";
}
