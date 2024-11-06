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

struct Edge {  //生成结构体用于村粗出点和价值
  int x, w;
  bool operator<(const Edge &u) const { return w == u.w ? x < u.x : w > u.w; }
};  //重载运算符以使用堆存储
vector<Edge> g[N];
int d[N];
bitset<N> intree;  //标记
void solve() {
  int n, m;
  cin >> n >> m;
  memset(d, 0x3f, sizeof d);
  for (int i = 1; i <= n; i++) g[i].push_back({i, 0});  //自身调用
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});  //取小,可以认为是双向的
    g[v].push_back({u, w});
  }
  int ans = 0;
  priority_queue<Edge> pq;  //优先队列
  pq.push({1, 0});
  d[1] = 0;
  while (pq.size()) {        //常规判断条件
    auto [x, w] = pq.top();  //有点像序对
    pq.pop();
    if (intree[x]) continue;  //如果使用过则跳过此点
    intree[x] = true;         //设当前点为使用
    ans += w;
    d[x] = 0;
    for (auto &[y, w] : g[x]) {  //找下一个点
      if (!intree[y] && w < d[y]) {
        d[y] = w;
        pq.push({y, w});
      }
    }
  }
  for (int i = 1; i <= n; i++) {  //如果存在独立点,则不存在最小生成树
    if (!intree[i]) {
      ans = -1;
    }
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}