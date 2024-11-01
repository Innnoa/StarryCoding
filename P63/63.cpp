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
const int N = 3e5 + 9;

vector<int> vec;
int res[N];

struct Q {
  int a, b;
} add[N], que[N];

auto find_x(int x) {
  return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x, w;
    cin >> x >> w;
    add[i] = {x, w};
    vec.push_back(x);
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    vec.push_back(l);
    vec.push_back(r);
    que[i] = {l, r};
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());

  for (int i = 1; i <= n; i++) {
    res[find_x(add[i].a)] += add[i].b;
  }
  for (unsigned int i = 1; i <= vec.size(); i++) {
    res[i] += res[i - 1];
  }
  for (int i = 1; i <= q; i++) {
    cout << res[find_x(que[i].b)] - res[find_x(que[i].a) - 1] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  while (_--) solve();
  return 0;
}