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
    string s;
    cin >> n >> s;
    ll sum = 0, cnt = 1;
    for (auto c : s) {
        if (c == 'A') {
            sum += cnt;
            cnt++;
        }
        else cnt = 1;
    }
    ll cnt_front = 0, cnt_end = 0;
    for (auto c : s) {
        if (c == 'A') cnt_front++;
        else break;
    }
    for (int i = (int)s.size()-1; i >= 0; i--) {
        if (s[i] == 'A') cnt_end++;
        else break;
    }

    cout << sum + (n-1) * (sum + cnt_front * cnt_end) << endl;
}