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
const int N = 1e2;
int dp[N];

void fib() {
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= N; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
}

void solve() {
  fib();
  int n;
  cin >> n;
  cout << dp[n];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}