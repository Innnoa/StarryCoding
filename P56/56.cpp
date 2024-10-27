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

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;
    a.push_back(a_i);
  }
  sort(a.begin(), a.end());
  for (auto &i : a) {
    cout << i << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}