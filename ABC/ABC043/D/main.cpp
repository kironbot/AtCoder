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
    char c1 = '-', c2 = '_';
    ll bgn = -1, end = -1;
    rep(i, 0, (ll)s.size()) {
        if (c2 == s[i]) {
            bgn = i;
            end = i+1;
            break;
        }
        else if (c1 == s[i]) {
            bgn = i-1;
            end = i+1;
            break;
        }
        else {
            c1 = c2;
            c2 = s[i];
        }
    }
    cout << bgn << " " << end << endl;
}
