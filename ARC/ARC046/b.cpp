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

    ll N, A, B;
    cin >> N >> A >> B;

    ll ans;
    if(A == B) {
        if(N % (A+1) == 0) ans = 1;
        else ans = 0;
    }
    else if (A > B) {
        ans = 0;
    }
    else {
        if(A >= N) ans = 0;
        else ans = 1;
    }

    if(ans == 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}
