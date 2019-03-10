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
    ll ans = INF;
    for(char c = 'a'; c <= 'z'; c++) {
        ll tmp = 0, con = 0;
        rep(j, 0, (ll)s.size()) {
            if(s[j] == c) {
                chmax(tmp, con);
                con = 0;
            } else {
                con++;
            }
        }
        chmax(tmp, con);
        chmin(ans, tmp);
    }
    cout << ans << endl;
}