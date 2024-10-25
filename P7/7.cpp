// Problem: ${前缀和}
// Contest: ${json.group}
// URL: ${https://www.starrycoding.com/problem/7}
// Memory Limit: ${128} MB
// Time Limit: ${500} ms
// More thought is needed

#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

void solve() {
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> n_i_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int n_i_num;
      cin >> n_i_num;
      n_i_sum[i] = n_i_sum[i - 1] + n_i_num;
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      cout << n_i_sum[r] - n_i_sum[l - 1] << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}