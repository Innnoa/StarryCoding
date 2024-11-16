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
const int N = 5e2 + 5;
const int M = 1e5 + 5;
int w[N], v[N];
int dp[2][M];
void solve() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int y = i & 1;
      if (j >= v[i])
        dp[y][j] = max(dp[y ^ 1][j], dp[y][j - v[i]] + w[i]);
      else
        dp[y][j] = dp[y ^ 1][j];
    }
  }
  cout << dp[n & 1][m];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}