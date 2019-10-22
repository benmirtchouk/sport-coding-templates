#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;

// ----- undirected -----

vector<vector<int>> adj;
vector<bool> seen;

bool dfs(int u, int par) {
  seen[u] = 1;

  for(int v : adj[u])
    if (!seen[v]) {
      if(dfs(v, u))
        return 1;
    } else if (v != par)
      return 1;

  return 0;
}

// ------ directed ------

vector<vector<int>> adj;
vector<int> cycle, parent; //parent[i] = -1
vector<bool> seen;

bool dfs(int u, int p) {
  if (parent[u] != -1) return 0;
  if (seen[u]) {
    cycle.push_back(u);
    return 1;
  }

  seen[u] = 1;

  for(int v : adj[u])
    if (dfs(v, u, seen, parent, adj)) {
      cycle.push_back(u);
      return 1;
    }

  parent[u] = p;
  return 0;
}
