#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 1;
ll c[1005][1005];
ll mod = 9929;
void Combination(){
    for(int i = 0; i <= 1000; i++ ){
        for( int j = 0; j <= i; j++ ){
            if(i == j || j == 0) c[i][j] = 1;
            else c[i][j] = ((c[i - 1][j] % mod + c[i - 1][j - 1] % mod) % mod );
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, r; cin >> k >> r;
    Combination();
    cout << c[k + 1][r];
    return 0;
}
