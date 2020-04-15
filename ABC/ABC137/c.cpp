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
    map<string, ll> mp;
    rep(i, 0, n) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    ll ans = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        ll cnt = itr->second;
        if(cnt >= 2) ans += cnt*(cnt-1)/2;
    }
    cout << ans << endl;
}
