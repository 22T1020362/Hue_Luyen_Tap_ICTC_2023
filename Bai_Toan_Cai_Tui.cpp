#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

map<pair<i64 , i64> , i64> mp;
i64 n , w;
const int N = 101;
i64 a[N] , b[N];

i64 f(i64 id , i64 cost) {
  if (cost > w) {
    return -1e18;
  }

  if (id > n) return 0;
  if (mp.find({id , cost}) != mp.end()) return mp[{id , cost}];
  return mp[{id , cost}] = max(f(id + 1 , cost) , f(id + 1 , cost + a[id]) + b[id]);
}
int main() {
  cin.tie(0) -> sync_with_stdio(false);
  cin >> n >> w;
  for (int i = 1 ; i <= n ; i++) {
    cin >> a[i] >> b[i];
  }
  cout << f(1 , 0) << '\n';
}
