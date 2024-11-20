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
const int M = 2e3 + 9;
int dp[M];
void solve() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int s, w, v;
    cin >> s >> w >> v;
    vector<int> vec;
    int x = 1;
    while (s >= x) vec.push_back(x), s -= x, x <<= 1;
    if (s) vec.push_back(s);
    for (auto& k : vec) {
      for (int j = m; j >= 0; j--) {
        if (j >= k * v)
          dp[j] = max(dp[j], dp[j - k * v] + k * w);
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