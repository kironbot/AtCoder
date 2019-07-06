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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--, b--, c--, d--;
    string s;
    cin >> s;

    rep(i, 0, n-1) {
        if(i < a) continue;
        if(max(c, d) <= i) continue;
        if(s[i] == '#' && s[i+1] == '#') {
            cout << "No" << endl;
            return 0;
        }
    }

    if(c < d) cout << "Yes" << endl;
    else {
        bool ok = false;
        rep(i, b-1, d) if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
            ok = true;
            break;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
