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
const int N = 1e5 + 9;
int a[N];

void solve() {
  int n;
  cin >> n;
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  stack<int> train;
  for (int i = 1; i <= n; i++) {
    while (pos <= n && (train.empty() || train.top() != i)) {
      train.push(a[pos++]);
    }
    if (train.top() == i)
      train.pop();
    else {
      cout << "No";
      return;
    }
  }
  cout << "Yes";
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  while (_--) solve();
  return 0;
}