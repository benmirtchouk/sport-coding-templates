#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define x first
#define y second

using namespace std;
typedef pair<int, int> pii;

// how to use custom hashes for unordered_*
struct HASH {
  size_t operator()(const pii& x)const {
    return hash<long long>()(((long long)x.x) ^ (((long long)x.y) << 32));
  }
};

unordered_map<pii, int, HASH> us;

// structs
struct cow {
  int x, y;
  bool H;

  bool operator< (const cow& b) const {
    return x < b.x || (x == b.x && b.H);
  }
};

int main() {
  // how custom compares work
  vector<cow> cows(n);
  sort(cows.begin(), cows.end());

  // also using lambda functions
  vector<pii> a(n);
  sort(a.begin(), a.end(), [&](const pii & a, const pii & b) {
    return a.y < b.y;
  });

  // cool trick! (makes array contain only unique values)
  vector<int> v(n);
  sort(all(v));
  v.resize(unique(all(v)) - v.begin());

  return 0;
}
