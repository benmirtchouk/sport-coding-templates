#include<bits/stdc++.h>

using namespace std;

vector<int> build(string& s) {
  int n = s.size();

  vector<vector<int> > suf(n, vector<int>(3, -1));
  for (int i = 0; i < n; i++) {
    suf[i][0] = s[i] - 'a';
    if (i != n - 1)
      suf[i][1] = s[i + 1] - 'a';

    suf[i][2] = i;
  }

  sort(suf.begin(), suf.end());

  for (int k = 4; k < 2 * n; k *= 2) {
    vector<int> prev = suf[0];
    suf[0][0] = 0;

    vector<int> index(n); //index[k] = place in suf where suf[i][2]=k
    index[suf[0][2]] = 0;

    for (int i = 1; i < n; i++) {
      if (suf[i][0] == prev[0] && suf[i][1] == prev[1])
        suf[i][0] = suf[i - 1][0];
      else {
        prev = suf[i];
        suf[i][0] = suf[i - 1][0] + 1;
      }

      index[suf[i][2]] = i;
    }

    for (int i = 0; i < n; i++) {
      if (suf[i][2] + k / 2 < n)
        suf[i][1] = suf[ index[suf[i][2] + k / 2]   ][0];
      else
        suf[i][1] = -1;
    }

    sort(suf.begin(), suf.end());
  }

  vector<int> suffix(n);
  for (int i = 0; i < n; i++)
    suffix[i] = suf[i][2];

  return suffix;
}

int comp(int idx, string& s, string& sub) {
  for (int i = 0; i < sub.size(); i++) {
    if(idx + i >= s.size())
      return -1;

    if (s[idx + i] < sub[i])
      return -1;
    if (s[idx + i] > sub[i])
      return 1;
  }
  return 0;
}

bool search(vector<int>& suffix, string& s, string& sub) {
  int lo = 0, hi = suffix.size() - 1;

  while(lo <= hi) {
    int mid = (lo + hi) / 2;

    int cmp = comp(suffix[mid], s, sub);

    if (cmp == 0)
      return mid;
    else if (cmp == -1)
      lo = mid + 1;
    else if (cmp == 1)
      hi = mid - 1;
  }

  return 0;
}

int main() {
//  string s;
//  cin >> s;

  srand(time(NULL));

  int n = 100000;
  string s(n, 'a');
  for (int i = 0; i < s.size(); i++)
    s[i] = 'a' + rand() % 26;

  clock_t start = clock();
  vector<int> suffix = build(s);
  cout << 1.0*(clock() - start)/CLOCKS_PER_SEC<<" s\n";


//  for (int i = 0; i < 10000; i++) {
//    string sub(10, 'a');
//    for (int i = 0; i < 10; i++)
//      sub[i] = 'a' + rand() % 26;
//
//    search(suffix, s, sub);
//  }
  return 0;
}

