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
  int MEX, XOR;
  cin >> MEX >> XOR;
  int mex_a = (MEX % 4 == 0)   ? 0
              : (MEX % 4 == 1) ? MEX - 1
              : (MEX % 4 == 2) ? 1
                               : MEX;
  if (mex_a == XOR) {
    cout << MEX << endl;
  } else if ((mex_a ^ XOR) == MEX) {
    cout << MEX + 2 << endl;
  } else {
    cout << MEX + 1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}