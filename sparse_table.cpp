#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;

vector<vector<int>> tab;

// f should be commutative and associative of course
int f(int a, int b) {
  return __gcd(a, b);
}

void gen_table(vector<int>& v) {
  int lg2 = 1, n = v.size(), tmp = v.size();
  while((tmp /= 2) && ++lg2);

  //tab[i][j] = f on range [i, i+2^j-1]
  tab = vector<vector<int>>(v.size(), vector<int>(lg2 + 1));
  forn(i, n) tab[i][0] = v[i];

  forn(sz, lg2) for(int i = 0; i < n - (1 << sz); i++)
    tab[i][sz + 1] = f(tab[i][sz], tab[i + (1 << sz)][sz]);
}

// f on [l,r]
int get_f(int l, int r) {
  int lg2 = 0, sz = r - l;
  while((sz /= 2) && ++lg2);

  return f(tab[l][lg2], tab[r - (1 << lg2) + 1][lg2]);
}


int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  forn(i, n) cin >> v[i];

  gen_table(v);


}
