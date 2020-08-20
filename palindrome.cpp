#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define forn(i,n) for(int i = 0; i < (int) n; i++)
#define ios ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

// Manacher's algorithm

vector<int> get_p_odd(string& s) {
  int n = s.size();
  vector<int> ans(n);

  int l = 0, r = -1;
  forn(i, n) {
    if (i <= r) ans[i] = min(ans[l + r - i], r - i);
    while(i - ans[i] > 0 && i + ans[i] < n - 1 && s[i - ans[i] - 1] == s[i + ans[i] + 1])
      ans[i]++;

    if (i + ans[i] > r) {
      r = i + ans[i];
      l = i - ans[i];
    }
  }

  return ans;
}

vector<int> get_p_even(string& s) {
  int n = s.size();
  vector<int> ans(n - 1);

  int l = 0, r = -1;
  forn(i, n - 1) {
    if (i < r) ans[i] = min(ans[l + r - i - 1], r - i);
    while(i - ans[i] + 1 > 0 && i + ans[i] < n - 1 && s[i - ans[i]] == s[i + ans[i] + 1])
      ans[i]++;

    if (i + ans[i] > r) {
      r = i + ans[i];
      l = i - ans[i] + 1;
    }
  }

  return ans;
}

int main() {
  string s;
  cin >> s;

//  int v = 0;
//  for(int x : get_p_odd(s)) v += x;
  for(int x : get_p_even(s)) cout << x << " ";
  cout << "\n";
}
