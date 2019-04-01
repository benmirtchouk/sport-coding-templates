#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

bool play(int a, int b) {
  cout << "? " << a << " " << b << endl;
  char r;
  cin >> r;
  return r == '>';
}

int main() {
  int n;
  cin >> n;

  vector<int> t(n);
  iota(all(t), 0);

  for(int i = 0; i + 1 < t.size(); i += 2) {
    if (play(t[i], t[i + 1]))
      t.push_back(t[i]);
    else
      t.push_back(t[i + 1]);
  }

  cout << "! " << t.back() << endl;
}
