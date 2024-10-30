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

struct cmp {
  bool operator()(const int &u, const int &v) const { return u < v; }
};

void solve() {
  priority_queue<int, vector<int>, cmp> pq;
  int q;
  cin >> q;
  int weight = 0;
  for (int i = 1; i <= q; i++) {
    int q_i;
    cin >> q_i;
    if (q_i == 1) {
      int q_in;
      cin >> q_in;
      pq.push(q_in);
      weight += q_in;
    } else {
      if (pq.size()) {
        weight -= pq.top();
        pq.pop();
      }
    }
  }
  cout << weight;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}