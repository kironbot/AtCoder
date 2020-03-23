#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N; string S;
    cin >> N >> S;
    ll ans = 0;
    rep(i, 1000) {
        int c[3] = {i / 100, (i / 10) % 10, i % 10};
        int f = 0;
        rep(j, N) {
            if(S[j] == (c[f] + '0')) f++;
            if(f == 3) break;
        }
        if(f == 3) ans++;
    }
    cout << ans << endl;
}
