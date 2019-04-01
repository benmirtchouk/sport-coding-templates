#include <bits/stdc++.h>

#define inf (1e9)

using namespace std;

void relax(int i, int j, int k, vector<vector<int>>& dist) {
  if (dist[i][j] > dist[i][k] + dist[k][j])
    dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
  int n, m, a, b, w;
  cin >> n >> m;

  vector<vector<int>> dist(n, vector<int>(n, inf));
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> w;
    dist[a][b] = dist[b][a] = w; //undirected
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        relax(i, j, k, dist);

  return 0;
}
