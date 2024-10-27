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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> type_animal(n + 10, 0);
    vector<int> weight_animal(n + 10, 0);
    vector<int> prefix(n + 10, 0);
    for (int i = 1; i <= n; i++) {
      cin >> type_animal[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> weight_animal[i];
    }
    int ess = 0;
    for (int i = 1; i <= n; i++) {
      ess += type_animal[i] * weight_animal[i];
    }
    int mx = 0, fix = 0;
    for (int i = 1; i <= n; i++) {
      mx = max(0ll, mx + (a[i] ? -1 : 1)w[i]);
      fix = max(fix, mx);
    }
    cout << ess + fix << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}