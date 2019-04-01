#include <bits/stdc++.h>

#define inf (1<<30)

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

int main() {
  freopen("graph.in", "r", stdin);

  int v, e;
  cin >> v >> e;

  vector<vector<int>> dist(v);
  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    dist[a].push_back({b, w});
    dist[b].push_back({a, w});
  }

  vector<pii> cost(v + 1);
  for (int i = 1; i <= v; i++)
    cost[i] = {inf, i};

  int ans = 0;
  for (int i = 0; i < v; i++) {
    ans += cost[1].x;

    for (int i = 0; i < adj[cost[1].y].size(); i++) {
      int v = adj[cost[1].y][i];
    }



  }

  cout << ans << "\n";

  return 0;
}
