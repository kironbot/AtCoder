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
    ll h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    ll ans = INF;
    vector<ll> id(h);
    rep(div, 0, 1<<(h-1)) {
        ll g = 0;
        rep(i, 0, h) {
            id[i] = g;
            if(div>>i&1) g++;
        }
        g++;
        vector<vector<ll>> c(h, vector<ll>(w, 0));
        rep(i, 0, h) rep(j, 0, w) c[id[i]][j] += (s[i][j] - '0');

        ll num = g-1;
        vector<ll> now(g);
        auto add = [&](ll j) {
            rep(i, 0, g) now[i] += c[i][j];
            rep(i, 0, g) if(now[i] > k) return false;
            return true;
        };
        rep(j, 0, w) {
            if(!add(j)) {
                num++;
                now = vector<ll>(g);
                if(!add(j)) {
                    num = INF;
                    break;
                }
            }
        }
        chmin(ans, num);
    }
    cout << ans << endl;
}
