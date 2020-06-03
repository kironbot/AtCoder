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
    string S; cin >> S;
    reverse(S.begin(), S.end());
    map<char, ll> mp;
    mp['R'] = 0;
    mp['G'] = 0;
    mp['B'] = 0;
    for(auto c : S) {
        if(mp[c] == 0) mp[c]++;
        else mp[c] = 0;
    }
    ll ans = 0;
    for(auto x : mp) ans += x.second;
    cout << ans << endl;
}
