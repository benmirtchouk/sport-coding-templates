#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0)

using namespace std;

stack<int> post;
vector<bool> done;
int n;

void dfs(int u, vector<vector<int>>& adj) {
  if (done[u]) return;
  done[u] = 1;

  for (int v : adj[u])
    dfs(v, adj);

  post.push(u);
}

int main() {
  ios;
  int m, a, b;
  cin >> n >> m;

  vector<vector<int>> adj(n), adjT(n);
  forn(i, m) {
    cin >> a >> b;
    adj[a - 1].push_back(b - 1);
    adjT[b - 1].push_back(a - 1);
  }

  done.resize(n);
  forn(i, n) if (!done[i])
    dfs(i, adj);

  stack<int> cp = post;
  post = stack<int>();

  fill(all(done), 0);

  vector<vector<int>> ans;
  while(!cp.empty()) {
    int i = cp.top();
    cp.pop();
    if (done[i]) continue;

    dfs(i, adjT);


    ans.push_back(vector<int>());
    while(post.size()) {
      ans.back().push_back(post.top());
      post.pop();
    }
  }

  cout << ans.size() << "\n";
  for(auto& v : ans) {
    cout << v.size() << " ";
    forn(i, v.size()) cout << v[i] << " \n"[i == v.size() - 1];
  }


}
