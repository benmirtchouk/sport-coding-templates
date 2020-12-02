#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

struct BIT{
  BIT(int n): MAXN(2*n), BT(2*n) {}

  // vals[x] += v
  void add(int x, int v) {
    for(x++; x < MAXN; x += x & -x)
      BT[x] += v;
  }

  // return sum of vals[i], 0 <= i <= x
  int get(int x) {
    int ret = 0;
    for(x++; x > 0; x &= x - 1)
      ret += BT[x];
    return ret;
  }

  int MAXN;
  vector<int> BT;
};
