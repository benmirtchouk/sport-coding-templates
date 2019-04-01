#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

#define maxn (1 << 18)
using namespace std;

int BT[maxn];

// gdi dont use index 0 in a BIT you fool

void add(int x, int v) {
  x += maxn / 2; // if negatives are needed

  for(int i = x | maxn; i < (maxn << 1); i += i & -i)
    BT[i ^ maxn] += v;
}

int get(int x) {
  x += maxn / 2;

  int ret = 0;
  for(int i = x - 1; i && x != 0; i &= i - 1)
    ret += BT[i];

  return ret;
}

int main() {
  vector<int> v {5, 6, 13, 1, 5, 3};

  for (int i = 0; i < v.size(); i++)
    add(i, v[i]);

  cout << get(5) - get(2) << endl;
}
