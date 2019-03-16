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
    ll N;
    cin >> N;
    rep(n, 1, N+1) {
        bool flg = true;
        if (n % 2 == 0) cout << 'a', flg = false;
        if (n % 3 == 0) cout << 'b', flg = false;
        if (n % 4 == 0) cout << 'c', flg = false;
        if (n % 5 == 0) cout << 'd', flg = false;
        if (n % 6 == 0) cout << 'e', flg = false;
        if(flg) cout << n;
        cout << endl;
    }
}