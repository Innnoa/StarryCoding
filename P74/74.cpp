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
int dp[1009];
void solve() {
  for (int i = 0; i <= T; i++) dp[i] = 0;
  for (int i = 1; i <= M; i++) cin >> t[i] >> v[i];
  for (int i = 1; i <= M; i++) {
    for (int j = T; j >= 1; j--) {
      if (j >= t[i])
        dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
      else
        dp[j] = dp[j];
    }
  }
  cout << dp[T] << endl;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> T >> M) {
    if (T == 0 && M == 0) break;
    solve();
  }
  return 0;
}