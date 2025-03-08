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
deque<string> deq;

void solve() {
  int n;
  cin >> n;
  for (int i{1}; i <= n; ++i) {
    char a, b;
    cin >> a >> b;
    if (a == 'f') {
      if (b == 'w') {
        string str;
        cin >> str;
        deq.push_front(str);
      } else {
        if (!deq.empty()) {
          deq.pop_front();
        }
      }
    } else {
      if (b == 'w') {
        string str;
        cin >> str;
        deq.push_back(str);
      } else {
        if (!deq.empty()) {
          deq.pop_back();
        }
      }
    }
  }
  if (deq.empty()) {
    cout << "#";
  }
  for (const auto& i : deq) {
    cout << i;
  }
  cout << "\n";
  deq.clear();
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}