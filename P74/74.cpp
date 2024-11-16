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
int T, M;
int t[105], v[105];
int dp[105][1009];
void solve() {
  for (int i = 1; i <= M; i++) {
    cin >> t[i] >> v[i];
  }
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= T; j++) {
      if (j >= t[i])
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[M][T] << endl;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> T >> M) {
    if (T == 0 && M == 0) break;
    solve();
  }
  return 0;
}