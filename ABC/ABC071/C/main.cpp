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
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i]; 
    sort(a.begin(), a.end());

    ll la = 0, lb = 0;
    ll tmp = a.back();
    a.pop_back();
    for(int i = n-2; i >= 0; i--) {
        if (tmp == a.back() && la == 0) {
            la = a.back();
            tmp = 0;
        }
        else if (tmp == a.back() && lb == 0){
            lb = a.back();
            break;
        }
        else {
            tmp = a.back();
        }
        a.pop_back();
    }
    cout << la * lb << endl;
}