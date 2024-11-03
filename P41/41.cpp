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
const int N = 2e5 + 9;
int a[N], m[N], tid[N];
int n, q;
int lowbit(int x) { return x & -x; }
void upthis(int k, int v) {
  for (int i = k; i <= n; i += lowbit(i)) {
    m[i] += v;
    tid[i] += k * v;
  }
}
int outthis(int t) {
  int res = 0;
  for (int i = t; i >= 1; i -= lowbit(i)) {
    res += (t + 1) * m[i] - tid[i];
  }
  return res;
}
void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    upthis(i, a[i]);
    upthis(i + 1, -a[i]);
  }
  for (int i = 1; i <= q; i++) {
    int fuck;
    cin >> fuck;
    if (fuck == 1) {
      int k, r, v;
      cin >> k >> r >> v;
      upthis(k, v);
      upthis(r + 1, -v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << outthis(r) - outthis(l - 1) << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}