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
    ll cntb = 0, sum_index = 0;
    rep(i, 0, (ll)s.size()) {
        if (s[i] == 'B') cntb++, sum_index += i;
    }
    cout << s.size()*cntb - cntb*(cntb+1)/2 - sum_index << endl;
}
