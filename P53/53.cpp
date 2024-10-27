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
  int t;
  cin >> t;
  while (t--) {
    int MEX, XOR;
    cin >> MEX >> XOR;
    int x = 0;
    for (int i = 0; i < MEX; i++) {
      x = x ^ i;
    }
    if (x == 0 && XOR == 0) {
      cout << MEX << endl;
      continue;
    }
    if (x == 0 && XOR != 0) {
      cout << MEX + 2 << endl;
      continue;
    }
    if (x == XOR) {
      cout << MEX << endl;
      continue;
    }
    cout << "3" << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}