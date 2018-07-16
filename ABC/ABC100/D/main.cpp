#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    ll x[N], y[N], z[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    
    ll s[8][N];
    for (int i = 0; i < N; i++) {
        s[0][i] = x[i] + y[i] + z[i];
        s[1][i] = -x[i] + y[i] + z[i];
        s[2][i] = x[i] - y[i] + z[i];
        s[3][i] = -x[i] - y[i] + z[i];
        s[4][i] = x[i] + y[i] - z[i];
        s[5][i] = -x[i] + y[i] - z[i];
        s[6][i] = x[i] - y[i] - z[i];
        s[7][i] = -x[i] - y[i] - z[i];
    }
    sort(s[0], s[0]+N, greater<ll>());
    sort(s[1], s[1]+N, greater<ll>());
    sort(s[2], s[2]+N, greater<ll>());
    sort(s[3], s[3]+N, greater<ll>());
    sort(s[4], s[4]+N, greater<ll>());
    sort(s[5], s[5]+N, greater<ll>());
    sort(s[6], s[6]+N, greater<ll>());
    sort(s[7], s[7]+N, greater<ll>());
    
    ll sum[8];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 8; j++) {
            if ( i == 0) sum[j] = 0;
            sum[j] += s[j][i];
        }
    }
    
    ll res = 0;
    for (int i = 0; i < 8; i++) {
        res = max(res, sum[i]);
    }
    if (M == 0) res = 0;
    cout << res << endl;
}
