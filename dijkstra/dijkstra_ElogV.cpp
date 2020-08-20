#include <bits/stdc++.h>
#define inf (1<<30)

using namespace std;
typedef pair<int, int> pii;

/*
 Remember lazy dijkstra for when the number of nodes
 pushed to pq may be really high (but we only need a few dists)

 q.top() = {-dist, p, i, source}
 where dist = distance from source to adj[p][i]

 -> transition to {-dist + d1 - d2, p, i+1, source} & {-dist - d, adj[p][i], 0, source}

 ex: https://codeforces.com/contest/1196/submission/57821476
*/

int main() {
  int n, m;
  cin >> n >> m;

  priority_queue<pii> q;
  vector<vector<pii>> adj(n);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;

    adj[a - 1].push_back({b - 1, w});
    adj[b - 1].push_back({a - 1, w});
  }

  vector<int> dist(n, inf);
  vector<bool> done(n);

  int s;
  cin >> s;
  s--;

  dist[s] = 0;
  priority_queue<pii> q;
  q.push(pii(0, s));

  while(!q.empty()) {
    int u = q.top().second;
    q.pop();

    if(done[u]) continue;

    for(int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      int w = adj[u][i].second;

      if(!done[v] && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        q.push({ -dist[v], v});
      }
    }

    done[u] = 1;
  }

  for (int i = 0; i < n; i++)
    if (i != s)
      cout << (done[i] ? dist[i] : -1) << " ";
  cout << "\n";


  return 0;
}

