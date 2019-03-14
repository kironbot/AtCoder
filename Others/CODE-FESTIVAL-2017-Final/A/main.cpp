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
    vector<string> t;
    rep(mask, 0, (1LL<<4)) {
        string u = "";
        if (mask & (1LL<<0)) u += "A";
        u += "KIH";
        if (mask & (1LL<<1)) u += "A";
        u += "B";
        if (mask & (1LL<<2)) u += "A";
        u += "R";
        if (mask & (1LL<<3)) u += "A";
        t.emplace_back(u);
    }
    for(auto v : t) {
        if (s == v) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
