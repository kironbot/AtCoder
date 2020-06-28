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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

ll N, K;
vll P, M, Z;

// x(<0)以下の積の個数 >= K かどうかチェック
bool check1(ll x) {
    ll sum = 0;
    for(auto p : P) {
        ll y = (x - p + 1) / p; // x < 0 に注意
        sum += upper_bound(M.begin(), M.end(), y) - M.begin();
    }
    return sum >= K;
}

// x(>0)以下の積の個数 >= K かどうかチェック
bool check2(ll x) {
    ll sum = 0;
    rep(i, P.size()) {
        ll y = x / P[i];
        ll tmp = upper_bound(P.begin(), P.end(), y) - P.begin();
        if(i < tmp) tmp--; //自身を除く
        sum += tmp;
    }
    rep(i, M.size()) {
        ll y = x / M[i];
        ll tmp = upper_bound(M.begin(), M.end(), y) - M.begin();
        if(i < tmp) tmp--; //自身を除く
        sum += tmp;
    }
    sum /= 2;
    return sum >= K;
}

int main() {
    cin >> N >> K;
    rep(i,N) {
        ll a;
        cin >> a;
        if(a > 0) P.push_back(a);
        if(a < 0) M.push_back(a);
        if(a == 0) Z.push_back(a);
    }

    ll cp = P.size(), cm = M.size(), cz = Z.size();
    ll minus = cp*cm;
    ll zero = cz*(cp+cm) + cz*(cz-1)/2;

    if(K <= minus) {
        sort(P.begin(), P.end());
        sort(M.begin(), M.end());

        ll ng = -1e18-1, ok = 0;
        while(ok - ng > 1) {
            ll mid = ng + (ok - ng) / 2;
            if(check1(mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
    else if(K <= minus + zero) {
        cout << 0 << endl;
    }
    else {
        K -= minus + zero;
        sort(P.begin(), P.end());
        rep(i, M.size()) M[i] = -M[i];
        sort(M.begin(), M.end());

        ll ng = -1, ok = 1e18+1;
        while(ok - ng > 1) {
            ll mid = ng + (ok - ng) / 2;
            if(check2(mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }

}
