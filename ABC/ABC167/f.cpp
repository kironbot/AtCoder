#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    vll m(N, 0), S(N);
    vector<pll> v1, v2;
    vector<string> s(N);
    rep(i, N) {
        cin >> s[i];
        ll tmp = 0;
        for(auto c : s[i]) {
            if(c == '(') tmp++;
            else tmp--;
            chmin(m[i], tmp);
        }
        S[i] = tmp;

        if(S[i] >= 0) v1.emplace_back(-m[i], i);
        else v2.emplace_back(m[i] - S[i], i);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll tot = 0, last = 0;
    for(auto p : v1) {
        auto idx = p.second;
        for(auto c : s[idx]) {
            if(c == '(') last++;
            else last--;
            chmin(tot, last);
        }
    }
    for(auto p : v2) {
        auto idx = p.second;
        for(auto c : s[idx]) {
            if(c == '(') last++;
            else last--;
            chmin(tot, last);
        }
    }
    if(tot == 0 && last == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}
