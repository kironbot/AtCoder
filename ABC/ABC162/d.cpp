#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    string S;
    cin >> N >> S;

    vll vr, vg, vb;
    rep(i, N) {
        if(S[i] == 'R') vr.push_back(i);
        if(S[i] == 'G') vg.push_back(i);
        if(S[i] == 'B') vb.push_back(i);
    }


    ll ans = 0;
    for(ll j = 1; j < N-1; j++) {
        if(S[j] == 'R') {
            ll left = vg.end() - lower_bound(vg.begin(), vg.end(), j);
            ll right = lower_bound(vb.begin(), vb.end(), j) - vb.begin();
            ans += left * right;
            left = vb.end() - lower_bound(vb.begin(), vb.end(), j);
            right = lower_bound(vg.begin(), vg.end(), j) - vg.begin();
            ans += left * right;
        }
        if(S[j] == 'G') {
            ll left = vr.end() - lower_bound(vr.begin(), vr.end(), j);
            ll right = lower_bound(vb.begin(), vb.end(), j) - vb.begin();
            ans += left * right;
            left = vb.end() - lower_bound(vb.begin(), vb.end(), j);
            right = lower_bound(vr.begin(), vr.end(), j) - vr.begin();
            ans += left * right;
        }
        if(S[j] == 'B') {
            ll left = vg.end() - lower_bound(vg.begin(), vg.end(), j);
            ll right = lower_bound(vr.begin(), vr.end(), j) - vr.begin();
            ans += left * right;
            left = vr.end() - lower_bound(vr.begin(), vr.end(), j);
            right = lower_bound(vg.begin(), vg.end(), j) - vg.begin();
            ans += left * right;
        }

        for(ll len = 1; j + len <= N-1; len++) {
            if(j - len < 0) continue;
            if(S[j-len] != S[j] && S[j-len] != S[j+len] && S[j] != S[j+len]) ans--;
        }
    }    
    cout << ans << endl;
}
