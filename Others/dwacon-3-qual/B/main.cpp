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
    string t;
    cin >> t;

    ll ans = 0;
    ll ni = 0, co = 0;
    for (auto c : t) {
        ll ni2, co2;
        if (c == '2' || c == '?') ni2 = co + 1;
        else ni2 = 0;
        if (c == '5' || c == '?') co2 = ni + 1;
        else co2 = 0;
        ni = ni2;
        co = co2;
        chmax(ans, co / 2 * 2);
    }
    cout << ans << endl;
}