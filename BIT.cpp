#include <bits/stdc++.h>
#define N (1 << 18)
using namespace std;

int BT[N];

void add(int x, int v) {
  for(x++; x <= N; x += x&-x)
    BT[x] += v;
}

int get(int x) {
  int ret = 0;
  for(x++; x > 0; x &= x-1)
    ret += BT[x];
  return ret;
}

int main() {
  vector<int> v {5, 6, 13, 1, 5, 3};

  for (int i = 0; i < v.size(); i++)
    add(i, v[i]);

  cout << get(5) - get(1) << endl;
}
