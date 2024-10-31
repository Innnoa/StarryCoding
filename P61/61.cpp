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
const int N = 2e5 + 9;
int a[N], res_min[N], res_max[N];
int fuck[N], front, back;
void solve() {
  int n, k;
  cin >> n >> k;
  // deque<int> fuck;  //存储下标
  for (int i = 1; i <= n; i++) cin >> a[i];
  // max
  for (int i = 1; i <= n; i++) {
    //验证队头合理性,大小是否合理
    while (back - front + 1 && fuck[front] <= i - k) front++;
    //验证队尾优越性,选大的
    while (back - front + 1 && a[fuck[back]] <= a[i]) back--;
    fuck[++back] = i;
    if (i >= k) cout << a[fuck[front]] << " ";  //一定是头最大
  }
  front = 1;
  back = 0;  //清空
  cout << endl;
  // min
  for (int i = 1; i <= n; i++) {
    //验证队头合理性,大小是否合理
    while (back - front + 1 && fuck[front] <= i - k) front++;
    //验证队尾优越性,选小的
    while (back - front + 1 && a[fuck[back]] >= a[i]) back--;
    fuck[++back] = i;
    if (i >= k) cout << a[fuck[front]] << " ";  //一定是头最小
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}