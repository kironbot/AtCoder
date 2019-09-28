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
    bool ok = true;
    for(ll i = 0; i < s.size(); i++) {
        if(i % 2 == 0 && (s[i] == 'R' || s[i] == 'U' || s[i] == 'D')) continue;
        else if(i % 2 == 1 && (s[i] == 'L' || s[i] == 'U' || s[i] == 'D')) continue;
        else ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
