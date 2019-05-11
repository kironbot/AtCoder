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
    cin >> n;
    ll ans = 0, numa = 0, numb = 0, numab = 0;
    rep(i, 0, n) {
        string s;
        cin >> s;
        for(int j = 0; j < (int)s.size()-1; j++) {
            if (s[j] == 'A' && s[j+1] == 'B') ans++;
        }
        if(s[0] == 'B' && s[s.size()-1] == 'A') numab++;
        else if(s[0] == 'B') numb++;
        else if(s[s.size()-1] == 'A') numa++;
    }
    if (numa == 0 && numb == 0) ans += max(0LL, numab-1);
    else ans += min(numa+numab, numb+numab);

    cout << ans << endl;
}
