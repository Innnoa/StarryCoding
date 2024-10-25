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
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> a_i(n + 9, 0);
  vector<int> a_i_diff(n + 9, 0);
  vector<int> a_i_sum(n + 9, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a_i[i];
  }
  for (int i = 1; i <= n; i++) {
    a_i_diff[i] = a_i[i] - a_i[i - 1];
  }
  while (p--) {
    int l_1, r_1, x;
    cin >> l_1 >> r_1 >> x;
    a_i_diff[l_1] += x;
    a_i_diff[r_1 + 1] -= x;
  }
  for (int i = 1; i <= n; i++) {
    a_i[i] = a_i[i - 1] + a_i_diff[i];
  }
  for (int i = 1; i <= n; i++) {
    a_i_sum[i] = a_i_sum[i - 1] + a_i[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << a_i_sum[r] - a_i_sum[l - 1] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}