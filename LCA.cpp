#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)

using namespace std;

int n, logn = 1;
vector<vector<int>> pa, adj;
vector<int> depth;

void dfs(int u, int par, vector<bool>& done, int d = 0) {
  if (done[u]) return;
  done[u] = 1;

  pa[u][0] = par;
  depth[u] = d;
  forn(i, adj[u].size()) dfs(adj[u][i], u, done, d+1);
}

int LCA(int a, int b) {
  if (depth[a] < depth[b])
    swap(a, b);

  for(int i = logn - 1; i >= 0; i--)
    while(depth[a] - (1 << i) >= depth[b] && pa[a][i] != -1)
      a = pa[a][i];

  if (a == b) return a;

  for(int i = logn - 1; i >= 0; i--)
    if (pa[a][i] != -1 && pa[a][i] != pa[b][i]) {
      a = pa[a][i];
      b = pa[b][i];
    }

  return pa[a][0];
}

int main() {
  int root, cpn;
  cin >> n >> root;

  cpn = n;
  while(cpn /= 2)
    logn++;

  pa = vector<vector<int>>(n, vector<int>(logn, -1));
  depth = vector<int>(n);
  adj = vector<vector<int>>(n);

  forn(i, n - 1) {
    int a, b;
    cin >> a >> b;

    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }

  vector<bool> done(n);
  dfs(root, -1, done);

  for(int i = 1; i < logn; i++)
    forn(j, n) if (pa[j][i - 1] != -1)
      pa[j][i] = pa[pa[j][i - 1]][i - 1];

  int q;
  cin >> q;

  forn(i, q) {
    int a, b;
    cin >> a >> b;

    cout << LCA(a, b) << "\n";
  }
}
