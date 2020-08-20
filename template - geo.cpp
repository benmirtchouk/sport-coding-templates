#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

struct vec {
  vec(double x, double y): x(x), y(y) {}
  double mag() {
    return sqrt(x * x + y * y);
  }
  void normalize() {
    double m = mag();
    x /= m;
    y /= m;
  }
  double x, y;
};

vec operator*(const double k, const vec v) {
  return {k * v.x, k * v.y};
}
vec operator+(const vec v, const vec w) {
  return {v.x + w.x, v.y + w.y};
}
vec rotate90(vec& v) {
  return {v.y, -v.x};
}
vec rotate180(vec& v) {
  return { -v.x, -v.y};
}
vec rotate270(vec& v) {
  return { -v.y, v.x};
}

void prnt(vec v) {
  cout << v.x << " " << v.y << "\n";
}

int main() {
  cout << fixed << setprecision(15);

}
