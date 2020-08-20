#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

struct trie {
  trie(): sz(0), ch(26, 0) {}
  int sz;
  vector<trie*> ch;
};

void insert(trie* root, string& s) {
  for(char c : s) {
    if (!root->ch[c - 'A'])
      root->ch[c - 'A'] = new trie();
    root = root->ch[c - 'A'];
    root->sz++;
  }
}

int k;

int ans(trie* root, int d = 0) {
  if (!root) return 0;
  int ret = (root->sz / k);
  forn(i, 26){
    ret += ans(root->ch[i], d + 1);
  }
  return ret;
}

int main() {
  int n;
  cin >> n >> k;

  trie *root = new trie();

  forn(i, n) {
    string s;
    cin >> s;
    insert(root, s);
  }

  cout << ans(root) << "\n";
}
