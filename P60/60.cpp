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
const int N = 2e5 + 10;
int a[N];
int res[N];
void solve() {
  a[0] = 1e9 + 1;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < a[i - 1] && res[i - 1] == -1) {
      res[i] = -1;
    }
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] < a[i]) {
        res[i] = a[j];
        j = -1;
      }
    }
    if (!res[i]) {
      res[i] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << res[i] << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}