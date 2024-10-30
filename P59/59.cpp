// Problem: ${json.name}
// Contest: ${json.group}
// URL: ${json.url}
// Memory Limit: ${json.memoryLimit} MB
// Time Limit: ${json.timeLimit} ms
// More thought is needed

#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<string, int> col;
  vector<string> ve;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (col.count(s)) {
      col[s]++;
    } else {
      ve.push_back(s);
      col[s] = 1;
    }
  }
  for (auto &i : ve) {
    cout << i << " " << col[i] << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}