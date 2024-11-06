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

struct Edge {
  int u, v, w;
  bool operator<(const Edge &m) const { return w < m.w; }
};

int d[N];
int pre[N];

int find(int x) { return pre[x] = (pre[x] == x ? x : find(pre[x])); }

void solve() {
  int n, m;
  cin >> n >> m;
  memset(d, 0x3f, sizeof d);

  vector<Edge> es;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    es.push_back({u, v, w});
  }
  sort(begin(es), end(es));
  int ans = 0;
  for (int i = 1; i <= n; i++) pre[i] = i;
  for (auto &[u, v, w] : es) {
    if (find(u) == find(v)) continue;
    ans += w;
    pre[find(u)] = find(v);
  }
  for (int i = 1; i < n; i++)
    if (find(i) != find(i + 1)) ans = -1;

  cout << ans;
}

signed main() {
  int _ = 1;
  while (_--) solve();
  return 0;
}