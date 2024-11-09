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
const int N = 2e6 + 9;
void solve() {
  int n;
  cin >> n;
  bitset<N> vis;
  for (int i = 2; i <= n; i++) {
    if (!vis[i])
      for (int j = i * 2; j <= n; j += i) vis[j] = 1;
  }
  for (int i = 2; i <= n; i++)
    if (!vis[i]) cout << i << " ";
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}