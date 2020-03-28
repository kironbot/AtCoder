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
#define debug(x) cerr << #x << ": " << x << endl;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    string s;
    cin >> s;

    deque<char> dq;
    for(auto c : s) dq.emplace_back(c);

    ll q;
    cin >> q;

    ll cnt = 0;
    rep(i, q) {
        ll t;
        cin >> t;
        if(t == 1) cnt = 1 - cnt;
        else {
            ll f;
            char c;
            cin >> f >> c;
            if(f == 1) {
                if(cnt == 0) dq.emplace_front(c);
                else dq.emplace_back(c);
            }
            else {
                if(cnt == 1) dq.emplace_front(c);
                else dq.emplace_back(c);
            }
        }
    }
    if(cnt == 1) {
        while(!dq.empty()) {
            cout << dq.back();
            dq.pop_back();
        }
    }
    else {
        while(!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }
    }
}
