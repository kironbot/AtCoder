#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    double p;
    cin >> p;

    cout.precision(10);
    if(1.5 / log(2.0) >= p) cout << p << endl;
    else cout << -1.5 * log2(1.5 / p / log(2.0)) + 1.5 / log(2.0) << endl;
}
