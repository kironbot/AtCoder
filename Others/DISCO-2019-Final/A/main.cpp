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
    ll n;
    string s;
    cin >> n >> s;
    double ans = 0;
    ll cnt = 0, cntmx = 0;
    for (char c : s) {
        if (c == '>') {
            ans += 1.0 / (cnt + 2);
            cnt++;
        }
        else {
            ans += 1.0;
            chmax(cntmx, cnt);
            cnt = 0;        
        }
    }
    ans += 1.0/(cntmx + 2) - 1.0;
    cout.precision(20);
    cout << ans << endl;
}