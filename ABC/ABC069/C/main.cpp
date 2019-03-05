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
    ll cnt4 = 0, cntodd = 0;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        if (a % 4 == 0) cnt4++;
        if (a % 2 == 1) cntodd++;
    }
    if (cnt4 >= cntodd) cout << "Yes" << endl;
    else if (n % 2 == 1 && cnt4 == cntodd-1 && cnt4+cntodd == n) cout << "Yes" << endl;
    else cout << "No" << endl;

}
