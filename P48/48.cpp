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
int a[N];
int stk[N], top;
void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int pos = upper_bound(stk + 1, stk + 1 + top, a[i]) - stk;
    if (pos == top + 1) top++;
    stk[pos] = a[i];
    ans = max(ans, top);
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}