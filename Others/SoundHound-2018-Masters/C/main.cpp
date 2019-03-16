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
    double n, m, d;
    cin >> n >> m >> d;
    double ans;
    if (d == 0) ans = (m-1)/n;
    else ans = (m-1)*2*(n-d)/n/n;
    cout.precision(20);
    cout << ans << endl;
}