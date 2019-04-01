#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

#define x first
#define y second
#define inf (1<<29)
#define eps (1e-7)

using namespace std;
typedef pair<int, int> pii;

pii intersect(vector<double> seg1, vector<double> seg2) { // vectors len 4
  double s1_x = seg1[2] - seg1[0];
  double s1_y = seg1[3] - seg1[1];
  double s2_x = seg2[2] - seg2[0];
  double s2_y = seg2[3] - seg2[1];

  double s = (-s1_y * (seg1[0] - seg2[0]) + s1_x * (seg1[1] - seg2[1])) / (-s2_x * s1_y + s1_x * s2_y);
  double t = ( s2_x * (seg1[1] - seg2[1]) - s2_y * (seg1[0] - seg2[0])) / (-s2_x * s1_y + s1_x * s2_y);

  if (s >= -eps && s <= 1 + eps && t >= -eps && t <= 1 + eps) {
    // intersect
    double i_x = seg1[0] + (t * s1_x);
    double i_y = seg1[1] + (t * s1_y);

    // (i only wanted integer intersections in this implementation)
    if (abs(i_x - round(i_x)) < eps && abs(i_y - round(i_y)) < eps)
      return {round(i_x), round(i_y)};
  }

  // don't intersect
  return {inf, inf};
}
