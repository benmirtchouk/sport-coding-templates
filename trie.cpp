#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

struct trie {
  trie(bool e = false): endmarker(e), children( {
    0
  }) {}
  bool endmarker;
  trie* children[4];
};

string fix(string s) {
  string f = "";
  forn(i, s.size()) {
    if (s[i] == 'A') f += (char)0;
    if (s[i] == 'C') f += (char)1;
    if (s[i] == 'G') f += (char)2;
    if (s[i] == 'T') f += (char)3;
  }
  return f;
}
string unfix(string s) {
  string u = "";
  forn(i, s.size()) {
    if (s[i] == 0) u += 'A';
    if (s[i] == 1) u += 'C';
    if (s[i] == 2) u += 'G';
    if (s[i] == 3) u += 'T';
  }
  return u;
}
void prnt(trie* root, int t = 0) {
  if (!root) return;
  forn(i, 4) if (root->children[i]) {
    cout << string(t, ' ') << i;
    if (root->children[i]->endmarker) cout << "e";
    cout << "\n";
    prnt(root->children[i], t + 1);
  }
}

bool insert(trie* root, string& s, int i = 0) {
  if (i == s.size() - 1)
    if(root->children[s[i]])
      if (root->children[s[i]]->endmarker)
        return false;
      else {
        root->children[s[i]]->endmarker = true;
        return true;
      }
    else {
      root->children[s[i]] = new trie(true);
      return true;
    }

  if (!root->children[s[i]])
    root->children[s[i]] = new trie();
  return insert(root->children[s[i]], s, i + 1);
}

string query(trie* root, string& s, int i = 0) {
  if (i == s.size()) {
    if (root->endmarker) return "";
    string best = "-";

    forn(j, 4) if (root->children[j]) {
      string cur = string(1, j) + query(root->children[j], s, i);
      if (best == "-" || cur.size() < best.size() || cur.size() == best.size() && cur < best)
        best = cur;
    }
    return best;
  }

  if (root->children[s[i]])
    return string(1, s[i]) + query(root->children[s[i]], s, i + 1);
  return query(root, s, s.size());
}

string path = "";
int prefix(trie* root, string& s, int i = 0) {
  if (i == s.size()) {
    int ret = 0;
    if (root->endmarker) {
      cout << unfix(s) + unfix(path) << "\n";
      ret++;
    }

    forn(j, 4) if (root->children[j]) {
      path += string(1, j);
      ret += prefix(root->children[j], s, i);
      path.pop_back();
    }
    return ret;
  }

  if (root->children[s[i]])
    return prefix(root->children[s[i]], s, i + 1);
  else return 0;
}

int nodes(trie* root) {
  if (!root) return 0;
  int ans = 0;
  forn(i, 4) if (root->children[i])
    ans += 1 + nodes(root->children[i]);
  return ans;
}

int main() {
  trie* root = new trie();
  prnt(root);

  string q, s;
  while(1) {
    cin >> q;

    if (q == "i") {
      cin >> s;
      s = fix(s);

      if (insert(root, s))
        cout << "inserted " << unfix(s) << "\n";
      else
        cout << "already present\n";
    }

    if (q == "q") {
      cin >> s;
      s = fix(s);

      string ret = query(root, s);
      int match = 0;
      while(match < min(s.size(), ret.size()) && s[match] == ret[match])
        match++;

      if (match == 0) cout << unfix(s) << ": no match found\n";
      else cout << "Match found: " << unfix(ret) << " " << (int)(100.0 * match / (max(s.size(), ret.size())) + 0.5) << "%\n";
    }

    if (q == "pq") {
      cin >> s;
      s = fix(s);

      path = "";
      if (prefix(root, s) == 0)
        cout << unfix(s) << ": no matches found\n";
    }

    if (q == "n") {
      cout << "There are " << nodes(root) << " nodes in the database\n";
    }

    if (q == "p"){
      path = "";
      s = "";
      prefix(root, s);
    }
  }
}
