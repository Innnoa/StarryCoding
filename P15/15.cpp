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
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> x_y_sum(n + 1e1, vector<int>(m + 1e1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x_y_num;
      cin >> x_y_num;
      x_y_sum[i][j] = x_y_sum[i][j - 1] + x_y_sum[i - 1][j] -
                      x_y_sum[i - 1][j - 1] + x_y_num;
    }
  }
  while (q--) {
    int x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    cout << x_y_sum[x_2][y_2] - x_y_sum[x_1 - 1][y_2] - x_y_sum[x_2][y_1 - 1] +
                x_y_sum[x_1 - 1][y_1 - 1]
         << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}