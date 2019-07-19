#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii>> Graph;

vector<int> parent;

int find(int v) {
  if (parent[v] == v) return v;

  parent[v] = parent[parent[v]];
  return find(parent[v]);
}

int main() {
  freopen("graph.in", "r", stdin);

  int v, e;
  cin >> v >> e;

  set<pair<int, pii>> s;
  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    s.insert({w, {a, b}});
  }

  parent.resize(v);
  for (int i = 0; i < v; i++)
    parent[i] = i;

  Graph adj(v);
  for (auto it = s.begin(); it != s.end(); it++) {
    int w = it->first, a = it->second.first, b = it->second.second;

    int pa = find(a), pb = find(b);
    if (pa != pb) {
      parent[pa] = pb;

      adj[a].push_back({b, w});
      adj[b].push_back({a, w});
    }
  }

  for (int i = 0; i < v; i++) {
    cout << i << ": ";
    for (int j = 0; j < adj[i].size(); j++) {
      cout << adj[i][j].first << " ";
    }
    cout << "\n";
  }


  return 0;
}
