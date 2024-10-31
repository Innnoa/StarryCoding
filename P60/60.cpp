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
const int N = 2e5 + 10;
int a[N];
int res[N];
stack<int> good;
void solve() {
  int n;
  cin >> n;
  good.push(1e9 + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    while (!good.empty() && good.top() >= a[i]) good.pop();
    if (good.empty()) {
      res[i] = -1;
    } else
      res[i] = good.top();
    good.push(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}