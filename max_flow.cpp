//Edmonds-Karp

#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)

#define inf (1<<20)
#define x first
#define y second

using namespace std;
typedef long long ll;

struct edge {
  edge(int a, int b, int c): from(a), to(b), cap(c), flow(0) {}
  int from, to, cap, flow;
};

int main() {
  int n, m;
  cin >> n >> m; //nodes, edges

  vector<vector<edge*>> adj(n);
  forn(i, m) {
    int a, b, c;
    cin >> a >> b >> c; //start, end, capacity of each edge

    edge* e = new edge(a, b, c);
    adj[a].push_back(e);
    adj[b].push_back(e);
  }

  int s, t;
  cin >> s >> t; //source, sink

  ll flow = 0;

  while(1) {
    queue<int> q;
    q.push(s);

    vector<pair<edge*,int>> parent(n, {0,0});
    parent[s] = {0, inf};

    while(!q.empty()) {
      int v = q.front();
      q.pop();

      if (v == t) break;

      forn(i, adj[v].size()) {
        edge* e = adj[v][i];

        if (e->from == v && e->flow != e->cap && !parent[e->to].x) { //forward edge
          q.push(e->to);
          parent[e->to] = {e, min(parent[v].y, e->cap - e->flow)};
        } else if (e->to == v && e->flow != 0 && !parent[e->from].x) { //backward edge
          q.push(e->from);
          parent[e->from] = {e, min(parent[v].y, e->flow)};
        }
      }
    }

    if (!parent[t].x) break;

    int u = t, aug = parent[t].y;
    flow += aug;

    while(u != s) { //augment
      edge* e = parent[u].x;

      if (e->to == u) {
        e->flow += aug;
        u = e->from;
      } else {
        e->flow -= aug;
        u = e->to;
      }
    }
  }

  forn(i, n) forn(j, adj[i].size()) if(adj[i][j]->from == i)
    cout << i << " -> " << adj[i][j]->to << " flow = " << adj[i][j]->flow << "\n";
  cout << "\n";

  cout << "total flow = " << flow << "\n";
}
