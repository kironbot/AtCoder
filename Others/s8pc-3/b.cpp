#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll H, W, K;
    cin >> H >> W >> K;
    vvc org(H+1, vc(W, '0'));
    rep(i, H) rep(j, W) cin >> org[H-1-i][j];

    ll ans = 0;

    if(K == 1) {
        rep(i, H) rep(j, W) ans += org[i][j] - '0';
        cout << ans << endl;
        return 0;
    }

    rep(py, H) rep(px, W) {
        if(py == 0 && px == 2) {
            ;
        }

        vvc in(H+1, vc(W, '0'));
        rep(i, H) rep(j, W) in[i][j] = org[i][j];

        for(ll y = py; y < H; y++) in[y][px] = in[y+1][px];

        ll ret = 0, num = 0;
        bool end = false;
        while(!end) {
            vvb used(H+1, vb(W, false));
            end = true;
            ll sumin = 0;

            rep(i, H) {
                ll left = 0, right = 0, cnt = 1;
                for(ll j = 1; j <= W; j++) {
                    if(in[i][j-1] == in[i][j] && in[i][j] != '0') {
                        cnt++;
                        right = j;
                        if(j == W && cnt >= K) {
                            sumin += cnt * (in[i][j] - '0');
                            for(ll k = left; k <= right; k++) used[i][k] = true;
                            end = false;
                        }
                    }
                    else {
                        if(cnt >= K) {
                            sumin += cnt * (in[i][j-1] - '0');
                            for(ll k = left; k <= right; k++) used[i][k] = true;
                            end = false;
                        }
                        left = right = j;
                        cnt = 1;
                    }
                }
            }
            ret += (1<<num) * sumin;
            num++;

            rep(j, W) {
                rep(i, H) {
                    ll k = i;
                    while(used[k][j]) k++;
                    in[i][j] = in[k][j];
                    if(in[k][j] != '0') used[k][j] = true;
                }
            }
        }
        chmax(ans, ret);
    }
    cout << ans << endl;
}
