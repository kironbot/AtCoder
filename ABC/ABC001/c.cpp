#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

int main() {
    cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(20);

    long double deg, dis;
    cin >> deg >> dis;

    string dir;
    if(deg < 112.5 || 3487.5 <= deg) dir = "N";
    else if(deg < 337.5) dir = "NNE";
    else if(deg < 562.5) dir = "NE";
    else if(deg < 787.5) dir = "ENE";
    else if(deg < 1012.5) dir = "E";
    else if(deg < 1237.5) dir = "ESE";
    else if(deg < 1462.5) dir = "SE";
    else if(deg < 1687.5) dir = "SSE";
    else if(deg < 1912.5) dir = "S";
    else if(deg < 2137.5) dir = "SSW";
    else if(deg < 2362.5) dir = "SW";
    else if(deg < 2587.5) dir = "WSW";
    else if(deg < 2812.5) dir = "W";
    else if(deg < 3037.5) dir = "WNW";
    else if(deg < 3262.5) dir = "NW";
    else if(deg < 3487.5) dir = "NNW";

    long double x = dis;
    int w;
    if(x < 0.25 * 60) w = 0;   
    else if(x < 1.55 * 60) w = 1;
    else if(x < 3.35 * 60) w = 2;
    else if(x < 5.45 * 60) w = 3;
    else if(x < 7.95 * 60) w = 4;
    else if(x < 10.75 * 60) w = 5;
    else if(x < 13.85 * 60) w = 6;
    else if(x < 17.15 * 60) w = 7;
    else if(x < 20.75 * 60) w = 8;
    else if(x < 24.45 * 60) w = 9;
    else if(x < 28.45 * 60) w = 10;
    else if(x < 32.65 * 60) w = 11;
    else w = 12;

    if(w==0) dir = "C";
    debug(x)
    cout << dir << " " << w << endl;
}
