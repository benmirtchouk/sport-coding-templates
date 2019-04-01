#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)

using namespace std;

vector<int> parent, sz;

int find(int x) {
  while(parent[x] != x) {
    parent[x] = parent[parent[x]];
    x = parent[x];
  }

  return x;
}

void onion(int a, int b) {
  int pa = find(a), pb = find(b);

  if (sz[pa] < sz[pb])
    swap(pa, pb);

  sz[pa] += sz[pb];
  parent[pb] = pa;
}

int main() {

}
