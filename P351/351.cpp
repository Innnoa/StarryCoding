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
deque<char> deq{'#'};
void solve() {
  string str;
  cin >> str;
  int digit{0};
  for (const auto& i : str) {
    if (isdigit(i)) {
      deq.push_front(i);
      ++digit;
    } else {
      deq.push_back(i);
    }
  }
  reverse(deq.begin(), deq.begin() + digit);
  for (const auto& i : deq) {
    cout << i;
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int _;
  cin >> _;
  while (_--) solve();
  return 0;
}