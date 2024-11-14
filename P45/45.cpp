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
const int N = 1e3 + 9;
const int M = 1e9 + 7;
int a[N][N];
void solve() {
  int n, m;
  cin >> n >> m;
  a[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = (a[i - 1][j - 1] % M + a[i - 1][j] % M) % M;
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}