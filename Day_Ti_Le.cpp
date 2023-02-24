#include <bits/stdc++.h>
#define taskname "A"
using namespace std;

typedef long long ll;
typedef array<array<ll, 2>, 2> Matrix;
const ll mod = 1e9+7;

Matrix operator *(const Matrix &a, const Matrix &b) {
    Matrix ans = {0, 0, 0, 0};
    ans[0][0] = (a[0][0] * b[0][0] % mod + a[0][1] * b[1][0] % mod) % mod;
    ans[1][0] = (a[1][0] * b[0][0] % mod + a[1][1] * b[1][0] % mod) % mod;
    ans[0][1] = (a[0][0] * b[0][1] % mod + a[0][1] * b[1][1] % mod) % mod;
    ans[1][1] = (a[1][0] * b[0][1] % mod + a[1][1] * b[1][1] % mod) % mod;
    return ans;
}

Matrix power(Matrix b, ll e) {
    Matrix ans = {1, 0, 0, 1};
    for (; e > 0; e >>= 1, b = b * b)
        if (e & 1) ans = ans * b;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    ll a, n; cin >> a >> n;
    Matrix ans = {1, 0, 0, 0};
    Matrix base = {1, 1, 1, 0};
    ans = ans * power(base, n + 1);

    a %= mod;
    cout << (ans[0][0] * a % mod - a + mod) % mod;
    return 0;
}
