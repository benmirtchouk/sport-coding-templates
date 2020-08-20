#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define inf (1ll<<60)
using namespace std;
typedef long long ll;

int main() {
  ios;
  int n, m;
  cin >> n >> m;

  vector<vector<ll>> dist(n, vector<ll>(n, inf));
  forn(i, m) {
    int a, b, w;
    cin >> a >> b >> w;
    dist[a - 1][b - 1] = w;
    dist[b - 1][a - 1] = w;
  }

  vector<ll> cost(n, inf);
  vector<bool> done(n);

  cost[0] = 0;
  forn(i, n) {
    int u = -1;
    forn(j, n) if (!done[j])
      if (u == -1 || cost[j] < cost[u]) u = j;

    if (cost[u] == inf) break;
    done[u] = 1;

    forn(j, n) if (!done[j])
      if (dist[u][j] < cost[j])
        cost[j] = dist[u][j];
  }

  ll ans = 0;
  forn(i, n) {
    if (cost[i] == inf) {
      cout << "-1\n";
      return 0;
    }
    ans += cost[i];
  }
  cout << ans << "\n";
}
