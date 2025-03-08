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
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
  int n;
  cin >> n;
  int energy{0};
  for (int i{1}; i <= n; ++i) {
    int a;
    cin >> a;
    pq.push(a);
  }
  while (pq.size() != 1) {
    int min = pq.top();
    pq.pop();
    min += pq.top();
    energy += min;
    pq.pop();
    pq.push(min);
  }
  cout << energy;
  pq.pop();
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}