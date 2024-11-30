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
const int inf = 4e18, p = 1e6 + 7;
int w[N], dp[N];
vector<int> g[N];
void dfs(int x, int pre) {
  dp[x] = w[x];
  for (auto &y : g[x]) {
    if (y == pre) continue;
    dfs(y, x);
    dp[x] = max(dp[x], dp[x] + dp[y]);
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, -1);
  cout << *max_element(dp + 1, dp + 1 + n);
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}