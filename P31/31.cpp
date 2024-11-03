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
int a[N], t[N];
vector<int> X;
int lowbit(int x) { return x & -x; }
int bin(int x) { return lower_bound(X.begin(), X.end(), x) - X.begin() + 1; }
void update(int k, int x) {
  for (unsigned int i = k; i <= X.size(); i += lowbit(i)) {
    t[i] += x;
  }
}
int getsum(int k) {
  int res = 0;
  for (int i = k; i >= 1; i -= lowbit(i)) {
    res += t[i];
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    X.push_back(a[i]);
  }
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1ll * getsum(X.size()) - getsum(bin(a[i]));
    update(bin(a[i]), 1);
  }
  cout << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}