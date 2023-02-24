#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;
ll n, t;
vector <ll> a(N);
bool F (ll val) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans >= t) return true;
        ans += (ll) val / a[i];
    }
    return ans >= t;
}

void Solve(){
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll L = 1, R = 1e18;
    while (L + 1 < R) {
        ll mid = (L + R) >> 1;
        if (F (mid)) {
            R = mid;
        }
        else{
            L = mid;
        }
    }
    cout << R;
}
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int cas = 1; 
  //cin >> cas;
  while(cas--) Solve();
  return 0;
}
