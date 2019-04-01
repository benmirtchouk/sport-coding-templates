#include <bits/stdc++.h>

#define inf (LLONG_MAX/2)

using namespace std;

typedef long long ll;

struct Node {
  Node(int a, int b): lo(a), hi(b), mn(0), sum(0), l(0), r(0), lazy(0) {}

  int lo, hi;
  ll mn, sum, lazy;
  Node *l, *r;
};

Node* build(int a, int b) {
  Node *n = new Node(a, b);

  if (a != b) {
    int c = (a + b) / 2;
    n->l = build(a, c);
    n->r = build(c + 1, b);
  }

  return n;
}

void push_down(Node* n) {
  if (n->r) n->r->lazy += n->lazy;
  if (n->l) n->l->lazy += n->lazy;
  n->mn += n->lazy;
  n->sum += n->lazy * (n->hi - n->lo + 1);
  n->lazy = 0;
}

int get(Node* root, int idx) {
  while(root->lo != root->hi) {
    int c = (root->lo + root->hi) / 2;

    push_down(root);

    if (idx <= c)
      root = root->l;
    else
      root = root->r;
  }

  push_down(root);
  return root->sum;
}

ll min(Node* root, int lo, int hi) {
  if (!root) return 0;
  ll ans = inf;

  push_down(root);

  if (root->lo >= lo && root->hi <= hi)
    ans = min(ans, root->mn);
  else if (!(lo > root->hi || root->lo > hi)) {
    ans = min(ans, min(root->l, lo, hi));
    ans = min(ans, min(root->r, lo, hi));
  }

  return ans;
}

ll sum(Node* root, int lo, int hi) {
  if (!root) return 0;
  ll ans = 0;

  push_down(root);

  if (root->lo >= lo && root->hi <= hi)
    ans += root->sum;
  else if (!(lo > root->hi || root->lo > hi)) {
    ans += sum(root->l, lo, hi);
    ans += sum(root->r, lo, hi);
  }

  return ans;
}

int overlap(int a, int b, int c, int d) {
  int ideal = (d - c + 1) + (b - a + 1);
  int actual = max(d, b) - min(a, c) + 1;

  return ideal - actual;
}

void increment(Node* root, int lo, int hi, ll val) {
  if (!root) return;

  push_down(root);

  if (root->lo >= lo && root->hi <= hi) {
    root->lazy += val;
    push_down(root);
  } else if (!(lo > root->hi || root->lo > hi)) {
    root->sum += val * overlap(lo, hi, root->lo, root->hi);

    increment(root->l, lo, hi, val);
    increment(root->r, lo, hi, val);

    root->mn = root->sum;
    if (root->l)
      root->mn = min(root->mn, root->l->mn);
    if (root->r)
      root->mn = min(root->mn, root->r->mn);
  }
}

int main() {
  int n = 2e5;

  srand(time(NULL));
  Node *root = build(0, n - 1);

  for (int i = 0; i < n; i++)
    increment(root, i, i, rand() % 100);

  for (int i = 0; i < n; i++) {
    int a = rand() % n, b = rand() % n;
    int lo = min(a, b), hi = max(a, b);

//    cout << "min on [" << lo << "," << hi << "] = " << min(root, lo, hi) << "\n";
//    cout << "sum on [" << lo << "," << hi << "] = " << sum(root, lo, hi) << "\n";
//    min(root, lo, hi);
    sum(root, lo, hi);

//    cout << "now inc\n\n";
    increment(root, lo, hi, 1);
  }

  return 0;
}

