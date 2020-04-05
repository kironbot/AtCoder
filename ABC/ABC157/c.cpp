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

    ll N, M;
    cin >> N >> M;
    vll s(M);
    vc c(M);
    rep(i, M) cin >> s[i] >> c[i];

    ll ans = -1;
    for(ll i = 0; i < pow(10, N); i++) {
        if (N > 1 && i < pow(10, N-1)) continue;

        bool ok = true;
        rep(j, M) {
            string t = to_string(i);
            if((ll)t.size() != N) ok = false;
            else if(t[s[j]-1] != c[j]) ok = false;
        }
        if(ok) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}