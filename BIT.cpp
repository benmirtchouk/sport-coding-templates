#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MAXN (1<<19)
using namespace std;

int BT[2][MAXN];

// vals[x] += v
void add(int x, int v, int T[]) {
  for(x++; x < MAXN; x += x & -x)
    T[x] += v;
}

// return sum of vals[i], 0 <= i <= x
int get(int x, int T[]) {
  int ret = 0;
  for(x++; x > 0; x &= x - 1)
    ret += T[x];
  return ret;
}
