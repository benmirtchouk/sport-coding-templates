#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;

int main() {
  int n,k;
  cin >> n >> k;

  vector<int> v(n);
  forn(i, n) cin >> v[i];

  deque<pair<int, int>> window;
  forn(i, n) {
    while (!window.empty() && window.back().first >= v[i])
      window.pop_back();
    window.push_back({v[i], i});

    while(window.front().second <= i - k)
      window.pop_front();

    cout << (window.front().first) << ' ';
  }
}
