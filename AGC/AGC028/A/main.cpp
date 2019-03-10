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
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    rep(i, 0, n) {
        if ((i*m) % n == 0) {
            if (s[i] == t[i*m/n]) continue;
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << n * m / __gcd(n, m) << endl;
}
