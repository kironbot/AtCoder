#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
#define vll vector<ll>
#define vvll vector<vll>
#define vc vector<char>
#define vvc vector<vc>
#define pll pair<ll, ll>
#define vpll vector<pll>
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N;
    cin >> N;
    ll c[20][20];
    rep(i, N) {
        ll a;
        cin >> a;
        rep(j, a) {
            ll x, y;
            cin >> x >> y;
            x--;
            c[i][x] = y;
        }
    }
}
