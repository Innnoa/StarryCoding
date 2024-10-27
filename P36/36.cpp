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
const int N = 1e5 + 10;
int a[N];
void solve() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int l_max = 0;
    for (int i = 1, j = 1; i <= n && j < n; j++) {
      for (int k = i; k <= j; k++) {
        if (a[j + 1] == a[k]) {
          i = k + 1;
        }
      }
      l_max = max(l_max, j - i + 1);
    }
    cout << l_max + 1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}