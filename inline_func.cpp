#include <bits/stdc++.h>

using namespace std;

int main() {
  function<void(int)> dfs = [&](int v) {
    all[v].insert(v);
    for (int u : g[v]) {
      dfs(u);
      if (all[u].size() > all[v].size()) {
        swap(all[v], all[u]);
      }
      for (int x : all[u]) {
        all[v].insert(x);
      }
      all[u].clear();
    }
    while (!all[v].empty() && cnt[v] > 0) {
      auto it = --all[v].end();
      ans += *it;
      all[v].erase(it);
      cnt[v]--;
    }
  };
}
