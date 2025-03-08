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
queue<int> que;

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i{1}; i <= n; ++i) {
    int a_i;
    cin >> a_i;
    que.push(a_i);
  }
  int tip{0};
  while (que.size() != 1) {
    ++tip;
    if (tip == m) {
      que.pop();
      tip = 0;
    } else {
      que.push(que.front());
      que.pop();
    }
  }
  cout << que.front() << "\n";
  que.pop();
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}