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
const int N = 3e2 + 9;
int node[N][N];  //因为是单向节点,用于存储一个节点到另一个节点的价值
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  memset(node, 0x3f, sizeof node);
  for (int i = 1; i <= m; i++) {  //存入
    int u, v, w;
    cin >> u >> v >> w;
    node[u][v] = min(node[u][v], w);
  }
  for (int i = 1; i <= n; i++) {  //自己指向自己的价值为0
    node[i][i] = 0;
  }
  for (int k = 1; k <= n; k++) {  //背下来即可
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        node[i][j] = min(node[i][j], node[i][k] + node[k][j]);
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (node[u][v] >= 4e18 ? -1 : node[u][v]) << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}