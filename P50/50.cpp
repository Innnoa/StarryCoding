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
  vector<vector<int>> x_y(n + 1e1, vector<int>(m + 1e1, 0));
  vector<vector<int>> x_y_q(n + 1e1, vector<int>(m + 1e1, 0));
  vector<vector<int>> x_y_next(n + 1e1, vector<int>(m + 1e1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> x_y[i][j];
    }
  }
  while (q--) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    x_y_q[x1][y1] += c;
    x_y_q[x2 + 1][y1] -= c;
    x_y_q[x1][y2 + 1] -= c;
    x_y_q[x2 + 1][y2 + 1] += c;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      x_y_next[i][j] = x_y_next[i - 1][j] + x_y_next[i][j - 1] -
                       x_y_next[i - 1][j - 1] + x_y_q[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << x_y[i][j] + x_y_next[i][j] << " ";
    }
    cout << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}