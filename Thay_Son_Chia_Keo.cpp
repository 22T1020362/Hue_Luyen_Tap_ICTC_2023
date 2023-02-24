#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
  #include "algo/debug.h"
#else
#define debug(...) 42 
#endif

using i64 = long long;

void solve() {
  i64 m , n , sum = 0;  cin >> m >> n;
  
  vector<i64> a(n);
  
  for (i64 &o : a) cin >> o , sum += o;

  sort(a.begin() , a.end());
  i64 k = sum - m;
  i64 ans = 0;
  for (int i = 0 ; i < n ; i++) {
    i64 tmp = k / (n - i);
    if (tmp <= a[i]) {
      ans += tmp * tmp;
      k -= tmp;
    } else {
      ans += a[i] * a[i];
      k -= a[i];
    }
  }
  cout << ans;
}

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  int TC = 1;
  // cin >> TC;
  while(TC--) {
    solve();
  }
}
