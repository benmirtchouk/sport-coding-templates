#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;

int main() {
  int n = 1e5;

  vector<int> p, lp(n + 1);

  for(int i = 2; i <= n; i++) {
    if (!lp[i]) {
      lp[i] = i;
      p.push_back(i);
    }

    for(int j = 0; j < p.size() && p[j] <= lp[i] && p[j]*i <= n; j++)
      lp[p[j] * i] = p[j];
  }

  cout << "ready\n";
  while(1){
    int x;
    cin >> x;

    while(x!=1){
      cout << lp[x] << " ";
      x/=lp[x];
    }
    cout << "\n\n";
  }
}
