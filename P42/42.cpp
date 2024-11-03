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
vector<int> fa[60];
void dfs(int n) {
  cout << n << " ";
  for (auto& i : fa[n]) {
    dfs(i);
  }
}
void bfs(int n) {
  queue<int> qe;
  qe.push(n);
  while (qe.size()) {
    int x = qe.front();
    qe.pop();
    cout << x << " ";
    for (auto& i : fa[x]) qe.push(i);
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int fa_i;
    cin >> fa_i;
    fa[fa_i].push_back(i);
  }
  dfs(1);
  cout << endl;
  bfs(1);
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}