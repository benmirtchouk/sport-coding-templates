#include <bits/stdc++.h>

#define inf (1<<30)

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

int main() {
  freopen("graph.in", "r", stdin);

  int v, e;
  cin >> v >> e;

  vector<vector<int>> dist(v, vector<int>(v, inf));
  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    dist[a][b] = w;
    dist[b][a] = w;
  }

  vector<int> cost(v, inf);
  vector<int> parent(v, -1);
  vector<bool> done(v);

  cost[0] = 0;
  parent[0] = 0;
  for (int i = 0; i < v; i++) {
    int u = -1;
    for (int j = 0; j < v; j++)
      if (!done[j])
        if (u == -1 || cost[j] < cost[u])
          u = j;

    if (cost[u] == inf) break;
    done[u] = true;

    for (int j = 0; j < v; j++)
      if (!done[j])
        if (dist[u][j] < cost[j]) {
          parent[j] = parent[u];
          cost[j] = dist[u][j];
        }
  }

  int ans = 0;
  for (int i = 0; i < v; i++)
    ans += cost[i];

  cout << ans << "\n";

  return 0;
}
