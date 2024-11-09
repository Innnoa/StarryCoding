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
const int N = 998244353;

int fastabs(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % N;
    a = a * a % N;
    b >>= 1;
  }
  return res;
}

int MOX(int a, int b, int c, int x) {
  return ((a * x % N + b) % N * fastabs(c * x % N, N - 2) % N) % N;
}

void solve() {
  int a, b, c, q;
  cin >> a >> b >> c >> q;
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    cout << MOX(a, b, c, x) << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}