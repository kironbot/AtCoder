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
    ll n;
    cin >> n;
    vector<ll> cnt(n, 0), a(n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i]--;
        cnt[a[i]]++;
    }

    ll all = 0;
    rep(i, 0, n) {
        if(cnt[i] >= 2) all += (cnt[i]-1) * cnt[i] / 2;
    }

    rep(i, 0, n) {
        if(cnt[a[i]] < 2) cout << all << endl;
        else {
            ll pre = (cnt[a[i]]-1) * cnt[a[i]] / 2;
            ll cur = (cnt[a[i]]-2) * (cnt[a[i]] - 1) / 2;
            ll ans = all - pre + cur;
            cout << ans << endl;
        } 
    }
}
