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
const int N = 1e2 + 5;
const int M = 1e4 + 9;
int dp[M];
void solve() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int s, w, v;
    cin >> s >> w >> v;
    while (s--) {
      for (int j = m; j >= 0; j--) {
        if (j >= v)
          dp[j] = max(dp[j], dp[j - v] + w);
        else
          dp[j] = dp[j];
      }
    }
  }
  cout << dp[m];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}