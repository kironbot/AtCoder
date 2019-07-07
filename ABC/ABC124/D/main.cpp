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
    string s;
    cin >> s;

    vector<ll> vec;
    vec.push_back(0);
    rep(i, 1, n) {
        if (s[i-1] != s[i]) vec.push_back(i);
    }
    ll m = vec.size();
    rep(i, 0, n+4*k) vec.push_back(n);

    ll ans = 0;
    rep(i, 0, m) {
        ll idx = vec[i];
        if(s[idx] == '0') chmax(ans, vec[i+2*k] - vec[i]);
        if(s[idx] == '1') chmax(ans, vec[i+2*k+1] - vec[i]);
    }
    cout << ans << endl;
}
