#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    int b[30];
    rep(i, 0, m) cin >> b[i];
    int a[30][30];
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

    int ans = 0;
    rep(i, 0, n) {
        int tmp = c;
        rep(j, 0, m) {
            tmp += a[i][j] * b[j];
        }
        if (tmp > 0) ans++;
    }
    cout << ans << endl;
}
