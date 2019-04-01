#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;

int main() {
  int n = 1e6;
  vector<int> v(n);
  iota(all(v), 0);

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  mt19937 g1(seed);

  cout << g1() << "\n";
  shuffle(all(v), mt19937(seed));
}
