#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    ll N; cin >> N;
    vll A(N+1);
    rep(i, N+1) cin >> A[i];
    vll sa(N+2, 0);
    // sa[i] := sum of A[0, i)
    rep(i, N+2) {
        if(i > 0) sa[i] = sa[i-1] + A[i-1];
    }

    if(A[0] >= 2) {
        cout << -1 << endl;
        return 0;
    }

    ll b = 1 - A[0];
    ll ans = 1;
    for(int i = 1; i <= N; i++) {
        b = 2 * b - A[i];
        if(b < 0) {
            cout << -1 << endl;
            return 0;
        }
        chmin(b, sa[N+1] - sa[i+1]);
        ans +=  b + A[i];
    }
    cout << ans << endl;
}
