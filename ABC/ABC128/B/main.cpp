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
    vector<pair<string, pair<ll, ll>>> vec;
    rep(i, 0, n) {
        string s;
        ll p;
        cin >> s >> p;
        vec.emplace_back(make_pair(s, make_pair(-p, i+1)));
    }
    sort(vec.begin(), vec.end());
    for(auto p : vec) {
        cout << p.second.second << endl;
    }
}
