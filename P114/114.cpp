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
const int N = 3e2 + 5, inf = 4e18;
int a[N], prefix[N];
int dp[N][N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1, j = i + len - 1; j <= n; i++, j++) {
      dp[i][j] = inf;
      for (int k = i; k < j; k++) {
        dp[i][j] =
            min(dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1], dp[i][j]);
      }
    }
  }
  cout << dp[1][n];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}