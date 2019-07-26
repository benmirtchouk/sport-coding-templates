#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define inf (1ll<<60)
using namespace std;
typedef long long ll;

void relax(int i, int j, int k, vector<vector<ll>>& dist) {
  if (dist[i][j] > dist[i][k] + dist[k][j])
    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
  int n, m, a, b;
  ll w;
  cin >> n >> m;

  vector<vector<ll>> dist(n, vector<ll>(n, inf));
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    dist[a][b] = dist[b][a] = w; //undirected
  }

  forn(k, n) forn(i, n) forn(j, n) relax(i, j, k, dist);

  return 0;
}
