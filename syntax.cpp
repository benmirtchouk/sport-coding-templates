#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
typedef pair<int,int> pii;

struct HASH {
  size_t operator()(const pii& x)const {
    return hash<long long>()(((long long)x.x) ^ (((long long)x.y) << 32));
  }
};

unordered_map<pii, int, HASH> us;

struct cow {
  int x, y;
  bool H;

  bool operator< (const cow& b) const {
    return x < b.x || (x == b.x && b.H);
  }
};

int main() {
  vector<cow> cows(n);

  sort(cows.begin(), cows.end());

  vector<pii> a(n);

  sort(a.begin(), a.end(), [](const pii & a, const pii & b) {
    return a.y < b.y;
  });

  return 0;
}
