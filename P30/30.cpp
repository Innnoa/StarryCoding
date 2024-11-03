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
vector<int> res;
bitset<15> vis;
void arr(int n, int len) {
  if (len == n) {
    for (auto& i : res) {
      cout << i << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vis[i] = true;
    res.push_back(i);
    len++;
    arr(n, len);
    vis[i] = false;
    res.pop_back();
    len--;
  }
}
void solve() {
  int n;
  cin >> n;
  arr(n, 0);
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}