#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;
typedef complex<double> cd;

vector<cd> fft(vector<cd> a, bool inverse = false) {
  int n = a.size();
  if (n == 1) return a;

  vector<cd> even(n / 2), odd(n / 2);
  forn(i, n / 2) {
    even[i] = a[2 * i];
    odd[i] = a[2 * i + 1];
  }
  vector<cd> lhs = fft(even, inverse), rhs = fft(odd, inverse);

  cd w = 1;
  cd w_n = {cos(2 * M_PI / n), sin(2 * M_PI / n)};
  if (inverse) w_n = cd(1) / w_n;

  vector<cd> out(n);
  forn(k, n / 2) {
    out[k] = lhs[k] + w * rhs[k];
    out[k + n / 2] = lhs[k] - w * rhs[k];
    w *= w_n;
  }

  return out;
}

vector<cd> multiply(vector<cd> a, vector<cd> b) {
  int n;
  for(n = 1; n < max(a.size(), b.size()); n *= 2);

  a.resize(2 * n);
  b.resize(2 * n);
  n *= 2;
  vector<cd> pt_a = fft(a), pt_b = fft(b), pt_c(n);

  forn(i, n) pt_c[i] = pt_a[i] * pt_b[i];

  vector<cd> c = fft(pt_c, true);
  forn(i,n) c[i] /= n;

  return c;
}

int main() {
  int n = 2;
  vector<cd> a{5, -3, 0.2, 3, 8}, b{ -1, 4, -1, 1, 1, 5, 3};

  auto c = multiply(a, b);
  cout << "\nc coeff form:\n";
  forn(i, c.size()) cout << c[i].real() << "\n";
}
