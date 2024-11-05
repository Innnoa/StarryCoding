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

const int N = 1e3 + 9;
int n, m;
struct Edge {  //自定义类型edge用于存储节点的指向节点和路径价值
  int out, value;
};
bitset<N> vis;  // vis做标记
int d[N];       // d数组存储最短路径
vector<Edge> node[N];  //生成edge类型数组,用于存储节点的入,出,价值,有点像桶
void dijstra(int x) {
  memset(d, 0x3f,
         sizeof(int) * (n + 1));  //设d数组初值为0x3f,使其在下文的比较中覆盖
  d[x] = 0;                       //最初节点的价值为0
  for (int i = 1; i <= n; i++) {  //对所有节点遍历
    int u = 1;
    for (int j = 1; j <= n; j++) {  //寻找最小点
      if (vis[u] || (!vis[j] && d[j] < d[u])) u = j;
    }
    vis[u] = true;                  //标记为true
    for (auto& [v, w] : node[u]) {  //在最小点中找各路径,并计算各路径的价值
      if (!vis[v] && d[v] > d[u] + w) d[v] = d[u] + w;
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    node[u].push_back({v, w});
  }
  dijstra(1);
  if (d[n] >= 0x3f3f3f3f3f3f) {
    cout << "-1";
  } else
    cout << d[n];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}