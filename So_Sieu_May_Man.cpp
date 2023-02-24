#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
#include "algo/debug.h"
#else
#define debug(...) 42 
#endif

using i64 = long long;
vector<i64> tmp , a , mul;

void f(i64 n) {
  if (n > 1e12) {
    return;
  }
  if (n > 1)
    tmp.push_back(n);
  f(n * 10 + 4);
  f(n * 10 + 7);
}

void F(i64 id , i64 pre) {
  if (pre > 1e12 || pre <= 0) {
    return;
  }
  if (pre > 1) {
    mul.push_back(pre);
  }
  for (int i = id ; i < (int) tmp.size() ; i++) {
    if (pre * tmp[i] > 1e12 or pre * tmp[i] <= 0) return;
    F(i , tmp[i] * pre);
  }
}


void solve() {
  i64 l , r;
  cin >> l >> r;
  cout << upper_bound(a.begin() , a.end() , r) - lower_bound(a.begin() , a.end() , l) << '\n';
}

int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  f(0LL);
  sort(tmp.begin() , tmp.end());
  F(0LL , 1LL);
  set<i64> s(mul.begin() , mul.end());
  a = vector<i64> (s.begin() , s.end());
  int TC = 1;
  cin >> TC;
  while(TC--) {
    solve();
  }
}
