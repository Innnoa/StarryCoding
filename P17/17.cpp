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
const int N = 1e5 + 9;
void solve() {
  int n;
  cin >> n;
  vector<int> res;
  for (int i = 2; i <= n / i; i++) {
    if (n % i) {
      continue;
    }
    res.push_back(i);
    while (n % i == 0) {
      n /= i;
    }
  }
  if (n > 1) res.push_back(n);
  sort(res.begin(), res.end());
  for (auto& i : res) {
    cout << i << " ";
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}