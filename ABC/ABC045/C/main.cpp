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
    int n = (int)s.size();
    if (n == 1) {
        cout << s << endl;
        return 0;
    }

    vector<string> t;
    for (ll mask = 0; mask < (1<<(n-1)); mask++) {
        string tmp = "";
        tmp += s[0];
        rep(i, 0, n-1) {
            if (mask & (1<<i)) {
                t.emplace_back(tmp);
                tmp = s[i+1]; 
            }
            else {
                tmp += s[i+1];
            }
            if (i == n-2) t.emplace_back(tmp);
        }
    }

    ll ans = 0;
    for(auto s : t) {
        ans += stoll(s);
    }
    cout << ans << endl;
}
