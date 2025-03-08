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
stack<char> sta;
map<char, char> ma{{'}', '{'}, {']', '['}, {')', '('}};

void solve() {
  bool tp = true;
  string str;
  cin >> str;
  for (auto& i : str) {
    if (i == '[' || i == '{' || i == '(') {
      sta.push(i);
    } else {
      if (!sta.empty() && ma[i] == sta.top()) {
        sta.pop();
      } else {
        tp = false;
      }
    }
  }
  if (sta.empty() && tp) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  while (sta.size()) sta.pop();
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}