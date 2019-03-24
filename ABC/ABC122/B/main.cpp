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
    string s;
    cin >> s;
    ll ans = 0;
    for(ll i = 0; i < (ll)s.size(); i++) {
        for (ll j = 1; j <= (ll)s.size() - i; j++) {
            string t = s.substr(i, j);
            bool ok = true;
            for(auto c : t) {
                if (c == 'A' || c == 'C' || c == 'G' || c == 'T') continue;
                else ok = false;
            }
            if (ok) chmax(ans, (ll)t.size());
        }
    }
    cout << ans << endl;
}
