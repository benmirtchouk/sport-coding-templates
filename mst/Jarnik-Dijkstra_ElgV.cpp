#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define inf (1ll<<30)
using namespace std;
typedef long long ll;

int main() {
  ios;
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  forn(i, m) {
    int a, b, w;
    cin >> a >> b >> w;
    adj[a - 1].emplace_back(b - 1, w);
    adj[b - 1].emplace_back(a - 1, w);
  }

  ll ans = 0;
  vector<bool> done(n);
  vector<ll> cost(n, inf);
  cost[0] = 0;

  priority_queue<pair<ll, int>> pq;
  pq.push({0, 0});

  while(!pq.empty()) {
    int u = pq.top().second;
    ll d = -pq.top().first;
    pq.pop();
    if (done[u]) continue;

    done[u] = 1;
    ans += cost[u];
    assert(cost[u] == d);

    for (auto& e : adj[u])
      if (cost[e.first] > e.second) {
        cost[e.first] = e.second;
        pq.push({ -cost[e.first], e.first});
      }
  }

  cout << ans << "\n";
  return 0;
}
