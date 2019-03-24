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
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> cnt(n+1);
    cnt[0] = 0;
    for(ll i = 1; i <= n; i++) {
        if(s[i-1] == 'A' && s[i] == 'C') cnt[i] = cnt[i-1] + 1;
        else cnt[i] = cnt[i-1];
    }
    rep(i, 0, q) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << max(0LL, cnt[r] - cnt[l]) << endl;
    }
}
