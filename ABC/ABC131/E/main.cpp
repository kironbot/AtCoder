#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, a, n) for (ll i = (a); i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll n, k;
    cin >> n >> k;
    ll kmax = (n-1) * (n-2) / 2;
    if(kmax < k) {
        cout << -1 << endl;
        return 0;
    }

    ll l = kmax - k;
    cout << n - 1 + l << endl;
    rep(i, 2, n+1) cout << 1 << " " << i << endl;
    rep(i, 2, n+1) rep(j, 2, n+1) {
        if (i >= j) continue;
        if (l > 0) {
            cout << i << " " << j <<endl;
            l--;
        }
    }
}
