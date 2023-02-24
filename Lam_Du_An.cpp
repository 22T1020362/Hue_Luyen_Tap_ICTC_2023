#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
  #include "algo/debug.h"
#else
#define debug(...) 42 
#endif

using i64 = long long;
const int N = 2e5 + 1;
struct node {
  i64 s , e , c;
  bool operator < (node b) {
    return e < b.e;
  }
};

node a[N];
i64 dp[N];

void solve() {
  int n;  cin >> n;
  for (int i = 1 ; i <= n ; i++) {
    cin >> a[i].s >> a[i].e >> a[i].c;
  }
  sort(a + 1 , a + n + 1);
  a[0].e = -1e8;

  for (int i = 1 ; i <= n ; i++) {
    dp[i] = dp[i - 1];
    int l = 0 , r = i - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (a[i].s > a[m].e) {
        l = m + 1;
      }
      else r = m - 1;
    }
    dp[i] = max(dp[i] , dp[l - 1] + a[i].c);
  }
  cout << dp[n];
  
}

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
 
  int TC = 1;
  // cin >> TC;
  while(TC--) {
    solve();
  }
}
