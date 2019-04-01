#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

#define epsilon (1e-12)
using namespace std;

function<double(double)> f;

double s(double l, double r) {
  return (r - l) / 6 * (f(r) + f(l) + 4 * f((r + l) / 2));
}

double integral(double l, double r) {
  double m = (l + r) / 2;
  double lhs = s(l, m), rhs = s(m, r), tot = s(l, r);

  if (abs(lhs + rhs - tot) < epsilon)
    return tot;

  return integral(l, m) + integral(m, r);
}

int main() {
  f = [&](double x) {
    return ((x*x-1)*exp(-x*x))*(((x*x*x-3*x))*exp(-x*x));
  };

//  cout << f(20) << "\n";
  cout << integral(-3, 3) << "\n";
}
