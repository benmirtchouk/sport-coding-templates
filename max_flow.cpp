//Edmonds-Karp

#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)

#define inf (1<<20)
#define x first
#define y second

using namespace std;
typedef long long ll;

bool BFS(vector< vector<ll> > &resAdjMatrix, ll &source, ll &sink, vector<ll> &parent) {
  ll n = resAdjMatrix.size();
  bool visited[n] = { false };

  queue<ll> q;

  q.push(source);
  visited[source] = true;
  parent[source] = -1;

  while(q.empty() == false) {
    ll u = q.front();
    q.pop();

    for(int i = 0; i < n; i++) {
      ll v = i;
      ll capacity = resAdjMatrix[u][v];

      if(visited[v] == false && capacity > 0) {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }

  return visited[sink];
}

ll FordFulkerson(vector< vector<ll> > &adjMatrix, ll &source, ll &sink) {
  ll maxflow = 0;

  vector< vector<ll> > resAdjMatrix;
  ll n = adjMatrix.size();
  for(ll i = 0; i < n; i++) {
    vector<ll> row;
    resAdjMatrix.push_back(row);
    for(ll j = 0; j < adjMatrix[i].size(); j++)
      resAdjMatrix[i].push_back(adjMatrix[i][j]);
  }

  vector<ll> parent(n, -1);
  while(BFS(resAdjMatrix, source, sink, parent) == true) {
    ll pathflow = inf;

    ll v = sink;
    while(v != source) {
      ll u = parent[v];
      ll capacity = resAdjMatrix[u][v];
      pathflow = min(pathflow, capacity);
      v = u;
    }

    v = sink;
    while(v != source) {
      ll u = parent[v];
      resAdjMatrix[u][v] -= pathflow;
      resAdjMatrix[v][u] += pathflow;
      v = u;
    }

    maxflow += pathflow;
  }

  return maxflow;
}

int main() {
//  int n, m;
//  cin >> n >> m; //nodes, edges
//
//  vector<vector<edge*>> adj(n);
//  forn(i, m) {
//    int a, b, c;
//    cin >> a >> b >> c; //start, end, capacity of each edge
//
//    edge* e = new edge(a, b, c);
//    adj[a].push_back(e);
//    adj[b].push_back(e);
//  }
//
//  int s, t;
//  cin >> s >> t; //source, sink
//
//  ll flow = 0;
//
//  while(1) {
//    queue<int> q;
//    q.push(s);
//
//    vector<pair<edge*,int>> parent(n, {0,0});
//    parent[s] = {0, inf};
//
//    while(!q.empty()) {
//      int v = q.front();
//      q.pop();
//
//      if (v == t) break;
//
//      forn(i, adj[v].size()) {
//        edge* e = adj[v][i];
//
//        if (e->from == v && e->flow != e->cap && !parent[e->to].x) { //forward edge
//          q.push(e->to);
//          parent[e->to] = {e, min(parent[v].y, e->cap - e->flow)};
//        } else if (e->to == v && e->flow != 0 && !parent[e->from].x) { //backward edge
//          q.push(e->from);
//          parent[e->from] = {e, min(parent[v].y, e->flow)};
//        }
//      }
//    }
//
//    if (!parent[t].x) break;
//
//    int u = t, aug = parent[t].y;
//    flow += aug;
//
//    while(u != s) { //augment
//      edge* e = parent[u].x;
//
//      if (e->to == u) {
//        e->flow += aug;
//        u = e->from;
//      } else {
//        e->flow -= aug;
//        u = e->to;
//      }
//    }
//  }
//
//  forn(i, n) forn(j, adj[i].size()) if(adj[i][j]->from == i)
//    cout << i << " -> " << adj[i][j]->to << " flow = " << adj[i][j]->flow << "\n";
//  cout << "\n";
//
//  cout << "total flow = " << flow << "\n";
}
