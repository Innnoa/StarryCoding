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
vector<int> v[N];
bitset<N> vis;
void find_v(int n) {
  vis[n] = true;
  for (auto& i : v[n]) {
    if (vis[i]) {
      continue;
    }
    find_v(i);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int k, j;
    cin >> k >> j;
    if (k != j) v[k].push_back(j);
  }
  find_v(1);
  for (int i = 1; i <= n; i++) {
    if (vis[i]) cout << i << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}