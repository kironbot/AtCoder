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
    ll N[2], K;
    cin >> N[0] >> N[1] >> K;
    vector<ll> num[2];
    num[0].assign(N[0], N[1]);
    num[1].assign(N[1], N[0]);
    rep(k, 0, K) {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        num[0][r]--;
        num[1][c]--;
    }

    ll ans = 0;
    rep(iter, 0, 2) {
        ll mid = 0, sum = 0;
        rep(i, 0, N[iter]) {
            sum += num[iter][i];
            mid = i;
            if (sum >= (N[0]*N[1]-K+1)/2) break;
        }
        ll val = 0;
        rep(i, 0, N[iter]) val += num[iter][i] * abs(i - mid);
        ans += val;
    }

    cout << ans << endl;
}