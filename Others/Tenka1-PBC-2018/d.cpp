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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    ll N;
    cin >> N;

    ll tmp = sqrt(2 * N);
    ll k;
    if (2 * N == tmp * (tmp - 1)) k = tmp;
    else if (2 * N == tmp * (tmp + 1)) k = tmp + 1;
    else {
        cout << "No" << endl;
        return 0;
    }

    ll a = 1;
    vvll ans(k);
    for(ll i = 0; i < k; i++) {
        for(ll j = i + 1; j < k; j++) {
            ans[i].push_back(a);
            ans[j].push_back(a);
            a++;
        }
    }

    cout << "Yes" << endl;
    cout << k << endl;
    rep(i, k) {
        cout << k-1;
        rep(j, k-1) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
}