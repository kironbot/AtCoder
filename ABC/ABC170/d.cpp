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

    ll N;
    cin >> N;
    vll a(N);
    rep(i,N) cin >> a[i];
    vll cnt(1100000, 0);
    rep(i,N) cnt[a[i]]++;

    if(N==1) {
        cout << 1 << endl;
        return 0;
    }

    if(cnt[1]==1) {
        cout << 1 << endl;
        return 0;
    }
    else if(cnt[1] >= 2) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    rep(i, N) {
        bool ok = true;
        for(ll n = 2; n*n <= a[i]; n++) {
            if(a[i] % n == 0) {
                ll m = a[i]/n;
                if(cnt[n]) ok = false;
                if(cnt[m]) ok = false;
            }
        }
        if(cnt[a[i]] >= 2) ok = false;
        if(ok) ans++;
    }
    cout << ans << endl;
}
