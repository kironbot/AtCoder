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

    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> vs(n);
    rep(i, n) cin >> vs[i];
    vs.push_back(vs[n-1]);
    vc ans;
    bool ok = true;
    rep(i, n) {
        if(vs[i] == "AB") {
            if(vs[i+1] == "AB") {
                if(a > 0) {
                    ans.push_back('B');
                    a--, b++;
                }
                else {
                    ans.push_back('A');
                    a++, b--;
                }
            }
            if(vs[i+1] == "AC") {
                if(b > 0) {
                    ans.push_back('A');
                    a++, b--;
                }
                else {
                    ans.push_back('B');
                    a--, b++;
                }
            }
            if(vs[i+1] == "BC") {
                if(a > 0) {
                    ans.push_back('B');
                    a--, b++;
                }
                else {
                    ans.push_back('A');
                    a++, b--;
                }
            }
        }
        if(vs[i] == "AC") {
            if(vs[i+1] == "AB") {
                if(c > 0) {
                    ans.push_back('A');
                    a++, c--;
                }
                else {
                    ans.push_back('C');
                    a--, c++;
                }
            }
            if(vs[i+1] == "AC") {
                if(a > 0) {
                    ans.push_back('C');
                    a--, c++;
                }
                else {
                    ans.push_back('A');
                    a++, c--;
                }
            }
            if(vs[i+1] == "BC") {
                if(a > 0) {
                    ans.push_back('C');
                    a--, c++;
                }
                else {
                    ans.push_back('A');
                    a++, c--;
                }
            }
        }
        if(vs[i] == "BC") {
            if(vs[i+1] == "AB") {
                if(c > 0) {
                    ans.push_back('B');
                    b++, c--;
                }
                else {
                    ans.push_back('C');
                    b--, c++;
                }
            }
            if(vs[i+1] == "AC") {
                if(b > 0) {
                    ans.push_back('C');
                    b--, c++;
                }
                else {
                    ans.push_back('B');
                    b++, c--;
                }
            }
            if(vs[i+1] == "BC") {
                if(b > 0) {
                    ans.push_back('C');
                    b--, c++;
                }
                else {
                    ans.push_back('B');
                    b++, c--;
                }
            }
        }

        if(a < 0 || b < 0 || c < 0) ok = false;
    }

    if(!ok) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for(auto x : ans) cout << x << endl;
    }
}
