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
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    int sum = 0;
    while (a) {
      if ((a & 0b1) == 1) {
        sum++;
      }
      a = a >> 1;
    }
    cout << sum << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}