#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;

vector<vector<int>> mx;

void gen_table(vector<int>& v) {
  int lg2 = 1, n = v.size(), tmp = v.size();
  while((tmp /= 2) && ++lg2);

  //mx[i][j] = max on range [i, i+2^j-1]
  mx = vector<vector<int>>(v.size(), vector<int>(lg2 + 1));
  forn(i, n) mx[i][0] = v[i];

  forn(sz, lg2) for(int i = 0; i < n - (1 << sz); i++)
    mx[i][sz + 1] = max(mx[i][sz], mx[i + (1 << sz)][sz]);
}

// max on [l,r]
int get_max(int l, int r) {
  int lg2 = 0, sz = r - l;
  while((sz /= 2) && ++lg2);

  return max(mx[l][lg2], mx[r - (1 << lg2) + 1][lg2]);
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  forn(i, n) cin >> v[i];

  gen_table(v);


}
