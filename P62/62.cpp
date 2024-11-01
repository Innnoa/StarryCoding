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
int sta[N], top;
int a[N], l[N], r[N];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {               //左闭
    while (top && a[sta[top]] >= a[i]) top--;  //找最小
    if (!top)                                  //均比a[i]大
      l[i] = 0;
    else  //存在比a[i]小
      l[i] = sta[top];
    sta[++top] = i;  //压入
  }
  top = 0;                                    //清空
  for (int i = n; i >= 1; i--) {              //右开
    while (top && a[sta[top]] > a[i]) top--;  //找最小
    if (!top)                                 //均比a[i]大
      r[i] = n + 1;
    else  //存在比a[i]小
      r[i] = sta[top];
    sta[++top] = i;  //压入
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += a[i] * (r[i] - i) * (i - l[i]);  // a[i]乘两边元素个数的乘积求和
  }
  cout << res;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}