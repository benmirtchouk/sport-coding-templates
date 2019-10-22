#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<ll> s;

int main() {
  srand(time(0));

  s.insert(5);
  s.insert(5);
  cout << s.size() << "\n";
  return 0;

  int n = 1e5;
  forn(i, n) s.insert(1ll * i * i);

  forn(i, n) {
    ll rnd1 = rand(), rnd2 = rand();
    ll rnd = rnd1 * rnd2;

    if (rnd >= 1ll * n * n) rnd = rnd1;
    assert((int)sqrt(rnd) + 1 == s.order_of_key(rnd + 1)); // order_of_key(x) = number of elements < x
  }

  ll ans = 0;
  forn(i, n) {
    ans += *s.find_by_order(i);
    assert(*s.find_by_order(i) == 1ll * i * i); // find_by_order(x) = element index x
  }
  cout << ans << "\n";
}
