#include <bits/stdc++.h>
#define inf (1<<30)

using namespace std;
typedef pair<int, int> pii;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<ll>> adj(n, vector<ll>(n, inf));

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;

    adj[a - 1][b - 1] = min(adj[a - 1][b - 1], 1ll * w);
    adj[b - 1][a - 1] = min(adj[b - 1][a - 1], 1ll * w);
  }

  vector<ll> dist(n, inf);
  vector<bool> done(n);

  int s;
  cin >> s;
  s--;

  dist[s] = 0;

  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int j = 0; j < n; j++)
      if (!done[j] && (u == -1 || dist[j] < dist[u]))
        u = j;

    done[u] = 1;

    for (int j = 0; j < n; j++)
      if (!done[j])
        dist[j] = min(dist[j], dist[u] + adj[u][j]);
  }

  for (int i = 0; i < n; i++)
    if (i != s)
      cout << (dist[i] < inf ? dist[i] : -1) << " ";
  cout << "\n";

  return 0;
}

