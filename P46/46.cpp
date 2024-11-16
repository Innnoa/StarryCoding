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
const int N = 1e9 + 7;
const int B = 1e7 + 9;
int fac[B];
int fastabs(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % N;
    a = a * a % N;
    b >>= 1;
  }
  return res;
}

void factorial() {
  fac[0] = 1;
  for (int i = 1; i < 1e7; i++) fac[i] = fac[i - 1] * i % N;
}
int MOX(int n, int m) {
  return ((fac[n] % N) % N * fastabs(fac[n - m] * fac[m] % N, N - 2) % N) % N;
}

void solve() {
  int n, m;
  cin >> n >> m;
  cout << MOX(n, m) << endl;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  factorial();
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}