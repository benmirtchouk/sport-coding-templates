#include <bits/stdc++.h>

#define inf (1e9)
#define low first
#define high second

using namespace std;

typedef pair<int, int> pii;

set<pii> intervals;

struct I_Nd {
  I_Nd(int a, int b): i(a, b), mx(b), l(0), r(0) {}
  I_Nd(pii p): i(p.low, p.high), mx(p.high), l(0), r(0) {}

  pii i;
  int mx;
  I_Nd *l, *r;
};

I_Nd* insert(I_Nd *r, pii i) {
  // Base case: Tree is empty, new node becomes root
  if (r == 0)
    return new I_Nd(i);

  // Get low value of interval at root
  int l = r->i.low;

  // If root's low value is smaller, then new interval goes to
  // left subtree
  if (i.low < l)
    r->l = insert(r->l, i);

  // Else, new node goes to right subtree.
  else
    r->r = insert(r->r, i);

  // Update the max value of this ancestor if needed
  if (r->mx < i.high)
    r->mx = i.high;

  return r;
}

bool overlap(pii i1, pii i2) {
  return i1.low <= i2.high && i2.low <= i1.high;
}

pii search(I_Nd *r, pii i) {
  // Base Case, tree is empty
  if (r == 0) return {-1,-1};

  // If given interval overlaps with root
  if (overlap(r->i, i))
    return r->i;

  // If left child of root is present and max of left child is
  // greater than or equal to given interval, then i may
  // overlap with an interval is left subtree
  if (r->l != 0 && r->l->mx >= i.low)
    return search(r->l, i);

  // Else interval can only overlap with right subtree
  return search(r->r, i);
}


int main() {


  return 0;
}
