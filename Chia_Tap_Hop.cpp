#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
  cin.tie(0) -> sync_with_stdio(false);
  i64 n;  cin >> n;
  if ((n * (n + 1) / 2) % 2 != 0) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  i64 r = n;
  vector<int> _1 , _2;
  i64 sum1 = 0 , sum2 = 0;
  while (r > 0) {
    if (sum1 <= sum2) {
      _1.push_back(r);
      sum1 += r--;
    } else {
      _2.push_back(r);
      sum2 += r--;
    }
  }
  cout << _1.size() << '\n';
  for (int i : _1) {
    cout << i << ' ';
  }
  cout << '\n';
  cout << _2.size() << '\n';

  for (int i : _2) {
    cout << i << ' ';
  }
}
