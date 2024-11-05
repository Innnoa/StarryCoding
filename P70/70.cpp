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

const int N = 2e5 + 9;
int n, m;
struct Edge {  //自定义类型edge用于存储节点的指向节点和路径价值
  int out, value;
  bool operator<(const Edge& v) const {  //自定义运算符
    return value == v.value ? out < v.out : value > v.value;
  }
};
bitset<N> vis;  // vis做标记
int d[N];       // d数组存储最短路径
vector<Edge> node[N];  //生成edge类型数组,用于存储节点的入,出,价值,有点像桶
void dijkstra(int x) {
  memset(d, 0x3f,
         sizeof(int) * (n + 1));  //设d数组初值为0x3f,使其在下文的比较中覆盖
  d[x] = 0;                       //最初节点的价值为0
  priority_queue<Edge> pq;  //用优先队列(堆)来存储,自带维护,小顶堆
  pq.push({x, d[x]});       //先把x存入
  while (
      pq.size()) {  //其实都是一个东西,只是因为小顶堆自带维护功能,代替其挨个找最小
    int a = pq.top().out;
    pq.pop();
    if (vis[a]) continue;
    vis[a] = true;
    for (auto& [y, w] : node[a]) {
      if (!vis[y] && d[y] > d[a] + w) {  //判断
        d[y] = d[a] + w;
        pq.push({y, d[y]});  //压入
      }
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
  dijkstra(1);
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