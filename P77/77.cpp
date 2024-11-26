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
const int N = 2e5 + 9;
int a[N], dp[N];

void solve() {
  int n;
  cin >> n;
  int max_n = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = i - 1; j > 0; j--) {
      if (a[i] >= a[j]) dp[i] = max(dp[j] + 1, dp[i]);
      max_n = max(max_n, dp[i]);
    }
  }
  cout << max_n;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}