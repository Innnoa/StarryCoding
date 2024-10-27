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
    //不变:
    for (int i = 1; i <= n; i++) {
      ess += type_animal[i] * weight_animal[i];  //鸭鸭最初的重量
    }
    //变化:
    int mx = 0, fix = 0;
    for (int i = 1; i <= n; i++) {
      mx = max(0ll,
               mx + (type_animal[i] ? -1 : 1) * weight_animal[i]);  //子段最值
      fix = max(fix, mx);  //全局最值(根据子段最值求出全局最值)
    }
    cout << ess + fix << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}