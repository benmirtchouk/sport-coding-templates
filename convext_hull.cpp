#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

int cross(pii v, pii w) {
  return v.x * w.y - v.y * w.x;
}

int cross(pii a, pii b, pii c) {
  return cross({b.x - a.x, b.y - a.y}, {c.x - b.x, c.y - b.y});
}

vector<pii> convexh(vector<pii> pts) {
  int n = pts.size();
  sort(all(pts));

  vector<pii> hull;

  forn(lu, 2) {
    int zero = hull.size();

    forn(i, n) {
      while(hull.size() >= zero + 2 && cross(hull[hull.size() - 2], hull.back(), pts[i]) >= 0)
        hull.pop_back();

      if (!hull.size() || hull.back() != pts[i])
        hull.push_back(pts[i]);
    }

    reverse(all(pts));
  }

  return hull;
}

int main() {
  int n;
  cin >> n;

  vector<pii> pts(n);
  forn(i, n) cin >> pts[i].x >> pts[i].y;
  cout << "\n\n";

  vector<pii> hull = convexh(pts);
  forn(i, hull.size()) cout << hull[i].x << " " << hull[i].y << "\n";
}
