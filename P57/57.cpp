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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 10, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int x;
    cin >> x;
    int l = 0, r = n;
    while (l + 1 != r) {
      int mid = ((l + r) >> 1);
      if (x > a[mid]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    if (a[r] == x)
      cout << r << " ";
    else
      cout << "-1 ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}