#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;
typedef pair<int, int> pii;

vector<int> parent, sz;

int find(int v) {
  while(parent[v] != v)
    v = parent[v] = parent[parent[v]];
  return v;
}

void onion(int a, int b) {
  a = find(a), b = find(b);
  if (sz[a] < sz[b])
    swap(a, b);

  sz[a] += sz[b];
  parent[b] = a;
}

int main() {
//  ios;
  int n, m;
  cin >> n >> m;

  vector<pair<int, pii>> s;
  forn(i, m) {
    int a, b, w;
    cin >> a >> b >> w;
    s.emplace_back(w, pii{a-1, b-1});
  }
  sort(all(s));

  parent.resize(n);
  sz.resize(n);
  iota(all(parent), 0);
  fill(all(sz), 1);

  long long ans = 0;
  for(auto& p : s) {
    int w = p.first, a = p.second.first, b = p.second.second;

    int pa = find(a), pb = find(b);
    if (pa != pb) {
      onion(pa, pb);
      ans += w;
    }
  }

  cout << ans << "\n";
  return 0;
}
