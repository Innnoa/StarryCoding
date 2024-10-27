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
const int N = 2e5 + 10;

class Book {
 public:
  int a, b, c;
  // bool operator<(const Book &u) const {
  // if (a == u.a && b == u.b) return c < u.c;
  // if (a == u.a) return b < u.b;
  // return a < u.a;
  // }
} p[N];

bool cmp(const Book &u, const Book &v) {
  if (u.a == v.a && u.b == v.b) return u.c > v.c;
  if (u.a == v.a) return u.b > v.b;
  return u.a > v.a;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].a >> p[i].b >> p[i].c;
  }
  sort(p + 1, p + 1 + n, cmp);
  // reverse(p + 1, p + 1 + n);
  for (int i = 1; i <= n; i++) {
    cout << p[i].a << " " << p[i].b << " " << p[i].c << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}