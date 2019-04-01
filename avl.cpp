#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

/* BEGIN AVL */

struct avl {
  avl(int x): x(x), h(1), sz(1), l(0), r(0) {};

  int x, h, sz;
  avl *l, *r;
};

void prnt(avl *root, int d = 0) {
  if (!root) {
    cout << string(d, '\t') << "xx\n";
    return;
  }
  prnt(root->r, d + 1);
  cout << string(d, '\t') << root->x << " (" << root->sz << ")\n";
  prnt(root->l, d + 1);
}

int upd(avl *root) {
  if (!root) return 0;

  int lh = root->l ? root->l->h : 0;
  int rh = root->r ? root->r->h : 0;
  root->h = 1 + max(lh, rh);

  int lsz = root->l ? root->l->sz : 0;
  int rsz = root->r ? root->r->sz : 0;
  root->sz = lsz + 1 + rsz;

  return lh - rh;
}

avl* leftrot(avl *root) {
  avl *p = root->r;
  root->r = p->l;
  p->l = root;

  upd(root), upd(p);
  return p;
}

avl* rightrot(avl *root) {
  avl *p = root->l;
  root->l = p->r;
  p->r = root;

  upd(root), upd(p);
  return p;
}

avl* insert(avl *root, int x) {
  if (!root) return new avl(x);
  else if (root->x == x) return root;

  if (x < root->x)
    root->l = insert(root->l, x);
  else
    root->r = insert(root->r, x);

  int bal = upd(root);

  if (bal == -2)
    if (x > root->r->x)
      return leftrot(root); // 1
    else if (x < root->r->x) {
      root->r = rightrot(root->r);
      return leftrot(root); // 2
    }

  if (bal == 2)
    if (x > root->l->x) {
      root->l = leftrot(root->l);
      return rightrot(root); // 3
    } else if (x < root->l->x)
      return rightrot(root); // 4

  return root;
}

/* END AVL */

int smallcount(avl *root, int v) {
  if (!root) return 0;

  int ans = 0;
  ans += smallcount(root->l, v);
  if (root->x <= v) ans++;
  if (root->x < v) ans += smallcount(root->r, v);

  return ans;
}

vector<int> sorted;
void printRange(avl *root, int l, int r) {
  if (!root) return;

  if (l <= root->x) printRange(root->l, l, r);
  if (l <= root->x && root->x <= r) sorted.push_back(root->x);
  if (root->x <= r) printRange(root->r, l, r);
}

bool checkBST(avl *root) {
  if (!root) return 1;
  if (root->l && root->x < root->l->x) return 0;
  if (root->r && root->x >= root->r->x) return 0;

  return checkBST(root->l) && checkBST(root->r);
}

int kth(avl *root, int k) {
  int l = root->l ? root->l->sz : 0;

  if (k <= l) return kth(root->l, k);
  if (k == l + 1) return root->x;
  return kth(root->r, k - l - 1);
}

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 g1(seed);

int main() {
  avl *root = 0;

  set<int> s;
  forn(i, 1e4) {
    int x = g1();
    root = insert(root, x);
    s.insert(x);
  }

  /* test smallcount() */
  forn(i, 1e2) {
    int x = rand();
    int a = smallcount(root, x);
    int b = distance(s.begin(), s.upper_bound(x));
    assert(a==b);
  }

  /* test printRange() */
  int i = 0;
  printRange(root, 500, 1000);
  for(auto it = s.lower_bound(500); it != s.upper_bound(1000); it++, i++) {
    assert(*it == sorted[i]);
  }

  /* test checkBST() */
  root->l->l->l->l->x = 0;
  cout << checkBST(root) << "\n";

  /* test kth() */
  auto it = s.begin();
  forn(i, s.size()) {
    assert(*it++ == kth(root, i + 1));
  }

}
