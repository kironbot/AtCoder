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
    map<string, ll> mp;
    mp["SUN"] = 7;
    mp["MON"] = 6;
    mp["TUE"] = 5;
    mp["WED"] = 4;
    mp["THU"] = 3;
    mp["FRI"] = 2;
    mp["SAT"] = 1;

    cout << mp[s] << endl;
}
