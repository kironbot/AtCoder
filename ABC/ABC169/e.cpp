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
    vpll v1, v2;
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        v1.emplace_back(a, b);
        v2.emplace_back(b, a);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll ans;
    if(N % 2 == 1) {
        ans = v2[(N-1)/2].first - v1[(N-1)/2].first + 1;
    }
    else {
        ans = v2[N/2].first + v2[N/2-1].first - v1[N/2].first - v1[N/2-1].first + 1;
    }
    cout << ans << endl;
}
