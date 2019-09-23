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
    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> ans(n, 1);
    rep(i, 0, n-1) {
        if(s[i]=='R' && s[i+1]=='R') {
            ans[i+2] += ans[i];
            ans[i] = 0;
        }
    }
    for(ll i=n-1; i >= 1; --i) {
        if(s[i]=='L' && s[i-1]=='L') {
            ans[i-2] += ans[i];
            ans[i] = 0;
        }
    }
    rep(i, 0, n) cout << ans[i] << " ";
    cout << endl;
}
