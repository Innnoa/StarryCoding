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

const int N = 5e3 + 10, M = 5e5 + 10;

void solve() {
  int n;
  cin >> n;
  bitset<M> bs;
  bs[0] = 1;
  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;
    bs |= (bs << a_i);
  }
  cout << bs.count();
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  while (_--) solve();
  return 0;
}