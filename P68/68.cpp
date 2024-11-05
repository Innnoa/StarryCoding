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
int pre[N];  //用来说明下一个节点指向
int Hash[N];
int root(int i) {
  return pre[i] = (pre[i] == i ? i : root(pre[i]));
}  // root数组用来找到输入节点的root节点
void merge(int u, int v) { pre[root(u)] = root(v); }  //用于将u节点连接到v节点上
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) pre[i] = i;  //将每个节点初始化为pre指向自己
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    merge(u, v);
  }
  for (int i = 1; i <= n; i++) {
    Hash[root(i)]++;  //桶存储
  }
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (Hash[i]) vec.push_back(Hash[i]);  //存到vec中
  }
  sort(vec.begin(), vec.end());
  for (auto& i : vec) {
    cout << i << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}